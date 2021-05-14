#ifndef NUTILITY_H
#define NUTILITY_H

#include <stdio.h>

#define isleap(y)		 ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define asize(x)         (sizeof(x) / sizeof(x[0]))


int			isprime(int);
static int  icmp(const void* vp1, const void* vp2);
void		pline(void);
int			ndigit(int);
void		set_array_random(int* p, int size);
void		print_array(const int* p, int size);
void		sort_array(int* p, int size);
void		clear_input_buffer(void);
void		sgets(char* pstr);
void	    swap(int* px, int* py);
void		randomize(void);
void 		a_max_runner_up(const int* a, int size, int* max, int* runner_up);
void 		unique_numbers(const int* a, int size);
void		bubble_sort(int* a, int size);
void	    merge(int* a, int* b, int size_a, int size_b, int* c);
int			binary_search(int* a, int size, int sval);
int			get_median(const int* p, size_t size);

#endif

