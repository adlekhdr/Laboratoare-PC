#include <limits.h>

#include <stdio.h>

#include <stdlib.h>
#include <math.h>
#include <float.h>

int a, b;
float f;
char string[8] = "Salut!";

int main() {
    printf("%s\n", string);

    printf("Introdu un număr ÎNTREG pentru a: ");
    scanf("%d", &a);
    
    printf("Introdu un număr ÎNTREG pentru b: ");
    scanf("%d", &b);

    printf("Introdu un număr REAL pentru f: ");
    scanf("%f", &f);

    printf("\n>>>> Operatori aritmetici\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %f\n", (float)a / b);
    printf("a %% b = %d\n", a % b);

    printf("a - b * a + b = %d\n", a - b * a + b);
    printf("(a - b) * a + b = %d\n", (a - b) * a + b);

    printf("++a = %d\n", ++a);
    printf("--b = %d\n", --b);

    printf("\n resetăm :) \n");

    printf("\n a-- = %d\n", a--);
    printf(" b++ = %d\n", b++);

    printf("acum a = %d și b = %d, ca la început! \n", a, b);

    printf("\n>>>> Funcții matematice\n");
    printf("sqrt(f) = %.4f\n", sqrt(f));
    printf("log(f) = %.4f\n", log(f));
    printf("pow(f, 2) = %.4f\n", pow(f, 2));
    printf("pow(f, a+b) = %.4f\n", pow(f, a+b));
    printf("round(f) = %.4f\n", roundf(f));
    printf("/* int */ round(f) = %d\n", (int)roundf(f));
    printf("abs(a), abs(b) = %d %d\n", abs(a), abs(b));

    printf("\n>>>> Operatori logici\n");
    printf("a > b : %d\n", (a > b));
    printf("a < b : %d\n", (a < b));
    printf("a == b: %d\n", (a == b));
    printf("a != b: %d\n", (a != b));
    printf("(a > 0 && b > 0) : %d\n", (a > 0 && b > 0));
    printf("(a > 0 || b > 0) : %d\n", (a > 0 || b > 0));
    printf("(a %% 2) ? printf(\"> Impar\") : printf(\"> Par\") => %s\n", (a % 2) ? "Impar" : "Par");
    

    // Secția cu tipuri de date primitive și limite

    long long llong1 = LLONG_MAX; // se poate nota și ca long long int
    long double ldouble2 = LDBL_MAX;

    unsigned int ua = UINT_MAX;
    short s = SHRT_MAX;
    long la = LONG_MAX;

    double d = DBL_MAX;

    char c = 'b';

    ret: printf("\n Dorești să vezi secțiunea cu tipuri de date? (y/Y = da, n/N = nu):");

    scanf(" %c", &c);

    if (c == 'n' || c == 'N') {
        printf("\n Adios! \n");
        return 0;
    } else if (c != 'y' && c != 'Y'){
        printf("Opțiune invalidă.\n");
        goto ret;
    }

    printf("\n>>>> Tipuri de date\n\n");

    // int
    printf("int\n");
    printf("Dimensiune: %zu bytes\n", sizeof(a));
    printf("Limite: de la %d la %d\n\n", INT_MIN, INT_MAX);

    // unsigned int
    printf("unsigned int\n");
    printf("Dimensiune: %zu bytes\n", sizeof(ua));
    printf("Limite: de la 0 la %u\n\n", ua);

    // short
    printf("short\n");
    printf("Dimensiune: %zu bytes\n", sizeof(s));
    printf("Limite: de la %hd la %hd\n\n", SHRT_MIN, SHRT_MAX);

    // unsigned short
    printf("unsigned short\n");
    printf("Dimensiune: %zu bytes\n", sizeof(unsigned short));
    printf("Limite: de la 0 la %hu\n\n", USHRT_MAX);

    // long int
    printf("long int\n");
    printf("Dimensiune: %zu bytes\n", sizeof(la));
    printf("Limite: de la %ld la %ld\n\n", LONG_MIN, LONG_MAX);

    // long long
    printf("long long int\n");
    printf("Dimensiune: %zu bytes\n", sizeof(llong1));
    printf("Limite: de la %lld la %lld\n\n", LLONG_MIN, LLONG_MAX);

    // float
    printf("float\n");
    printf("Dimensiune: %zu bytes\n", sizeof(f));
    printf("Limite: de la %e la %e\n\n", FLT_MIN, FLT_MAX);

    // double
    printf("double\n");
    printf("Dimensiune: %zu bytes\n", sizeof(d));
    printf("Limite: de la %e la %e\n\n", DBL_MIN, DBL_MAX);

    // long double
    printf("long double\n");
    printf("Dimensiune: %zu bytes\n", sizeof(ldouble2));
    printf("Limite: de la %Le la %Le\n\n", LDBL_MIN, LDBL_MAX);

    // char
    printf("char\n");
    printf("Dimensiune: %zu bytes\n", sizeof(c));
    printf("Limite: de la %d la %d\n\n", CHAR_MIN, CHAR_MAX);

    // unsigned char
    printf("unsigned char\n");
    printf("Dimensiune: %zu bytes\n", sizeof(unsigned char));
    printf("Limite: de la 0 la %u\n\n", UCHAR_MAX);

    return 0;
}
