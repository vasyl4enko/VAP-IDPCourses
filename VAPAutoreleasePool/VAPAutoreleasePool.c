//
//  VAPAutoreleasePool.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 04.07.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPAutoreleasePool.h"
#include "VAPLinkedList.h"
#include "VAPObject.h"
#include "VAPAutoreleasingStack.h"
#include "VAPMacros.h"
#include "VAPEnumerator.h"
#include <assert.h>

#pragma mark -
#pragma mark Private Declaration

static VAPAutoreleasePool *___pool = NULL;

struct VAPAutoreleasePool{
    VAPObject _super;
    VAPLinkedList *_list;
    VAPAutoreleasingStack *_stack;
    
};

static
void VAPAutoreleasePoolSetList(VAPAutoreleasePool *pool, VAPLinkedList *list);

static
void VAPAutoreleasePoolSetStack(VAPAutoreleasePool *pool, VAPAutoreleasingStack *stack);

static
void VAPAutoreleasePoolSetPool(VAPAutoreleasePool *pool);

static
VAPAutoreleasePool *VAPAutoreleasePoolGetPool();

static
VAPAutoreleasingStack *VAPAutoreleasePoolGetStack(VAPAutoreleasePool *pool);

static
VAPLinkedList *VAPAutoreleasePoolGetList(VAPAutoreleasePool *pool);


#pragma mark -
#pragma mark Public Implementation

void __VAPAutoreleasePoolDeallocate(void *object) {
    
    __VAPObjectDeallocate(object);
}

VAPAutoreleasePool *VAPAutoreleasePoolCreate() {
    VAPAutoreleasePool *pool = VAPAutoreleasePoolGetPool();
    if (!pool) {
        pool = VAPObjectCreateType(VAPAutoreleasePool);
        VAPAutoreleasePoolSetPool(pool);
        
        VAPAutoreleasingStack *stack = VAPAutoreleasingStackCreateWithSize(1024);
        VAPAutoreleasingStackPushObject(stack, NULL);
        VAPAutoreleasePoolSetStack(pool, stack);
        
        VAPLinkedList *list = VAPObjectCreateType(VAPLinkedList);
        VAPLinkedListAddFirstObject(list, stack);
        VAPAutoreleasePoolSetList(pool, list);
        VAPObjectRelease(list);
    } else {
        VAPAutoreleasePoolAddObject(pool, NULL);
    }
    
    return pool;
}

void VAPAutoreleasePoolAddObject(VAPAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        if (false == VAPAutoreleasingStackIsFull(VAPAutoreleasePoolGetStack(pool))) {
            VAPAutoreleasingStackPushObject(VAPAutoreleasePoolGetStack(pool), object);
        } else {
            VAPAutoreleasingStack *stack = VAPAutoreleasingStackCreateWithSize(1024);
            VAPLinkedListAddFirstObject(VAPAutoreleasePoolGetList(pool), stack);
            VAPAutoreleasePoolSetStack(pool, stack);
        }
    }
}

void VAPAutoreleasePoolDrain(VAPAutoreleasePool *pool) {
    if (NULL != pool) {
        VAPLinkedList *list = VAPAutoreleasePoolGetList(pool);
        VAPAutoreleasingStack *stack = VAPAutoreleasePoolGetStack(pool);
        VAPAutoreleasingPopType type = VAPAutoreleasingStackPopObjectsUntilNULL(stack);
        do {
//            VAPAutoreleasingPopType type = VAPAutoreleasingStackPopObjectsUntilNULL(stack);
            assert(NULL != stack);
            if (true == VAPAutoreleasingStackIsEmpty(VAPAutoreleasePoolGetStack(pool))) {
                VAPLinkedListNode *node = VAPLinkedListPrivateGetHead(list);
                VAPAutoreleasePoolSetStack(pool, VAPLinkedListNodeGetObject(VAPLinkedListNodeGetNextNode(node)));
                VAPLinkedListRemoveObject(list, node);
            }
        } while (VAPAutoreleasingPopNULL != type);
        
    }
}

#pragma mark -
#pragma mark Private Implementation

void VAPAutoreleasePoolSetList(VAPAutoreleasePool *pool, VAPLinkedList *list) {
    VAPRetainSetter(pool, _list, list);
}

void VAPAutoreleasePoolSetStack(VAPAutoreleasePool *pool, VAPAutoreleasingStack *stack) {
    VAPAssignSetter(pool, _stack, stack);
}

VAPAutoreleasingStack *VAPAutoreleasePoolGetStack(VAPAutoreleasePool *pool) {
    return NULL != pool ? pool->_stack : NULL;
}


void VAPAutoreleasePoolSetPool(VAPAutoreleasePool *pool) {
    ___pool = pool;
}

VAPAutoreleasePool *VAPAutoreleasePoolGetPool() {
    return ___pool;
}

VAPLinkedList *VAPAutoreleasePoolGetList(VAPAutoreleasePool *pool) {
    return  NULL != pool ? pool->_list : NULL;
}
