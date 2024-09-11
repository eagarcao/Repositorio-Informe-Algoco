#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

// Esta funcion crea el archivo del vector final, junto con su tiempo de ejecucion.
void createFile(vector<int>& arr, float time, string fileName){
    ofstream file;
    file.open("Std"+fileName+".txt");
    file << "Tiempo de ejecucion : " << time << " segundos.\n";
    for (int i = 0; i < arr.size(); i++)
        file << arr[i] << "\n";
    file.close();
}


int main(){   
    vector<int> vec;
    string fileName;
    int n;
    cin >> fileName >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        vec.push_back(input);
    }

    auto start = chrono::system_clock::now();
    // Funcion de sorting de la libreria estandar
    sort(vec.begin(), vec.end());
    auto end = chrono::system_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Tiempo de ejecucion : " << duration.count() << " segundos" << endl;

    createFile(vec, duration.count(), fileName);

    return 0;
}