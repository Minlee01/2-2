#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define MAX_INPUT 100
#define MAX_BIT 24
#define DIGIT 6
#define BIT 64


typedef struct {
	int num;
	int digit[MAX_BIT / DIGIT];
}element;



void print(element* arr) {
	for (int i = 0; i < MAX_INPUT; i++) {
		printf("%d \n", arr[i].num);
	}
}

void make_rand_number(element input[]) {
	for (int i = 0; i < MAX_INPUT; i++) {
		int r = pow(2, MAX_BIT);
		int num = rand() % r;
		input[i].num = num;
		for (int j = 0; j < MAX_BIT / DIGIT; j++) {
			input[i].digit[j] = num % BIT;
			num /= BIT;
		}
	}
}

void counting_sort(element rad_d[], const int dig_num, element B[]) {

	int hist[BIT];

	for (int i = 0; i < BIT; i++) {
		hist[i] = 0;
	}

	for (int i = 0; i < MAX_INPUT; i++) {
		int index = rad_d[i].digit[dig_num];
		hist[index] += 1;
	}


	for (int i = 1; i < BIT; i++) {
		hist[i] = hist[i] + hist[i - 1];
	}

	for (int i = (MAX_INPUT - 1); i >= 0; i--) {
		int index = rad_d[i].digit[dig_num];
		int c_index = hist[index];
		B[c_index - 1] = rad_d[i];
		hist[index] -= 1;
	}

}

void radix_sort(element rad_d[]) {
	element result_t[MAX_INPUT];
	element result[MAX_INPUT];

	counting_sort(rad_d, 0, result_t);
	counting_sort(result_t, 1, result);
	counting_sort(result, 2, result_t);
	counting_sort(result_t, 3, result);

	printf("========radix sort result\n");
	print(result);
}

int main() {
	element rad_d[MAX_INPUT];
	make_rand_number(rad_d);
	print(rad_d);
	printf("====\n");

	radix_sort(rad_d);

	return 0;
}