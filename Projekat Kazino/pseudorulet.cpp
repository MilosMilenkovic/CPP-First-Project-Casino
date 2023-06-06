#include "resursi.h"
Pseudorulet& Pseudorulet::operator *=(const string& x) {
	this->boja_broj = x;
	return *this;
};
int& Pseudorulet::operator [](int x) {
	return niz[x];
};
void Pseudorulet::operator+(int x) {
	promeni_balans(x);
}
void Pseudorulet::generisi_broj() {
	ishod = rand() % 37;
};
void Pseudorulet::odredi_boju() {
	srand(time(NULL));
	generisi_broj();
	if (ishod < 11 || (ishod > 18 && ishod < 29)) {
		if (ishod % 2 == 0)
			boja_broj = "c";
		else
			boja_broj = "r";
	}
	else if (ishod > 10 && ishod < 19 || (ishod > 28 && ishod < 37))
	{
		if (ishod % 2 == 0)
			boja_broj = "r";
		else
			boja_broj = "c";
	}
	restart:
	string unos;
	cout << "Unesite boju(r-crvena, c-crna):";
	cin >> unos;
	if (cin.fail() || unos!="r" && unos != "c") {
		cin.clear();
		cin.ignore();
		cout << "Nemoguc unos. Pokusajte ponovo." << endl;
		goto restart;
	}
	else {
		if (unos == boja_broj) {
			cout << "Boja je: " << ishod<< boja_broj << "." << endl
			  << "Pogodak." << endl;
			promeni_balans(3);
			promeni_rezultat(5);
		}
		else {
			cout << "Boja je: " << ishod << boja_broj << "." << endl
			     << "Promasaj." << endl;
			promeni_balans(-3);
			promeni_rezultat(-1);
		}
	}
};
void Pseudorulet::par_nepar() {
	srand(time(NULL));
	generisi_broj();
	if (ishod % 2 == 0)
		parni_broj = true;
	else
		parni_broj = false;
restart:
	string unos;
	cout << "Unesite parnost(p-parni, n-neparni):";
	cin >> unos;
	if (cin.fail() || unos != "p" && unos != "n") {
		cin.clear();
		cin.ignore();
		cout << "Nemoguc unos. Pokusajte ponovo." << endl;
		goto restart;
	}
	else {
		if (unos == "p") {
			if (parni_broj)
			{
				cout << "Broj je: " << ishod << ". " << endl
					<< "Pogodak." << endl;
				promeni_balans(3);
				promeni_rezultat(5);
			}
			else {
				cout << "Broj je: " << ishod << ". " << endl
					<< "Promasaj." << endl;
				promeni_balans(-3);
				promeni_rezultat(-1);
			}
		}
		if (unos == "n") {
			if (!parni_broj)
			{
				cout << "Broj je: " << ishod << ". " << endl
					<< "Pogodak." << endl;
				promeni_balans(3);
				promeni_rezultat(5);
			}
			else {
				cout << "Broj je: " << ishod << ". " << endl
					<< "Promasaj." << endl;
				promeni_balans(-3);
				promeni_rezultat(-1);
			}
		}

	}

};
void Pseudorulet::pogodi_brojeve() {
	generisi_broj();
	int brojac, brojac_pogodak = 0, brojac_promasaj = 0, razlika;
	cout << "Koliko brojeva zelite da unesete:";
restart:
	cin >> brojac;
	if (cin.fail() || brojac < 1 || brojac>37) {
		cin.clear();
		cin.ignore();
		cout << "Nemoguc unos. Pokusajte ponovo." << endl;
		goto restart;
	}
	for (int i = 0; i < brojac; i++) {
		int broj;
		cout << "Unesite " << i + 1 << ". " << "broj:";
	restart1:
		cin >> broj;
		if (cin.fail() || brojac < 1 || brojac>37) {
			cin.clear();
			cin.ignore();
			cout << "Nemoguc unos. Pokusajte ponovo." << endl;
			goto restart1;
		}
		niz[i] = broj;
	}
	for (int i = 0; i < brojac; i++) {
		if (niz[i] == ishod) {
			brojac_pogodak++;
			promeni_balans(3);
			promeni_rezultat(5);
		}
		else {
			brojac_promasaj++;
			promeni_balans(-3);
			promeni_rezultat(-1);
		}
	}
	cout << "Broj je: " << ishod << "." << endl;
	cout << "Vasi brojevi: ";
	for (int i = 0; i < brojac; i++)
		cout << niz[i] << (i == brojac - 1 ? "." : ", ");
	cout << endl;
	if (brojac_pogodak == 1) {
		cout << "Pogodili ste broj." << endl;
	}
	else
		cout << "Niste pogodili broj." << endl;
	razlika = brojac_pogodak * 3 - brojac_promasaj * 3;
	if (razlika > 0 && razlika != brojac_promasaj * 3)
		cout << "Zaradili ste $" << razlika << ". " << endl;
	else {
		if (razlika == brojac_promasaj * 3)
			cout << "Izgubili ste $" << razlika << ". " << endl;
		else
			cout << "Izgubili ste $" << (-1) * razlika << ". " << endl;
	}
};
void Pseudorulet::zapocni_igru() {
	int izbor = 0;
	while (izbor != 5) {
		cout << "=============================================================================" << endl
			<< "                              Pseudorulet" << endl
			<< "                             Izaberite opciju:" << endl
			<< "                           [1]Par-nepar " << endl
			<< "                           [2]Pogodi broj" << endl
			<< "                           [3]Pogodi boju" << endl
			<< "                           [4]Prikazi listu rezultata"<<endl
			<< "                           [5]Izlaz" << endl
			<< "=============================================================================" << endl;
	restart:
		cin >> izbor;
		if (cin.fail() || izbor > 5 || izbor < 1) {
			cin.clear();
			cin.ignore();
			cout << "Nemoguc unos. Pokusajte ponovo." << endl;
			goto restart;
		}
		else
		{
			switch (izbor) {
			case 1:
				par_nepar();
				break;
			case 2:
				pogodi_brojeve();
				break;
			case 3:
				odredi_boju();
				break;
			case 4:
				sortiraj_listu_opadajuci();
				pisi_listu();
				break;
			case 5:
				cout << "Izlaz" << endl;
				izbor = 5;
				break;
			}
		}
	}
}
