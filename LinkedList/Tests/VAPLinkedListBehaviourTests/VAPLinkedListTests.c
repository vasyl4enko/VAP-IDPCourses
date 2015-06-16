//
//  VAPLinkedListTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 04.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedListTests.h"
#include "VAPLinkedList.h"
#include <assert.h>


#pragma mark -
#pragma mark Private Declaration

static
void VAPLinkedListBehaviour();


#pragma mark -
#pragma mark Public Implementation

void VAPLinkedListBehaviourTests() {
    VAPLinkedListBehaviour();
}

#pragma mark -
#pragma mark Private Implementation


void VAPLinkedListBehaviour() {
    //firstly create empty linked list
    VAPLinkedList *list = VAPObjectCreateType(VAPLinkedList);
    
    //  Is list emty?
    assert(true == VAPLinkedListIsEmpty(list));
    
    //let's create some objects for linked list
    
    VAPObject *obj = VAPObjectCreateType(VAPObject);
    VAPObject *obj2 = VAPObjectCreateType(VAPObject);
    VAPObject *obj3 = VAPObjectCreateType(VAPObject);
    VAPObject *obj4 = VAPObjectCreateType(VAPObject);
    
    //  Check reference count this objects. It's will be 1;
    assert(1 == VAPGetReferenceCount(obj));
    assert(1 == VAPGetReferenceCount(obj2));
    assert(1 == VAPGetReferenceCount(obj3));
    assert(1 == VAPGetReferenceCount(obj4));
    
    // Add all elements to head
    VAPLinkedListAddObject(list, obj);
    VAPLinkedListAddObject(list, obj2);
    VAPLinkedListAddObject(list, obj3);
    VAPLinkedListAddObject(list, obj4);
    
    
    //  Check reference count this objects. It's will be 2;
    assert(2 == VAPGetReferenceCount(obj));
    assert(2 == VAPGetReferenceCount(obj2));
    assert(2 == VAPGetReferenceCount(obj3));
    assert(2 == VAPGetReferenceCount(obj4));
    
    //  Check list count. It will be 4
    assert(4 == VAPLinkedListGetCount(list));
    
    //Let's remove obj3 from linked list
    VAPLinkedListRemoveObject(list, obj3);
    
    //  Check list count. It will be 3
    assert(3 == VAPLinkedListGetCount(list));
    
    //  Is contains obj3 in linked list. It will be false
    assert(false == VAPLinkedListIsContainsObject(list, obj3));
    
    //  Is contains obj in linked list. It will be true.
    assert(true == VAPLinkedListIsContainsObject(list, obj));
    
    //  Is contains obj2 in linked list. It will be true.
    assert(true == VAPLinkedListIsContainsObject(list, obj2));
    
    //  Is contains obj4 in linked list. It will be true.
    assert(true == VAPLinkedListIsContainsObject(list, obj4));
    
    //Let's remove obj4 from linked list
    VAPLinkedListRemoveObject(list, obj4);
    
    //  Is contains obj4 in linked list. It will be true.
    assert(false == VAPLinkedListIsContainsObject(list, obj4));
    
    //  Is contains obj in linked list. It will be true.
    assert(true == VAPLinkedListIsContainsObject(list, obj));
    
    //  Is contains obj2 in linked list. It will be true.
    assert(true == VAPLinkedListIsContainsObject(list, obj2));
    
    //  Check list count. It will be 2
    assert(2 == VAPLinkedListGetCount(list));
    
    assert(2 == VAPGetReferenceCount(obj));
    assert(2 == VAPGetReferenceCount(obj2));
    assert(1 == VAPGetReferenceCount(obj3));
    assert(1 == VAPGetReferenceCount(obj4));
    
    // Remove all objects
    
    VAPLinkedListRemoveAllObjects(list);
    
    //  Check list count. It will be 0

    assert(0 == VAPLinkedListGetCount(list));
    
    
    
    
    
    
    VAPLinkedListAddObject(list, NULL);
    //  Check list count. It will be 0
    assert(1 == VAPLinkedListGetCount(list));
    
    VAPObjectRelease(list);
    VAPObjectRelease(obj);
    VAPObjectRelease(obj2);
    VAPObjectRelease(obj3);
    VAPObjectRelease(obj4);
 
    //  is Empty
    //  
}

