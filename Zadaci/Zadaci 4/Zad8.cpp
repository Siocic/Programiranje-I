/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa student (student je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct student
{
    char *ID;
    char *imePrezime;
    float *prosjek;
};
Kompletan 2D niz predstavlja univerzitet. Redovi dvodimenzionalnog niza predstavljaju različite fakultete,a kolone studente (radi jednostavnosti rješenja podrazumijevati da svaki fakultet ima isti broj studenata). 
Omogućiti korisniku unos svih podataka za sve studente, te napraviti funkciju koja će pronaći fakultet sa najvećim prosjekom te ispisati koji je to redni broj fakulteta (index reda sa najvećim prosjekom). 
Zatim pronaći i ispisati ID studenta koji ima najveći prosjek na cijelom univerzitetu.
(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača. Obavezno voditi računa o dealociranju dinamički alocirane memorije.)
*/
#include<iostream>
using namespace std;

struct student
{
    char* ID;
    char* ime;
    char* prezime;
    float* prosjek;

    void unosStudent()
    {
        ID = new char[10];
        cout << "ID studenta: ";
        cin.ignore();
        cin.getline(ID, 10);

        ime = new char[10];
        cout << "Ime: ";
        cin.getline(ime, 10);

        prezime = new char[20];
        cout << "Prezime: ";
        cin.getline(prezime, 20);

        prosjek = new float;
        cout << "Prosjek: ";
        cin >> *prosjek;
    }
    void ispisStudenta()
    {
        cout << "ID: " << ID << endl;
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Prosjek: " << *prosjek << endl;
    }
    void dealokacijaStudenta()
    {
        delete[]ID;
        ID = nullptr;

        delete[]ime;
        ime = nullptr;

        delete[]prezime;
        prezime = nullptr;

        delete prosjek;
        prosjek = nullptr;
    }
};
void prosjekFakulteta(student**, int, int);
void najboljiStudent(student**, int, int);
int main()
{
    //redovi = fakulteti
    //kolone = studenti

    srand(time(0));

    int brFakulteta, brStudenti;
    cout << "Unesite broj Fakulteta: ";
    cin >> brFakulteta;
    cout << "Unesite broj Studenata: ";
    cin >> brStudenti;

    student** s = new student * [brFakulteta];
    for (int i = 0; i < brFakulteta; i++)
    {
        *(s + i) = new student[brStudenti];
    }

    for (int i = 0; i < brFakulteta; i++)
    {
        for (int j = 0; j < brStudenti; j++)
        {
            (*(*(s + i) + j)).unosStudent();
        }
    }
    cout << "----------------------------------------------------------------" << endl;
    for (int i= 0; i < brFakulteta; i++)
    {
        for (int j = 0; j < brStudenti; j++)
        {
            (*(*(s + i) + j)).ispisStudenta();
        }
    }
    cout << "----------------------------------------------------------------" << endl;
    prosjekFakulteta(s, brFakulteta, brStudenti);
    cout << "----------------------------------------------------------------" << endl;
    najboljiStudent(s, brFakulteta, brStudenti);
    cout << "----------------------------------------------------------------" << endl;
    for (int i = 0; i < brFakulteta; i++)
    {
        for (int j = 0; j < brStudenti; j++)
        {
            (*(*(s + i) + j)).dealokacijaStudenta();
        }
    }
    for (int i = 0; i < brFakulteta; i++)
    {
        delete[] * (s + i);
    }
    delete s;
    s = nullptr;

    return 0;
}
void prosjekFakulteta(student** s, int brFakulteta, int brStudenta)
{
    float* prosjek = new float[brFakulteta] {};

    for (int i = 0; i < brFakulteta; i++)
    {
        for (int k = 0; k < brStudenta; k++)
        {
            *(prosjek + i) += *(*(s + i) + k)->prosjek;
        }
        *(prosjek + i) /= brStudenta;
    }
    int IDFakulteta = 0;
    for (int i = 0; i < brFakulteta; i++)
    {
        if (*(prosjek + i) < *(prosjek + IDFakulteta))
        {
            IDFakulteta = i;
        }
    }
    cout << "Fakultet sa najvecim prosjekom se nalazi na indeksu: " << IDFakulteta << endl;

    delete[]prosjek;
    prosjek = nullptr;
}
void najboljiStudent(student** s, int brFakulteta, int brStudenta)
{
    int fakultet = 0, studenti = 0;
    for (int i = 0; i < brFakulteta; i++)
    {
        for (int j = 0; j < brStudenta; j++)
        {
            if ((*(*(s + fakultet) + studenti)).prosjek < (*(*(s + i) + j)).prosjek)
            {
                fakultet = i;
                studenti = j;
            }
        }
    }
    cout << "Student sa najvecim prosjekom ima ID: " << (*(*(s+fakultet)+studenti)).ID << endl;

}