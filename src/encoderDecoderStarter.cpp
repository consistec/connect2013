/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: 
 *
 * @file		encoderDecoderStarter.cpp
 *
 * @date		12.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make encoder_decoder (nur dieses Programm uebersetzen)
 * 								make all 			 (alle Programme uebersetzen)
 * 								make clean 			 (zum loeschen)
 */

using namespace std;

#include "module/StringsUndTools.h"
#include "module/Verschluesseln.h"
#include "module/Entschluesseln.h"

/**
 * Hauptprogramm fuer den encoderDecoder.
 */
int main (int argc,char **argv) {
	try {
		if (argc == 2) {
			string MENU_PUNKT(argv[1]);
			if ((MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_HELP))
					|| (MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_HELP_S))) {
				cout << StringsUndTools::helpMenuEncoderDecoder();
			}
		}

		else if (argc == 4) {
			string MENU_PUNKT(argv[1]);
			if ((MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_ENTSCHLUESSELN_S))
					|| (MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_ENTSCHLUESSELN))) {
				Entschluesseln zuEntschluesseln(argv[2], argv[3]);
				zuEntschluesseln.entschluesseleDatei();
			}
			else if ((MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_VERSCHLUESSELN_S))
					|| (MENU_PUNKT == static_cast<string>(StringsUndTools::PARAM_VERSCHLUESSELN))) {
				Verschluesseln zuVerschluesseln(argv[2], argv[3]);
				zuVerschluesseln.verschluesseleDatei();
			}
		}
		else {
			throw logic_error(StringsUndTools::helpMenuEncoderDecoder());
		}
	} catch (const exception &e) {
		cout << e.what() << endl;
	}
}
