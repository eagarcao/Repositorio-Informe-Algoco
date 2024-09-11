#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

// Funcion para multiplicar matrices
vector<vector<long int> > multiplicar(vector<vector<long int> > matrizA, vector<vector<long int> > matrizB){
    // Cantidad de filas y columnas de cada matriz
    int fA = matrizA.size(), cA = matrizA[0].size(), fB = matrizB.size(), cB = matrizB[0].size();
    // Vector que guardara matriz resultante
    vector<vector<long int> > matrizAB(fA, vector<long int> (fB));
    for(int i = 0; i < fA; i++){
        for(int j = 0; j < fB; j++){
            for(int k = 0; k < cB; k++){
                // Se multiplica con B[j][k] ya que es la matriz traspuesta
                matrizAB[i][j] += matrizA[i][k] * matrizB[j][k];
            }
        }
    }
    return matrizAB;
}


// Funcion para guardar tiempo de ejecucion y resultado en un archivo.
void createFile(vector<vector<long int> > matriz, float time, string name){
    int m = matriz.size(), n = matriz[0].size();
    ofstream file;
    file.open("Trasp"+name+".txt");
    file << "Tiempo de ejecucion : " << time << " segundos.\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            file << matriz[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
}

int main(){
    vector<vector<long int> > matrizAB;
    string fileName;
    int fA, cA, fB, cB;
    cout << "Creando matrices..." << endl;
    // La primera linea de los archivos contiene el nombre
    // despues esta el numero de filas y columnas de la matriz A
    cin >> fileName >> fA >> cA;
    vector<vector<long int> > matrizA(fA, vector<long int> (cA));
    for(int i = 0; i < fA; i++){
        for(int j = 0; j < cA; j++){
            int elemento;
            cin >> elemento;
            matrizA[i][j] = elemento;
        }
    }
    // Cuando termina la matriz A viene el numero de filas y columnas de la matriz B
    cin >> fB >> cB;
    vector<vector<long int> > matrizB(cB, vector<long int> (fB));
    for(int i = 0; i < fB; i++){
        for(int j = 0; j < cB; j++){
            int elemento;
            cin >> elemento;
            matrizB[j][i] = elemento;
        }
    }

    cout << "Matrices listas. " << endl;

    auto start = chrono::system_clock::now();
    matrizAB = multiplicar(matrizA, matrizB);
    auto end = chrono::system_clock::now();

    chrono::duration<float> duration = end - start;
    cout << "Tiempo de ejecucion : " << duration.count() << " segundos" << endl;

    createFile(matrizAB, duration.count(), fileName);
    return 0;

}