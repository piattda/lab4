/*
	NAME: David Piatt
	DATE: 2/19/17
	CLASS: CSE 2421, M/W 4:15p

	This program takes a pointer to a char array and rotates all letters by a key. It only rotates lower and upper case letters in the English alphabet and does not support the extended ANSII II alphabet. Please represent umlaut with an e after the letter and scharfes s by ss. 

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void caesarcipher(char * word, int r){
    //create an array to hold the new word. It needs to be 1 char bigger than the original to hold the terminating char. 
    char * toReturn = malloc((strlen(word)+ 1) * sizeof(char));
    int i, ch = 0;
    
    //iterate through the word    
    for(i = 0; i < strlen(word) + 1; i ++){   
        ch = word[i];
        
     //upper case case
     if(word[i] >= 65 && word[i] <=90){
             
             ch = ch - 65;
             ch = ch + r;
             ch = ch % 26;
             ch = ch + 65;
             toReturn[i] = ch;
    }
     //lower case case
     else if(word[i] >= 97 && word[i] <= 122 ){
            ch = ch - 97;
            ch = ch + r;
            ch = ch % 26;
            ch = ch + 97;
            toReturn[i] = ch;
    }
    //the case that the char is the empty char
    else if(word[i] == '\0'){
            toReturn[i] = '\0';
    }
    //if it's not in the regular letters then don't change it. 
    else{
            toReturn[i] = word[i];
    }

    }
    printf("%s\n", toReturn);
    //we free the array because we're good people
    free(toReturn);
}

