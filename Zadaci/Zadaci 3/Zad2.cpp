
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
