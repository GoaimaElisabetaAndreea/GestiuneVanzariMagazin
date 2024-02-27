#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Vanzari {
private:
	int codProdus;
	char* denumire = nullptr;
	float pret;
	int cantitate;
	struct data_calendaristica {
		int an;
		int luna;
		int zi;
	}data;
public:
	Vanzari()
	{
		denumire = nullptr;
		codProdus = 0;
		pret = 0.0;
		cantitate = 0;
		data.an = 2024;
		data.luna = 01;
		data.zi = 01;
	}

	Vanzari(int codProdus, char* denumire, float pret, int cantitate, int an, int luna, int zi)
	{
		this->codProdus = codProdus;
		if (denumire != nullptr)
		{
			this->denumire = new char[sizeof(denumire) + 1];
			strcpy_s(this->denumire, sizeof(denumire) + 1, denumire);
		}
		else
			denumire = nullptr;
		this->pret = pret;
		this->cantitate = cantitate;
		this->data.an = an;
		this->data.luna = luna;
		this->data.zi = zi;

	}

	void setCodProdus(int cod)
	{
		if (cod > 0)
			codProdus = cod;
	}

	int getCodProdus()
	{
		return codProdus;
	}

	void setDenumire(const char* nume)
	{
		if (nume != nullptr)
		{
			denumire = new char[strlen(nume) + 1];
			strcpy_s(denumire, strlen(nume) + 1, nume);
		}
	}

	//returnam copie pentru ca nu ar fi safe sa dam cuiva un pointer la o adresa de memorie cu care noi lucram
	char* getDenumire()
	{
		if (denumire != nullptr)
		{
			char* copie = new char[strlen(denumire) + 1];
			strcpy_s(copie, strlen(denumire) + 1, denumire);
			return copie;
		}
		else
			return nullptr;
	}

	void setPret(float pret)
	{
		if (pret > 0)
			this->pret = pret;
	}

	float getPret()
	{
		return pret;
	}

	void setCantitate(int cantitate)
	{
		if (cantitate > 0)
			this->cantitate = cantitate;
	}

	int getCantitate()
	{
		return cantitate;
	}

	void setAn(int an)
	{
		if (an >= 2000 && an <= 2024)
			this->data.an = an;
	}

	int getAn()
	{
		return data.an;
	}

	void setLuna(int luna)
	{
		if (luna >= 1 && luna <= 12)
			this->data.luna = luna;
	}

	int getLuna()
	{
		return data.luna;
	}

	void setZi(int zi)
	{
		if (zi >= 1 && zi <= 31)
			this->data.zi = zi;
	}

	int getZi()
	{
		return data.zi;
	}

	void getData()
	{
		cout << data.zi << "." << data.luna << "." << data.an << endl;
	}

	Vanzari(const Vanzari& v)
	{
		if (v.codProdus >= 0)
		{
			this->codProdus = v.codProdus;
		}
		if (v.denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = new char[sizeof(v.denumire) + 1];
			strcpy_s(this->denumire, sizeof(v.denumire) + 1, v.denumire);
		}
		else
			this->denumire = nullptr;
		if (v.pret > 0)
		{
			this->pret = v.pret;
		}
		if (v.cantitate > 0)
		{
			this->cantitate = v.cantitate;
		}
		if (v.data.an >= 2000 && v.data.an <= 2024)
		{
			this->data.an = v.data.an;
		}
		if (v.data.luna >= 1 && v.data.luna <= 12)
		{
			this->data.luna = v.data.luna;
		}
		if (v.data.zi >= 1 && v.data.zi <= 31) //ar trebui verificat pentru fiecare luna
		{
			this->data.zi = v.data.zi;
		}
	}

	Vanzari& operator=(const Vanzari& v)
	{
		if (this != &v) //verificam sa nu se faca autoasignare, adica sa am obiectul a si sa zic a=a
		{
			if (v.codProdus >= 0)
			{
				this->codProdus = v.codProdus;
			}
			if (v.denumire != nullptr)
			{
				delete[] this->denumire;
				this->denumire = new char[sizeof(v.denumire) + 1];
				strcpy_s(this->denumire, sizeof(v.denumire) + 1, v.denumire);
			}
			else
				this->denumire = nullptr;
			if (v.pret > 0)
			{
				this->pret = v.pret;
			}
			if (v.cantitate > 0)
			{
				this->cantitate = v.cantitate;
			}
			if (v.data.an >= 2000 && v.data.an <= 2024)
			{
				this->data.an = v.data.an;
			}
			if (v.data.luna >= 1 && v.data.luna <= 12)
			{
				this->data.luna = v.data.luna;
			}
			if (v.data.zi >= 1 && v.data.zi <= 31) //ar trebui verificat pentru fiecare luna
			{
				this->data.zi = v.data.zi;
			}
		}
		return *this; // returnam obiectul pentru a face apel in cascada adica a=b=c
	}
	~Vanzari() {
		if (denumire != nullptr)
		{
			delete[] denumire;
			denumire = nullptr;
		}
	}

	float vanzariTotalePerioada()
	{
		Vanzari v;
		float s = 0;
		string nume;
		int ok = 1;
		int an1, luna1, zi1 = 1;
		int an2, luna2, zi2 = 1;
		while (ok == 1)
		{
			cout << "Introduceti anul perioadei de incepere a vanzarii: " << endl;
			cin >> an1;
			int ok2 = 1;
			while (ok2 == 1)
			{
				if (an1 > 2024)
				{
					cout << "Anul nu poate fi mai mare de 2024" << endl;
					cout << "Introduceti anul perioadei de incepere a vanzarii: " << endl;
					cin >> an1;
				}
				else if (an1 < 0)
				{
					cout << "Anul nu poate fi un numar negativ" << endl;
					cout << "Introduceti anul perioadei de incepere a vanzarii: " << endl;
					cin >> an1;

				}
				else
					ok2 = 0;
			}
			cout << "Introduceti anul perioadei de sfarsit a vanzarii: " << endl;
			cin >> an2;
			ok2 = 1;
			while (ok2 == 1)
			{
				if (an2 > 2024)
				{
					cout << "Anul nu poate fi mai mare de 2024" << endl;
					cout << "Introduceti anul perioadei de sfarsit a vanzarii: " << endl;
					cin >> an2;
				}
				else if (an2 < 0)
				{
					cout << "Anul nu poate fi un numar negativ" << endl;
					cout << "Introduceti anul perioadei de sfarsit a vanzarii: " << endl;
					cin >> an2;
				}
				else ok2 = 0;
			}
			if (an1 > an2)
				cout << "Anul perioadei de incepere nu poate fi mai mare decat anul de sfarsit al perioadei" << endl;
			else
				ok = 0;
		}
		ok = 1;
		while (ok == 1)
		{
			cout << "Introduceti luna perioadei de incepere a vanzarii: " << endl;
			cin >> luna1;
			cout << "Introduceti luna perioadei de sfarsit a vanzarii: " << endl;
			cin >> luna2;

			if (luna1 >= 1 && luna1 <= 12 && luna2 >= 1 && luna2 <= 12)
			{
				if (an1 == an2 && luna1 > luna2)
				{
					cout << "Luna perioadei de incepere nu poate fi mai mare decat luna de sfarsit a perioadei" << endl;
					cout << "Introduceti luna perioadei de incepere a vanzarii: " << endl;
					cin >> luna1;
					cout << "Introduceti luna perioadei de sfarsit a vanzarii: " << endl;
					cin >> luna2;
				}
				else if (an1 == an2 && luna1 <= luna2)
					ok = 0;
				else
					ok = 0;
			}
			else
			{
				cout << "Luna introdusa nu este valida. Introduceti o luna intre 1 si 12." << endl;
			}
		}
		ok = 1;
		while (ok == 1)
		{
			if (luna1 == luna2)
			{
				cout << "Introduceti ziua perioadei de incepere a vanzarii: " << endl;
				cin >> zi1;
				cout << "Introduceti ziua perioadei de sfarsit a vanzarii: " << endl;
				cin >> zi2;
				while (ok == 1)
				{
					if (zi1 > zi2 || zi1 < 1 || zi2 > 31)
					{
						cout << "Ziua introdusa nu este valida. Introduceti o zi intre 1 si 31 si asigurati-va ca ziua de incepere nu este mai mare decat ziua de sfarsit." << endl;
						cout << "Introduceti ziua perioadei de incepere a vanzarii: " << endl;
						cin >> zi1;
						cout << "Introduceti ziua perioadei de sfarsit a vanzarii: " << endl;
						cin >> zi2;
					}
					else
					{
						ok = 0;
					}
				}
			}
			else
			{
				ok = 1;
				while (ok == 1)
				{
					cout << "Introduceti ziua perioadei de incepere a vanzarii: " << endl;
					cin >> zi1;
					cout << "Introduceti ziua perioadei de sfarsit a vanzarii: " << endl;
					cin >> zi2;
					if ((zi1 > 1) && (zi2 > 1) && zi1 < 31 && zi2 < 31)
					{
						ok = 0;
					}
					else
					{
						cout << "Ziua introdusa nu este valida. Introduceti o zi intre 1 si 31" << endl;
					}
				}
			}
		}

		cout << "Introduceti numele fisierului din care doriti sa cititi date: ";
		cin >> nume;
		ifstream f;
		f.open(nume);
		if (f.is_open())
		{
			while (f >> *this)
			{
				if (an1 == an2 && an2 == this->data.an)
				{
					if (luna1 == luna2 && luna2 == this->data.luna)
					{
						if (this->data.zi >= zi1 && this->data.zi <= zi2)
						{
							s += (this->pret * this->cantitate);
						}
					}
					else if (this->data.luna == luna1)
					{
						if (this->data.zi >= zi1)
						{
							s += (this->pret * this->cantitate);
						}
					}
					else if (this->data.luna == luna2)
					{
						if (this->data.zi <= zi2)
						{
							s += (this->pret * this->cantitate);
						}
					}
					else if (luna1 < this->data.luna && this->data.luna < luna2)
					{
						s += (this->pret * this->cantitate);
					}
				}
				else if (this->data.an == an1)
				{
					if (this->data.luna >= luna1)
					{
						if (this->data.luna == luna1 && this->data.zi >= zi1)
						{
							s += (this->pret * this->cantitate);
						}
						else if (this->data.luna > luna1)
						{
							s += (this->pret * this->cantitate);
						}

					}
				}
				else if (this->data.an == an2)
				{
					if (this->data.luna <= luna2)
					{
						if (this->data.luna == luna2 && this->data.zi >= zi2)
						{
							s += (this->pret * this->cantitate);
						}
						else if (this->data.luna < luna2)
						{
							s += (this->pret * this->cantitate);
						}

					}
				}
				else if (an1 < this->data.an && this->data.an < an2)
				{
					s += (this->pret * this->cantitate);
				}
			}
		}
		else
			cout << "eroare la deschiderea fisierului";
		return s;
	}

	int operator()(int valore, int ca)
	{
		int s = 0;
		return s;
	}

	friend ostream& operator<<(ostream& out, Vanzari v);
	friend istream& operator>>(istream&, Vanzari& v);
	friend ifstream& operator>>(ifstream& f, Vanzari& v);

};

