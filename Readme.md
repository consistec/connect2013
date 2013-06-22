##HTW Connect Programmierwettbewerb##

###Uebersetzen des Programms###

Um das Programm zu Uebersetzen muss [Maven][] auf dem System installiert sein.

1. Zum Quellcode navigieren:

		cd /path/to/src/folder

2. Das Projekt "bauen"
	
		mvn clean package

Maven laedt nun die benoetigten Bibliotheken herunter und generiert eine JAR-Datei mit dem Namen **encoder.jar** im Verzeichnis **target**.

###Ausfuehren des Programms###

Das Programm kann nach dem kompilieren wie folgt ausgefuehrt werden:

	java -jar encoder.jar inputFile.txt outputFile.txt

###Hinweise###

* Die Unit-Tests koennen wie folgt gestartet werden:  

		cd /path/to/src/folder
		mvn test

* Als Eingabedatei koennen (mit Absicht) nur Dateien im ASCII-Format genutzt werden, da nur fuer diese eine Codierung vorgegeben wurde. 

###Kontakt###

Name: André Schommer  
EMail: [andre.schommer@googlemail.com](mailto:andre.schommer@googlemail.com)

 [Maven]: <http://maven.apache.org/download.cgi> "Maven Download Page"