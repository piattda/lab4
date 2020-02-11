/*
	NAME: David Piatt
	DATE: 2/19/17
	CLASS: CSE 2421, M/W 4:15p
	
	This program encrypts the characters pointed to at by the pointer to word. It applies the bitwise xor operator between the char and the key provided by the function calling it. 
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xorencrypt(char * word, char * key){
    //make unsigned char array to stor values. Unsigned lets us use negative int values and store bigger ints. 
    unsigned char * toReturn = malloc((strlen(word)+1)*sizeof(char));
    int i, c=0;
    //the key in hexadecimal form
    unsigned int key_hex;
    key_hex = strtol(key, NULL ,16);
    
    //populate the toReturn array with the characters from the word array after the xor function is applied to them. 
    for(i = 0; i < strlen(word); i ++){
        c = word[i];
        toReturn[i] = (c ^ key_hex);    
     }    
    //add a terminating character to the end of the array. I know it can have terminating chars in the input and they will remain terminating characters but I feel like this is good practice. 
    toReturn[strlen(word)] = '\0';
    printf("%s\n",toReturn);
    //we free the used memory because we're good people
    free(toReturn);
}

