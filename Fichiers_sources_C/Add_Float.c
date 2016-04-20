#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
  float x,y,z=0; int i;float deb,fin,t;
  // initialisation des variables x et y à des valeurs aléatoires
srand(time(NULL));
x=(float)rand(); y=(float)rand();
printf("Les nombres à additionnés : %e, %e\n",x,y);
  // declencher le test 
deb=clock();
for (i=0;i<=100000000;i++)
 z=x+y;
fin=clock();
  // Les resultats d'execution
printf(" Temps debut : %f\n",deb);
printf(" Temps fin : %f\n",fin);
printf(" Clocks/sec : %ld\n",CLOCKS_PER_SEC);
t=(fin-deb)/CLOCKS_PER_SEC;
printf(" Temps d'execution : %f\n",t);
printf(" Une addition prend presque : %e secondes\n",t/100000000);

return(0);

}



