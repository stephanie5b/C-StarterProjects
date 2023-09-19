/*
 * TemperatureConverter
 *
 * A simple program to convert temperatures 
 * between Celsius and Fahrenheit based on 
 * the user's choice.
 *
 */
 
#include <stdio.h>

int main(void) {
    // Variables
    double userTemp;
    int userChoiceOfTemp;
    double conversion;

    // Get user input for temperature
    printf("Enter a temperature: ");
    scanf("%lf", &userTemp);

    // Prompt user for conversion choice
    printf("\n1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\nChoose an option (1/2): ");
    scanf("%d", &userChoiceOfTemp);

    // Perform conversion based on choice
    switch (userChoiceOfTemp) {
        case 1: // Fahrenheit to Celsius
            conversion = (userTemp - 32.0) * 5.0/9.0;
            printf("\n%.1lf°C", conversion);
            break;
        case 2: // Celsius to Fahrenheit
            conversion = userTemp * 9.0/5.0 + 32.0;
            printf("\n%.1lf°F", conversion);
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}
