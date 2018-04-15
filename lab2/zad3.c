#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int N;
    printf("Podaj N:\n");
    scanf("%d", &N);                        // pobranie dlugosci pierwszej tablicy

    int *tab1 = (int *) calloc(N, sizeof(int));  // zaalokowanie pamieci dla pierwszej tablicy

    srand(time(NULL));
    for (int i = 0; i < N; i++) {           // wypelnienie pierwszej tablicy losowymi liczbami
        tab1[i] = rand() % 58 + 55;
    }

    float *tab2 = (float *) calloc((N+1) / 2, sizeof(int));     //zaalokowanie pamieci dla drugiej tablicy

    for (int i = 0; i<(N+1) / 2; i++){                          // wypelnienie wartosci odpowiednimi srednimi
        if (2*i + 1 < N){
            tab2[i] = (tab1[2*i] + tab1[2*i+1]) / 2.0;
        }else{
            tab2[i] = tab1[2*i];                                // przepisanie ostatniej wartosci jesli tablica jest o nieparzystej dlugosci
        }
    }

    printf("tab1: ");                               // wypisanie obu tablic
    for (int i = 0; i < N; i++) {
        printf(" %d |", tab1[i]);
    }
    printf("\n");

    printf("tab2: ");
    for (int i=0; i<(N+1) / 2; i++){
        printf(" %.1f |", tab2[i]);
    }
    printf("\n");

    free(tab1);                                 // zwolnienie pamieci po obu tablicach
    free(tab2);

    return 0;
}