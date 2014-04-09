/** Projektname: Consistec_Wettbewerb_connect(at)htw2013
 *
 * Beschreibung: Implementierung der Klasse Verschluesseln
 *
 * @file		Verschluesseln.cpp
 *
 * @date		12.06.2013
 * @author		Moritz Fey
 * 
 * Uebersetzung per Makefile: 	make all	/ make clean (zum loeschen)
 */

#include "Verschluesseln.h"

using namespace std;

Verschluesseln::Verschluesseln(const char* inputFileName, const char* outputFileName) {
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

Verschluesseln::~Verschluesseln() {
	if (inputFile.is_open()) {
		inputFile.close();
	}

	if (outputFile.is_open()) {
		outputFile.close();
	}
}

void Verschluesseln::verschluesseleDatei() {
	string zeile;

	if (inputFile.is_open())
	{
		while (inputFile.good())
		{
			getline (inputFile,zeile);
			verschluesseleZeile(zeile);
		}
		inputFile.close();
		outputFile.close();
	}
}

void Verschluesseln::verschluesseleZeile(string zeile) {
	char enCryptChar = '\0';
	if (outputFile.is_open()) {
		for (long i = 0; i < static_cast<long>(zeile.length()); i++) {
			enCryptChar = verschluesseleZeichen(zeile[i]);
			outputFile.put(enCryptChar);
		}
	}
	outputFile.put('\n');
}

char Verschluesseln::verschluesseleZeichen(char zeichen) {
	if (zeichen >= 'a' && zeichen <= 'z') {
		zeichen = verschluesseleKleinBuchstaben(zeichen);
	}
	if (zeichen >= 'A' && zeichen <= 'Z') {
		zeichen = verschluesseleGrossBuchstaben(zeichen);
	}

	return zeichen;
}

char Verschluesseln::verschluesseleKleinBuchstaben(char zeichen) {
	if (zeichen >= 'a' && zeichen <= 'm') {
		if (zeichen >= 'l') {
			zeichen -= 11;
		}
		else {
			zeichen += 2;
		}
	}
	else if (zeichen >= 'n' && zeichen <= 'z') {
		if (zeichen <= 'o') {
			zeichen += 11;
		}
		else {
			zeichen -= 2;
		}
	}
	return zeichen;
}

char Verschluesseln::verschluesseleGrossBuchstaben(char zeichen) {
	if (zeichen >= 'A' && zeichen <= 'M') {
		if (zeichen == 'A') {
			zeichen += 12;
		}
		else {
			zeichen -= 1;
		}
	}
	else if (zeichen >= 'N' && zeichen <= 'Z') {
		if (zeichen == 'Z') {
			zeichen -= 12;
		}
		else {
			zeichen += 1;
		}

	}
	return zeichen;
}
