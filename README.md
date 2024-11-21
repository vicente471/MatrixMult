# MatrixMult
# Codigo para experimentar distintas formas de acceder a las matrices en la multiplicacion, programado en C

Modo de compilacion : gcc t1.c -o t1.exe
Modo de ejecucion: ./t1.exe -P -O < data.txt
Donde 			
			-P Modo de ejecucion {1: i-j-l, 2: j-i-;, 3: i-l-j, 4: j-l-i, 5: l-i-j, 6: l-j-i , 7: Aritmetica Punteros, 8: Unidimensional}
			-O {V: verboso, S: silencioso}
Para replicar experimento correr 3 scripts sh de la siguiente manera
./Experimento.sh

Donde este .sh ejecuta todos los modos con la entrada desde data.txt hasta data10.txt, guardando los resultados en Resultados.txt
