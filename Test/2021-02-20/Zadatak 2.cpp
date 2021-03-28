
#include <iostream>

using namespace std;

bool provjeraSavrsen(int);
void savrsenBroj(int);
int simulacijaUnosa();

int main() {
    int n;

  
    do
    {
        n = simulacijaUnosa();

    } while (n<=10 && n<=1000);

    savrsenBroj(n);

    system("pause>0");
    return 0;
}
int simulacijaUnosa()
{
    int x;
    x = rand() % 1000 + 1;
    return x;
}

bool provjeraSavrsen(int n) {

    int suma = 0;

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0) 
        {
            suma += i;
        }
    }
    return suma == n;//ako nam je broj djeljitelja jednak n broj je savrsen
}
void savrsenBroj(int n)
{
    cout << "Savrseni brojevi od 1 do " << n << " su: ";

    for (int i = 1; i <= n; i++) {
        if (provjeraSavrsen(i)) {
            cout << i << " ";
        }
    }

}

