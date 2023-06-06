#include "resursi.h"
void Blekdzek::promesaj() {
    srand(time(NULL));
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = spil[i];
        spil[i] = spil[j];
        spil[j] = temp;
    }
};
int Blekdzek::trenutni_rezultat() {
    int rezultat = 0;
    for (int i = 0; i < 9; i++) {
        if (ruka[i] < 11 && ruka[i] >= 2)
            rezultat += ruka[i];
        else if (ruka[i] > 10)
            rezultat += 1;
    }
    for (int i = 0; i < 9; i++) {
        if (ruka[i] == 1)
            if (rezultat > 10)
                rezultat += 1;
            else
                rezultat += 11;
    }
    return rezultat;
};
void Blekdzek::pisi_ruku() {
    cout << "Ruka: ";
    for (int i = 0; i < 9; i++)
        if (ruka[i] != 0)
            cout << ruka[i] << " ";
    cout << endl;
};
void Blekdzek::izvuci_kartu() {
    for (int i = 0; i < 9; i++) {
        if (ruka[i] == 0) {
            for (int j = 0; j < 52; j++)
            {
                if (spil[j] != 0) {
                    ruka[i] = spil[j];
                    spil[j] = 0;
                    break;
                }
            }
            cout << "Izvucena karta: " << ruka[i] << endl;
            break;
        }
    }
    cout << "Trenutni rezultat: " << trenutni_rezultat() << endl;
    pisi_ruku();
};
void Blekdzek::na_default() {
    for (int j = 0; j < 52; j += 4)
        for (int i = j; i < j + 4; i++)
            spil[i] = j / 4 + 1;
    for (int i = 0; i < 9; i++)
        ruka[i] = 0;
};

void Blekdzek::zapocni_igru(){
    promesaj();
    int izbor = 0;
    while (izbor != 4) {
        cout << "=============================================================================" << endl
             << "                              Blekdzek" << endl
             << "                             Izaberite opciju:" << endl
             << "                           [1]Izvucite kartu " << endl
             << "                           [2]Prekinite igru" << endl
             << "                           [3]Prikazi listu rezultata" << endl
             << "                           [4]Izlaz" << endl
             << "=============================================================================" << endl;
    
        if (ruka[8] != 0 && trenutni_rezultat() < 21)
        {
            cout << "Cestitamo! Ako zelite mozete poceti novu partiju, u suprotnom izaberite opciju izlaz. " << endl;
            promeni_balans(3);
            promeni_rezultat(5);
            kraj->skor.uzmi_igraca();
            na_default();
            promesaj();
            izbor = 4;
        }
        else {
        restart:
        
        cin >> izbor;
        if (cin.fail() || izbor > 4 || izbor < 1) {
            cin.clear();
            cin.ignore();
            cout << "Nemoguc unos. Pokusajte ponovo." << endl;
            goto restart;
        }
        else {
            switch (izbor) {
            case 1:
                izvuci_kartu();
                if (trenutni_rezultat() > 21) {
                    cout << "Zbir je premasio 21, gubitak." << endl
                        << "Mozete krenuti novu partiju, a ako ne zelite izaberite opciju izlaz" << endl;
                    promeni_balans(-3);
                    promeni_rezultat(-1);
                    izbor = 4;
                    na_default();
                    promesaj();
                   
                }
                break;
            case 2: {
                int rezultat_kazino = rand() % 7 + 15;
                if (rezultat_kazino > trenutni_rezultat()) {
                    cout << "Izgubili ste. " << endl;
                    promeni_balans(-3);
                    promeni_rezultat(-1);
                    na_default();
                    promesaj();
                    izbor = 4;
                }
                else
                {
                    cout << "Cestitamo, pobedili ste." << endl;
                    promeni_balans(3);
                    promeni_rezultat(5);
                    na_default();
                    promesaj();
                    izbor = 4;
            
                }


            }
                  break;
            case 3:
                sortiraj_listu_opadajuci();
                pisi_listu();
                break;
            case 4: {
                cout << "Izlaz." << endl;
                na_default();
                promesaj();
                break;
            }
            }
        }


        }
    }
}