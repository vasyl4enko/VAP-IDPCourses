//
//  VAPArray.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 19.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPArray.h"
#include "VAPString.h"
#include "VAPMacros.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static const uint64_t kVAPArrayMaximumCapacity = UINT64_MAX - 1;

#pragma mark -
#pragma mark Private Declaration

static
void VAPArraySetCount(VAPArray *array, uint64_t count);

static
void VAPArraySetCapacity(VAPArray *array, uint64_t capacity);

static
bool VAPArrayShouldResize(VAPArray *array);

static
uint64_t VAPArrayPreferedCapacity(VAPArray *array);

static
void VAPArrayResizeIfNeeded(VAPArray *array);

#pragma mark -
#pragma mark Public Declaration

bool VAPArrayIsContainsObject(VAPArray *array, void *element) {
    bool isContains = false;
    if (NULL != array && NULL != element) {
        uint64_t count = VAPArrayGetCount(array);
        void **localElements = VAPArrayGetElements(array);
        for (uint64_t index = 0; index < count; index++) {
            if (element == localElements[index]) {
                isContains = true;
                break;
            }
        }
    }
    return isContains;
}

void *VAPArrayGetObjectAtIndex(VAPArray *array, uint64_t index) {
//    void *objectAtIndex;
//    if (NULL != array) {
//        void **elements = VAPArrayGetElements(array);
//        uint64_t count = VAPArrayGetCount(array);
//        if (count < index) {
//            printf("Array index out of bounds");
//            
//            return NULL;
//        }
//        for (uint64_t cycleIndex = 0; cycleIndex <= index; cycleIndex++) {
//            if (cycleIndex == index) {
//                objectAtIndex = elements[index];
//            }
//        }
//    }
    void *objectAtIndex = NULL;
    if (NULL != array && index < VAPArrayGetCount(array) - 1) {
        objectAtIndex = array->_elements[index];
    }
    
    return objectAtIndex;
}

#pragma mark -
#pragma mark Accessors



void **VAPArrayGetElements(VAPArray *array) {
    return array != NULL ? array->_elements : NULL;
}

uint64_t VAPArrayGetCount(VAPArray *array) {
    return NULL != array ? array->_count : 0;
}

uint64_t VAPArrayGetCapacity(VAPArray *array) {
    return NULL != array ? array->_capacity : 0;
}

void VAPArrayAddObject(VAPArray *array, void *object) {
    if (NULL != array && object != NULL) {
        uint64_t count = VAPArrayGetCount(array);
        if (!VAPArrayIsContainsObject(array, object)) {
            VAPArraySetCount(array, count + 1);
            VAPObjectRetain(object);
            array->_elements[count] = object;
            
        }
    }
}

void VAPArrayRemoveObjectAtIndex(VAPArray *array, uint64_t index) {
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        
        assert(VAPArrayGetCount(array) > index);
        
        void *object = VAPArrayGetObjectAtIndex(array, index);
        VAPObjectRelease(object);
        array->_elements[index] = NULL;
        for (uint64_t localIndex = index + 1; localIndex < count; localIndex++) {
            array->_elements[localIndex - 1] = array->_elements[localIndex];
        }
        
        void **elements = VAPArrayGetElements(array);
        elements[count - 1] = NULL;
        VAPArraySetCount(array, count - 1);
    }
    
}

void VAPArrayRemoveAllObjects(VAPArray *array) {
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        for (uint64_t index = 0; index < count; index++) {
            VAPArrayRemoveObjectAtIndex(array, 0);
        }
        VAPArraySetCapacity(array, 0);
    }
    
    
}

#pragma mark -
#pragma mark Private Implementation

static
void VAPArraySetCount(VAPArray *array, uint64_t count) {
    if (NULL != array) {
        assert(kVAPArrayMaximumCapacity >= count);
        
        array->_count = count;
        VAPArrayResizeIfNeeded(array);
    }
}

static
void VAPArraySetCapacity(VAPArray *array, uint64_t capacity) {
    if (NULL != array && array->_capacity != capacity) {
        assert(kVAPArrayMaximumCapacity >= capacity);
        
        size_t size = capacity * sizeof(*array->_elements);
        if (0 == size && array->_elements != NULL) {
            free(array->_elements);
            array->_elements = 0;
        } else {
            array->_elements = realloc(array->_elements, size);
            
            assert(NULL != array->_elements);
        }
        
        array->_capacity = capacity;
    }
    
}

static
bool VAPArrayShouldResize(VAPArray *array) {
    return (NULL != array) && (array->_capacity != VAPArrayPreferedCapacity(array));
}

static
uint64_t VAPArrayPreferedCapacity(VAPArray *array) {
    if (NULL != array) {
        uint64_t localCount = VAPArrayGetCount(array);
        uint64_t localCapacity = VAPArrayGetCapacity(array);
        if (localCount <= localCapacity) {
            return localCapacity;
        }
        
        if (localCapacity < localCount) {
            return  localCapacity + 1 + localCount * 0.65;
            
        }
    }

    return 0;
}

static
void VAPArrayResizeIfNeeded(VAPArray *array){
    if (VAPArrayShouldResize(array)) {
        VAPArraySetCapacity(array, VAPArrayPreferedCapacity(array));
    }
}

void __VAPArrayDeallocate(void *object) {
    VAPArray *array = object;
    VAPArrayRemoveAllObjects(object);
    
    if (NULL != array->_elements) {
        free(array->_elements);
        array->_elements = NULL;
    }
    __VAPObjectDeallocate(object);
}


