
/*
	NAME: David Piatt
	DATE: 2/19/17
	CLASS: CSE 2421, M/W 4:15p
	This program takes user input and determines to apply the caesar cipher, xor encryption, or reports an error. It also checks for a -k or -r extension to change the default rotation or encryption and retports an error if the -k or -r is -something_else
	
	There are probably cases I haven't checked for but I have a midterm to study for. 
	

*/
#include <stdio.h>
#include "caesar.h"
#include "xor.h"
#include <string.h>
//function to remind the user what acceptable inputs are. 
void printUsage(){
    printf("You have not entered valid input\n");
    printf("Please enter ceasar or xor\n");
    printf("Please use the correct extension of -k or -r\n");
    printf("If no extension is provided then a default (r = 13, k = 0x22) will be used\n");
    printf("The program will output the encrypted input.\n");

}

int main(int argc, char **argv ){
		
    //case where caesar is called on word with default rotation.
    if((strcmp(argv[1],"caesar")== 0) && (strcmp(argv[2],"-r")!=0) && (argv[3] == NULL)){
        caesarcipher(argv[2],13);
    
    }
    //case where caesar is called with a rotation
    else if((strcmp(argv[1],"caesar")==0) && (strcmp(argv[2],"-r")==0)){
        //I'm assuming the integer isn't too big. 
        int r =13;
        sscanf(argv[3],"%d",&r);
        caesarcipher(argv[4],r);    
    
    }
    //case where xor is called with default key
    else if((strcmp(argv[1],"xor")==0)&&(strcmp(argv[2],"-k")!=0)&&(argv[3]==NULL)){
        xorencrypt(argv[2],"0x22");
    
    }
    //case where xor and key are provided
    else if((strcmp(argv[1],"xor")==0)&&(strcmp(argv[2],"-k")==0)){
        //I'm assuming the hexidecimal number is correct and that I just spelled it correctly. I don't know how to validate that it is correct. 
        xorencrypt(argv[4],argv[3]);
    }
    //case where the first argument isn't xor or caesar
    //reports error
    else if((strcmp(argv[1],"xor")!=0)&&(strcmp(argv[1],"caesar")!=0)){
        printf("Please enter a encryption function, caesar or xor, lowercase\n\n");
        printUsage();
    }
    //case where caesar is entered but invalid rotation is entered. an error message is reported.
    else if((strcmp(argv[1],"caesar") == 0) && (strcmp(argv[2],"-r")!=0)){
        printf("The proper extension to perform the caesar cipher with a rotation of r is '-r'. \n\n");
        printUsage();
    }
    //case where xor is entered but the key is wrong. An error is reported. 
    else if((strcmp(argv[1],"xor")==0)&&(strcmp(argv[2],"-k")!=0)){
        printf("The proper extension to perform the xor encryption with a key of k is '-k'. \n\n");
        printUsage();
    }
    //case where I have no idea what was inputed or going on. :(
    else{
        printf("I honestly don't know what you've entered. See the directions again. \n\n");
        printUsage();
    }
    
    return 0;   
}
