#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int isprime(int val)
{
	if (val == 0 || val == 1)
		return 0;
	
	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return 0;
	return 1;
}


static int icmp(const void* vp1, const void* vp2)
{
	return *(const int*)vp1 - *(const int*)vp2;
}


void set_array_random(int* p, int size)
{
	while (size--) {
		*p = rand() % 1000;
		++p;
	}
}


void print_array(const int* p, int size)
{
	for (int i = 0; i < size; ++i) {
		if (i != 0 && i % 20 == 0)
			printf("\n");
		printf("%3d ", p[i]);
	}
	printf("\n-----------------------------------------------------------------------------------------\n");
}


void sort_array(int* p, int size)
{
	qsort(p, size, sizeof(int), &icmp);
}


void pline(void)
{
	printf("\n----------------------------------------------------------------------\n");
}


int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val) {
		++digit_count;
		val /= 10;
	}
	
	return digit_count;
}


void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}


void sgets(char* p)
{
	int c;

	while ((c = getchar()) != '\n')
		*p++ = (char)c;

	*p = '\0';
}


void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}


void randomize(void)
{
	srand((unsigned)time(NULL));
}


void a_max_runner_up(const int* a, int size, int* max, int* runner_up)
{

	*max = a[0];
	*runner_up = a[1];

	if (a[1] > a[0]) {
		*runner_up = a[0];
		*max = a[1];
	}

	for (int i = 2; i < size; ++i) {
		if (a[i] > *max) {
			*runner_up = *max;
			*max = a[i];
		}
		else if (a[i] > *runner_up)
			*runner_up = a[i];
	}

}


void unique_numbers(const int* a, int size)
{
	int i;
	int k;

	for (i = 0; i < size; ++i) {
		for (k = 0; k < size; ++k) {
			if (i != k && a[i] == a[k])
				break;
		}

		if (k == size)
			printf("%3d ", a[i]);
	}
	printf("\n");
}

void bubble_sort(int* a, int size)
{
	for (int i = 0; i < size - 1; ++i) {
		for (int k = 0; k < size - 1 - i; ++k) {
			if (a[k] > a[k + 1])
				swap(&a[k], &a[k + 1]);
		}
	}

}


void merge(int* a, int* b, int size_a, int size_b, int* c)
{
	sort_array(a, size_a);
	sort_array(b, size_b);

	int idx_a = 0;
	int idx_b = 0;

	for (int i = 0; i < size_a + size_b; ++i) {
		if (idx_a == size_a)
			c[i] = b[idx_b++];
		else if (idx_b == size_b)
			c[i] = a[idx_a++];
		else if (a[idx_a] < b[idx_b])
			c[i] = a[idx_a++];
		else
			c[i] = b[idx_b++];
	}
}


int binary_search(int* a, int size, int sval)
{	
	sort_array(a, size);

	int idx_first = 0;
	int idx_last = size - 1;
	int idx_mid;

	while (idx_first <= idx_last) {
		idx_mid = (idx_first + idx_last) / 2;

		if (a[idx_mid] == sval)
			break;

		if (a[idx_mid] > sval)
			idx_last = idx_mid - 1;

		else
			idx_first = idx_mid + 1;
	}

	if (idx_first > idx_last) {
		printf("value could not found!");
		return 0;
	}

	else {
		printf("got it! it's %d . element of sorted array\n", idx_mid);
		return 1;
	}

}


int get_median(const int* p, size_t size)
{
	int* pd = malloc(size * sizeof(int));
	if (!pd) {
		printf("not enough memory\n");
		exit(EXIT_FAILURE);
	}

	memcpy(pd, p, size * sizeof(int));
	qsort(pd, size, sizeof(*pd), &icmp);
	int retval = pd[size / 2];
	free(pd);
	return retval;

}