#include <stdio.h>


int main() {
    	
    int n=256;
    int a,b;
    int s[256] ={ 103, 244, 218, 35, 116, 49, 105, 118, 202, 182, 13, 198, 159, 150, 92, 140, 
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
