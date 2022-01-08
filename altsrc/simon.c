#include "nexys_driver.c"
#include "disp_driver.c"

#define choices 4
#define bounce_delay 1000000
#define short_delay 5000000
#define long_delay 8500000

// 'Simon says' program for Nexys A7

int delay;

int main()
{
    // Initialize switches, LEDs and display
    baseIO_init();
    disp_init();
    
    disp_hex_value(0);
    LEDs_value(0);

    int seed = 7;       // Seed for random (randomized through delays)
    int n = 0, v[1005];
    while (1) { 
        // Generate inital sequence
        for(int i=0;i<=long_delay;i++);
        disp_hex_value(0);
        n = 1;
        srand(seed);
        v[0] = 1 << (rand() % choices);

        // Main loop
        int ok = 1;
        while (ok == 1) {
            // Show sequence
            LEDs_value(0);
            disp_hex_value(0xBE6);
            for(int i=0;i<=long_delay;i++);
            for (int i=0;i<n;i++) {
                LEDs_value(v[i]);
                disp_dec_value(i+1);                    // Count on display

                for(int j=0;j<=short_delay;j++);
            }
            LEDs_value(0);
            
            disp_hex_value(0x5EC); 
            for(int j=0;j<=long_delay;j++);
            // Check sequence
            for (int i=0;i<n;i++) {
                int r = switch_read();
                disp_dec_value(i+1);                    // Count on display

                while (r == switch_read()) seed++;      // Seed random through delay
                for (int j=1;j<=bounce_delay;j++);      // Delay to prevent bounce

                // Get changed switch & check it
                int val = r ^ switch_read();
                if (val != v[i]) { ok = 0; i = n; }
            }

            // Show result
            if (ok) {
                disp_hex_value(0x600D);
                LEDs_value(0xFFFF);
            }
            else {
                disp_hex_value(0xBAD);
                LEDs_value(0xAAAA);
            }

            for(int j=0;j<=8500000;j++);
            
            // Add to sequence
            v[n++] = 1 << (rand() % choices);
            srand(seed);	// Reseed random
        }
    }

    return 0;
}
