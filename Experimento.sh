#!/bin/bash

archivos_lista=(
    "data.txt" "data2.txt" "data3.txt" "data4.txt" "data5.txt"
    "data6.txt" "data7.txt" "data8.txt" "data9.txt" "data10.txt"
)

archivo_salida="Resultados.txt"

echo "Modo, Tamaño, Tiempo" > "$archivo_salida"

# Bucle para cada modo de ejecución (-1 a -8)
for modo in {1..8}; do
    echo "Ejecutando en modo: -$modo" >> "$archivo_salida"
    
    # Bucle para cada archivo en archivos_lista
    for file in "${archivos_lista[@]}"; do
        echo "Procesando archivo: $file en modo -$modo"

        # Obtener la primera línea del archivo (se asume que representa el tamaño de la matriz)
        primer_linea=$(head -1 "$file")

        # Ejecutar el programa con el archivo y el modo actual
        datos_procesados=$(./t2.exe -"$modo" -S < "$file")

        # Guardar el tamaño y el tiempo de procesamiento en el archivo de salida bajo el modo actual
        echo "-${modo}, ${primer_linea}, ${datos_procesados}" >> "$archivo_salida"
    done
done

echo "Procesamiento finalizado. Revisa los resultados en: $archivo_salida"
