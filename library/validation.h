#include <ctype.h> // Para isalpha
#include <string.h> //para usar strings

int validation(char letters[]){
	int i=0;
	while ( letters[i]) {
		if ( !isalpha(letters[i])  && letters[i] != ' ') {
			return 0;
		}
		i++;
	};
	return 1;
};
