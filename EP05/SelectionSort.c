#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Percorre todo o array
    for (i = 0; i < n-1; i++) {
        // Encontra o menor elemento no array não ordenado
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento não ordenado
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr, n);

    end_time = clock(); // marca o tempo de término da execução

    time_elapsed = ((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000); // calcula o tempo total em milissegundos

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTempo de execução: %f milissegundos", time_elapsed);

    return 0;
}
