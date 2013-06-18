/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Implementierung der Klasse Entschluesseln
 *
 * @file		Entschluesseln.cpp
 *
 * @date		12.06.2013
 * @author	 	Moritz Fey
 *
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */
#include "Entschluesseln.h"

using namespace std;

Entschluesseln::Entschluesseln(const char* inputFileName, const char* outputFileName) {
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
	this->inputFile.open(inputFileName);
	if (!inputFile) {
		throw logic_error(static_cast<string>(StringsUndTools::MSG_KEINE_DATEI_GEFUNDEN) + inputFileName);
	}
	if (StringsUndTools::istLeer(inputFile)) {
		throw logic_error(static_cast<string>(StringsUndTools::MSG_DATEI_LEER) + inputFileName);
	}
	this->outputFile.open(outputFileName);
}

Entschluesseln::~Entschluesseln() {
	if (inputFile.is_open()) {
		inputFile.close();
	}

	if (outputFile.is_open()) {
		outputFile.close();
	}
}

void Entschluesseln::entschluesseleDatei() {
	string zeile;

	if (inputFile.is_open())
	{
		while ( inputFile.good() )
		{
			getline (inputFile,zeile);
			entschluesseleZeile(zeile);
		}
		inputFile.close();
		outputFile.close();
	}
}

void Entschluesseln::entschluesseleZeile(string zeile) {
	char deCryptChar = '\0';
	if (outputFile.is_open()) {
		for (long i = 0; i < static_cast<long>(zeile.length()); i++) {
			deCryptChar = entschluesseleZeichen(zeile[i]);
			outputFile.put(deCryptChar);
		}
	}
	outputFile.put('\n');
}

char Entschluesseln::entschluesseleZeichen(char zeichen) {
	if (zeichen >= 'a' && zeichen <= 'z') {
		zeichen = entschluesseleKleinBuchstaben(zeichen);
	}
	if (zeichen >= 'A' && zeichen <= 'Z') {
		zeichen = entschluesseleGrossBuchstaben(zeichen);
	}

	return zeichen;
}

char Entschluesseln::entschluesseleKleinBuchstaben(char zeichen) {
	if (zeichen >= 'a' && zeichen <= 'm') {
		if (zeichen <= 'b') {
			zeichen += 11;
		}
		else {
			zeichen -= 2;
		}
	}
	else if (zeichen >= 'n' && zeichen <= 'z') {
		if (zeichen >= 'y') {
			zeichen -= 11;
		}
		else{
			zeichen += 2;
		}
	}
	return zeichen;
}

char Entschluesseln::entschluesseleGrossBuchstaben(char zeichen) {
	if (zeichen >= 'A' && zeichen <= 'M') {
		if (zeichen == 'M') {
			zeichen -= 12;
		}
		else {
			zeichen += 1;
		}
	}
	else if (zeichen >= 'N' && zeichen <= 'Z') {
		if (zeichen == 'N') {
			zeichen += 12;
		}
		else {
			zeichen -= 1;
		}
	}
	return zeichen;
}
