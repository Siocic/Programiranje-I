
#include<iostream>
using namespace std;

bool prostBroj(int);
long int faktorijel(int);
int generisiFibonaci(int);
void provjera(long int&, int);
int main()
{
	long int suma = 0;
	for (int i = 0; i < 100; i++)
	{
		provjera(suma, i);
	}

	cout << "Suma = " << suma << endl;

	return 0;
}
bool prostBroj(int broj)
{
	for (int i = 2; i <= broj/2; i++)
	{
		if (broj % i == 0)
		{
			return false;
		}
	}
	return true;
}
long int faktorijel(int broj)
{
	long int prozivod = 1;
	for (int i = 2; i <= broj; i++)
	{
		prozivod *= i;//5!=5*4*3*2*1=120
	}
	return prozivod;//120
}
int generisiFibonaci(int pozicija)
{
	if (pozicija == 0 || pozicija == 1)
	{
		return pozicija;
	}
	int prvi = 0, drugi = 1, fibonaci=0;

	for (int i = 0; i < pozicija; i++)
	{
		fibonaci = prvi + drugi;//0=1+0 -> 1
		if (fibonaci < drugi)//1<1
		{
			return 0;//
		}
		prvi = drugi;//0=1
		drugi = fibonaci;//1=1
		//fib=prvi+drugi tj. 1=1+1 ->2
	}
	return fibonaci;
}
void provjera(long int& suma, int pozicija)
{
	int broj;
	broj = generisiFibonaci(pozicija);//provjera fib niza
	if (prostBroj(broj))//provjera prostog broja
	{
		suma += faktorijel(broj);//racunanje faktorijela
	}
}
