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
    VAPHumanSetChildren(humanoid, VAPObjectCreateType(VAPArray));
    VAPHumanSetName(humanoid, VAPStringCreateWithString(name));
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);

    return humanoid;
}


void __VAPHumanDeallocate(void *object) {
    VAPHuman *human = object;
    VAPHumanDivorce(human);
    VAPHumanSetFather(human, NULL);
    VAPHumanSetMother(human, NULL);
    VAPObjectRelease(VAPHumanGetName(human));
    VAPArray *array = VAPHumanGetChildren(human);
    VAPArrayRemoveAllObjects(array);
    VAPObjectRelease(array);
 
    __VAPObjectDeallocate(human);
}

void VAPHumanMarry(VAPHuman *human, VAPHuman *partner) {

    if (NULL != human && NULL != partner && human != partner) {
        VAPGender humanGender = VAPHumanGetGender(human);
        VAPGender partnerGender = VAPHumanGetGender(partner);
        if (humanGender != partnerGender) {
            if (!(VAPHumanIsMarried(human) || VAPHumanIsMarried(partner))) {
                if (humanGender == VAPGenderMale) {
                    VAPObjectRetain(partner);
                } else if (partnerGender == VAPGenderMale) {
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
                human->_partner = NULL;
                VAPObjectRelease(partner);
            } else if (VAPHumanGetGender(partner) == VAPGenderMale) {
                human->_partner = NULL;
                partner->_partner = NULL;
                VAPObjectRelease(human);
            }
        }
    }
}

VAPHuman *VAPHumanCreateChild(VAPHuman *human, VAPHuman *partner) {
    VAPHuman *child = NULL;
    if (NULL != human && NULL != partner && partner != human) {
        if (VAPHumanIsMarriedWithPartner(human, partner)) {
            child = VAPHumanCreateWithParameters("unname", 0, arc4random_uniform(3));
            VAPHumanSetChild(human, child);
            VAPHumanSetChild(partner, child);
            VAPHumanSetFather(child, human);
            VAPHumanSetMother(child, partner);
        }
    }
    return child;
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

bool VAPHumanIsMarriedWithPartner(VAPHuman *human, VAPHuman *partner) {
//    if (NULL != human && NULL != partner) {
//        if (VAPHumanGetPartner(human) == partner && VAPHumanGetPartner(partner) == human) {
//            return true;
//        }
//    }
//    return false;
    
    return (VAPHumanGetPartner(human) == partner) && (VAPHumanGetPartner(partner) == human);
}

bool VAPHumanIsMarried(VAPHuman *human) {

//    return NULL != human ? NULL != human->_partner ? true : false : false;
    return (NULL != human) && (NULL != human->_partner);
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



