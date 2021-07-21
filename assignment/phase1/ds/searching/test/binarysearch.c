#include <stdio.h>

int binarysearch (char **array, int low, int high, char *key) {
//	sort (array , size);
	int mid;
	if (low >high) {
		return -1;
	} else {
		mid = (low + high) / 2;
		if (strcmp (key, *(array + mid)) == 0) {
			return mid;
		} else if (strcmp (key, *(array + mid)) > 0) {
			//low = mid + 1;
			binarysearch (array, mid + 1, high, key);
		} else if (strcmp (key,  *(array + mid)) < 0) {
		//	high = mid - 1;
			binarysearch (array, low, mid - 1, key);
		}
	}
}
