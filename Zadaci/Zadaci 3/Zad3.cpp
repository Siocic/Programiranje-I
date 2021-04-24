/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1. 
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju. 
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
*/
#include<iostream>
using namespace std;
void Fibonacci(int*, int, int);
void ispisNiza(int*, int, int);
int main()
{
	int n;

	cout << "Unesite n: ";
	cin >> n;

	int* velicinaNiza = new int[n];

	*(velicinaNiza + 0) = 1;
	*(velicinaNiza + 1) = 1;
	//1+1=2; 2+1=3; 3+2=5; 5+3=8; ......
	Fibonacci(velicinaNiza, n, 2);
	ispisNiza(velicinaNiza, n, 0);
	

	delete[]velicinaNiza;
	velicinaNiza = nullptr;

	return 0;
}
void Fibonacci(int* niz, int n, int trenutna)
{
	if (trenutna == n || *(niz + trenutna - 2) + *(niz + trenutna - 1) < 0)
	{
		return;
	}
	*(niz + trenutna) = *(niz + trenutna - 2) + *(niz + trenutna - 1);
	Fibonacci(niz, n, trenutna + 1);
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
