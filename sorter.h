/*
 * sorter.h
 *
 *  Created on: Oct 18, 2018
 *      Author: iskandar
 */

#ifndef SORTER_H_
#define SORTER_H_

#include "sorter.h"
#include "vector.h"
#include "timer.h"

typedef struct _sorter{
	Counter *p_counter;
	void (*p_sort)(struct _sorter *, Vector **, Vector **, int, int);

} Sorter;

/*
 * Constructor for Sorter class
 */
Sorter *init_sorter();

/*
 * Destructor for Sorter class
 */
void del_sorter(Sorter *);

/*
 * Compares sub elements lexicographically
 * Return:
 * 	lhs > rhs: 1
 * 	lhs < rhs: 2
 * 	lhs = rhs: 0
 */
int compare_element(int *, int *, int);

void merge(Vector **, Vector **, Counter *, int, int, int);

/*
 * Compares two vectors
 * Return:
 * 	lhs > rhs: 1
 * 	lhs < rhs: 2
 * 	lhs = rhs: 0
 */
int compvec(Vector *, Vector *, Counter *);

void swap(Vector *, Vector *);
void merge_sort(Sorter *, Vector **, Vector **, int, int);
void heap_sort(Vector **, Vector **);
void quick_sort(Vector **, Vector **);


#endif /* SORTER_H_ */
