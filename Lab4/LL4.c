#include <stdio.h>
#include <stdlib.h>

// funcții utilitare (implementări cu pointeri)
unsigned long lungimea_textului(const char *s) {
    const char *p = s;
    while (*p) ++p;
    return (size_t)(p - s);
}

char *aloca_si_copiaza_text(const char *src) {
    size_t n = lungimea_textului(src);
    char *d = malloc(n + 1);
    if (!d) return NULL;
    char *pd = d;
    while ((*pd++ = *src++));
    return d;
}

int compara_string(const char *a, const char *b) {
    while (*a && (*a == *b)) { ++a; ++b; }
    return (unsigned char)*a - (unsigned char)*b;
}

int compara_string_lungime(const char *a, const char *b) {
    size_t len_a = lungimea_textului(a);
    size_t len_b = lungimea_textului(b);
    return (int)(len_a - len_b);
}

char *aloca_si_concatenare(const char *a, const char *b) {
    size_t la = lungimea_textului(a);
    size_t lb = lungimea_textului(b);
    char *r = malloc(la + lb + 1);
    if (!r) return NULL;
    char *p = r;
    while (*a) *p++ = *a++;
    while ((*p++ = *b++)) ;
    return r;
}

void inverseaza_text(char *s) {
    if (!s) return;
    char *l = s, *r = s;
    while (*r) ++r;
    if (r == s) return;
    --r;
    while (l < r) {
        char t = *l; *l = *r; *r = t;
        ++l; --r;
    }
}

// Adunarea a două matrice
void aduna_matrici() {
    int r, c;
    printf("Adunare matrice - introdu: randuri coloane: ");
    if (scanf("%d %d", &r, &c) != 2) return;
    int n = r * c;
    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));
    int *S = malloc(n * sizeof(int));
    if (!A || !B || !S) { printf("Eroare alocare\n"); free(A); free(B); free(S); return; }

    printf("Introdu elementele primei matrice (%d valori):\n", n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", A + i);

    printf("Introdu elementele matricei 2 (%d valori):\n", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", B + i);
    
    for (int i = 0; i < n; ++i)
        S[i] = A[i] + B[i];

    printf("Suma matricilor:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) printf("%d ", S[i * c + j]);
        printf("\n");
    }
    free(A);
    free(B);
    free(S);
}

// Înmulțirea a doua matrice
void inmultire_matrici() {
    int r, m, c;
    printf("Inmultire matrice: introdu 3 numere (r, m, c). Matricea A are r*m, iar B are m*c: ");
    if (scanf("%d %d %d", &r, &m, &c) != 3) return;
    int *A = malloc(r * m * sizeof(int));
    int *B = malloc(m * c * sizeof(int));
    int *R = malloc(r * c * sizeof(int));
    if (!A || !B || !R) {
        printf("Eroare alocare\n");
        free(A); free(B); free(R);
        return;
    }
    printf("Elementele primei matricei A (%d valori):\n", r*m);
    for (int i = 0; i < r*m; ++i) scanf("%d", A + i);
    printf("Elementele matricei a doua B (%d valori):\n", m*c);
    for (int i = 0; i < m*c; ++i) scanf("%d", B + i);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            int sum = 0;
            for (int k = 0; k < m; ++k)
                sum += A[i*m + k] * B[k*c + j];
            R[i*c + j] = sum;
        }

    printf("\nRezultatul inmultirii (randuri x coloane):\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) printf("%d ", R[i*c + j]);
        printf("\n");
    }

    free(A); free(B); free(R);
}

// Lungimea șirului
void lungime_sir() {
    char tmp[100];
    printf("Lungime sir - introdu un sir: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (fgets(tmp, sizeof(tmp), stdin)) {
        size_t len = lungimea_textului(tmp);
        if (len > 0 && tmp[len-1] == '\n') {
            tmp[len-1] = '\0';
            len--;
        }
        printf("Lungimea: %zu\n", len);
    }
}

