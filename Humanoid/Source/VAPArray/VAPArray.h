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
    void *_elements;
    uint64_t _count;
} VAPArray;

extern
void *VAPArrayCreate(void *element);

extern
void *VAPArrayGetObjectAtIndex(void *array, uint64_t index);

extern
void *VAPArrayGetObjects(void *array);

extern
uint64_t VAPArrayGetCount(void *array);

extern
void VAPArrayAddElement(void *array, void *element);

extern

void __VAPArrayDeallocate(void *object);






#endif /* defined(__VAP_IDPCources__VAPArray__) */
