/*
 * vector.h
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "udef.h"

typedef struct _vector{

	int *pdata;
	size_t size;
	size_t count;

	void (*p_generate)(struct _vector *, int, const int);
	void (*p_update)(struct _vector *, int, int);
	void (*p_print)(struct _vector *, const char *);
	void (*p_reverse)(struct _vector *, int);

} Vector;

/*
 *	Initilize vector on heap
 */
Vector **init_vector(unsigned int, unsigned int);
/*
 *	Delete vector from heap
 */
void del_vector(Vector **, int);

/*
 * Constructor for Vector class
 * Returns empty vector
 */
Vector *init_vector_element(unsigned int);

/*
 * Destructor for Vector class
 * Returns empty vector
 */
void del_vector_element(Vector *);

/*
 * method to update vector parameters: size, count
 */
void v_update(Vector *, int, int);

/*
 * method to generate vector's list of data
 */
void v_generate(Vector *, int, const int);

/*
 * Reverse vector data
 */
void v_reverse(Vector *, int);

/*
 * method to print vector to stdout
 */
void v_print(Vector *pa_v, const char *);

/*
 * method to print vector elements for a given range to stdout
 */
void _print_range(Vector **, int, int, const char *);

#endif /* VECTOR_H_ */
