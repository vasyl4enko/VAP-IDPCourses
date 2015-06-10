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
    
};

static
void VAPHumanSetName(VAPHuman *humanoid, VAPString *name);

static
void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children);

#pragma mark -
#pragma mark Public Implementation

VAPHuman *VAPHumanCreateWithParameters(char *name, uint16_t age, VAPGender gender) {
    VAPHuman *humanoid = VAPObjectCreateType(VAPHuman);
    VAPArray *array = VAPObjectCreateType(VAPArray);
    VAPHumanSetChildren(humanoid, array);
    VAPObjectRelease(array);
    VAPString *string = VAPStringCreateWithString(name);
    VAPHumanSetName(humanoid, string);
    VAPObjectRelease(string);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);
    
    return humanoid;
}


void __VAPHumanDeallocate(void *object) {
    VAPHumanDivorce(object);
    VAPHumanSetFather(object, NULL);
    VAPHumanSetMother(object, NULL);
    VAPHumanSetName(object, NULL);
    VAPArrayRemoveAllObjects(VAPHumanGetChildren(object));
    VAPHumanSetChildren(object, NULL);
    
    __VAPObjectDeallocate(object);
}

bool VAPHumanMarry(VAPHuman *human, VAPHuman *partner) {
    bool result = false;
    if (NULL != human && NULL != partner && human != partner) {
        VAPGender humanGender = VAPHumanGetGender(human);
        VAPGender partnerGender = VAPHumanGetGender(partner);
        if (humanGender != partnerGender) {
            if (!(VAPHumanIsMarried(human) || VAPHumanIsMarried(partner))) {
                VAPObjectRetain(humanGender == VAPGenderMale ? partner : human);
                human->_partner = partner;
                partner->_partner = human;
                result = true;
            }
        }
    }
    return result;
}

void VAPHumanDivorce(VAPHuman *human) {
    if (NULL != human) {
        VAPHuman *partner = VAPHumanGetPartner(human);
        if (NULL != partner) {
            partner->_partner = NULL;
            human->_partner = NULL;
            VAPObjectRelease(VAPHumanGetGender(human) == VAPGenderMale
                             ? partner
                             : human);
        }
    }
}

VAPHuman *VAPHumanCreateChild(VAPHuman *human, VAPHuman *partner) {
    VAPHuman *child = NULL;
    if (NULL != human &&
        NULL != partner &&
        partner != human &&
        VAPGenderOther != VAPHumanGetGender(human) &&
        VAPGenderOther != VAPHumanGetGender(partner))
    {
        if (VAPHumanGetPartner(human) == partner) {
            child = VAPHumanCreateWithParameters("unname", 0, arc4random_uniform(2) + 1);
            VAPHumanAddChild(human, child);
            VAPHumanAddChild(partner, child);
        }
    }
    return child;
}

void VAPHumanRemoveChildAtIndex(VAPHuman *human, uint64_t index) {
    assert(index < kMaxChildrenCount);
    if (NULL != human) {
        VAPArrayRemoveObjectAtIndex(VAPHumanGetChildren(human), index);
    }
}

void VAPHumanRemoveChild(VAPHuman *human, VAPHuman *child) {
    if (NULL != human && NULL != child) {
        void **children = VAPArrayGetElements(VAPHumanGetChildren(human));
        uint64_t count = VAPArrayGetCount(VAPHumanGetChildren(human));
        for (uint64_t index = 0; index < count; index++) {
            if (children[index] == child) {
                VAPArrayRemoveObjectAtIndex(VAPHumanGetChildren(human), index);
            }
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
    VAPAssignSetter(humanoid, mother, VAPHuman);
}

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father) {
    VAPAssignSetter(humanoid, father, VAPHuman);
}

VAPString *VAPHumanGetName(VAPHuman *humanoid) {
    
    return NULL != humanoid ? humanoid->_name : NULL;
}

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age) {
    VAPAssignSetter(humanoid, age, VAPHuman);
}

uint16_t VAPHumanGetAge(VAPHuman *humanoid) {
    
    return NULL != humanoid ? humanoid->_age : 0;
}

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender) {
    VAPAssignSetter(humanoid, gender, VAPHuman);
}

VAPGender VAPHumanGetGender(VAPHuman *humanoid) {
    
    return NULL != humanoid ? humanoid->_gender : 0;
}

uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid) {
    
    return NULL != humanoid ? VAPArrayGetCount(VAPHumanGetChildren(humanoid)) : 0;
    
}

bool VAPHumanIsMarried(VAPHuman *human) {
    
    return (NULL != human) && (NULL != human->_partner);
}

#pragma mark -
#pragma mark Private Implementation

void VAPHumanSetName(VAPHuman *humanoid, VAPString *name) {
    if (NULL != humanoid) {
        VAPObjectRetain(name);
        VAPObjectRelease(humanoid->_name);
        humanoid->_name = name;
    }
}

void VAPHumanAddChild(VAPHuman *humanoid, VAPHuman *child) {
    if (humanoid != NULL && child != NULL && humanoid != child) {
        uint64_t childrenCount = VAPHumanGetChildrenCount(humanoid);
        if (childrenCount < kMaxChildrenCount) {
            VAPArrayAddObject(VAPHumanGetChildren(humanoid), child);
            if (VAPHumanGetGender(humanoid) == VAPGenderMale) {
                VAPHumanSetFather(child, humanoid);
            } else {
                VAPHumanSetMother(child, humanoid);
            }
        }
    }
}

void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children) {
    if (NULL != humanoid) {
        VAPArray *oldChildren = VAPHumanGetChildren(humanoid);
        if (oldChildren != children) {
            VAPObjectRetain(children);
            VAPObjectRelease(oldChildren);
            humanoid->_children = children;
        }
    }
}



