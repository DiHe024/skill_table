/*
##########################################################################
--------------------------------------------------------------------------
	Datum:			09.04.23
	Name :			D.Henning
	Modul:			PRG24 - Programmierparadigmen
	Thema:			Laborbericht zu Klassen und Operationen
	Beschreibung:	Umsetzung Klassendiagramm der VHS-Aichach-Friedberg
	Datei:			VHSKlassen.h
--------------------------------------------------------------------------
##########################################################################
*/
#pragma once
#ifndef VHSKlassen

#define VHSKlassen

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#############################################################################################################//
//#############################################################################################################//

class Adresse
{
private:
	string strasse;
	string hausnummer;
	string plz;
	string ort;
public:
	Adresse(string newStr = "", string newHnr = "", string newPlz = "", string newOrt = "");
	void setStrasse(string newStr);
	void setHausnummer(string newHnr);
	void setPLZ(string newPlz);
	void setOrt(string newOrt);
	string getStrasse();
	string getHausnummer();
	string getPLZ();
	string getOrt();
	~Adresse();
};

Adresse::Adresse(string newStr, string newHnr, string newPlz, string newOrt)
{
	strasse = newStr;
	hausnummer = newHnr;
	plz = newPlz;
	ort = newOrt;
}

void Adresse::setStrasse(string newStr){strasse = newStr;}
void Adresse::setHausnummer(string newHnr){	hausnummer = newHnr;}
void Adresse::setPLZ(string newPLZ){hausnummer = newPLZ;}
void Adresse::setOrt(string newOrt){hausnummer = newOrt;}

string Adresse::getStrasse() { return strasse; }
string Adresse::getHausnummer() { return hausnummer; }
string Adresse::getPLZ() { return plz; }
string Adresse::getOrt() { return ort; }

Adresse::~Adresse(){cout << "Objekt von Adresse geloescht!";}

//#############################################################################################################//
//#############################################################################################################//

class Bankverbindung
{
private:
	string bankname;
	string iban;
	string bic;
public:
	Bankverbindung(string newBName = "", string newIban = "", string newBic = "");
	void setBankname(string newBankname);
	void setIban(string newIban);
	void setBic(string newBic);
	string getIban();
	string getBankname();
};

Bankverbindung::Bankverbindung(string newBName, string newIban, string newBic)
{
	bankname = newBName;
	iban = newIban;
	bic = newBic;
}
void Bankverbindung::setBankname(string newBankname) { bankname = newBankname; }
void Bankverbindung::setIban(string newIban) { iban = newIban; }
void Bankverbindung::setBic(string newBic) { bic = newBic; }

string Bankverbindung::getIban() { return iban; }
string Bankverbindung::getBankname() { return bankname; }

//#############################################################################################################//
//#############################################################################################################//

class Termin
{
private:
	static int termininstanzen;
	int terminnummer;
	string kurs;
	string datum;
	string uhrzeit;
	int dauer;
public:
	Termin(string newKurs = "", string newDatum = "" , string newZeit = "", int newDauer = 0);
	void setDatum(string newDatum);
	void setUhrzeit(string newZeit);
	int getTerminnummer();
	void delTermin();
	~Termin();
};

int Termin::termininstanzen = 0;

Termin::Termin(string newKurs, string newDatum, string newZeit, int newDauer)
{
	termininstanzen = terminnummer++;
	kurs = newKurs;
	datum = newDatum;
	uhrzeit = newZeit;
	dauer = newDauer;
}

void Termin::setDatum(string newDatum){	datum = newDatum;}
void Termin::setUhrzeit(string newZeit){uhrzeit = newZeit;}

int Termin::getTerminnummer() { return terminnummer; }

void Termin::delTermin() { this->~Termin(); }

Termin::~Termin(){	cout << "Objekt von Termin geloescht!";}

//#############################################################################################################//
//#############################################################################################################//

class Kursbuchung
{
private:
	int kursnummer;
	int benutzerID;
	bool bezahlt;
public:
	Kursbuchung(int kursnummer = 0, int benutzerID = 0);
	bool getBezahlt();
};
Kursbuchung::Kursbuchung(int kursnummer, int benutzerID) {
kursnummer = kursnummer;
benutzerID = benutzerID;
bezahlt = false;
}

bool Kursbuchung::getBezahlt() { return bezahlt; }

//#############################################################################################################//
//#############################################################################################################//

class Benutzer
{
protected:
	static int benutzerinstanzen;
	int benutzerID;
	string email;
	string password;
	string vorname;
	string nachname;
	Adresse benutzeradresse;
public:
	Benutzer(string newvorname = "", string newnachname = "", string newemail = "", string newpassword = "", 
		string neueStrasse = "", string neueHausnummer = "", string neuePLZ = "", string neuerOrt = "");
	void setPasswort(string newPsw);
	void setEmail(string newEmail);
	void setVorname(string newVName);
	void setNachname(string newNName);
	string getVorname();
	string getNachname();
	int getBenutzerID();
	void ausgabeAdresse();
};

