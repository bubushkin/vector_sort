/*
 * timer.h
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>

typedef struct _timer{

	clock_t s_t;
	clock_t e_t;
	double delta_t;

}Timer;

typedef struct _counter{
	unsigned long counter;
	Timer timer;
} Counter;

/*
 * Start timer;
 */
void t_start(Timer *);

/*
 * End timer;
 */
void t_end(Timer *);

/*
 * Print delta in pretty print
 */
void t_print(Timer *, const char *);

#endif /* TIMER_H_ */
