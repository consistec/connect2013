/** Projektname:	connect2013
 *
 * Beschreibung:	Encoder - kodiert den Text einer Input-Datei in eine Output-Datei
 *
 * @file		encoder.cpp
 *
 * @date		12.06.2013
 * @author		Carsten Gross / Moritz Fey
 * Matrikelnr.	3602001 	 / 3602087
 *
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */
/* Namespace definieren*/
using namespace std;

#include <string>
#include <iostream>
#include <fstream>

int main(int argc,char *argv []) {
	ifstream infile;
	ofstream outfile;
	string eingabe;
	string ausgabe;

	if (argc == 3) {
		eingabe = argv[1];
		ausgabe = argv[2];

		infile.open(eingabe.c_str());
		if (!infile) {
			cout << eingabe << " kann nicht geoeffnet werden\n";
			return 1;
		}

		outfile.open(ausgabe.c_str());
		if (!outfile) {
			cout << ausgabe << " kann nicht geoeffnet werden.\n";
			return 1;
		}

		char c1;
		char c2;

		while (infile.get(c1) ) {
			if (c1 >= 'a' && c1<= 'k'){
				c2 = c1 + 2;
			}else if (c1 >= 'l' && c1<= 'm'){
				c2 = c1 - 11;
			}else if (c1 >= 'n' && c1<= 'o'){
				c2 = c1 + 11;
			}else if (c1 >= 'p' && c1<= 'z'){
				c2 = c1 - 2;
			}else if (c1 == 'A'){
				c2 = c1 + 12;
			}else if (c1 >= 'B' && c1<= 'Y'){
				c2 = c1 - 1;
			}else if ( c1 == 'Z'){
				c2 = c1 - 12;
			}else{
				c2 = c1;
			}
			outfile.put(c2);
		}
		infile.close();
		outfile.close();
		cout << endl << "Programmende" << endl;
	}
	else {
		cout << " Fehler bei einlesen, bitte nocheinmal !";
	}
}
