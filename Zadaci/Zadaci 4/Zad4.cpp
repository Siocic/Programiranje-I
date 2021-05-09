
#include <iostream>
using namespace std;

struct vremenska_prognoza
{
    char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza()
    {
        padavine = new char[10];
        temperatura = new float;
        vlaznost_vazduha = new float;
    }
	void unosPrognoza()
    {
        cin.ignore();
	    do
	    {
            cout << "Padavine (samo kisa ili snijeg): ";
            cin.getline(padavine, 10);
	    	//strcmp() je ugnijezdena funckija i ovde smo je koristili za uspredbu argumenata koje smo mi unijeli
            if (strcmp(padavine, "kisa") != 0 && strcmp(padavine, "snijeg"))
            {
                cout << "Pogresan unos. Molimo Vas unesite ponovo. " << endl;
            }
	    }
	    while (strcmp(padavine,"kisa")!=0 && strcmp(padavine, "snijeg"));

        cout << "Temperatura: ";
        cin >> *temperatura;

        cout << "Vlaznost vazduha: ";
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
void najtacnijiMeteorolog(vremenska_prognoza**, vremenska_prognoza*, int, int);
int main()
{
    //Redovi dvodimenzionalnog niza predstavljaju različite meteorologe, a kolone različite dane.

    int brMeteorologa, brDana;

    cout << "brMeteorologa: ";
    cin >> brMeteorologa;
    cout << "brDana: ";
    cin >> brDana;

    vremenska_prognoza** vp = new vremenska_prognoza * [brMeteorologa];
	for (int i=0; i<brMeteorologa; i++)
	{
        *(vp + i) = new vremenska_prognoza[brDana];
	}

	for (int i=0;i<brMeteorologa;i++)
	{
		for (int j=0;j<brDana;j++)
		{
            (*(*(vp + i) + j)).unosPrognoza();
		}
	}
    cout << "--------------------------------------------------------------------------------" << endl;
	for (int i=0;i<brMeteorologa;i++)
	{
        cout << "brMeteorloga [" << i << "]" << endl;
		for (int j=0;j<brDana;j++)
		{
            cout << "brDana [" << j << "]" << endl;

            (*(*(vp + i) + j)).ispisPrognoza();
		}
	}
    cout << "--------------------------------------------------------------------------------" << endl;

    vremenska_prognoza* vp2 = new vremenska_prognoza[brDana];
    jednodimenzionalniNiz(vp2, brDana);
	
    cout << "--------------------------------------------------------------------------------" << endl;
    najtacnijiMeteorolog(vp, vp2, brMeteorologa, brDana);
    cout << "--------------------------------------------------------------------------------" << endl;


    system("pause>0");
    return 0;
}
void jednodimenzionalniNiz(vremenska_prognoza* vp2, int brDana)
{
    cout << "Unesite vrijednosti: " << endl;
	for (int i=0;i<brDana;i++)
	{
        cin.ignore();

        do
        {
            cout << "Unesite padavine (samo kisa ili snijeg): ";
            cin.getline((vp2 + i)->padavine, 10);
            if (strcmp((vp2 + i)->padavine, "kisa") != 0 && strcmp((vp2 + i)->padavine, "snijeg") != 0)
            {
                cout << "Pogresan unos. Unesite ponovo" << endl;
            }

        } while (strcmp((vp2 + i)->padavine, "kisa") != 0 && strcmp((vp2 + i)->padavine, "snijeg") != 0);

        cout << "Uneiste temperaturu: ";
        cin >> *(vp2 + i)->temperatura;

        cout << "Unesite vlaznost vazduha: ";
        cin >> *(vp2 + i)->vlaznost_vazduha;
	}
}
void najtacnijiMeteorolog(vremenska_prognoza** vp, vremenska_prognoza* vp2, int brMetorologa, int brDana)
{
    float* meteorolog = new float[brDana] {};

	for (int i=0;i<brMetorologa;i++)
	{
		for (int j=0;j<brDana;j++)
		{
            *(meteorolog + i) += abs(*(*(vp + i) + j)->padavine - *(vp2 + i)->padavine);
		}
	}
    int index = 0;
	for (int i=0;i<brDana;i++)
	{
		if (*(meteorolog+i)<*(meteorolog+index))
		{
            index = i;
		}
	}
    cout << "Najtacniji meteorlog se nalazi na index-u: " << index << endl;
    delete[]meteorolog;
    meteorolog = nullptr;
}
