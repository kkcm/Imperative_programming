#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, r;
    printf("Podaj rozmiar tablicy.\n");
    scanf("%d", &N);
    printf("Podaj promien.\n");
    scanf("%d", &r);

    printf("Podaj kolejne wartosci elementow tablicy.\n");
    int **arr2d = (int**)calloc(N, sizeof(int*));
    for (int i=0; i<N; i++){
        arr2d[i] = (int*)calloc(N, sizeof(int));
        for (int j=0; j<N; j++){
            scanf("%d", &arr2d[i][j]);
        }
    }

    printf("\nTwoje dane wejsciowe:\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf(" %d |", arr2d[i][j]);
        }
        printf("\n");
    }

    int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

    int **arr2dd = (int**)calloc(N, sizeof(int*));
    for (int i=0; i<N; i++){
        arr2dd[i] = (int*)calloc(N, sizeof(int));
        for(int j=0; j<N; j++){
            for(int l=0; l<9; l++){
                if((i+dx[l] >= 0) && (i+dx[l] < N) && (j+dy[l] >= 0) && (j+dy[l] < N) && (arr2d[i+dx[l]][j+dy[l]] == 1))
                    arr2dd[i][j]++;
            }
        }
    }

    printf("\nTwoje dane wyjsciowe:\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf(" %d |", arr2dd[i][j]);
        }
        printf("\n");
    }

    return 0;
}