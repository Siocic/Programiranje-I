/*
Napisati program koji učitava prirodan broj n. 
Program treba ispisati najmanji prirodan broj m, veći ili jednak n, koji je potencija nekog prirodnog broja, tj. m = k ^ l, gdje su k i l prirodni brojevi >= 2.
*/
#include<iostream>
#include<cmath>
using namespace std;

int potencijal(int);
int main()
{
    int n;
   
    do
    {
        cout << "Unesite broj: ";
        cin >> n;

    } while (n<=0);



    cout << potencijal(n) << endl;
    system("pause>0");
    return 0;
}
int potencijal(int n)
{
    int tempBroj;
    while (1)
    {
        int l = 2;
        while (l < sqrt(n) + 1)
        {
            tempBroj = n;
            int k = 0;
            while (tempBroj % l == 0)
            {
                tempBroj /= l;
                k++;
            }

            if (tempBroj == 1 && k >= 2) return n;
            l++;
        }

        n++;
    }

    return n;
}
