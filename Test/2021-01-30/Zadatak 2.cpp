
#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	int kockaBroj1, kockaBroj2, kockaBroj3, brojac = 0, brojBacanja = 0;

	srand(time(0));
		do
		{
			kockaBroj1 = rand() % 6 + 1;
			kockaBroj2 = rand() % 6 + 1;
			kockaBroj3 = rand() % 6 + 1;

			if (kockaBroj1==kockaBroj2 && kockaBroj1==kockaBroj3)
			{
				brojac++;
			}
			else
			{
				brojac = 0;
			}
			brojBacanja++;

		} while (brojac!=2);

		cout << brojBacanja << endl;

	system("pause>0");
	return 0;
}