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
#include <stdbool.h>
#include <string.h>

#pragma mark -
#pragma mark Private Declaration

static
bool VAPArrayIsElementContains(VAPArray *array, void *element);

static
void VAPArraySetCount(VAPArray *array, uint64_t count);

static
void VAPArraySetCapacity(VAPArray *array, uint64_t capacity);


#pragma mark -
#pragma mark Accessors

void *VAPArrayGetObjectAtIndex(VAPArray *array, uint64_t index) {
    void *objectAtIndex;
    if (NULL != array) {
        void **elements = VAPArrayGetElements(array);
        uint64_t count = VAPArrayGetCount(array);
        if (count < index) {
            printf("Array index out of bounds");
            
            return NULL;
        }
        for (uint64_t cycleIndex = 0; cycleIndex <= index; cycleIndex++) {
            if (cycleIndex == index) {
                objectAtIndex = elements[index];
            }
        }
    }
    
    return objectAtIndex;
}

void **VAPArrayGetElements(VAPArray *array) {
    return array != NULL ? array->_elements : NULL;
}

uint64_t VAPArrayGetCount(VAPArray *array) {
    return NULL != array ? array->_count : 0;
}

uint64_t VAPArrayGetCapacity(VAPArray *array) {
    return NULL != array ? array->_capacity : 0;
}

void VAPArrayAddElement(VAPArray *array, void *element) {
    uint64_t localCount = VAPArrayGetCount(array);
    uint64_t localCapacity = VAPArrayGetCapacity(array);
    VAPArrayIsElementContains(array, element);
    if (NULL != array && NULL != element && false == VAPArrayIsElementContains(array, element)) {
        if (localCount < localCapacity) {
            array->_elements[localCount] = VAPObjectRetain(element);
            VAPArraySetCount(array, localCount + 1);
        } else if (localCount == localCapacity) {
            void **reallocArray = realloc(array->_elements, (localCapacity + 1) * sizeof(*array->_elements));
            if (NULL != reallocArray) {
                array->_elements = reallocArray;
                VAPArraySetCount(array, localCount + 1);
                VAPArraySetCapacity(array, localCapacity + 1 + localCount * 0.65);
                array->_elements[localCount] = VAPObjectRetain(element);
            }
            VAPArraySetCount(array, localCount + 1);
        }
    }
}

void VAPArrayRemoveObjectAtIndex(VAPArray *array, uint64_t index) {
    if (NULL != array && index < VAPArrayGetCount(array) - 1) {
        uint64_t count = VAPArrayGetCount(array);
        if (index < count - 1) {
            uint64_t elementCount = VAPArrayGetCount(array) - index - 1;
            void **elements = VAPArrayGetElements(array);
            
            memmove(elements[index], elements[index + 1], elementCount);

            elements[count-1] = NULL;
        }
        
        VAPArraySetCount(array, count-1);
    }
}

void VAPArrayRemoveAllObjects(VAPArray *array) {
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        for (uint64_t index = 0; index < count; index++) {
            VAPObjectRelease(VAPArrayGetObjectAtIndex(array, index));
        }
        array->_elements = NULL;
        VAPArraySetCapacity(array, 0);
        VAPArraySetCount(array, 0);
    }
}

#pragma mark -
#pragma mark Private Implementation

bool VAPArrayIsElementContains(VAPArray *array, void *element) {
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

void VAPArraySetCount(VAPArray *array, uint64_t count) {
    VAPMacrosSetter(array, count, VAPArray);
}

void VAPArraySetCapacity(VAPArray *array, uint64_t capacity) {
    if (NULL != array) {
        array->_capacity = capacity;
        if (NULL == VAPArrayGetElements(array)) {
            array->_elements = calloc(capacity, sizeof(*array->_elements));
        }
    }
}


void __VAPArrayDeallocate(void *object) {
    void **localElements = VAPArrayGetElements(object);
    for (uint64_t index = 0; index < VAPArrayGetCount(object); index++) {
        VAPObjectRelease(localElements[index]);
    }
    __VAPObjectDeallocate(object);
}

//extern
//void __VAPArrayDeallocate(void *object);





