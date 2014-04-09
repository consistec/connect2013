/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Hauptprogramm fuer den decoder
 *
 * @file		decoderStarter.cpp
 *
 * @date		13.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make decoder 		 (nur dieses Programm uebersetzen)
 * 								make all 			 (alle Programme uebersetzen)
 * 								make clean 			 (zum loeschen)
 */

using namespace std;

#include "module/Entschluesseln.h"
#include "module/StringsUndTools.h"

/**
 * Hauptprogramm fuer den decoder.
 */
int main (int argc,char **argv) {
	try {
		if (argc == 3) {
			Entschluesseln zuEntschluesseln(argv[1], argv[2]);
			zuEntschluesseln.entschluesseleDatei();
		}
		else {
			throw logic_error(StringsUndTools::HELP_MENU_DECODER);
		}
	} catch (const exception &e) {
		cout << e.what() << endl;
	}
}







