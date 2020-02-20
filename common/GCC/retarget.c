#include "UrtLib.h"

// Retargetting printf for the GCC toolchain.
int _write(int file, char *ptr, int len)
{
    int count = 0;
    while(count != len)
    {
        UrtTx(pADI_UART0, *(ptr + count));
        while(!(pADI_UART0->COMLSR & BITM_UART_COMLSR_TEMT));
        count += 1;
    }
    return len;
}
