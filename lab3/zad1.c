#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 10;

void write(int tab[][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf(" %d |", tab[i][j]);
        }
        printf("\n");
    }
}

int sumaprzekatnej (int tab[][N]){ //przekatna z lewego gornego rogu do dolnego prawego
    int sum = 0;
    for(int i=0; i<N; i++){
        sum += tab[i][i];
    }
    return sum;
}

int sumapodprzekatna (int tab[][N]){
    int sum = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<i; j++){
            sum += tab[i][j];
        }
    }
    return sum;
}

int sumawszystkich (int tab[][N]){
    int sum = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            sum += tab[i][j];
        }
    }
    return sum;
}

void iloczynmacierzy(int tab1[][N], int tab2[][N], int tab3[][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int l=0; l<N; l++){
                tab3[i][j] += tab1[i][l]*tab2[l][j];
            }
        }
    }
}

int main() {

    int tab1[N][N], tab2[N][N], tab3[N][N];

    srand( time ( NULL ) );
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            tab1[i][j] = rand()%33+12;
            tab2[i][j] = rand()%33+12;
            tab3[i][j] = 0;
        }
    }

    write(tab1);
    printf("\n");
    write(tab2);
    printf("\n");
    write(tab3);
    printf("\n");

    printf("Suma elementow na przekatnej tab1 wynosi %d.\n", sumaprzekatnej(tab1));
    printf("Suma elementow na przekatnej tab2 wynosi %d.\n", sumaprzekatnej(tab2));
    printf("\n");

    printf("Suma elementow pod przekatna tab1 wynosi %d.\n", sumapodprzekatna(tab1));
    printf("Suma elementow pod przekatna tab2 wynosi %d.\n", sumapodprzekatna(tab2));
    printf("\n");

    printf("Suma wszystkich elementow tab1 wynosi %d.\n", sumawszystkich(tab1));
    printf("Suma wszystkich elementow tab2 wynosi %d.\n", sumawszystkich(tab2));
    printf("\n");

    iloczynmacierzy(tab1, tab2, tab3);
    write(tab3);
    printf("\n");

    return 0;
}