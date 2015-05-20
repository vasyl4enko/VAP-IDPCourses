//
//  VAPArrayTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPArrayTests.h"
#include "VAPArray.h"
#include "VAPString.h"

#define VAPArrayTestsPrintCount(object) \
    printf("%llu - counts of objects in "#object "\n", VAPArrayGetCount(object))

#pragma mark -
#pragma mark Private Declaration
static
void VAPArrayCreationTest(void);

#pragma mark -
#pragma mark Public Implementation
void VAPArrayTests() {
    VAPArrayCreationTest();
}
#pragma mark -
#pragma mark Private Implementation
void VAPArrayCreationTest(void) {
    char *pushkin = "Puskin";
    char *lermontov = "Lermontov";
    char *chehov = "Chehov";
    
    //VAPArray object created with first element VAPString string
    VAPArray *testArray = VAPArrayCreate(VAPStringCreate(pushkin));
    //VAPArray get count
//    printf("%llu",VAPArrayGetCount(testArray));
    VAPArrayTestsPrintCount(testArray);
    //VAPArray add VAPString object
    VAPArrayAddElement(testArray, VAPStringCreate(lermontov));
    //VAPArray get count
    VAPArrayTestsPrintCount(testArray);
    //VAPArray add VAPString object
    //VAPArray get all array
    //VAPArray get object at index 2
    //VAPArray release

}

