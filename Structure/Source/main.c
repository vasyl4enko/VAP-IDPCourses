//
//  main.c
//  Structure
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <stdio.h>
#include "TestDataStructure.h"
#include "BytesNumbersToConsol.h"


int main(int argc, const char * argv[]) {
    
    VAPOutputTestDataStructures();
    char testValue = 3;
    printByte(&testValue,reverse);
    printf("\n");
    int val = 432;
    printFieldOfByte(&val,sizeof(int),reverse);
    printf("\n");
    
    unsigned short x = 1;
    printf("%s\n", *((unsigned char *) &x) == 0 ? "big-endian" : "little-endian");
    return 0;
}

