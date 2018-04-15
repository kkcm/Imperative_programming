#include <stdio.h>
#include <stdlib.h>

int main (void){
        int n, m;
        scanf ("%d", &n);
        if ( n < 3 || n > 1000){
                printf ("zla dana, odpal program od poczatku n\n");
                return 1;
        }
        scanf ("%d", &m);

        int **tab = (int**)calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++) {
                 tab[i] = (int*)calloc(n, sizeof(int));
                 if (tab[i] == NULL) {
                         printf("blad, brak PAO\n");
                         return 1;
                 }
        }

        for (int i=0; i<m; i++){
                int a, b;
                scanf ("%d", &a);
                if ( a < 1 || a > n){
                        printf ("zla dana, odpal program od poczatku n\n");
                       return 1;
                }
                scanf ("%d", &b);
                if ( b < 1 || b > n || b < a){
                         printf ("zla dana, odpal program od poczatku n\n");
                         return 1;
                }
        tab[a-1][b-1] = 1;
        }

        for (int i=0; i<n; i++) tab[i][i] = 22;


        int licznik = 0;

        for (int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                int zmienna = tab[i][j];
                int poz = j;
                for (int x = j+1; x<n; x++){
                        if(tab[i][x] == zmienna){
                                for (int y=i; y<n-1; y++){
                                        if (tab[y][x] == zmienna){
                                                if ( y == poz){
                                                         licznik++;
                                                }
                                        }
                                }
                        }
                }
                }
        }


        printf("%d\n", licznik);

         for (int i = 0; i < n; i++) free(tab[i]);
         free(tab);

return 0;
}

