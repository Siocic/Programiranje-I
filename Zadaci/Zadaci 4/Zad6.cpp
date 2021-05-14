/*
 Kreirati dvodimenzionalni dinamički niz čiji su elementi objekti tipa figura (figura je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza, te omogućiti unos elemenata.
 struct figura
{
    int ID;
    char *nazivFigure;
    float *visinaFigure;
};
Potrebno je napisati funkciju koja će računati prosječnu visinu svih figura koje se nalaze na crnim poljima ispod sporedne dijagonale.
(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta vrijednost.)
 */
#include <iostream>
using namespace std;
struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    figura()
    {
        nazivFigure = new char[10];
        visinaFigure = new float;
    }
	void unosFigura()
    {
        cout << "ID: ";
        cin >> ID;

        cout << "Naziv figura: ";
        cin.ignore();
        cin.getline(nazivFigure, 10);

        cout << "Visina figure: ";
        cin >> *visinaFigure;
    }
	void ispisFigura()
    {
        cout << "ID: " << ID << endl;
        cout << "Naziv fiugure: " << nazivFigure << endl;
        cout << "Visina figure: " << *visinaFigure << endl;
    }
	~figura()
    {
        delete[]nazivFigure;
        nazivFigure = nullptr;

        delete visinaFigure;
        visinaFigure = nullptr;
    }
	
};
float* prosjecnaVisina(figura**, int, int);//funkcija vraca pokazivac
int main()
{
    int red, kolona;

    cout << "Red: ";
    cin >> red;
    cout << "Kolona: ";
    cin >> kolona;

    figura** f = new figura * [red];
	for (int i=0; i<red; i++)
	{
        *(f + i) = new figura[kolona];
	}

	for (int i=0; i<red; i++)
	{
		for (int j=0; j<kolona; j++)
		{
            (*(*(f + i) + j)).unosFigura();
		}
           
	}
    cout << "-----------------------------------------------------------------------" << endl;
	for (int i=0; i<red; i++)
	{
		for (int j=0; j<kolona; j++)
		{
            (*(*(f + i) + j)).ispisFigura();
		}
	}
    cout << "-----------------------------------------------------------------------" << endl;
    float* prosjek = prosjecnaVisina(f, red, kolona);
    cout << "Prosjecna visina figura je: " << *prosjek << endl;//stavili *prosjek da nam ispise vrijednost a ne adresu
    cout << "-----------------------------------------------------------------------" << endl;

    delete prosjek;//posto smo napravili novo memorijsko mjesto za nas prosjek moramo ga i dealocirati

	for (int i=0; i<red; i++)
	{
        delete[] * (f + i);
	}
    delete[]f;
    f = nullptr;


    system("pause>0");
	return 0;
}
float* prosjecnaVisina(figura** f, int red, int kolona)//funkcija vraca pokazivac
{
    int brojac = 0;
    float prosjek = 0.0f;

	for (int i=0; i<red; i++)
	{
		for (int j=0; j<kolona; j++)
		{
			if ((i+j)>=red-1 && (i+j)%2==0)
			{
                prosjek += *(*(f + i) + j)->visinaFigure;
                brojac++;
			}
		}
	}
    if (brojac>0)
    {
        prosjek /= brojac;
    }

    return new float(prosjek);//napravili smo novo mjesto u memoriji gdje smo smjestili nas prosjek
}
