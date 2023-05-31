#include <stdio.h>

void odwroc_kolumny(int tab[][3], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int start = 0;
        int end = rows - 1;
        
        while (start < end) {
            int temp = tab[start][j];
            tab[start][j] = tab[end][j];
            tab[end][j] = temp;
            
            start++;
            end--;
        }
    }
}

void przesun_kolumny(int tab[][3], int rows, int cols) {
    int temp_col[3];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp_col[j] = tab[i][j];
        }
        
        for (int j = 0; j < cols; j++) {
            int new_col = (j + 2) % cols;
            tab[i][new_col] = temp_col[j];
        }
    }
}

void wyswietl_tablice(int tab[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tab1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows1 = 3;
    int cols1 = 3;
    
    printf("Przed odwróceniem kolumn:\n");
    wyswietl_tablice(tab1, rows1, cols1);
    
    odwroc_kolumny(tab1, rows1, cols1);
    
    printf("Po odwróceniu kolumn:\n");
    wyswietl_tablice(tab1, rows1, cols1);
    
    int tab2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows2 = 3;
    int cols2 = 3;
    
    printf("Przed przesunięciem kolumn:\n");
    wyswietl_tablice(tab2, rows2, cols2);
    
    przesun_kolumny(tab2, rows2, cols2);
    
    printf("Po przesunięciu kolumn:\n");
    wyswietl_tablice(tab2, rows2, cols2);
    
    return 0;
}
