# Makefile 
# Autor: Carsten Gross
# erstellt am: 20.06.2013

PROGRAM=encoder.out
OBJECTS=encoder.o
DEPENDFILE=.depend
GXX=g++
CFLAGS=-Wall -g -pedantic #-std=c++11 
.PHONY: all
all: dep ${PROGRAM}

${PROGRAM}: ${OBJECTS}
	@echo '------->Baue Programm'
	${GXX} ${OBJECTS} -o ${PROGRAM}
	@echo 
	
%.o: %.cpp
	@echo '------>Baue Modul $@'
	${GXX} -c ${CFLAGS} $< -o $@
	@echo

.PHONY: clean

clean:
	@echo '------>Loesche die Module und das Programm'
	rm -f *.o
	rm -f *.out
	rm -f *.exe
	rm -f *.stackdump

.PHONY: dep

dep: *.cpp
	@echo '------>Finde Abhaengigkeiten'
	${GXX} -MM *.cpp > ${DEPENDFILE}
	@echo 
	
-include ${DEPENDFILE}
