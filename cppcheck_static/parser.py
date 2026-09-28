import sys
import xml.etree.ElementTree as ET
from collections import defaultdict
from html import escape


def analyze_cppcheck(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    issues = defaultdict(lambda: {
        "count": 0,
        "description": ""
    })

    for error in root.findall(".//error"):
        cppcheck_id = error.get("id", "unknown")
        severity = error.get("severity", "unknown")
        message = error.get("msg", "")

        key = (cppcheck_id, severity)

        issues[key]["count"] += 1

        if not issues[key]["description"]:
            issues[key]["description"] = message

    return issues


def generate_html(issues, output_file):
    rows = []

    sorted_issues = sorted(
        issues.items(),
        key=lambda item: (item[0][1], item[0][0])
    )

    for (cppcheck_id, severity), data in sorted_issues:

        rows.append(
            f"""
            <tr>
                <td>{escape(cppcheck_id)}</td>
                <td>{escape(severity)}</td>
                <td>{data["count"]}</td>
                <td>{escape(data["description"])}</td>
            </tr>
            """
        )

    html = f"""<!DOCTYPE html>
<html lang="sr">
<head>
    <meta charset="UTF-8">
    <title>Cppcheck Report</title>

    <style>
        body {{
            font-family: Arial, sans-serif;
            margin: 40px;
            color: #222;
        }}

        h1 {{
            margin-bottom: 25px;
        }}

        table {{
            border-collapse: collapse;
            width: 100%;
        }}

        th, td {{
            border: 1px solid #ccc;
            padding: 8px 10px;
            text-align: left;
        }}

        th {{
            background-color: #f2f2f2;
        }}

        tr:nth-child(even) {{
            background-color: #fafafa;
        }}

        td:nth-child(3) {{
            text-align: center;
            width: 80px;
        }}
    </style>
</head>

<body>

<h1>Cppcheck staticka analiza projekta LibreSprite</h1>
<h3> Uradjeno je testiranje app modula <h3>

<table>
    <thead>
        <tr>
            <th>Cppcheck ID</th>
            <th>Kategorija</th>
            <th>Broj</th>
            <th>Opis</th>
        </tr>
    </thead>

    <tbody>
        {"".join(rows)}
    </tbody>
</table>

</body>
</html>
"""

    with open(output_file, "w", encoding="utf-8") as f:
        f.write(html)


def main():
    if len(sys.argv) != 3:
        print(
            "Upotreba:\n"
            "  python parser.py deep_analysis.xml analysis_report.html"
        )
        sys.exit(1)

    xml_file = sys.argv[1]
    output_file = sys.argv[2]

    try:
        issues = analyze_cppcheck(xml_file)
        generate_html(issues, output_file)

        print(f"Izvestaj je generisan kao html stranica: {output_file}")
        print(f"Pronadjeno kategorija: {len(issues)}")

    except ET.ParseError as e:
        print(f"Greška pri citanju XML fajla: {e}")
        sys.exit(1)

    except FileNotFoundError as e:
        print(f"Fajl nije pronadjen: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
