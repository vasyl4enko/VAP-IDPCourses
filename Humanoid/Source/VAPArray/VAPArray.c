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

#pragma mark -
#pragma mark Private Declaration

static
void VAPArraySetCount(VAPArray *array, uint64_t count);

static
void VAPArraySetCapacity(VAPArray *array, uint64_t capacity);

#pragma mark -
#pragma mark Public Implementation

void *VAPArrayCreateWithCapacity(uint64_t capacity) {
    VAPArray *array = VAPObjectCreateType(VAPArray);
    VAPArraySetCapacity(array, capacity);
    
    
    return array;
}

#pragma mark -
#pragma mark Accessors

//void *VAPArrayGetObjectAtIndex(void *array, uint64_t index) {
//    void *elements = VAPArrayGetElements(array);
//    uint64_t count = VAPArrayGetCount(array);
//    if (count < index) {
//        printf("Array index out of bounds");
//        
//        return NULL;
//    }
//    
//    void *objectAtIndex = NULL;
//    for (uint64_t cycleIndex = 0; cycleIndex <= index; cycleIndex++, elements++) {
//        if (cycleIndex == index) {
//            objectAtIndex = elements;
//        }
//    }
//    
//    return objectAtIndex;
//}

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
    if (NULL != array && NULL != element) {
        
        if (NULL == VAPArrayGetElements(array)) {
            array->_elements = calloc(1, sizeof(element));
            *array->_elements = element;
            VAPArraySetCount(array, localCount + 1);
            if (localCapacity == 0) {
                VAPArraySetCapacity(array, 1);
            }
        } else if (localCount < localCapacity) {
            for (uint64_t index = 0; index <= localCount; index++) {
                
                if (index == localCount) {
                    array->_elements[index] = element;
                }
            }
            VAPArraySetCount(array, localCount + 1);
        } else if (localCount == localCapacity) {
            
            void **reallocArray = realloc(array->_elements, (localCapacity + 1) * sizeof(array->_elements));
            if (NULL != reallocArray) {
                array->_elements = reallocArray;
                VAPArraySetCount(array, localCount + 1);
                VAPArraySetCapacity(array, localCapacity + 1);
                for (uint64_t index = 0; index <= localCount; index++) {
                    
                    if (index == localCount) {
                        array->_elements[index] = element;
                    }
                }
            }
            VAPArraySetCount(array, localCount + 1);

        }
        
    }
    

}


#pragma mark -
#pragma mark Private Implementation

void VAPArraySetCount(VAPArray *array, uint64_t count) {
    VAPMacrosSetter(array, count, VAPArray);
}

void VAPArraySetCapacity(VAPArray *array, uint64_t capacity) {
    if (NULL != array) {
        array->_capacity = capacity;
        if (NULL == VAPArrayGetElements(array)) {
            array->_elements = calloc(capacity, sizeof(array->_elements));
        }
    }
}

void __VAPArrayDeallocate(void *object) {
    __VAPObjectDeallocate(object);
}

//extern
//void *VAPArrayCreateWithCapacity(uint64_t _capacity);
//
//extern
//void *VAPArrayGetObjectAtIndex(VAPArray *array, uint64_t index);
//
//extern
//void **VAPArrayGetElements(VAPArray *array);
//
//extern
//uint64_t VAPArrayGetCount(VAPArray *array);
//
//extern
//uint64_t VAPArrayGetCapacity(VAPArray *array);
//
//extern
//void VAPArrayAddElement(VAPArray *array, void *element);
//
//extern
//void __VAPArrayDeallocate(void *object);



//void VAPArrayAddElement(VAPArray *array, void *element) {
//    uint64_t localCount = VAPArrayGetCount(array);
//    uint64_t localCapacity = VAPArrayGetCapacity(array);
//    
//    if (NULL != array && NULL != element) {
//        if (NULL == VAPArrayGetElements(array)) {
//            array->_elements = calloc(1, sizeof(element));
//            //            *array->_elements = calloc(1, sizeof(array->_elements));
//            *array->_elements = element;
//            
//            VAPArraySetCount(array, localCount + 1);
//            if (localCapacity == 0) {
//                VAPArraySetCapacity(array, 1);
//            }
//        } else if (localCount < localCapacity) {
//            //            void **localElements = VAPArrayGetElements(array);
//            for (uint64_t index = 0; index <= localCount; index++) {
//                
//                if (index == localCount) {
//                    array->_elements[index] = element;
//                    //is equel array->_elements[1]
//                }
//            }
//            VAPArraySetCount(array, localCount + 1);
//        } else if (localCount == localCapacity) {
//            VAPArray *reallocArray = realloc(VAPArrayGetElements(array), (localCapacity + 1) * sizeof(array->_elements));
//            if (NULL != reallocArray) {
//                VAPArraySetCapacity(reallocArray, localCapacity + 1);
//                VAPArraySetCount(reallocArray, localCount + 1);
//                array = reallocArray;
//                for (uint64_t index = 0; index <= localCount; index++) {
//                    
//                    if (index == localCount) {
//                        //                        array->_elements = malloc(sizeof(array->_elements));
//                        array->_elements[index] = element;
//                        
//                    }
//                }
//            }
//            VAPArraySetCount(array, localCount + 1);
//        }
//    }
//}





