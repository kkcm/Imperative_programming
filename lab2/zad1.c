#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char readarg (char *tab, char number[8]){
    char min=0;
    int correct = 0;
    printf("Podaj %s liczbe: \n", number);
    scanf ("%s", tab);
    if (tab[0] == '-'){
        min = 1;
    }
    for (int i=min; i!=strlen(tab); i++){               // sprawdzenie czy podany znak jest liczba
        if(tab[i] < 48 || tab[i] > 57){
            correct = 1;
        }
    }
    if (tab[0]==48 || (tab[0]==49 && tab[1]==48)){      // sprawdzenie czy pierwsza cyfra nie jest zerem
        correct = 1;
    }
    if (strlen(tab)-min > 100){                         // sprawdzenie czy liczba nie jest dluzsza niz 100 znakow
        correct = 1;
    }
    if(correct==1){                                     // sprawdzenie czy wykryto blad
        printf("\nNIEPOPRAWNE DANE!\n");
        min = readarg(tab,number);                      // ponowne wczytywanie liczby
    }
    return min;
}

void convert (char *tab, char min){
    int i=0;
    if (min == 1){
        i = 1;
    }
    while (tab[i] != 0){
        tab [i] -= 48;
        i++;
    }
}

void write (char *tab, int length){
    for (int i=length; i>0; i--){
        tab[i] +=48;
    }
    if(tab[0] == 0){
        printf("%s",tab+1);
    } else{
        tab[0] += 48;
        printf("Twoj wynik wynosi: %s.\n", tab);
    }
}


int main(void) {
    char tab1[102];         // 100 cyfr + znak + NULL na koniec stringa
    char tab2[102];         // 100 cyfr + znak + NULL na koniec stringa
    char *result;           //tablica wynikowa
    char min1, min2;        //zmienne okreslajace znak (1 dla -, 0 dla +)

    int l,k;                // dlugosc tablicy wynikowej
    int x,y;                // długość wczytanych słów

    printf("Program oblicza iloczyn dwoch liczb calkowitych.\n");
    min1 = readarg (tab1, "pierwsza");
    min2 = readarg (tab2, "druga");

    x = strlen (tab1);
    y = strlen (tab2);

    convert (tab1, min1);
    convert (tab2, min2);

    l = x+y-min1-min2;      // dlugosc wyniku to suma dlugosci liczb minus ewentualne znaki odejmowania
    x -= 1; y -= 1;         // pozycja ostatniego znaku w tablicy w danym slowie

    result = (char*)calloc(l, sizeof(char));

    for (int i=y; i>=min2; i--) {                       // mnozymy od konca liczby, czyli tak jak pisemnie
                                                        // w tej petli bierzemy cyfry z drugiej liczby
        k=l-1;                                          // numer ostatniego znaku w tablicy wynikowej
        for (int j=x;j>=min1;j--) {
                                                         // w tej petli bierzemy cyfry z pierwszej liczby
            result[k-y+i] += ((tab1[j])*(tab2[i]));
            while (result[k-y+i]>9) {                   // przeniesienie czesci dziesietnych
                result[k-y+i]-=10;
                result[k-y+i-1]+=1;
            }
            k--;                                        // przesuniecie sie w tablicy wynikowej o jeden w lewo
        }
    }

    if (((min1 == 1) && (min2 == 0)) || ((min1== 0) && (min2 == 1))){
        printf ("-");
    }
    write(result, l-1);
    free (result);

    return 0;
}