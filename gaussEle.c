#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 3
void gaussElimination(float a[N][N+1]);
void backSubstitution(float a[N][N+1], float x[N]);
void printSolution(float x[N]);
int main() {
    float a[N][N+1], x[N];
    printf("Enter coefficients of the augmented matrix row by row:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    gaussElimination(a);  // Perform Gauss Elimination
    backSubstitution(a, x);  // Perform Back Substitution to find solution
    printSolution(x);  // Print solution
    return 0;
}
void gaussElimination(float a[N][N+1]) {
    int i, j, k;
    float ratio;
    for (i = 0; i < N - 1; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!\n");
            exit(1);
        }
        for (j = i + 1; j < N; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k <= N; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}
// Function to perform back substitution
void backSubstitution(float a[N][N+1], float x[N]) {
    x[N-1] = a[N-1][N] / a[N-1][N-1];  // Solve for the last variable
    for (int i = N - 2; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] = x[i] - a[i][j] * x[j];  // Subtract known values
        }
        x[i] = x[i] / a[i][i];  // Solve for the current variable
    }
}
// Function to print the solution
void printSolution(float x[N]) {
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %0.3f\n", i + 1, x[i]);
    }
}
