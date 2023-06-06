#include "resursi.h"
using namespace std;
int main() {
    Igrac igrac;
    Pseudorulet rulet;
    Skor skor;
    Blekdzek bj;
    string izbor = "d";
    Kazino kazino(rulet, bj);
    while (izbor == "d")
    {
        cout << "=============================================================================" << endl;
        cout << "                         Dobrodosli u Kazino." << endl
            << "Zelite li da se registujete? " << endl
            << "Unesite \"d\" kako biste se registrovali, a bilo koji drugi karakter za izlaz." << endl
            << "=============================================================================" << endl;
        cin >> izbor;
        if (cin.fail() || izbor != "d") {
            cout << "Dovidjenja!" << endl;
            izbor = "n";

        }
        else {

            cout << "=============================================================================" << endl;
            igrac.sastavi_igraca();
            skor.postavi_igraca(igrac);
            kazino.niz[0]->dodaj_skor(skor);
            kazino.niz[1]->dodaj_skor(skor);
            cout << "=============================================================================" << endl;
            if (igrac.uzmi_balans() > 10 && kazino.uzmi_budzet() > 500) {
                int izbor_igre = 0;
                while (izbor_igre != 3) {
                    kazino.prikazi_igre();
                restart:
                    cin >> izbor_igre;
                    if (cin.fail() || izbor_igre > 3 || izbor_igre < 1) {
                        cin.clear();
                        cin.ignore();
                        cout << "Nemoguc unos. Pokusajte ponovo." << endl;
                        goto restart;
                    }
                    else {
                        switch (izbor_igre)
                        {
                        case 1: {
                            int izbor_rulet = 0;
                            int x = kazino.niz[0]->kraj->skor.uzmi_balans_igraca();
                            kazino.niz[0]->zapocni_igru();
                            if (x > kazino.niz[0]->kraj->skor.uzmi_balans_igraca())
                                kazino.promeni_budzet(x - kazino.niz[0]->kraj->skor.uzmi_balans_igraca());
                            else
                                kazino.promeni_budzet(kazino.niz[0]->kraj->skor.uzmi_balans_igraca() - x);
                        }
                              break;
                        case 2: {
                            int y = kazino.niz[1]->kraj->skor.uzmi_balans_igraca();
                            kazino.niz[1]->zapocni_igru();
                            if (y > kazino.niz[1]->kraj->skor.uzmi_balans_igraca())
                                kazino.promeni_budzet(y - kazino.niz[1]->kraj->skor.uzmi_balans_igraca());
                            else
                                kazino.promeni_budzet(kazino.niz[1]->kraj->skor.uzmi_balans_igraca() - y);
                        }
                              break;
                        }
                    }
                }
            }
            else {
                if (igrac.uzmi_balans() < 10) {
                    int suma;
                    cout << "Balans mora biti veci od 10 kako biste igrali. Molimo vas uplatite jos novca." << endl << "Unesite sumu : " << endl;
                rs:
                    cin >> suma;
                    if (cin.fail() || suma < 0) {
                        cin.clear();
                        cin.ignore();
                        cout << "Nemoguc unos. Pokusajte ponovo." << endl;
                        goto rs;
                        igrac.balans_promena(suma);
                    }
                    else if (kazino.uzmi_budzet() < 500) {
                        cout << "Izvinjavamo se, budzet kazina se trenutno obnavlja, pokusajte opet." << endl;
                        kazino.promeni_budzet(500);
                    }
                }

            }
        }
    }
}
    
   
   
