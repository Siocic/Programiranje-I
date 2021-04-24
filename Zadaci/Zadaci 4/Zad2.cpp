/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct vozilo
{
    char *markaVozila;
    char *brojSasije;
    char *tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int *kubnihCM;
};
Redovi dvodimenzionalnog niza predstavljaju različite firme a u kolone različita vozila u tim firmama. (radi jednostavnosti rješenja podrazumijevati da svaka firma ima isti broj vozila). Omogućiti korisniku unos svih podataka za sva vozila.

Napisati i testirati funkciju koja će pronaći (firmu) koja ima največu prosječnu kubikazu vozila (prosjek vrijednosti kubnihCM).

Zatim napisati i testirati funkciju koja će pronaći i ispisati porosječnu kubikažu vozila (prosjek vrijednosti kubnihCM) svih vozila tipova "A" te posebno svih vozila tipa "B" u cijeloj matrici

(Pošto se trazi u istoj funkciji, vodite računa o optimizaciji petlji jer to utiče na broj bodova).

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/
#include<iostream>
using namespace std;
struct vozilo
{
    char* markaVozila;
    char* brojSasije;
    char* tipVozila;//dozvoliti unos samo A,B,C
    int* kubniCM;

    void unosVozila()
    {
        markaVozila = new char[15];
        cout << "Unesite marku vozila: ";
        cin.ignore();
        cin.getline(markaVozila, 15);

        brojSasije = new char[15];
        cout << "Unesite broj sasije: ";
        cin.getline(brojSasije, 15);

        tipVozila = new char;
        do
        {
            cout << "Unesite tip vozila: ";
            cin >> *tipVozila;
            if (*tipVozila != 'A' && *tipVozila != 'B' && *tipVozila != 'C')
            {
                cout << "Pogresan unos! Unesite ponovo." << endl;
            }

        } while (*tipVozila!='A' && *tipVozila!='B' && *tipVozila!='C');
        cin.ignore();

        kubniCM = new int;
        cout << "Unesite kubikazu vozila: ";
        cin >> *kubniCM;
    }
    void ispisVozila()
    {
        cout << "Marka vozila: " << markaVozila << endl;
        cout << "Broj sasije: " << brojSasije << endl;
        cout << "Tip vozila: " << *tipVozila << endl;
        cout << "Kubni CM: " << *kubniCM << endl;
    }
    void dealokacijaVozila()
    {
        delete[]markaVozila;
        markaVozila = nullptr;

        delete[]brojSasije;
        brojSasije = nullptr;

        delete tipVozila;
        tipVozila = nullptr;

        delete kubniCM;
        kubniCM = nullptr;
    }
};
void prosjecnaKubikazaVozikaPoFirmi(vozilo**, int, int);
void prosjecnaKubikazaVozilaPoTipu(vozilo**, int, int);
int main()
{
    //redovi su firme
    //kolone su automobili

    int brFirmi, brVozila;

    cout << "Unesite broj firmi: ";
    cin >> brFirmi;
    cout << "Unesite broj vozila: ";
    cin >> brVozila;

    vozilo** v = new vozilo * [brFirmi];
    for (int i = 0; i < brFirmi; i++)
    {
        *(v + i) = new vozilo[brVozila];
    }
    for (int i = 0; i < brFirmi; i++)
    {
        for (int j = 0; j < brVozila; j++)
        {
            (*(*(v + i) + j)).unosVozila();
        }
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < brFirmi; i++)
    {
        for (int j = 0; j < brVozila; j++)
        {
            (*(*(v + i) + j)).ispisVozila();
        }
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    prosjecnaKubikazaVozikaPoFirmi(v, brFirmi, brVozila);
    cout << "-------------------------------------------------------------------------------" << endl;
    prosjecnaKubikazaVozilaPoTipu(v, brFirmi, brVozila);




    for (int i = 0; i < brFirmi; i++)
    {
        for ( int j = 0; j < brVozila; j++)
        {
            (*(*(v + i) + j)).dealokacijaVozila();
        }
    }
    for (int i = 0; i < brVozila; i++)
    {
        delete[] * (v + i);
        *(v + i) = nullptr;
    }
    delete[]v;
    v = nullptr;


    system("pause>0");
    return 0;
}
void prosjecnaKubikazaVozikaPoFirmi(vozilo** v, int brFirma, int brVozilo)
{
    float* prosjekFirma = new float[brFirma] {};

    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozilo; j++)
        {
            *(prosjekFirma + i) += *(*(v + i) + j)->kubniCM;
        }
        *(prosjekFirma + i) /= brVozilo;
    }
    int maxAvarage = 0;
    for (int i = 0; i < brFirma; i++)
    {
        if (*(prosjekFirma+i)>*(prosjekFirma+maxAvarage))
        {
            maxAvarage = i;
        }
    }

    cout << "Firma sa najvecom kubukazom se nalazi na indeksu: " << maxAvarage << endl;

    delete[]prosjekFirma;
    prosjekFirma = nullptr;
}
void prosjecnaKubikazaVozilaPoTipu(vozilo** v, int brFirmi, int brVozila)
{
    float averageA=0.0f, averageB=0.0f;
    int counterA = 0, counterB = 0;

    for (  int  i = 0; i < brFirmi; i++)
    {
        for (int j = 0; j < brVozila; j++)
        {
            if (*(*(v+i)+j)->tipVozila=='A')
            {
                averageA += *(*(v + i) + j)->kubniCM;
                counterA++;

            }
            else if(*(*(v+i)+j)->tipVozila=='B')
            {
                averageB += *(*(v + i) + j)->kubniCM;
                counterB++;
            }
        }
    }
    if (counterA>0)
    {
        cout << "Prosjecna kubikaza po tipu vozila A iznosi: " << averageA / counterA << endl;
    }
    if (counterB > 0)
    {
        cout << "Prosjecna kubikaza po tipu vozila B iznosi: " << averageB / counterB << endl;

    }
    
}
