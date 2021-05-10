
#include <iostream>
using namespace  std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    figura()
    {
        nazivFigure = new char[10];
        visinaFigure = new float;
    }
    void unosFigura()
    {
        cout << "ID: ";
        cin >> ID;

        cout << "Naziv figure: ";
        cin.ignore();
        cin.getline(nazivFigure, 10);

        cout << "Visina figure: ";
        cin >> *visinaFigure;
    }
	void ispisFigura()
    {
        cout << "ID: " << ID << endl;
        cout << "Naziv figure: " << nazivFigure << endl;
        cout << "Visina figure: " << *visinaFigure << endl;
    }
    ~figura()
    {
        delete[]nazivFigure;
        nazivFigure = nullptr;

        delete visinaFigure;
        visinaFigure = nullptr;
    }
 
};
float* prosjecnaVisina(figura**, int, int);//funkcija koja vraca pokazivac
int main()
{
    int red, kolona;

    cout << "Red: ";
    cin >> red;
    cout << "Kolona: ";
    cin >> kolona;

    figura** f = new figura * [red];
	for (int i=0;i<red;i++)
	{
        *(f + i) = new figura[kolona];
	}

	for (int i=0;i<red;i++)
	{
		for (int j=0;j<red;j++)
		{
            (*(*(f + i) + j)).unosFigura();
		}
	}
    cout << "------------------------------------------------------" << endl;
	for (int i=0;i<red;i++)
	{
        cout << "red [" << i << "]" << endl;
		for (int j=0;j<kolona;j++)
		{
            cout << "kolona [" << j << "]" << endl;
            (*(*(f + i) + j)).ispisFigura();
		}
	}
    cout << "------------------------------------------------------" << endl;

    float* prosjekVisina = prosjecnaVisina(f, red, kolona);
    cout << "Prosjecna visina na crnim poljiima iznosi:  " <<  *prosjekVisina << endl;
    cout << "------------------------------------------------------" << endl;


    system("pause>0");
	return 0;
}
float* prosjecnaVisina(figura** f, int red, int kolona)
{
    int brojac = 0;
    float prosjek = 0.0f;

	for (int i=0;i<red; i++)
	{
		for (int j=0;j<kolona;j++)
		{
			if ((i+j)>=red-1 && (i+j)%2==0)
			{
                prosjek += *(*(f + i) + j)->visinaFigure;
                brojac++;
			}
		}
	}

    if (brojac>0)
    {
        prosjek /= brojac;
    }
    return new float(prosjek);
}
