
#include<iostream>
using namespace std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    void unosFigura()
    {
        ID = rand() % 100 + 1;

        nazivFigure = new char[20];
        cout << "Unesite nazive figure: ";
        cin.ignore();
        cin.getline(nazivFigure, 20);

        visinaFigure = new float;
        *visinaFigure = rand() % 100 + 10;

    }
    void ispisFigura()
    {
        cout << "ID: " << ID << endl;
        cout << "Naziv figure: " << nazivFigure << endl;
        cout << "Visina figure: " << *visinaFigure << endl;
    }
    void dealokacijaFigura()
    {
       
        delete[]nazivFigure;
        nazivFigure = nullptr;

        delete visinaFigure;
        visinaFigure = nullptr;

    }
};
void prosjecnaVisina(figura**, int, int);
int main()
{
    srand(time(0));

    int red, kolona;
    cout << "Unesite broj redova: ";
    cin >> red;
    cout << "Unesite broj kolona: ";
    cin >> kolona;

    figura** f = new figura * [red];
    for (int i = 0; i < red; i++)
    {
        *(f + i) = new figura[kolona];
    }
    
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(f + i) + j)).unosFigura();
        }
    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(f + i) + j)).ispisFigura();
        }
    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    prosjecnaVisina(f, red, kolona);
    cout << "-------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(*(f + i) + j)).dealokacijaFigura();
        }
    }
    for (int i = 0; i < red; i++)
    {
        delete[] * (f + i);
    }
    delete f;
    f = nullptr;

    return 0;
}
void prosjecnaVisina(figura** f, int red, int kolona)
{
    int brojac = 0;
    float prosjek = 0.0f;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            //ispod sporedne dijagonale
            if ((i+j)>=red-1 && (i+j)%2==0)
            {
                prosjek += *(*(f + i) + j)->visinaFigure;
                brojac++;

            }
        }
    }

    if (brojac>0)
    {
        cout << "Prosjecna visina iznosi: " << prosjek / brojac << endl;
    }
}
