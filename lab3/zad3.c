#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// zadanie rozwiazane metoda LU

const double eps = 1e-12;

bool ludist (int N, double **tab){
    int k,i,j;
    for (k=0; k<N-1; k++){
        if (fabs(tab[k][k]) < eps) return false;

        for(i=k+1; i<N; i++){
            tab[i][k] /= tab[k][k];
        }

        for(i=k+1; i<N; i++){
            for(int j=k+1; j<N; j++){
                tab[i][j] -= tab[i][k] * tab[k][j];
            }
        }
    }

    return true;
}

bool lusolve (int n, double **tab1, double *tab2, double *tab3){
    int i, j;
    int s;
    tab3[0] = tab2[0];

    for (i=1; i<n; i++){
        s = 0;
        for (j=0; j<i; j++) s += tab1[i][j] * tab3[j];

        tab3[i] = tab2[i] - s;
    }

    if(fabs(tab1[n-1][n-1]) < eps) return false;

    tab3[n-1] /= tab1[n-1][n-1];

    for (i=n-2; i>=0; i--){
        s = 0;
        for (int j=i+1; j<n; j++) s += tab1[i][j] * tab3[j];

        if(fabs(tab1[i][i]) < eps) return false;

        tab3[i] = (tab3[i] - s) / tab1[i][i];
    }

    return true;
}


int main() {
    int N;
    printf ("Podaj rzad rownania:\n");
    scanf ("%d", &N);

    double **arr2dA = (double**)calloc(N, sizeof(double*));
    printf("Podaj kolejne wierwsze macierzy wspolczynników:\n");
    for (int i=0; i<N; i++){
        arr2dA[i] = (double*)calloc(N, sizeof(double));
        for (int j=0; j<N; j++){
            scanf("%lf", &arr2dA[i][j]);
        }
    }

    double *arr2dB = (double*)calloc(N, sizeof(double));
    printf("Podaj macierz wyrazow wolnych:\n");
    for (int i=0; i<N; i++){
        scanf("%lf", &arr2dB[i]);
    }

    printf("\nTwoje dane wejsciowe:\n");
    printf("Macierz A:\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf(" %lf |", arr2dA[i][j]);
        }
        printf("\n");
    }

    printf("Macierz B:\n");
    for (int i=0; i<N; i++){
        printf(" %lf |", arr2dB[i]);
        printf("\n");
    }

    double *arr2dX = (double*)calloc(N, sizeof(double));

    if (ludist(N, arr2dA) && lusolve(N, arr2dA, arr2dB, arr2dX)) {
        printf("\nTwoje dane wyjsciowe:\n");
        for (int i=0; i<N; i++){
            printf(" %lf |", arr2dX[i]);
            printf("\n");
        }
    } else {
        printf("DZIELNIK ZERO\n");
    }

    for (int i=0; i<N; i++) free(arr2dA[i]);
    free(arr2dA);
    free(arr2dB);
    free(arr2dX);

    return 0;
}