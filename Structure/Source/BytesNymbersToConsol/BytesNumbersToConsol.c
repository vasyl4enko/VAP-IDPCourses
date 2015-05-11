//
//  BytesNumbersToConsol.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "BytesNumbersToConsol.h"

#pragma mark -
#pragma mark Private Declarations

static const int mask = 0x80;

#pragma mark -
#pragma mark Public Implementations

void printFieldOfByte(void *data, size_t size) {
    char *value = (char *)data;
    for (long i = size; i > 0; i--) {
        printByte(&value[i-1]);
    }
}

void printByte(char *byte) {
    uint8_t buff = *byte;
    uint8_t value;
    
    for (uint8_t i = 0; i < 8; i++) {
        value = mask & buff<<i;

        printf("%s ",(value & mask) ? "1" : "0");
    }
    printf("\n");
    
}

#pragma mark -
#pragma mark Private Implementations
