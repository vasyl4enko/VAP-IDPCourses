//
//  VAPLinkedList.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 03.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedList.h"

#pragma mark -
#pragma mark Private Declaration

#pragma mark -
#pragma mark Public Implementation

#warning make all setters

void __VAPLinkedListDeallocate(void *object) {
//  VAPLinkedListNode *_head; release
    VAPObjectRelease(object);
}

bool VAPLinkedListIsEmpty(VAPLinkedList *list) {
    return (NULL != list) && (VAPLinkedListGetFirstNode(list));
}

//extern
//void VAPLinkedListAddNodeAtEnd(VAPLinkedList *list, VAPLinkedListNode *node);

extern
void VAPLinkedListAddObjectAtIndex(VAPLinkedList *list, void *object, uint64_t index);

extern
void VAPLinkedListAddObject(VAPLinkedList *list, void *object);

extern
void VAPLinkedListAddObjectAtStart(VAPLinkedList *list, void *object) {
    if (NULL != list && NULL != object) {
        VAPLinkedListNode *newFirstNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNodeSetNextNode(newFirstNode, list->_head);
        VAPObjectRelease(list->_head)
        list->_head = newFirstNode;
    }
}

extern
void VAPLinkedListRemoveAllObjects(VAPLinkedList *list);

extern
void VAPLinkedListRemoveObjectAtIndex(VAPLinkedList *list, uint64_t index);

extern
VAPLinkedListNode *VAPLinkedListGetFirstNode(VAPLinkedList *list) {
    if (NULL != list) {
        
    }
}


#pragma mark -
#pragma mark Private Implementation