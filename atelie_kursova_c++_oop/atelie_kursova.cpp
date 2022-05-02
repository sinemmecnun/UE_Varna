#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Drehi
{
public:
	virtual void View() = 0;
	virtual int calc_cena() = 0;
	string ime, cvqt, material;
	int tip;
};

class Rokli : public Drehi
{
public:
	bool duljina; //dulga / kusa
	bool dantela; // da /ne
	bool kamuni; //da / ne;
	Rokli(string i, string m, string c, bool dj, bool d, bool k)
	{
		ime = i;
		material = m;
		cvqt = c;
		duljina = dj;
		dantela = d;
		kamuni = k;
		tip = 1;
	}

	virtual void View()
	{
		cout << ime + '\t' + material + '\t' + cvqt + '\t';
		if (duljina == 1) cout << "dulga\t";
		else cout << "kusa\t";
		if (dantela == 1) cout << "s dantela\t";
		else cout << "bez dantela\t";
		if (kamuni == 1) cout << "s kamuni";
		else cout << "bez kamuni";
	}
	virtual int calc_cena()
	{
		int cena = 400;
		if (duljina == 1) cena += 200;
		if (dantela == 1) cena += 300;
		if (kamuni == 1) cena += 350;
		return cena;
	}
};

class Kostyumi : public Drehi
{
public:
	bool shtipka; //da/ne
	bool aksesoar; //vratovruzka/papionka
	bool sako; //da/ne
	Kostyumi(string i, string m, string c, bool sh, bool a, bool s)
	{
		ime = i;
		material = m;
		cvqt = c;
		shtipka = sh;
		aksesoar = a;
		sako = s;
		tip = 2;
	}
	virtual void View()
	{
		cout << ime << '\t' << material << '\t' << cvqt << '\t';
		if (shtipka == 1) cout << "s shtipka\t";
		else cout << "bez shtipka\t";
		if (aksesoar == 1) cout << "vratovruzka\t";
		else cout << "papionka\t";
		if (sako == 1) cout << "sus sako";
		else cout << "bez sako";
	}
	virtual int calc_cena()
	{
		int cena = 400;
		if (shtipka == 1) cena += 200;
		if (aksesoar == 1) cena += 300;
		if (sako == 1) cena += 350;
		return cena;
	}
};

class Obuvki : public Drehi
{
public:
	int cena;
	Obuvki(string i, int price, string m, string c)
	{
		ime = i;
		cena = price;
		material = m;
		cvqt = c;
		tip = 3;
	}
	virtual void View()
	{
		cout << ime << '\t';
		cout << to_string(cena) << '\t';
		cout << material << '\t' << cvqt;
	}
	virtual int calc_cena()
	{
		return cena;
	}
};

class Poruchka
{
public:
	void addOrder(Drehi* order)
	{
		poruchki.push_back(order);
	}

	void getOrders() {
		for (int i = 0; i < poruchki.size(); i++) {
			poruchki[i]->View();
			cout << endl;
		}
	}
	void Process()
	{
		if (poruchki.empty())
		{
			cout << "Nqma poruchki za izpulnenie" << endl;
		}
		else
		{
			short int pr;
			for (int i = 0; i < poruchki.size(); i++)
			{
				cout << i + 1 << ". ";
				poruchki[i]->View();
				cout << endl;
			}
			cout << "Izberete nomer na poruchka: ";
			cin >> pr;
			pr--;
			if (pr >= 0 && pr < poruchki.size())
			{
				poruchki.erase(poruchki.begin() + pr);
				cout << "Poruchkata e izpulnena" << endl;
			}
		}
	}

	float Dohodi()
	{
		float dohodi = 0;
		for (int i = 0; i < poruchki.size(); i++)
		{
			dohodi += poruchki[i]->calc_cena();
		}
		return dohodi;
	}

	int RokliCena() {
		int cena_rokli = 0;
		for (int i = 0; i < poruchki.size(); i++){
			if (poruchki[i]->tip == 1) cena_rokli += poruchki[i]->calc_cena();
		}
		return cena_rokli;
	}
private:
	vector <Drehi*> poruchki;
};

void List()
{
	cout << "1.Rokli\n2.Kostyumi\n3.Obuvki\nIzberete ot spisuka: ";
}

