# Makefile fuer Crypto-Programm
# Mit diesem Makefile wird ein Test-Programm fuer den encoder uebersetzt.
# Das Crypto-Programm ist ein Zusatz zu dem vom Wettbewerb geforderten Programm.
# Autor: Moritz Fey 
# erstellt am: 15.06.2013


PROGRAM_ENCODER=encoder
PROGRAM_DECODER=decoder
PROGRAM_ENCODER_DECODER=encoderDecoder
PROGRAM_ENCODER_TEST=encoderTest

ENCODER_OBJECTS=encoderStarter.o module/Verschluesseln.o module/StringsUndTools.o
DECODER_OBJECTS=decoderStarter.o module/Entschluesseln.o module/StringsUndTools.o
ENCODER_DECODER_OBJECTS=encoderDecoderStarter.o module/Verschluesseln.o module/Entschluesseln.o module/StringsUndTools.o
ENCODER_TEST_OBJECTS=encoderTestStarter.o module/Verschluesseln.o module/Entschluesseln.o module/StringsUndTools.o

GXX=g++
CFLAGS=-Wall -g -pedantic
.PHONY: all


all: ${PROGRAM_ENCODER} ${PROGRAM_DECODER} ${PROGRAM_ENCODER_DECODER} ${PROGRAM_ENCODER_TEST}

${PROGRAM_ENCODER}: ${ENCODER_OBJECTS}
	@echo''
	@echo '------->Baue Programm ${PROGRAM_ENCODER}'
	${GXX} ${ENCODER_OBJECTS} -o ${PROGRAM_ENCODER}

${PROGRAM_DECODER}: ${DECODER_OBJECTS}
	@echo''
	@echo '------->Baue Programm ${PROGRAM_DECODER}'
	${GXX} ${DECODER_OBJECTS} -o ${PROGRAM_DECODER}
	
${PROGRAM_ENCODER_DECODER}: ${ENCODER_DECODER_OBJECTS}
	@echo''
	@echo '------->Baue Programm ${PROGRAM_ENCODER_DECODER}'
	${GXX} ${ENCODER_DECODER_OBJECTS} -o ${PROGRAM_ENCODER_DECODER}

${PROGRAM_ENCODER_TEST}: ${ENCODER_TEST_OBJECTS}
	@echo''
	@echo '------->Baue Programm ${PROGRAM_ENCODER_TEST}'
	${GXX} ${ENCODER_TEST_OBJECTS} -o ${PROGRAM_ENCODER_TEST}
	
%.o: %.cpp
	@echo''
	@echo '------>Baue Modul $@'
	${GXX} -c ${CFLAGS} $< -o $@

.PHONY: clean

clean:
	@echo''
	@echo '------>Loesche die Module und die Binarys'
	rm -f *.o module/*.o mainProgramme/*.o
	rm -f encoder decoder encoderDecoder encoderTest
	rm -f encoder.exe decoder.exe encoderDecoder.exe encoderTest.exe
	rm -f *.stackdump
