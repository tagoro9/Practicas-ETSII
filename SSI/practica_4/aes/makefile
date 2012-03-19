# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/bitset/bitset.h lib/keys/keys.h lib/functions/aesfunctions.h lib/bitsetmatrix/bitsetmatrix.h lib/aes/aes.h lib/gui/aesgui.h
OBJS = bin/main.o bin/bitset.o bin/aesfunctions.o bin/keys.o bin/bitsetmatrix.o bin/aes.o bin/aesgui.o
EXEC = bin/main
# Compilador y opciones
CC     = g++
CFLAGS = -c `pkg-config gtkmm-2.4 --cflags --libs`
CDEBUG = -g
LIBS = -lboost_regex-mt -I/opt/local/include/ -L/opt/local/lib/ `pkg-config gtkmm-2.4 --cflags --libs`
# Reglas
all: $(EXEC)
cli: bin/cli
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
#Cli
bin/cli: bin/cli.o bin/bitset.o bin/bitsetmatrix.o bin/keys.o bin/aesfunctions.o bin/aes.o
	g++ -o bin/cli bin/cli.o bin/bitset.o bin/bitsetmatrix.o bin/keys.o bin/aesfunctions.o bin/aes.o -lboost_regex-mt -I/opt/local/include/ -L/opt/local/lib/
bin/cli.o: main_cli.cc bin/bitset.o bin/aesfunctions.o bin/keys.o bin/bitsetmatrix.o bin/aes.o
	g++ -o bin/cli.o -c -g main_cli.cc
#Principal
bin/main.o: $(MAIN) $(INCS)
	$(CC) -o bin/main.o $(CFLAGS) $(CDEBUG) $(MAIN)	
#Clase aes
bin/aes.o: lib/aes/aes.cc lib/aes/aes.h
	$(CC) -o bin/aes.o $(CFLAGS) $(CDEBUG) lib/aes/aes.cc
#AesFunctions
bin/aesfunctions.o: lib/functions/aesfunctions.cc lib/functions/aesfunctions.h
	$(CC) -o bin/aesfunctions.o $(CFLAGS) $(CDEBUG) lib/functions/aesfunctions.cc
#Clase bitset
bin/bitset.o: lib/bitset/bitset.cc lib/bitset/bitset.h
	$(CC) -o bin/bitset.o $(CFLAGS) $(CDEBUG) lib/bitset/bitset.cc
#Clase keys
bin/keys.o: lib/keys/keys.cc lib/keys/keys.h
	$(CC) -o bin/keys.o $(CFLAGS) $(CDEBUG) lib/keys/keys.cc
#Clase bitsetmatrix
bin/bitsetmatrix.o: lib/bitsetmatrix/bitsetmatrix.cc lib/bitsetmatrix/bitsetmatrix.h
	$(CC) -o bin/bitsetmatrix.o $(CFLAGS) $(CDEBUG) lib/bitsetmatrix/bitsetmatrix.cc
#Clase AesGui
bin/aesgui.o: lib/gui/aesgui.cc lib/gui/aesgui.h
	$(CC) -o bin/aesgui.o $(CFLAGS) $(CDEBUG) lib/gui/aesgui.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) bin/cli bin/cli.o core*.*
