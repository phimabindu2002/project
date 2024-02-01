#include <stdio.h>
#include <stdint.h>

// The S-Box to be tested
const uint8_t sbox[256] =  { 103, 244, 218, 35, 116, 49, 105, 118, 202, 182, 13, 198, 159, 150, 92, 140, 
247, 127, 4, 226, 95, 100, 137, 2, 245, 40, 115, 179, 142, 63, 65, 98, 
237, 170, 193, 43, 78, 132, 135, 209, 189, 240, 176, 57, 191, 211, 32, 128, 
223, 15, 175, 48, 164, 203, 190, 66, 155, 177, 102, 104, 111, 14, 233, 236, 
147, 234, 124, 212, 33, 119, 161, 184, 56, 34, 143, 87, 90, 204, 70, 0, 
121, 230, 117, 162, 53, 21, 39, 9, 166, 67, 101, 60, 79, 6, 38, 145, 
85, 10, 113, 213, 183, 242, 22, 235, 11, 12, 141, 126, 108, 238, 47, 154, 
62, 139, 160, 112, 58, 136, 194, 195, 59, 107, 254, 64, 1, 80, 134, 250, 
192, 3, 231, 201, 42, 74, 146, 197, 97, 157, 88, 222, 248, 149, 45, 61, 
239, 148, 77, 89, 173, 44, 214, 16, 187, 220, 172, 205, 20, 52, 180, 19, 
229, 133, 106, 144, 86, 129, 156, 51, 206, 30, 208, 232, 215, 196, 178, 81, 
185, 152, 8, 55, 41, 130, 252, 94, 138, 76, 93, 171, 167, 228, 75, 123, 
96, 221, 169, 5, 37, 120, 217, 181, 125, 91, 241, 210, 153, 168, 251, 50, 
110, 109, 255, 253, 68, 7, 249, 36, 246, 72, 188, 18, 243, 99, 54, 165, 
174, 186, 83, 163, 69, 31, 71, 73, 131, 24, 27, 23, 158, 84, 82, 216, 
224, 25, 122, 219, 199, 26, 114, 29, 46, 227, 17, 207, 225, 151, 200, 28};

int main()
{
    int delta_u, delta_v, x, y, z;
    int max_differential = 0;
    int nonlinearity = 0; // Nonlinearity
    int min_abs_diff = 256;
    int differential_uniformity = 0; // Differential Uniformity
    int bijectivity = 1; // Bijectivity
    int sac = 0; // Strict Avalanche Criterion
    int bic = 0; // Bit Independence Criterion
    int n = 256;

    // Differential Probability Table
    int ddt[256][256] = {0};

    // Iterate over all possible input differences
    for (delta_u = 1; delta_u < 256; delta_u++) {

        // Iterate over all possible input values
        for (x = 0; x < 256; x++) {

            // Calculate output difference
            delta_v = sbox[x] ^ sbox[x ^ delta_u];

            // Increment probability count in DDT
            ddt[delta_u][delta_v]++;
        }
    }

    // Find the maximum differential probability
    for (delta_u = 1; delta_u < 256; delta_u++) {
        for (delta_v = 1; delta_v < 256; delta_v++) {
            if (ddt[delta_u][delta_v] > max_differential) {
                max_differential = ddt[delta_u][delta_v];
                sac++; // Increment SAC
            }
            if (ddt[delta_u][delta_v] < min_abs_diff) {
                min_abs_diff = ddt[delta_u][delta_v];
            }
            if (ddt[delta_u][delta_v] == 0) {
                bijectivity = 0; // Not bijective
            }
        }
    }

    // Calculate Nonlinearity
    nonlinearity = 128 - (max_differential / 2);

    // Calculate Differential Uniformity
    differential_uniformity = (n - min_abs_diff) / 2;

    // Calculate BIC
    bic = 256 - max_differential;

    // Print the results
    printf("Nonlinearity: %d\n", nonlinearity);
    printf("Differential Uniformity: %d\n", differential_uniformity);
    printf("Bijectivity: %s\n", (bijectivity == 1) ? "Yes" : "No");
    printf("SAC: %d\n", sac);
    printf("BIC: %d\n", bic);
    printf("Differential Probability: %f\n", (float)max_differential / n);

    return 0;
}

