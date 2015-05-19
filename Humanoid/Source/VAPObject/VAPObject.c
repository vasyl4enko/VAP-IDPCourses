//
//  VAPObject.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 17.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <assert.h>

#include "VAPObject.h"

void *__VAPObjectCreate(size_t objectSize, VAPObjectDeallocCallBack deallocCallBack) {
    assert(objectSize != 0);
    
    VAPObject *object = calloc(1, objectSize);
    
    assert(object != NULL);
    
    object->_referenceCount = 1;
    object->_deallocCallBack = deallocCallBack;
    
    return object;
}

void *VAPObjectRetain(void *object) {
    if (object != NULL) {
        ((VAPObject *)object)->_referenceCount++;
    }
    
    return object;
}

void VAPObjectRelease(void *object) {
    if (object != NULL) {
        uint64_t count = ((VAPObject *)object)->_referenceCount - 1;
        ((VAPObject *)object)->_referenceCount = count;
        
        if (count == 0) {
            ((VAPObject *)object)->_deallocCallBack(object);
        }
        
    }
}

uint64_t IDPGetReferenceCount(void *object) {
    return object ? ((VAPObject *)object)->_referenceCount : 0;
}

void __VAPObjectDeallocate(void *object) {
    free(object);
}



