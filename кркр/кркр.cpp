#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mebeli
{
public:
	Mebeli() {};
	~Mebeli() {};
	virtual void print_info() = 0;
	virtual int calc_cena() = 0;

protected:
	string name;
	int price; 
};

class Masa :public Mebeli
{
public:
	Masa(string ime, string razmer, string mat, int cena) {                          //1.malka 
		name = ime; size = razmer; material = mat; price = cena;                    //2.sredna 
	};                                                                             //3.golqma 
	~Masa() {};
	
	virtual int calc_cena() {                                                           //1.styklena +80lv
		if (size == "1") {                                                             //2.dyrwena +50lv
			if (material == "1")                                                      //3.jelqzna i dyrwena +70lv
				return price + 80;
			else if (material == "2")
				return price + 50;
			else return price + 70;
		}
		else if (size == "2"){
			if (material == "1")
				return price *1.2 + 80;
			else if (material == "2") 
				return price * 1.2 + 50;
			else return price * 1.2 + 70; 
		}
		else {
			if (material == "1")
				return price * 1.5 + 80;
			else if (material == "2")
				return price * 1.5 + 50;
			else return price * 1.5 + 70;
		}
	}
	virtual void print_info() {
		cout << "Masa - " << name << " Razmer - " << size << ", Material - " << material << ", Cena - " << calc_cena() << "lv." << endl;
	}

private:
	string size; string material;
};

class Divan :public Mebeli
{
public:
	Divan(string ime, string razmer, string razteg, int cena) {
		name = ime; size = razmer; raztegatelen = razteg; price = cena;
	};
	~Divan() {};
	virtual int calc_cena() {
		if (size == "1") {
			if (raztegatelen == "1") return price + 500;
			else return price;
		}
		else if (size == "2") {
			if (raztegatelen == "1") return price + 500;
			else return price;
		}
		else {
			if (raztegatelen == "1") return price + 500;
			else return price;
		}
	}
	virtual void print_info(){
		cout << "Diwan - " << name << ", Razmer - " << size << ", Raztegatelen - " << raztegatelen << ", Cena - " << calc_cena()  << "lv." << endl;
	}

private:
	string size;
	string raztegatelen;
};

class Stol :public Mebeli
{
public:
	Stol(string ime, string vid, int cena) {
		name = ime; type = vid; price = cena;
	};
	~Stol() {};
	virtual int calc_cena() {
		if (type == "1") return price;
		else if (type == "2") return price + 50;
		else return price + 100;
	}
	virtual void print_info() {
		cout << "Stol - " << name << ", Wid stol - " << type << ", Cena - " << calc_cena() << "lv." << endl;
	}

private:
	string type;
};
class Proizvodstwo
{
public:
	Proizvodstwo() {};
	~Proizvodstwo() {};
	void Add(Mebeli* obj) { 
		spisyk.push_back(obj); 
		cout << "Poruchkata e prieta." << endl << endl;
	};
	void List() {
		if (spisyk.empty()) {
			cout << "Nqma porychki za mebeli.\n";
		}
		else {
			cout << "Prorychkite za mebeli sa: \n";
			for (int x = 0; x < spisyk.size(); x++)
				spisyk[x]->print_info();
		}
	};
	int Obrabotka() {
		if (spisyk.empty()) {
			cout << "Nqma porychki za mebeli.\n";
			return 0;
		}
		else {
			cout << "Wywedete nomer na porychka: "; cin >> e;
			if ((e > 0) && (e - 1< spisyk.size())) {
				int price = spisyk[e-1]->calc_cena();
				spisyk.erase(spisyk.begin() + (e -1));
				return price;
			}
			else {
				cout << "Greshen nomer na porychka!!!!!" << endl << endl;
				return 0;
			}
		}
	};

private:
	vector <Mebeli*> spisyk;
	int e;
};
,
int main()
{
	Proizvodstwo m;
	string opciq;

	while (true) {
		cout << "---------------------Menu---------------------" << endl;
		cout << "1.Porychka na masa\n2.Porychka na divan\n3.Poruchka na stol\n4.Izvejdane na spisyka s poruchki\n5.Obrabotka na porychka\n0.Izhod" << endl << endl;
		cout << "Izberete opciq: "; getline(cin, opciq);

		if (opciq == "0") break;
		if (opciq == "1") {
			string name, size, material; int price;
			cout << "Izberete model na masa: Victoria, Sophia, Mara.\nModel: "; getline(cin, name);
			cout << "Izberete edin ot slednite razmeri:\n1.Malka\n2.Sredna\n3.Golqma\nRazmer: "; getline(cin, size);
			cout << "Izberete edin slednite materiali: \n1.Styklo\n2.Dyrwo\n3.Jelqzo\nMaterial: "; getline(cin, material);
			cout << "Kakwa da e nachalnata cena? "; cin >> price;
			m.Add(new Masa(name, size, material, price));
		}
		if (opciq == "2") {
			string name, size, raztegatelen; int price;
			cout << "Izberete model na diwan: Victoria, Sophia, Mara.\nModel: "; getline(cin, name);
			cout << "Izberete edin ot slednite razmeri:\n1.Malyk\n2.Sreden\n3.Golqm\nRazmer: "; getline(cin, size);
			cout << "Da byde li raztegatelen?   1.Da   2.Ne\nOtgovor: "; getline(cin, raztegatelen);
			cout << "Kakwa da e nachalnata cena? "; cin >> price;
			m.Add(new Divan(name, size, raztegatelen, price));
		}
		if (opciq == "3") {
			string name, vid; int price;
			cout << "Izberete model na stol: Victoria, Sophia, Mara.\nModel: "; getline(cin, name);
			cout << "Izberete edna ot slednite opcii: \n1.Dyrwen\n2.Jelezen\n3.Wyrtqsht se\nOpciq: "; getline(cin, vid);
			cout << "Kakwa da e nachalnata cena? "; cin >> price;
			m.Add(new Stol(name, vid, price));
		}
		if (opciq == "4") m.List();
		if (opciq == "5") cout << "Obrabotena porucka - " << m.Obrabotka() << endl;
	}
}