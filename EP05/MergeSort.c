#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // cria arrays temporários para armazenar os elementos da metade esquerda e direita do array original
    int L[n1], R[n2];

    // copia os elementos para os arrays temporários
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // combina os elementos dos arrays temporários de volta no array original
    i = 0; // índice inicial do primeiro subarray
    j = 0; // índice inicial do segundo subarray
    k = l; // índice inicial do subarray fundido
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia os elementos restantes do subarray esquerdo, se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia os elementos restantes do subarray direito, se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // ordena recursivamente as duas metades do array
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // combina as duas metades ordenadas
        merge(arr, l, m, r);
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

    mergeSort(arr, 0, n-1);

    end_time = clock(); // marca o tempo de término da execução

    time_elapsed = ((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000); // calcula o tempo total em milissegundos

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTempo de execução: %f milissegundos", time_elapsed);

    return 0;
}
