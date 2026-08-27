#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void readMatrix(int matrix[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    while (1) {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 4) {
            printf("\nExiting program...\n");
            break;
        }

        switch (choice) {
            case 1: // Addition
                printf("Enter rows and columns (e.g. 2 2): ");
                scanf("%d %d", &r1, &c1);
                
                printf("Enter second matrix rows and columns: ");
                scanf("%d %d", &r2, &c2);

                if (r1 != r2 || c1 != c2) {
                    printf("\nError: Both matrices must have the same dimensions!\n");
                    break;
                }

                printf("Enter elements of Matrix A (%d elements):\n", r1 * c1);
                readMatrix(a, r1, c1);

                printf("Enter elements of Matrix B (%d elements):\n", r2 * c2);
                readMatrix(b, r2, c2);

                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        result[i][j] = a[i][j] + b[i][j];
                    }
                }

                printf("\n--- Resulting Matrix ---\n");
                printMatrix(result, r1, c1);
                break;

            case 2: // Multiplication
                printf("Enter Matrix A rows and columns: ");
                scanf("%d %d", &r1, &c1);
                
                printf("Enter Matrix B rows and columns: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("\nError: Columns of A (%d) must equal Rows of B (%d)!\n", c1, r2);
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                readMatrix(a, r1, c1);

                printf("Enter elements of Matrix B:\n");
                readMatrix(b, r2, c2);

                // Perform multiplication
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        result[i][j] = 0; // Initialize cell
                        for (int k = 0; k < c1; k++) {
                            result[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }

                printf("\n--- Product Matrix ---\n");
                printMatrix(result, r1, c2);
                break;

            case 3: // Transpose
                printf("Enter matrix rows and columns: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter matrix elements:\n");
                readMatrix(a, r1, c1);

                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        result[j][i] = a[i][j];
                    }
                }

                printf("\n--- Transposed Matrix ---\n");
                printMatrix(result, c1, r1);
                break;

            default:
                printf("\nInvalid option! Try again.\n");
        }
    }

    return 0;
}
