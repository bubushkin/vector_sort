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

int vector_len = 1000;
int cell_len = 5;

int main(int argc, char **argv){

	Sorter *p_sorter = init_sorter();
	Vector **p_list_in = init_vector(vector_len, cell_len);

#ifdef DEBUG
	printf("Original\n");

	for(int idx = 0x0; idx < vector_len; idx++){
		Vector *p_aux = p_list_in[idx];
		printf("[ ");
		for(int i = 0; i < cell_len; i++)
			printf(" %d ", p_aux->pdata[i]);
		printf(" ]");
		printf("\n");
	}
	printf("\n");
#endif
	Vector **p_list_out = DMALLOC(Vector, vector_len);

	t_start(&p_sorter->p_counter->timer);
	p_sorter->p_merge_sort(p_sorter, p_list_in, p_list_out, 0x0, vector_len-1);
	t_end(&p_sorter->p_counter->timer);

#ifdef DEBUG
	printf("Sorted(MergeSort)\n");
	for(int idx = 0x0; idx < vector_len; idx++){
		Vector *p_in = p_list_in[idx];
		printf("[ ");
		for(int i = 0; i < cell_len; i++)
			printf(" %d ", p_in->pdata[i]);
		printf(" ]");
		printf("\n");
	}
#endif

	t_print(&p_sorter->p_counter->timer, "Time took for MergeSort");
	printf("Number of comparisions: %ld \n", p_sorter->p_counter->counter);

	del_vector(p_list_in, vector_len);
	free(p_list_out);

	/*
	 * Quick-Sort
	 */
	p_list_in = init_vector(vector_len, cell_len);

#ifdef DEBUG
	printf("Original\n");

	for(int idx = 0x0; idx < vector_len; idx++){
		Vector *p_aux = p_list_in[idx];
		printf("[ ");
		for(int i = 0; i < cell_len; i++)
			printf(" %d ", p_aux->pdata[i]);
		printf(" ]");
		printf("\n");
	}
	printf("\n");
#endif

	t_start(&p_sorter->p_counter->timer);
	p_sorter->p_quick_sort(p_sorter, p_list_in, 0x0, vector_len - 1);
	t_end(&p_sorter->p_counter->timer);

#ifdef DEBUG
	printf("Sorted(QuickSort)\n");
	for(int idx = 0x0; idx < vector_len; idx++){
		Vector *p_in = p_list_in[idx];
		printf("[ ");
		for(int i = 0; i < cell_len; i++)
			printf(" %d ", p_in->pdata[i]);
		printf(" ]");
		printf("\n");
	}
#endif

	t_print(&p_sorter->p_counter->timer, "Time took for QuickSort");
	printf("Number of comparisions: %ld \n", p_sorter->p_counter->counter);

	del_sorter(p_sorter);
	del_vector(p_list_in, vector_len);


	return EXIT_SUCCESS;
}
