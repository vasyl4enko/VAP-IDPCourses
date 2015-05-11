//
//  BytesNumbersToConsol.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "BytesNumbersToConsol.h"
#include <stdlib.h>
#include <string.h>

#pragma mark -
#pragma mark Private Declarations

static const int mask = 0x80;  
static const int reverseMask = 0x1;
static const unsigned short x = 1;



#pragma mark -
#pragma mark Public Implementations

void printByte(char *byte, Reverse type) {
    uint8_t buff = *byte;
    uint8_t value;
    
    for (uint8_t i = 0; i < 8; i++) {
        
        if (type == nonreverse) {
            value = mask & buff<<i;
            printf("%s",(value & mask) ? "1" : "0");
        } else {
            value = reverseMask & buff>>i;
            printf("%s",(value & reverseMask) ? "1" : "0");
        }
        

        
    }
}


void printFieldOfByte(void *data, size_t size, Reverse type) {


    if (type ||(*((unsigned char *) &x) == 0)) {
        char *value = (char *)data;
        for (long i = 0; i < size; i++) {
            printByte(&value[i], type);
            if (i!=1) {
                printf(",");
            }
            
        }
    } else {
        char *value = (char *)data;
        for (long i = size; i > 0; i--) {
            printByte(&value[i-1], type);
            if (i != 1) {
                printf(",");
            }
            
        }
    }
    
}
