#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Input the hand in this format: Ac, Tc, Kd, 3d, 7s\n");
	char user_input[18];
	fgets(user_input, 19, stdin);

	// separate user input by comma
	const char separator[3] = ", ";
   	char *token;
   	token = strtok(user_input, separator);
   	while (token != NULL) {
    	printf("%s\n", token);
      	token = strtok(NULL, separator);
   	}
}