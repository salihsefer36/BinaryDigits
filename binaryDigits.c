#include <stdio.h>
#include <string.h>
#include <math.h>

int bit_count;
char binary_input[65];

void CheckAndPrintBinaryNumber()
{
    printf("Please enter your number's bit: ");
    scanf("%d", &bit_count);

    printf("Please enter %d bit binary number : ", bit_count);
    scanf("%s", binary_input);

    int input_length = strlen(binary_input);

    if (input_length != bit_count) {
        printf("Error: The binary number you entered does not fit within the specified length of %d bits\n", bit_count);
        return;
    }

    int decimal_value = 0;
    int is_negative = (binary_input[0] == '1');

    if (is_negative) {
        for (int i = 0; i < bit_count; i++) {
            if (binary_input[i] == '1') {
                decimal_value += (int)pow(2, bit_count - 1 - i);
            } else if (binary_input[i] != '0') {
                printf("Error: The binary number you entered is not valid\n");
                return;
            }
        }

        decimal_value -= (int)pow(2, bit_count);
    } else {
        for (int i = 0; i < bit_count; i++) {
            if (binary_input[i] == '1') {
                decimal_value += (int)pow(2, bit_count - 1 - i);
            } else if (binary_input[i] != '0') {
                printf("Error: The binary number you entered is not valid\n");
                return;
            }
        }
    }

    printf("Your binary number: %s\n", binary_input);
    printf("Converted to decimal number: %d\n", decimal_value);
}

int main() 
{
    CheckAndPrintBinaryNumber();
    return 0;
}