#include <stdio.h>

int slad_macierzy(int** macierz, int n) {
    int slad = 0;
    for (int i = 0; i < n; i++) {
        slad += macierz[i][i];
    }
    return slad;
}

int suma_elementow_brzegowych(int m, int n, int** macierz) {
    int suma = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                if (macierz[i][j] % 2 == 0) {
                    suma += macierz[i][j];
                }
            }
        }
    }
    return suma;
}

int main() {
    a)
    int n = 3;
    int** macierz_a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        macierz_a[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            macierz_a[i][j] = i * n + j + 1;
        }
    }
    int slad = slad_macierzy(macierz_a, n);
    printf("Slad macierzy: %d\n", slad); 

    b)
    int m = 3;
    n = 4;
    int** macierz_b = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        macierz_b[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            macierz_b[i][j] = i * n + j + 1;
        }
    }
    int suma = suma_elementow_brzegowych(m, n, macierz_b);
    printf("Suma elementow brzegowych: %d\n", suma); 

    for (int i = 0; i < n; i++) {
        free(macierz_a[i]);
    }
    free(macierz_a);

    for (int i = 0; i < m; i++) {
        free(macierz_b[i]);
    }
    free(macierz_b);

    return 0;
}
