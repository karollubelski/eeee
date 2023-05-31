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

element* usunSrodkowe(element* lista) {
    if (lista == NULL) {
        return NULL;
    }
    
    element* slow = lista;
    element* fast = lista;
    element* prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    if (prev == NULL) {
        // Usuwanie pierwszego elementu
        element* temp = lista;
        lista = lista->next;
        free(temp);
    } else {
        // Usuwanie środkowego elementu/y
        prev->next = slow->next;
        free(slow);
    }
    
    return lista;
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
    
    lista = dodajNaKoniec(lista, 5);
    lista = dodajNaKoniec(lista, 8);
    lista = dodajNaKoniec(lista, 9);
    lista = dodajNaKoniec(lista, 1);
    lista = dodajNaKoniec(lista, 6);
    
    printf("Lista poczatkowa: ");
    wyswietlListe(lista);
    
    element* nowaLista = usunSrodkowe(lista);
    
    printf("Nowa lista: ");
    wyswietlListe(nowaLista);
    
    zwolnijPamiec(nowaLista);
    
    return 0;
}
