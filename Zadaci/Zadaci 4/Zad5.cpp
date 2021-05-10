/*
 Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa košarkaš (košarkaš je struktura čija su obilježja data u nastavku).
 Omogućiti korisniku da unese dimenzije niza.

struct kosarkas
{
    char *ID;
    char *imePrezime;
    int *postignutiKosevi;
};
Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove.
Omogućiti korisniku unos svih podataka za sve košarkaše, te napraviti funkciju koja će pronaći najuspješniji klub (klub u kojem je postignut najveći broj koševa).
Također je potrebno pronači najuspješnijeg košarkaša u tom timu (ne mora biti najuspješniji u ligi) i
najlošijeg košarkaša u kompletnoj ligi te izračunati razliku u broju postignutih koševa ta dva košarkaša.
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)
 */
#include <iostream>
using namespace std;

struct kosarkas
{
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas()
    {
        ID = new char;
        imePrezime = new char[20];
        postignutiKosevi = new int;
    }
    void unosKosarkas()
    {
        cout << "ID = ";
        cin >> *ID;
        cin.ignore();

        cout << "Ime i prezime: ";
        cin.getline(imePrezime, 20);

        *postignutiKosevi = rand() % 50;
    }
	void ispisKosarkas()
    {
        cout << "ID = " << *ID << endl;
        cout << "Ime i prezime: " << imePrezime << endl;
        cout << "Kosevi: " << *postignutiKosevi << endl;

    }
	~kosarkas()
    {
        delete[]ID;
        ID = nullptr;

        delete[]imePrezime;
        imePrezime = nullptr;

        delete[]postignutiKosevi;
        postignutiKosevi = nullptr;
    }
};
void najuspjesnijiKlub(kosarkas**, int, int);
void igrac(kosarkas**, int, int);
int main()
{
    //Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove.
    srand(time(0));
    int brKosarkasa, brKlubova;

    cout << "brKosarkasa: ";
    cin >> brKosarkasa;
    cout << "brKlubova: ";
    cin >> brKlubova;

    kosarkas** k = new kosarkas * [brKosarkasa];
	for (int i=0; i<brKosarkasa; i++)
	{
        *(k + i) = new kosarkas[brKlubova];
	}

	for (int i=0; i<brKosarkasa; i++)
	{
		for (int j=0; j<brKlubova; j++)
		{
            (*(*(k + i) + j)).unosKosarkas();
		}
	}
    cout << "-------------------------------------------------------------------" << endl;
	for (int i=0;i<brKosarkasa;i++)
	{
        cout << "brKosarkasa  [" << i << "]" << endl;
		for (int j=0;j<brKlubova;j++)
		{
            cout << "brKlubova [" << j << "]" << endl;
            (*(*(k + i) + j)).ispisKosarkas();
		}
	}
    cout << "-------------------------------------------------------------------" << endl;
    najuspjesnijiKlub(k, brKosarkasa, brKlubova);
    cout << "-------------------------------------------------------------------" << endl;
    igrac(k, brKosarkasa, brKlubova);
    cout << "-------------------------------------------------------------------" << endl;

	

    system("pause>0");
	return 0;
}
void najuspjesnijiKlub(kosarkas** k, int brKosarkasa, int brKlubova)
{
    float* uspjesan = new float[brKosarkasa] {};

    for (int i=0;i<brKosarkasa;i++)
    {
	    for (int j=0;j<brKlubova;j++)
	    {
            *(uspjesan + i) += *(*(*(k + i) + j)).postignutiKosevi;
	    }
        *(uspjesan + i) /= brKlubova;
    }

	int indexKosarkas = 0;
	for (int i=0; i<brKosarkasa; i++)
	{
		if(*(uspjesan+i)>*(uspjesan+indexKosarkas))
		{
            indexKosarkas = i;
		}
	}
    cout << "Najbolji klub se nalazi na index-u: " << indexKosarkas << endl;

    delete[]uspjesan;
    uspjesan = nullptr;
	
}
void igrac(kosarkas** k, int brKosarkasa, int brKlubova)
{
    int* najbolji = new int[brKosarkasa] {};
    int* najgori = new int[brKosarkasa] {};

	//najbolji tim
    float* uspjesan = new float[brKosarkasa] {};

    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            *(uspjesan + i) += *(*(k + i) + j)->postignutiKosevi;
        }
        *(uspjesan + i) /= brKlubova;
    }

    int indexKosarkas = 0;
    for (int i = 0; i < brKosarkasa; i++)
    {
        if (*(uspjesan + i) > *(uspjesan + indexKosarkas))
        {
            indexKosarkas = i;
        }
    }
    //trazimo najboljeg kosarkasa
    for (int i = 0; i < brKosarkasa; i++)
    {
        *(najbolji + i) = *(*(k + i) + indexKosarkas)->postignutiKosevi;
    }

   int najboljiK = *(najbolji + 0);
  

    for (int i = 0; i < brKosarkasa; i++)
    {
        if (*(najbolji + i) > najboljiK) {
            najboljiK = *(najbolji + i);
        }
    }
    
	//trazimo najgoreg kosarkasa
    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            *(najgori + i) += *(*(*(k + i) + j)).postignutiKosevi;
        }
    }

    int najgoriK = *(najgori + 0);
  

    for (int i = 0; i < brKosarkasa; i++)
    {
        if (*(najgori + i) < najgoriK)
        {
            najgoriK = *(najgori + i);
        }
    }
   
    int razlikaK = abs(najboljiK - najgoriK); // abs() u slucaju da se oduzima od manjeg a ne od veceg;

    cout << "Najbolji kosarkas u klubu " << indexKosarkas << " ima " << najboljiK << " koseva" << endl;
    cout << "Najgori kosarkas u cijeloj ligi ima koseva:  " << najgoriK << endl;
    cout << "Razlika izmdu najboljeg i najgoreg je: " << razlikaK << endl;


    delete[]uspjesan;
    uspjesan = nullptr;
    delete[]najbolji;
    najbolji = nullptr;
    delete[]najgori;
    najgori = nullptr;

    

}
