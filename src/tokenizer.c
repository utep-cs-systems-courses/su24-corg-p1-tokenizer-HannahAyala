#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>

//true if \t or ' ' false otherwise
int space_char(char c){
	if (c == '\t' || c == ' ')
	       return 1;
	return 0;
}

//true if it is not \t or ' ' or zero terminals false otherwise
int non_space_char(char c){
	if (c != '\t' && c != ' ' && c != '\0')
		return 1;
	return 0;
}

//return a pointer to first char of space separated token return zero pointer if no token
char *token_start(char *str){
	while (!non_space_char(*str)){
		str++;
	}	
	return *str == '\0' ? '\0': str;
}

//return a pointer to the space separator after token
char *token_terminator(char *str){
	while(non_space_char(*str)){
		str++;
	}
	return str;
}

//return the num of tokens
int count_tokens(char *str){
	int counter = 0;

	while(*str != '\0'){
		str = token_start(str);
		
		counter++;
		str = token_terminator(str);
	}
	return counter;
}

//returns new string of length len with val inStr
char *copy_str(char *inStr, short len){
	char *c = malloc((len+1)*sizeof(char));
	for (int i = 0; i<len; i++){
		c[i] = *inStr;
		inStr++;
	}
	c[len] = 0;
	return (c);
}
	
char **tokenize(char *str){
	int size = count_tokens(str);
	char **c = (char**)malloc((size+1) * sizeof(char*));
	for (int i = 0; i<size; i++){
		str= token_start(str);
		char *temp = token_terminator(str);
		char len = temp-str;
		char *t = copy_str(str, len);
		c[i]  = t;
		str = token_terminator(str);
	}	
	c[size] = 0;
	return c;
}


void print_tokens(char **tokens){
	while (*tokens != 0){
		char *t = *tokens;
		while (*t != 0){
			printf("%c", *t);
			*t++;
		}
		putchar('\n');
		tokens++;
	}
}

void free_tokens(char **tokens){
	
}
