#include "header.h"

#define SWAP(NUM) (((NUM << 24) | (NUM >> 24)))
unsigned int swap (unsigned int NUM) {
	int NUM1;
	NUM1 = SWAP(NUM);
	NUM = (NUM & 0x00FFFF00);
	NUM = (((NUM & 0x00FF0000) >> 8) | ((NUM & 0x0000FF00) << 8));
	NUM = NUM1 | NUM;
	printf("0x%x", NUM);
	printf("\n");
	return 0;

}
