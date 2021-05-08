
#include <iostream>
using namespace  std;

struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;

    fudbaler()
    {
        godRodjenja = new int;
        brojIgraca = new int;
        golovi = new int;
    	
    }

    void unosFudbaler()
    {
        *godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
        *brojIgraca = rand() % 30 + 1;
        *golovi = rand() % 5;
    	
    }
	void ispisFudbaler()
    {
        cout << "Godine rodjenja: " << *godRodjenja << endl;
        cout << "Broj igraca: " << *brojIgraca << endl;
        cout << "Golovi: " << *golovi << endl;
    }
	
    ~fudbaler()
    {
        delete godRodjenja;
        godRodjenja = nullptr;

        delete brojIgraca;
        brojIgraca = nullptr;

        delete golovi;
        golovi = nullptr;
    	
    }
};
void timNajveciProsjek(fudbaler**, int, int);
void igracSaNajviseGolovaUnajlosijemTimu(fudbaler**, int, int);
int main()
{
    //Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.
    srand(time(0));
    int brTimova, brIgraca;

    cout << "brTimova: ";
    cin >> brTimova;
    cout << "brIgraca: ";
    cin >> brIgraca;

    fudbaler** f = new fudbaler * [brTimova];
    for (int i=0; i<brTimova; i++)
    {
        *(f + i) = new fudbaler[brIgraca];
    }

	for (int i=0; i<brTimova; i++)
	{
		for (int j=0; j<brIgraca; j++)
		{
            (*(*(f + i) + j)).unosFudbaler();
		}
	}
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < brTimova; i++)
    {
        cout << "brTimova[ " << i << " ]" << endl;
        for (int j = 0; j < brIgraca; j++)
        {
            cout << "brIgraca[ " << j << " ]" << endl;
            (*(*(f + i) + j)).ispisFudbaler();
        }
    }
    cout << "-------------------------------------------------------------------------" << endl;
    timNajveciProsjek(f, brTimova, brIgraca);
    cout << "-------------------------------------------------------------------------" << endl;
    igracSaNajviseGolovaUnajlosijemTimu(f, brIgraca, brTimova);
    cout << "-------------------------------------------------------------------------" << endl;

	
    for (int i=0; i<brIgraca; i++)
    {
        delete[] * (f + i);
    }
    delete[]f;
    f = nullptr;

	

    system("pause>0");
    return 0;
}
void timNajveciProsjek(fudbaler** f, int brTimova, int brIgraca)
{
    float* prosjek = new float[brTimova] {};

    for (int i=0; i<brTimova; i++)
    {
	    for (int j=0; j<brIgraca; j++)
	    {
            *(prosjek + i) += *(*(f + i) + j)->golovi;
	    }
        *(prosjek + i) /= brIgraca;
    }
    int index = 0;
	for (int i=0; i<brTimova; i++)
	{
		if (*(prosjek+i)>*(prosjek+index))
		{
            index = i;
		}
	}

    cout << "Najbolji tim se nalazi na indeksu: " << index<< " i sa podacima: " << endl;
    for (int j = 0; j < brIgraca; j++)
    {
        cout << "Godina rodjenja je: " << *(*(f + index) + j)->godRodjenja << endl;
        cout << "Broj igrac je: " << *(*(f + index) + j)->brojIgraca << endl;
        cout << "Broj golova igraca je: " << *(*(f + index) + j)->golovi << endl;
    }

    delete[]prosjek;
    prosjek = nullptr;
    	
}
void igracSaNajviseGolovaUnajlosijemTimu(fudbaler**f, int brTimova, int brIgraca)
{
    float* prosjek = new float[brTimova]{};

	for (int i=0; i<brTimova; i++)
	{
		for (int j=0; j<brIgraca; j++)
		{
            *(prosjek + i) += *(*(f + i) + j)->golovi;
		}
        *(prosjek + i) /= brIgraca;
	}
    int index = 0;
	for (int i=0; i<brTimova; i++)
	{
		if (*(prosjek+i)<*(prosjek+index))
		{
            index = i;
		}
	}
    int najboljiIgrac = *(*(*(f + index) + 0)).golovi;
    int indexIgraca=0;

	for (int j=0; j<brIgraca; j++)
	{
		if (*(*(f+index)+j)->golovi >najboljiIgrac)
		{
            najboljiIgrac = *(*(f + index) + j)->golovi;
            indexIgraca = j;
		}
	}
    cout << "Najbolji fudbaler u najgorem timu je rodjen: " << *(*(f + index) + indexIgraca)->godRodjenja << " i ima golova " << *(*(f + index) + indexIgraca)->golovi << endl;

    delete[]prosjek;
    prosjek = nullptr;
}

