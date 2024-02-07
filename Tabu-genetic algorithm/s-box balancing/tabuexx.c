#include <stdio.h>


int main() {
    	
    int n=256;
    int a,b;
    int s[256] ={30, 170, 246, 206, 237, 166, 223,  17,  31, 251, 240, 218, 162,  20, 234, 133,
242, 153,  35, 236,  10, 148,  21, 132,  63,  54, 253, 152, 154, 125, 143, 161,
 59, 110, 102, 146,  86,  93, 135, 217,  83, 100, 193, 163,   8,  71,  32, 157,
126, 138,  50, 189, 244, 214,  81,  82,  61,  13, 202,  28, 210,  19,  18, 140,
243, 186,  42,   6, 198,   9,   5, 109,  79,   1, 122, 171, 245, 205,  76,  26,
 41,  85,  88, 127,  73, 249, 177, 173,  66, 209,  52, 105, 174,  74, 181, 194,
 22, 120,  62, 226,  39,  70, 231, 228,   3,  24, 111, 176, 139, 129, 156,  98,
 95,  49,  60,  72, 158, 151,  78,  43,  80, 233, 144, 222, 160, 137, 107, 165,
224,   4, 131, 159, 117,  92, 179,  48,  75, 141, 175, 113, 190,  67, 200,  23,
 87, 208,  94,  65,  58,   7,  11, 207, 241, 185, 225, 203,  14, 239,  53, 220,
 38, 180, 195,  84, 116,  25, 115, 178, 106, 108,  33, 147,  89, 155, 219, 104,
128, 199, 167, 130, 114, 119, 229, 197,  16,  90, 232, 169, 183, 227,  44,  36,
172,  55, 221, 145, 252,  51, 211, 215, 254,  40,  37,  57, 192, 247, 255, 235,
 12,  64,  34, 103, 250, 248,  77, 168, 121, 150,  46,   0, 142, 184,  15,  69,
 29,  47, 124, 164, 112, 213,  68,  27, 191,  97, 187, 101, 216, 149, 136, 238,
201,  91,   2, 196, 212, 182,  56,  96, 134, 118, 188, 230,  45, 204, 123,  99};
    int y1[256],y2[256],y3[256],y4[256],y5[256],y6[256],y7[256],y8[256];

        for(int i=0;i<n;i++)
        {
           int  output_mask = s[i];
            y1[i]=  (output_mask &(1<<7))/128;
             y2[i]=  (output_mask &(1<<6))/64;
             y3[i]=  ((output_mask) &(1<<5))/32;
             y4[i]=  (output_mask) &(1<<4)/16;
             y5[i]=  (output_mask) &(1<<3)/8;
             y6[i]=  (output_mask) &(1<<2)/4;
             y7[i]=  (output_mask) &(1<<1)/2;
             y8[i]=  (output_mask) &(1<<0)/1;
        }
       
       
       
    int zeroCount = 0;
    int oneCount = 0;
    int z1=0;
    int o1= 0;
    for (int i = 0; i < 256; i++) {
        if (y1[i] == 0) {
           zeroCount++;
           z1=zeroCount;
        } else if (y1[i] == 1) {
           oneCount++;
           o1=oneCount;
        }
       
    }
     zeroCount = 0;
     oneCount = 0;
    int z2=0;
    int o2= 0;
    for (int i = 0; i < 256; i++) {
        if (y2[i] == 0) {
           zeroCount++;
           z2=zeroCount;
        } else if (y2[i] == 1) {
           oneCount++;
           o2=oneCount;
        }
       
    }
     zeroCount = 0;
     oneCount = 0;
    int z3=0;
    int o3= 0;
    for (int i = 0; i < 256; i++) {
        if (y3[i] == 0) {
           zeroCount++;
           z3=zeroCount;
        } else if (y3[i] == 1) {
           oneCount++;
           o3=oneCount;
        }
       
    }
     zeroCount = 0;
     oneCount = 0;
    int z4=0;
    int o4= 0;
    for (int i = 0; i < 256; i++) {
        if (y4[i] == 0) {
           zeroCount++;
           z4=zeroCount;
        } else if (y4[i] == 1) {
           oneCount++;
           o4=oneCount;
        }
       
    }
     zeroCount = 0;
     oneCount = 0;
    int z5=0;
    int o5= 0;
    for (int i = 0; i < 256; i++) {
        if (y5[i] == 0) {
           zeroCount++;
           z5=zeroCount;
        } else if (y5[i] == 1) {
           oneCount++;
           o5=oneCount;
        }
       
    }
    zeroCount = 0;
     oneCount = 0;
    int z6=0;
    int o6= 0;
    for (int i = 0; i < 256; i++) {
        if (y6[i] == 0) {
           zeroCount++;
           z6=zeroCount;
        } else if (y6[i] == 1) {
           oneCount++;
           o6=oneCount;
        }
       
    }
    zeroCount = 0;
     oneCount = 0;
    int z7=0;
    int o7= 0;
    for (int i = 0; i < 256; i++) {
        if (y7[i] == 0) {
           zeroCount++;
           z7=zeroCount;
        } else if (y7[i] == 1) {
           oneCount++;
           o7=oneCount;
        }
       
    }
     zeroCount = 0;
     oneCount = 0;
    int z8=0;
    int o8= 0;
    for (int i = 0; i < 256; i++) {
        if (y8[i] == 0) {
           zeroCount++;
           z8=zeroCount;
        } else if (y8[i] == 1) {
           oneCount++;
           o8=oneCount;
        }
      
    }
    if(z1==128&&o1==128&&z2==128&&o2==128&&z3==128&&o3==128&&z4==128&&o4==128&&z5==128&&o5==128&&z6==128&&o6==128&&z7==128&&o7==128&&z8==128&&o8==128)
    {
        printf("Dickson s box is balanced");
    }
    else
    {
       printf("Dickson s box is not balanced");
    }
    return 0;
} 
