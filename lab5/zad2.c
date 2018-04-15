#include <stdio.h>
#include <stdlib.h>

struct complex{
    int re;
    int im;
};

int mycompare(const void* a, const void* b){
    struct complex* arg1 = (struct complex*)a;
    struct complex* arg2 = (struct complex*)b;
    if ((arg1->re)*(arg1->re)+(arg1->im)*(arg1->im) > (arg2->re)*(arg2->re)+(arg2->im)*(arg2->im)) return 1;
    else if ((arg1->re)*(arg1->re)+(arg1->im)*(arg1->im) < (arg2->re)*(arg2->re)+(arg2->im)*(arg2->im)) return -1;
    else return 0;
}

int main( )
{
    int N;
    printf("Podaj liczbe elementow tablicy:\n");
    scanf("%d", &N);

    struct complex *tab;
    tab = malloc(sizeof *tab*N);
    if(!tab){
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i=0; i<N; i++){
        tab[i].re = rand()%21 - 10;
        tab[i].im = rand()%21 - 10;
    }

    printf("\nTablica przed posortowaniem.\n");
    for (int i=0; i<N; i++){
        printf (" %d + %di|", tab[i].re, tab[i].im);
    }
    printf("\n");

    qsort(tab, N, sizeof(struct complex), mycompare);

    printf("\nTablica posortowana.\n");
    for (int i=0; i<N; i++){
        printf (" %d + %di|", tab[i].re, tab[i].im);
    }
    printf("\n");

    return 0;
}