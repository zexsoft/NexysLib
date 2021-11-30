#include "nexys_driver.c"
#include "disp_driver.c"

int main()
{
    baseIO_init();
    disp_init();
    
    while (1) { 
        disp_hex_value(switch_read());
    }
    
    return 0;
}
