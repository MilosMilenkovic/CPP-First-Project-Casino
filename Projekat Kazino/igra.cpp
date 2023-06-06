#include "resursi.h"
void Igra::uzmi_ime_igre() {
	cout << ime;
};
void Igra::dodaj_skor(Skor novi_skor) {
    Lista* novi = new Lista;
    novi->skor = novi_skor;
    novi->sled = nullptr;
    if (!pocetak) {
        pocetak = novi;
    }
    else {
        Lista* temp;
        temp = pocetak;
        while (temp->sled)
            temp = temp->sled;
        temp->sled = novi;
    }
    if (broj_skorova()==1) {
        kraj = pocetak;
    }
    else
    {
        Lista* temp;
        temp = pocetak;
        while (temp->sled)
            temp = temp->sled;
        kraj = temp;
    }
};
void Igra::pisi_listu() {
    Lista* temp = pocetak;
    if (!temp)
        cout << "Trenutno nema podataka o predjasnjim rezultatima." << endl;
    else
        cout << left << setw(20) << "Ime" << right << setw(68) << "Rezultat" << endl;
    while (temp) {
        temp->skor.pisi_skor();
        temp = temp->sled;
    };
    cout << "------------------------------------------------------------------------------------------" << endl;
};
   

void Igra::sortiraj_listu_rastuci() {
    Skor temp;
    Lista* i, * j;
    for (i = pocetak; i; i = i->sled)
    {
        for (j = i->sled; j; j = j->sled)
        {
            if (j->skor.uzmi_rezultat() < i->skor.uzmi_rezultat())
            {
                temp = i->skor;
                i->skor = j->skor;
                j->skor = temp;
            }
        }
    }
};
void Igra::sortiraj_listu_opadajuci() {
    Skor temp;
    Lista* i, * j;
    for (i = pocetak; i; i = i->sled)
    {
        for (j = i->sled; j; j = j->sled)
        {
            if (j->skor.uzmi_rezultat() > i->skor.uzmi_rezultat())
            {
                temp = i->skor;
                i->skor = j->skor;
                j->skor = temp;
            }
        }
    }
};
void Igra::promeni_balans(int budzet) {
    Lista* tek = kraj;
    tek->skor.balans(budzet);
};
void Igra::promeni_rezultat(int x) {
    Lista* tek = kraj;
    tek->skor.postavi_rezultat(x);
};
int Igra::broj_skorova() {
    Lista* tek = pocetak;
    int brojac = 0;
    while (tek) {
        tek = tek->sled;
        brojac++;
    }
    return brojac;
};
