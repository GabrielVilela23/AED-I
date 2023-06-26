#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1005

int main()
{
bool p, f, fp;
int fila[MAXN], pilha[MAXN], filaPrioridade[MAXN];
int n, operacao, numero, tamFila = 0, tamPilha = 0, tamFilaPrioridade = 0;

while (scanf("%d", &n) != EOF)
{
    tamFila = tamPilha = tamFilaPrioridade = 0;

    p = true, f = true, fp = true;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &operacao, &numero);

        if (operacao == 1)
        {
            if (p)
                pilha[tamPilha++] = numero;
            if (f)
                fila[tamFila++] = numero;
            if (fp)
                filaPrioridade[tamFilaPrioridade++] = numero;
        }
        else
        {
            if (p)
            {
                if (tamPilha == 0 || pilha[tamPilha-1] != numero)
                    p = false;
                else
                    tamPilha--;
            }

            if (f)
            {
                if (tamFila == 0 || fila[0] != numero)
                    f = false;
                else
                    for (int j = 0; j < tamFila-1; ++j)
                        fila[j] = fila[j+1];
                    tamFila--;
            }

   