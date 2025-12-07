#include <stdio.h>

#define MAX 1000

int main() {
  int randuri, coloane;

  while (1) {
    printf("Introduceti numerele pentru rândurile și coloanele tabloului, "
           "exemplu: 4 5, max %d: ",
           MAX);
    int rezultat = scanf("%d %d", &randuri, &coloane);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (rezultat != 2) {
      puts("Input invalid!");
      continue;
    }

    if (randuri < 0 || coloane < 0 || randuri > MAX || coloane > MAX) {
      puts("Număr invalid, încearcă din nou!");
      continue;
    }
    break;
  }

  int a[randuri][coloane];

  puts("Introduceți elementele tabloului, pentru fiecare rând:\n");
  for (int i = 0; i < randuri; i++) {
    for (int j = 0; j < coloane; j++) {
      int valoare = scanf("%d", &a[i][j]);
      if (valoare != 1) {
        puts("Format Invalid");
        return 2;
      }
    }
  }

  puts("\n<==========================>");
  puts("\nTabloul introdus este:\n");
  for (int i = 0; i < randuri; i++) {
    for (int j = 0; j < coloane; j++) {
      printf("%5d ", a[i][j]);
    }
    puts("\n\n");
  }
  puts("<==========================>\n");

  // 1. Suma elementelor negative din coloanele impare
  int suma_negative = 0;
  for (int j = 0; j < coloane; j++) {
    if (j % 2 != 1) {
      for (int i = 0; i < randuri; i++) {
        if (a[i][j] < 0) {
          suma_negative += a[i][j];
        }
      }
    }
  }
  printf("Suma elementelor negative din coloanele impare: %d\n", suma_negative);

  // 2. Produsul elementelor pozitive mai mici ca media diagonalei principale
  int nr_dominant = (randuri < coloane) ? randuri : coloane;

  int suma_diagonala = 0;
  for (int i = 0; i < nr_dominant; i++) {
    suma_diagonala += a[i][i];
  }

  double media = (double)suma_diagonala / nr_dominant;

  printf("Media diagonalei: %.2lf \n", media);

  long long produs = 1;
  short nr_existente = 0;
  for (int i = 0; i < randuri; i++) {
    for (int j = 0; j < coloane; j++) {
      if (a[i][j] > 0 && a[i][j] < media) {
        produs *= a[i][j];
        nr_existente += 1;
      }
    }
  }

  (nr_existente)
      ? printf(
            "Produsul a %d elemente pozitive mai mici decât media diagonalei "
            "principale = %lld\n",
            nr_existente, produs)
      : puts("Nu există elemente pozitive mai mici decât media diagonalei "
             "principale.\n");

  return 0;
}


