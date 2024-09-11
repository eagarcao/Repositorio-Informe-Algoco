#!/bin/bash

# Itera sobre los archivos que comienzan con "Des" y terminan con ".txt"
for file in ArchivosOrdenamiento/Des*.txt; do
    echo "Ejecutando con archivo de entrada: $file"
    ./mergeSort < "$file"
done

for file in ArchivosOrdenamiento/Ord*.txt; do
    echo "Ejecutando con archivo de entrada: $file"
    ./mergeSort < "$file"
done

for file in ArchivosOrdenamiento/ParD*.txt; do
    echo "Ejecutando con archivo de entrada: $file"
    ./mergeSort < "$file"
done

for file in ArchivosOrdenamiento/ParI*.txt; do
    echo "Ejecutando con archivo de entrada: $file"
    ./mergeSort < "$file"
done

for file in ArchivosOrdenamiento/Rev*.txt; do
    echo "Ejecutando con archivo de entrada: $file"
    ./mergeSort < "$file"
done