//operator pentru afisare in consola si din fisier
ostream& operator<<(ostream& out, Vanzari v)
{
	cout << "Cod produs: ";
	out << v.codProdus << endl;
	cout << "Denumire produs: ";
	if (v.denumire != nullptr)
	{
		out << v.denumire << endl;
	}
	cout << "Pret: ";
	out << v.pret << endl;
	cout << "Cantitate: ";
	out << v.cantitate << endl;
	cout << "Data vanzarii: ";
	out << v.data.zi << endl;
	out << v.data.luna << endl;
	out << v.data.an << endl;
	out << endl;
	return out;
}

//operator citire de la consola
istream& operator>>(istream& in, Vanzari& v)
{
	cout << "Cod produs: " << endl;
	in >> v.codProdus;
	cout << "Denumire: " << endl;
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	if (v.denumire != nullptr)
	{
		delete[] v.denumire;
		v.denumire = nullptr;
	}
	v.denumire = new char[strlen(buffer) + 1];
	strcpy_s(v.denumire, strlen(buffer) + 1, buffer);
	cout << "Pret: " << endl;
	in >> v.pret;
	cout << "Cantitate: " << endl;
	in >> v.cantitate;
	cout << "Introduceti data vanzarii" << endl;
	cout << "Anul: " << endl;
	in >> v.data.an;
	cout << "Luna: " << endl;
	in >> v.data.luna;
	cout << "Ziua: " << endl;
	in >> v.data.zi;
	return in;


}

