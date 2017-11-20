#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>

int highest_pair(card *ptr);
char highest_card(card *ptr);
bool one_pair(card *ptr);
bool two_pair(card *ptr);
bool three_kind(card *ptr);
bool four_kind(card *ptr);
bool full_house(card *ptr);
bool straight(card *ptr);
bool flush(card *ptr);
bool royal_flush(card *ptr);
bool straight_flush(card *ptr);

#endif