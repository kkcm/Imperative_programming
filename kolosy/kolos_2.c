#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct circle {
    char kolor[20];
    double x;
    double y;
    double r;
};

int mycompare(struct circle *a, struct circle *b){

    struct circle *orderA = (struct circle *)a;
    struct circle *orderB = (struct circle *)b;

    int rc;
    rc = strcmp(orderA->kolor, orderB->kolor);

    if (rc == 0){
        if (( orderA->r - orderB->r ) > 0) return 1;
        else if (( orderA->r - orderB->r ) < 0) return -1;
        else return 0;
    }
    return rc;
}

int liczkolka(struct circle *list, int length){
    int counter = 1;
    for (int i=1; i<length; i++ ){
        if(strcmp(list[i-1].kolor, list[i].kolor)!=0){
            counter++;
        }
    }
    return counter;
}

void ustawarrayilenw (struct circle** array, int lw, struct circle* list, int length, int *lenw){
    int i=0;
    array[0] = &list[0];
    lenw[0]=1;
    for (int j = 1; j<length; j++){
        if(strcmp(list[j-1].kolor, list[j].kolor)!=0){
            i++;
            array[i] = &list[j];
        }
        lenw[i]++;
    }
}


int main() {

    printf ("Podaj liczbe kolek.\n");
    int N=0;
    scanf ("%d", &N);

    while (N<=0){
        printf ("Nie podales odpowiedniej liczby kolek, zrob to teraz.\n");
        scanf ("%d", &N);
    }

   struct circle *listakolek = (struct circle*)calloc(N, sizeof(struct circle));

   printf ("Podaj opisy kolek.\n");
    for (int i=0; i<N; i++){
        scanf("%s", listakolek[i].kolor);
        scanf("%lf", &listakolek[i].x);
        scanf("%lf", &listakolek[i].y);
        scanf("%lf", &listakolek[i].r);
    }

    printf ("Podaj kolor do wydrukowania.\n");
    char kolordowydrukowania[20];
    scanf("%s", kolordowydrukowania);

    qsort(listakolek, N, sizeof(struct circle), mycompare);

    int lw = liczkolka(listakolek, N);

    struct circle **array_2 = (struct circle**)calloc(lw, sizeof(struct circle*));
    int *lenw = (int*)calloc(lw,sizeof(int));

    ustawarrayilenw(array_2, lw, listakolek, N, lenw);

    int i;
    for(i=0; i<lw; i++) {
        if (strcmp(array_2[i]->kolor, kolordowydrukowania) == 0){
            printf("Zaczynam wypisywac kolka o kolorze %s.\n", kolordowydrukowania);
            for (int j=0; j<lenw[i]; j++){
                printf("kolor = %s, x = %f, y = %f, r = %f \n", (array_2[i]+j)->kolor, (array_2[i]+j)->x,
                       (array_2[i]+j)->y, (array_2[i]+j)->r);
            }
        }
    }
    free (listakolek);
    free (array_2);
    free(lenw);
   return 0;
}

