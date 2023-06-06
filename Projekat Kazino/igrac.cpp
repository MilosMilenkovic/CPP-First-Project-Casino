#include "resursi.h"
using namespace std;
void Igrac::pisi_igraca() {
	cout << identifikator << " " << ime << " $" << balans << endl;
};
void Igrac::sastavi_igraca() {
	char korisnik[80];
	int novac;
	cout << "Unesite vase korisnicko ime:";
	cin >> korisnik;
restart:
	cout << "Koliko novca zelite da ulozite?:";
	cin >> novac;
	if (cin.fail()||novac<0)
	{
		cin.clear();
		cin.ignore();
		cout << "Pokusajte opet." << endl;
		goto restart;
	}
	else {
		strcpy_s(ime, korisnik);
		balans = novac;
	}
};
string Igrac::uzmi_ime() {
	return string(ime);
};
int Igrac::uzmi_balans() {
	return balans;
};
int Igrac::uzmi_identifikator() {
	return identifikator;
};
void Igrac::balans_promena(int br) {
	balans += br;
};