// Copiere sir in altul
void copiaza_sir() {
    char tmp[100];
    printf("Copiere sir - introdu un sir: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(tmp, sizeof(tmp), stdin);

    char *copie = aloca_si_copiaza_text(tmp);
    if (!copie) { printf("Eroare alocare\n"); return; }
    printf("Copie: %s\n", copie);
    free(copie);
}

// Concateneaza doua siruri
void concateneaza_siruri() {
    char a[500], b[500];
    printf("Concat - sir A: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(a, sizeof(a), stdin);

    if (lungimea_textului(a) > 0 && a[lungimea_textului(a)-1] == '\n') {
        a[lungimea_textului(a)-1] = '\0';
    }

    printf("Concat - sir B: ");

    fgets(b, sizeof(b), stdin);

    if (lungimea_textului(a) > 0 && a[lungimea_textului(a)-1] == '\n') {
        a[lungimea_textului(a)-1] = '\0';
    }

    size_t len = lungimea_textului(a);
    if (len > 0 && a[len-1] == '\n') {
        a[len-1] = '\0';
    }

    char *res = aloca_si_concatenare(a, b);
    if (!res) { printf("Eroare alocare\n"); return; }
    printf("\nRezultat: %s\n", res);
    free(res);
}

// Comparare a doua siruri
void compara_siruri() {
    char a[500], b[500];
    printf("Comparare - sir 1: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(a, sizeof(a), stdin);

    printf("Comparare - sir 2: ");

    fgets(b, sizeof(b), stdin);

    int cmp = compara_string(a, b);
    if (cmp == 0) printf("Sirurile sunt egale\n");
    else if (cmp < 0) printf("Sir 1 < Sir 2\n");
    else printf("Sir 1 > Sir 2\n");
}

void compara_siruri_lungime() {
    char a[500], b[500];
    printf("Comparare - sir 1: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(a, sizeof(a), stdin);

    printf("Comparare - sir 2: ");

    fgets(b, sizeof(b), stdin);

    int cmp = compara_string_lungime(a, b);
    if (cmp == 0) printf("Sirurile sunt egale\n");
    else if (cmp < 0) printf("Sir 1 < Sir 2\n");
    else printf("Sir 1 > Sir 2\n");
}

// Inversul unui sir
void inverseaza_sir() {
    char s[1000];
    
    printf("Inverseaza - sir (fara spatii): ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(s, sizeof(s), stdin);

    inverseaza_text(s);
    printf("Sir invers: %s\n", s);
}

// Alocarea unui sir si initializare
void aloca_si_init_sir() {
    int len;
    char tmp[1000];

    printf("Alocare sir - introdu lungimea dorita: ");
    if (scanf("%d", &len) != 1) return;
    if (len < 0) { printf("Lungime invalida\n"); return; }

    printf("Introdu sir de init (max 999 caractere, fara spatii): ");
    scanf("%999s", tmp);

    char *s = malloc((size_t)len + 1);
    if (!s) { printf("Eroare alocare\n"); return; }
    int i = 0;
    for (; i < len && tmp[i] != '\0'; ++i)
        s[i] = tmp[i];
    for (; i <= len; ++i)
        s[i] = '\0';

    printf("Sir alocat si initializat: '%s'\n", s);
    free(s);
}

// Alocare tablou bidimensional + sortare randuri dupa medie
void sorteaza_randuri_dupa_media() {
    int r, c;
    printf("Sortare randuri - introdu: randuri coloane: ");
    if (scanf("%d %d", &r, &c) != 2) return;
    if (r <= 0 || c <= 0) { printf("Dimensiuni invalide\n"); return; }

    int **mat = malloc(r * sizeof(int*));
    if (!mat) { printf("Eroare alocare\n"); return; }
    for (int i = 0; i < r; ++i) {
        mat[i] = malloc(c * sizeof(int));
        if (!mat[i]) { printf("Eroare alocare rand\n"); /* eliberam ce s-a alocat */ 
            for (int k = 0; k < i; ++k) free(mat[k]);
            free(mat); return;
        }
    }

    printf("Introdu matricea, rand cu rand (valori int):\n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            scanf("%d", &mat[i][j]);

    double *medie = malloc(r * sizeof(double));
    if (!medie) { printf("Eroare alocare\n"); for (int i=0;i<r;++i) free(mat[i]); free(mat); return; }
    for (int i = 0; i < r; ++i) {
        long s = 0;
        for (int j = 0; j < c; ++j) s += mat[i][j];
        medie[i] = (double)s / c;
    }

    /* bubble sort */
    for (int i = 0; i < r-1; ++i) {
    for (int j = 0; j < r-1-i; ++j) {
        if (medie[j] > medie[j+1]) {
            double tm = medie[j]; medie[j] = medie[j+1]; medie[j+1] = tm;
            int *tp = mat[j]; mat[j] = mat[j+1]; mat[j+1] = tp;
        }
        }
    }


    printf("Matrice sortata dupa media randurilor (crescator):\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) printf("%d ", mat[i][j]);
        printf("  (media=%.2f)\n", medie[i]);
    }

    for (int i = 0; i < r; ++i) free(mat[i]);
    free(mat); free(medie);
}

// Inserare si stergere intr-un tablou unidimensional. Tabloul ocupa memorie strict numarului de elemente prezente (realloc)
void inserare_stergere_tablou() {
    int n;
    printf("Tablou unidimensional dinamic - numar elemente initial: ");
    if (scanf("%d", &n) != 1) return;
    if (n < 0) { printf("Numar invalid\n"); return; }
    int *a = NULL;
    if (n > 0) {
        a = malloc(n * sizeof(int));
        if (!a) { printf("Eroare alocare\n"); return; }
        printf("Introdu %d elemente:\n", n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    }

    int op;
    printf("Operatie - 1: insert, 2: delete: ");
    if (scanf(" %d", &op) != 1) { free(a); return; }

    if (op == 1) {
        int pos, val;
        printf("Pozitia (0..%d) si valoarea: ", n);
        scanf("%d %d", &pos, &val);
        if (pos < 0 || pos > n) { printf("Pozitie invalida\n"); free(a); return; }
        int *b = realloc(a, (n + 1) * sizeof(int));
        if (!b) { printf("Eroare realocare\n"); free(a); return; }
        a = b;
        for (int i = n; i > pos; --i) a[i] = a[i-1];
        a[pos] = val;
        n++;
    } else if (op == 2) {
        if (n == 0) { printf("Tablou gol, nu se poate sterge\n"); free(a); return; }
        int pos;
        printf("Pozitia de sters (0..%d): ", n-1);
        scanf("%d", &pos);
        if (pos < 0 || pos >= n) { printf("Pozitie invalida\n"); free(a); return; }
        for (int i = pos; i < n-1; ++i) a[i] = a[i+1];
        if (n-1 == 0) {
            free(a);
            a = NULL;
            n = 0;
        } else {
            int *b = realloc(a, (n-1) * sizeof(int));
            if (!b) { printf("Eroare realocare\n"); free(a); return; }
            a = b; n--;
        }
    } else {
        printf("Operatie necunoscuta\n");
    }

    printf("\nTablou rezultat (n=%d):\n", n);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
}

// Meniu
int main(void) {
    int opt;
    while (1) {
        printf("\n=== MENIU ===\n"
        "1 - Adunare matrice\n"
        "2 - Inmultire matrice\n"
        "3 - Lungimea sirului\n"
        "4 - Copiere sir\n"
        "5 - Concatenare siruri\n"
        "6 - Comparare siruri\n"
        "7 - Inversare sir\n"
        "8 - Alocare sir si initializare (dinamic)\n"
        "9 - Alocare tablou bidimensional + sortare randuri dupa medie\n"
        "10 - Inserare / Stergere element in tablou dinamic\n"
        "11 - Comparare siruri dupa lungime\n"
        "0  - Iesire\n"
        "Alege optiunea: ");
        if (scanf("%d", &opt) != 1) break;
        switch (opt) {
            case 1: aduna_matrici(); break;
            case 2: inmultire_matrici(); break;
            case 3: lungime_sir(); break;
            case 4: copiaza_sir(); break;
            case 5: concateneaza_siruri(); break;
            case 6: compara_siruri(); break;
            case 7: inverseaza_sir(); break;
            case 8: aloca_si_init_sir(); break;
            case 9: sorteaza_randuri_dupa_media(); break;
            case 10: inserare_stergere_tablou(); break;
            case 11: compara_siruri_lungime(); break;
            case 0: printf("La revedere!\n"); return 0;
            default: printf("Optiune invalida\n");
        }
    }
    return 0;
}