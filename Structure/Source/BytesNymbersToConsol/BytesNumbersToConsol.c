//
//  BytesNumbersToConsol.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "BytesNumbersToConsol.h"
#include <string.h>

static const long long maskOfLeftBit = 0b1000000000000000000000000000000000000000000000000000000000000000;
static const int countOfBits = 64;
static const int lengthOfString = 65;


void printNumbersBits(long long value){
    
    long long var = 0;
    int iterator = 0;
    char result[lengthOfString];
    while (iterator < countOfBits) {
        
        if(iterator){
            var = maskOfLeftBit & value<<iterator;
            var == 0 ? strcat(result, "0") : strcat(result, "1");
        }else{
            var = maskOfLeftBit & value;
            var == 0 ? strcat(result, "0") : strcat(result, "1");
        }
        
        iterator++;
    }
    
    printf("%s\n",result);
}