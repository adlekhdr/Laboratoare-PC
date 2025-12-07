//Lucrare de laborator 2

#include <stdio.h>

#define MAX 1000

int main() {
    unsigned int marimetablou = 0;

    //
    while (1) {
        printf("\nIntrodu numarul de elemente pentru tablou (max %d): ", MAX);
        int rezultat = scanf(" %u", &marimetablou);

        int c;
        while ((c = getchar()) != '\n' && c != EOF); // curatare de buffer

        if (rezultat != 1) {
            puts("Input invalid!");
            continue;
        }

        if (marimetablou == 0 || marimetablou > MAX) {
            puts("Numar invalid, incearca din nou!");
            continue;
        }

        break;
    }

    float tablou[marimetablou];

    printf("Tablou de %u elemente creat!\n", marimetablou);
    //

    for (unsigned int i = 0; i < marimetablou; i++) {
        printf("tablou[%u] = ", i);
        scanf("%f", &tablou[i]);
    }

    printf("Tablou complet:\n");
    for (unsigned int i = 0; i < marimetablou; i++) {
        printf("%.2f ", tablou[i]);
    }

    float minim = tablou[0];
    unsigned short primul = 0;
    unsigned short ultimul = 0;
    float suma_neg = 0;
    unsigned short cate_neg = 0;

    for (unsigned short i = 0; i < marimetablou; i++) {
      if (tablou[i] < minim) {
        minim = tablou[i];
        primul = ultimul = i;
      } else if (tablou[i] == minim) {
        ultimul = i;
      }

      if (tablou[i] < 0) {
        suma_neg += tablou[i];
        cate_neg++;
      }
    }

    puts("\n================");

    printf("Valoarea minima: %.2f \n", minim);
    printf("Pozitia primului element cu valoarea minima: %d\n", primul);
    printf("Pozitia ultimului element cu valoarea minima: %d\n", ultimul);

    if (cate_neg > 0)
        printf("Media elementelor negative: %.2f\n", suma_neg / cate_neg);
    else
        printf("Nu exista elemente negative in tablou.\n");

    return 0;
}