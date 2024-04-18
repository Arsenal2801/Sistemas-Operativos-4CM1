# Practica 2 - Creacion de procesos y ejecucion de programas

## Objetivos

* Conocer el procedimiento de creación de procesos (Fork)
* Estudiar el procedimiento de ejecución de un programa dentro de un proceso (exec)
* Suspender la ejecución de un proceso hasta que otro termine (wait)
* Aplicar las funciones fork, wait y exec en un programa en C, usando el estándar POSIX

## Instrucciones

Crear un programa que simule una terminal bash. A continuación se describe el funcionamiento esperado:

1. El programa imprime un prompt usando un caracter especial ($) y recibe una cadena que es el nombre del "archivo ejecutable".
2. El programa crea un nuevo proceso para ejecutar el "archivo ejecutable".
3. El programa valida que el nuevo proceso se haya creado correctamente, si no es así, imprime el error correspondiente.
4. El programa ejecuta el “archivo ejecutable” desde el nuevo proceso.
5. Una vez que el nuevo proceso termina la ejecución del archivo, finaliza su ejecución con la instrucción exit.
6. El programa valida que la ejecución del “archivo ejecutable” fue correcta, de no ser así, imprime el mensaje de error correspondiente (e.g. el archivo no existe o no es un archivo ejecutable).
7. El proceso principal (padre) suspende su ejecución hasta que el proceso nuevo termine la ejecución del “archivo ejecutable”.
8. El programa vuelve a imprimir el prompt para recibir una nueva cadena.
9. El programa se ejecuta de manera cíclica hasta que el usuario escribe EXIT

A continuación se enlistan los programas que serán los archivos ejecutables (usar los mismos nombres):

1. printPpid - Imprime la información del ID proceso padre
2. printPid - Imprime la información del ID del proceso
3. printGroup - Imprime la información del grupo del proceso
4. printSesion - Imprime la información de la sesión
5. printUser – Imprime la información del usuario que ejecutó el proceso
6. PrintSerieFibonacci (n) – Imprime el elemento n de la serie fibonacci
