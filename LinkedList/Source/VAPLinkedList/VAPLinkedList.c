//
//  VAPLinkedList.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 03.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedList.h"
#include <assert.h>

#pragma mark -
#pragma mark Private Declaration

static
VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list);

#pragma mark -
#pragma mark Public Implementation

#warning make all setters

void __VAPLinkedListDeallocate(void *object) {
//  VAPLinkedListNode *_head; release
    VAPObjectRelease(object);
}

bool VAPLinkedListIsEmpty(VAPLinkedList *list) {
    return (NULL != list) && (VAPLinkedListGetFirstObject(list));
}

void VAPLinkedListSetObjectAtIndex(VAPLinkedList *list, void *object, uint64_t index) {
    if (NULL != list) {
#warning use getter in assert!
        assert(index < list->_count);
        
#warning look at 80 - 85
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        for (uint64_t iterator = 0; iterator < index; iterator++) {
            if (iterator == index) {
                VAPLinkedListNodeSetObject(head, object);
            } else {
                head = VAPLinkedListNodeGetNextNode(head);
            }
        }
    }
}
#warning mess
extern
void VAPLinkedListAddObject(VAPLinkedList *list, void *object);

void VAPLinkedListAddObjectAtStart(VAPLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
        VAPLinkedListNode *newFirstNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNodeSetNextNode(newFirstNode, list->_head);
        VAPObjectRelease(list->_head);
        list->_head = newFirstNode;
    }
}
#warning mess
extern
void VAPLinkedListRemoveAllObjects(VAPLinkedList *list);
#warning mess
extern
void VAPLinkedListRemoveObjectAtIndex(VAPLinkedList *list, uint64_t index);


void *VAPLinkedListGetFirstObject(VAPLinkedList *list) {

    return NULL != list ? VAPLinkedListNodeGetObject(VAPLinkedListGetHead(list)) : NULL;
}

void *VAPLinkedListGetObjectAtIndex(VAPLinkedList *list, uint64_t index) {
    void *result = NULL;
    if (NULL != list) {
        assert(index < list->_count);
        
        
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        for (uint64_t iterator = 0; iterator < index; iterator++) {
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

VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list) {
    return NULL != list ? list->_head : NULL;
}
