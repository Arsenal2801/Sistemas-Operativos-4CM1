#! /bin/bash
#
# Elaboro:
# Ayala Fuentes Sunem Gizeth
# Campos Zeron Salvador
# Michel Hernandez Santiago
# Caballero Paredes Victor

COLOR='\033[38;5;206m'
NORMAL='\033[0m'
RED='\033'

# Impresion de la cabecera
echo "--------------------------------------------------------------------"
echo "Bienvenido al generador de carpetas"
echo -e "${COLOR}Para crear las carpetas presione 1 para continuar ${NORMAL}"
echo "--------------------------------------------------------------------"

# Lectura de OPT
read OPT

# Validacion de opcion correcta
case $OPT in
  # Caso valido
  "1")
  # Declaracion de variables
    COUNT=0
    MAX=10
    # Lectura y solicitud de datos
    echo -e "${COLOR}Ingresa la cantidad de archivos que quieras generar"
    read CANT
    # Validacion menor que 10
    if [ $MAX -lt $CANT ];
    then
      echo "Favor de ingresar un numero menor que 10"
      exit 2
    fi
    echo -e "${COlOR}Ingresa el nombre principal para las carpetas"
    read NAME
    # Ciclo de creacion de carpetas
    while [ ${COUNT} -ne ${CANT} ]; do
      mkdir "${NAME}_${COUNT}"
      echo -e "${COLOR}Carpeta creada con el nombre ${NAME}_${COUNT}"
      COUNT=$((COUNT+1))
    done
    ls -l
    # Eliminacion de carpetas creadas
    for ((COUNTER=0; $COUNTER<$CANT; ((COUNTER++)))); do
      rmdir ${NAME}_${COUNTER}
      echo "Se ha eliminado la carpeta con nombre: ${NAME}_${COUNTER}"
    done
    ls -l
  ;;
  # Caso base
  *)
    echo -e "${COLOR}Hasta luego :3"
    ;;
esac
