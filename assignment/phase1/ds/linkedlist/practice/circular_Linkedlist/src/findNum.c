#include "header.h"

int find (int num, node_t *list) {
	int position = 0;
	if (list == NULL) {
		return -1;
	} else {
		node_t *temp = list;
		while (temp->link != NULL) {
			position++;
			if (temp->data == num) {
				return position;
			}
			temp = temp->link;
		}
		if (temp->data == num) {
			position++;
			return position;
		}
	}
	position = -1;
	return position;
}
