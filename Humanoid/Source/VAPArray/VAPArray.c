//
//  VAPArray.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 19.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPArray.h"
#include <stdlib.h>

#pragma mark -
#pragma mark Public Implementation

void* VAPArrayCreate(void *element) {
    VAPArray *array = VAPObjectCreateType(VAPArray);
    VAPArrayAddElement(array, element);
    
    
    return array;
}

extern
void* VAPArrayCreate(void *element);

extern
void* VAPArrayGetObjectAtIndex(void *array, uint64_t index);

void* VAPArrayGetObjects(void *array) {

    return NULL;
}

void VAPArrayAddElement(void *array, void *element) {
    if (array != NULL && element != NULL) {
        if (((VAPArray *) array)->_elements == NULL ) {
            ((VAPArray *) array)->_elements = calloc(1, sizeof(element));
            ((VAPArray *) array)->_elements = element;
            ((VAPArray *) array)->_count = 1;
        } else {
            uint64_t count = ((VAPArray *) array)->_count + 1;
            VAPArray *buff;
           ((VAPArray *)buff)->_elements = realloc(((VAPArray *)array)->_elements, count * sizeof(element));
            printf("%lu\n",sizeof(buff));
            printf("%lu\n",sizeof(array));
            for (int i = 0; i <  count; i++,((VAPArray *)buff)->_elements++) {
                if (i == (((VAPArray *) array)->_count)) {
                    ((VAPArray *)buff)->_elements = element;
                }
            }
            printf("%lu\n",sizeof(buff));
        }
    }
}


void __VAPArrayDeallocate(void *object) {
    __VAPObjectDeallocate(object);
}