/*
 * main.c
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */


#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "timer.h"
#include "udef.h"
#include "sorter.h"

int n = 100;
int m = 5;

int main(int argc, char **argv){

	Sorter *p_merge_sort = init_sorter(0x1);
	Vector **p_list_in = init_vector(n, m);

	printf("Original\n");

	for(int idx = 0x0; idx < n; idx++){
		Vector *p_aux = p_list_in[idx];
		for(int i = 0; i < m; i++)
			printf("[%d] ", p_aux->pdata[i]);
		printf("\n");
	}
	printf("\n");

	Vector **p_list_out = DMALLOC(Vector, n);

	t_start(&p_merge_sort->p_counter->timer);
	p_merge_sort->p_sort(p_merge_sort, p_list_in, p_list_out, 0x0, n-1);
	t_end(&p_merge_sort->p_counter->timer);

	printf("Sorted(MergeSort)\n");
	for(int idx = 0x0; idx < n; idx++){
		Vector *p_in = p_list_in[idx];
		for(int i = 0; i < m; i++)
			printf("[%d] ", p_in->pdata[i]);
		printf("\n");
	}
	t_print(&p_merge_sort->p_counter->timer, "Time took for MergeSort");


	for(int idx = 0x0; idx < n; idx++){
		Vector *p_aux = p_list_in[idx];
		p_aux->p_reverse(p_aux, m);
	}

	printf("Revrsed\n");

	for(int idx = 0x0; idx < n; idx++){
		Vector *p_aux = p_list_in[idx];
		for(int i = 0; i < m; i++)
			printf("[%d] ", p_aux->pdata[i]);
		printf("\n");
	}
	printf("\n");

	t_start(&p_merge_sort->p_counter->timer);
	p_merge_sort->p_sort(p_merge_sort, p_list_in, p_list_out, 0x0, n-1);
	t_end(&p_merge_sort->p_counter->timer);

	printf("Sorted(MergeSort)\n");
	for(int idx = 0x0; idx < n; idx++){
		Vector *p_in = p_list_in[idx];
		for(int i = 0; i < m; i++)
			printf("[%d] ", p_in->pdata[i]);
		printf("\n");
	}
	t_print(&p_merge_sort->p_counter->timer, "Time took for MergeSort");



	return EXIT_SUCCESS;
}
