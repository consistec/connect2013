#Uebersetzen der Programme
Zum uebersetzen der Programm muss zuerst in den Ordner src gewechselt werden mit
```
cd src
```

##Uebersetzen des encoder Programms:
```
make encoder
```
Syntax des Programms:
```
encoder [EINGABEDATEI] [AUSGABEDATEI]
```

##Uebersetzen des Testprogramms:
```
make encoderTest
```
Syntax des Programms:
```
encoderTest [EINGABEDATEI] [AUSGABEDATEI]
```

##Uebersetzen des decoder Programms:
```
make decoder
```
Syntax des Programms:
```
decoder [EINGABEDATEI] [AUSGABEDATEI]
```

##Uebersetzen des kombinierten encoder_decoder Programms:
```
make encoder_decoder
```
Syntax des Programms:
```
encoder_decoder [EINGABEDATEI] [AUSGABEDATEI]
```

##Uebersetzen aller Programme:
```
make all
```

##Loeschen der Objektdateien
```
make clean
```

##Tests
Um die encoder Klasse zu testen muss zuerst das Testprogramm mit make encoderTest
uebersetzt werden. Danach kann mit
```
encoderTest [EINGABEDATEI] [AUSGABEDATEI] [REFERENZDATEI] 
```
geprueft werden, ob das codieren funktioniert hat.
Die Referenzdatei muss die passend zur Eingabedatei bereits verschluesselte Datei 
sein, die dann mit der Ausgabedatei vergleichen wird. Das Programm gibt dann als Ausgabe,
wenn die Dateien gleich sind, dass die Verschluesselung erfolgreich war und bei Unterschieden,
dass die Verschluesselung nicht erfolgreich war.


Konatkt:
Moritz Fey
e-Mail: moritz.fey@gmail.com

