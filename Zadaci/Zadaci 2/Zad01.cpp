
#include<iostream>
using namespace std;
int baciKocku();
int main()
{
	srand(time(0));
	
	cout << "Tri broja smo dobili uzastopno nakon " << baciKocku() << " bacanja. " << endl;

	return 0;
}
int baciKocku()
{
	int brojBacanja = 0;
	int brojIstih = 0;
	do
	{
		int kocka1, kocka2, kocka3;
		kocka1 = rand() % 6 + 1;
		kocka2 = rand() % 6 + 1;
		kocka3 = rand() % 6 + 1;

		if (kocka1 == kocka2 && kocka2 == kocka3)
		{
			brojIstih++;
		}
		else
		{
			brojIstih = 0;
		}
		brojBacanja++;

	} while (brojIstih<2);

	return brojBacanja;
}
