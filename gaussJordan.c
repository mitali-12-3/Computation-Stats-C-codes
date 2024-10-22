#include<stdio.h>
#include<math.h>
#define N 3
void gaussjordan(float a[N][N+1]);
void solveSystem(float a[N][N+1], float x[N]);
void printSolution(float x[N]);
int main() {
    float a[N][N+1], x[N]; 
    printf("Enter coefficients of Augmented Matrix (row by row):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }
    gaussjordan(a); 
    solveSystem(a, x); // Solve for the variables using back substitution
    printSolution(x); // Print the solution
    return 0;
}
void gaussjordan(float a[N][N+1]) {
    int i,j,k;
    float ratio;
    for (i = 0; i < N; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error! Division by zero.\n");
            return;
        }
        for (j = 0; j < N; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k <= N; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
}
void solveSystem(float a[N][N+1], float x[N]) {
    for (int i = 0; i < N; i++) {
        x[i] = a[i][N] / a[i][i];
    }
}
void printSolution(float x[N]) {
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %0.3f\n", i+1, x[i]);
    }
}
