/*
Algoritmo bubble Sort versao melhorada
UEMS
Ciencia da computacao- AED II
programadora: Raiza Arteman
rgm: 23428
data da ultima modoficacao : 30/10/2013


*/

#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>
#define true 1
#define false 0

typedef int bool;

int *bubbleSort(int vet[], int N)
{
	bool mudou;
	int n;
	int j, i;
	int guarda;
	int aux;
	mudou = true;
	n = N;
	guarda = n;

	while(mudou)
	{
		j = 0;
		mudou = false;
		while(j < n)
		{

			i = j;
			++i;
			if(vet[j] > vet[i])
			{

				if(i < N)
				{
					aux = vet[j];
					vet[j] = vet[i];
					vet[i] = aux;
				}
				mudou = true;
				guarda = j;

			}
			j += 1 ;
			
		}
		n = guarda;
	}
	return vet;
	
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

	FILE *p;
	int i;
	int *v;
	unsigned tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	double tp[3], media = 0;
	
	
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


