
#include<iostream>
using namespace std;

int unos();
int procenat(int);
int main()
{
	srand(time(0));
	int kocka1 = 0, kocka2 = 0, kocka3 = 0, kocka4 = 0, kocka5 = 0, kocka6 = 0;
	int baceno = 0;
	int n, kocka;
	do
	{
		cout << "Unesite n: ";
		cin >> n;

	} while (n > 10 && n > 1000);

	while (baceno<n)
	{
		kocka = unos();
		switch (kocka)
		{
		case 1:
		{
			kocka1++;
		}
		break;
		case 2:
		{
			kocka2++;
		}
		break;
		case 3:
		{
			kocka3++;
		}
		break;
		case 4:
		{
			kocka4++;
		}
		break;
		case 5:
		{
			kocka5++;
		}
		break;
		case 6:
		{
			kocka6++;
		}
		break;
		default:
		{
			cout << "Nije validno bacanje " << endl;
		}
		}
		cout << kocka << " ";
		baceno++;

	}

	cout << endl;
	cout << "Procenat bacanja za broj 1:" << round(procenat(kocka1) / n * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 2: " << round(procenat(kocka2) / n * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 3: " << round(procenat(kocka3) / n * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 4: " << round(procenat(kocka4) / n * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 5: " << round(procenat(kocka5) / n * 100.0) / 100.0 << "%" << endl;
	cout << "Procenat bacanja za broj 6: " << round(procenat(kocka6) / n * 100.0) / 100.0 << "%" << endl;


	return 0;
}
int unos()
{
	int kocka;
	kocka = rand() % 6 + 1;
	return kocka;
}
int procenat(int broj)
{
	int procenat;
	procenat = broj * 100;
	return procenat;
}