int Benutzer::benutzerinstanzen = 0;

Benutzer::Benutzer(string newvorname, string newnachname, string newemail, string newpassword, 
	string neueStrasse, string neueHausnummer, string neuePLZ, string neuerOrt)
{
	benutzerID = benutzerinstanzen++;
	vorname= newvorname;
	nachname = newnachname;
	email = newemail;
	password = newpassword;
	benutzeradresse.setStrasse(neueStrasse);
	benutzeradresse.setHausnummer(neueHausnummer);
	benutzeradresse.setPLZ(neuePLZ);
	benutzeradresse.setOrt(neuerOrt);
}

void Benutzer::setEmail(string newEmail) { email = newEmail; }
void Benutzer::setPasswort(string newPsw) { password = newPsw; }
void Benutzer::setVorname(string newVName) { vorname = newVName; }
void Benutzer::setNachname(string newNName) { nachname = newNName; }

string Benutzer::getNachname() { return nachname; }
string Benutzer::getVorname() { return vorname; }
int Benutzer::getBenutzerID() { return benutzerID; }

void Benutzer::ausgabeAdresse() {
	cout << "Adresse des Benutzers\n" << getVorname() << " " << getNachname()
		<< "\n" << benutzeradresse.getStrasse() << " " << benutzeradresse.getHausnummer()
		<< "\n" << benutzeradresse.getPLZ() << " " << benutzeradresse.getOrt() << endl;
}

//#############################################################################################################//
//#############################################################################################################//

class Teilnehmer :public Benutzer
{
private:
	string gebDatum;
	string telefonnummer;
	Bankverbindung bank;
	vector <Kursbuchung> kursbuchungen;
public:
	Teilnehmer(string newGDatum = "", string newTelefon = "", 
		string newvorname = "", string newnachname = "", string newemail = "", string newpassword = "",
		string neueStrasse = "", string neueHausnummer = "", string neuePLZ = "", string neuerOrt = "");
	void setGebDatum(string newGDatum);
	void setTelefon(string newTelefon);
	void setBank(string newBankname, string newIban, string newBic);
	void kursBuchen(int kursnummer);
};


Teilnehmer::Teilnehmer(string newGDatum, string newTelefon, string newvorname, string newnachname, string newemail, string newpassword,
	string neueStrasse, string neueHausnummer, string neuePLZ, string neuerOrt) {
	gebDatum = newGDatum;
	telefonnummer = newTelefon;
	vorname = newvorname;
	nachname = newnachname;
	email = newemail;
	password = newpassword;
	benutzeradresse.setStrasse(neueStrasse);
	benutzeradresse.setHausnummer(neueHausnummer);
	benutzeradresse.setPLZ(neuePLZ);
	benutzeradresse.setOrt(neuerOrt);
}

void Teilnehmer::setGebDatum(string newGDatum) { gebDatum = newGDatum; }
void Teilnehmer::setTelefon(string newTelefon) { telefonnummer = newTelefon; }
void Teilnehmer::setBank(string newBankname, string newIban, string newBic) {
	bank.setBankname(newBankname);
	bank.setIban(newIban);
	bank.setBic(newBic);}

void Teilnehmer::kursBuchen(int kursnummer) {
	kursbuchungen.push_back(Kursbuchung(kursnummer, this->getBenutzerID()));
}

//#############################################################################################################//
//#############################################################################################################//

class Dozent :public Benutzer
{
private:
	string beschreibung;
	string beruf;
	vector <string> kurse;
public:

	Dozent(string newBeschreibung = "", string newBeruf = "",
		string newvorname = "", string newnachname = "", string newemail = "", string newpassword = "",
		string neueStrasse = "", string neueHausnummer = "", string neuePLZ = "", string neuerOrt = "");
	void setBeschreibung(string newBeschreibung);
	void setBeruf(string newBeruf);
};

Dozent::Dozent(string newBeschreibung, string newBeruf, string newvorname, string newnachname, string newemail, string newpassword,
	string neueStrasse, string neueHausnummer, string neuePLZ, string neuerOrt) {
	beschreibung = newBeschreibung;
	beruf = newBeruf;
	vorname = newvorname;
	nachname = newnachname;
	email = newemail;
	password = newpassword;
	benutzeradresse.setStrasse(neueStrasse);
	benutzeradresse.setHausnummer(neueHausnummer);
	benutzeradresse.setPLZ(neuePLZ);
	benutzeradresse.setOrt(neuerOrt);
}

void Dozent::setBeschreibung(string newBeschreibung) { beschreibung = newBeschreibung; }
void Dozent::setBeruf(string newBeruf) { beruf = newBeruf; }

//#############################################################################################################//
//#############################################################################################################//

