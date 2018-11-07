/*
 * sorter.c
 *
 *  Created on: Oct 18, 2018
 *      Author: iskandar
 */

#include "sorter.h"
#include "udef.h"
#include "timer.h"
#include <string.h>


Sorter *init_sorter(){

	Sorter *p_sorter = MALLOC(Sorter, 0x1);
	if(p_sorter == NULL){
		PRINT_ERR("malloc failed.");
		EXIT_ERR;
	}
	CLEAR(p_sorter, Sorter, 0x1);
	p_sorter->p_counter = MALLOC(Counter, 0x1);
	if(p_sorter->p_counter == NULL){
		PRINT_ERR("malloc failed.");
		EXIT_ERR;
	}
	CLEAR(p_sorter->p_counter, Counter, 0x1);

//	COORDINATE_SORTER(atype);
	INIT_SORTER();

	return p_sorter;
}

void del_sorter(Sorter *pa_sorter){

	pa_sorter->p_merge_sort = NULL;
	pa_sorter->p_quick_sort = NULL;
	pa_sorter->p_heap_sort = NULL;

	free(pa_sorter->p_counter);
	free(pa_sorter);

}

int compare_element(int *palhs, int *parhs, int asize){

	int ret = 0;
	for(int idx = 0x0; idx < asize; idx++){
		if(palhs[idx] == parhs[idx])
			continue;
		if(palhs[idx] < parhs[idx]){
			ret = 0x1;
			break;
		}
		if(palhs[idx] > parhs[idx]){
			ret = 0x2;
			break;
		}
	}
	return ret;
}

int compvec_qs(Vector *pa_v_x, Vector *pa_v_y, Counter *pa_counter){
	pa_counter->counter++;
	int ret = compare_element_qs(pa_v_x->pdata, pa_v_y->pdata, (int)pa_v_x->size);
	return ret;
}

int compare_element_qs(int *palhs, int *parhs, int asize){

	int ret = 0;
	for(int idx = 0x0; idx < asize; idx++){
		if(palhs[idx] <= parhs[idx]){
			ret = 0x1;
			break;
		}
		if(palhs[idx] > parhs[idx]){
			ret = 0x2;
			break;
		}
	}
	return ret;
}

int compvec(Vector *pa_v_x, Vector *pa_v_y, Counter *pa_counter){
	pa_counter->counter++;
	int ret = compare_element(pa_v_x->pdata, pa_v_y->pdata, (int)pa_v_x->size);
	return ret;
}


void merge_sort(Sorter *pa_sorter, Vector **pla_v_in, Vector **pla_v_out, int aleft, int aright){

//	_print_range(pla_v_in, aleft, aright, __func__);

	int mid = (aright + aleft) / 0x2;

	if(aright > aleft){
	    merge_sort(pa_sorter, pla_v_in, pla_v_out, aleft, mid);
	    merge_sort(pa_sorter, pla_v_in, pla_v_out, mid+1, aright);
		merge(pla_v_in, pla_v_out, pa_sorter->p_counter, aleft, mid+1, aright);
	}
}

void swap(Vector **pa_v, int aleft, int aright){
	Vector *temp = pa_v[aleft];
	pa_v[aleft] = pa_v[aright];
	pa_v[aright] = temp;
}

void quick_sort(Sorter *pa_sorter, Vector **pla_v_in, int alow, int ahigh){
	int pivot;
	if(ahigh > alow){
		pivot = partition(pla_v_in, pa_sorter->p_counter, alow, ahigh);
		quick_sort(pa_sorter, pla_v_in, alow, pivot - 1);
		quick_sort(pa_sorter, pla_v_in, pivot + 1, ahigh);
	}
}
/*
 * Compares two vectors
 * Return:
 * 	lhs > rhs: 2
 * 	lhs <= rhs: 1
 * 	lhs = rhs: 0
 */

int partition(Vector **pa_v, Counter *pa_t, int alow, int ahigh){

	int left, right;
	Vector *p_pivot;
	p_pivot = pa_v[alow];
	left = alow;
	right = ahigh;

	while(left < right){
#ifdef DEBUG
		_print_range(pa_v, left, right, __func__);

		pa_v[left]->p_print(pa_v[left], "left");
		p_pivot->p_print(p_pivot, "pivot");
		pa_v[right]->p_print(pa_v[right], "right");
#endif

		while(compvec_qs(pa_v[left], p_pivot, pa_t) == 0x1 && left < ahigh)
			left++;

		while(compvec_qs(pa_v[right], p_pivot, pa_t) == 0x2)
			right--;

		if(left < right){
			swap(pa_v, left, right);
#ifdef DEBUG
			_print_range(pa_v, alow, ahigh, __func__);
#endif

		}
	}
	pa_v[alow] = pa_v[right];
	pa_v[right] = p_pivot;
	return right;
}

void merge(Vector **pa_v, Vector **pla_v_out, Counter *pa_t, int aleft, int amid, int aright){

	int left, left_end, right, out_idx;

	left = aleft;
	left_end = amid - 0x1;
	out_idx = aleft;
	right = aright;

	int size = right - left + 0x1;

#ifdef DEBUG
	_print_range(pa_v, aleft, aright, __func__);
#endif

	while((left <= left_end) && (amid <= right)){
		int cmp = compvec(pa_v[left], pa_v[amid], pa_t);
		switch(cmp){
			case 0:
			case 1:
				pla_v_out[out_idx++] = pa_v[left++];
				break;
			case 2:
				pla_v_out[out_idx++] = pa_v[amid++];
				break;
		}
	}
	while(left <= left_end){
		pla_v_out[out_idx++] = pa_v[left++];
	}

	while(amid <= right){
		pla_v_out[out_idx++] = pa_v[amid++];
	}

	for(int idx = 0x0; idx <= size; idx++){
		pa_v[right] = pla_v_out[right];
		right--;
	}
}

void heap_sort(Sorter *pa_sorter, Vector **pla_v_in, Vector **pla_v_out, int aleft, int aright){

}
