# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

#!/bin/bash
directorio=$1
patron=$2
Archivo_Resumen=$3
find $directorio -type f -exec grep -Hn "$patron" {} \; >> $Archivo_Resumen 2>/dev/null
