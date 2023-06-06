#include "resursi.h"
int Kazino::uzmi_budzet() {
	return budzet;
};
void Kazino::prikazi_igre() {
	cout << "=============================================================================" << endl
		<< "                              Dobrodosli! " << endl
		<< "                             Izaberite igru:" << endl
		<< "                            [1]Rulet " << endl
		<< "                            [2]Blekdzek  " << endl
		<< "                            [3]Izlaz "<<endl
		<< "=============================================================================" << endl;
};
void Kazino::povecaj_balans_igraca_r(int x, Pseudorulet igra) {
	igra.promeni_balans(x);
};
void Kazino::povecaj_balans_igraca_b(int x, Blekdzek igra) {
	igra.promeni_balans(x);
};
void Kazino::promeni_budzet(int x) {
	budzet += x;
}