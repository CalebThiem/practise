#include <stdio.h>
#include <stdint.h>

#define MAX_INPUT_LENGTH 17

// Define array to store user input

char userInput[MAX_INPUT_LENGTH];

void getInput(void);

// Prototype of function to check that user input is valid 

uint8_t checkInput(char *);

// Prototype of function to identify the issuer of the credit card

uint8_t identifyCard(char *);

// **TO DO**

int main()
    {
        getInput();

        while (checkInput(userInput) == 0)
        {
            getInput();
        }

        printf("%s", userInput);
    }

// Requests input from user and stores it in userInput char array

void getInput(void)
{
    printf("Number: ");
    
    fgets(userInput, MAX_INPUT_LENGTH, stdin); 

}

// Checks to see if each character in the user input is a number between 0 and 9

uint8_t checkInput(char *userInput)
{
    uint8_t i = 0;

    while (i < MAX_INPUT_LENGTH)
    {
        if ((int) (userInput[i]) < 0 || (int) (userInput[i]) > 9)
        {
            if (userInput[i] != '\0')
            {
            return 0;
            }
        }

        else 
        {
            i += 1;

            continue;
        }
    }

    // printf("%s", userInput);
    return 1;
}

// Uses Luhn's algorithm to check card number validity and identify issuer **TO DO**

uint8_t identifyCard(char *userInput)
{
    return 1;
}
