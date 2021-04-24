/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove. Omogućiti korisniku unos svih podataka za sve košarkaše, 
te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa). 
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) i najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa ta dva košarkaša.
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)
*/
#include<iostream>
using namespace std;
struct kosarkas
{
    char* ID;
    char* ime;
    char* prezime;
    int* postignutiKosevi;
    kosarkas()
    {
        ID = new char[10];
        ime = new char[10];
        prezime = new char[20];
        postignutiKosevi = new int;
    }
    void unosKosarkas()
    {
        cout << "ID: ";
        cin.getline(ID, 10);

        cout << "Ime: ";
        cin.getline(ime, 10);

        cout << "Prezime: ";
        cin.getline(prezime, 20);

        *postignutiKosevi = rand() % 60 + 1;
    }
    void ispisKosarkas()
    {
        cout << "ID: " << ID << endl;
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Kosevi: " << *postignutiKosevi << endl;
    }
    ~kosarkas()
    {
        delete[]ID;
        ID = nullptr;

        delete[]ime;
        ime = nullptr;

        delete[]prezime;
        prezime = nullptr;

        delete postignutiKosevi;
        postignutiKosevi = nullptr;
    }
};
int najuspjesnijiKlub(kosarkas**, int, int);
void igrac(kosarkas**, int, int,int);
int main()
{
    srand(time(0));
    //Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove
    int brKosarkasa, brKlubova;
    cout << "Unesite broj kosarkasa: ";
    cin >> brKosarkasa;
    cout << "Unesite broj klubova: ";
    cin >> brKlubova;
    cin.ignore();

    kosarkas** k = new kosarkas * [brKosarkasa];
    for (int i = 0; i < brKosarkasa; i++)
    {
        *(k + i) = new kosarkas[brKlubova];
    }
    
    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            (*(*(k + i) + j)).unosKosarkas();
        }
    }
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            (*(*(k + i) + j)).ispisKosarkas();
        }
    }
    cout << "-------------------------------------------------------------------------" << endl;
    int najboljiKlub=najuspjesnijiKlub(k, brKosarkasa, brKlubova);
    cout << "-------------------------------------------------------------------------" << endl;
    igrac(k, brKosarkasa, brKlubova, najboljiKlub);
    cout << "-------------------------------------------------------------------------" << endl;
    
    return 0;
}
int najuspjesnijiKlub(kosarkas** k, int brKosarkasa, int brKlubova)
{
    float* najuspjesniji = new float[brKosarkasa] {};

    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            *(najuspjesniji + i) += *(*(k + i) + j)->postignutiKosevi;
        }
        *(najuspjesniji + i) /= brKlubova;
    }

    int klub = 0;

    for (int i = 0; i < brKosarkasa; i++)
    {
        if (*(najuspjesniji+i)<*(najuspjesniji+klub))
        {
            klub = i;
        }
    }
    cout << "Najusojesniji klub se nalazi: " << klub <<" i "<< endl;
    for (int i = 0; i < brKosarkasa; i++)
    {
        cout << "ID igraca je: " << (*(k + i) + klub)->ID << endl;
        cout << "Ime igraca je: " << (*(k + i) + klub)->ime << endl;
        cout << "Prezime igraca je: " << (*(k + i) + klub)->prezime << endl;
        cout << "Broj postignutih koseva od igraca je: " << *(*(k + i) + klub)->postignutiKosevi << endl;
    }
    return klub;
    delete[]najuspjesniji;
    najuspjesniji = nullptr;
}
void igrac(kosarkas** k, int brKosarkas, int brKlubova,int trenutna)
{
    int* najbolji =new int[brKosarkas] {};
    int* najgori = new int[brKosarkas] {};
   

    for (int i = 0; i < brKosarkas; i++)
    {
        *(najbolji + i) = *(*(k + i) + trenutna)->postignutiKosevi; 
    }

    int najboljiK = *(najbolji + 0);
    
    for (int i = 0; i < brKosarkas; i++)
    {
        if (*(najbolji + i) > najboljiK) {
            najboljiK = *(najbolji + i);
        }
    }
 
    for (int i = 0; i < brKosarkas; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            *(najgori + i) += *(*(k + i) + j)->postignutiKosevi; 
        }
    }
  
    int najgoriK = *(najgori + 0);
  
    for (int i = 0; i < brKosarkas; i++)
    {
        if (*(najgori + i) < najgoriK)
        {
            najgoriK = *(najgori + i);
        }
    }
    int razlikaK = abs(najboljiK - najgoriK); // abs() u slucaju da se oduzima od manjeg a ne od veceg;

    cout << "Najbolji kosarkas u klubu " << trenutna << " ima " << najboljiK << " koseva" << endl;
    cout << "Najgori kosarkas u cijeloj ligi ima koseva:  " << najgoriK << endl;
    cout << "Razlika izmdu najboljeg i najgoreg je: " << razlikaK << endl;

    delete[]najbolji;
    najbolji = nullptr;
    delete[]najgori;
    najgori = nullptr;

    
    
}
