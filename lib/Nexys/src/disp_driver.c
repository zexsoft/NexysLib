// Nexys A7 - 8-Segment display driver
#include "nexys_driver.c"

#define disp_Amain 0x8000103C                       // Main IO address
#define disp_Ainit 0x80001038                       // Initialization address
#define disp_start 0x00000000                       // Initialization value

void disp_init() {                                  // Initializes display
    WRITE_GPIO(disp_Ainit, disp_start);             // Power all digits
}

void disp_init_value(int val) {                     // Initializes display
    WRITE_GPIO(disp_Ainit, val);                    // Power specified digits
                                                    // (1 bit -> 1 digit)
}

void disp_hex_value(int val) {                      // Displays int value as HEX
    WRITE_GPIO(disp_Amain, val);
}

void disp_dec_value(int val) {                      // Displays int value as DEC
    int val2 = 0, pow = 0;

    // Convert from DEC to DEC as HEX
    while (val > 0) {
        val2 += (val%10) * 1 << pow;

        pow += 4;
        val /= 10;
    }

    WRITE_GPIO(disp_Amain, val2);
}

void disp_char_value(char val) {                    // Displays ASCII char [PLACEHOLDER]

}

void disp_str_value(char *s, int l) {               // Displays string [PLACEHOLDER]
    for (int i=0;i<l;i++) {
        
    }
}
