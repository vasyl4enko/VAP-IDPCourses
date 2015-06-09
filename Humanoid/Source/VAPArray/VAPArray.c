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

static
void VAPArraySetObjectAtIndex(VAPArray *array, void *object, uint64_t index);

#pragma mark -
#pragma mark Public Declaration

void __VAPArrayDeallocate(void *object) {
    VAPArrayRemoveAllObjects(object);
    __VAPObjectDeallocate(object);
}

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
    void *objectAtIndex = NULL;
    if (NULL != array && index < VAPArrayGetCount(array)) {
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


void VAPArraySetObjectAtIndex(VAPArray *array, void *object, uint64_t index) {
    assert(index < kVAPArrayMaximumCapacity);
    
    if (NULL != array) {
        void *localObject = array->_elements[index];
        if (localObject != object) {
            VAPObjectRetain(object);
            VAPObjectRelease(localObject);
            array->_elements[index] = object;
            
        }
    }
}

void VAPArrayAddObject(VAPArray *array, void *object) {
    if (NULL != array && object != NULL) {
        uint64_t count = VAPArrayGetCount(array);
        if (!VAPArrayIsContainsObject(array, object)) {
            VAPArraySetCount(array, count + 1);
            VAPArraySetObjectAtIndex(array, object, count);
        }
    }
}

void VAPArrayRemoveObjectAtIndex(VAPArray *array, uint64_t index) {
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        
        assert(kVAPArrayMaximumCapacity > index);
        
        VAPArraySetObjectAtIndex(array, NULL, index);
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
            VAPObjectRelease(array->_elements[index]);
        }
        VAPArraySetCount(array, 0);
    }
}

#pragma mark -
#pragma mark Private Implementation


void VAPArraySetCount(VAPArray *array, uint64_t count) {
    assert(count < kVAPArrayMaximumCapacity - 1);
    
    if (NULL != array) {
        array->_count = count;
        VAPArrayResizeIfNeeded(array);
    }
}


void VAPArraySetCapacity(VAPArray *array, uint64_t capacity) {
    assert(capacity < kVAPArrayMaximumCapacity - 1);
    
    
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        size_t size = capacity * sizeof(*array->_elements);
        if (array->_capacity != capacity && capacity != 0) {
            array->_capacity = capacity;
            
            array->_elements = realloc(array->_elements, size);
            
            assert(NULL != array->_elements);
//            void **startPointer = array->_elements + array->_count;
//            memset(startPointer, 0, size - sizeCount);
        }
        
        if (count == 0 && capacity == 0) {
            if (NULL != array->_elements) {
                free(array->_elements);
                array->_elements = NULL;
            }
        }
        
        size_t sizeCount = array->_count  * sizeof(*array->_elements);
        void **startPointer = array->_elements + array->_count - 1;
        memset(startPointer, 0, size - sizeCount);
    }
}


bool VAPArrayShouldResize(VAPArray *array) {
    
    return NULL != array && array->_capacity != VAPArrayPreferedCapacity(array);
}


uint64_t VAPArrayPreferedCapacity(VAPArray *array) {
    uint64_t preferedCapacity = 0;
    if (NULL != array) {
        uint64_t count = VAPArrayGetCount(array);
        uint64_t capacity = VAPArrayGetCapacity(array);
        if (count == 0) {
            return preferedCapacity = 0;
        }
        
        if (count > capacity) {
            preferedCapacity = count + capacity + 1;
        } else {
            preferedCapacity = capacity;
        }
    }

    return preferedCapacity;
}


void VAPArrayResizeIfNeeded(VAPArray *array){
    if (VAPArrayShouldResize(array)) {
        VAPArraySetCapacity(array, VAPArrayPreferedCapacity(array));
    }

}

