// Nexys A7 - Base IO driver
#ifndef NEXYS
#define NEXYS

// Macro definitions
#define READ_GPIO(dir) (*(volatile unsigned *)dir)
#define WRITE_GPIO(dir, value) { (*(volatile unsigned *)dir) = (value); }

void baseIO_init();

int switch_read();

void LEDs_value(int val);

#endif