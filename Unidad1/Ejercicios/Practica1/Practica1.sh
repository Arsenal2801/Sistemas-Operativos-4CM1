#!/bin/bash

echo "_____________________________________________________________"
echo "_____________________________________________________________"
echo "                          Practica 1                         "
echo "Elaboró:"
echo "       - Ayala Fuentes Sunem Gizeht"
echo "       - Campos Zeron Salvador"
echo "_____________________________________________________________"
echo "_____________________________________________________________"

echo "Opciones:"
echo "        1.- Imprime las lineas de syslog"
echo "        2.- Valida la informacion de 3 archivos"
echo "        3.- Validacion de argumentos"
echo "        4.- Copiar archivos desde un fichero con dichos nombres a un fichero de destino"
echo "        5.- Buscar ciertas ocurrencias y guardar los nombres de los archivos en un documento de texto"
echo "        6.- Ejecuta comandos y guarda la salida de ellos en un archivo"
echo "_____________________________________________________________"
echo "_____________________________________________________________"

read -p "Seleccione una opcion para ejecutar el script correspondiente: " OPT

case $OPT in
  1):
    ./Scripts/Problema_1.sh
    ;;
  2):
    read -p "Ingresa el nombre del primer archivo: " PARAM_1
    read -p "Ingresa el nombre del segundo archivo: " PARAM_2
    read -p "Ingresa el nombre del ultimo archivo: " PARAM_3
    ./Scripts/Archivos.sh "$PARAM_1" "$PARAM_2" "$PARAM_3"
    ;;
  3):
    echo "Ejecuta el siguiente comando e ingresa los paramentros que quieras"
    echo "./Scripts/Problema_5.sh"
    ;;
  4):
    read -p "Ingresa el nombre del archivo de texto con los nombres de los archivos: " FILE
    read -p "Ingresa la ruta en donde quieres copiar los archivos: " DIRECTORY
    ./Scripts/Problema_6.sh "$FILE" "$DIRECTORY"
    ;;
  5):
    read -p "Ingresa la ruta donde quieres buscar: " DIRNAME
    read -p "Ingresa la palabra clave entre commilas para buscar las ocurrencias: " WORD
    read -p "Ingresa donde se va a guardar el archivo: " FILENAME
    ./Scripts/Problema_7.sh "$DIRNAME" "$WORD" "$FILENAME"
    ;;
  6):
    ./Scripts/Practica_8.sh
    ;;
esac

