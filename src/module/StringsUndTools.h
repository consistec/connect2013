/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Headerdatei der Klasse StringsUndTools
 *
 * @file		StringsUndTools.h
 *
 * @date		12.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */

#ifndef STRINGSUNDTOOLS_H_
#define STRINGSUNDTOOLS_H_

using namespace std;

#include <fstream>
#include <iostream>
#include <sstream>

/**
 * Klasse mit Strings und global benoetigten Funktionen.
 */
class StringsUndTools {
public:
	/// HelpMenu-String fuer Encoder
	static const char* HELP_MENU_ENCODER;
	/// HelpMenu-String fuer EncoderTest
	static const char* HELP_MENU_ENCODER_TEST;
	/// HelpMenu-String fuer Decoder
	static const char* HELP_MENU_DECODER;
	/// String fuer Exception, dass keine Datei vorhanden ist
	static const char* MSG_KEINE_DATEI_GEFUNDEN;
	/// String fuer Exception, dass Datei leer ist
	static const char* MSG_DATEI_LEER;
	/// langer String fuer Kommandozeilen Parameter bei Entschluesseln
	static const char* PARAM_ENTSCHLUESSELN;
	/// kurzer String fuer Kommandozeilen Parameter bei Entschluesseln
	static const char* PARAM_ENTSCHLUESSELN_S;
	/// langer String fuer Kommandozeilen Parameter bei Verschluesseln
	static const char* PARAM_VERSCHLUESSELN;
	/// kurzer String fuer Kommandozeilen Parameter bei Verschluesseln
	static const char* PARAM_VERSCHLUESSELN_S;
	/// langer String fuer Kommandozeilen Parameter bei Help
	static const char* PARAM_HELP;
	/// kurzer String fuer Kommandozeilen Parameter bei Help
	static const char* PARAM_HELP_S;
	/// String fuer eine erfolgreiche Verschluesselung in encoderTest
	static const char* MSG_VERSCHLUESSELUNG_TRUE;
	/// String fuer eine nicht erfolgreiche Verschluesselung in encoderTest
	static const char* MSG_VERSCHLUESSELUNG_FALSE;

	/**
	 * Funktion die prueft, ob eine Datei leer ist.
	 * @param datei
	 * @return	Datei leer oder nicht
	 */
	static bool istLeer(ifstream& datei);

	/**
	 * Funktion prueft, ob zwei Dateien den gleichen inhalt haben.
	 * @param lhs	Erste Datei des Vergleichs
	 * @param rhs	Zweite Datei des Vergleichs
	 * @return	Status der Gleichheit
	 */
	static bool dateienGleich(const char* lhs, const char* rhs);

	/**
	 * Baut einen String Stream der die Hilfe fuer das Programm encoderDecoder beinhaltet.
	 * @return o.str() String-Stream der Hilfe
	 */
	static string helpMenuEncoderDecoder();
};

#endif /* STRINGSUNDTOOLS_H_ */
