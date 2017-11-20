#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>

int highest_pair(card *ptr);
char highest_card(card *ptr);
bool one_pair(card *ptr);
bool two_pair(card *ptr);
bool three_kind(card *ptr);

#endif