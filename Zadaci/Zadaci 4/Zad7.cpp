
#include<iostream>
using namespace std;
struct uposlenik
{
    char* ID;
    char* ime;
    char* prezime;
    float* plata;

    void unosUposlenik()
    {
        ID = new char[10];
        cout << "ID zaposlenika: ";
        cin.ignore();
        cin.getline(ID, 10);

        ime = new char[10];
        cout << "Unesite ime: ";
        cin.getline(ime, 10);

        prezime = new char[20];
        cout << "Unesite prezime: ";
        cin.getline(prezime, 20);

        plata = new float;
        *plata = rand() % 3000 + 600;
    }
    void ispisUposlenik()
    {
        cout << "ID: " << *ID << endl;
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Plata: " << *plata << endl;
    }
    void dealokacijaUposlenik()
    {
        delete ID;
        ID = nullptr;

        delete[] ime;
        ime = nullptr;

        delete[]prezime;
        prezime = nullptr;

        delete plata;
        plata = nullptr;
    }
};
void prosjekPlate(uposlenik**, int, int);
int main()
{
    //redovi = odjelFirma
    //kolona = radnici

    srand(time(0));
    
    int brOdjelaFirma, brRadnici;
    
    cout << "Unesite broj odjela u firmi: ";
    cin >> brOdjelaFirma;
    cout << "Unesite broj radnika: ";
    cin >> brRadnici;

    uposlenik** u = new uposlenik * [brOdjelaFirma];
    for (int i = 0; i < brOdjelaFirma; i++)
    {
        *(u + i) = new uposlenik[brRadnici];
    }
    for (int i = 0; i < brOdjelaFirma; i++)
    {
        for (int j = 0; j < brRadnici; j++)
        {
            (*(*(u + i) + j)).unosUposlenik();
        }
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < brOdjelaFirma; i++)
    {
        for (int j = 0; j < brRadnici; j++)
        {
            (*(*(u + i) + j)).ispisUposlenik();
        }
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    prosjekPlate(u, brOdjelaFirma, brRadnici);
    cout << "----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < brOdjelaFirma; i++)
    {
        for (int j = 0; j < brRadnici; j++)
        {
            (*(*(u + i) + j)).dealokacijaUposlenik();
        }
    }
    for (int i = 0; i < brOdjelaFirma; i++)
    {
        delete[] * (u + i);
    }
    delete[]u;
    u = nullptr;

    return 0;
}
void prosjekPlate(uposlenik** u, int brFirma, int brRadnici)//prosjek plate po odjelima firme
{
    float* prosjek = new float[brFirma] {};

    for (int i = 0; i < brFirma; i++)
    {
        for (int j = 0; j < brRadnici; j++)
        {
            *(prosjek + i) += *(*(u + i) + j)->plata;
        }
        *(prosjek + i) /= brRadnici;
    }
    int prosjekOdjela = 0;
    for (int i = 0; i < brFirma; i++)
    {
        if (*(prosjek + i) < *(prosjek + prosjekOdjela))
        {
            prosjekOdjela = i;
        }
    }
    cout << "Odjel sa najvecim prosjekom je: " << prosjekOdjela << " a najveci prosjek plate je: " << *(prosjek + prosjekOdjela) << endl;

    delete[]prosjek;
    prosjek = nullptr;

}
