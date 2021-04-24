/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vozilo (vozilo je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct vozilo
{
    char *markaVozila;
    char *nazivVozila;
    char *tipVozila; // omogućiti unos samo 'A', 'B','C'
    float *potrosnja_goriva_po_km;
};
Redovi matrice predstavljaju firme, kolone automobile. Izračunati u kojoj je firmi najveća potrošnja goriva po km.

Naći i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/
#include<iostream>
using namespace std;
struct vozilo
{
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;

    void unosVozila()
    {
        markaVozila = new char[15];
        cout << "Unesite marku vozila: ";
        cin.ignore();
        cin.getline(markaVozila, 15);

        nazivVozila = new char[15];
        cout << "Unesite naziv vozila: ";
        cin.getline(nazivVozila, 15);

        tipVozila = new char;
        do
        {
            cout << "Unesite tip vozila: ";
            cin >> tipVozila;
            if (*tipVozila != 'A' && *tipVozila != 'B' && *tipVozila != 'C')
            {
                cout << "Pogresan unos!. Molimo Vas unesite ponovo " << endl;
            }

        } while (*tipVozila!='A' && *tipVozila!='B' && *tipVozila!='C');
        cin.ignore();

        potrosnja_goriva_po_km = new float;
        cout << "Unesite potrosnju goriva po km: ";
        cin >> *potrosnja_goriva_po_km;
    }
    void ispisVozila()
    {
        cout << "Marka vozila: " << markaVozila << endl;
        cout << "Naziv vozila: " << nazivVozila << endl;
        cout << "Tip vozila: " << *tipVozila << endl;
        cout << "Potrosnja goriva po km: " << *potrosnja_goriva_po_km << endl;
    }
    void dealokacijaVozila()
    {
        delete[]markaVozila;
        markaVozila = nullptr;

        delete[]nazivVozila;
        nazivVozila = nullptr;

        delete tipVozila;
        tipVozila = nullptr;

        delete potrosnja_goriva_po_km;
        potrosnja_goriva_po_km = nullptr;
    }
};
void firmaNajvecaPotrosnja(vozilo**, int, int);
void potrosnjaPoTipuC(vozilo**, int, int);
int main()
{
    // redovi firme
    //kolone automobile

    int brFirma, brVozilo;
    cout << "Unesite broj firmi: ";
    cin >> brFirma;
    cout << "Unesite broj vozila: ";
    cin >> brVozilo;

    vozilo** v = new vozilo * [brFirma];
    for (int i = 0; i < brFirma; i++)
    {
        *(v + i) = new vozilo[brVozilo];
    }
    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozilo; j++)
        {
            (*(*(v + i) + j)).unosVozila();
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozilo; j++)
        {
            (*(*(v + i) + j)).ispisVozila();
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    firmaNajvecaPotrosnja(v, brFirma, brVozilo);
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    potrosnjaPoTipuC(v, brFirma, brVozilo);
    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozilo; j++)
        {
            (*(*(v + i) + j)).dealokacijaVozila();
        }
    }
    for (int i = 0; i < brFirma; i++)
    {
        delete[] * (v + i);
        
    }
    delete[]v;
    v = nullptr;

    system("pause>0");
    return 0;
}
void firmaNajvecaPotrosnja(vozilo** v, int brFirma, int brVozila)
{
    float* potrosnjaFirma = new float[brFirma] {};

    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozila; j++)
        {
            *(potrosnjaFirma + i) += *(*(v + i) + j)->potrosnja_goriva_po_km;
        }
        *(potrosnjaFirma + i) /= brVozila;
    }

    int maxFirma = 0;

    for (int i = 0; i < brFirma; i++)
    {
        if (*(potrosnjaFirma+i)>*(potrosnjaFirma+maxFirma))
        {
            maxFirma = i;
        }
    }

    cout << "Firma koja ima najavecu potrosnju nalazi se na index-u: " << maxFirma << endl;

    delete[]potrosnjaFirma;
    potrosnjaFirma = nullptr;
}
void potrosnjaPoTipuC(vozilo** v, int brFirma, int brVozila)
{
    float averageC = 0.0f;
    int counterC = 0;

    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brVozila; j++)
        {
            if (*(*(v + i) + j)->tipVozila == 'C')
            {
                averageC += *(*(v + i) + j)->potrosnja_goriva_po_km;
                counterC++;
            }
        }
    }
    if (counterC>0)
    {
        cout << "Potrosnja po tipu C iznosi: " << averageC / counterC << endl;
    }

    
}