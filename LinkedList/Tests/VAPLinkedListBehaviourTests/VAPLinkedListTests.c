//
//  VAPLinkedListTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 04.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedListTests.h"
#include "VAPLinkedList.h"
#include "VAPEnumerator.h"
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
    //Firstly create empty linked list
    VAPLinkedList *list = VAPObjectCreateType(VAPLinkedList);
    
    
    //  Linked list should be empty
    assert(true == VAPLinkedListIsEmpty(list));
    
    assert(0 == VAPLinkedListGetCount(list));
    
    //  Reference count of list == 1
    assert(1 == VAPGetReferenceCount(list));
    
    //let's create first object
    VAPObject *object = VAPObjectCreateType(VAPObject);
    
    //  object should not be nil
    assert(NULL != object);
    
    //  object reference count should be 1
    assert(1 == VAPGetReferenceCount(object));
    
    //add object to list
    VAPLinkedListAddObject(list, object);
    
    //  object reference count should be 2
    assert(2 == VAPGetReferenceCount(object));
    
    //  Linked list has one object
    assert(false == VAPLinkedListIsEmpty(list));
    
    assert(1 == VAPLinkedListGetCount(list));
    
    //let's try to add identical object
    VAPLinkedListAddObject(list, object);
    
    //  object reference count should be 2
    assert(2 == VAPGetReferenceCount(object));
    
    //  Linked list has one object
    assert(1 == VAPLinkedListGetCount(list));
    
    //Create second object
    VAPObject *object2 = VAPObjectCreateType(VAPObject);
    
    //  object2 should not be nil
    assert(NULL != object2);
    
    //  object2 reference count should be 1
    assert(1 == VAPGetReferenceCount(object2));
    
    // the first object should be "object"
    assert(object == VAPLinkedListGetFirstObject(list));
    
    //add object2 to head
    VAPLinkedListAddObject(list, object2);
    
    //  object2 reference count should be 2
    assert(2 == VAPGetReferenceCount(object2));
    
    //  Linked list has two object
    assert(2 == VAPLinkedListGetCount(list));
    
    //  the first object should be "object2"
    assert(object2 == VAPLinkedListGetFirstObject(list));
    
    //Create third object
    VAPObject *object3 = VAPObjectCreateType(VAPObject);
    
    //  object3 should not be nil
    assert(NULL != object3);
    
    //  object3 reference count should be 1
    assert(1 == VAPGetReferenceCount(object3));
    
    //add object3 to tail
    VAPLinkedListAddObjectAtTheTail(list, object3);
    
    //  object3 reference count should be 2
    assert(2 == VAPGetReferenceCount(object3));
    
    //  Linked list has three object
    assert(3 == VAPLinkedListGetCount(list));
    
    //  the first object should be "object2" also
    assert(object2 == VAPLinkedListGetFirstObject(list));
    
    //Create fourth object
    VAPObject *object4 = VAPObjectCreateType(VAPObject);
    
    //  object4 should not be nil
    assert(NULL != object4);
    
    //  object4 reference count should be 1
    assert(1 == VAPGetReferenceCount(object4));
    
    //add object4 to head
    VAPLinkedListAddObject(list, object4);
    
    //  object4 reference count should be 2
    assert(2 == VAPGetReferenceCount(object4));
    
    //  Linked list has four object
    assert(4 == VAPLinkedListGetCount(list));
    
    //  the first object should be "object4"
    assert(object4 == VAPLinkedListGetFirstObject(list));
    
//    VAPObjectRetain(object4);
//    
//    VAPObjectRetain(object2);
//    VAPObjectRetain(object2);
//    
//    VAPObjectRetain(object);
//    VAPObjectRetain(object);
//    VAPObjectRetain(object);
//    
//    
//    VAPObjectRetain(object3);
//    VAPObjectRetain(object3);
//    VAPObjectRetain(object3);
//    VAPObjectRetain(object3);
    
    //check all objects in list
    assert(true == VAPLinkedListIsContainsObject(list, object4));
    assert(true == VAPLinkedListIsContainsObject(list, object2));
    assert(true == VAPLinkedListIsContainsObject(list, object));
    assert(true == VAPLinkedListIsContainsObject(list, object3));
    
