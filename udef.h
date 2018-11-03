/*
 * udef.h
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#ifndef UDEF_H_
#define UDEF_H_

#include <stdlib.h>
#include <string.h>

#define MAX_VAL 99

#define PRINT_ERR(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define MALLOC(X, S) (X*)malloc(sizeof(X)*S);

#define DMALLOC(X, S) (X**)malloc(sizeof(X*)*S);

#define CLEAR(X, T, N) memset(X, 0x0, sizeof(T)*N);

#define EXIT_ERR exit(-1);

#define COORDINATE_SORTER(X) switch(X){ 	\
		case 1:								\
			p_sorter->p_sort = merge_sort;	\
			break;							\
		case 3:								\
			p_sorter->p_sort = quick_sort;	\
			break;							\
		case 2:								\
			p_sorter->p_sort = heap_sort;	\
			break;							\
		default:							\
			break;							\
	}


#define STDOUT stdout

#define PRINT_INFO(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define PRINT_WARN(M, ...) fprintf(stderr, "[WARN] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif /* UDEF_H_ */
