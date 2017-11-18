#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "card.h"

bool per(card *ptr) {
	for (int i = 0; i < 5; ++i) {
		printf("%i.%c%c\n", i, (ptr + i) -> rank, (ptr + i) -> color);
	}
	return false;
}

int per_count(card *ptr) {
	int8_t counts[13], tmp;
	for (int i = 0; i < 5; ++i) {
		switch((ptr + i) -> rank) {
      		case 'A':
      			counts[12]++;
      			break;
      		case 'K':
      			counts[11]++;
      			break;
      		case 'Q':
      			counts[10]++;
      			break;
      		case 'J':
      			counts[9]++;
      			break;
      		case 'T':
      			counts[8]++;
      			break;
      		default :
      			tmp = (((ptr + i) -> rank) - '0') - 2;
      			counts[tmp]++;
      			break;
   		}
	}

	int8_t result = 0;
	for (int i = 0; i < 13; ++i) {
		printf("%i\n", counts[i]);
		if (counts[i] > result) {
			result = counts[i];
		}
	}

	return result;
}