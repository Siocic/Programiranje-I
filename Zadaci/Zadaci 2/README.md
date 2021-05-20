# Postavke za druge zadatke

# [Zadatak 1](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad01.cpp)
Napisati program koji simulira bacanje 3 kockice (jedna kockica ima 6 strana i na tim stranama su brojevi 1 - 6). 
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. 
Simulirati konstantno bacanje sve tri kockice dok se u dva uzastopna bacanja ne desi da se dobiju isti brojevi na sve tri kockice 
(npr. u šestom bacanju se dobiju brojevi 2, 2, 2, a u sedmom 4, 4, 4 na sve tri kockice).
Ispisati koliko je ukupno bilo bacanja dok se nije ispunio navedeni uslov.
Nije potrebno tražiti bilo kakav unos od korisnika.

# [Zadatak 2](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad02.cpp)
Napisati program koji će omogućiti unos prirodnog broja A (A > 100000), te kreirati i ispisati broj B koji će se sastojati od cifara broja A u obrnutom redoslijedu gdje je svaka parna cifra uklonjena.
Npr. ako se unese 45362792, funkcija treba vratiti 9735. Ispisati razliku brojava A i B
(Obavezno koristiti bar jednu korisnički definisanu funkciju)

# [Zadatak 3](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad03.cpp)
Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u kojem su parne cifre zamijenjene cifrom '5'.
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene.

# [Zadatak 4](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad04.cpp)
Svaki paran broj se može prikazati kao suma dva prosta broja (tkz. Goldbachovo pravilo).
Napisati program koji će najprije učitati dva prirodna broja n1 i n2 (n2 > n1).
Zatim prikazati sve parne brojeve u intervalu od n1 do n2 kao sumu dva prosta broja.
(U glavnom programu samo unijeti navedena dva prirodna broja i pozvati funkciju koja obavlja zadani posao.)

# [Zadatak 5](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad05.cpp)
Napisati program koji omogućava korisniku unos prirodnog broja N (50 < N < 5000000).
Zatim uneseni broj proslijediti funkciji kao parametar po referenci. 
U funkciji je od unesenog broja potrebno kreirati novi broj teko što će se poredak cifri unesenog broja obrnuti. Prilikom obrtanja potrebno je odbaciti neparne cifre.
Npr. Za uneseni broj 1234567 obrnuti broj bez neparnih cifara je 642.

# [Zadatak 6](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad06.cpp)
Napisati program koji će omogućiti korisniku unos broja n ( 10 <= n <= 1000). 
Zatim simulirati n bacanja kockice (kockica ima 6 strana i na tim stranicama su brojevi 1-6).
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. 
Izračunati statičke podatke u kojem procentu ukupnog bacanja se dobiva svaki od mogućih brojeva 1-6. 
Obavezno koristiti switch statement za zbrajanje rezultata bacanja kockice.
Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadataka.

# [Zadatak 7](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad07.cpp)
Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000).
Zatim simulirati unos n slučajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1.
Izračunati statističke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje prost broj.
Npr. Ako je generisano 10 brojeva (n = 10): 5,7,4,13,17,20,25,23,30,45, u ovom uzorku od 10 brojeva postoji 5 prostih brojeva pa je procenat prostih brojeva u ovom slučaju 50%.
(Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadatka.)

# [Zadatak 8](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad08.cpp)
Napisati program koji izračunava ukupan zbir faktorijela od svih prostih brojeva koji su članovi prvih 100 elemenata Fibonacci niza (tzv. fibonacci prime).
Napomena: Pazljivo pročitajte zadatak. Obavezno voditi računa da se uradi tačno ono što je trazeno u zadatku i da zadatak bude logicki ispravan.
Obavezno koristiti bar jednu funkciju kojoj ćete proslijediti parametar po referenci.

# [Zadatak 9](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad09.cpp)
Napisati program koji korisniku omogućava unos realnog broja x, cijelog broja m i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom sljedećih karaktera 's' (sin), 'c' (cos), 'q' (sqrt), 'p' (pow). 
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.Za funkciju pow() drugi parametar treba biti 3.
Za odabranu funkciju izraz je:

![68747470733a2f2f692e706f7374696d672e63632f6b675667576e39622f53637265656e73686f742d312e706e67](https://user-images.githubusercontent.com/77838860/115952653-8cb4ec80-a4e7-11eb-99c1-33fbb0bb4055.png)

Broj faktora u izrazu odgovara unesenom broju m. U rješenju obavezno iskoristiti switch iskaz.

# [Zadatak 10](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad10.cpp)
Napisati program koji ce omoguciti korisniku unos broj n (uz uslov 10<=n<=1000). 
Zatim simulirati unos n slucajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand()%1000+1. 
Izracunati statisticke podatke u kojem procentu se od n generisanih slucajnih vrijednosti pojavljuje savrsen broj. 
Za neki broj se kaze da je savrsen ukoliko je jednak sumi svih svojih djelilaca (ne ukljucujici njega samog).
Na primjer, 28 je savrsen broj: njegovi djelioci su 1, 2, 4, 7 i 14, a 1 + 2 + 4 + 7 + 14 = 28. 
Jedini savrseni brojevi u opsegu od 1 do 100 su brojevi 6 i 28.

# [Zadatak 11](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad11.cpp)
Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100.
Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre.
Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".

# [Zadatak 12](https://github.com/Siocic/Programiranje-I/blob/main/Zadaci/Zadaci%202/Zad12.cpp)
Omogućiti unos dva prirodna broja A i B (A>100000, B>50000).
Napisati program koji će kreirati i ispisati broj C koji će se sastojati od cifara broja A u obrnutom redoslijedu ali bez cifara koje se pojavljuju u broju B.
Obavezno koristiti bar jednu funkciju. Ispsati razliku brojeva A i C.
