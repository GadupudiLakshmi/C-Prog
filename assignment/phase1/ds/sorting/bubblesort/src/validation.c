#include "header.h"

int validation (char number[]) {
	int index;
	int num = 0;
	for (index = 0; number[index] != '\0' && number[index] != '\n'; index++) {
		if (number[index] >= '0' && number[index] <= '9') {
			num = num * 10 + (number[index] - '0');
		} else {
			printf("Invalid input \n");
			return -1;
		}
	}
	return num;
}
