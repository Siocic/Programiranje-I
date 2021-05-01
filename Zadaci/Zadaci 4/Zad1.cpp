
#include<iostream>
using namespace std;
struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;

    void unosFudbaler()
    {
        godRodjenja = new int;
        *godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);

        brojIgraca = new int;
        *brojIgraca = rand() % 30 + 1;

        golovi = new int;
        *golovi = rand() % 5;
    }
    void ispisFudbaler()
    {
        cout << "Godine rodjenja fudbalera: " << *godRodjenja << endl;
        cout << "Broj igraca: " << *brojIgraca << endl;
        cout << "Golovi: " <<*golovi <<endl;

    }
    void dealokacijaFudbaler()
    {
        delete godRodjenja;
        godRodjenja = nullptr;

        delete brojIgraca;
        brojIgraca = nullptr;

        delete golovi;
        golovi = nullptr;
    }

};
void timSaNajvecimProsjekom(fudbaler**, int, int);
void igracSaNajviseGolova(fudbaler**, int, int);
int main()
{
    //redovi timovi
    //kolona igraci
    srand(time(NULL));
    int brTimova, brIgraca;

    cout << "Unesite broj timova: ";
    cin >> brTimova;
    cout << "Unesite broj igraca: ";
    cin >> brIgraca;

    fudbaler** mat = new fudbaler*[brTimova];

    for (int i = 0; i < brTimova; i++)
    {
        *(mat + i) = new fudbaler[brIgraca];
    }
    for (int i = 0; i < brTimova; i++)
    {
        for (int j = 0; j < brIgraca; j++)
        {
            (*(*(mat + i) + j)).unosFudbaler();
        }
    }
    for (int i = 0; i < brTimova; i++)
    {
        for (int j = 0; j < brIgraca; j++)
        {
            (*(*(mat + i) + j)).ispisFudbaler();
        }
    }
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    timSaNajvecimProsjekom(mat, brTimova, brIgraca);
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    igracSaNajviseGolova(mat, brTimova, brIgraca);
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < brTimova; i++)
    {
        for (int j = 0; j < brIgraca; j++)
        {
            (*(*(mat + i) + j)).dealokacijaFudbaler();
        }
    }
    for (int i = 0; i < brTimova; i++)
    {
        delete[]*(mat+i);
    }
    delete[]mat;
    mat = nullptr;




    system("pause>0");
    return 0;
}
void timSaNajvecimProsjekom(fudbaler** f, int brTimova, int brIgraca)
{
    float* bestTeam = new float[brTimova] {};

    for (int i = 0; i < brTimova; i++)
    {
        for (int j = 0; j < brIgraca; j++)
        {
            *(bestTeam + i) += *(*(f + i) + j)->golovi;
        }
        *(bestTeam + i) /= brIgraca;
    }

    int indexTeam = 0;

    for (int i = 0; i < brTimova; i++)
    {
        if (*(bestTeam+i)>*(bestTeam+indexTeam))
        {
            indexTeam = i;
        }
    }
    cout << "Najbolji tim se nalazi na indeksu: " << indexTeam << " i sa podacima: " << endl;
    for (int j = 0; j < brIgraca; j++)
    {
        cout << "Godina rodjenja je: " << *(*(f + indexTeam) + j)->godRodjenja << endl;
        cout << "Broj igrac je: " << *(*(f + indexTeam) + j)->brojIgraca << endl;
        cout << "Broj golova igraca je: " << *(*(f + indexTeam) + j)->golovi << endl;
    }
    cout << endl;

    delete[]bestTeam;

}
void igracSaNajviseGolova(fudbaler** f, int brTimova, int brIgraca)
{
    float* najgoriTim = new float[brTimova] {};

    for (int i = 0; i < brTimova; i++)
    {
        for (int j = 0; j < brIgraca; j++)
        {
            *(najgoriTim + i) += *(*(f + i) + j)->golovi;
        }
        *(najgoriTim + i) /= brIgraca;
    }
    int indexTeam = 0;

    for (int i = 0; i < brTimova; i++)
    {
        if (*(najgoriTim+i)<*(najgoriTim+indexTeam))
        {
            indexTeam=i;
        }
    }
    int bestPlayer = *(*(f + indexTeam) + 0)->golovi;
    int indexPlayer = 0;

    for (int j = 0; j < brIgraca; j++)
    {
        if (*(*(f + indexTeam) + j)->golovi > bestPlayer)
        {
            bestPlayer = *(*(f + indexTeam) + j)->golovi;
            indexPlayer = j;
        }
        
    }
    cout << "Najbolji fudbaler u najgorem timu je rodjen: " << *(*(f + indexTeam) + indexPlayer)->godRodjenja << " i ima golova " << *(*(f + indexTeam) + indexPlayer)->golovi << endl;
    
    delete[]najgoriTim;
}

