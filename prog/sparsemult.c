// Sparse matrix multiplication

#include <stdio.h>
void enterData(int mat1[][10], int mat2[][10], int r1, int c1, int r2, int c2){
    printf("\nEnter elements of matrix 1:\n");
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c1; ++j){
            printf("Enter elements a%d%d: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");
    for(int i = 0; i < r2; ++i){
        for(int j = 0; j < c2; ++j){
            printf("Enter elements b%d%d: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }
}
void multiplyMatrices(int mat1[][10], int mat2[][10], int mult[][10], int r1, int c1, int r2, int c2){
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c2; ++j){
            mult[i][j] = 0;
        }
    }
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c2; ++j){
            for(int k=0; k<c1; ++k){
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void display(int mult[][10], int r1, int c2){
    printf("\nOutput Matrix:\n");
    for(int i = 0; i < r1; ++i){
        for(int j = 0; j < c2; ++j){
            printf("%d  ", mult[i][j]);
            if(j == c2 - 1)
                printf("\n\n");
        }
    }
}

int main()
{
    int mat1[10][10], mat2[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    printf("Enter rows and column for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and column for second matrix: ");
    scanf("%d %d", &r2, &c2);

    // If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
    while (c1 != r2)
    {
        printf("Error! column of first matrix not equal to row of second.\n");
        printf("Enter rows and column for first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and column for second matrix: ");
        scanf("%d%d", &r2, &c2);
    }

    // Function to take matrices data
        enterData(mat1, mat2, r1, c1, r2, c2);

        // Function to multiply two matrices.
        multiplyMatrices(mat1, mat2, mult, r1, c1, r2, c2);

        // Function to display resultant matrix after multiplication.
        display(mult, r1, c2);

    return 0;
}