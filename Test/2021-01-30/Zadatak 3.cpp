
#include<iostream>
using namespace std;

void puniNiz(int*, int, int);

int main()
{

	int velicina;

	cout << "Unesite velicinu: ";
	cin >> velicina;

	int* niz=new int[velicina];
	puniNiz(niz, velicina, 0);
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i)<<" " ;
	}

	delete[]niz;
	niz = nullptr;
	system("pause>0");
	return 0;
}
void puniNiz(int* niz, int vel, int trenutna)
{
	if (vel==trenutna)
	{
		return;
	}
	if (trenutna<=vel)
	{
		if (trenutna == 0)
		{
			*(niz + trenutna) = 2;
		}
		if (trenutna>0)
		{
			int temp= *(niz + trenutna-1) * 2;
			if (temp<0)
			{
				return;
			}
			*(niz + trenutna) = temp;
		}
		puniNiz(niz, vel, trenutna + 1);
	}
}