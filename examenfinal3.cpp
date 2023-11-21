#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high); 

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
              
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    srand(time(0));
    int n = 10000;
    int arr[n];

    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    
    clock_t start, end;
    double cpu_time_used;

    
    printf("Insertion Sort:\n");
    for (int i = 0; i < 100; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) {
            temp[j] = arr[j];
        }

        start = clock();
        insertionSort(temp, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; 
        printf("Execution %d: %f ms\n", i + 1, cpu_time_used);
    }


    printf("\nQuick Sort:\n");
    for (int i = 0; i < 100; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) {
            temp[j] = arr[j];
        }

        start = clock();
        quickSort(temp, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; // Tiempo en milisegundos
        printf("Execution %d: %f ms\n", i + 1, cpu_time_used);
    }

   
    printf("\nBubble Sort:\n");
    for (int i = 0; i < 100; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) {
            temp[j] = arr[j];
        }

        start = clock();
        bubbleSort(temp, n);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0; // Tiempo en milisegundos
        printf("Execution %d: %f ms\n", i + 1, cpu_time_used);
    }

    return 0;
}

