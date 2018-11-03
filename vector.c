/*
 * vector
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#include "vector.h"
#include "udef.h"
#include <unistd.h>

Vector **init_vector(unsigned int anrows, unsigned int avsize){

	Vector **p_vec = DMALLOC(Vector, anrows);

	for(int idx = 0; idx < anrows; idx++){
		Vector *p_aux = init_vector_element(avsize);
		if(p_aux == NULL){
			PRINT_ERR("malloc failed.");
			EXIT_ERR;
		}
		p_aux->p_generate(p_aux, avsize, MAX_VAL);

		p_vec[idx] = p_aux;
		p_aux = NULL;
	}

	return p_vec;
}

void del_vector(Vector **pa_v, int rows){

	for(int idx = 0x0; idx < rows; idx++){
		del_vector_element(pa_v[idx]);
	}
}

Vector *init_vector_element(unsigned int size){

	Vector *p_vec = MALLOC(Vector,0x1);

	if(p_vec == NULL){
		PRINT_ERR("malloc failed.");
		EXIT_ERR;
	}
	CLEAR(p_vec, Vector, 0x1);

	p_vec->pdata = MALLOC(int,size);
	if(p_vec->pdata == NULL){
		PRINT_ERR("malloc failed.");
		EXIT_ERR;
	}
	CLEAR(p_vec->pdata, int, size);

	p_vec->size = size;
	p_vec->count = 0x0;

	p_vec->p_generate = v_generate;
	p_vec->p_print = v_print;
	p_vec->p_update = v_update;
	p_vec->p_reverse = v_reverse;

	return p_vec;
}


void del_vector_element(Vector *pa_v){

	free(pa_v->pdata);
	pa_v->size = 0x0;
	pa_v->count = 0x0;
	pa_v->p_generate = NULL;
	pa_v->p_print = NULL;
	pa_v->p_update = NULL;
	free(pa_v);
}

void v_update(Vector *pa_v, int asize, int acnt){
	pa_v->size = asize;
	pa_v->count = acnt;
}

void v_generate(Vector *pa_v, int an, const int amax){


	FILE *fp=fopen("/dev/urandom","r");

	if (fp == NULL){
		PRINT_ERR("urandom opening failed");
		EXIT_ERR;
	}

	int *paux = pa_v->pdata;

	for(int idx = 0x0; idx < an; idx++){
		int i = fgetc(fp);
		*paux++ = i % amax;
	}

	pa_v->p_update(pa_v, pa_v->size, an);

	fclose(fp);
}

void v_reverse(Vector *pa_v, int size){

	int temp[size];

	int *paux = pa_v->pdata;

	for(int idx = size -1; idx >= 0x0; idx--){
		temp[idx] = *paux--;
	}

	for(int idx = 0x0; idx < size; idx++){
		*paux++ = temp[idx];
	}
}


void v_print(Vector *pa_v, const char *msg){

	int *p_aux = pa_v->pdata;
	fprintf(STDOUT, "=== %s ===\n", msg);
	fprintf(STDOUT, "Capacity: %d\nCount: %d\n", (int)pa_v->size, (int)pa_v->count);
	fprintf(STDOUT, "[\n\t");
	for(int idx = 0x0; idx < pa_v->size; idx++){
		fprintf(STDOUT, "%d | ", *p_aux++);
	}
	fprintf(STDOUT, "\n]\n");
}
