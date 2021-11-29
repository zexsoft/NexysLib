#include "disp_driver.h"
#include "nexys_driver.h"

#define disp_Amain 0x8000103C   // Main IO address
#define disp_Ainit 0x80001038   // Initialization address
#define disp_start 0x0          // Initialization value

void disp_init() {                              // Initializes display
    WRITE_GPIO(disp_Ainit, disp_start);         // Setup Display -> Output
}

void disp_init_value(int val) {                              // Initializes display
    WRITE_GPIO(disp_Ainit, val);         // Setup Display -> Output
}

void disp_hex_value(int val) {                      // Displays value in HEX
    WRITE_GPIO(disp_Amain, val);
}

void disp_char_value(char val) {                    // Displays value as ASCII char

}

void disp_str_value(char *s, int l) {               // Displays string
    for (int i=0;i<l;i++) {
        
    }
}