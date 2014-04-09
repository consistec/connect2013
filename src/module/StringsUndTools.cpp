/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Implementierung der Klasse StringsUndTools
 *
 * @file		StringsUndTools.cpp
 *
 * @date		12.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */

using namespace std;

#include "StringsUndTools.h"

const char* StringsUndTools::HELP_MENU_ENCODER = "Aufruf: encoder [EINGABEDATEI] [AUSGABEDATEI]\n";

const char* StringsUndTools::HELP_MENU_DECODER = "Aufruf: decoder [EINGABEDATEI] [AUSGABEDATEI]\n";

const char* StringsUndTools::HELP_MENU_ENCODER_TEST = "Aufruf: encoderTest [EINGABEDATEI] [AUSGABEDATEI] [VERGLEICHSDATEI]\n";

const char* StringsUndTools::MSG_KEINE_DATEI_GEFUNDEN = "\nKonnte Datei nicht finden oder oeffnen: ";
const char* StringsUndTools::MSG_DATEI_LEER = "\nDie Eingabedatei ist leer: ";

const char* StringsUndTools::PARAM_ENTSCHLUESSELN = "--entschluessen";
const char* StringsUndTools::PARAM_ENTSCHLUESSELN_S = "-e";
const char* StringsUndTools::PARAM_VERSCHLUESSELN = "--verschluessen";
const char* StringsUndTools::PARAM_VERSCHLUESSELN_S = "-v";
const char* StringsUndTools::PARAM_HELP = "--help";
const char* StringsUndTools::PARAM_HELP_S = "-h";

const char* StringsUndTools::MSG_VERSCHLUESSELUNG_TRUE = "\nDas neu verschluesselte File entspricht der Referenzdatei, Verschluesselung erfolgreich\n";
const char* StringsUndTools::MSG_VERSCHLUESSELUNG_FALSE = "\nDas neu verschluesselte File entspricht nicht der Referenzdatei, Verschluesselung nicht erfolgreich\n";

bool StringsUndTools::istLeer(ifstream& datei) {
	return datei.peek() == ifstream::traits_type::eof();

}

bool StringsUndTools::dateienGleich(const char* lhs, const char* rhs) {
	fstream lhsFile(lhs);
	fstream rhsFile(rhs);
	while (lhsFile.good() && rhsFile.good()) {
		if (lhsFile.get() != rhsFile.get()) {
			return false;
		}
	}
	return true;
}

string StringsUndTools::helpMenuEncoderDecoder() {
	ostringstream o;
	o << "\nAufruf: encoderDecoder [OPTION] [EINGABEDATEI] [AUSGABEDATEI]\n"
	  << "Optionen: \n"
	  << "  -v, --verschluesseln        Verschluesseln der Eingabedatei\n"
	  << "  -e, --entschluesseln        Entschluesseln der Eingabedatei\n"
	  << "  -h, --help                  Dieses Hilfemenu" << endl;
	return o.str();
}
