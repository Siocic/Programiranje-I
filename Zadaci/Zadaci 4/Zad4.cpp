
#include<iostream>
using namespace std;

struct vremenska_prognoza
{
    char* padavine;//unos samo kisa ili snijeg
    float* temperatura;
    float* vlaznost_vazduha;

    
    void unosPrognoza()
    {
        padavine = new char[15];
        cout << "Unesite padavine: ";
        cin.ignore();
        cin.getline(padavine, 15);

        temperatura = new float;
        cout << "Unesite temperaturu: ";
        cin >> *temperatura;

        vlaznost_vazduha = new float;
        cout << "Vlaznost vazduha: ";
        cin >> *vlaznost_vazduha;
    }
    void ispisPrognoza()
    {
        cout << "Padavine: " << padavine << endl;
        cout << "Temperatura: " << *temperatura << endl;
        cout << "Vlaznost vazduha: " << *vlaznost_vazduha << endl;
    }
    void dealokacija()
    {
        delete[]padavine;
        padavine = nullptr;

        delete temperatura;
        temperatura = nullptr;

        delete vlaznost_vazduha;
        vlaznost_vazduha = nullptr;
    }
   
    
};
void unosNiza(vremenska_prognoza*, int);
int najtacnijiMeteorolog(vremenska_prognoza**,float*, int, int);
int main()
{
    int brMeteorologa, brDana;

    cout << "Unesite broj meteorologa: ";
    cin >> brMeteorologa;
    cout << "Unesite broj dana: ";
    cin >> brDana;

    vremenska_prognoza** v = new vremenska_prognoza * [brMeteorologa];
    for (int i = 0; i < brMeteorologa; i++)
    {
        *(v + i) = new vremenska_prognoza[brDana];
    }
    for (int i = 0; i < brMeteorologa; i++)
    {
        for (int j = 0; j < brDana; j++)
        {
            (*(*(v + i) + j)).unosPrognoza();
        }
    }
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < brMeteorologa; i++)
    {
        for (int j = 0; j < brDana; j++)
        {
            (*(*(v + i) + j)).ispisPrognoza();
        }
    }
    cout << "---------------------------------------------------------------------" << endl;

    float* niz = new float[brDana] {};
    for (int i = 0; i < brDana; i++)
    {
        cout << "Unesite padavine: ";
        cin >> *(niz + i);
    }
  
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Meteorolog sa najtacnijom prognozom dnevnih temperatura je na indeksu: " << najtacnijiMeteorolog(v, niz, brMeteorologa, brDana) << endl;

  for (int i = 0; i < brMeteorologa; i++)
  {
      for (int j = 0; j < brDana; j++)
      {
          (*(*(v + i) + j)).dealokacija();
      }
  }

    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < brMeteorologa; i++)
    {
        delete[] * (v + i);
    }
    delete[]v;
    v = nullptr;

    system("pause>0");
    return 0;
}

int najtacnijiMeteorolog(vremenska_prognoza** v, float* niz, int brMeteorologa, int brDana)
{
    float* pomocni = new float[brDana] {};

    for (int i = 0; i < brMeteorologa; i++)
    {
        for (int j = 0; j < brDana; j++)
        {
            *(pomocni + i) += abs(*(*(v + i) + j)->temperatura - *(niz + i));// abs() daje apsolutnu vrijednost izraza (u slučaju da imamo negativan broj)
        }
    }

    // Kompariramo pomocni niz da bi nasli najmanji element (tj. meteorolog sa najmanjom gresom)
    int minError = 0;
    for (int i = 0; i < brDana; i++)
    {
        if (*(pomocni + i) < *(pomocni + minError)) {
            minError = i;
        }
    }

    // Dealokacija pomocni niza, izvrsava se prije return statement-a kako bi se zaista izvrsila a ne samo bila ignorirana.
    delete[] pomocni;

    return minError;
}
