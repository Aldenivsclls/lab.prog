//  ALUNO: ANTONIO ALDENI ALVES VASCONCELOS FILHO
//  MATRÍCULA: 20212045050541
//  https://github.com/Aldenivsclls
//  eleições majoritárias plurality

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAXI 9

typedef struct
{
    string name;
    int votes;
}
candidate;
candidate candidates[MAXI];
int candidate_count;
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Uso: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAXI)
    {
        printf("Numero maximo de candidatos e: %i\n", MAXI);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");


    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Voto invalido.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
void print_winner(void)
{
    int maximum_vote = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[i].votes == maximum_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}