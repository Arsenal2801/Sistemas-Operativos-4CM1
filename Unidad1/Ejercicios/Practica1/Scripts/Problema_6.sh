#!/bin/bash
# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

# Que lea nombres de archivos de un archivo de texto y los copie a otro
# directorio el usuario introduce el nombre del archivo y el nombre del
# directorio destino

if [ $# -ne 2 ]; then
  echo "Por favor ingresa un archivo y una ruta como parametros"
  echo "Como en este ejemplo:"
  echo "$0 <archivo> <directorio_de_destino>"
  exit 1
fi

FILENAME="$1"
DIRECTORY="$2"

if ! test -f "$FILENAME"; then
  echo "El archivo de nombres '$FILENAME' no existe"
  exit 1
fi

if ! test -d "$DIRECTORY"; then
  echo "La ruta '$DIRECTORY' no existe"
  exit 1
fi

while IFS= read -r NEW_FILENAME; do
  if test -f "$NEW_FILENAME"; then
    cp "$NEW_FILENAME" "$DIRECTORY"
    echo "Se ha copiado $NEW_FILENAME en $DIRECTORY correctamente"
  else
    echo "El archivo '$NEW_FILENAME' no existe"
  fi
done<"$FILENAME"
