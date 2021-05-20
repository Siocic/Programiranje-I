
#include <iostream>


using namespace std;

int brojC(int A, int B);

bool isIsto(int B, int cifra);

int main()
{
	int A, B;

	do
	{
		cout << "Unesite A: ";
		cin >> A;
		cout << "Unesite B: ";
		cin >> B;

	} while (A < 100000 && B < 50000);
	cout << "-------------------------------" << endl;
	int C = brojC(A, B);//ovde pozivamo nasu funkciju C koja ce u ovom slucaju ispisati 21
	cout << "A: " << A << endl;//1234567
	cout << "B: " << B << endl;//3456789
	cout << "C: " << C << endl;//21

	cout << "Broj A u obrnutom redoslijedu bez cifara B je: " << C << endl;//21

	return 0;
}

int brojC(int A, int B)//npr A=1234567 B=3456789
{
	int C = 0;

	while (A > 0)//1234567>0 || 123456>0 || 12345>0 || 1234>0 || 123>0 || 12>0 || 1>0
	{
		int cifra = A % 10;//1234567%10=7 || 123456%10=6 || 12345%10=5 || 1234%10=4 || 123%10=3 || 12%10=2 || 1%10=1

		if (!isIsto(B, cifra))//B=3456789 cifra=7  nakon sto se provrtila funkcija isIsto i vidjeli da u B ima cifra 7 broj A cemo djeliti sa 10 ||B=3456789 cifra=6 i opet odlazimo u funkciju isIsto i trazimo sada broj 6
		{                        //B=3456789 cifra=5 cifra se nalazi u B pa A opet djelimo ||B=3456789 cifra=4 cifra se opet nalazi || B=3456789 cifra=3 cifra se opet nalazi
			                     //posto sada nije isto B=3456789 i cifra=2 vrsimo dodjelu C
			                    //B=3456789 cifra=1 opet idemo u funkciju isIsto, opet nije isto B=3456789 i cifra=1 i sada cifru dodjelujemo u C u naredno liniji
			C = C * 10 + cifra;//ovde radimo obrtanje cifre sad je 0=0*10+2 i sada je C=2
			                           //2=2*10+1=21 ovaj je broj obrnut od A i sadrzi samo cifre koje nisu u B
		}

		A /= 10;//1234567/10=123456 || 123456/10=12345 || 12345/10=1234 || 1234/10=123 || 123/10=12 || 12/10=1
	}

	return C;
}

bool isIsto(int B, int cifra)//B=3456789 cifra=7 || i za ostale je isto sad cemo odradit kad se cifra ne nalazi u B||
{                                   //B=3456789 cifra=2    
	while (B > 0)//3456789>0 || 345678>0 || 34567>0
	{
		int cifraB = B % 10;//3456789%10=9 || 345678%10=8 || 34567%10=7

		if (cifraB == cifra) //cifraB=9 cifra=7 posto nije isto broj ponovo djelimo sa 10 || cifraB=8 cifra=7 nije isto opet djelimo || cifraB=7 cifra=7
			return true;//7==7 posto je isto vracamo se u funkciju brojC

		B /= 10; //3456789/10=345678 || 345678/10=34567
	}

	return false;//opet isto vrtimo petlju i posto nismo nasli cifru=2 u B vrati ne tacno(false) i vrati se u funkciju brojC
}
