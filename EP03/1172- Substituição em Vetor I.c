#include <stdio.h>
 
int main() {
 
    int v[10], i;
    
//Lê o vetor e já incorpora o intervalo em i
    for (i=0; i<10; i++){
        scanf ("%d", &v[i]);}
        
//Verifica os números no intervalo
    for (i=0; i<10; i++){
        if (v[i]<=0){
            v[i]=1;}}

//Imprime com base nos alterados
    for (i=0; i<10; i++){
        printf ("X[%d] = %d\n", i, v[i]);}
 
return 0;
}