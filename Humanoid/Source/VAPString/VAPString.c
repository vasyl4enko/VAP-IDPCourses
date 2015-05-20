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

void *VAPStringCreate(char *name) {
    
    
    VAPString *object = VAPObjectCreateType(VAPString) ;
    VAPStringSetName(object, name);
    
    return object;
}


void __VAPStringDeallocate(void *object) {
    
    VAPStringSetName(object, NULL);
    __VAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors 


char *VAPStringGetName(void *string){
    return string ?((VAPString *) string)->_name : NULL;
}

void VAPStringSetName(void *string, char *newName) {
    if (string != NULL) {
        char *previousName = ((VAPString *) string)->_name;
        if (previousName != NULL) {
            free(previousName);
        }
        
        char *copiedName = NULL;
        if (NULL != newName) {
            copiedName = strdup(newName);
            
            assert(copiedName != NULL);
            
        }
        ((VAPString *) string)->_name = copiedName;
    }
    
}

#pragma mark -
#pragma mark Private implementation


