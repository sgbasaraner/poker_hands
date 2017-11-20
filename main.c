#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"
#include "check.h"

int main(int argc, char *argv[]) {
	printf("Input the hand in this format: Ac, Tc, Kd, 3d, 7s\n");
	char user_input[18];
	fgets(user_input, 19, stdin);

	// separate user input by comma and add separated values to a hand array
	const char separator[3] = ", ";
   	char *token;
   	token = strtok(user_input, separator);
   	char hand_str[5][3];
   	int tmp = 0;
   	while (token != NULL) {
   		printf("%i.%s\n", tmp + 1, token);
   		strcpy(hand_str[tmp], token);
      	token = strtok(NULL, separator);
      	tmp++;
   	}

   	// parse input to an array of cards
   	card hand[5];
   	for (int i = 0; i < 5; i++) {
   		card tmp;
   		tmp.rank = hand_str[i][0];
   		tmp.color = hand_str[i][1];
   		hand[i] = tmp;
   	}

   	card *ptr = hand;

   	if (royal_flush(ptr)) {
   		printf("ROYAL FLUSH\n");
   	} else if (straight_flush(ptr)) {
   		printf("STRAIGHT FLUSH\n");
   	} else if (four_kind(ptr)) {
   		printf("FOUR OF A KIND\n");
   	} else if (full_house(ptr)) {
   		printf("FULL HOUSE\n");
   	} else if (flush(ptr)) {
   		printf("FLUSH\n");
   	} else if (straight(ptr)) {
   		printf("STRAIGHT\n");
   	} else if (three_kind(ptr)) {
   		printf("THREE OF A KIND\n");
   	} else if (two_pair(ptr)) {
   		printf("TWO PAIRS\n");
   	} else if (one_pair(ptr)) {
   		printf("A PAIR\n");
   	}

   	printf("The highest card is: %c\n", highest_card(ptr));
}