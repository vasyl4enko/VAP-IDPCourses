//
//  BytesNumbersToConsol.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__BytesNumbersToConsol__
#define __VAP_IDPCources__BytesNumbersToConsol__

#include <stdio.h>

typedef enum {
    nonreverse,
    reverse
} Reverse;

extern
void printByte(char *byte, Reverse type);

extern
void printFieldOfByte(void *data, size_t size, Reverse type);

#endif /* defined(__VAP_IDPCources__BytesNumbersToConsol__) */
