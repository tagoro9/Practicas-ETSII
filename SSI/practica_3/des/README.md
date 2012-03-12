#Cifrado Des

##Autor: Víctor Mora Afonso. alu3966.
###Asignatura: Seguridad en sistemas informáticos
###Marzo de 2012

********************************

####Uso de la aplicación

Existen dos versiones del programa: una versión de terminal y otra versión con una interfaz gráfica.

* Versión de consola

Para compilarla ejecutar en la carpeta raíz el *makefile* con la opción *cli*.

    make cli

Se creará un ejecutable en la carpeta *bin* con el nombre *cli*. Al ejecutarlo, es necesario pasarle 3 parámetros:

1. **Semilla** (puede estar en formato binario (64 bits), en hexadecimal (16 dígitos) o en texto plano (8 caracteres).
2. **Mensaje** puede estar en los mismos formatos que la semilla.
3. **Modo de ejecución**.

    * **Estándar:** s 
    * **Depuración:** d
    * **Depuración extendida:** e
    
Un ejemplo de ejecución:

    ./bin/cli "LALALALA" "MENSAJES" "e"

* Versión gráfica

Para compilarla ejecutar el *makefile* de la raíz de la aplicación (all).

Se creará un ejecutable *main* en la carpeta *bin*.

    ./bin/main

En la aplicación se han de introducir tanto la clave como el mensaje (en formato binario, hexadecimal o texto). Tras hacer click en el botón *cifrar* se mostrará la salida del algoritmo y, si se marcaron las opciones de depuración, aparecerá en el texto una traza del mismo.

********************************

####Notas sobre compilación

Para poder compilar la práctica es necesario tener instaladas las librerías *[boost](http://www.boost.org)*. (En ubuntu: librerías libboost-dev y libboos-regex-dev)

Además para compilar la versión gráfica de la práctica es necesario también tener instaladas las librerías gtkmm2.4