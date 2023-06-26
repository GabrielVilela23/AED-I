#include <stdio.h>

int main(){
    int n, i=0, j=0, l, k;
    char c[51];
    int total;
    
    scanf("%d",&n);
    while (i < n){
        scanf("%d%*c",&l);
        total = 0;
        for (j=0; j < l; j++){
            scanf("%[^\n]%*c",&c);
            for(k = 0; c[k] != '\0'; k++){
                total += c[k] - 65 + j + k;
            
            }
         }
        i++;
        printf("%d\n", total);
    }
    return 0;
}