#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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

char convert_rank_back(int8_t rank) {
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

int8_t convert_color(char color) {
	switch(color) {
  		case 'c':
  			return 3;
  		case 'd':
  			return 2;
  		case 'h':
  			return 1;
   		case 's':
  			return 0;
  		default:
  			printf("Failed to convert color\n");
  			exit(1);
	}
}

char convert_color_back(int8_t color) {
	switch(color) {
  		case 3:
  			return 'c';
  		case 2:
  			return 'd';
  		case 1:
  			return 'h';
   		case 0:
  			return 's';
  		default:
  			printf("Failed to convert color back\n");
  			exit(1);
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
	return convert_rank_back(highest);
}

bool one_pair(card *ptr) {
	int8_t counts[13] = {0};
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
	}

	for (int i = 0; i < 13; ++i) {
		if (counts[i] == 2) {
			return true;
		}
	}

	return false;
}

bool two_pair(card *ptr) {
	int8_t counts[13] = {0};
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
	}


	bool first_pair = false;
	bool second_pair = false;

	for (int i = 0; i < 13; ++i) {
		if (counts[i] == 2) {
			first_pair = true;
			continue;
		}

		if (counts[i] == 2 && first_pair) {
			second_pair = true;
		}
	}

	if (first_pair && second_pair) {
		return true;
	}

	return false;
}

bool three_kind(card *ptr) {
	int8_t counts[13] = {0};
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
	}

	for (int i = 0; i < 13; ++i) {
		if (counts[i] == 3) {
			return true;
		}
	}

	return false;
}

bool four_kind(card *ptr) {
	int8_t counts[13] = {0};
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
	}

	for (int i = 0; i < 13; ++i) {
		if (counts[i] == 4) {
			return true;
		}
	}

	return false;
}

bool full_house(card *ptr) {
	int8_t counts[13] = {0};
	for (int i = 0; i < 5; ++i) {
   		counts[convert_rank((ptr + i) -> rank)]++;
	}

	bool pair = false;
	bool three_kind = false;

	for (int i = 0; i < 13; ++i) {
		if (counts[i] == 2) {
			pair = true;
		}

		if (counts[i] == 3) {
			three_kind = true;
		}
	}

	if (pair && three_kind) {
		return true;
	}

	return false;
}

bool straight(card *ptr) {
	int8_t ranks[5];
	for (int i = 0; i < 5; ++i) {
		ranks[i] = convert_rank((ptr + i) -> rank);
	}

	// bubble sort
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4 - i; ++j) {
			if (ranks[j] > ranks[j + 1]) {
				int8_t tmp = ranks[j + 1];
				ranks[j + 1] = ranks[j];
				ranks[j] = tmp;
			}
		}
	}

	if (ranks[4] != 12) {	
		for (int i = 0; i < 4; ++i) {
			if (ranks[i] + 1 != ranks[i + 1]) {
				return false;
			}
		}
	} else {
		for (int i = 0; i < 3; ++i) {
			if (ranks[i] + 1 != ranks[i + 1]) {
				return false;
			}
		}
	}

	return true;
}

bool flush(card *ptr) {
	char color = ptr -> color;
	for (int i = 0; i < 5; ++i) {
		if (color != ((ptr + i) -> color)) {
			return false;
		}
	}

	return true;
}

bool straight_flush(card *ptr) {
	if (straight(ptr) && flush(ptr)) {
		return true;
	}

	return false;
}

bool royal_flush(card *ptr) {
	if (!flush(ptr)) {
		return false;
	}

	int8_t ranks[5];
	for (int i = 0; i < 5; ++i) {
		ranks[i] = convert_rank((ptr + i) -> rank);
	}

	// bubble sort
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4 - i; ++j) {
			if (ranks[j] > ranks[j + 1]) {
				int8_t tmp = ranks[j + 1];
				ranks[j + 1] = ranks[j];
				ranks[j] = tmp;
			}
		}
	}

	if ((ranks[0] == 8) && straight(ptr)) {
		return true;
	}	
	
	return false;
}