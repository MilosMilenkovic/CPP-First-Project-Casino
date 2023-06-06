#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Igrac {
private:
	int identifikator;
	char ime[80];
	int balans;
public:

	Igrac() {
		identifikator = rand() % 1000;
		strcpy_s(ime, "\0");
		balans = 0;
	}
	Igrac(const Igrac& igrac) {  
		identifikator = igrac.identifikator;
		strcpy_s(ime, igrac.ime);
		balans = igrac.balans;
	}
	string uzmi_ime();
	int uzmi_identifikator();
	int uzmi_balans();
	void pisi_igraca();
	void sastavi_igraca();
	void balans_promena(int br);

	
};
class Skor {
private:
	Igrac igrac;
	double rezultat;
public:	
	Skor()
	{
		rezultat = 0;
	}
	void postavi_igraca(Igrac ime);
	void postavi_rezultat(int novi_rezultat);
	void balans(int x);
	void uzmi_igraca();
	double uzmi_rezultat();
	double uzmi_balans_igraca();
	void pisi_skor();

};
class Igra {
public:
	char ime[30];
	struct Lista {
		Skor skor;
		Lista* sled;
	};
	Lista* pocetak, * kraj;
	Igra() {
		strcpy_s(ime, "\0");
		pocetak = nullptr;
		kraj = nullptr;
	};
	virtual ~Igra() {};
	void dodaj_skor(Skor novi_skor);
	void uzmi_ime_igre();
	void sortiraj_listu_rastuci();
	void sortiraj_listu_opadajuci();
	void pisi_listu();
	void promeni_balans(int x);
	void promeni_rezultat(int x);
	int broj_skorova();
	virtual void zapocni_igru()=0;


};
class Pseudorulet :public Igra {
public:
	int ishod;
	string boja_broj;
	bool parni_broj;
	int niz[37];
	Pseudorulet() {
		ishod = 0;
		parni_broj = false;
		for (int i = 0; i < 37; i++)
			niz[i] = -1;
	}
	Pseudorulet& operator *=(const string&);
	int& operator [](int x);
	void operator+(int x);
	void pogodi_brojeve();
	void par_nepar();
	void odredi_boju();
	void generisi_broj();
	void zapocni_igru();
};
class Blekdzek:public Igra {
public:
	int spil[52];
	int ruka[9];
	Blekdzek() {
		strcpy_s(ime, "Blekdzek");
		for (int j = 0; j < 52; j += 4)
			for (int i = j; i < j + 4; i++)
				spil[i] = j / 4 + 1;
		for (int i = 0; i < 9; i++)
			ruka[i] = 0;
	};
	void na_default();
	int trenutni_rezultat();
	void izvuci_kartu();
	void zapocni_igru();
	void promesaj();
	void pisi_ruku();
};

class Kazino {
public:
	Igra* niz[2];
	int budzet = 0;
	Kazino(Pseudorulet a, Blekdzek b) {
		niz[0] = new Pseudorulet;
		niz[1] = new Blekdzek;
		*niz[0] = a;
		*niz[1] = b;
		budzet = 700;
	};
	int uzmi_budzet();
	void prikazi_igre();
	void promeni_budzet(int x);
	void povecaj_balans_igraca_b(int x, Blekdzek igra);
	void povecaj_balans_igraca_r(int x, Pseudorulet igra);
};

