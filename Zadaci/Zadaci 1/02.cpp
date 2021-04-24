
#include<iostream>
using namespace std;
int sastavi(int, int&);
int main()
{
	int broj, rez = 0;
	do
	{
		cout << "Upisi cifru: ";
		cin >> broj;
		if (broj > 9)
		{
			cout << "Cifra nije validna." << endl;
		}
		else if (broj > 0)
		{
			sastavi(broj, rez);
		}
	} while (broj >= 0);

	cout << "Broj sastavljen od zadanih cifara " << rez << endl;
	system("pause>0");
	return 0;
}
int sastavi(int broj, int& rez)
{
	return rez = rez * 10 + broj;
}
