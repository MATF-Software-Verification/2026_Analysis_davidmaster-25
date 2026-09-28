## Statička i dinamička analiza aplikacije LibreSprite

### LibreSprite
LibreSprite je slobodan softver otvorenog koda za kreiranje i animaciju sprajtovima.
Aplikacija ima mogućnosti:

- Pregleda animacije u realnom vremenu.

- „Onion skinning“ – prikaz prethodnih i narednih frejmova kao poluprovidnih slojeva radi lakšeg animiranja.

- Mogućnost istovremenog uređivanja više spriteova.

- Dostupne palete spremne za upotrebu, kao i mogućnost kreiranja sopstvenih paleta.

- Spriteovi se sastoje od slojeva i frejmova.

- Režim pločastog crtanja (Tiled Drawing), koristan za kreiranje šara i tekstura.

- Alati za precizno pikselno crtanje, kao što su popunjavanje kontura, poligoni, režim senčenja i drugi.

- Podržano je više tipova fajlova za sprajtove i animacije.

### Cilj analize

Cilj ovog izveštaja je analiza kvaliteta, stabilnosti, pouzdanosti i korišćenja resursa C++ aplikacije primenom statičkih i dinamičkih metoda testiranja.

Tokom analize korišćene su sledeće tehnike:

- Cppcheck – statička analiza izvornog koda;

- Clang-Tidy – analiza kvaliteta i potencijalnih problema u C++ kodu;

- Valgrind Massif – dinamička analiza korišćenja heap memorije;

- AddressSanitizer (ASan) – detekcija grešaka pri pristupu memoriji;

- Unit testovi – testiranje pojedinačnih komponenti sistema;

- Integracioni testovi – testiranje saradnje između različitih komponenti sistema.


### Skripte
Sve skripte za generisanje izvršnog fajla aplikacije i pokretanje testiranja nalaze se u folderu bash_scripts

