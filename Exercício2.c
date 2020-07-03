#include <stdio.h>
int main(){
    int i, j, k1, k2, soma = 0, valida = 0, valida2 = 0;
    int vet_a[10] = {5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    char vet_b[10] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M'};
    int matriz_s[10][10], matriz_invesrsa[10][10], matriz_id[10][10];

    //Implementação da Relação S com os vetores a e b:
    for(i = 0;i < 10; i++){
        for(j = 0; j < 10; j++){
            matriz_s[i][j] = 0;
            matriz_s[0][5] = 1;
            matriz_s[1][0] = 1;
            matriz_s[2][3] = 1;
            matriz_s[3][7] = 1;
            matriz_s[4][4] = 1;
            matriz_s[5][9] = 1;
            matriz_s[6][1] = 1;
            matriz_s[7][6] = 1;
            matriz_s[8][8] = 1;
            matriz_s[9][2] = 1;
        }
    }
    //Apresentação da matriz da relação S
    printf("\n\n---------------- MATRIZ S  ----------------\n");
    printf("S\t");
    for(i = 0; i < 10; i++){
        printf("%c  ", vet_b[i]);
    }

    for(i = 0; i < 10; i++){
        printf("\n%d\t", vet_a[i]);
        for(j = 0; j < 10; j++){
            printf("%d  ", matriz_s[i][j]); 
        }
    }

    //Matriz inversa S-
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz_invesrsa[i][j] = matriz_s[j][i];
        }
        
    }
    
    //Impressão da MAtriz S- na tela
    printf("\n\n---------------- MATRIZ S- ----------------\n");
    printf("S\t");
    for(i = 0; i < 10; i++){
        printf("%c  ", vet_b[i]);
    }

    for(i = 0; i < 10; i++){
        printf("\n%d\t", vet_a[i]);
        for(j = 0; j < 10; j++){
            printf("%d  ", matriz_invesrsa[i][j]); 
        }
    }

    //Construção da matriz identidade  para validação de isomorfismo:
    for ( k1 = 0; k1 < 10; k1++)
    {
        for (k2 = 0; k2 < 10; k2++)
        {
            soma = 0;
            for (i = 0; i < 10; i++)
            {
                soma = soma + matriz_s[k1][i] * matriz_invesrsa[i][k2];
            }
            matriz_id[k1][k2] = soma;
        }
        
    }
    //Impressão da matriz identidade na tela
    printf("\n\n---------------- MATRIZ ID ----------------\n");
    printf("S\t");
    for(i = 0; i < 10; i++){
        printf("%c  ", vet_b[i]);
    }

    for(i = 0; i < 10; i++){
        printf("\n%d\t", vet_a[i]);
        for(j = 0; j < 10; j++){
            printf("%d  ", matriz_id[i][j]); 
        }
    } 
    
    //Validação ISOMORFISMO OU ISORRELAÇÃO
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            if(matriz_id[i][j] == matriz_id[i+1][j+1]){
                valida2++;
            } 
            if (i == j)
            {
                if (matriz_id[i][j] == matriz_id[i+1][j+1])
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

}