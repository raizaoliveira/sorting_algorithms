#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

void print(int v[], unsigned tam)
{
	unsigned i;
	for(i = 0; i <= tam + 2; i++)
	{
		printf("%d     ", v[i]);
	}
	puts(" ");

}



void intercalar(int v[], int aux[], int ini1, int ini2, int fim2)
{
	int in1 = ini1, in2 = ini2, fim1 = in2 - 1, au = 0;
	int i;

	
	while(in1 <= fim1  && in2 <= fim2)
	{
		if(v[in1] < v[in2])
		{
			aux[au++] = v[in1++];
		}
		else
		{
			aux[au++] = v[in2++];
		}
	}
	while(in1 <= fim1)
	{
		aux[au++] = v[in1++];
	}
	while(in2 <= fim2)
	{
		aux[au++] = v[in2++];
	}
	
	for(i = 0; i < au; i++)
	{
		v[i + ini1] = aux[i];
	}


}

int  *mergeSort(int v[], int aux[], int esq, int dir)
{
	int meio;

	if(esq < dir)
	{
		meio = (esq + dir)/ 2;
		mergeSort(v, aux, esq, meio);
		mergeSort(v, aux, meio + 1, dir);
		intercalar(v, aux, esq, meio + 1, dir);

	}


	return v;

}

int main()
{	
	int opt;
	int *v, *aux;
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
	
	printf("1 -mediana de tres\n2 -Primeiro elemento\n3 -Aleatorio\n");
	scanf(" %d", &opt);
	
	/*    10*/
	puts("tamanho do vetor 10");
	tam = 10;
	sum = 0;
	media_tempo = 0;
	sprintf(arquivo_saida, "media tempo aleatorio");
	pt_arq_saida = fopen( arquivo_saida, "a");
	if(!pt_arq_saida)
		puts("Nao abriu arquivo de saida");
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
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
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
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
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
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
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10000 = %.10f\n",media_tempo);

	/*100.000*/
	puts("tamanho do vetor 100.000");
	tam = 100000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para cem mil = %.10f\n",  media_tempo);
	
	/*1000.000*/
	puts("tamanho do vetor 1 milhao");
	tam = 1000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 1 milhao = %.10f\n",  media_tempo);
	
	/*10.000.000*/
	puts("tamanho do vetor 10 milhoes");
	tam = 10000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 milhoes = %.10f\n",  media_tempo);
	
	/*100.000.000*/
	puts("tamanho do vetor 100 milhoes");
	tam = 100000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 100 milhoes = %.10f\n",  media_tempo);
	
	/*500.000.000*/
	puts("tamanho do vetor 500.000");
	tam = 500000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = mergeSort(v, aux, 0, tam - 1);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 500 milhoes = %.10f\n",  media_tempo);
	fclose(pt_arq_saida);

	
	return 0;
}



