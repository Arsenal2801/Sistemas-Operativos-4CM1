#!/bin/bash
# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

# Imprimir las ultimas 15 lineas del log del sistema (/var/log/syslog) en orden inverso
# redirigir la salida estandar a un archivo de texto que se llame syslog.txt
# redirigir los errores al archivo /dev/null

ROUTE="/var/log/syslog"
LAST_LINES=$(tail -n 15 $ROUTE)
INVERT_LINES=$(echo "$LAST_LINES" | tac  > syslog.txt 2>/dev/null)
echo -e "El archivo se a creado $INVERT_LINES \n"

batcat syslog.txt || cat syslog.txt

