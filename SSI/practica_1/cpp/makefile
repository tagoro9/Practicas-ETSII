#g++ simple.cc -o simple `pkg-config gtkmm-3.0 --cflags --libs`
# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/rc4.h lib/grc4.h
OBJS = bin/main.o bin/rc4.o bin/grc4.o
EXEC = bin/main
LIBS = `pkg-config gtkmm-3.0 --cflags --libs`
# Compilador y opciones
CC     = g++
CFLAGS = -c `pkg-config gtkmm-3.0 --cflags --libs`
CDEBUG = -g
# Reglas
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
#Principal
bin/main.o: $(MAIN) $(INCS)
	$(CC) -o bin/main.o $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase rc4
bin/rc4.o: lib/rc4.cc lib/rc4.h
	$(CC) -o bin/rc4.o $(CFLAGS) $(CDEBUG) lib/rc4.cc
#Clase grc4
bin/grc4.o: lib/grc4.cc lib/grc4.h
	$(CC) -o bin/grc4.o $(CFLAGS) $(CDEBUG) lib/grc4.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*
