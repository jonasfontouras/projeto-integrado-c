#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, k, k1, k2, valida = 0, valida2 = 0, mult, soma = 0, lc = 0, cont = 0, cont_zero = 0, cont_j = 0, cont_zero_j = 0;
    int vet_a[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18}, vet_b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int confere[10][10];
    int inversa[10][10];
    int identidade[10][10];

    printf("\n\n---------------- MATRIZ R  ----------------\n");
    printf("R\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", vet_b[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        printf("%d\t", vet_a[i]);
        for (j = 0; j < 10; j++)
        {
            confere[i][j] = 0;
            confere[0][0] = 1;
            confere[0][1] =1;
            confere[1][3] = 1;
            confere[2][8] = 1;
            confere[3][9] = 1;
            confere[4][2] = 1;
            confere[5][1] = 1;
            confere[6][4] = 1;
            confere[7][6] = 1;
            confere[8][7] = 1;
            confere[9][5] = 1;

            printf("%d  ", confere[i][j]);
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            inversa[i][j] = confere[j][i];
        }
    }

    printf("\n\n---------------- MATRIZ R- ----------------\n");
    printf("R-\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", vet_a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        printf("%d \t", vet_b[i]);
        for (j = 0; j < 10; j++)
        {
            if (j >= 5)
            {
                printf(" ");
            }

            printf("%d  ", inversa[i][j]);
        }
    }

    for (k1 = 0; k1 < 10; k1++)
    {
        for (k2 = 0; k2 < 10; k2++)
        {
            mult = 0;
            for (i = 0; i < 10; i++)
            {
                mult = mult + confere[k1][i] * inversa[i][k2];
            }
            identidade[k1][k2] = mult;
        }
    }

    printf("\n\n---------- MATRIZ IDENTIDADE RoR- ---------\n");
    printf("RoR-\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", vet_b[i]);
    }

    for (i = 0; i < 10; i++)
    {
        printf("\n");
        printf("%d \t", vet_a[i]);

        for (j = 0; j < 10; j++)
        {
            printf("%d  ", identidade[i][j]);
        }
    }

       //Validação ISOMORFISMO/ISORRELAÇÃO
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            if(identidade[i][j] == identidade[i+1][j+1]){
                valida2++;
            } 
            if (i == j)
            {
                if (identidade[i][j] == identidade[i+1][j+1])
                {
                    valida++;
                }
            }
        }
        
    }
    
    if (valida == 9 && valida2 == 98)
    {
        printf("\nE isomorfa");
    }
    else
    {
        printf("\nnao e isomorfa");
    }
    return 0;
}