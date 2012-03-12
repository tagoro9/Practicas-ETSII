# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/bitset/bitset.h lib/sbox/sbox.h lib/keys/keys.h lib/des/des.h lib/gui/desGui.h
OBJS = bin/main.o bin/bitset.o bin/sbox.o bin/keys.o bin/des.o bin/desGui.o
EXEC = bin/main
# Compilador y opciones
CC     = g++
CFLAGS = -c `pkg-config gtkmm-2.4 --cflags --libs`
CDEBUG = -g
LIBS = -lboost_regex-mt -I/opt/local/include/ -L/opt/local/lib/ `pkg-config gtkmm-2.4 --cflags --libs`
# Reglas
all: $(EXEC)
cli : bin/cli
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
bin/cli: bin/cli.o bin/bitset.o bin/sbox.o bin/keys.o bin/des.o
	g++ -o bin/cli bin/cli.o bin/bitset.o bin/sbox.o bin/keys.o bin/des.o -lboost_regex-mt -I/opt/local/include/ -L/opt/local/lib/
#Cli
bin/cli.o: main_cli.cc lib/bitset/bitset.h lib/sbox/sbox.h lib/keys/keys.h lib/des/des.h
	g++ -o bin/cli.o -c -g main_cli.cc
#Principal
bin/main.o: $(MAIN) $(INCS)
	$(CC) -o bin/main.o $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase bitset
bin/bitset.o: lib/bitset/bitset.cc lib/bitset/bitset.h
	$(CC) -o bin/bitset.o $(CFLAGS) $(CDEBUG) lib/bitset/bitset.cc
#Clase sbox
bin/sbox.o: lib/sbox/sbox.cc lib/sbox/sbox.h
	$(CC) -o bin/sbox.o $(CFLAGS) $(CDEBUG) lib/sbox/sbox.cc
#Clase keys
bin/keys.o: lib/keys/keys.cc lib/keys/keys.h
	$(CC) -o bin/keys.o $(CFLAGS) $(CDEBUG) lib/keys/keys.cc
#Clase des
bin/des.o: lib/des/des.cc lib/des/des.h
	$(CC) -o bin/des.o $(CFLAGS) $(CDEBUG) lib/des/des.cc
#Clase DesGui
bin/desGui.o: lib/gui/desGui.cc lib/gui/desGui.h
	$(CC) -o bin/desGui.o $(CFLAGS) $(CDEBUG) lib/gui/desGui.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*