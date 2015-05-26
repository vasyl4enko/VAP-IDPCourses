//
//  VAPArrayTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPArrayTests.h"
#include "VAPArray.h"
#include <assert.h>


#define VAPArrayTestsPrintCount(object) \
    printf("%llu - counts of objects in "#object "\n", VAPArrayGetCount(object))

#pragma mark -
#pragma mark Private Declaration
static
void VAPArrayBehaviorTest(void);

#pragma mark -
#pragma mark Public Implementation
void VAPArrayTests() {
    VAPArrayBehaviorTest();
}
#pragma mark -
#pragma mark Private Implementation
void VAPArrayBehaviorTest(void) {
    //create array
    VAPArray *array = VAPObjectCreateType(VAPArray);
    
    //reference count 1
    assert(1 == VAPGetReferenceCount(array));
    
    //create object
    VAPObject *object = VAPObjectCreateType(VAPObject);
    VAPObject *object2 = VAPObjectCreateType(VAPObject);
    VAPObject *object3 = VAPObjectCreateType(VAPObject);
    VAPObject *object4 = VAPObjectCreateType(VAPObject);
    VAPObject *object5 = VAPObjectCreateType(VAPObject);
    VAPObject *object6 = VAPObjectCreateType(VAPObject);
    VAPObject *object7 = VAPObjectCreateType(VAPObject);
    VAPObject *object8 = VAPObjectCreateType(VAPObject);
    VAPObject *object9 = VAPObjectCreateType(VAPObject);
    VAPObject *object10 = VAPObjectCreateType(VAPObject);
    //reference count 1
    assert(1 == VAPGetReferenceCount(object));
    
    for (uint64_t index = 0 ; index < 5; index++) {
        VAPArrayAddElement(array, object);
    }
    
    
    
    assert(1 == VAPArrayGetCount(array));
    
    for (uint64_t index = 0 ; index < 1; index++) {
        VAPArrayAddElement(array, object);
        VAPArrayAddElement(array, object2);
        VAPArrayAddElement(array, object3);
        VAPArrayAddElement(array, object4);
        VAPArrayAddElement(array, object5);
        VAPArrayAddElement(array, object6);
        VAPArrayAddElement(array, object7);
        VAPArrayAddElement(array, object8);
        VAPArrayAddElement(array, object9);
        VAPArrayAddElement(array, object10);
        
    }
    
    //release object
    VAPObjectRelease(object);
    
    
    //release array
    VAPObjectRelease(array);
}

