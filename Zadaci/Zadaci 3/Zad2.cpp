/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. 
Zatim,korisnik unosi željeni broj te rekurzivnom funkcijom provjerava da li je taj broj član kreiranog niza. 
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/
#include<iostream>
using namespace std;
void puniNiz(int*, int, int);
void ispisNiza(int*, int, int);
int main()
{
	int n;

	cout << "Unesite n: ";
	cin >> n;

	int* velicinaNiza = new int[n];

	*(velicinaNiza + 0) = 1;
	*(velicinaNiza + 1) = 2;

	puniNiz(velicinaNiza, n, 2);
	ispisNiza(velicinaNiza, n, 1);

	delete[]velicinaNiza;
	velicinaNiza = nullptr;


	return 0;
}
void puniNiz(int* niz, int n, int trenutna)
{
	if (trenutna == n || *(niz + trenutna - 1) * 2 < 0)
	{
		return;
	}
	*(niz + trenutna) = *(niz + trenutna - 1) * 2;
	puniNiz(niz, n, trenutna + 1);

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
