//
//  VAPLinkedListTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 04.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedListTests.h"
#include "VAPLinkedList.h"


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
    //  create list
    VAPLinkedList *list = VAPObjectCreateType(VAPLinkedList);
    
    VAPObject *obj = VAPObjectCreateType(VAPObject);
    VAPObject *obj2 = VAPObjectCreateType(VAPObject);
    VAPObject *obj3 = VAPObjectCreateType(VAPObject);
    VAPObject *obj4 = VAPObjectCreateType(VAPObject);
    VAPLinkedListAddObject(list, obj);
    VAPLinkedListAddObject(list, obj2);
    VAPLinkedListAddObject(list, obj3);
    VAPLinkedListSetObjectAtIndex(list, obj4, 1);
    VAPObjectRelease(obj4);
    
    printf("%llu\n",VAPGetReferenceCount(obj4));
    printf("%llu\n",VAPGetReferenceCount(obj3));
    printf("%llu\n",VAPGetReferenceCount(obj2));
    printf("%llu\n",VAPGetReferenceCount(obj));
    



    
    
    
    VAPObjectRelease(list);
 
    //  is Empty
    //  
}

