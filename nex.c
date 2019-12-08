#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  FILE *fp1;
  char cdizi[40];
  double dd1;
  int id1;
  char cd1;


  if ((fp1=fopen( "custom.txt", "w" )) == NULL) {
      printf("Dosya açılamadı!\n");
      exit(1);
  }

  fprintf (fp1,"%lf %d %s %c", 654.123, 9852, "Bilgisayar", 'A');
  fclose (fp1);

  if ((fp1=fopen ("custom.txt", "r")) == NULL) {
      printf("Dosya açılamadı!\n");
      exit(1);
  }

  fscanf (fp1,"%lf%d%s %c", &dd1, &id1, cdizi, &cd1);
  printf("%lf %d %s %c", dd1, id1, cdizi, cd1);
  fclose (fp1);
}
