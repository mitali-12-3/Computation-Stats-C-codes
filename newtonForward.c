#include <stdio.h>
#define SIZE 10
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}
int main() {
    float x[SIZE], y[SIZE][SIZE];
    int n;
    float a, h, u, sum;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }
    for (int j = 1; j <= n-1; j++) {
        for (int i = 0; i <= n -1- j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%f", y[i][j]);
        }
        printf("\n");
    }
    
    printf("\nEnter the value of x for interpolation: ");
    scanf("%f", &a);
    h = x[1] - x[0]; //step length
    u = (a - x[0]) / h;
    sum = y[0][0];
    for (int i = 1; i < n; i++) {
        float term = u;
        for (int j = 1; j < i; j++) {
            term *= (u - j);
        }
        sum += (term * y[0][i]) / factorial(i);
    }
    printf("\nInterpolated value at x = %f is %f\n", a, sum);
    return 0;
}
