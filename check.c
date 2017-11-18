#include <stdbool.h>
#include "card.h"

bool per(card *ptr) {
	for (int i = 0; i < 5; ++i) {
		printf("%i.%c%c\n", i, (ptr + i) -> rank, (ptr + i) -> color);
	}
	return false;
}