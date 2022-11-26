//  ALUNO: ANTONIO ALDENI ALVES VASCONCELOS FILHO
//  MATRÍCULA: 20212045050541
//  https://github.com/Aldenivsclls
//  cifra de cesar
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool digitos(string text);
char girar(char p, int k);

int main(int argc, string argv[])
{
    int k, tam;
    string plaintext;
    if (argc != 2 || !digitos(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    k = atoi(argv[1]);
    plaintext = get_string("plaintext: ");
    tam = strlen(plaintext);
    char ciphertext[tam + 1];
    for (int i = 0; i< tam; i++)
    {
        ciphertext[i] = girar(plaintext[i], k);
    }
    ciphertext[tam] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool digitos(string text)
{
    int tam;

    tam = strlen(text);

    for (int i = 0; i < tam; i++){
        if (!isdigit(text[i])) {
            return false;
        }
    }
    return true;
}
char girar(char p, int k)
{
    char pi, c, ci;
    if (isupper(p)) {
        pi = p - 65;
        ci = (pi + k)%26;
        c = ci + 65;
    }
    else if (islower(p)) {
        pi = p - 97;
        ci = (pi + k)%26;
        c = ci + 97;
    }
    else {
        return p;
    }
    return c;

}