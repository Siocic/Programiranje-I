
#include<iostream>
using namespace std;
struct fudbaler
{
	int ID;
	char* ime;
	char* prezime;
	char* pozicijaIgraca;//V,N,O
	int* brojGolova;

	fudbaler()
	{
		ime = new char[10];
		prezime = new char[20];
		pozicijaIgraca = new char;
		brojGolova = new int;
	}
	void unosFudbalera()
	{
		cout << "ID: ";
		cin >> ID;

		cout << "Ime: ";
		cin >> ime;

		cout << "Prezime: ";
		cin >> prezime;
		do
		{
			cout << "Pozicija (samo: O, V, N): ";
			cin >> *pozicijaIgraca;
			if (*pozicijaIgraca != 'O' && *pozicijaIgraca != 'V' && *pozicijaIgraca != 'N')
			{
				cout << "Pogresan unos. Molimo Vas unesite ponovo poziciju igraca" << endl;
			}

		} while (*pozicijaIgraca!='O' && *pozicijaIgraca != 'V' && *pozicijaIgraca != 'N');

		*brojGolova = rand() % 5;
		
	}
	void ispisFudbalera()
	{
		cout << "ID: " << ID << endl;
		cout << "Ime: " << ime << endl;
		cout << "Prezime: " << prezime << endl;
		cout << "Pozicija: " << *pozicijaIgraca << endl;
		cout << "Broj golova: " << *brojGolova << endl;
	}
	~fudbaler()
	{
		delete[]ime;
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
void odabrnaPozicija(fudbaler**, int, int);
int main()
{
	srand(time(0));
	//Redovi predstavljaju razlicite klubove, a kolone razlicite fudabalere.
	int brKlubova, brFudbalera;

	cout << "Unesite broj klubova: ";
	cin >> brKlubova;
	cout << "Unesite broj fudbalera: ";
	cin >> brFudbalera;

	fudbaler** f = new fudbaler * [brKlubova];
	for (int i = 0; i < brKlubova; i++)
	{
		*(f + i) = new fudbaler[brFudbalera];
	}

	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			(*(*(f + i) + j)).unosFudbalera();
		}
	}
	cout << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			(*(*(f + i) + j)).ispisFudbalera();
		}
	}
	cout << "-------------------------------------------------------------------------" << endl;
	brojGolovaPoPozicijiIgraca(f, brKlubova, brFudbalera);
	cout << "-------------------------------------------------------------------------" << endl;
	odabrnaPozicija(f, brKlubova, brFudbalera);
	cout << "-------------------------------------------------------------------------" << endl;



	return 0;
}
void brojGolovaPoPozicijiIgraca(fudbaler** f, int brKlubova, int brFudbalera)
{
	int odbrana = 0, vezni = 0, napad = 0;//brojaci za svaku poziciju
	float sumaO = 0, sumaV = 0, sumaN = 0;//sume za svaku poziciju

	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			if (*(*(f + i) + j)->pozicijaIgraca == 'O')
			{
				sumaO += *(*(f + i) + j)->brojGolova;
				odbrana++;
			}
			if (*(*(f + i) + j)->pozicijaIgraca == 'V')
			{
				sumaV += *(*(f + i) + j)->brojGolova;
				vezni++;
			}
			else if (*(*(f + i) + j)->pozicijaIgraca == 'N')
			{
				sumaN += *(*(f + i) + j)->brojGolova;
				napad++;
			}
		}
		if (odbrana > 0)
		{
			sumaO /= odbrana;
		}
		if (vezni > 0)
		{
			sumaV /= vezni;
		}
		if (napad > 0)
		{
			sumaN /= napad;
		}
		cout << "Ispis za klub " << i << endl;
		cout << "Prosjek odbrambenih igraca je: " << sumaO << endl;
		cout << "Prosjek veznih igraca je: " << sumaV << endl;
		cout << "Prosjek igraca koji igraju  u napadu: " << sumaN << endl;
	}
}
void odabrnaPozicija(fudbaler** f, int brKlubova, int brFudbalera)
{
	char pozicija;
	do
	{
		cout << "Pozicija (samo: O, V, N): ";
		cin >> pozicija;
		if (pozicija != 'O' && pozicija != 'V' && pozicija != 'N')
		{
			cout << "Pogresan unos. Molimo Vas unesite ponovo poziciju igraca" << endl;
		}

	} while (pozicija != 'O' && pozicija != 'V' && pozicija != 'N');

	float* odabranaPozicija = new float[brKlubova] {};
	int pozicijaGolovi = 0;
	for (int i = 0; i < brKlubova; i++)
	{
		for (int j = 0; j < brFudbalera; j++)
		{
			if (*(*(f+i)+j)->pozicijaIgraca==pozicija)
			{
				*(odabranaPozicija + i) += *(*(f + i) + j)->brojGolova;
				pozicijaGolovi++;
			}
		}
		if (pozicijaGolovi>0)
		{
			*(odabranaPozicija + i) /= pozicijaGolovi;
		}
	}
	int najboljiKlub = 0;//index kluba

	for (int i = 0; i < brKlubova; i++)
	{
		if (*(odabranaPozicija + i) > *(odabranaPozicija + najboljiKlub))
		{
			najboljiKlub = i;
		}
	}
	cout << "Najbolji klub je na indexu: " << najboljiKlub << endl;

	delete[]odabranaPozicija;
	odabranaPozicija = nullptr;

}

