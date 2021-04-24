
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, X;
			

	do
	{
		cout << "Unesite broj A: ";
		cin >> n;
		cout << "Unesite broj B: ";
		cin >> X;

	} while (n <= 10 && X < 1);

	double S = 0;
	for (int i = 0; i < n; i++)
	{
		S += pow(-1, i) * i / pow(X, i);
	}

	cout << S;
	return 0;
}
