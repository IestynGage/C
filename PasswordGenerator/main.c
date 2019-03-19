/*--------------------------------------------------------------------
 * Password Generator
 * -------------------------------------------------------------------
 * Name: Iestyn Gage
 * Date of creation :15/08/2018
 * Desc: This project was developed to create a password generator that can
 * be easily customised i.e. password length, characters used.
 *
 * -------------------------------------------------------------------
 * File Structure
 * --------------------------------------------------------------------
 * 1.Pre-Processor
 * 2.Variables
 * 3.Functions
 * 4.Main
 */

/* -------------------------------------------------------------------
 *  Pre-Processor
 * -------------------------------------------------------------------
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define GENERATING_CHAR

#define LETTERS 50
#define LETTERS_NUMBERS 59
#define LETTERS_NUMBERS_SYMBOLS 74

/*-------------------------------------------------------------------
 * Variables
 * -------------------------------------------------------------------
 */

/*______________________________
 * totalCharacters
 * Used to hold the total possible characters
 * letters = 50, letters+numbers = 59, Letters+numbers+Symbols = 74
 */
int totalCharacters = LETTERS_NUMBERS;

/* -------------------------------------------------------------------
 * Functions
 * -------------------------------------------------------------------
 */

/*__________________________________
 * randomNumber
 *
 * Generates an integer dependent on the total characters
 */
int randomNumber(){
    int divider = RAND_MAX / totalCharacters;
    int number = rand() / divider;

    return number;
}

/*___________________________________________
 *IntegerConvertToCharacter
 *
 *
 * After recieveing integer should transfere it into a
 * character. Needs to be able to deal with different amount of possible characters
 * The function skips tries to sky all characters that won't be accepted
 */
char ConvertToLetter(int inputInteger){
    int processedInteger = inputInteger;
    if(totalCharacters == LETTERS){
        processedInteger +=65;

        if(processedInteger>90){
            processedInteger+=6;
        }
    }

    if(totalCharacters == LETTERS_NUMBERS){
        processedInteger +=48;

        if(processedInteger>57){
            processedInteger+=7;
        }
        if(processedInteger>90){
            processedInteger+=6;
        }
    }

    if(totalCharacters == LETTERS_NUMBERS_SYMBOLS){
        processedInteger+=48;
    }
    char c = (char) processedInteger;

    #ifdef GENERATING_CHAR
        printf("Input: %2d Processed: %3d ASCII: %c\n",inputInteger,processedInteger,c);
    #endif

    return c;
}

/* ___________________________________________
 * PasswordGenerator
 *
 *
 */
void PasswordGenerator(int passwordLength,char password[]){
    passwordLength= passwordLength - 1;

    for(int i=0; i<=passwordLength; i++){
        int rmdInt = randomNumber();
        char c = ConvertToLetter(rmdInt);
        password[i] = c;
    }
    password[passwordLength+1] = '\0';// ends the "String"
}

/* -------------------------------------------------------------------
 *  main()
 *  -------------------------------------------------------------------
 */
int main() {
    srand(time(NULL));
    //------------------------------
    int passwordLength = 8;
    char password[passwordLength+1];

    PasswordGenerator(passwordLength,password);

    printf("Password: %s\n",password);

}