/**
 * This C program takes a matrix as input, calculates its transpose, and displays both the original
 * matrix and its transpose.
 * 
 * @return The program returns 0, which indicates successful execution.
 */
#include <stdio.h>

int main(){
    int row,col,i,j;
    printf("Enter the number of row for matrix : ");
    scanf("%d",&row);
    printf("Enter the number of col for matrix : ");
    scanf("%d",&col);

    int mat[row][col],trans[col][row];

    printf("Enter the element of matrix\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d",&mat[i][j]);
        }
    }

    printf("Element of matrix\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            trans[j][i]=mat[i][j];
        }
    }

    printf("Transpose Element\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}