//operator citire din fisier text
ifstream& operator>>(ifstream& f, Vanzari& v)
{
	if (f.is_open())
	{
		int cod = 0;
		string nume;
		float pret = 0;
		int cantitate = 0;
		int an = 0, luna = 0, zi = 0;
		f >> cod;
		v.setCodProdus(cod);
		f >> nume;
		if (sizeof(nume) > 0)
		{
			v.setDenumire(nume.c_str());
		}
		f >> pret;
		v.setPret(pret);
		f >> cantitate;
		v.setCantitate(cantitate);
		f >> zi;
		v.setZi(zi);
		f >> luna;
		v.setLuna(luna);
		f >> an;
		v.setAn(an);
	}
	return f;
}

int main()
{
	char* denumire = new char[4];
	strcpy_s(denumire, 4, "apa");
	char* denumire2 = new char[6];
	strcpy_s(denumire2, 6, "lapte");
	char* denumire3 = new char[6];
	strcpy_s(denumire3, 6, "paine");
	char* denumire4 = new char[4];
	strcpy_s(denumire4, 4, "oua");
	Vanzari v1(1, denumire, 2.3, 2, 2023, 02, 01), v2;
	Vanzari v3(2, denumire2, 7.5, 2, 2024, 02, 02);
	Vanzari v4(3, denumire3, 1, 2, 2024, 02, 03);
	Vanzari v5(4, denumire4, 2, 3, 2023, 02, 04);
	ofstream f;
	f.open("fisier.txt");
	f << v1;
	f << v3;
	f << v4;
	f << v5;
	f.close();
	cout << v2.vanzariTotalePerioada();
	delete[] denumire;
	delete[] denumire2;
	delete[] denumire3;
	delete[] denumire4;
}


