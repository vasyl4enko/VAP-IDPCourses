//
//  VAPArray.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 19.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPArray.h"
#include <stdlib.h>

#pragma mark -
#pragma mark Public Implementation

void *VAPArrayCreate(void *element) {
    VAPArray *array = VAPObjectCreateType(VAPArray);
    VAPArrayAddElement(array, element);
    
    return array;
}


void *VAPArrayGetObjectAtIndex(void *array, uint64_t index) {
    void *elements = VAPArrayGetObjects(array);
    uint64_t count = VAPArrayGetCount(array);
    if (count < index) {
        printf("Array index out of bounds");
        
        return NULL;
    }
    
    void *objectAtIndex = NULL;
    for (uint64_t cycleIndex = 0; cycleIndex <= index; cycleIndex++, elements++) {
        if (cycleIndex == index) {
            objectAtIndex = elements;
        }
    }
    
    return objectAtIndex;
}

void *VAPArrayGetObjects(void *array) {
    
    return array != NULL ? ((VAPArray *)array)->_elements : NULL;
}

uint64_t VAPArrayGetCount(void *array) {
    
    return array != NULL ? ((VAPArray *)array)->_count : 0;
}

void VAPArrayAddElement(void *array, void *element) {
    if (array != NULL && element != NULL) {
        if (((VAPArray *) array)->_elements == NULL ) {
            ((VAPArray *) array)->_elements = malloc(sizeof(element));
            ((VAPArray *) array)->_elements = element;
            ((VAPArray *) array)->_count = 1;
        } else {
            uint64_t count = ((VAPArray *) array)->_count + 1;
            VAPArray *buff;
            buff->_elements = realloc(((VAPArray *)array)->_elements, count * sizeof(*element));
            
            if (NULL != buff ) {
                ((VAPArray *)array)->_elements = buff->_elements;
            }

            for (int i = 0; i <  count; i++,((VAPArray *)array)->_elements++) {
                if (i == (((VAPArray *) array)->_count)) {
                    ((VAPArray *)array)->_elements = element;
                    ((VAPArray *) array)->_count += 1;
                    
                }
            }
//            printf("%lu\n",sizeof(buff));
        }
    }
}


void __VAPArrayDeallocate(void *object) {
    __VAPObjectDeallocate(object);
}