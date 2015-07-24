//
//  main.c
//  LinkedList
//
//  Created by Aleksandr Vasylchenko on 02.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

#include "VAPLinkedList.h"
#include "VAPString.h"
#include "VAPLinkedListTests.h"
#include "VAPAutoreleasePool.h"
#include "VAPAutoreleasingStack.h"

int main(int argc, const char * argv[]) {
    VAPLinkedListBehaviourTests();
//    VAPAutoreleasingStack *stack = VAPObjectCreateType(VAPAutoreleasingStack);
    VAPAutoreleasePool *pool = VAPAutoreleasePoolCreate();
//    VAPObject *obj = VAPObjectCreateType(VAPObject);
//    VAPObject *obj1 = VAPObjectCreateType(VAPObject);
//    VAPAutoreleasePoolAddObject(pool, obj);
//    assert(1 == VAPGetReferenceCount(obj));
//    VAPAutoreleasePoolAddObject(pool, obj1);
//    
//    VAPAutoreleasePoolDrain(pool);
    
    uint64_t iterator = 0;
    
    while (iterator < 2000000) {
        VAPAutoreleasePoolAddObject(pool, VAPObjectCreateType(VAPObject));
        iterator++;
    }
    
    
    
    pool = VAPAutoreleasePoolCreate();
    
    while (iterator < 200000) {
        VAPAutoreleasePoolAddObject(pool, VAPObjectCreateType(VAPObject));
        iterator++;
    }
    
    pool = VAPAutoreleasePoolCreate();
    while (iterator < 200000) {
        VAPAutoreleasePoolAddObject(pool, VAPObjectCreateType(VAPObject));
        iterator++;
    }
    
    VAPAutoreleasePoolDrain(pool);
//    VAPAutoreleasePoolDrain(pool);
    assert(1 == VAPGetReferenceCount(pool));
    
    

    return 0;
}
