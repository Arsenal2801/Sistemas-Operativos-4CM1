# Ayala Fuentes Sunem Gizeht
# Campos Zeron Salvador

#!/bin/bash

output=$(eval "ls -l; date; pwd; mv file1 file2; cp file2 file3")
echo "### Salida de los comandos" > output.txt
echo "$output" | sed -n '/^total/p;/^[a-zA-Z]/p' | sort >> output.txt
cat output.txt
