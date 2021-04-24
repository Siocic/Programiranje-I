/*
Postujuci sve faze procesa programiranja, napisati proram koji korisniku omogucava unos cijelog broja N, te izracunava vrijednost sume faktorijela prostih brojeva u intervalu [1, N].
*/
#include <iostream>

using namespace std;

bool prostBroj(int);
int faktorijel(int broj);

int main()
{
    int N;

    cout << "Unesite prirodan broj: ";
    cin >> N;


    int suma = 0;
    for (int i = 1; i <= N; i++)
    {
        if (prostBroj(i))
        {
            suma += faktorijel(i);
        }
    }


    cout << suma << endl;

    system("pause>0");
    return 0;
}
bool prostBroj(int x)
{
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    if (x == 1)
    {
        return false;
    }
    return true;
}
int faktorijel(int broj)
{
    long unsigned int proizvod = 1;

    for (int i = 1; i <= broj; i++)
    {


        proizvod *= i;

    }

    return proizvod;
}