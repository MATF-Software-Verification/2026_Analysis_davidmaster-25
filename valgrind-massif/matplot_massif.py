import matplotlib.pyplot as plt
import re
import sys

def parse_massif(filename):
    times = []
    memories = []
    
    print(f"Reading file: {filename}...")
    
    try:
        with open(filename, 'r') as f:
            lines = f.readlines()
            
        current_time = 0
        
        for i, line in enumerate(lines):
            if 'snapshot=' in line:
                # Resetujemo vreme za svaki novi snapshot
                current_time = 0 
            
            time_match = re.search(r'time=(\d+)', line)
            if time_match:
                current_time = int(time_match.group(1))
            
            mem_match = re.search(r'mem_heap_B=(\d+)', line)
            if mem_match:
                mem_val = int(mem_match.group(1)) / (1024 * 1024) # Prebacujemo u MB
                times.append(current_time)
                memories.append(mem_val)
                    
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)
    except Exception as e:
        print(f"An error occurred during parsing: {e}")
        sys.exit(1)
        
    return times, memories

def plot_massif(times, memories, output_file='massif_plot.png'):
    if not times or not memories:
        print("Error: No data points were extracted.")
        return

    print(f"Successfully parsed {len(times)} snapshots.")
    
    plt.figure(figsize=(12, 7))
    
    # Koristimo linijski grafikon sa popunjavanjem
    plt.plot(times, memories, label='Heap Usage', color='#2c3e50', linewidth=2)
    plt.fill_between(times, memories, color='#3498db', alpha=0.3)
    
    # Estetika
    plt.title('LibreSprite Heap Memory Usage Over Time', fontsize=14, fontweight='bold')
    plt.xlabel('Time (units)', fontsize=12)
    plt.ylabel('Memory Usage (MB)', fontsize=12)
    plt.grid(True, which='both', linestyle='--', alpha=0.5)
    
    # Pronalazenje i oznacavanje Peak-a
    if memories:
        peak_mem = max(memories)
        peak_idx = memories.index(peak_mem)
        peak_time = times[peak_idx]
        
        plt.annotate(f'Peak: {peak_mem:.2f} MB', 
                     xy=(peak_time, peak_mem), 
                     xytext=(peak_time, peak_mem * 1.1),
                     arrowprops=dict(facecolor='red', shrink=0.05),
                     fontsize=10, color='red', fontweight='bold',
                     ha='center')

    plt.tight_layout()
    plt.savefig(output_file, dpi=300)
    print(f"Success! Plot saved as {output_file}")

if __name__ == "__main__":
    filename = 'massif.out'
    if len(sys.argv) > 1:
        filename = sys.argv[1]
        
    t, m = parse_massif(filename)
    plot_massif(t, m)