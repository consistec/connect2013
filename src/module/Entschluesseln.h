/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Headerdatei der Klasse Entschluesseln
 *
 * @file		Entschluesseln.h
 *
 * @date		12.06.2013
 * @author	 	Moritz Fey
 *
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */

#ifndef ENTSCHLUESSELN_H_
#define ENTSCHLUESSELN_H_

using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "StringsUndTools.h"

/**
 * Klasse zum Entschluesseln von Text-Dateien.
 */
class Entschluesseln {
public:
	/**
	 * Konstruktor verlangt Eingabedatei und Ausgabedatei.
	 * @param inputFileName		Name der Eingabedatei
	 * @param outputFileName	Name der Ausgabedatei
	 */
	Entschluesseln(const char* inputFileName, const char* outputFileName);

	/**
	 * Destruktor schliesst Dateien, falls sie noch geoeffnet sein sollten.
	 */
	~Entschluesseln();

	/**
	 * Entschluesselt Text mit der Umkehrung des herausgefunden Algorithmus.
	 * Zuerst wird eine Pruefung vorgenommen, ob das oeffnen der Datei funktioniert hat.
	 * Falls nicht wird eine Fehlermeldung ausgegeben und das Programm beendet.
	 * Danach durchlaeuft die Funktion den Text zeilenweise und ruft mit der aktuellen
	 * Zeile als Parameter die Funktion entschluesseleZeile() auf.
	 *
	 */
	void entschluesseleDatei();

	/**
	 * Entschluesselt die aktuelle Zeile und schreibt sie dann zeichenweise in die Ausgabedatei.
	 * Zum Entschluesseln wird der String zeichenweise durchlaufen und fuer jedes Zeichen
	 * die Funktion entschluesseleZeichen() mit dem aktuellen Zeichen als Parameter aufgerufen.
	 * Danach wird das entschluesselte Zeichen in die Ausgabedatei geschrieben.
	 * Am Ende der Funktion wird noch ein Linefeed in die Datei geschrieben, damit
	 * die Ausgabedatei die gleiche Struktur wie die Eingabedatei hat.
	 * @param zeile	aktuelle Zeile
	 */
	void entschluesseleZeile(string zeile);

	/**
	 * Zum Entschluesseln eines Zeichen muss zuerst determiniert werden, ob es sich
	 * um einen Kleinbuchstaben oder eine Grossbuchstaben handelt. Je nach Buchstabentyp
	 * wird entweder entschluesseleKleinBuchstaben() oder entschluesseleGrossBuchstaben()
	 * mit dem aktuellen Zeichen als Argument aufgerufen.
	 * @param zeichen	verschluesseltes Zeichen
	 * @return zeichen	unverschluesseltes Zeichen
	 */
	char entschluesseleZeichen(char zeichen);

	/**
	 * Entschluesselt den uebergebenen Kleinbuchstaben.
	 * Zuerst muss gemaess des Algorithmus festgestellt werden, ob der gegebene Buchstabe
	 * in der ersten Haelfte des Alphabets liegt oder in der zweiten.
	 * In der ersten Haelfte werden die Buchstaben um 2 Positionen zurueck
	 * im Alphabet verschoben (dabei werden a und b wieder hinten angereiht).
	 * In der zweiten Haelfte des Alphabets werden die Buchstaben um 2 Positionen nach vorne
	 * verschoben (dabei werden y und z wieder vorne angereiht).
	 * @param zeichen	verschluesseltes Zeichen
	 * @return zeichen	unverschluesseltes Zeichen
	 */
	char entschluesseleKleinBuchstaben(char zeichen);

	/**
	 * Entschluesselt den uebergebenen Grossbuchstaben.
	 * Zuerst muss gemaess des Algorithmus festgestellt werden, ob der gegebene Buchstabe
	 * in der ersten Haelfte des Alphabets liegt oder in der zweiten.
	 * In der ersten Haelfte werden die Buchstaben um 1 Position nach vorne
	 * im Alphabet verschoben (dabei wird M wieder vorne angereiht).
	 * In der zweiten Haelfte des Alphabets werden die Buchstaben um 1 Position zurueck
	 * verschoben (dabei wird N wieder hinten angereiht).
	 * @param zeichen	verschluesseltes Zeichen
	 * @return zeichen	unverschluesseltes Zeichen
	 */
	char entschluesseleGrossBuchstaben(char zeichen);

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

#endif /* ENTSCHLUESSELN_H_ */
