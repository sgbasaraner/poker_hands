#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "card.h"

int8_t convert_rank(char rank) {
	switch(rank) {
  		case 'A':
  			return 12;
  		case 'K':
  			return 11;
  		case 'Q':
  			return 10;
   		case 'J':
  			return 9;
  		case 'T':
  			return 8;
  		default :
  			return (rank - '0') - 2;
	}
}

char convert_back(int8_t rank) {
	switch(rank) {
		case 12:
			return 'A';
		case 11:
			return 'K';
		case 10:
			return 'Q';
		case 9:
			return 'J';
		case 8:
			return 'T';
		default:
			return (rank + 2) + '0';
	}
}

int highest_pair(card *ptr) {
	int8_t counts[13];
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
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

char highest_card(card *ptr) {
	int8_t highest = 0;
	for (int i = 0; i < 5; ++i) {
		int8_t tmp = convert_rank((ptr + i) -> rank);
		if (tmp > highest) {
			highest = tmp;
		}
	}
	return convert_back(highest);
}