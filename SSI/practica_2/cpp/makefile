#g++ simple.cc -o simple `pkg-config gtkmm-3.0 --cflags --libs`
# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/a5.h
OBJS = bin/main.o bin/a5.o
EXEC = bin/main
#LIBS = `pkg-config gtkmm-3.0 --cflags --libs`
LIBS =
# Compilador y opciones
CC     = g++
#CFLAGS = -c `pkg-config gtkmm-3.0 --cflags --libs`
CFLAGS = -c
CDEBUG = -g
# Reglas
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
#Principal
bin/main.o: $(MAIN) $(INCS)
	$(CC) -o bin/main.o $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase a5
bin/a5.o: lib/a5.cc lib/a5.h
	$(CC) -o bin/a5.o $(CFLAGS) $(CDEBUG) lib/a5.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*
