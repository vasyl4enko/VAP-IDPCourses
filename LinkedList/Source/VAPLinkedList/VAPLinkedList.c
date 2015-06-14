//
//  VAPLinkedList.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 03.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedList.h"
#include "VAPMacros.h"
#include <assert.h>

#pragma mark -
#pragma mark Private Declaration

static
void VAPLinkedListSetHead(VAPLinkedList *list, VAPLinkedListNode *node);

static
VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list);

static
VAPLinkedListNode *VAPLinkedListGetNodeBeforeIndex(VAPLinkedList *list, uint64_t index);

static
void VAPLinkedListSetCount(VAPLinkedList *list, uint64_t count);

#pragma mark -
#pragma mark Public Implementation

#warning make all setters

void __VAPLinkedListDeallocate(void *object) {
//  VAPLinkedListNode *_head; release
    VAPObjectRelease(object);
}

bool VAPLinkedListIsEmpty(VAPLinkedList *list) {
    return (NULL != list) && !(VAPLinkedListGetFirstObject(list));
}

void VAPLinkedListSetObjectAtIndex(VAPLinkedList *list, void *object, uint64_t index) {
    if (NULL != list) {
        assert(index < list->_count);
        if (index == 0) {
            VAPLinkedListAddObject(list, object);
        } else {
            VAPLinkedListNode *beforeNode = VAPLinkedListGetNodeBeforeIndex(list, index);
            VAPLinkedListNode *nextNode = VAPLinkedListNodeGetNextNode(beforeNode);
            VAPLinkedListNode *node = VAPLinkedListNodeCreateWithObject(object);
            VAPLinkedListNodeSetNextNode(node, nextNode);
            VAPLinkedListNodeSetNextNode(beforeNode, node);
        }
        
        VAPLinkedListSetCount(list, list->_count + 1);
    }
}

void VAPLinkedListAddObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *newFirstNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNodeSetNextNode(newFirstNode, list->_head);
        VAPObjectRelease(list->_head);
//        list->_head = newFirstNode;
        VAPLinkedListSetHead(list, newFirstNode);
        VAPLinkedListSetCount(list, list->_count + 1);
    }
}
#warning message
extern
void VAPLinkedListRemoveAllObjects(VAPLinkedList *list);
#warning message
extern
void VAPLinkedListRemoveObjectAtIndex(VAPLinkedList *list, uint64_t index);


void *VAPLinkedListGetFirstObject(VAPLinkedList *list) {

    return NULL != list ? VAPLinkedListNodeGetObject(VAPLinkedListGetHead(list)) : NULL;
}

void *VAPLinkedListGetObjectAtIndex(VAPLinkedList *list, uint64_t index) {
    void *result = NULL;
    if (NULL != list && !VAPLinkedListIsEmpty(list)) {
        assert(index < list->_count);
        
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        for (uint64_t iterator = 0; iterator <= index; iterator++) {
            if (iterator == index) {
                result = VAPLinkedListNodeGetObject(head);
            } else {
                head = VAPLinkedListNodeGetNextNode(head);
            }
        }
    }
    
    return result;
}

#pragma mark -
#pragma mark Private Implementation

void VAPLinkedListSetHead(VAPLinkedList *list, VAPLinkedListNode *node) {
    VAPRetainSetter(list, _head, node);
}

VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list) {
    return NULL != list ? list->_head : NULL;
}


VAPLinkedListNode *VAPLinkedListGetNodeBeforeIndex(VAPLinkedList *list, uint64_t index) {
    
    if (NULL != list && !VAPLinkedListIsEmpty(list)) {
        assert(index < list->_count);
        
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *nextNode;
        uint64_t iterator = 0;
        while (NULL != (nextNode = VAPLinkedListNodeGetNextNode(head))) {
            if (iterator == index - 1) {
                return head;
            }
            head = nextNode;
            iterator++;
        }
    }
    
    return NULL;
}

static
void VAPLinkedListSetCount(VAPLinkedList *list, uint64_t count) {
    VAPAssignSetter(list, _count, count);
}
