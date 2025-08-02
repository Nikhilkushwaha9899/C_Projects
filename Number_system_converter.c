#include <stdio.h>

void toBinary(int n) {
    int binary[32];
    int i = 0;
    if (n == 0) {
        printf("0");
        return;
    }
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    // Print binary in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Decimal: %d\n", decimal);

    printf("Binary: ");
    toBinary(decimal);
    printf("\n");

    printf("Octal: %o\n", decimal);        // %o prints octal in C
    printf("Hexadecimal: %X\n", decimal);  // %X prints hex in uppercase

    return 0;
}
