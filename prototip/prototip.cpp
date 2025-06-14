#include <iostream>
#include <string>
#include <vector>
using namespace std;

class taxPayer
{
public:
	taxPayer() {};
	~taxPayer() {};
	virtual void print_Info() = 0; 
	virtual double calc_Tax() = 0; 

protected:
	string ID;
};

class taxDot : public taxPayer
{
public:
	taxDot(string ime, double suma) { ID = ime; dohod = suma; };
	~taxDot() {};
	virtual void print_Info() {
		cout << "DOD: Ime:" << ID << ", Dohod:" << dohod << ", Tax:" << calc_Tax() << endl;
	};
	virtual double calc_Tax() { return dohod * 0.1; };

private:
	double dohod;
};

class taxEstate : public taxPayer
{
public:
	taxEstate(string adres, double ocenka) { ID = adres; dan_ocenka = ocenka; };
	~taxEstate() {}
	virtual void print_Info() {
		cout << "ESTATE: Adres:" << ID << ", Ocenka:" << dan_ocenka << ", Tax:" << calc_Tax() << endl;
	};
	virtual double calc_Tax() { return dan_ocenka * 0.001; };

private:
	double dan_ocenka;

};

class taxCar :public taxPayer
{
public:
	taxCar(string reg, int po, int ag) { ID = reg; power = po; age = ag; };
	~taxCar() {};
	virtual void print_Info() {
		cout << "MPS: Reg:" << ID << ", Moshtnost:" << power << ", Vazrast:" << age << ", Tax:" << calc_Tax() << endl;
	};
	virtual double calc_Tax() {
		double baza = 300;
		if (power > 100) baza *= 1.3;
		baza = baza - (age * 0.05) * baza;
		return baza;
	};

private:
	int power, age;
};

class taxQueue
{
public:
	taxQueue() {};
	~taxQueue() {};
	void Add(taxPayer* obj) { opashka.push_back(obj); };
	void List() {
		if (opashka.empty()) {
			cout << "Nqma nikoi\n";
		}
		else {
			cout << "Na opashkata sa:\n";
			for (int x = 0; x < opashka.size(); x++)
				opashka[x]->print_Info();
		}
	};
	double Proccess() {
		if (opashka.empty()) {
			cout << "Nqma nikoi\n";
			return 0;
		}
		else {
			double tax = opashka[0]->calc_Tax();
			opashka.erase(opashka.begin());
			return tax;
		}
	};

private:
	vector <taxPayer*> opashka;
};

int main()
{
	taxQueue q;

	while (true) {
		cout << "\n\nMENU\n===========================\n";
		cout << "1. Dobavqne na DOD\n2. Dobavqne na ESTATE\n3. Dobavqne na CAR\n";
		cout << "4. Izvejdane\n5. Obrabotka\n0. Izhod\n";

		cout << endl;
		cout << "Vuvedi: ";

		string izb;
		getline(cin, izb);

		if (izb == "0") break;
		if (izb == "4") q.List();
		if (izb == "5") cout << "Plateni:" << q.Proccess() << endl;
		if (izb == "1") {
			string ime; double suma;
			cout << "Ime: "; getline(cin, ime);
			cout << "Dohod: "; cin >> suma;
			q.Add(new taxEstate(ime, suma));
		};
		if (izb == "2") {
			string adr; double suma;
			cout << "Adres:"; getline(cin, adr);
			cout << "Ocenka:"; cin >> suma;
			q.Add(new taxEstate(adr, suma));
		};
		if (izb == "3") {
			string reg; int p, a;
			cout << "Reg:"; getline(cin, reg);
			cout << "Moshtnost:"; cin >> p;
			cout << "Vuzrast:"; cin >> a;
			q.Add(new taxCar(reg, p, a));
		}
	}
}