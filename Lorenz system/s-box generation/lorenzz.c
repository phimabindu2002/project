#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Lorenz system equations for unsigned int
void lorenz_system(unsigned int x, unsigned int y, unsigned int z, unsigned int u, double a, double b, double c, double k, unsigned int *dx, unsigned int *dy, unsigned int *dz, unsigned int *du) {
    *dx = (unsigned int)(-a * (y - x));
    *dy = (unsigned int)(-c * x - y - x * z + u);
    *dz = (unsigned int)(-x * y - b * z);
    *du = (unsigned int)(-k * x);
}

// Runge-Kutta method for system iteration with unsigned int
void runge_kutta(unsigned int *x, unsigned int *y, unsigned int *z, unsigned int *u, double a, double b, double c, double k, double h) {
    unsigned int dx1, dy1, dz1, du1;
    unsigned int dx2, dy2, dz2, du2;
    unsigned int dx3, dy3, dz3, du3;
    unsigned int dx4, dy4, dz4, du4;

    lorenz_system(*x, *y, *z, *u, a, b, c, k, &dx1, &dy1, &dz1, &du1);
    lorenz_system(*x + (unsigned int)(0.5 * h * dx1), *y + (unsigned int)(0.5 * h * dy1), *z + (unsigned int)(0.5 * h * dz1), *u + (unsigned int)(0.5 * h * du1), a, b, c, k, &dx2, &dy2, &dz2, &du2);
    lorenz_system(*x + (unsigned int)(0.5 * h * dx2), *y + (unsigned int)(0.5 * h * dy2), *z + (unsigned int)(0.5 * h * dz2), *u + (unsigned int)(0.5 * h * du2), a, b, c, k, &dx3, &dy3, &dz3, &du3);
    lorenz_system(*x + (unsigned int)(h * dx3), *y + (unsigned int)(h * dy3), *z + (unsigned int)(h * dz3), *u + (unsigned int)(h * du3), a, b, c, k, &dx4, &dy4, &dz4, &du4);

    *x += (unsigned int)(h / 6.0 * (dx1 + 2.0 * dx2 + 2.0 * dx3 + dx4));
    *y += (unsigned int)(h / 6.0 * (dy1 + 2.0 * dy2 + 2.0 * dy3 + dy4));
    *z += (unsigned int)(h / 6.0 * (dz1 + 2.0 * dz2 + 2.0 * dz3 + dz4));
    *u += (unsigned int)(h / 6.0 * (du1 + 2.0 * du2 + 2.0 * du3 + du4));
}

// Shuffling function to randomize the array
void shuffle(unsigned int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            unsigned int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Generate S-box based on the hyperchaotic system with balanced and unrepeated output
void generate_balanced_sbox(double a, double b, double c, double k, int iterations, unsigned int sbox[16][16]) {
    int i, j;
    unsigned int x, y, z, u;

    // Set initial values and parameters
    x = 10;
    y = 10;
    z = 10;
    u = 10;

    // Initialize array of possible output values
    unsigned int possible_outputs[256];
    for (i = 0; i < 256; ++i) {
        possible_outputs[i] = i;
    }

    // Iterate the system
    for (i = 0; i < iterations; ++i) {
        // Runge-Kutta method for N iterations
        for (j = 0; j < 200; ++j) {
            runge_kutta(&x, &y, &z, &u, a, b, c, k, 0.01);
        }

        // Obtain the next possible output value
        unsigned int output_value = (unsigned int)(x * y * z * u) % 256;
        
        // Swap the obtained output value with the last possible value
        unsigned int temp = possible_outputs[i % 256];
        possible_outputs[i % 256] = possible_outputs[output_value];
        possible_outputs[output_value] = temp;
    }

    // Convert the obtained values into a 16x16 S-box
    for (i = 0; i < 16; ++i) {
        for (j = 0; j < 16; ++j) {
            sbox[i][j] = possible_outputs[i * 16 + j];
        }
    }
}

int main() {
    double a = 10.0;
    double b = 8.0 / 3.0;
    double c = 28.0;
    unsigned int balanced_sbox[16][16];
    generate_balanced_sbox(a, b, c, 16.6, 5000, balanced_sbox);

    // Print the generated balanced and unrepeated S-box
    printf("Generated Balanced and Unrepeated S-box:\n");
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            printf("%u ", balanced_sbox[i][j]);
        }
        printf("\n");
    }

    return 0;
}

