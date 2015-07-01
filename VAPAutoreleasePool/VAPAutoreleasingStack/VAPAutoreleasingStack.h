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


typedef struct VAPAutoreleasingStack VAPAutoreleasingStack;

struct VAPAutoreleasingStack{
    VAPObject _super;
    
    void **data;
    uint64_t count;
    size_t size;
};


typedef enum {
    VAPAutoreleasingPopUntilNULL,
    VAPAutoreleasingPopObject
} VAPAutoreleasingPopType;

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
