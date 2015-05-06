//
//  VAPTestGenerateMethods.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 06.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPTestGenerateMethods.h"
#include "VAPGenereteMethods.h"

#pragma mark -
#pragma mark Private

void VAPcallGeneretedFunc(void);

generetingMethodToPrintType(int, %d);
generetingMethodToPrintType(char, %c);
generetingMethodToPrintType(float, %f);
generetingMethodToPrintType(double, %f);

#pragma mark -
#pragma mark Public

void VAPGenerateOutputTests(void) {
    VAPcallGeneretedFunc();
    
}

#pragma mark -
#pragma mark Private implementation

void VAPcallGeneretedFunc(void) {
    callGenereted(int,5);
    callGenereted(char,67);
    callGenereted(float,3.5);
    callGenereted(double,4.7);
}


