//

#include<stdio.h>

int main (void)
{
  int numerolin, numerocol,lin, col, conta = 1;

  printf("Informe o numero de linhas da matriz: ");
  scanf("%d", &numerolin);
  printf("Informe o numero de colunas da matriz: ");
  scanf("%d", &numerocol);

  float matriz[numerolin][numerocol];
  float matriz2[numerolin][numerocol];
  float matriz3[numerolin][numerocol];
  float t = 0.0;

  printf ("\nInforme os valores para os elementos da primeira matriz \n\n");

  for (lin=0; lin<numerolin; lin++)
    for (col=0; col<numerocol; col++)
    {
      printf ("\nElemento[%d][%d] = ", lin, col);
      scanf ("%f", &matriz[lin][col]);
    }

  printf ("\nInforme os valores para os elementos da segunda matriz \n\n");

  for (lin=0; lin<numerolin; lin++)
    for (col=0; col<numerocol; col++)
    {
      printf ("\nElemento[%d][%d] = ", lin, col);
      scanf ("%f", &matriz2[lin][col]);
    }

  printf("\nmatriz 1:\n\n");

  for (lin=0; lin<numerolin; lin++)
  {
    for (col=0; col<numerocol; col++)
    {
      printf ("%0.1f", matriz[lin][col]);
      printf(" ");
    }
    printf("\n");
  }

  printf("\nmatriz 2:\n\n");

  for (lin=0; lin<numerolin; lin++)
  {
    for (col=0; col<numerocol; col++)
    {
      printf ("%0.1f", matriz2[lin][col]);
      printf(" ");
    }
    printf("\n");
  }

  printf("\nusando (1-t*A+t*B): \n\n");
    while (t<1.1)
    {
        printf("matriz %d com t=%0.1f:\n",conta,t);
        for (lin=0; lin<numerolin; lin++)
        {
            for (col=0; col<numerocol; col++)
            {
                matriz3[lin][col] = ((1-t)*matriz[lin][col]+t*matriz2[lin][col]);
                printf ("%0.1f", matriz3[lin][col]);
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
        t=t+0.1;
        conta++;
    }
    return(0);
}