#include <stdio.h>

int power(int number, int exp ){        //funkcja pomocnicza obliczajaca potege danej liczby
    int res = 1;
    while(exp != 0){
        res *= number;
        exp--;
    }
    return res;
}


int main() {
    int number, sys;
    printf("Podaj liczbe:\n");
    scanf("%d", &number);
    printf("Wczytana liczba to %d.\n",number);
    printf("Podaj podstawe systemu liczbowego:\n");
    scanf("%d", &sys);
    printf("Wczytana podstawa systemu liczbowego to %d.\n",sys);

    int tmp = number;
    int i=0;
    while(tmp != 0){            // pętla wyznaczajaca liczbe cyfr w danej liczbie
        tmp /= sys;
        i++;
    }
    printf("Podales liczbe %d-cyfrowa.\n", i);

    int sum = 0;
    tmp = number;

    while(tmp != 0){                    // petla sumujaca potegi kazdej cyfry liczby w danym systemie liczbowym
        sum += power(tmp % sys, i);
        tmp /= sys;
    }

    printf("Twoja otrzymana suma wynosi: %d.\n", sum);

    if(number == sum){                                            // sprawdzenie czy otrzymana suma jest rowna podanej liczbie
        printf("%d jest liczba narcystyczna w systemie liczbowym o podstawie %d.\n", number, sys);
    } else{
        printf("%d nie jest liczba narcystyczna w systemie liczbowym o podstawie %d.\n", number, sys);
    }

    return 0;
}