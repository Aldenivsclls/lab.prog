//questao 1
// mario less
#include <stdio.h>
#include <cs50.h>

int main () {
    
    int alt;
    do {
    alt= get_int ("Altura: ");
    }
    while (alt < 1 || alt > 8);
    
    for (int lin = 0; lin < alt; lin++) {
        for (int esp = 0; esp < alt - lin - 1; esp++){
            printf(" ");
        }
        for(int col =0; col <= lin; col++) {
        printf("#");
        }
        printf("\n");
    }
}