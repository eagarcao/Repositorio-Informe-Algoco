// REFERENCIA :  https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <random>
using namespace std;

// Inicializa generadores de números aleatorios
random_device rd;
mt19937 gen(rd());

// Función que realiza la partición del vector usando un pivote aleatorio
int partition(vector<int> &vec, int low, int high) {
    // Selecciona un índice aleatorio entre low y high como pivote
    uniform_int_distribution<> distrib(low, high);
    int randN = distrib(gen);

    // Intercambia el elemento en el índice aleatorio con el primer elemento del subvector
    swap(vec[randN], vec[low]);

    // El pivote es ahora el primer elemento del subvector
    int pivot = vec[low];
    int i = (low + 1);

    // Recorre el subvector desde el segundo elemento hasta el último
    for (int j = low + 1; j <= high; j++) {
        // Compara si el elemento actual es menor o igual al pivote
        if (vec[j] <= pivot) {
            swap(vec[i], vec[j]); // Intercambia el elemento actual con el elemento en i
            i++;
        }
    }

    // Coloca el pivote en su posición correcta (entre los menores y mayores)
    swap(vec[i - 1], vec[low]);

    // Retorna la posicion final del pivote
    return (i - 1);
}

// Función que implementa el algoritmo de ordenación Quick Sort
void quickSort(vector<int> &vec, int low, int high) {
    // Verifica si el subvector tiene más de un elemento
    if (low < high) {
        // pi es el indice de la particion, arr[pi] esta en la posicion correcta
        // Realiza la partición y obtiene la posición del pivote
        int pi = partition(vec, low, high);

        // Ordena los elementos que estan antes y despues de pi de forma separada
        quickSort(vec, low, pi - 1); // Lado izquierdo del pivote
        quickSort(vec, pi + 1, high); // Lado derecho del pivote
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