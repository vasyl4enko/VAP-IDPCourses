//
//  VAPArray.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 19.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPArray__
#define __VAP_IDPCources__VAPArray__

#include <stdio.h>

#include "VAPObject.h"

typedef struct {
    VAPObject _super;
    void **_elements;
    uint64_t _count;
    uint64_t _capacity;
} VAPArray;

extern
void *VAPArrayCreateWithCapacity(uint64_t _capacity);

extern
void *VAPArrayGetObjectAtIndex(VAPArray *array, uint64_t index);

extern
void **VAPArrayGetElements(VAPArray *array);

extern
uint64_t VAPArrayGetCount(VAPArray *array);

extern
uint64_t VAPArrayGetCapacity(VAPArray *array);

extern
void VAPArrayAddElement(VAPArray *array, void *element);

extern
void VAPArrayRemoveAllObjects(VAPArray *array);

extern
void __VAPArrayDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPArray__) */
