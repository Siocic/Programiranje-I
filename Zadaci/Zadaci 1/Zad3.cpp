/*
Napisati program koji će omogućiti unos prirodnog broja A (A > 100000),
te kreirati i ispisati broj B koji će se sastojati od cifara broja A u obrnutom redoslijedu u kojem je svaka parna uklonjena.
(npr. ako se unese 45362792 funkcija će vratiti 9735). Ispisati razliku brojeva A i B.
(Obavezno koristiti bar jednu korisnički definiranu funkciju.)
*/
#include<iostream>
using namespace std;

int obrniBroj(int);
int main()
{
	int A, B;
	do
	{
		cout << "A = ";
		cin >> A;
	} while (A < 100000);

	B = obrniBroj(A);
	cout << "B = " << B << endl;
	cout << "A - B = " << A - B << endl;

	return 0;
}
int obrniBroj(int A)
{
	int noviBroj = 0;
	int cifra=0;

	while (A>0)
	{
		cifra = A % 10;
		if (cifra % 2 ==0 )
		{
			
			A /= 10;
		}
		else
		{
			noviBroj =noviBroj* 10 + cifra;
			A /= 10;

		}
	}
	return noviBroj;
}