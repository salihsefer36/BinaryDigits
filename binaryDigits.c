#include <stdio.h>
#include <string.h>
#include <math.h>

int bit_count;
char binary_input1[65], binary_input2[65];

int ConvertBinaryToDecimal(const char* binary_input, int bit_count) {
    int decimal_value = 0;
    int is_negative = (binary_input[0] == '1');

    if (is_negative) {
        for (int i = 0; i < bit_count; i++) {
            if (binary_input[i] == '1') {
                decimal_value += (int)pow(2, bit_count - 1 - i);
            } else if (binary_input[i] != '0') {
                printf("Error: The binary number you entered is not valid\n");
                return 0;
            }
        }
        decimal_value -= (int)pow(2, bit_count);
    } else {
        for (int i = 0; i < bit_count; i++) {
            if (binary_input[i] == '1') {
                decimal_value += (int)pow(2, bit_count - 1 - i);
            } else if (binary_input[i] != '0') {
                printf("Error: The binary number you entered is not valid\n");
                return 0;
            }
        }
    }

    return decimal_value;
}

void CheckAndPrintBinarySum() {
    printf("Please enter your number's bit count: ");
    scanf("%d", &bit_count);

    printf("Please enter the first %d-bit binary number: ", bit_count);
    scanf("%s", binary_input1);

    if (strlen(binary_input1) != bit_count) {
        printf("Error: The binary number you entered does not fit within the specified length of %d bits\n", bit_count);
        return;
    }

    printf("Please enter the second %d-bit binary number: ", bit_count);
    scanf("%s", binary_input2);

    if (strlen(binary_input2) != bit_count) {
        printf("Error: The binary number you entered does not fit within the specified length of %d bits\n", bit_count);
        return;
    }

    int decimal1 = ConvertBinaryToDecimal(binary_input1, bit_count);
    int decimal2 = ConvertBinaryToDecimal(binary_input2, bit_count);

    int sum = decimal1 + decimal2;
    int subtract = decimal1 - decimal2;
    int product = decimal1 * decimal2;
    float division = decimal1 / decimal2;
    int modulus = decimal1 % decimal2;

    printf("First binary number: %s\n", binary_input1);
    printf("Second binary number: %s\n", binary_input2);
    printf("First Number + Second Number: %d\n", sum);
    printf("First Number - Second Number: %d\n", subtract);
    printf("First Number * Second Number: %d\n", product);
    printf("First Number / Second Number: %.2f\n", division);
    printf("First Number modulus Second Number: %d\n", modulus);
}

int main() {
    CheckAndPrintBinarySum();
    return 0;
}