#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CARD_LENGTH 16

// Allow for newline character and null terminator (appended by fgets())

#define MAX_ARRAY_LENGTH MAX_CARD_LENGTH + 2

int new_line_search(char * userInput);

int check_input(char * userInput, int inputLength);

int check_luhn(char * userInput, int inputLength);

int add_digits(char * digitList, int multiply);

int identify_card(char * userInput, int inputLength);

int numberValid = 0; 

int main(void)
{
    while (numberValid == 0)
    {
        char userInput[MAX_ARRAY_LENGTH];

        printf("Number: ");

        fgets(userInput, MAX_ARRAY_LENGTH, stdin);

        // Check if the user inputted a value MAX_CARD_LENGTH characters long

        if (new_line_search(userInput) == 1)
        {
            int inputLength = strlen(userInput);

            if (check_input(userInput, inputLength) == 1)
            {
                if (check_luhn(userInput, inputLength) == 1)
                {       
                    numberValid = 1; 

                    switch (identify_card(userInput, inputLength)) {
                        case 1: 
                            printf("VISA\n");
                            break;
                        case 2:
                            printf("MASTERCARD\n");
                            break;
                        case 3:
                            printf("AMEX\n");
                            break; 
                        case 0:
                            printf("INVALID\n");
                            break;
                    }
                }
                else {
                    printf("INVALID\n");
                    break;
                }

            }
        } else {

            /* If fgets wrote to the array without including a return character
             then empty the sdtin buffer by making more fgets calls. When 
             buffer is empty (indicated by presence of newline character,  
             go to start of loop and request new input. */
             
            do {
                fgets(userInput, MAX_ARRAY_LENGTH, stdin);
            }
            while (new_line_search(userInput) == 0);
        
            continue;
        }
    }
}

// Checks array for newline character, if present returns 1

int new_line_search(char * userInput)
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

int check_input(char * userInput, int inputLength)
{
    for (int i = 0; i < inputLength - 1; i++)
    {
        if (isdigit(userInput[i]) == 0)
        { 
            return 0;
        }
    }

    return 1;
}

int check_luhn(char * userInput, int inputLength)
{
    // Ignore newline character at end of string

    inputLength--;

    // Copy every other character to evens, copy the rest to odds
    
    char evens[(inputLength % 2) + 1];

    char odds[(inputLength % 2) + 1];

        int i = 0;
        int j = 0;

        for (; i <= inputLength - 2; i = i + 2)
        {
            evens[j] = userInput[(i + 1)];

            j++;
        }

        // End the string with a NUL byte

        evens[j++] = '\0';
        
        i = 0;  
        j = 0;

        for (; i <= inputLength - 1; i = i + 2)
        {
            odds[j] = userInput[i];
            j++;
        }
        
        odds[j] = '\0';

        int luhn = 0;

        if (inputLength % 2 == 0)
        {
            luhn = add_digits(odds, 1);
            luhn = luhn + add_digits(evens, 0);
        }
        else {
            luhn = add_digits(evens, 1);
            luhn = luhn + add_digits(odds, 0);
        }

    if (luhn % 10 == 0) 
    {
        return 1;
    } else {
        return 0;
    }

}

int add_digits(char * digitList, int multiply)
{
    int inputLength = strlen(digitList);

    char stepOneString[inputLength];

    stepOneString[0] = '\0';

    char numbers;

    int evensLen = strlen(digitList);

    for (int k = 0; k < evensLen; k++)
    {
        int tempInt = 0;

        tempInt = digitList[k] - '0';

        if (multiply == 1)
        {
            tempInt = tempInt * 2;
        }

        char tempString[3];

        sprintf(tempString, "%d", tempInt);

        strcat(stepOneString, tempString);
    } 

    int stepOneStringLen = strlen(stepOneString); 

    int stepTwoInt = 0;

    for (int k = 0; k < stepOneStringLen; k++) 
    {
        stepTwoInt = stepTwoInt + (stepOneString[k] - '0');
    }

    return stepTwoInt;
}

int identify_card(char * userInput, int inputLength)
{
    if (userInput[0] == '4' && (((inputLength - 1) == 13) || ((inputLength - 1) == 16)))
    {
        return 1;
    }

    if (userInput[0] == '5' && ((inputLength - 1) == 16))
    {
        switch (userInput[1]) {
            case '1':
                return 2;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 2;
                break;
            case '4':
                return 2;
                break;
            case '5':
                return 2;
                break;
        }
    }

    if (userInput[0] == '3' && ((inputLength - 1) == 15))
    {
        switch (userInput[1]) {
            case '4':
                return 3;
                break;
            case '7':
                return 3;
                break;
        }
    }

    return 0;
        
}