class Kurs
{
private:
	static int kursinstanzen;
	int kursnummer;
	string kursname;
	string kursBeschreibung;
	double kursgebuehr;
	int kursanzahl;
	string beginn;
	int maxAnzahl;
	vector<Termin> kurstermin;
	string kursleiter;
	Adresse* kursort;
public:
	Kurs();
	Kurs(Adresse* neukursort, Dozent &kursleiter, string newkursname = "", string newkursbeschreibung ="", double newkursgebuher = 0.0,
		int newanzahl = 0, string beginn = "", int newMaxanzahl = 0);
	int getKursnummer();
	string getKursname();
	string getKursbeschreibung();
	int getKursanzahl();
	string getKursbeginn();
	void setKursname(string newKName);
	void setKursgebuehr(double newKGebuehr);
	void addKurstermin(string newDatum = "", string newUhrzeit = "", int newDauer = 0);
	void delKurs();
	~Kurs();
};

int Kurs::kursinstanzen = 0;

Kurs::Kurs() {
	kursnummer = kursinstanzen++;
	kursname = "";
	kursBeschreibung = "";
	kursgebuehr = 0.0;
	kursanzahl = 0;
	beginn = "";
	maxAnzahl = 0;
	kursleiter = "";
}

Kurs::Kurs(Adresse* neukursort, Dozent &newkursleiter, string newkursname, string newkursbeschreibung, double newkursgebuher,
	int newanzahl, string newbeginn, int newMaxanzahl)
{
	kursnummer = kursinstanzen++;
	kursname = newkursname;
	kursBeschreibung = newkursbeschreibung;
	kursgebuehr = newkursgebuher;
	kursanzahl = newanzahl;
	beginn = newbeginn;
	maxAnzahl = newMaxanzahl;
	kursleiter = newkursleiter.getVorname() + " " + newkursleiter.getNachname();
	kursort = neukursort;

}

int Kurs::getKursnummer() { return kursnummer; }
string Kurs::getKursname() { return kursname; }
string Kurs::getKursbeschreibung() { return kursBeschreibung; }
int Kurs::getKursanzahl() { return kursanzahl; }
string Kurs::getKursbeginn() { return beginn; }

void Kurs::setKursgebuehr(double newKGebuehr) { kursgebuehr = newKGebuehr; }
void Kurs::setKursname(string newKName) { kursname = newKName; }

void Kurs::addKurstermin(string newDatum, string newUhrzeit, int newDauer){
	kurstermin.push_back(Termin(this->getKursname(), newDatum, newUhrzeit, newDauer));}

void Kurs::delKurs() { this->~Kurs(); }

Kurs::~Kurs()
{
	kurstermin.clear();
	cout << "Objekt von Kurs geloescht!";}


//#############################################################################################################//
//#############################################################################################################//

class Kategorie
{
private:
	string kategoriename;
	vector <Kurs> kursliste;

public:
	Kategorie(string newKatName = "");
	void addKurs(Kurs &newKurs);
	void delKurs(Kurs *oldKurs, string kursname);
	string getKategoriename();
	void delKategorie();
	~Kategorie();
};

Kategorie::Kategorie(string newKatName) {kategoriename = newKatName;}

void Kategorie::addKurs(Kurs &newKurs) { kursliste.push_back(newKurs); }

void Kategorie::delKurs(Kurs *oldKurs, string delkursname)
{
	for (int i = 0; i < int(kursliste.size()); i++)
	{
		if (kursliste[i].getKursname() == delkursname)
		{
			kursliste.erase(kursliste.begin() + (i - 1));
			oldKurs->delKurs();
		}
	}
}
string Kategorie::getKategoriename() { return kategoriename; }

void Kategorie::delKategorie() { this->~Kategorie(); }

Kategorie::~Kategorie(){	cout << "Objekt von Kategorie geloescht!";}

//#############################################################################################################//
//#############################################################################################################//
class Programm
{
private:
	string programmname;
	string programmbeginn;
	string programmende;
	vector <Kategorie> kategorien;
public:
	Programm(string newprogrammname = "", string newprogrammbegin = "", string newprogrammende = "");
	void addKate(Kategorie &neueKategorie);
	void delKate(Kategorie *alteKategorie, string kategoriename);
	void setProgrammname(string newPName) { programmname = newPName; }
};

Programm::Programm(string newprogrammname, string newprogrammbegin, string newprogrammende) {
	programmname = newprogrammname;
	programmbeginn = newprogrammbegin;
	programmende = newprogrammende;
}

void Programm::addKate(Kategorie &neueKategorie) { kategorien.push_back(neueKategorie);  }
void Programm::delKate(Kategorie *alteKategorie, string delkategoriename)
{
	for (int i = 0; i < int(kategorien.size()); i++)
	{
		if (kategorien[i].getKategoriename() == delkategoriename)
		{
			kategorien.erase(kategorien.begin()+(i-1));
			alteKategorie->delKategorie();
		}
	}
}

//#############################################################################################################//

#endif // !VHSKlassen
