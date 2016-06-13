#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

int *bubbleSort(int array[], unsigned lenght)
{
	unsigned i, j;
	int aux;

	for(i = 0; i < lenght; i++)
	{
		for(j = 0; j < lenght - 1 ; j++)
		{
			if(array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	return array;
}


void print(int v[], unsigned tam)
{
	unsigned i;
	for(i = 0; i < tam; i++)
	{
		printf("   %d", v[i]);
	}
	puts(" ");

}

int main()
{	

	int *v;
	unsigned tam;
	char name[100];
	char arquivo_saida[50];
	struct timeval ttl;
	double t0,t1;
	double media_tempo, sum;
	FILE *pt_arq_saida;
	register int i;
	puts("nome do arquivo");
	scanf(" %s", name);
	/*    10*/
	puts("tamanho do vetor 10");
	tam = 10;
	sum = 0;
	media_tempo = 0;
	sprintf(arquivo_saida, "media tempo crescente");
	pt_arq_saida = fopen( arquivo_saida, "a");
	if(!pt_arq_saida)
		puts("Nao abriu arquivo de saida");
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
	/*100*/
	puts("tamanho do vetor 100");
	tam = 100;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 100 = %.10f\n", media_tempo);
	


	/*1000*/
	puts("tamanho do vetor 1000");
	tam = 1000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para arquivo %s = %.10f\n", name, media_tempo);
		

	
	/*10000*/
	puts("tamanho do vetor 10.000");
	tam = 10000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para arquivo %s = %.10f\n", name, media_tempo);

	/*100000*/
	puts("tamanho do vetor 100.000");
	tam = 100000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para arquivo %s = %.10f\n", name, media_tempo);
	
	/*500000*/
	puts("tamanho do vetor 500.000");
	tam = 500000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = bubbleSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para arquivo %s = %.10f\n", name, media_tempo);
	fclose(pt_arq_saida);

	
	return 0;
}




