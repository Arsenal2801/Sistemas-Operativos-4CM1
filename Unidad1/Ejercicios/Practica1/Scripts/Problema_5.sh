#!/bin/bash
# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

# Valida los argumentos de ejecucion de el script
# Si tiene argumentos que imprima el numero de argumentos y su valor,
# Si no entonces imprime "Sin argumentos"

if ! test $# -ne 0; then
  echo "Sin argumentos"
  exit 1
fi
echo "El numero de argumentos es: $#"

COUNT=0
for ARGS in "$@"; do
  COUNT=$(($COUNT+1))
  echo "El argumento ${COUNT} tiene valor $ARGS"
done
