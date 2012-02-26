# Ficheros con codigo fuente
MAIN = main.cc
INCS = lib/skc/skc.h lib/skc/a5/a5.h lib/skc/rc4/rc4.h lib/gui/gui.h
OBJS = bin/main.o bin/skc.o bin/a5.o bin/rc4.o bin/gui.o
EXEC = bin/main
LIBS = `pkg-config gtkmm-2.4 --cflags --libs`
# Compilador y opciones
CC     = g++
CFLAGS = -c `pkg-config gtkmm-2.4 --cflags --libs`
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
#Clase Gui
bin/gui.o: lib/gui/gui.cc lib/gui/gui.h
	$(CC) -o bin/gui.o $(CFLAGS) $(CDEBUG) lib/gui/gui.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*