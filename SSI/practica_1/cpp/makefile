# Ficheros con codigo fuente
MAIN = principal.cpp
INCS = rc4.h
OBJS = principal.o rc4.o
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
principal.o: $(MAIN) $(INCS)
	$(CC) $(CFLAGS) $(CDEBUG) $(MAIN)
#Clase rc4
rc4.o: rc4.cpp rc4.h
	$(CC) $(CFLAGS) $(CDEBUG) rc4.cpp
#Limpiar
clean:
	rm -f $(OBJS) $(EXEC) core*.*
