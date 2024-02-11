/*
##########################################################################
--------------------------------------------------------------------------
	Datum:			09.04.23
	Name :			D.Henning
	Modul:			PRG24 - Programmierparadigmen
	Thema:			Laborbericht zu Klassen und Operationen
	Beschreibung:	Umsetzung Klassendiagramm der VHS-Aichach-Friedberg
	Datei:			main.cpp
--------------------------------------------------------------------------
##########################################################################
*/

#include "VHSKlassen.h"

int main(void) {

	Teilnehmer MaxMustermann("01.01.2000", "123456", "Max", "Mustermann", "Max@Mustermann.de", "123456", "Mustermannstrasse", "4a", "01067", "Dresden");
	//Objekt von Bankverbindung wird gleichzeitig "leer" initialisiert. Deswegen eine zusätzliche Methode zum befüllen.
	MaxMustermann.setBank("Volksbank", "DE12 3456 7890 1234", "ABCDEF");
	//Objekt von Kursbuchung wird bei Buchung unter Angabe der Kursnummer erstellt.
	MaxMustermann.kursBuchen(1);
	
	Dozent ErikaMustermann("Yoga zum Entspannen von Zuhause", "Yoga-Lehrerin", "Erika", "Mustermann", "Erika@Mustermann.de", "654321", "Mustermannstrasse", "20", "01067", "Dresden");

	Adresse Turnhalle("Schulweg", "1", "80353", "Muenchen");

	Kurs Yoga1(&Turnhalle, ErikaMustermann, "Yoga - Fit mit Yoga", "Yoga fur jedes Alter", 24.50, 30, "01.01.2024", 30);
	Yoga1.addKurstermin("01.05.2023", "12:00", 60);

	Programm Herbst2023("Herbst 2023", "01.09.23", "30.12.23");

	Kategorie Gesundheit("Gesundheit & Bewegung");


}

