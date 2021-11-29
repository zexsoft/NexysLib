#include "nexys_driver.h"

#define baseIO_Ainit 0x80001408     // Base IO initialization address (docs)
#define baseIO_start 0x0000FFFF     // Base IO initialization value
                                    // Low 16 outputs => 4 nibbles for LEDs (output => FFFF)
                                    // High 16 inputs => 4 nibbles for switches (input => 0000)

#define switch_Amain 0x80001400     // Switches main IO address (docs)
#define LEDs_Amain 0x80001404       // LEDs main IO address (docs)

void baseIO_init() {                            // Initializes base GPIO
    WRITE_GPIO(baseIO_Ainit, baseIO_start);
}

int switch_read() {                             // Returns switches states in lower nibbles
    return READ_GPIO(switch_Amain) >> 16;       // Output switches input shifted from high to low nibbles
                                                // 0xFFFF0000 => 0x0000FFFF (1 bit => 1 switch)
}

void LEDs_value(int val) {                      // Sets LEDs states from lower nibbles
    WRITE_GPIO(LEDs_Amain, val);                // Write values to LEDs (1 bit => 1 LED)
}