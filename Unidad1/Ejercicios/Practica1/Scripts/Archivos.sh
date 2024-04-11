#!/bin/bash

# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

ERROR_COLOR="\e[031m"
RESET="\e[033m"

if test $# -ne 3; then
	echo "Pos favor ingrese 3 nombres de archivos como parametros"
	exit 1
fi
COUNT=1
for file in "$@"; do
	if ! test -e "$file"; then
      COUNT=$((COUNT+1))
    fi
done

if [ $COUNT -gt 1 ]; then
  echo -e "${ERROR_COLOR}Ingrese nombres de archivos existentes ${RESET}"
  exit 1
fi

FILE_1=$1
FILE_2=$2
FILE_3=$3

if ! test -r "$FILE_1"; then
  echo -e "\n${ERROR_COLOR}El archivo ${FILE_1} no tiene permisos de lectura${RESET}"
else
  echo -e "\nEl archivo ${FILE_1} tiene permisos de lectura"
fi

if ! test -x "$FILE_2"; then
  echo -e "\n${ERROR_COLOR}El archivo ${FILE_2} no tiene permisos de ejecucion${RESET}"
else
  echo -e "\nEl archivo ${FILE_2} si tiene permisos de ejecucion"
fi

echo -e "\nEl propetiario del archivo es:" $(ls -l "$FILE_3" | awk '{print $3}')

echo -e "\nEl archivo mas antiguo es:" $(stat -c "%Y %n" "$FILE_1" "$FILE_2" "$FILE_3" | sort -n | head -1 | cut -d" " -f2)
