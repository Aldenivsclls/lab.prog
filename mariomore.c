//  ALUNO: ANTONIO ALDENI ALVES VASCONCELOS FILHO
//  MATRÍCULA: 20212045050541
//  https://github.com/Aldenivsclls
//  questão 2
//  mario more
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int user_input;
    do
    {
        user_input = get_int("Altura: ");
    }
    while(user_input<1 || user_input>8);

    for (int z = user_input; z > 0; z--)
    {
        for (int b = 1; b < z; b++)
        {
            printf(" ");
        }
        for (int b = 0;b<(user_input-z+1);b++)
        {
            printf("#");
        }
        printf("  ");
        for (int b = 0;b<(user_input-z+1);b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
