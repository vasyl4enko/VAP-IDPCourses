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
    
    __VAPObjectDeallocate(object);
}

bool VAPLinkedListIsEmpty(VAPLinkedList *list) {
    return (NULL != list) && NULL == VAPLinkedListGetHead(list);
}


void VAPLinkedListAddObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *newNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNodeSetNextNode(newNode, head); // if first set null
        VAPLinkedListSetHead(list, newNode);
        VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
        VAPObjectRelease(newNode);
    }
}

// false or true.... didn't tested... 
//void VAPLinkedListAddObjectAtTheTail(VAPLinkedList *list, void *object) {
//    if (NULL != list) {
//        if (VAPLinkedListIsEmpty(list)) {
//            VAPLinkedListNode *node = VAPLinkedListNodeCreateWithObject(object);
//            VAPLinkedListSetHead(list, node);
//            VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
//        } else {
//            VAPLinkedListNode *head = VAPLinkedListGetHead(list);
//            VAPLinkedListNode *nextNode;
//            uint64_t iterator = 0;
//            uint64_t count = VAPLinkedListGetCount(list);
//            while (iterator < count) {
//                nextNode = VAPLinkedListNodeGetNextNode(head);
//                if (NULL == nextNode) {
//                    VAPLinkedListNodeSetNextNode(head, VAPLinkedListNodeCreateWithObject(object));
//                    VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
//                } else {
//                    head = nextNode;
//                }
//                iterator++;
//            }
//        }
//    }
//}


void VAPLinkedListRemoveAllObjects(VAPLinkedList *list) {
    if (NULL != list) {
        VAPLinkedListSetHead(list, NULL);
        VAPLinkedListSetCount(list, 0);
    }
}


void VAPLinkedListRemoveObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *nextNode = VAPLinkedListNodeGetNextNode(head);
        
        while (NULL != head) {
            nextNode = VAPLinkedListNodeGetNextNode(head);
            if (object == VAPLinkedListNodeGetObject(head)) {
                VAPLinkedListNode *beforeNode = VAPLinkedListGetNodeBeforeObject(list, object);
                if (NULL == beforeNode) {
                    VAPLinkedListSetHead(list, nextNode);
                } else {
                    VAPLinkedListNodeSetNextNode(beforeNode, nextNode);
                }
                
                VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) - 1);
                break; // we can delete break and this function remove identical objects in all list
            }
            head = nextNode;
        }
    }
}


void *VAPLinkedListGetFirstObject(VAPLinkedList *list) {

    return NULL != list ? VAPLinkedListNodeGetObject(VAPLinkedListGetHead(list)) : NULL;
}


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
