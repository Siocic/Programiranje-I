
#include <iostream>
using namespace std;

struct kosarkas
{
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas()
    {
        ID = new char[10];
        imePrezime = new char[20];
        postignutiKosevi = new int;
    }
    void unosKosarkas()
    {
        cout << "ID: ";
        cin.ignore();
        cin.getline(ID, 10);

        cout << "Ime prezime: ";
        cin.getline(imePrezime, 20);

        *postignutiKosevi = rand() % 50;
    }
	void ispisKosarkas()
    {
        cout << "ID: " << ID << endl;
        cout << "Ime prezime: " << imePrezime << endl;
        cout << "Kosevi: " << *postignutiKosevi << endl;
    }
	~kosarkas()
    {
        delete[]ID;
        ID = nullptr;

        delete[]imePrezime;
        imePrezime = nullptr;

        delete postignutiKosevi;
        postignutiKosevi = nullptr;
    }
	
};
void najuspjesnijiKlub(kosarkas**, int, int);
int* razlikaIgraca(kosarkas**, int, int);//(Funkcija treba vratiti pokazivač na memorijsku lokaciju u kojoj je upisana ta razlika.)
int main()
{
    srand(time(0));
	//Redovi dvodimenzionalnog niza predstavljaju različite košarkaše a kolone različite klubove.
    int brKosarkasa, brKlubova;

    cout << "brKosarkasa: ";
    cin >> brKosarkasa;
    cout << "brKLubova: ";
    cin >> brKlubova;

    kosarkas** k = new kosarkas * [brKosarkasa];
	for (int i=0; i<brKosarkasa; i++)
	{
        *(k + i) = new kosarkas[brKlubova];
	}

	for (int i=0; i<brKosarkasa; i++)
	{
		for (int j=0; j<brKlubova; j++)
		{
            (*(*(k + i) + j)).unosKosarkas();
		}
	}
    cout << "---------------------------------------------------------------------------------------------------" << endl;
	for (int i=0;i<brKosarkasa;i++)
	{
		for (int j=0; j<brKlubova; j++)
		{
            (*(*(k + i) + j)).ispisKosarkas();
		}
	}
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    najuspjesnijiKlub(k, brKosarkasa, brKlubova);
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    int* razlikaKoseva = razlikaIgraca(k, brKosarkasa, brKlubova);
    cout << "Razlika izmedu najbolje i najgoreg kosarkasa je: " << *razlikaKoseva << endl;//stavili smo *razlikaKoseva da nam ispise broj a ne adresu na kojoj se nalazi
    cout << "---------------------------------------------------------------------------------------------------" << endl;

    delete razlikaKoseva;//posto smo mu proslijedili dinamicku alociranu memoriju moramo je i dealocirati

    for (int i=0; i<brKosarkasa; i++)
	{
        delete[] * (k + i);
	}
    delete[]k;
    k = nullptr;

	

    system("pause>0");
    return 0;
}
void najuspjesnijiKlub(kosarkas** k, int brKosarkasa, int brKlubova)
{
    float* uspjesanKlub = new float[brKosarkasa]{};

	for (int i=0;i<brKosarkasa; i++)
	{
		for (int j=0; j<brKlubova; j++)
		{
            *(uspjesanKlub + i) += *(*(k + i) + j)->postignutiKosevi;
		}
        *(uspjesanKlub + i) /= brKlubova;
	}

    int indexKluba = 0;
	for (int i=0; i<brKosarkasa; i++)
	{
		if(*(uspjesanKlub+i)>*(uspjesanKlub+indexKluba))
		{
            indexKluba = i;
		}
	}
    cout << "Najuspjesniji klub se nalazi na index-u: " << indexKluba << endl;

    delete[]uspjesanKlub;
    uspjesanKlub = nullptr;
}
int* razlikaIgraca(kosarkas**k, int brKosarkasa, int brKlubova)
{
    int* najbolji = new int[brKosarkasa] {};
    int* najgori = new int[brKosarkasa] {};
	float* uspjesanKlub = new float[brKosarkasa]{};
	

	//trazimo najbolji klub da bi mogli naci najboljeg kosarkasa
    for (int i = 0; i < brKosarkasa; i++)
    {
        for (int j = 0; j < brKlubova; j++)
        {
            *(uspjesanKlub + i) += *(*(k + i) + j)->postignutiKosevi;
        }
        *(uspjesanKlub + i) /= brKlubova;
    }

    int indexKluba = 0;
    for (int i = 0; i < brKosarkasa; i++)
    {
        if (*(uspjesanKlub + i) > *(uspjesanKlub + indexKluba))
        {
            indexKluba = i;
        }
    }
	//trazimo najboljeg igraca u najboljem timu
	for (int i=0; i<brKosarkasa; i++)
	{
        *(najbolji + i) += *(*(k + i) + indexKluba)->postignutiKosevi;//uzimamo koseve samo na index-u gdje se nalazi najbolji tim
	}
    int najboljiKosarkas = *(najbolji + 0);
	for (int i=0; i<brKosarkasa; i++)
	{
		if(*(najbolji+i)>najboljiKosarkas)
		{
            najboljiKosarkas = *(najbolji + i);
		}
	}

	//trazimo najgoreg kosarkasa u cijeloj ligi
	for (int i=0;i<brKosarkasa;i++)
	{
		for (int j=0; j<brKlubova; j++)
		{
            *(najgori + i) += *(*(k + i) + j)->postignutiKosevi;
		}
	}
    int najgoriKosarkas = *(najgori + 0);
	for (int i=0; i<brKosarkasa; i++)
	{
		if(*(najgori+i)<najgoriKosarkas)
		{
            najgoriKosarkas = *(najgori + i);
		}
	}

    int razlikaKoseva;
    razlikaKoseva = abs(najboljiKosarkas - najgoriKosarkas);//traazimo razliku izmedu najboljeg i najgoreg
      
    cout << "Najbolji kosarkas u najboljem timu " << indexKluba << " ima " << najboljiKosarkas << " koseva " << endl;
    cout << "Najgori kosarkas u cijelog ligi ima " << najgoriKosarkas << " koseva " << endl;


     delete[]uspjesanKlub;
    uspjesanKlub = nullptr;

    delete[]najbolji;
    najbolji = nullptr;
    delete[]najgori;
    najgori = nullptr;

    return new int(razlikaKoseva);//novo mjesto u memoriji gdje smo smjestili nasu razliku koseva
}

