#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CARD_LENGTH 16

// Allow for newline character and null terminator (appended by fgets())

#define MAX_ARRAY_LENGTH MAX_CARD_LENGTH + 2

int newLineSearch(char * userInput);

int numberValid = 0; 

int main(void)
{
    while (numberValid == 0)
    {
        char userInput[MAX_ARRAY_LENGTH];

        printf("Number: ");

        fgets(userInput, MAX_ARRAY_LENGTH, stdin);

        // Check if the user inputted a value MAX_CARD_LENGTH characters long

        if (newLineSearch(userInput) == 1)
        {
            /* Write number checking function **TO DO**
            if (checkNumber == 1)
                numberValid = 1;           
            else {
                break;
            }
            */
        } else {

            /* If fgets wrote to the array without including a return character
             then empty the sdtin buffer by making more fgets calls. When 
             buffer is empty (indicated by presence of newline character,  
             go to start of loop and request new input. */
             
            do {
                fgets(userInput, MAX_ARRAY_LENGTH, stdin);
            }
            while (newLineSearch(userInput) == 0);
        
            continue;
        }
    }
}

// Checks array for newline character, if present returns 1

int newLineSearch(char * userInput)
{
    for (int i = 0; i <= MAX_ARRAY_LENGTH; i++)
    {
       if (userInput[i] == '\n')
       {
        return 1;
       }
    }

    return 0;
}
