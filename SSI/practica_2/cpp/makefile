# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/skc/skc.h lib/skc/a5/a5.h lib/skc/rc4/rc4.h
OBJS = bin/main.o bin/skc.o bin/a5.o bin/rc4.o
EXEC = bin/main
LIBS =
# Compilador y opciones
CC     = g++
CFLAGS = -c
CDEBUG = -g
# Reglas
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
#Principal
bin/main.o: $(MAIN) $(INCS)
	$(CC) -o bin/main.o $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase skc
bin/skc.o: lib/skc/skc.cc lib/skc/skc.h
	$(CC) -o bin/skc.o $(CFLAGS) $(CDEBUG) lib/skc/skc.cc
#Clase a5
bin/a5.o: lib/skc/a5/a5.cc lib/skc/a5/a5.h 
	$(CC) -o bin/a5.o $(CFLAGS) $(CDEBUG) lib/skc/a5/a5.cc
#Clase rc4
bin/rc4.o: lib/skc/rc4/rc4.cc lib/skc/rc4/rc4.h 
	$(CC) -o bin/rc4.o $(CFLAGS) $(CDEBUG) lib/skc/rc4/rc4.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*