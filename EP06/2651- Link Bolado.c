#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    
    char z[100010];
    int i;
    
    while (scanf("%s ", z) != EOF) {
        
        for (i = 0; i < strlen(z); i++)
            z[i] = toupper(z[i]);
            
        printf("Link %s\n", (strstr(z, "ZELDA") != NULL? "Bolado" : "Tranquilo"));
    }

    return 0;
}