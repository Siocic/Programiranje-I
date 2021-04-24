
#include<iostream>
using namespace std;

int obrniBroj(int);
int sumaCifri(int);
int main()
{
	int X, Y;

	do
	{
		cout << "X = ";
		cin >> X;
		cout << "Y = ";
		cin >> Y;

	} while (X<10 || X>5000 || Y<10 || Y>5000);
	if (X>Y)
	{
		int temp = X;
		X = Y;
		Y = temp;
	}
	cout << "Brojevi koji ispunjuvaju uslov su: ";
	for (int i = X; i <= Y; i++)
	{
		if (obrniBroj(i) % sumaCifri(i) == 0)
		{
			cout << i << " ";
		}
	}


	return 0;
}
int obrniBroj(int broj)
{
	int noviBroj = 0;
	while (broj>0)
	{
		int cifra= broj % 10;
		noviBroj = noviBroj * 10 + cifra;
		broj /= 10;
	}

	return noviBroj;
}
int sumaCifri(int broj)
{
	int suma = 0;
	while (broj>0)
	{
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}
