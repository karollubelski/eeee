#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int value;
    struct element* next;
} element;

element* utworzElement(int value) {
    element* nowy = (element*)malloc(sizeof(element));
    nowy->value = value;
    nowy->next = NULL;
    return nowy;
}

element* dodajNaKoniec(element* lista, int value) {
    element* nowy = utworzElement(value);
    
    if (lista == NULL) {
        return nowy;
    }
    
    element* obecny = lista;
    while (obecny->next != NULL) {
        obecny = obecny->next;
    }
    obecny->next = nowy;
    
    return lista;
}

void zwolnijPamiec(element* lista) {
    element* obecny = lista;
    while (obecny != NULL) {
        element* nastepny = obecny->next;
        free(obecny);
        obecny = nastepny;
    }
}

element* coDrugiElement(element* lista) {
    element* nowaLista = NULL;
    
    int licznik = 1;
    element* obecny = lista;
    while (obecny != NULL) {
        if (licznik % 2 == 1) {
            nowaLista = dodajNaKoniec(nowaLista, obecny->value);
        }
        licznik++;
        obecny = obecny->next;
    }
    
    return nowaLista;
}

void wyswietlListe(element* lista) {
    element* obecny = lista;
    while (obecny != NULL) {
        printf("%d ", obecny->value);
        obecny = obecny->next;
    }
    printf("\n");
}

int main() {
    element* lista = NULL;
    
    lista = dodajNaKoniec(lista, 1);
    lista = dodajNaKoniec(lista, 5);
    lista = dodajNaKoniec(lista, 8);
    lista = dodajNaKoniec(lista, 7);
    lista = dodajNaKoniec(lista, 2);
    
    printf("Lista poczatkowa: ");
    wyswietlListe(lista);
    
    element* nowaLista = coDrugiElement(lista);
    
    printf("Nowa lista: ");
    wyswietlListe(nowaLista);
    
    zwolnijPamiec(nowaLista);
    
    return 0;
}
