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
#pragma mark Private implementation



//static
//void VAPStringSetName(VAPString *string, char *newName);

#pragma mark -
#pragma mark Public implementation

void *VAPStringCreateWithString(char *string) {
    
    
    VAPString *object = VAPObjectCreateType(VAPString) ;
    VAPStringSetName(object, string);
    
    return object;
}


void __VAPStringDeallocate(void *object) {
    
    VAPStringSetName(object, NULL);
    __VAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors 


char *VAPStringGetName(void *string){
    return string != NULL ? ((VAPString *) string)->_string : NULL;
}

void VAPStringSetName(void *string, char *newString) {
    if (string != NULL && newString != string) {
        char *previousName = ((VAPString *) string)->_string;
        if (previousName != NULL) {
            free(previousName);
        }
        
        char *copiedName = NULL;
        if (NULL != newString) {
            copiedName = strdup(newString);
            
            assert(copiedName != NULL);
            
        }
        ((VAPString *) string)->_string = copiedName;
    }
}

#pragma mark -
#pragma mark Private implementation


