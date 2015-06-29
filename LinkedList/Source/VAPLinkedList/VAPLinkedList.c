//
//  VAPLinkedList.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 03.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "VAPLinkedList.h"
#include "VAPMacros.h"
#include "VAPLinkedListPrivate.h"
#include "VAPEnumeratorPrivate.h"
#include "VAPEnumerator.h"

#pragma mark -
#pragma mark Private Declaration

static
void VAPLinkedListSetHead(VAPLinkedList *list, VAPLinkedListNode *node);

static
VAPLinkedListNode *VAPLinkedListGetHead(VAPLinkedList *list);

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
    if (NULL != list && !VAPLinkedListIsContainsObject(list, object) && NULL != object) {
        VAPLinkedListNode *newNode = VAPLinkedListNodeCreateWithObject(object);
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNodeSetNextNode(newNode, head);
        VAPLinkedListSetHead(list, newNode);
        VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
        VAPObjectRelease(newNode);
    }
}

void VAPLinkedListAddObjectAtTheTail(VAPLinkedList *list, void *object) {
    if (NULL != list && !VAPLinkedListIsContainsObject(list, object) && NULL != object) {
        if (VAPLinkedListIsEmpty(list)) {
            VAPLinkedListAddObject(list, object);
        } else {
            VAPLinkedListNodeContext context;
            memset(&context, 0, sizeof(context));
            context.object = object;
            VAPLinkedListNode *contextNode = VAPLinkedListPrivateGetNodeWithContext(list,
                                                                 VAPLinkedListPrivateContainsPreviousObject,
                                                                 &context);
            if (NULL != contextNode && NULL == VAPLinkedListNodeGetNextNode(contextNode)) {
                VAPLinkedListNode *tailNode = VAPLinkedListNodeCreateWithObject(object);
                VAPLinkedListNodeSetNextNode(context.node, tailNode);
                VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
                VAPObjectRelease(tailNode);
            }
//            VAPLinkedListNode *head = VAPLinkedListGetHead(list);
//            VAPLinkedListNode *nextNode;
//            uint64_t iterator = 0;
//            uint64_t count = VAPLinkedListGetCount(list);
//            while (iterator < count) {
//                nextNode = VAPLinkedListNodeGetNextNode(head);
//                if (NULL == nextNode) {
//                    VAPLinkedListNode *tailNode = VAPLinkedListNodeCreateWithObject(object);
//                    VAPLinkedListNodeSetNextNode(head, tailNode);
//                    VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) + 1);
//                    VAPObjectRelease(tailNode);
//                    break;
//                }
//                head = nextNode;
//                iterator++;
//            }
        }
    }
}

void VAPLinkedListRemoveAllObjects(VAPLinkedList *list) {
    if (NULL != list) {
        VAPLinkedListSetHead(list, NULL);
        VAPLinkedListSetCount(list, 0);
    }
}

void VAPLinkedListRemoveObject(VAPLinkedList *list, void *object) {
    if (NULL != list) {
        VAPLinkedListNode *head = VAPLinkedListGetHead(list);
        VAPLinkedListNode *contextNode = NULL;
        if (object == VAPLinkedListNodeGetObject(head)) {
            VAPLinkedListSetHead(list, VAPLinkedListNodeGetNextNode(head));
            VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) - 1);
            head = NULL;
        }
        VAPLinkedListNodeContext context;
        memset(&context, 0, sizeof(context));
        context.object = object;
        contextNode = VAPLinkedListPrivateGetNodeWithContext(list, VAPLinkedListPrivateContainsObject, &context);
        if (NULL != contextNode) {
            VAPLinkedListNodeSetNextNode(context.previousNode, VAPLinkedListNodeGetNextNode(context.node));
            VAPLinkedListSetCount(list, VAPLinkedListGetCount(list) - 1);
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
    bool result = false;
    if (NULL != list) {
        VAPLinkedListNodeContext context;
        memset(&context, 0, sizeof(context));
        context.object = object;
        result = NULL != VAPLinkedListPrivateGetNodeWithContext(list, VAPLinkedListPrivateContainsObject, &context);
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

void VAPLinkedListSetCount(VAPLinkedList *list, uint64_t count) {
    VAPAssignSetter(list, _count, count);
    if (0 == count) {
        VAPLinkedListPrivateSetMutationCount(list, 0);
    } else {
        VAPLinkedListPrivateSetMutationCount(list, VAPLinkedListPrivateGetMutationCount(list) + count);
    }
}

void VAPLinkedListPrivateSetMutationCount(VAPLinkedList *list, uint64_t mutationsCount) {
    if (NULL != list) {
        list->_mutationsCount = mutationsCount;
    }
}

uint64_t VAPLinkedListPrivateGetMutationCount(VAPLinkedList *list) {
    return NULL != list ? list->_mutationsCount : 0;
}


void VAPLinkedListPrivateSetHead(VAPLinkedList *list, VAPLinkedListNode *node) {
    VAPRetainSetter(list, _head, node);
}


VAPLinkedListNode *VAPLinkedListPrivateGetHead(VAPLinkedList *list) {
    return NULL != list ? list->_head : NULL;
}

VAPLinkedListNode *VAPLinkedListPrivateGetNodeWithContext(VAPLinkedList *list,
                                                          VAPLinkediListComparisonFunction comparator,
                                                          VAPLinkedListNodeContext *context) {
    VAPLinkedListNode *result = NULL;
    if (NULL != list) {
        VAPEnumerator *enumerator = VAPEnumeratorCreateWithList(list);
        while (true == VAPEnumeratorIsValid(enumerator) && NULL != VAPEnumeratorGetNextObject(enumerator)) {
            VAPLinkedListNode *node = VAPEnumeratorGetNode(enumerator);
            context->node = node;
            if (true == VAPLinkedListPrivateContainsObject(node, *context)) {
//            if (true == comparator(node, context)) {
                result = node;
                break;
            }
            context->previousNode = node;
        }

        VAPObjectRelease(enumerator);
    }
    return result;
}

bool VAPLinkedListPrivateContainsObject(VAPLinkedListNode *node, VAPLinkedListNodeContext context) {
    return NULL != node && context.object == VAPLinkedListNodeGetObject(node);
}

bool VAPLinkedListPrivateContainsPreviousObject(VAPLinkedListNode *node,VAPLinkedListNodeContext context) {
    return NULL != context.node && NULL == VAPLinkedListNodeGetObject(VAPLinkedListNodeGetNextNode(context.node));
}


