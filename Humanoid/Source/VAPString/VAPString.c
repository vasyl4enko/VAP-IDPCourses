//
//  VAPString.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 18.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPString.h"


#include <string.h>
#include <assert.h>

#pragma mark -
#pragma mark Private Declaration

static
void VAPStringSetLength(VAPString *object, char *string);

#pragma mark -
#pragma mark Public Implementation

void *VAPStringCreateWithString(char *string) {
    
    
    VAPString *object = VAPObjectCreateType(VAPString) ;
    VAPStringSetString(object, string);
    
    return object;
}


void __VAPStringDeallocate(void *object) {
    
    VAPStringSetString(object, NULL);
    __VAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors 


char *VAPStringGetString(void *string){
    return string != NULL ? ((VAPString *) string)->_string : NULL;
}

void VAPStringSetString(void *string, char *newString) {
    if (string != NULL && newString != string) {
        
        char *previousString = ((VAPString *) string)->_string;
        if (previousString != NULL) {
            free(previousString);
        }
        
        char *copiedString = NULL;
        if (NULL != newString) {
            copiedString = strdup(newString);
            
            assert(copiedString != NULL);
            
        }
        ((VAPString *) string)->_string = copiedString;
        VAPStringSetLength(string, copiedString);
    }
}

uint64_t VAPStringGetLength(VAPString *object) {
    
    return NULL != object ? object->_length : 0;
}

#pragma mark -
#pragma mark Private Implementation

void VAPStringSetLength(VAPString *object, char *string) {
    if (NULL != object) {
        if (NULL != string) {
            object->_length = strlen(string);
        } else {
            object->_length = 0;
        }
    }
}


