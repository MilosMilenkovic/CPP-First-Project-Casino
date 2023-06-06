#include "resursi.h"
void Skor::postavi_igraca(Igrac ime) {
	igrac = ime;
};
void Skor::postavi_rezultat(int novi_rezultat) {
	rezultat += novi_rezultat;
};
void Skor::uzmi_igraca() {
	 igrac.pisi_igraca();
};
void Skor::balans(int x) {
	igrac.balans_promena(x);
};
double Skor::uzmi_rezultat() {
	return rezultat;
};
double Skor::uzmi_balans_igraca() {
	int x = igrac.uzmi_balans();
	return x;
};
void Skor::pisi_skor() {
	const char razmak = ' ';
	const int ime_duzina = 80;
	const int skor_duzina = 10;
	cout <<left<<setw(ime_duzina+skor_duzina) << setfill('-') << "-"<<endl;
	cout << left << setw(ime_duzina) << setfill(razmak) << igrac.uzmi_ime() << setw(skor_duzina) << setfill(razmak) << rezultat << endl;
	
	
};
