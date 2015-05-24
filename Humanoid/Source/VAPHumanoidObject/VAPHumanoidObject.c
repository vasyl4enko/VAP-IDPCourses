//
//  VAPHumanoidObject.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObject.h"
#include "VAPString.h"
#include "VAPArray.h"
#include "VAPObject.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "VAPMacros.h"



static const int kMaxchildrenCount = 20;

#pragma mark -
#pragma mark Private Declaration


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
void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t childrenCount);

static
void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children);

#pragma mark -
#pragma mark Public Implementation

VAPHuman* VAPHumanCreateWithParameters(char *name, uint16_t age, VAPGender gender) {
    
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

void VAPHumanMarry(VAPHuman *human, VAPHuman *partner) { // change logic
//    if (human != NULL && partner != NULL) {
//        if ((human->_gender == VAPGenderMale && partner->_gender == VAPGenderFemale)  ) {
//            if (!(VAPHumanGetPartner(human) || VAPHumanGetPartner(partner))) {
//                VAPHumanSetPartner(human, partner);
//                VAPHumanSetPartner(partner, human);
//                printf("%s and %s MARRIED1\n",VAPStringGetName(human->_name),VAPStringGetName(partner->_name));
//            } else {
//                printf("can't\n");
//            }
//        } else {
//            printf("can't\n");
//        }
//    }
    if (NULL != human && NULL != partner && human != partner) {
        if (VAPHumanGetGender(human) != VAPHumanGetGender(partner)) {
            if (!VAPHumanGetPartner(human) || !VAPHumanGetPartner(partner)) {
                if (VAPHumanGetGender(human) == VAPGenderMale) {
                    VAPObjectRetain(partner);
                } else if (VAPHumanGetGender(partner) == VAPGenderMale) {
                    VAPObjectRetain(human);
                }
                VAPHumanSetPartner(human, partner);
                VAPHumanSetPartner(partner, human);
                
            }
        }
    }
}

void VAPHumanDivorce(VAPHuman *human) { // change logic
//    if (man != NULL && woman != NULL) {
//        if (man->_partner == woman && woman->_partner == man) {
//
//            VAPHumanSetPartner(man, NULL);
//            VAPHumanSetPartner(woman, NULL);
//            printf("%s and %s deMARRIED\n",VAPHumanGetName(woman), VAPHumanGetName(man));
//            
//        } else {
//            printf("%s and %s can't demarried\n",VAPHumanGetName(woman), VAPHumanGetName(man));
//        }
//    }
    if (NULL != human) {
        VAPHuman *partner = VAPHumanGetPartner(human);
        VAPHumanSetPartner(human, NULL);
        VAPHumanSetPartner(partner, NULL);
        if (VAPHumanGetGender(human) == VAPGenderMale) {
            VAPObjectRelease(partner);
        } else if (VAPHumanGetGender(partner) == VAPGenderMale) {
            VAPObjectRelease(human);
        }
    }
}

void VAPHumanFamilyBirthChild(VAPHuman *human, VAPHuman *partner) { // change logic
//    if (man != NULL && woman != NULL) {
//        if (VAPHumanGetPartner(man) == woman && VAPHumanGetPartner(woman) == man) {
//            VAPHuman *child = VAPHumanCreate("unname", 0, rand()%3);
//            VAPHumanSetChild(man, child);
//            VAPHumanSetChild(woman, child);
//            VAPHumanSetFather(child, man);
//            VAPHumanSetMother(child, woman);
//            
//        }
//    }
    if (NULL != human && NULL != partner) {
        if (VAPHumanGetPartner(human) == partner && VAPHumanGetPartner(partner) == human) {
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
    return humanoid != NULL ? humanoid->_children : NULL ;
}

void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner) {
    VAPMacrosSetter(humanoid, partner, VAPHuman);
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

void VAPHumanSetName(VAPHuman *humanoid, VAPString *name) {
    VAPMacrosSetter(humanoid, name, VAPHuman);
}

char *VAPHumanGetName(VAPHuman *humanoid) {
    
    return humanoid ? VAPStringGetName(humanoid->_name) : 0;
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

#pragma mark -
#pragma mark Private Implementation

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) {
    if (humanoid != NULL && child != NULL && humanoid != child) {
        if (VAPHumanGetChildrenCount(humanoid) < kMaxchildrenCount) {
            VAPArrayAddElement(VAPHumanGetChildren(humanoid), child);
        } else {
            printf("Family tired\n");
        }
    }
}

void VAPHumanSetChildren(VAPHuman *humanoid, VAPArray *children) {
    VAPMacrosSetter(humanoid, children, VAPHuman);
}

void __VAPHumanDeallocate(void *object) {
    
    __VAPObjectDeallocate(object);
}

