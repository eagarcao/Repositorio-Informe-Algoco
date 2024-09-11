// REFERENCIA :  https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crea vectores temporales para almacenar los elementos de los subvectores.
    vector<int> L(n1), R(n2);

    // Copia los datos a los vectores L y R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inicializa los índices para iterar sobre los subvectores L, R y arr.
    int i = 0, j = 0;
    int k = left;

    // Une los vectores de forma ordenada
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Coloca el menor elemento en arr[k].
            i++; // Avanza en el subvector izquierdo.
        }
        else {
            arr[k] = R[j]; // Coloca el menor elemento en arr[k].
            j++; // Avanza en el subvector derecho.
        }
        k++;
    }

    // Copia los elementos restantes del subvector izquierdo (si los hay).
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia los elementos restantes del subvector derecho (si los hay).
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función que implementa el algoritmo Merge Sort.
void mergeSort(vector<int>& arr, int left, int right){
    // Caso base: Si el subvector tiene un solo elemento o está vacío, no se hace nada.
    if (left >= right)
        return;

    // Encuentra el punto medio para dividir el vector en dos mitades.
    int mid = left + (right - left) / 2;
    // Ordena la primera mitad recursivamente.
    mergeSort(arr, left, mid);
    // Ordena la segunda mitad recursivamente.
    mergeSort(arr, mid + 1, right);
    // Combina las dos mitades ordenadas.
    merge(arr, left, mid, right);
}

// Esta funcion crea el archivo del vector final, junto con su tiempo de ejecucion.
void createFile(vector<int>& arr, float time, string fileName){
    ofstream file;
    file.open("Merge"+fileName+".txt");
    file << "Tiempo de ejecucion : " << time << " segundos.\n";
    for (int i = 0; i < arr.size(); i++)
        file << arr[i] << "\n";
    file.close();
}

int main()
{
    vector<int> arr;
    // Nombre del archivo que esta leyendo.
    string fileName;
    int n;
    cin >> fileName >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }
    
    auto start = chrono::system_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::system_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Tiempo de ejecucion : " << duration.count() << " segundos" << endl;

    createFile(arr, duration.count(), fileName);
    return 0;
}
