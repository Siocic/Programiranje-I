
#include<iostream>
using namespace std;

void napuniNiz(int*, int, int);

int main()
{
	int velicina;
	
	cout << "Unesite velicinu niza: ";
	cin >> velicina;

	int* niz = new int[velicina];

	napuniNiz(niz, velicina, 0);
	for (int i = 0; i < velicina; i++)
	{
		cout << *(niz + i) << " ";
	}



	system("pause>0");
	return 0;
}
void napuniNiz(int* niz, int velicina, int trenutna)
{
	if (velicina == trenutna)
	{
		return;
	}
	if (trenutna <= velicina)
	{
		if (trenutna == 0)
		{
			*(niz + trenutna) = 2;
		}
		if (trenutna > 0)
		{
			int temp= *(niz + trenutna-1) * 2;

			if (temp<0)
			{
				return;
			}
			*(niz + trenutna) = temp;

		}
		napuniNiz(niz, velicina, trenutna + 1);
	}

}