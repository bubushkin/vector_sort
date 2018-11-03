/*
 * timer.c
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "udef.h"

/*
 * Start timer
 */
void t_start(Timer *p_t){
	p_t->s_t = clock();
}

/*
 * End timer;
 */
void t_end(Timer *p_t){
	p_t->e_t = clock();
	p_t->delta_t = (double) (p_t->e_t - p_t->s_t) / CLOCKS_PER_SEC;
}

/*
 * Print delta in pretty print
 */
void t_print(Timer *p_t, const char *msg){
	fprintf(STDOUT, "%s(seconds): %lf\n", msg, p_t->delta_t);
}

