
#include<iostream>
using namespace std;
struct fudbaler
{
	int ID;
	char* ime;
	char* prezime;
	char* pozicijaIgraca;// samo O - odabrana, V - Vezni, N - Napad
	int* brojGolova;

	void unosIgraca()
	{
		cout << "ID: ";
		cin >> ID;

		ime = new char[10];
		cout << "Unesite ime igraca: ";
		cin.ignore();
		cin.getline(ime, 10);

		prezime = new char[10];
		cout << "Unesite prezime igraca: ";
		cin.getline(prezime, 10);

		pozicijaIgraca = new char;
		do
		{
			cout << "Unesite poziciju igraca (O - odabrana, V - Vezni, N - Napad): ";
			cin >> *pozicijaIgraca;
			if (*pozicijaIgraca != 'O' && *pozicijaIgraca != 'V' && *pozicijaIgraca != 'N')
			{
				cout << "Pogresan unos. Molimo Vas unesite ponovo poziciju igraca: " << endl;
			}
			
		} while (*pozicijaIgraca != 'O' && *pozicijaIgraca != 'V' && *pozicijaIgraca != 'N');
		cin.ignore();

		brojGolova = new int;
		*brojGolova = rand() % 6;
	}
	void ispisIgraca()
	{
		cout << "ID: " << ID << endl;
		cout << "Ime: " << ime << endl;
		cout << "Prezime: " << prezime << endl;
		cout << "Pozicija igraca: " << *pozicijaIgraca << endl;
		cout << "Broj golova igraca: " << *brojGolova << endl;
	}
	void dealokacijaIgraca()
	{
		delete[] ime;
		ime = nullptr;

		delete[]prezime;
		prezime = nullptr;

		delete pozicijaIgraca;
		pozicijaIgraca = nullptr;

		delete brojGolova;
		brojGolova = nullptr;
	}
};
void brojGolovaPoPozicijiIgraca(fudbaler**, int, int);
void prosjekKlubOdOdabranePozicije(fudbaler**, int, int);
int main()
{
	//Redovi predstavljaju razlicite klubove, a kolone razlicite fudabalere.
	int brKlubova, brFudbalera;

	cout << "Unesite broj klubova: ";
	cin >> brKlubova;
	cout << "Unesite broj fudbalera: ";
	cin >> brFudbalera;

	fudbaler** igrac = new fudbaler * [brKlubova];
	for (int i = 0; i < brKlubova; i++)
	{
		*(igrac + i) = new fudbaler[brFudbalera];
	}
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			(*(*(igrac + i) + j)).unosIgraca();
		}
	}
	cout << "---------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			(*(*(igrac + i) + j)).ispisIgraca();
		}
	}
	cout << "---------------------------------------------------------------------------------------" << endl;
	brojGolovaPoPozicijiIgraca(igrac, brKlubova, brFudbalera);
	cout << "---------------------------------------------------------------------------------------" << endl;
	prosjekKlubOdOdabranePozicije(igrac, brKlubova, brFudbalera);

	cout << "---------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			(*(*(igrac + i) + j)).dealokacijaIgraca();
		}
	}
	for (int i = 0; i < brKlubova; i++)
	{
		delete[] * (igrac + i);
	}
	delete[]igrac;
	igrac = nullptr;


	system("pause>0");
	return 0;
}
void brojGolovaPoPozicijiIgraca(fudbaler** igrac, int brKlubova, int brFudbalera)
{
	//3 pozicije O - odbrana, V - Vezni, N - Napad
	int brojacOdbrana = 0, brojacVezni = 0, brojacNapad = 0;//brojaci za nase pozicije
	float sumaOdbrana = 0, sumaVezni = 0, sumaNapad = 0;//sume za nase pozicije

	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			if (*(*(igrac+i)+j)->pozicijaIgraca=='O')//odabiremo poziciju O - Odbrana
			{
				sumaOdbrana += *(*(igrac + i) + j)->brojGolova;//sumiramo golove na poziciji O - Odbrana
				brojacOdbrana++;
			}
			if (*(*(igrac+i)+j)->pozicijaIgraca=='V')//odabiremo poziciju V - Vezni
			{
				sumaVezni += *(*(igrac + i) + j)->brojGolova;//sumiramo golove na poziciji V - Vezni
				brojacVezni++;
			}
			else if (*(*(igrac + i) + j)->pozicijaIgraca == 'N')//odabiremo poziciju N - Napad
			{
				sumaNapad += *(*(igrac + i) + j)->brojGolova;//sumiramo golove na poziciji N - Napad
				brojacNapad++;
			}
		}
	//ispis pozicija
	if (brojacOdbrana > 0)//ako imamo broj golova veci od nula pravimo ispis
	{
		sumaOdbrana /= brojacOdbrana;
	}
	if (brojacOdbrana>0)
	{
		sumaVezni /= brojacVezni;
	}
	if (brojacNapad>0)
	{
		sumaNapad /= brojacNapad;
	}

	cout << "Ispis za klub " << i << endl;
	cout << "Prosjek odbrambenih igraca je: " << sumaOdbrana << endl;
	cout << "Prosjek veznih igraca je: " << sumaVezni << endl;
	cout << "Prosjek igraca koji igraju  u napadu: " << sumaNapad << endl;
	}
	
}
void prosjekKlubOdOdabranePozicije(fudbaler** igrac, int brKlubova, int brFudbaler)
{
	char odabir;
	do
	{
		cout << "Unesite poziciju igraca (O - odabrana, V - Vezni, N - Napad): ";
		cin >> odabir;
		if (odabir != 'O' && odabir != 'V' && odabir != 'N')
		{
			cout << "Pogresan unos. Molimo Vas unesite ponovo poziciju igraca: " << endl;
		}
		
	} while (odabir != 'O' && odabir != 'V' && odabir != 'N');

	float* prosjekOdabrenePozicije = new float[brKlubova] {};
	int brojGolovaZaPoziciju = 0;
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbaler; j++)
		{
			if (*(*(igrac+i)+j)->pozicijaIgraca==odabir)
			{
				*(prosjekOdabrenePozicije + i) += *(*(igrac + i) + j)->brojGolova;
				brojGolovaZaPoziciju++;
			}
		}
		if (brojGolovaZaPoziciju>0)
		{
			*(prosjekOdabrenePozicije + i) /= brojGolovaZaPoziciju;
		}
	}
	int najboljiKlub=0;//index kluba

	for (int i = 0; i < brKlubova; i++)
	{
		if (*(prosjekOdabrenePozicije + i) > *(prosjekOdabrenePozicije + najboljiKlub))
		{
			najboljiKlub = i;
		}
	}
	cout << "Najbolji klub je na indexu: " << najboljiKlub << endl;

	delete[]prosjekOdabrenePozicije;
	prosjekOdabrenePozicije = nullptr;

}