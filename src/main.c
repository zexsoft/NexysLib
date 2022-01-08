#include "nexys_driver.c"
#include "disp_driver.c"

// Example program for Nexys A7

int main()
{
    baseIO_init();
    disp_init();
    
    while (1) { 
        disp_dec_value(switch_read());
    }
    
    return 0;
}
