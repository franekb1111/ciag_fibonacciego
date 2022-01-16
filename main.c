#include <stdio.h>
#include <stdlib.h>

double fib(int n)
{
    double a = 1;
    double b = 1;
    if(n==0)
        a = 0;
    for (int i = 2; i < n; ++i)
    {
        double c = a + b;
        b = a;
        a = c;
    }
    return a;
}

int main()
{
    int n;
    int wybor;
    char s[4]; //liczba moze byc maks. trzycyfrowa, (dla wiekszych liczb nie ma sensu zwiekszac tabliczy bo traci sie dokladnosc w dalszych obliczeniach)

    //&s[0] = s

    printf("1. Oblicz wyraz ciagu Fibonacciego dla liczby n \n");
    printf("2. Oblicz wyrazy ciagu Fibonacciego z pliku tekstowego \n");
    printf("Twoj wybor: ");
    scanf("%d", &wybor);

    if(wybor == 1)
    {
       printf("Wpisz dowolna liczbe naturalna, dla ktorej chcesz obliczyc wyraz ciagu Fibonacciego: ");
       scanf("%d", &n);
       printf("Fib[%d] = %.f\n", n, fib(n));

    }
    if(wybor == 2)
    {
        FILE * plik = fopen("wyrazy.txt", "r");

        if(plik == NULL)
        {
            printf("Otwarcie pliku nieudane");
            return 1;
        }

        while (fgets(s, 4, plik) != NULL)
        {
            int liczba = atoi(s); // funkcja pomija znaki biale i zwraca int
            double f = fib(liczba);
            printf("Fib[%d] = %.f\n", liczba, f);
        }

        fclose(plik);
    }
    return 0;
}