//    VAPEnumerator *enumerator = VAPEnumeratorCreateWithList(list);
    
//    while (VAPEnumeratorIsValid(enumerator)) {
//        VAPObject *obj = VAPEnumeratorGetNextObject(enumerator);
//        printf("%llu\n",VAPGetReferenceCount(obj));
//    }
    
    
//    VAPObjectRelease(object4);
//    
//    VAPObjectRelease(object2);
//    VAPObjectRelease(object2);
//    
//    VAPObjectRelease(object);
//    VAPObjectRelease(object);
//    VAPObjectRelease(object);
//    
//    
//    VAPObjectRelease(object3);
//    VAPObjectRelease(object3);
//    VAPObjectRelease(object3);
//    VAPObjectRelease(object3);
    
    //remove head. this is object 2
    VAPLinkedListRemoveObject(list, object4);
    
    //is object4 contains in list
    assert(false == VAPLinkedListIsContainsObject(list, object4));
    
    //  object4 reference count should be 1
    assert(1 == VAPGetReferenceCount(object4));
    
    //Get head
    assert(object2 == VAPLinkedListGetFirstObject(list));
    
    //Linked list has three objects
    assert(3 == VAPLinkedListGetCount(list));
    
    //remove object
    VAPLinkedListRemoveObject(list, object);
    
    //is object contains in list
    assert(false == VAPLinkedListIsContainsObject(list, object));
    
    //  object reference count should be 1
    assert(1 == VAPGetReferenceCount(object));
    
    //Linked list has two objects
    assert(2 == VAPLinkedListGetCount(list));
    
    //remove object2
    VAPLinkedListRemoveObject(list, object2);
    
    //is object2 contains in list
    assert(false == VAPLinkedListIsContainsObject(list, object2));
    
    //Get head
    assert(object3 == VAPLinkedListGetFirstObject(list));
    
    //Linked list has one objects
    assert(1 == VAPLinkedListGetCount(list));
    
    //  object2 reference count should be 1
    assert(1 == VAPGetReferenceCount(object2));
    
    //remove last object
    VAPLinkedListRemoveObject(list, object3);
    
    //is object3 contains in list
    assert(false == VAPLinkedListIsContainsObject(list, object3));
    
    //Get head
    assert(NULL == VAPLinkedListGetFirstObject(list));
    
    //Linked list has one objects
    assert(0 == VAPLinkedListGetCount(list));
    
    //  object2 reference count should be 1
    assert(1 == VAPGetReferenceCount(object3));
    
    
    //add all objects to list
    VAPLinkedListAddObject(list, object);
    VAPLinkedListAddObject(list, object2);
    VAPLinkedListAddObject(list, object3);
    VAPLinkedListAddObject(list, object4);
    
    //  check reference count
    assert(2 == VAPGetReferenceCount(object));
    assert(2 == VAPGetReferenceCount(object2));
    assert(2 == VAPGetReferenceCount(object3));
    assert(2 == VAPGetReferenceCount(object4));
    
    //  Linked list has four objects
    assert(4 == VAPLinkedListGetCount(list));
    
    //delete all objects
    VAPLinkedListRemoveAllObjects(list);
    
    //  Linked list has 0 objects
    assert(0 == VAPLinkedListGetCount(list));
    
    //check all objects in list
    assert(false == VAPLinkedListIsContainsObject(list, object4));
    assert(false == VAPLinkedListIsContainsObject(list, object2));
    assert(false == VAPLinkedListIsContainsObject(list, object));
    assert(false == VAPLinkedListIsContainsObject(list, object3));
    
    //  check reference count
    assert(1 == VAPGetReferenceCount(object));
    assert(1 == VAPGetReferenceCount(object2));
    assert(1 == VAPGetReferenceCount(object3));
    assert(1 == VAPGetReferenceCount(object4));
    

    VAPObjectRelease(list);
    VAPObjectRelease(object);
    VAPObjectRelease(object2);
    VAPObjectRelease(object3);
    VAPObjectRelease(object4);

}

