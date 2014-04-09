/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Hauptprogramm fuer den encoder
 *
 * @file		encoderStarter.cpp
 *
 * @date		13.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make encoder		 (nur dieses Programm uebersetzen)
 * 								make all 			 (alle Programme uebersetzen)
 * 								make clean 			 (zum loeschen)
 */

using namespace std;

#include "module/Verschluesseln.h"
#include "module/StringsUndTools.h"

/**
 * Hauptprogramm fuer den encoder.
 */
int main (int argc,char **argv) {
	try {
		if (argc == 3) {
			Verschluesseln zuVerschluesseln(argv[1], argv[2]);
			zuVerschluesseln.verschluesseleDatei();
		}
		else {
			throw logic_error(StringsUndTools::HELP_MENU_ENCODER);
		}
	} catch (const exception &e) {
		cout << e.what() << endl;
	}
}







