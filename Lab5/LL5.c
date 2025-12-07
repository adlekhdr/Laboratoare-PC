#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citeste_sir(char *s, int dim) {
    printf("Introduceti un sir: ");
    fgets(s, dim, stdin);
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n')
        s[n-1] = '\0';
}

int este_palindrom(const char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (tolower(s[i]) != tolower(s[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}

void inverseaza_cuvintele(char *s) {
    char *cuvinte[100];
    int nr = 0;

    char *p = strtok(s, " ");
    while (p != NULL) {
        cuvinte[nr++] = p;
        p = strtok(NULL, " ");
    }

    for (int i = nr - 1; i >= 0; i--)
        printf("%s ", cuvinte[i]);
    printf("\n");
}

int prima_aparitie(const char *s, char c) {
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            return i;
    return -1;
}

int ultima_aparitie(const char *s, char c) {
    int poz = -1;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            poz = i;
    return poz;
}

int toate_aparitiile(const char *s, char c, int pozitii[]) {
    int k = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            pozitii[k++] = i;
    return k;
}

void sorteaza_cuvinte(char *s) {
    char *cuvinte[100];
    int nr = 0;

    char *p = strtok(s, " ");
    while (p != NULL) {
        cuvinte[nr++] = p;
        p = strtok(NULL, " ");
    }

    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
            if (strcmp(cuvinte[i], cuvinte[j]) > 0) {
                char *tmp = cuvinte[i];
                cuvinte[i] = cuvinte[j];
                cuvinte[j] = tmp;
            }

    for (int i = 0; i < nr; i++)
        printf("%s ", cuvinte[i]);
    printf("\n");
}

int main() {
    int alegere;
    char s[256];

    while (1) {
        printf("\n==== Meniu ====\n");
        printf("1. Verificare palindrom\n");
        printf("2. Inverseaza cuvintele\n");
        printf("3. Prima aparitie a unui caracter\n");
        printf("4. Ultima aparitie a unui caracter\n");
        printf("5. Toate aparitiile unui caracter\n");
        printf("6. Sorteaza cuvinte\n");
        printf("0. Iesire\n");
        printf("Optiunea: ");
        scanf("%d", &alegere);
        getchar();

        if (alegere == 0) break;

        if (alegere >= 1 && alegere <= 6)
            citeste_sir(s, sizeof(s));

        switch (alegere) {
            case 1:
                if (este_palindrom(s))
                    printf("Este palindrom.\n");
                else
                    printf("Nu este palindrom.\n");
                break;

            case 2:
                inverseaza_cuvintele(s);
                break;

            case 3: {
                char c;
                printf("Caracterul cautat: ");
                c = getchar();
                int p = prima_aparitie(s, c);
                if (p == -1) printf("Nu apare.\n");
                else printf("Apare prima data la indexul %d.\n", p);
            }
            break;

            case 4: {
                char c;
                printf("Caracterul cautat: ");
                c = getchar();
                int p = ultima_aparitie(s, c);
                if (p == -1) printf("Nu apare.\n");
                else printf("Apare ultima data la indexul %d.\n", p);
            }
            break;

            case 5: {
                char c;
                printf("Caracterul cautat: ");
                c = getchar();
                int pozitii[100];
                int k = toate_aparitiile(s, c, pozitii);
                if (k == 0)
                    printf("Nu exista aparitii.\n");
                else {
                    printf("Apare la pozitiile: ");
                    for (int i = 0; i < k; i++)
                        printf("%d ", pozitii[i]);
                    printf("\n");
                }
            }
            break;

            case 6:
                sorteaza_cuvinte(s);
                break;

            default:
                printf("Optiune invalida.\n");
        }
    }
    return 0;
}
