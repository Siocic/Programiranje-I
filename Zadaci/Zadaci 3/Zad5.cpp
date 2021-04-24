
#include<iostream>
using namespace std;

void unesiNiz(int*, int, int, int);
void ispisNiza(int*, int, int);
int main()
{
	srand(time(0));

	int n;
	do
	{
		cout << "Unesite n: ";
		cin >> n;
	} while (n<=0);

	int* velicinaNiza = new int[n];

	unesiNiz(velicinaNiza, n, 0, 0);
	ispisNiza(velicinaNiza, n, 0);

	delete[]velicinaNiza;
	velicinaNiza = nullptr;

	return 0;
}
void unesiNiz(int* niz, int n, int trenutna, int zaredom)
{
	if (trenutna == n || zaredom >= 3)
	{
		return;
	}
	*(niz + trenutna) = rand() % 100 + 1;
	if (*(niz + trenutna) == *(niz + trenutna - 1))
	{
		zaredom += 2;
	}
	if (*(niz + trenutna) != *(niz + trenutna - 1))
	{
		zaredom = 0;
	}
	unesiNiz(niz, n, trenutna + 1, zaredom);
}
void ispisNiza(int* niz, int n, int trenutna)
{
	if (trenutna == n)
	{
		return;
	}
	cout << *(niz + trenutna) << endl;
	ispisNiza(niz, n, trenutna + 1);
}
