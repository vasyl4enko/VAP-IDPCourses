//
//  VAPAutoreleasingStack.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 01.07.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPAutoreleasingStack__
#define __VAP_IDPCources__VAPAutoreleasingStack__

#include <stdio.h>
#include <stdbool.h>

#include "VAPObject.h"

extern const uint64_t kVAPAutoreleasingStackMaxSize;

typedef struct VAPAutoreleasingStack VAPAutoreleasingStack;

struct VAPAutoreleasingStack{
    VAPObject _super;
    void **_data;
    uint64_t _count;
    size_t _size;
};


typedef enum {
    VAPAutoreleasingPopNULL,
    VAPAutoreleasingPopObject
} VAPAutoreleasingPopType;

extern
void __VAPAutoreleasingStackDeallocate(void *object);

extern
VAPAutoreleasingStack *VAPAutoreleasingStackCreateWithSize(size_t size);

extern
bool VAPAutoreleasingStackIsEmpty(VAPAutoreleasingStack *stack);

extern
bool VAPAutoreleasingStackIsFull(VAPAutoreleasingStack *stack);

extern
void VAPAutoreleasingStackPushObject(VAPAutoreleasingStack *stack, void *object);

extern
VAPAutoreleasingPopType VAPAutoreleasingStackPopObject(VAPAutoreleasingStack *stack);

extern
VAPAutoreleasingPopType VAPAutoreleasingStackPopObjectsUntilNULL(VAPAutoreleasingStack *stack);

#endif /* defined(__VAP_IDPCources__VAPAutoreleasingStack__) */
