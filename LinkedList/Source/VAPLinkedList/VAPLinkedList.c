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
VAPLinkedListNode *VAPLinkedListGetNodeBeforeObject(VAPLinkedList *list, void *object);

static
void VAPLinkedListSetCount(VAPLinkedList *list, uint64_t count);

#pragma mark -
#pragma mark Public Implementation

void __VAPLinkedListDeallocate(void *object) {
    VAPLinkedListRemoveAllObjects(object);
    VAPObjectRelease(object);
}

bool VAPLinkedListIsEmpty(VAPLinkedList *list) {
    return (NULL != list) && 0 == VAPLinkedListGetHead(list);
}


void VAPLinkedListAddObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *newFirstNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNodeSetNextNode(newFirstNode, head);
        VAPLinkedListSetHead(list, newFirstNode);
        VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
        VAPObjectRelease(newFirstNode);
    }
}

void VAPLinkedListAddObjectAtTheTail(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        if (VAPLinkedListIsEmpty(list)) {
            VAPLinkedListNode *node = VAPLinkedListNodeCreateWithObject(object);
            VAPLinkedListSetHead(list, node);
            VAPLinkedListSetCount(list, list->_count + 1);
        } else {
            VAPLinkedListNode *head = VAPLinkedListGetHead(list);
            VAPLinkedListNode *nextNode;
            uint64_t iterator = 0;
            uint64_t count = VAPLinkedListGetCount(list);
            while (iterator < count) {
                nextNode = VAPLinkedListNodeGetNextNode(head);
                if (NULL == nextNode) {
                    VAPLinkedListNodeSetNextNode(head, VAPLinkedListNodeCreateWithObject(object));
                } else {
                    head = nextNode;
                }
                iterator++;
            }
        }
    }
}

void VAPLinkedListRemoveAllObjects(VAPLinkedList *list) {
    
    VAPLinkedListSetHead(list, NULL);
    VAPLinkedListSetCount(list, 0);
}


void VAPLinkedListRemoveObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *nextNode =VAPLinkedListNodeGetNextNode(head);
        
        if (VAPLinkedListNodeGetObject(head) != object) {
            while (NULL != head) {
                nextNode = VAPLinkedListNodeGetNextNode(head);
                if (object == VAPLinkedListNodeGetObject(head)) {
                    VAPLinkedListNode *beforeNode = VAPLinkedListGetNodeBeforeObject(list, object);
                    VAPLinkedListNodeSetNextNode(beforeNode, nextNode);
                    VAPObjectRelease(head);
                    VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) - 1);
                    break;
                }
                head = nextNode;
            }
        } else {
            VAPObjectRetain(nextNode);
            VAPObjectRelease(head);
            VAPLinkedListSetHead(list, NULL);
            VAPLinkedListSetHead(list, nextNode);
            
            VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) - 1);
        }
        
    }
}


void *VAPLinkedListGetFirstObject(VAPLinkedList *list) {

    return NULL != list ? VAPLinkedListNodeGetObject(VAPLinkedListGetHead(list)) : NULL;
}

// true
uint64_t VAPLinkedListGetCount(VAPLinkedList *list) {
    
    return NULL != list ? list->_count : 0;
}

bool VAPLinkedListIsContainsObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *nextNode;
        
        while (NULL != head) {
            nextNode = VAPLinkedListNodeGetNextNode(head);
            if (object == VAPLinkedListNodeGetObject(head)) {
                return true;
            }
            head = nextNode;
        }
    }
    return false;
}

#pragma mark -
#pragma mark Private Implementation

void VAPLinkedListSetHead(VAPLinkedList *list, VAPLinkedListNode *node) {
    VAPRetainSetter(list, _head, node);
}

VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list) {
    return NULL != list ? list->_head : NULL;
}


VAPLinkedListNode *VAPLinkedListGetNodeBeforeObject(VAPLinkedList *list, void *object) {
    
    if (NULL != list) {
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *nextNode;

        while (NULL != (nextNode = VAPLinkedListNodeGetNextNode(head)) || NULL != head) {
            if (object == VAPLinkedListNodeGetObject(nextNode)) {
                return head;
            }
            head = nextNode;
        }
    }
    
    return NULL;
}

static
void VAPLinkedListSetCount(VAPLinkedList *list, uint64_t count) {
    VAPAssignSetter(list, _count, count);
}
