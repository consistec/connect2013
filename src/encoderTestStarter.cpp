/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Kleines Test-Programm zum Testen der Verschluesselung
 *
 * @file		encoderTestStarter.cpp
 *
 * @date		15.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make encoderTest	 (nur dieses Programm uebersetzen)
 * 								make all 			 (alle Programme uebersetzen)
 * 								make clean 			 (zum loeschen)
 */
using namespace std;

#include "module/StringsUndTools.h"
#include "module/Verschluesseln.h"

/**
 * Hauptprogramm fuer den encoderTest.
 */
int main (int argc, char **argv) {
	try {
		if (argc == 4) {
			Verschluesseln zuVerschluesseln(argv[1], argv[2]);
			zuVerschluesseln.verschluesseleDatei();

			if (StringsUndTools::dateienGleich(argv[2], argv[3])) {
				cout << StringsUndTools::MSG_VERSCHLUESSELUNG_TRUE <<endl;
			}
			else{
				cout << StringsUndTools::MSG_VERSCHLUESSELUNG_FALSE <<endl;
			}
		}
		else {
			throw logic_error(StringsUndTools::HELP_MENU_ENCODER_TEST);
		}
	} catch (const exception &e) {
		cout << e.what() << endl;
	}
}




