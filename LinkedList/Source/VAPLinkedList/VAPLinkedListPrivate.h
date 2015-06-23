//
//  VAPLinkedListPrivate.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 22.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef VAP_IDPCources_VAPLinkedListPrivate_h
#define VAP_IDPCources_VAPLinkedListPrivate_h

#include <stdio.h>

#include "VAPLinkedList.h"
#include "VAPLinkedListNode.h"

extern
void VAPLinkedListPrivateSetMutationCount(VAPLinkedList *list, uint64_t mutationsCount);

extern
uint64_t VAPLinkedListPrivateGetMutationCount(VAPLinkedList *list);

extern
void VAPLinkedListPrivateSetHead(VAPLinkedList *list, VAPLinkedListNode *node);

extern
VAPLinkedListNode *VAPLinkedListPrivateGetHead(VAPLinkedList *list);

#endif
