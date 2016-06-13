#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>
#include <time.h>

int *aux(int array[], int tam)
{
	register int i, k = 0;

	for(i = tam; i > 0; i--)
	{
		k = i -1;
		array[i] = array[k];
	}

	return array;
}


void change(int *n1, int *n2)
{
	int tp;
	tp = *n1;
	*n1 = *n2;
	*n2 = tp;
}


void print(int v[], int tam)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		printf(" %u\n", v[i]);
	}
	puts(" ");

}

int pivo_first(int ini)
{
	return ini;

}

int pivo_aleatorio(int n1)
{
	int index;
	srand(time(NULL));
	index = (rand()% n1);
	return index;
}



int pivo_mediana(int array[], int tam, int meio, int ini)
{
	int aux;
	if(array[ini] > array[meio])
	{
		aux = array[ini];
		array[ini] = array[meio];
		array[meio] = aux;
		
	}
	if(array[meio] > array[tam])
	{
		aux = array[meio];
		array[meio] = array[tam];
		array[tam] = aux;
		
	}
	if(array[ini] > array[meio])
	{
		aux = array[ini];
		array[ini] = array[meio];
		array[meio] = aux;
		
	}
	return meio;
}

int *quicksort(int ini, int fim, int vtr[], int opt)
{
	int aux, i, key, j, pivo, meio;
	 if((fim - ini) < 2)
 	{
   	 if((fim - ini) == 1)
		   {
		      if(vtr[ini] > vtr[fim])
			   {
		   		aux = vtr[ini];
		   		vtr[ini] = vtr[fim];
		  	 		vtr[fim] = aux;
		   	}
	   	}
 	}
	else
 	{
		switch(opt)
		{
   		case 1 :
				meio = (ini + fim) / 2;
				pivo = pivo_mediana( vtr, fim, meio, ini);
				break;
			case 2:
				pivo = pivo_first(ini);
				break;
			case 3:
				pivo = pivo_aleatorio(fim - ini) + ini;
				break;

		}
   	aux = vtr[pivo];
   	vtr[pivo] = vtr[fim];
   	vtr[fim] = aux;
   	i = ini;
   	j 	= fim - 1;
  	 	key = vtr[fim];
  	 	while(j >= i)
   	{
			while(vtr[i] < key)
			{
		   	i++;
			}
			while(vtr[j] > key)
			{
		   	j--;
			}
			if(j >= i)
			{
		   	aux = vtr[i];
		   	vtr[i] = vtr[j];
		   	vtr[j] = aux;
		  	 	i++;
		   	j--;
			}
   }
   aux = vtr[i];
   vtr[i] = vtr[fim];
   vtr[fim] = aux;
   quicksort(ini, i , vtr, opt);
   quicksort(i + 1, fim, vtr, opt);
 }

	return vtr;
}



int main()
{
	int opt;	
	int *v;
	int tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	puts("tamanho do vetor");
	scanf(" %d", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	printf("1 -mediana de tres\n2 -Primeiro elemento\n3 -Aleatorio\n");
	scanf(" %d", &opt);
	

	v = load_file( name, tam);


	gettimeofday(&ttl, 0);
	t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

	
	v = quicksort(0, tam, v, opt);

	gettimeofday(&ttl, 0);
	t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);


	printf("Tempo %.6f\n", t1 -t0);
	
	free(v);
	return 0;


}


