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
    
    //create array
    VAPArray *array2 = VAPObjectCreateType(VAPArray);
    
    //reference count 1
    assert(1 == VAPGetReferenceCount(array));
    
    //reference count 1
    assert(1 == VAPGetReferenceCount(array2));
    
    //create object
    VAPObject *object = VAPObjectCreateType(VAPObject);
    
    //create another object;
    VAPObject *object2 = VAPObjectCreateType(VAPObject);
    
    //reference count 1
    assert(1 == VAPGetReferenceCount(object));
    
    //reference count 1
    assert(1 == VAPGetReferenceCount(object2));
    
    //add object to array
    VAPArrayAddObject(array, object);
  
    //reference count 2
    assert(2 == VAPGetReferenceCount(object));
    
    VAPArrayGetCount(array);
    
    //count of objects in array
    assert(1 == VAPArrayGetCount(array));
    
    //try to add the same object 1
    VAPArrayAddObject(array, object);
    
    //count of objects in array
    assert(1 == VAPArrayGetCount(array));
    
    //add object2;
    VAPArrayAddObject(array, object2);
    
    //count of objects in array 2
    assert(2 == VAPArrayGetCount(array));
    
    
    //remove object at index
    VAPArrayRemoveObjectAtIndex(array, 0);
    
    //count of objects in array 2
    assert(1 == VAPArrayGetCount(array));
    
    
    //create object
    VAPObject *object3 = VAPObjectCreateType(VAPObject);
    
    //add object and object 3 to array
    VAPArrayAddObject(array, object);
    assert(2 == VAPArrayGetCount(array));
    VAPArrayAddObject(array, object3);
    
    //count of objects in array 3
    assert(3 == VAPArrayGetCount(array));
    
    //get object from array by index 1
    void *objectFromArray = VAPArrayGetObjectAtIndex(array, 1);
    
    //compare object and object from array
    assert(VAPGetReferenceCount(object) == VAPGetReferenceCount(objectFromArray));
    
    //is object contains in array
    assert(true == VAPArrayIsContainsObject(array, object2));
    
    //remove all objects
    VAPArrayRemoveAllObjects(array);
    
    //count of objects in array 0
    assert(0 == VAPArrayGetCount(array));
    
    //release object
    VAPObjectRelease(object);
    
    //release another object
    VAPObjectRelease(object2);
    
    //release third object
    VAPObjectRelease(object3);
    
    //release array
    VAPObjectRelease(array);
    
    //release array2
    VAPObjectRelease(array2);
    
   
}

