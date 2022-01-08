#include "nexys_driver.c"
#include "disp_driver.c"

// Simon says

int delay;

int main()
{
    // Initialize switches, LEDs and display
    baseIO_init();
    disp_init();
    
    disp_hex_value(0);
    LEDs_value(0);

    int seed = 7;
    int n = 0, v[105];
    while (1) { 
        // Generate inital sequence
        for(int i=0;i<=8500000;i++);
        disp_hex_value(0);
        n = 1;
        srand(seed);
        v[0] = 1 << (rand() % 4);

        // Main loop
        int ok = 1;
        while (ok == 1) {
            // Show sequence
            LEDs_value(0);
            disp_hex_value(0xBE6);
            for(int i=0;i<=8500000;i++);
            for (int i=0;i<n;i++) {
                LEDs_value(v[i]);
                disp_hex_value(i+1);

                for(int j=0;j<=5000000;j++);
            }
            LEDs_value(0);
            
            disp_hex_value(0x5EC); 
            for(int j=0;j<=8500000;j++);
            // Check sequence
            for (int i=0;i<n;i++) {
                int r = switch_read();
                disp_hex_value(i+1);

                while (r == switch_read()) seed++;
                for (int j=1;j<=1000005;j++);       // Delay to prevent bounce

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
            v[n++] = 1 << (rand() % 4);
            srand(seed);	// Reseed random
        }
    }

    return 0;
}
