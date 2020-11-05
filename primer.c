#include <stdio.h>

#define PETICIO "Escriga un nombre sencer i li diré si és o no un nombre primer:"
#define AFIRMATIU "El nombre és primer"
#define NEGATIU "El nombre NO és primer"

int main()
{
  int nombre,divisor=1;

  printf("%s", PETICIO);
  scanf("%i", &nombre);

  if (nombre > 1)
    divisor=2;
  while (nombre%divisor!=0){
    divisor++;
  }
  if (divisor != nombre)
    printf("%s\n", NEGATIU);
  else
    printf("%s\n", AFIRMATIU);
  return 0;
}
