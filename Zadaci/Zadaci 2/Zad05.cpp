
#include<iostream>
using namespace std;

int obrniBroj(int&);
int main()
{
	int N;

	do
	{
		cout << "Unesite N: ";
		cin >> N;
	} while (50 > N||N > 5000000);

	cout << "Broj procitan naopako bez neparnih cifara je: " << obrniBroj(N) << endl;

	return 0;
}
int obrniBroj(int& N)
{
	int noviBroj = 0;
	int ostatak=0;
	while (N>0)
	{
		ostatak = N % 10;
		if (ostatak%2!=0)
		{
			N /= 10;
		}
		else
		{
			noviBroj = noviBroj * 10 + ostatak;
			N /= 10;
		}
	}
	return noviBroj;
}
