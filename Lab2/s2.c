#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    puts("Introdu un caracter: ");
    scanf(" %c", &c);

    if (isalpha(c)){
        puts("Caracterul introdus este din alfabet");
    }
    else if (isdigit(c))
        puts("Caracterul introdus este cifră");
    else
        puts("Caracterul introdus nu este nici cifră, nici din alfabet");
    
    return 0;
}