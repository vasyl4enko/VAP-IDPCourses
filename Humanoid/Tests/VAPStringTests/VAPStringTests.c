//
//  VAPStringTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPStringTests.h"
#include "VAPString.h"
#include <assert.h>

#pragma mark -
#pragma mark Private Declaration

static
void VAPStringCreationTest(void);

#pragma mark -
#pragma mark Public Implementation

void VAPStringTests(void) {
    VAPStringCreationTest();
}

#pragma mark -
#pragma mark Private Implementation

void VAPStringCreationTest(void) {
    
    
    //create VAPString object
    VAPString *string = VAPStringCreateWithString("Karl Marks");
    
    //reference count == 1
    assert(1 == VAPGetReferenceCount(string));
    
    //create NULL pointer variable
    VAPString *string2 = NULL;
    
    //copy string to string2
    string2 = VAPObjectRetain(string);
    
    //reference count == 2
    assert(2 == VAPGetReferenceCount(string2));
    
    //get char string and their length
    printf("%s and their length %lld \n",VAPStringGetString(string2), VAPStringGetLength(string2));
    
    //release VAPstring object
    VAPObjectRelease(string);
    
    //release string2
    VAPObjectRelease(string2);
    
}