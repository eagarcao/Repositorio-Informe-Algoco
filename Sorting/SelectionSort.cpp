// REFERENCIA : https://www.geeksforgeeks.org/selection-sort-algorithm-2/
#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;


void selectionSort(int arr[], int n){
    // Recorre todo el array (excepto el último elemento, que se ordena por sí solo)
    for (int i = 0; i < n - 1; i++){
        // Inicializa el índice del elemento más pequeño con el índice del elemento actual
        int min_idx = i;
        // Busca el indice del elemento mas pequieño en la parte no ordenada del array
        for (int j = i + 1; j < n; j++){
            // Si encuentra un elemento más pequeño, actualiza min_idx
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Si el índice del elemento más pequeño no es el mismo que el índice actual,
        // intercambia el elemento más pequeño encontrado con el primer elemento no ordenado
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Esta funcion crea el archivo del array final, junto con su tiempo de ejecucion.
void createFile(int arr[], int n, float time, string fileName){
    ofstream file;
    file.open("Selection"+fileName+".txt");
    file << "Tiempo de ejecucion : " << time << " segundos.\n";
    for (int i = 0; i < n; i++)
        file << arr[i] << "\n";
    file.close();
}

int main()
{   
    // Nombre del archivo que esta leyendo
    string fileName;
    int n;
    cin >> fileName >> n;
    int *arr = new int[n];
    // Ingresa los elementos al array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    auto start = chrono::system_clock::now();
    selectionSort(arr, n);
    auto end = chrono::system_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Tiempo de ejecucion : " << duration.count() << " segundos" << endl;
    createFile(arr, n, duration.count(), fileName);
    return 0;
}