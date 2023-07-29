#include <stdio.h>
#include <math.h>

int multiplicand = 0, multiplier = 0, c = 0;
int multiplicand_binary[5] = {0}, multiplier_binary[5] = {0}, product[5] = {0};

void convertToBinary(int num, int binary[]){
    int abs_num = fabs(num);
    for (int i = 0; i < 5; i++){
        binary[i] = abs_num & 1;
        abs_num >>= 1;
    }
}

void binaryAdd(int a[], int b[], int result[]){
    int carry = 0;
    for (int i = 0; i < 5; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum & 1;
        carry = sum >> 1;
    }
}

void binarySubtract(int a[], int b[], int result[]){
    int complement_b[5];
    for (int i = 0; i < 5; i++) {
        complement_b[i] = (b[i] ^ 1) & 1;
    }
    int temp[5];
    binaryAdd(a, complement_b, temp);
    binaryAdd(temp, complement_b, result);
}

void arshift(){
    int temp = (product[4] << 1) | c;
    for (int i = 0; i < 4; i++){
        product[i] = product[i + 1];
    }
    product[4] = temp;
    c = product[0];
    printf("\nAR-SHIFT: ");
    for (int i = 4; i >= 0; i--){
        printf("%d", product[i]);
    }
    printf(":");
    for (int i = 4; i >= 0; i--){
        printf("%d", multiplicand_binary[i]);
    }
}

void printBinary(int binary[]){
    for (int i = 4; i >= 0; i--){
        printf("%d", binary[i]);
    }
}

int main(){
    printf("\t\tBOOTH'S MULTIPLICATION ALGORITHM\n");
    printf("Enter two numbers to multiply (Both must be less than 16):\n");

    do {
        printf("Enter Multiplicand: ");
        scanf("%d", &multiplicand);
        printf("Enter Multiplier: ");
        scanf("%d", &multiplier);
    } while (multiplicand >= 16 || multiplier >= 16);

    printf("\nExpected Product = %d", multiplicand * multiplier);
    convertToBinary(multiplicand, multiplicand_binary);
    convertToBinary(multiplier, multiplier_binary);

    printf("\n\nBinary Equivalents are:\n");
    printf("Multiplicand = ");
    printBinary(multiplicand_binary);
    printf("\nMultiplier = ");
    printBinary(multiplier_binary);
    printf("\nB' + 1 = 10000");
    printf("\n\n");

    for (int i = 0; i < 5; i++){
        if (multiplicand_binary[i] == 0 && c == 0){
            printf("\n-->");
            arshift();
        }
        else if (multiplicand_binary[i] == 1 && c == 0){
            printf("\n-->");
            printf("\nADD B: ");
            binaryAdd(product, multiplier_binary, product);
            arshift();
        }
        else if (multiplicand_binary[i] == 0 && c == 1){
            printf("\n-->");
            printf("\nSUB B: ");
            binarySubtract(product, multiplier_binary, product);
            arshift();
        }
        c = multiplicand_binary[i];
    }

    printf("\nProduct is = ");
    printBinary(product);
    printBinary(multiplicand_binary);

    return 0;
}
