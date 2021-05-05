# Postavke za cetvrte zadatke

# [Zadatak 1](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad1.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler(fudbaler je struktura čija su obilježja data u nastavku).Omogućiti korisniku da unese dimenzije niza.
```
struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.

Omogućiti korisniku unos svih podataka za sve igrače, te napraviti(i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom.Zatim napraviti(i testirati u main funkciji) 
funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova.Radi lakšeg testiranja programa obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće :

godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve u rangu 1980 - 2000
brojIgraca : rand() % 30 + 1
golovi : rand() % 5
(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama.Obavezno koristiti aritmetiku pokazivača.)

# [Zadatak 2](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad2.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```
struct vozilo
{
    char *markaVozila;
    char *brojSasije;
    char *tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int *kubnihCM;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite firme a u kolone različita vozila u tim firmama. (radi jednostavnosti rješenja podrazumijevati da svaka firma ima isti broj vozila). Omogućiti korisniku unos svih podataka za sva vozila.

Napisati i testirati funkciju koja će pronaći (firmu) koja ima največu prosječnu kubikazu vozila (prosjek vrijednosti kubnihCM).

Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila (prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno svih vozila tipa "B" u cijeloj matrici

(Pošto se trazi u istoj funkciji, vodite računa o optimizaciji petlji jer to utiče na broj bodova).

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)

# [Zadatak 3](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad3.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```
struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
```
Redovi matrice predstavljaju firme, kolone automobile. Izračunati u kojoj je firmi najveća potrošnja goriva po km.

Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)

# [Zadatak 4](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad4.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```
struct vremenska_prognoza
{
    char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float *temperatura;
    float *vlaznost_vazduha;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane. Omogućiti korisniku unos svih prognoza za sve meteorologe.
Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane.
Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, 
odnosno koji je imao najmanju grešku u procjeni temperatura. Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.
(U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
# [Zadatak 4 drugi nacin] (https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad04v2.cpp) 
# [Zadatak 5](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad5.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```
struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove. Omogućiti korisniku unos svih podataka za sve košarkaše, 
te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa). 
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) i najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa ta dva košarkaša.
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)

# [Zadatak 6](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad6.cpp)
Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.
```
struct figura
{
    int ID
    char *nazivFigure;
    float *visinaFigure;
};
```
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale.

(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)

# [Zadatak 7](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad7.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). Omogućiti korisniku da unese dimenzije niza.
```
struct uposlenik
{
    char *ID;
    char *imePrezime;
    float *plata;
};
```
Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici (radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika).

Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme te ispisati koji je to redni broj odjela (indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.

# [Zadatak 8](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad8.cpp)
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student (student je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.
```
struct student
{
    char *ID;
    char *imePrezime;
    float *prosjek;
};
```
Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete,a kolone studente (radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata). 
Omogućiti korisniku unos svih podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni broj fakulteta (index reda sa najvećim prosjekom). 
Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.
(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alocirane memorije.)

# [Zadatak 9](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%204/Zad9.cpp)
Kreirati dinamicki niz ciji su elementi objekta tipa fudbaler (fudbaler je struktura cija su obiljeza data u nastavku).
Omoguciti korisniku da unese dimenzije niza te omoguciti unos elemenata.
Redovi predstavljaju razlicite klubove, a kolone razlicite fudabalere.
Radi jednostavnosti rjesenja, pretpostaviti da svaki klub ima isti broj fudbalera.
Ovisno o unesenoj poziciji (N, O ili V) identificira se da li je dati fudaler napadac, odbrambeni ili vezni igrac. U razlicitim klubovima mogu igrati razliciti brojevi napadaca, veznih igraca ili odbrambenih igraca. 
(Npr. klub 1 moze imati 10 veznih, 3 napadaca i 5 odbrambenih igraca, dok klub 2 moze imati 12 veznih igraca, 2 napadaca i 6 odbrambenih igraca i sl.).
Izracunati i ispisati broj golova po poziciji igraca za sve klubove.
Zatim omoguciti korisniku izbor jendog tipa fudbalera (N, O ili V) i prema korisnickom izbrou pronaci klub koji ima najbolji prosjek postignutih zgoditaka top tipa igraca
(npr. ako se inese slovo V za klub 1 racuna se prosjek za 10 veznih igraca dok se za klub 2 racuna prosjek 12 veznih igraca i ti prosjeci se porede).
U ovom zadatku je zabranjeno indeksirati elemenete niza u uglastim zagradama. Obavezno koristiti aritmetiku pokazivaca. 
Obavezno voditi racuna o dealociranju dinamicki alociranje memorije.







