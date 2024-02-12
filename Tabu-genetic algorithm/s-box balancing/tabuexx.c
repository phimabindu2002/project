#include <stdio.h>

int main() {
    int n = 256;
    int a, b;
    int s[256] = {182, 89, 231, 62, 145, 240, 102, 191, 94, 49, 220, 137, 97, 60, 193, 13, 28, 6, 104, 214, 160, 161, 50, 22, 202, 27, 178, 70, 168, 253, 218, 237, 86, 20, 169, 80, 108, 90, 109, 154, 252, 208, 118, 29, 38, 135, 251, 63, 158, 17, 114, 87, 66, 115, 76, 91, 238, 142, 221, 146, 33, 141, 41, 233, 219, 18, 11, 176, 183, 99, 151, 250, 210, 55, 147, 223, 23, 203, 68, 205, 194, 111, 138, 96, 71, 213, 10, 196, 225, 153, 122, 24, 144, 155, 15, 2, 31, 101, 125, 52, 255, 152, 215, 3, 0, 117, 186, 58, 106, 129, 32, 195, 236, 105, 166, 14, 59, 72, 121, 8, 30, 25, 35, 83, 19, 131, 110, 75, 113, 234, 81, 254, 190, 134, 192, 36, 156, 189, 16, 48, 124, 37, 51, 64, 139, 235, 103, 209, 84, 69, 140, 187, 177, 116, 204, 239, 148, 206, 167, 245, 212, 229, 248, 127, 107, 92, 39, 143, 197, 85, 184, 201, 171, 12, 247, 78, 243, 57, 98, 82, 26, 46, 9, 95, 217, 73, 44, 159, 246, 163, 67, 200, 188, 207, 198, 132, 5, 216, 100, 54, 227, 172, 93, 164, 128, 179, 244, 112, 7, 40, 79, 170, 119, 175, 242, 232, 43, 199, 123, 53, 136, 126, 61, 56, 228, 173, 149, 165, 65, 150, 222, 157, 120, 34, 45, 42, 133, 241, 230, 88, 47, 174, 21, 180, 1, 185, 249, 130, 77, 181, 226, 211, 74, 162, 224, 4};
    int y1[256], y2[256], y3[256], y4[256], y5[256], y6[256], y7[256], y8[256]; // Declare arrays y1, y2, ..., y8

    for (int i = 0; i < n; i++) {
        int output_mask = s[i];
        y1[i] = (output_mask & (1 << 7)) / 128;
        y2[i] = (output_mask & (1 << 6)) / 64;
        y3[i] = ((output_mask) & (1 << 5)) / 32;
        y4[i] = (output_mask) & (1 << 4) / 16;
        y5[i] = (output_mask) & (1 << 3) / 8;
        y6[i] = (output_mask) & (1 << 2) / 4;
        y7[i] = (output_mask) & (1 << 1) / 2;
        y8[i] = (output_mask) & (1 << 0) / 1;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int z1 = 0;
    int o1 = 0;
    for (int i = 0; i < 256; i++) {
        if (y1[i] == 0) {
            zeroCount++;
            z1 = zeroCount;
        } else if (y1[i] == 1) {
            oneCount++;
            o1 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z2 = 0;
    int o2 = 0;
    for (int i = 0; i < 256; i++) {
        if (y2[i] == 0) {
            zeroCount++;
            z2 = zeroCount;
        } else if (y2[i] == 1) {
            oneCount++;
            o2 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z3 = 0;
    int o3 = 0;
    for (int i = 0; i < 256; i++) {
        if (y3[i] == 0) {
            zeroCount++;
            z3 = zeroCount;
        } else if (y3[i] == 1) {
            oneCount++;
            o3 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z4 = 0;
    int o4 = 0;
    for (int i = 0; i < 256; i++) {
        if (y4[i] == 0) {
            zeroCount++;
            z4 = zeroCount;
        } else if (y4[i] == 1) {
            oneCount++;
            o4 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z5 = 0;
    int o5 = 0;
    for (int i = 0; i < 256; i++) {
        if (y5[i] == 0) {
            zeroCount++;
            z5 = zeroCount;
        } else if (y5[i] == 1) {
            oneCount++;
            o5 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z6 = 0;
    int o6 = 0;
    for (int i = 0; i < 256; i++) {
        if (y6[i] == 0) {
            zeroCount++;
            z6 = zeroCount;
        } else if (y6[i] == 1) {
            oneCount++;
            o6 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z7 = 0;
    int o7 = 0;
    for (int i = 0; i < 256; i++) {
        if (y7[i] == 0) {
            zeroCount++;
            z7 = zeroCount;
        } else if (y7[i] == 1) {
            oneCount++;
            o7 = oneCount;
        }
    }
    zeroCount = 0;
    oneCount = 0;
    int z8 = 0;
    int o8 = 0;
    for (int i = 0; i < 256; i++) {
        if (y8[i] == 0) {
            zeroCount++;
            z8 = zeroCount;
        } else if (y8[i] == 1) {
            oneCount++;
            o8 = oneCount;
        
    }
    if (z1 == 128 && o1 == 128 && z2 == 128 && o2 == 128 && z3 == 128 && o3 == 128 && z4 == 128 && o4 == 128 && z5 == 128 && o5 == 128 && z6 == 128 && o6 == 128 && z7 == 128 && o7 == 128 && z8 == 128 && o8 == 128) {
        printf("Dickson s box is balanced");
    } else {
        printf("Dickson s box is not balanced");
    }
    return 0;
}
}
