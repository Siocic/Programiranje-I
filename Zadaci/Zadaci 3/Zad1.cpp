/*
Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2).
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja, a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).
Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (voditi računa o tipu podatka zbog veličine broja).
(Obavezno koristiti aritmetiku pokazivača)
*/
#include<iostream>
using namespace std;

void puniNiz(int*, int, int);
void ispisNiza(int*, int, int);
int main()
{
	int n;
	do
	{
		cout << "Unesite n: ";
		cin >> n;
	} while (n<2);
	int* velicinaNiza = new int[n];

	*(velicinaNiza + 0) = 1;
	*(velicinaNiza + 1) = 3;
	//1*3=3 3*3=9
	puniNiz(velicinaNiza, n, 2);
	ispisNiza(velicinaNiza, n, 0);

	delete[]velicinaNiza;
	velicinaNiza = nullptr;

	return 0;
}
void puniNiz(int* niz, int n, int trenutna)
{
	if (trenutna==n || *(niz+trenutna-2)**(niz+trenutna-1)<0)
	{
		return;
	}

	*(niz + trenutna) = *(niz + trenutna - 2) * *(niz + trenutna - 1);
	puniNiz(niz, n, trenutna+1);
}
void ispisNiza(int* niz, int n, int trenutna)
{
	if (trenutna == n)
	{
		return;
	}
	cout << *(niz + trenutna) << " ";
	ispisNiza(niz, n, trenutna + 1);
}