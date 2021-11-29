#include "nexys_driver.h"
#include "disp_driver.h"

int main()
{
    baseIO_init();
    disp_init();
    
    while (1) { 
        disp_hex_value(switch_read());
    }
    
    return 0;
}
