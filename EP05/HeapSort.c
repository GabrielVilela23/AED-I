#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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

    heapSort(arr, n);

    end_time = clock(); // marca o tempo de término da execução

    time_elapsed = ((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000); // calcula o tempo total em milissegundos

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTempo de execução: %f milissegundos", time_elapsed);

    return 0;
}
