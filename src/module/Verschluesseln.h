/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Headerdatei der Klasse Verschluesseln
 *
 * @file		Verschluesseln.h
 *
 * @date		12.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */

#ifndef VERSCHLUESSELN_H_
#define VERSCHLUESSELN_H_

using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "StringsUndTools.h"

/**
 * Klasse zum Verschluesseln von Text-Dateien.
 */
class Verschluesseln {
public:
	/**
	 * Konstruktor verlangt Eingabedatei und Ausgabedatei.
	 * @param inputFileName		Name der Eingabedatei
	 * @param outputFileName	Name der Ausgabedatei
	 */
	Verschluesseln(const char* inputFileName, const char* outputFileName);

	/**
	 * Destruktor schliesst Dateien, falls sie noch geoeffnet sein sollten.
	 */
	~Verschluesseln();

	/**
	 * Verschluesselt Text mit dem herausgefunden Algorithmus.
	 * Zuerst wird eine Pruefung vorgenommen, ob das oeffnen der Datei funktioniert hat.
	 * Falls nicht wird eine Fehlermeldung ausgegeben und das Programm beendet.
	 * Danach durchlaeuft die Funktion den Text zeilenweise und ruft mit der aktuellen
	 * Zeile als Parameter die Funktion verschluesseleZeile() auf.
	 *
	 */
	void verschluesseleDatei();

	/**
	 * Verschluesselt die aktuelle Zeile und schreibt sie dann zeichenweise in die Ausgabedatei.
	 * Zum Verschluesseln wird der String zeichenweise durchlaufen und fuer jedes Zeichen
	 * die Funktion verschluesseleZeichen() mit dem aktuellen Zeichen als Parameter aufgerufen.
	 * Danach wird das verschluesselte Zeichen in die Ausgabedatei geschrieben.
	 * Am Ende der Funktion wird noch ein Linefeed in die Datei geschrieben, damit
	 * die Ausgabedatei die gleiche Struktur wie die Eingabedatei hat.
	 * @param zeile	aktuelle Zeile
	 */
	void verschluesseleZeile(string zeile);

	/**
	 * Zum Verschluesseln eines Zeichen muss zuerst determiniert werden, ob es sich
	 * um einen Kleinbuchstaben oder eine Grossbuchstaben handelt. Je nach Buchstabentyp
	 * wird entweder verschluesseleKleinBuchstaben() oder verschluesseleGrossBuchstaben()
	 * mit dem aktuellen Zeichen als Argument aufgerufen.
	 * @param zeichen	unverschluesseltes Zeichen
	 * @return zeichen	verschluesseltes Zeichen
	 */
	char verschluesseleZeichen(char zeichen);

	/**
	 * Verschluesselt den uebergebenen Kleinbuchstaben.
	 * Zuerst muss gemaess des Algorithmus festgestellt werden, ob der gegebene Buchstabe
	 * in der ersten Haelfte des Alphabets liegt oder in der zweiten.
	 * In der ersten Haelfte werden die Buchstaben um 2 Positionen nach vorne
	 * im Alphabet verschoben (dabei werden l und m wieder vorne angereiht).
	 * In der zweiten Haelfte des Alphabets werden die Buchstaben um 2 Positionen zurueck
	 * verschoben (dabei werden n und o wieder hinten angereiht).
	 * @param zeichen	unverschluesseltes Zeichen
	 * @return zeichen	verschluesseltes Zeichen
	 */
	char verschluesseleKleinBuchstaben(char zeichen);

	/**
	 * Verschluesselt den uebergebenen Grossbuchstaben.
	 * Zuerst muss gemaess des Algorithmus festgestellt werden, ob der gegebene Buchstabe
	 * in der ersten Haelfte des Alphabets liegt oder in der zweiten.
	 * In der ersten Haelfte werden die Buchstaben um 1 Position zurueck
	 * im Alphabet verschoben (dabei wird A wieder hinten angereiht).
	 * In der zweiten Haelfte des Alphabets werden die Buchstaben um 1 Position nach vorne
	 * verschoben (dabei wird Z wieder vorne angereiht).
	 * @param zeichen	unverschluesseltes Zeichen
	 * @return zeichen	verschluesseltes Zeichen
	 */
	char verschluesseleGrossBuchstaben(char zeichen);

private:
	/// Name der Eingabedatei
	string inputFileName;
	/// Name der Ausgabedatei
	string outputFileName;
	/// Filestream der Eingabedatei
	ifstream inputFile;
	/// Filestream der Ausgabedatei
	ofstream outputFile;
};

#endif /* VERSCHLUESSELN_H_ */
