//
//  VAPAutoreleasingStack.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 01.07.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <assert.h>

#include "VAPAutoreleasingStack.h"
#include "VAPMacros.h"

#pragma mark -
#pragma mark Private Declaration

const uint64_t kVAPAutoreleasingStackMaxSize = UINT64_MAX;

static
void VAPAutoreleasingStackSetData(VAPAutoreleasingStack *stack, void **data);

static
void **VAPAutoreleasingStackGetData(VAPAutoreleasingStack *stack);

static
void VAPAutoreleasingStackSetCount(VAPAutoreleasingStack *stack, uint64_t count);

static
uint64_t VAPAutoreleasingStackGetCount(VAPAutoreleasingStack *stack);

static
void VAPAutoreleasingStackSetSize(VAPAutoreleasingStack *stack, size_t size);

static
size_t VAPAutoreleasingStackGetSize(VAPAutoreleasingStack *stack);


#pragma mark -
#pragma mark Public Implementation

extern
void __VAPAutoreleasingStackDeallocate(void *object) {
    
    VAPAutoreleasingStackSetSize(object, 0);
    
    __VAPObjectDeallocate(object);
}


VAPAutoreleasingStack *VAPAutoreleasingStackCreateWithSize(size_t size) {
    VAPAutoreleasingStack *stack = VAPObjectCreateType(VAPAutoreleasingStack);
    VAPAutoreleasingStackSetSize(stack, size);
    
    return stack;
}

bool VAPAutoreleasingStackIsEmpty(VAPAutoreleasingStack *stack) {
    return NULL != stack && (0 == VAPAutoreleasingStackGetCount(stack));
}

bool VAPAutoreleasingStackIsFull(VAPAutoreleasingStack *stack) {
    uint64_t m = (VAPAutoreleasingStackGetSize(stack) / sizeof(VAPAutoreleasingStackGetData(stack)));
    return NULL != stack &&
    VAPAutoreleasingStackGetCount(stack) == m;
   
}

void VAPAutoreleasingStackPushObject(VAPAutoreleasingStack *stack, void *object) {
    if (NULL != stack) {
        
        assert(false == VAPAutoreleasingStackIsFull(stack));
        
        void **data = VAPAutoreleasingStackGetData(stack);
        data[VAPAutoreleasingStackGetCount(stack)] = object;
        VAPAutoreleasingStackSetCount(stack, VAPAutoreleasingStackGetCount(stack) + 1);
    }
}

VAPAutoreleasingPopType VAPAutoreleasingStackPopObject(VAPAutoreleasingStack *stack) {
    if (NULL != stack) {
        
        assert(false == VAPAutoreleasingStackIsEmpty(stack));
        
        void **data = VAPAutoreleasingStackGetData(stack);
        uint64_t count = VAPAutoreleasingStackGetCount(stack);
        void *object = data[count - 1];
        VAPAutoreleasingStackSetCount(stack, count - 1);
        VAPObjectRelease(object);
        return object ? VAPAutoreleasingPopObject : VAPAutoreleasingPopNULL;
        
    }
    
    return 0;
}


VAPAutoreleasingPopType VAPAutoreleasingStackPopObjectsUntilNULL(VAPAutoreleasingStack *stack) {
    VAPAutoreleasingPopType result = 0;
    if (NULL != stack) {
        while (VAPAutoreleasingPopNULL != (result = VAPAutoreleasingStackPopObject(stack))) {
        }
        
    }
    return result;
}

#pragma mark -
#pragma mark Private Implementation

void VAPAutoreleasingStackSetData(VAPAutoreleasingStack *stack, void **data) {
    if (NULL != stack) {
        VAPRetainSetter(stack, _data, data);
    }
}

void **VAPAutoreleasingStackGetData(VAPAutoreleasingStack *stack) {
    return NULL != stack ? stack->_data : NULL;
}

void VAPAutoreleasingStackSetCount(VAPAutoreleasingStack *stack, uint64_t count) {
    if (NULL != stack) {
        VAPAssignSetter(stack, _count, count);
    }
}

uint64_t VAPAutoreleasingStackGetCount(VAPAutoreleasingStack *stack) {
    return NULL != stack ? stack->_count : 0;
}

void VAPAutoreleasingStackSetSize(VAPAutoreleasingStack *stack, size_t size) {
    if (NULL != stack && size < kVAPAutoreleasingStackMaxSize) {
        VAPAssignSetter(stack, _size, size);
        if (0 == size) {
            
            assert(true == VAPAutoreleasingStackIsEmpty(stack));
            
            free(VAPAutoreleasingStackGetData(stack));
            VAPAutoreleasingStackSetData(stack, NULL);
            
        } else {
            stack->_data = malloc(size);
            
            assert(NULL !=  stack->_data);
        }
    }
}

size_t VAPAutoreleasingStackGetSize(VAPAutoreleasingStack *stack) {
    return NULL != stack ? stack->_size : 0;
}