int main()
{
	signed short int ans;
	char loop;
	vector <Rokli> rokli;
	vector <Kostyumi> kostyumi;
	vector <Obuvki> obuvki;
	fstream dress, costume, shoes;
	Poruchka ord;

	dress.open("B://rokli.txt", ios::in);
	if (!dress.is_open())
	{
		cout << "Can't open rokli";
		return -1;
	}
	while (!dress.eof())
	{
		string name, mat, color, len, lace_str, stone_str;
		bool length = 0, lace = 0, stones = 0;
		getline(dress, name, '\t');
		getline(dress, mat, '\t');
		getline(dress, color, '\t');
		getline(dress, len, '\t');
		if (len == "dulga") length = 1;
		else if (len == "kusa") length = 0;
		getline(dress, lace_str, '\t');
		if (lace_str == "s dantela") lace = 1;
		else if (lace_str == "bez dantela") lace = 0;
		getline(dress, stone_str, '\n');
		if (stone_str == "s kamuni") stones = 1;
		else if (stone_str == "bez kamuni") stones = 0;
		rokli.push_back(Rokli(name, mat, color, length, lace, stones));
	}

	costume.open("B://kostyumi.txt", ios::in);
	if (!costume.is_open())
	{
		cout << "Can't open kostyumi";
		return -1;
	}
	while (!costume.eof())
	{
		string name, mat, color, sht_str, accessory_str, blazer_str;
		bool shtipka_temp = 0, accessory = 0, blazer = 0;
		getline(costume, name, '\t');
		getline(costume, mat, '\t');
		getline(costume, color, '\t');
		getline(costume, sht_str, '\t');
		if (sht_str == "s shtipka") shtipka_temp = 1;
		else if (sht_str == "bez shtipka") shtipka_temp = 0;
		getline(costume, accessory_str, '\t');
		if (accessory_str == "vratovruzka") accessory = 1;
		else if (accessory_str == "papionka") accessory = 0;
		getline(costume, blazer_str, '\n');
		if (blazer_str == "sus sako") blazer = 1;
		else if (blazer_str == "bez sako") blazer = 0;
		kostyumi.push_back(Kostyumi(name, mat, color, shtipka_temp, accessory, blazer));
	}

	shoes.open("B://obuvki.txt", ios::in);
	if (!shoes.is_open())
	{
		cout << "Can't open obuvki";
		return -1;
	}
	while (!shoes.eof())
	{
		string name, mat, color, price_temp;
		int cena_temp;
		getline(shoes, name, '\t');
		getline(shoes, price_temp, '\t');
		cena_temp = stoi(price_temp);
		getline(shoes, mat, '\t');
		getline(shoes, color, '\n');
		obuvki.push_back(Obuvki(name, cena_temp, mat, color));
	}

	dress.close();
	costume.close();
	shoes.close();

	do {
		cout << "===================================================" << endl;
		cout << "Izberete ot dolniq spisuk:\n1. Pokaji inventar\n2. Pokaji poruchki\n3. Dobavi dreha/obuvki\n4. Premahni dreha/obuvki\n5. Kupi\n6. Specialna poruchka" << endl;
		cout << "===================================================" << endl;
		cout << "Opciq: ";
		cin >> ans;
		if (ans == 1) //show all
		{
			List();
			short int izb;
			cin >> izb;
			if (izb == 1)
			{ //rokli
				for (vector <Rokli>::iterator it = rokli.begin(); it != rokli.end(); it++)
				{
					it->View();
					cout << endl;
				}
			}
			else if (izb == 2)
			{ //kostyumi
				for (vector <Kostyumi>::iterator it = kostyumi.begin(); it != kostyumi.end(); it++)
				{
					it->View();
					cout << endl;
				}
			}
			else if (izb == 3)
			{ //obuvki
				for (vector <Obuvki>::iterator it = obuvki.begin(); it != obuvki.end(); it++)
				{
					it->View();
					cout << endl;
				}
			}
			else cout << "Error" << endl;
		}
		else if (ans == 2)
		{ //show orders
			ord.getOrders();
			cout << "Obshtiqt dohod ot poruchkite e: " << ord.Dohodi() << "lv." << endl;
			cout << "Obshtiqt dohod ot roklite e: " << ord.RokliCena() << " lv." << endl;
			cout << "Iskate li da obrabotite poruchka? (y/n) ";
			char otg;
			cin >> otg;
			if (otg == 'y' || otg == 'Y')
				ord.Process();
		}
		else if (ans == 3) //add
		{
			char v;
			List();
			short int izb;
			cin >> izb;
			if (izb == 1) //rokli
			{
				string name, mat, color, len, lace_str, stone_str;
				bool length = 0, lace = 0, stones = 0;
				cout << "Ime: ";
				cin.ignore(10, '\n');
				getline(cin, name);
				cout << "Material: ";
				getline(cin, mat);
				cout << "Cvqt: ";
				getline(cin, color);
				cout << "Duljina: ";
				getline(cin, len);
				if (len == "dulga") length = 1;
				else if (len == "kusa") length = 0;
				cout << "Dantela (s/bez): ";
				getline(cin, lace_str);
				if (lace_str == "s") lace = 1;
				else if (lace_str == "bez") lace = 0;
				cout << "Kamuni (s/bez): ";
				getline(cin, stone_str);
				if (stone_str == "s") stones = 1;
				else if (stone_str == "bez") stones = 0;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					rokli.push_back(Rokli(name, mat, color, length, lace, stones));
				}
			}
			else if (izb == 2) //kostyumi
			{
				string name, mat, color, sht_str, accessory_str, blazer_str;
				bool shtipka_temp = 0, accessory = 0, blazer = 0;
				cout << "Ime: ";
				cin.ignore(10, '\n');
				getline(cin, name);
				cout << "Material: ";
				getline(cin, mat);
				cout << "Cvqt: ";
				getline(cin, color);
				cout << "Shtipka (s/bez): ";
				getline(cin, sht_str);
				if (sht_str == "s") shtipka_temp = 1;
				else if (sht_str == "bez") shtipka_temp = 0;
				cout << "Vratovruzka (vratovruzka/papionka): ";
				getline(cin, accessory_str);
				if (accessory_str == "v") accessory = 1;
				else if (accessory_str == "p") accessory = 0;
				cout << "Sako (s/bez): ";
				getline(cin, blazer_str, '\n');
				if (blazer_str == "s") blazer = 1;
				else if (blazer_str == "bez") blazer = 0;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					kostyumi.push_back(Kostyumi(name, mat, color, shtipka_temp, accessory, blazer));
				}
			}
			else if (izb == 3) //obuvki
			{
				string name, mat, color, price_temp;
				int cena_temp;
				cout << "Ime: ";
				cin.ignore(10, '\n');
				getline(cin, name);
				cout << "Cena: ";
				getline(cin, price_temp);
				cena_temp = stoi(price_temp);
				cout << "Material: ";
				getline(cin, mat);
				cout << "Cvqt: ";
				getline(cin, color);
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					obuvki.push_back(Obuvki(name, cena_temp, mat, color));
				}
			}
			else cout << "Error" << endl;
		}
		else if (ans == 4) // remove
		{
			char v;
			List();
			short int izb;
			cin >> izb;
			int i = 0;
			if (izb == 1) //rokli
			{
				short int number;
				for (vector <Rokli>::iterator it = rokli.begin(); it != rokli.end(); it++)
				{
					cout << i + 1 << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Premahvame: ";
				cin >> number; number--;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					rokli.erase(rokli.begin() + number);
				}
				else break;
				dress.close();
			}
			else if (izb == 2) //kostyumi
			{
				short int number;
				for (vector <Kostyumi>::iterator it = kostyumi.begin(); it != kostyumi.end(); it++)
				{
					cout << i + 1 << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Premahvame: ";
				cin >> number;
				number--;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					kostyumi.erase(kostyumi.begin() + number);
				}
			}
			else if (izb == 3) //obuvki
			{
				short int number;
				for (vector <Obuvki>::iterator it = obuvki.begin(); it != obuvki.end(); it++)
				{
					cout << i + 1 << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Premahvame: ";
				cin >> number; number--;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					obuvki.erase(obuvki.begin() + number);
				}
			}
			else cout << "Error" << endl;
		}
		else if (ans == 5) // buy
		{
			List();
			short int izb;
			cin >> izb;
			if (izb == 1) //rokli
			{
				short int number;
				int i = 1;
				for (vector <Rokli>::iterator it = rokli.begin(); it != rokli.end(); it++)
				{
					cout << i << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Izberete roklq: ";
				cin >> number;
				number--;
				cout << "Duljite: " << rokli[number].calc_cena() << " leva" << endl;

				rokli.erase(rokli.begin() + number);
			}
			else if (izb == 2) //kostyumi
			{
				short int number;
				int i = 1;
				for (vector <Kostyumi>::iterator it = kostyumi.begin(); it != kostyumi.end(); it++)
				{
					cout << i << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Izberete kostum: ";
				cin >> number;
				number--;
				cout << "Duljite: " << kostyumi[number].calc_cena() << " leva" << endl;
				kostyumi.erase(kostyumi.begin() + number);
			}
			else if (izb == 3) //obuvki
			{
				short int number;
				int i = 1;
				for (vector <Obuvki>::iterator it = obuvki.begin(); it != obuvki.end(); it++)
				{
					cout << i << ". ";
					it->View();
					cout << endl;
					i++;
				}
				cout << "Izberete obuvki: ";
				cin >> number; number--;
				cout << "Duljite: " << obuvki[number].calc_cena() << " leva" << endl;
				obuvki.erase(obuvki.begin() + number);
			}
			else cout << "Error" << endl;
		}
		else if (ans == 6) // order
		{
			cout << "1.Rokli\n2.Kostyumi\nIzberete ot spisuka: ";
			short int izb;
			char v;
			cin >> izb;

			if (izb == 1) //rokli
			{
				string name, mat, color, len, lace_str, stone_str;
				bool length = 0, lace = 0, stones = 0;
				cout << "Ime: ";
				cin.ignore(10, '\n');
				getline(cin, name);
				cout << "Material: ";
				getline(cin, mat);
				cout << "Cvqt: ";
				getline(cin, color);
				cout << "Duljina (dulga/kusa): ";
				getline(cin, len);
				if (len == "dulga") length = 1;
				else if (len == "kusa") length = 0;
				cout << "Dantela (s/bez): ";
				getline(cin, lace_str);
				if (lace_str == "s") lace = 1;
				else if (lace_str == "bez") lace = 0;
				cout << "Kamuni (s/bez): ";
				getline(cin, stone_str);
				if (stone_str == "s") stones = 1;
				else if (stone_str == "bez") stones = 0;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					Rokli* drs = new Rokli(name, mat, color, length, lace, stones);
					ord.addOrder(drs);
					cout << "Duljite: " << drs->calc_cena() << "lv." << endl;
				}
			}
			else if (izb == 2) //kostyumi
			{
				string name, mat, color, sht_str, accessory_str, blazer_str;
				bool shtipka_temp = 0, accessory = 0, blazer = 0;
				cout << "Ime: ";
				cin.ignore(10, '\n');
				getline(cin, name);
				cout << "Material: ";
				getline(cin, mat);
				cout << "Cvqt: ";
				getline(cin, color);
				cout << "Shtipka (s/bez): ";
				getline(cin, sht_str);
				if (sht_str == "s") shtipka_temp = 1;
				else if (sht_str == "bez") shtipka_temp = 0;
				cout << "Vratovruzka (v/p): ";
				getline(cin, accessory_str);
				if (accessory_str == "v") accessory = 1;
				else if (accessory_str == "p") accessory = 0;
				cout << "Sako (s/bez): ";
				getline(cin, blazer_str, '\n');
				if (blazer_str == "s") blazer = 1;
				else if (blazer_str == "bez") blazer = 0;
				cout << "Potvurjdavane? (y/n) ";
				cin >> v;
				if (v == 'y' || v == 'Y')
				{
					Kostyumi* cos = new Kostyumi(name, mat, color, shtipka_temp, accessory, blazer);
					ord.addOrder(cos);
					cout << "Duljite: " << cos->calc_cena() << "lv." << endl;
				}
			}
			else cout << "Error" << endl;
		}
		else cout << "Error" << endl;
		cout << "Otnovo? (y/n): ";
		cin >> loop;
	} while (loop == 'y' || loop == 'Y');

	//prezapisvane na faylove
	//rokli
	dress.open("B://rokli.txt", ios::out | ios::trunc);
	for (vector <Rokli>::iterator it = rokli.begin(); it != rokli.end(); it++)
	{
		dress << it->ime << '\t' << it->material << '\t' << it->cvqt << '\t';
		if (it->duljina == 1) dress << "dulga\t";
		else dress << "kusa\t";
		if (it->dantela == 1) dress << "s dantela\t";
		else dress << "bez dantela\t";
		if (it->kamuni == 1) dress << "s kamuni";
		else dress << "bez kamuni";
		if (it != rokli.end() - 1) dress << endl;
	}
	dress.close();

	//kostyumi
	costume.open("B://kostyumi.txt", ios::out | ios::trunc);
	for (vector <Kostyumi>::iterator it = kostyumi.begin(); it != kostyumi.end(); it++)
	{
		costume << it->ime << '\t' << it->material << '\t' << it->cvqt << '\t';
		if (it->shtipka == 1) costume << "s shtipka\t";
		else costume << "bez shtipka\t";
		if (it->aksesoar == 1) costume << "vratovruzka\t";
		else costume << "papionka\t";
		if (it->sako == 1) costume << "sus sako";
		else costume << "bez sako";
		if (it != kostyumi.end() - 1) costume << endl;
	}
	costume.close();

	//obuvki
	shoes.open("B://obuvki.txt", ios::out | ios::trunc);
	for (vector <Obuvki>::iterator it = obuvki.begin(); it != obuvki.end(); it++)
	{
		shoes << it->ime << '\t' << it->cena << '\t' << it->material << '\t' << it->cvqt;
		if (it != obuvki.end() - 1) shoes << endl;
	}
	shoes.close();

	return 0;
}