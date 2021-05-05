/*
 Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa vremenska_prognoza (prognoza je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct vremenska_prognoza
{
    char *padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float *temperatura;
    float *vlaznost_vazduha;
};
Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane.
Omogućiti korisniku unos svih prognoza za sve meteorologe.
Dodatno kreirati jednodimenzionalni dinamički niz čija će veličina biti uneseni broj dana u koji ćete omogućiti unos stvarnih izmjerenih vrijednosti za dane.
Zatim napraviti funkciju koja će pronaći i ispisati index meteorologa čija je prognoza dnevnih temperatura bila najtačnija, odnosno koji je imao najmanju grešku u procjeni temperatura.
Pomoć: suma svih razlika između prognozirane i stvarne temperature za jednog meteorologa predstavlja njegovu ukupnu grešku.
(U ovom zadatku je zabranjeno indeksirati elemente u niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)
 */
#include <iostream>
using namespace  std;

struct vremenska_prognoza
{

    char* padavine;//samo kisa ili snijeg
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza()
    {
        padavine = new char[10];
        temperatura = new float;
        vlaznost_vazduha = new float;
    }
	void unosProgonoza()
    {
        cin.ignore();
        do
        {
            cout << "Unesite padavine (samo kisa ili snijeg): " << endl;
            cin.getline(padavine, 10);
            if (strcmp(padavine, "kisa") != 0 && strcmp(padavine, "snijeg")!=0)
            {
                cout << "Pogresan unos. Unesite ponovo" << endl;
            }

        } while (strcmp(padavine, "kisa") != 0 && strcmp(padavine, "snijeg")!=0);

        cout << "Unesite temperaturu: ";
        cin >> *temperatura;

        cout << "Unesite vlaznost vazduha: ";
        cin >> *vlaznost_vazduha;
    	
    }
	void ispisPrognoza()
    {
        cout << "Padavine: " << padavine << endl;
        cout << "Temperatura: " << *temperatura << endl;
        cout << "Vlaznost vazduha: " << *vlaznost_vazduha << endl;
    }
    ~vremenska_prognoza()
    {
        delete[]padavine;
        padavine = nullptr;

        delete temperatura;
        temperatura = nullptr;

        delete vlaznost_vazduha;
        vlaznost_vazduha = nullptr;
    }
};
void jednodimenzionalniNiz(vremenska_prognoza*, int);
int najtacnijiMetorolog(vremenska_prognoza**, vremenska_prognoza*, int, int);
int main()
{
    int brMetorologa, brDana;

    cout << "Unesite broj meteorologa: ";
    cin >> brMetorologa;
    cout << "Unesite broj dana: ";
    cin >> brDana;

    vremenska_prognoza** v = new vremenska_prognoza * [brMetorologa];
	for (int i=0;i<brMetorologa;i++)
	{
        *(v + i) = new vremenska_prognoza[brDana];
	}

	for (int i=0;i<brMetorologa;i++)
	{
		for (int j=0;j<brDana;j++)
		{
            (*(*(v + i) + j)).unosProgonoza();
		}
	}
    cout << "----------------------------------------------------------------" << endl;
    for (int i=0; i<brMetorologa; i++)
	{
		for (int j=0; j<brDana; j++)
		{
            (*(*(v + i) + j)).ispisPrognoza();
		}
            
	}
	
    cout << "----------------------------------------------------------------" << endl;
	
    vremenska_prognoza* v2 = new vremenska_prognoza[brDana];
    jednodimenzionalniNiz(v2, brDana);
    cout << "----------------------------------------------------------------" << endl;
    cout << "Najtacniji meteorolog se nalazi na index-u: " << najtacnijiMetorolog(v, v2, brMetorologa, brDana) << endl;
    cout << "----------------------------------------------------------------" << endl;

	for (int i=0;i<brMetorologa;i++)
	{
        delete[] * (v + i);
	}
    delete[]v;
    v = nullptr;

    system("pause>0");
    return 0;
   
}
void jednodimenzionalniNiz(vremenska_prognoza*v2, int brDana)
{
	for (int i=0;i<brDana;i++)
	{
        cin.ignore();

        do
        {
            cout << "Unesite padavine (samo kisa ili snijeg): " << endl;
            cin.getline((v2+i)->padavine, 10);
            if (strcmp((v2 + i)->padavine, "kisa") != 0 && strcmp((v2 + i)->padavine, "snijeg") != 0)
            {
                cout << "Pogresan unos. Unesite ponovo" << endl;
            }

        } while (strcmp((v2 + i)->padavine, "kisa") != 0 && strcmp((v2 + i)->padavine, "snijeg") != 0);

        cout << "Uneiste temperaturu: ";
        cin >> *(v2 + i)->temperatura;

        cout << "Unesite vlaznost vazduha: ";
        cin >> *(v2 + i)->vlaznost_vazduha;
	}
}
int najtacnijiMetorolog(vremenska_prognoza** v1, vremenska_prognoza*v2, int brMeteorologa, int brDana)
{
    float* meteorolog = new float[brDana] {};

	for (int i=0;i<brMeteorologa;i++)
	{
		for (int j=0;j<brDana;j++)
		{
            *(meteorolog + i) += abs(*(*(v1 + i) + j)->padavine - *(v2 + i)->padavine);
		}
	}
    int tacno = 0;
	for (int i=0;i<brDana;i++)
	{
		if(*(meteorolog+i)<*(meteorolog+tacno))
		{
            tacno = i;
		}
	}

    delete[]meteorolog;

    return tacno;
}

