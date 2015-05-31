//
//  VAPHumanoidObject.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObject.h"
#include "VAPObject.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "VAPMacros.h"

#pragma mark -
#pragma mark Private Declaration

static const int kMaxChildrenCount = 20;

struct VAPHuman {
    VAPObject _super;
    VAPArray *_children;
    VAPHuman *_partner;
    VAPHuman *_mother;
    VAPHuman *_father;
    VAPString *_name;
    uint16_t _age;
    VAPGender _gender;
    uint8_t _childrenCount;

};

static
void VAPHumanSetName(VAPHuman *humanoid, VAPString *name);

static
void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t childrenCount);

static
void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children);

#pragma mark -
#pragma mark Public Implementation

VAPHuman *VAPHumanCreateWithParameters(char *name, uint16_t age, VAPGender gender) {
    
    VAPHuman *humanoid = VAPObjectCreateType(VAPHuman);
    assert(humanoid != NULL);
    VAPString *string = VAPStringCreateWithString(name);
    VAPArray *array = VAPObjectCreateType(VAPArray);
    VAPHumanSetChildren(humanoid, array);
    VAPHumanSetName(humanoid, string);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);

    return humanoid;
}


void __VAPHumanDeallocate(void *object) {

    VAPHuman *human = object;
    VAPHumanDivorce(object);
    VAPHumanSetFather(human, NULL);
    VAPHumanSetMother(human, NULL);
    VAPObjectRelease(VAPHumanGetName(human));
    VAPArray *array = VAPHumanGetChildren(object);
    VAPArrayRemoveAllObjects(array);
    
    
    
    __VAPObjectDeallocate(object);
}

void VAPHumanMarry(VAPHuman *human, VAPHuman *partner) {

    if (NULL != human && NULL != partner && human != partner) {
        if (VAPHumanGetGender(human) != VAPHumanGetGender(partner)) {
            if (!VAPHumanGetPartner(human) || !VAPHumanGetPartner(partner)) {
                if (VAPHumanGetGender(human) == VAPGenderMale) {
                    VAPObjectRetain(partner);
                } else if (VAPHumanGetGender(partner) == VAPGenderMale) {
                    VAPObjectRetain(human);
                }
                human->_partner = partner;
                partner->_partner = human;
                
            }
        }
    }
}

void VAPHumanDivorce(VAPHuman *human) {
    if (NULL != human) {
        VAPHuman *partner = VAPHumanGetPartner(human);
        if (NULL != partner) {
            if (VAPHumanGetGender(human) == VAPGenderMale) {
                partner->_partner = NULL;
                VAPObjectRelease(partner);
                human->_partner = NULL;
            } else if (VAPHumanGetGender(partner) == VAPGenderMale) {
                human->_partner = NULL;
                partner->_partner = NULL;
                VAPObjectRelease(human);
                
            }
        }
        
    }
}

void VAPHumanBirthChild(VAPHuman *human, VAPHuman *partner) { // change logic

    if (NULL != human && NULL != partner && partner != human) {
        if (VAPHumanIsMarriedWithPartner(human, partner)) {
            VAPHuman *child = VAPHumanCreateWithParameters("unname", 0, arc4random_uniform(3));
            VAPHumanSetChild(human, child);
            VAPHumanSetChild(partner, child);
            VAPHumanSetFather(child, human);
            VAPHumanSetMother(child, partner);
        }
        
        
        
        
    }
}

#pragma mark -
#pragma mark Accessors

VAPArray *VAPHumanGetChildren(VAPHuman *humanoid) {
    return  NULL != humanoid ? humanoid->_children : NULL ;
}

VAPHuman *VAPHumanGetPartner(VAPHuman *humanoid) {
    return humanoid ? humanoid->_partner : NULL;
}

void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother) {
    VAPMacrosSetter(humanoid, mother, VAPHuman);
}

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father) {
    VAPMacrosSetter(humanoid, father, VAPHuman);
}

VAPString *VAPHumanGetName(VAPHuman *humanoid) {
    
    return NULL != humanoid ? humanoid->_name : NULL;
}

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age) {
    VAPMacrosSetter(humanoid, age, VAPHuman);
}

uint16_t VAPHumanGetAge(VAPHuman *humanoid) {

    return NULL != humanoid ? humanoid->_age : 0;
}

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender) {
    VAPMacrosSetter(humanoid, gender, VAPHuman);
}

VAPGender VAPHumanGetGender(VAPHuman *humanoid) {
    
    return NULL != humanoid ? humanoid->_gender : 0;
}

void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t childrenCount) {
    VAPMacrosSetter(humanoid, childrenCount, VAPHuman);
}

uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid) {
    
    return humanoid != NULL ? humanoid->_childrenCount : 0;

}

bool VAPHumanIsMarriedWithPartner(VAPHuman *human, VAPHuman *partner) {
    return true;
}

#pragma mark -
#pragma mark Private Implementation

void VAPHumanSetName(VAPHuman *humanoid, VAPString *name) {
    if (NULL != humanoid && NULL != name) {
        VAPString *oldName = VAPHumanGetName(humanoid);
        if (oldName != name) {
            VAPObjectRetain(name);
            VAPObjectRelease(oldName);
            
            humanoid->_name = name;
        }
    }
}

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) {
    if (humanoid != NULL && child != NULL && humanoid != child) {
        uint64_t childrenCount = VAPHumanGetChildrenCount(humanoid);
        if (childrenCount < kMaxChildrenCount) {
            VAPArrayAddObject(VAPHumanGetChildren(humanoid), child);
            VAPHumanSetChildrenCount(humanoid, childrenCount + 1);
        } else {
            printf("Family tired\n");
        }
    }
}

void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children) {
    if (NULL != humanoid && NULL != children) {
        VAPArray *oldChildren = VAPHumanGetChildren(humanoid);
        if (oldChildren != children) {
            VAPObjectRetain(children);
            VAPObjectRelease(oldChildren);
            
            humanoid->_children = children;
        }
    }
}



