#Ayala Fuentes Sunem Gizeht
#Campos Zeron Salvador
echo "Introdusca 1 para suma"
echo "Introdusca 2 para resta"
echo "Introdusca 3 para multiplicación"
echo "Introdusca 4 para división"

suma(){
read -p  "Introdusca el primer número: " N1
read -p "Introdusca el segundo número: " N2
echo "Resultado= " $(echo "$N1+$N2" | bc -l)
}

resta(){
read -p  "Introduce el priemr número: " N1
read -p "Introduce el segundo número: " N2
echo "Resultado= " $(echo "$N1-$N2" | bc -l)
}


multiplicacion(){
read -p  "Introdusca el primer número: " N1
read -p "Introdusca el segundo número: " N2
echo "Resultado= " $(echo "$N1*$N2" | bc -l)
}


division(){
read -p  "Introdusca el primer número: " N1
read -p "Introdusca el segundo número: " N2
echo "Resultado= " $(echo "$N1/$N2" | bc -l)
}


read OPT
case $OPT in
1):
suma
;;
2):
resta
;;
3):
multiplicacion
;;
4):
division
;;

esac
