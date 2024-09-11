// REFERENCIA :  https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

// Función que realiza la partición del vector y coloca el pivote en la posición correcta.
int partition(vector<int> &vec, int low, int high) {
    // Selecciona el ultimo elemento como pivote
    int pivot = vec[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Compara si el elemento actual es menor o igual al pivote
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Coloca el pivote en su posición correcta (entre los menores y mayores)
    swap(vec[i + 1], vec[high]);

    // Retorna la posicion final del pivote
    return (i + 1);
}

// Función que implementa el algoritmo de ordenación Quick Sort.
void quickSort(vector<int> &vec, int low, int high) {
    // Verifica si el subvector tiene más de un elemento (condición para dividir)
    if (low < high) {
        // pi es el indice de la particion, arr[pi] esta en la posicion correcta
        // Realiza la partición y obtiene la posición del pivote.
        int pi = partition(vec, low, high);

        // Ordena recursivamente los elementos antes y después del pivote.
        quickSort(vec, low, pi - 1); // Lado izquierdo del pivote.
        quickSort(vec, pi + 1, high); // Lado derecho del pivote.
    }
}

// Esta funcion crea el archivo del vector final, junto con su tiempo de ejecucion.
void createFile(vector<int>& arr, float time, string fileName){
    ofstream file;
    file.open("Quick"+fileName+".txt");
    file << "Tiempo de ejecucion : " << time << " segundos.\n";
    for (int i = 0; i < arr.size(); i++)
        file << arr[i] << "\n";
    file.close();
}

int main() {
    vector<int> vec;
    string fileName;
    int n;
    cin >> fileName >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        vec.push_back(input);
    }
    
      // Calling quicksort for the vector vec
    

    auto start = chrono::system_clock::now();
    quickSort(vec, 0, n - 1);
    auto end = chrono::system_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Tiempo de ejecucion : " << duration.count() << " segundos" << endl;
    createFile(vec, duration.count(), fileName);
    return 0;
}