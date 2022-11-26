//  ALUNO: ANTONIO ALDENI ALVES VASCONCELOS FILHO
//  MATRÍCULA: 20212045050541
//  https://github.com/Aldenivsclls
//  cifra de substituição
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_char(string key);

int main(int argc, string argv[])
{
    int comprimento, index;
    string plaintext;
    if (argc != 2) {
        printf("Uso: ./substitution key\n");
        return 1;
    }
    if (!check_char(argv[1])) {
        printf("A chave deve conter 26 caracteres exclusivos\n");
        return 1;
    }
    plaintext = get_string("plaintext: ");
    comprimento = strlen(plaintext);
    string key = argv[1];
    char ciphertext[comprimento + 1];
    for (int i = 0; i< comprimento; i++) {
        if (islower(plaintext[i])) {
            index = plaintext[i] -97;
            ciphertext[i] = key[index];
                if (isupper(ciphertext[i])) {
                    ciphertext[i] += 32;
                }
        }
        else if (isupper(plaintext[i])) {
            index = plaintext[i] - 65;
            ciphertext[i] = key[index];
                if (islower(ciphertext[i])) {
                    ciphertext[i] -=32;
                }
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[comprimento] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}

bool check_char(string key)
{
    int comprimento;

    comprimento = strlen(key);

    if (comprimento != 26) {
        return false;
    }
    for (int i = 0; i < comprimento; i++) {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < comprimento; i++) {
        if (!isalpha(key[i])) {
            return false;
        }
        for (int j = i+1; j< comprimento; j++) {
            if (key[i] == key[j]) {
                return false;
            }
        }
    }
    return true;
}