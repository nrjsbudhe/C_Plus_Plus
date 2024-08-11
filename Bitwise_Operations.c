
#include <stdio.h>
#include <stdint.h>

void printBinary(unsigned n) {
    if (n > 1)
        printBinary(n >> 1);
    printf("%d", n & 1);
}

int main() {
    uint8_t num = 0b10000001;
    uint8_t bit4 = num & (1<<3);
    uint8_t bit8 = num & (1<<7);

    bit4 = (bit4<<4);
    bit8 = (bit8>>4);
    printBinary(num);
    printf("\n");
    printBinary(bit4);
    printf("\n");
    printBinary(bit8);
    printf("\n");

    if (bit4 != 0)
    {
        num |= bit4;
    }
    else
    {
        num &= ~(1<<7);
    }

    if (bit8 != 0){
        num |= bit8;
    }
    else
    {
        num &= ~(1<<3);
    }

    printBinary(num);
    return 0;
    
}