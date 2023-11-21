#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generarArregloOrdenado(int arreglo[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        arreglo[i] = i;
    }
}


int busquedaSecuencial(int arreglo[], int tamano, int clave) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == clave) {
            return i;
        }
    }
    return -1; 
}


int busquedaBinaria(int arreglo[], int inicio, int fin, int clave) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arreglo[medio] == clave) {
            return medio; 
        }
        if (arreglo[medio] < clave) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1; 
}

int main() {
    const int tamano = 50000;
    int arreglo[tamano];
    srand(time(NULL));

    generarArregloOrdenado(arreglo, tamano);

    
    const int numEjecuciones = 100;
    clock_t inicio, fin;
    double tiemposSecuencial[numEjecuciones];
    double tiemposBinaria[numEjecuciones];

   
    printf("Búsqueda Secuencial:\n");
    for (int i = 0; i < numEjecuciones; i++) {
        int clave = rand() % tamano;
        inicio = clock();
        busquedaSecuencial(arreglo, tamano, clave);
        fin = clock();
        tiemposSecuencial[i] = ((double)(fin - inicio) * 1000.0) / CLOCKS_PER_SEC;
        printf("Ejecución %d: %.4f ms\n", i + 1, tiemposSecuencial[i]);
    }

    // Búsqueda Binaria
    printf("\nBúsqueda Binaria:\n");
    for (int i = 0; i < numEjecuciones; i++) {
        int clave = rand() % tamano;
        inicio = clock();
        busquedaBinaria(arreglo, 0, tamano - 1, clave);
        fin = clock();
        tiemposBinaria[i] = ((double)(fin - inicio) * 1000.0) / CLOCKS_PER_SEC;
        printf("Ejecución %d: %.4f ms\n", i + 1, tiemposBinaria[i]);
    }


    double sumaSecuencial = 0.0;
    double minSecuencial = tiemposSecuencial[0];
    double maxSecuencial = tiemposSecuencial[0];
    for (int i = 0; i < numEjecuciones; i++) {
        sumaSecuencial += tiemposSecuencial[i];
        if (tiemposSecuencial[i] < minSecuencial) {
            minSecuencial = tiemposSecuencial[i];
        }
        if (tiemposSecuencial[i] > maxSecuencial) {
            maxSecuencial = tiemposSecuencial[i];
        }
    }


    double sumaBinaria = 0.0;
    double minBinaria = tiemposBinaria[0];
    double maxBinaria = tiemposBinaria[0];
    for (int i = 0; i < numEjecuciones; i++) {
        sumaBinaria += tiemposBinaria[i];
        if (tiemposBinaria[i] < minBinaria) {
            minBinaria = tiemposBinaria[i];
        }
        if (tiemposBinaria[i] > maxBinaria) {
            maxBinaria = tiemposBinaria[i];
        }
    }

    
    printf("\nEstadísticas Búsqueda Secuencial:\n");
    printf("Tiempo Promedio: %.4f ms\n", sumaSecuencial / numEjecuciones);
    printf("Tiempo Mínimo: %.4f ms\n", minSecuencial);
    printf("Tiempo Máximo: %.4f ms\n", maxSecuencial);

    printf("\nEstadísticas Búsqueda Binaria:\n");
    printf("Tiempo Promedio: %.4f ms\n", sumaBinaria / numEjecuciones);
    printf("Tiempo Mínimo: %.4f ms\n", minBinaria);
    printf("Tiempo Máximo: %.4f ms\n", maxBinaria);

    return 0;
}

