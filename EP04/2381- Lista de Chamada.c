#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    while (getchar() != '\n');
    
    char** strings = (char**)malloc(n * sizeof(char*));
    
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char)); 
        fgets(strings[i], 100, stdin);
    }
    
    qsort(strings, n, sizeof(char*), compareStrings);
    
    printf("%s", strings[k-1]);
    
    // Liberar a memória alocada
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
 
    return 0;
}
