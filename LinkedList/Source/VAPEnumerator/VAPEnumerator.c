//
//  VAPEnumerator.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 22.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <assert.h>

#include "VAPEnumerator.h"
#include "VAPEnumeratorPrivate.h"
#include "VAPMacros.h"
//#include "VAPLinkedListNode.h"


#pragma mark -
#pragma mark Private Declration

static
void VAPEnumeratorSetList(VAPEnumerator *enumerator, VAPLinkedList *list);

static
VAPLinkedList *VAPEnumeratorGetList(VAPEnumerator *enumerator);

static
void VAPEnumeratorSetNode(VAPEnumerator *enumerator, VAPLinkedListNode *node);

static
void VAPEnumeratorSetIsValid(VAPEnumerator *enumerator, bool valid);

static
void VAPEnumeratorSetMutationsCount(VAPEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t VAPEnumeratorGetMutationsCount(VAPEnumerator *enumerator);

static
void VAPEnumeratorListValidation(VAPEnumerator *enumerator, VAPLinkedListNode *node);


#pragma mark -
#pragma mark Public Implementation

void __VAPEnumeratorDeallocate(void *object) {
    VAPEnumeratorSetNode(object, NULL);
    VAPEnumeratorSetList(object, NULL);
    
    __VAPObjectDeallocate(object);
}

VAPEnumerator *VAPEnumeratorCreateWithList(VAPLinkedList *list) {
    if (NULL == list || NULL == VAPLinkedListGetFirstObject(list)) {
        return NULL;
    }
    VAPEnumerator *enumerator = VAPObjectCreateType(VAPEnumerator);
    VAPEnumeratorSetList(enumerator, list);
    VAPEnumeratorSetMutationsCount(enumerator, VAPLinkedListPrivateGetMutationCount(list));
    VAPEnumeratorSetIsValid(enumerator, true);
    
    
    return enumerator;
}

void *VAPEnumeratorGetNextObject(VAPEnumerator *enumerator) {
    if (NULL != enumerator) {
        if (true == VAPEnumeratorIsValid(enumerator)) {
            VAPLinkedList *list = VAPEnumeratorGetList(enumerator);
            VAPLinkedListNode *node;
            
            assert(VAPEnumeratorGetMutationsCount(enumerator) == VAPLinkedListPrivateGetMutationCount(list));
            
            if (NULL == VAPEnumeratorGetNode(enumerator) && VAPEnumeratorIsValid(enumerator)) {
                node = VAPLinkedListPrivateGetHead(list);
            } else {
                node = VAPLinkedListNodeGetNextNode(VAPEnumeratorGetNode(enumerator));
            }
            VAPEnumeratorSetNode(enumerator, node);
            VAPEnumeratorListValidation(enumerator,node);
            
            return VAPLinkedListNodeGetObject(node);
        }
    }
    
    return NULL;
}

bool VAPEnumeratorIsValid(VAPEnumerator *enumerator) {
    return NULL != enumerator && enumerator->_isValid;
}

#pragma mark -
#pragma mark Private Implementation

void VAPEnumeratorSetList(VAPEnumerator *enumerator, VAPLinkedList *list) {
    VAPRetainSetter(enumerator, _list, list);
}

VAPLinkedList *VAPEnumeratorGetList(VAPEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_list : NULL;
}

void VAPEnumeratorSetNode(VAPEnumerator *enumerator, VAPLinkedListNode *node) {
    VAPRetainSetter(enumerator, _node, node);
}

VAPLinkedListNode *VAPEnumeratorGetNode(VAPEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_node : NULL;
}

void VAPEnumeratorSetIsValid(VAPEnumerator *enumerator,  bool valid) {
    VAPAssignSetter(enumerator, _isValid, valid);
}

void VAPEnumeratorSetMutationsCount(VAPEnumerator *enumerator, uint64_t mutationsCount) {
    VAPAssignSetter(enumerator, _mutationsCount, mutationsCount);
}

uint64_t VAPEnumeratorGetMutationsCount(VAPEnumerator *enumerator) {
    return NULL != enumerator ? enumerator->_mutationsCount : 0;
}

void VAPEnumeratorListValidation(VAPEnumerator *enumerator, VAPLinkedListNode *node) {
    if (NULL != enumerator && NULL != node) {
        if (NULL != VAPLinkedListNodeGetNextNode(node)) {
            VAPEnumeratorSetIsValid(enumerator, true);
        } else {
            VAPEnumeratorSetIsValid(enumerator, false);
        }
    }
}



