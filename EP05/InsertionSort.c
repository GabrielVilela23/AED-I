#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    int n = 10;
    int arr[n];
    srand(time(NULL));
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100; // preenche o array com valores aleatórios entre 0 e 99
    }

    clock_t start_time, end_time;
    double time_elapsed;

    start_time = clock(); // marca o tempo de início da execução

    insertionSort(arr, n);

    end_time = clock(); // marca o tempo de término da execução

    time_elapsed = ((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000); // calcula o tempo total em milissegundos

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTempo de execução: %f milissegundos", time_elapsed);

    return 0;
}
