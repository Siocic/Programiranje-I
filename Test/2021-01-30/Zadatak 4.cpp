
#include<iostream>
using namespace std;

struct student
{
	char* ID;
	char* imePrezime;
	float* prosjek;

	void unosStudent()
	{
		ID = new char[10];
		cout << "Unesite ID studenta: ";
		cin >> ID;

		imePrezime = new char[10];
		cout << "Unesite ime i prezime studenta: ";
		cin >> imePrezime;

		prosjek = new float;
		cout << "Unesite prosjek studenta: ";
		cin >> *prosjek;
	}
	void ispisStudenta()
	{
		cout <<"ID: " << ID << endl;
		cout << "Ime i prezime studenta: " << imePrezime << endl;
		cout << "Prosjek studenta: " << *prosjek << endl;
	}
	void dealokacijaStudenta()
	{
		delete[]ID;
		ID = nullptr;

		delete[]imePrezime;
		imePrezime = nullptr;

		delete prosjek;
		prosjek = nullptr;
	}
};
void fakultetSaNajvecimProsjekom(student**, int, int);
void studentSaNajvecimProsjekom(student**, int, int);
int main()
{
	//redovi = fakulteti
	//kolone = studenti

	int brFakulteti, brStudenata;

	cout << "Unesite broj fakulteta: ";
	cin >> brFakulteti;
	cout << "Unesite broj studenta: ";
	cin >> brStudenata;

	student** s = new student * [brFakulteti];

	for (int i = 0; i < brFakulteti; i++)
	{
		*(s + i) = new student[brStudenata];
	}

	for (int i = 0; i < brFakulteti; i++)
	{
		for (int j = 0; j < brStudenata; j++)
		{
			(*(*(s + i) + j)).unosStudent();
		}
	}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < brFakulteti; i++)
	{
		for (int j = 0; j < brStudenata; j++)
		{
			(*(*(s + i) + j)).ispisStudenta();
		}
	}
	cout << "---------------------------------------------------------------------------------------------" << endl;
	fakultetSaNajvecimProsjekom(s, brFakulteti, brStudenata);
	cout << "---------------------------------------------------------------------------------------------" << endl;
	studentSaNajvecimProsjekom(s, brFakulteti, brStudenata);
	cout << "---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < brFakulteti; i++)
	{
		delete[] * (s + i);
	}
	delete s;
	s = nullptr;

	system("pause>0");
	return 0;
}
void fakultetSaNajvecimProsjekom(student** s, int brFakulteta, int brStudenata)
{
	int* prosjekFakulteta = new int[brFakulteta];
	for (int i = 0; i < brFakulteta; i++)
	{
		*(prosjekFakulteta + i) = 0;
		for (int j = 0; j < brStudenata; j++)
			*(prosjekFakulteta + i) += *(*(s + i) + j)->prosjek;
		*(prosjekFakulteta + i) /= brStudenata;
	}

	int najboljiFakultet = 0;
	for (int i = 1; i < brFakulteta; i++)
	{
		if (*(prosjekFakulteta + i) > *(prosjekFakulteta + najboljiFakultet))
		{

			najboljiFakultet = i;
		}
	}

	cout << "Najbolji fakultet se nalazi na indeksu: " << najboljiFakultet << endl;

	delete[] prosjekFakulteta;
	prosjekFakulteta = nullptr;
	
}
void studentSaNajvecimProsjekom(student** s, int brFakulteta, int brStudenta)
{
	//fakultet = red
	//studnet = kolona
	int fakultet = 0, student = 0;
	for (int i = 0; i < brFakulteta; i++)
	{
		for (int j = 0; j < brStudenta; j++)
		{
			if ((*(*(s + fakultet) + student)).prosjek < (*(*(s + i) + j)).prosjek)
			{
				fakultet = i;
				student = j;
			}
		}
	}
	cout << "Student sa najvecim prosjekom ima ID: " << (*(*(s + fakultet) + student)).ID << endl;
}