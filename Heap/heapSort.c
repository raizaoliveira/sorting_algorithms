#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

void print(unsigned v[], unsigned tam)
{
	unsigned i;
	printf("Tamanho: %u\n", tam);
	for(i = 1; i <= tam; i++)
	{
		printf("v[%u] =  %u\n", i,v[i]);
	}
	puts(" ");

}


unsigned *aux(unsigned array[], unsigned tam)
{
	register unsigned i, k = 0;

	for(i = tam; i > 0; i--)
	{
		k = i -1;
		array[i] = array[k];
	}

	return array;
}

void change(unsigned *n1, unsigned *n2)
{
	unsigned tp;
	tp = *n1;
	*n1 = *n2;
	*n2 = tp;
}

unsigned index_son_left(unsigned i)
{
	return (2 * i);
}

unsigned index_son_right(unsigned i)
{
	return (2 * i + 1);
}

void pushdown(unsigned i, unsigned heap[], unsigned tam)
{
	unsigned H_left, H_right;

	H_left = 0; 
	H_right = 0;
	
	if(index_son_left(i) <= tam)
	{
		H_left = 1;
	}
	
	if(index_son_right(i) <= tam)
	{
		H_right = 1;
	}
	
	if(H_left && !H_right)
	{
		if(heap[i] < heap[index_son_left(i)])
		{
			change(&heap[index_son_left(i)], &heap[i]);
			pushdown( index_son_left(i), heap, tam);

		}
	}
	else
	{
		if(H_left && H_right)
		{
			if(( heap[i] < heap[index_son_left(i)]) || (heap[i] < heap[index_son_right(i)]))
			{
				if(heap[index_son_left(i)] > heap[index_son_right(i)])
				{
					change(&heap[index_son_left(i)], &heap[i]);
					i = index_son_left(i);
				}
				else
				{
					change(&heap[index_son_right(i)], &heap[i]);
					i = index_son_right(i);
				}
				pushdown(i, heap, tam);
			}
		}
	}
}

void makeheap(unsigned heap[], unsigned tam)
{
	unsigned i;

	for(i = tam/2; i >= 1; i--)
	{
		pushdown(i, heap, tam);	
	}
}

void crashheap(unsigned heap[], unsigned tam)
{
	unsigned i;
	unsigned n = tam;
	for(i = 1; i <= n; i++)
	{
		change(&heap[1], &heap[tam]);
		tam--;
		pushdown(1, heap, tam);	
	}
}

unsigned *heapSort(unsigned array[], unsigned tam)
{
	makeheap(array, tam);
	crashheap(array, tam);
	return array;

}

int main()
{
	
	unsigned *v;
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
	
	sprintf(arquivo_saida, "media tempo aleatorio");
	pt_arq_saida = fopen( arquivo_saida, "a");
	if(!pt_arq_saida)
		puts("Nao abriu arquivo de saida");
	
	/*    10*/
	puts("tamanho do vetor 10");
	tam = 10;
	sum = 0;
	media_tempo = 0;
	
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
		/*    100*/
	puts("tamanho do vetor 10");
	tam = 100;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);

		/*    1000*/
	puts("tamanho do vetor 1000");
	tam = 1000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);

		/*    10000*/
	puts("tamanho do vetor 10 mil");
	tam = 10000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);

	/*    100 mil*/
	puts("tamanho do vetor 100 mil");
	tam = 100000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
	/*    1 milhao*/
	puts("tamanho do vetor 100 mil");
	tam = 1000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
	/*    10 milhao*/
	puts("tamanho do vetor 10 milhoes");
	tam = 10000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
	/*    100 milhoes*/
	puts("tamanho do vetor 100 milhoes");
	tam = 100000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	
	/*    500 milhoes*/
	puts("tamanho do vetor 100 mil");
	tam = 500000000;
	sum = 0;
	media_tempo = 0;
	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);
		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		v = heapSort(v, tam);
		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
		printf("\nTime: %.10f \n\n", t1 - t0);	
		sum += (t1 - t0);
	}
	media_tempo = sum / 3;
	printf("media_tempo = %.10f\n", media_tempo);
	fprintf(pt_arq_saida, "\nMedia de tempo para 10 elementos = %.10f\n", media_tempo);
	fclose(pt_arq_saida);
	return 0;
	
}


