#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int mem_disp()
{
 int mem;FILE *fp;char s[50];

  system("cat /proc/meminfo|grep MemFree>mem.txt");
   fp=fopen("mem.txt","r");
    if (fp==NULL){ printf("* Execution interrompue \n"); system("rm mem.txt");exit(0);}
     fgets(s,50,fp);
   fclose(fp);
  sscanf(s+11,"%d",&mem);
  system("rm mem.txt");
  return(mem);
}

long init_N()
{ long N=0; char c=0;
  printf("* Saisir manuellement la taille des matrices ? o/n\n");
  c=getchar();
  if (c=='n' || c=='N'){ N=mem_disp();N=(long)sqrt(((N*1024)/sizeof(float))/3);return(N);}
  else { printf("* N= ");scanf("%ld",&N);return(N);}
}


 
int main()
{
  float *A,*B,*C;long i,j,N;float deb,fin;
  srand(time(NULL));
  N=init_N();
  system("clear");
  printf("* La taille max d une mat :%ld\n",N);

  A=malloc(sizeof(float)*N*N);
  if (A==NULL){ printf("* Allocation impossible \n"); exit(0);}
  B=malloc(sizeof(float)*N*N);
  if (B==NULL){ printf("* Allocation impossible \n"); exit(0);}
  C=malloc(sizeof(float)*N*N);
  if (C==NULL){ printf("Allocation impossible \n"); exit(0);}
  printf("* L'allocation s'est bien deroulée avec N= %ld\n",N);
 
    for (i=0;i<N;i++)
      for (j=0;j<N;j++)
       {
 	*(A+i*N+j)=(float)rand();
        *(B+i*N+j)=(float)rand();
       }
 printf("* Le remplissage s'est bien déroulé\n");
  deb=clock();
  for (i=0;i<N;i++)
      for (j=0;j<N;j++)
        *(C+i*N+j)=*(A+i*N+j) + *(B+i*N+j);
  fin=clock();
 printf("* La sommation de A + B s'est bien déroulée\n");
 printf("* Temps necessaire pour l'addition A + B : %e\n",(fin-deb)/CLOCKS_PER_SEC);

 deb=clock();
  for (i=0;i<N;i++)
      for (j=0;j<N;j++)
        *(C+i*N+j)=*(B+i*N+j) + *(A+i*N+j);
  fin=clock();
 printf("* La sommation de B + A s'est bien déroulée\n");
 printf("* Temps necessaire pour l'addition B + A : %e\n",(fin-deb)/CLOCKS_PER_SEC);

 return(0);

}



