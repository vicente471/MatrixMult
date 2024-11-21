# MatrixMult

Código para experimentar distintas formas de acceder a las matrices en la multiplicación, programado en C.

## Modo de compilación
```
gcc t1.c -o t1.exe
Modo de ejecución
./t1.exe -P -O < data.txt
Parámetros de ejecución
-P: Modo de ejecución
1: i-j-l
2: j-i-l
3: i-l-j
4: j-l-i
5: l-i-j
6: l-j-i
7: Aritmética de Punteros
8: Unidimensional
-O: Verbosidad de salida
V: Verboso
S: Silencioso
Replicación del experimento
Para replicar el experimento, ejecuta el script .sh con el siguiente comando:

./Experimento.sh
El script ejecuta todos los modos de acceso utilizando las entradas desde data.txt hasta data10.txt, guardando los resultados en Resultados.txt.
