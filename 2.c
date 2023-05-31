#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* oddziel_literami_W(const char* napis) {
    int n = strlen(napis);
    char* nowy_napis = (char*)malloc((2 * n + 1) * sizeof(char)); // +1 dla znaku '\0'
    int j = 0;

    for (int i = 0; i < n; i++) {
        nowy_napis[j++] = napis[i];
        
        if (islower(napis[i]) && islower(napis[i + 1])) {
            nowy_napis[j++] = 'W';
        }
    }

    nowy_napis[j] = '\0';

    return nowy_napis;
}

int main() {
    const char* napis = "doba";
    char* nowy_napis = oddziel_literami_W(napis);
    printf("Nowy napis: %s\n", nowy_napis);  // Wyświetli: Nowy napis: dobWa

    free(nowy_napis);

    return 0;
}
