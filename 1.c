#include <stdio.h>
#include <stdlib.h>

char* formatujDaneOsobowe(char* napis) {
    int dlugosc = 0;
    while (napis[dlugosc] != '\0') {
        dlugosc++;
    }
    
    char* wynik = (char*)malloc((dlugosc + 2) * sizeof(char)); // Dodajemy 2 miejsca na kropkę i znak null-terminating
    
    int i, j;
    for (i = 0, j = 0; i < dlugosc; i++, j++) {
        if (i == 0 || (i > 0 && napis[i-1] == ' ')) {
            wynik[j] = napis[i] >= 'a' && napis[i] <= 'z' ? napis[i] - ('a' - 'A') : napis[i];
        } else if (napis[i] == ' ') {
            wynik[j] = '.';
            j++;
            wynik[j] = napis[i+1] >= 'a' && napis[i+1] <= 'z' ? napis[i+1] - ('a' - 'A') : napis[i+1];
            i++;
        } else {
            wynik[j] = napis[i] >= 'A' && napis[i] <= 'Z' ? napis[i] + ('a' - 'A') : napis[i];
        }
    }
    
    wynik[j] = '\0';
    
    return wynik;
}

int main() {
    char napis[] = "KAMIL NOWAK";
    
    printf("Dane osobowe: %s\n", napis);
    
    char* wynik = formatujDaneOsobowe(napis);
    
    printf("Sformatowane dane osobowe: %s\n", wynik);
    
    free(wynik);
    
    return 0;
}
