#include <stdio.h>

int main() {
    int n;
    int min = 1, max = 10;

    printf("Introdu un numar pentru tabelul de inmultire: ");
    scanf("%d", &n);

    printf("De la cât până la cât doriți acest număr înmulțit? (implicit 1->10, format: {numar minim} {numar maxim}): ");
    scanf("%d %d", &min, &max);

    printf("Tabelul de inmultire pentru %d:\n", n);

    for (int i = min; i <= max; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
