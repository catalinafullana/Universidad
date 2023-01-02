#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    // Mientras no se alcance el final de la entrada
    while (d != 0 || n != 0) {
        int k = 0; // Inicializamos k a 0
        bool encontrado = false; // Bandera para indicar si se ha encontrado una soluci�n
            // Mientras no se haya encontrado una soluci�n y k sea menor que d, seguimos buscando
            while (!encontrado && k < d) {
                k++; // Incrementamos k
                int ceros = 0; // Contador de ceros
                int factorial = 1; // Valor del factorial de k

                // Calculamos el factorial de k
                for (int i = 1; i <= k; i++) {
                    factorial *= i;
                }

                // Contamos los ceros al final del factorial
                while (factorial % 10 == 0) {
                    ceros++;
                    factorial /= 10;
                }

                // Si el n�mero de ceros es igual a n, hemos encontrado una soluci�n
                if (ceros == n) {
                    encontrado = true;
                }
            }

        // Si se ha encontrado una soluci�n, la imprimimos
        if (encontrado) {
            cout << k << endl;
        }
        // Si no, imprimimos "NINGUNO"
        else {
            cout << "NINGUNO" << endl;
        }

        cin >> d >> n; // Leemos el siguiente caso de prueba
    }

    return 0;
}
