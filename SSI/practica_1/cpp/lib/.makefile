# Ficheros con codigo fuente
MAIN = main.cc
INCS = rc4.h
OBJS = main.o rc4.o
EXEC = rc4
LIBS =
# Compilador y opciones
CC     = g++
CFLAGS = -c -ansi -pedantic
CDEBUG = -g
# Reglas
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
#Principal
main.o: $(MAIN) $(INCS)
	$(CC) $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase rc4
rc4.o: rc4.cc rc4.h
	$(CC) $(CFLAGS) $(CDEBUG) rc4.cc
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*
