//
//  VAPHumanoidObject.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObject.h"
#include "VAPString.h"
#include "VAPObject.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>



static const int kMaxchildrenCount = 20;

#pragma mark -
#pragma mark Private Declaration


struct VAPHuman {
    VAPObject _super;
    VAPHuman *_children[kMaxchildrenCount]; // change to class
    VAPHuman *_partner;
    VAPHuman *_mother;
    VAPHuman *_father;
    VAPString *_name;
    uint16_t _age;
    VAPGender _gender;
    uint8_t _childrenCount:5; //don't need
    bool _isMarried:1; // don't need
};

//static
//void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);

#pragma mark -
#pragma mark Public Implementation

VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender) {
//    VAPHuman *humanoid = calloc(1, sizeof(VAPHuman *));
//    
//    assert(humanoid != NULL);
//    humanoid->_name = malloc(sizeof(VAPString *));
//
//    VAPHumanSetName(humanoid, name);
//    VAPHumanSetAge(humanoid, age);
//    VAPHumanSetGender(humanoid, gender);
    VAPString *string = VAPObjectCreateType(VAPString);
    VAPHuman *humanoid = VAPObjectCreateType(VAPHuman);
    humanoid->_name = string;
    
    assert(humanoid != NULL);
//    humanoid->_name = malloc(sizeof(VAPString *));
   
    
    VAPHumanSetName(humanoid, name);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);

    return humanoid;
}

//void VAPHumanDealoc(VAPHuman *humanoid) {
//    if (humanoid) {
//        if (VAPHumanGetChildrenCount(humanoid) == 0) {
//            free(humanoid);
//        } else if (VAPHumanGetChildrenCount(humanoid) != 0) {
//            VAPHuman **children = VAPHumanGetArrayOfChildren(humanoid);
//            for (int i = 0;i < VAPHumanGetChildrenCount(humanoid) ; i++, children++) {
//                free(children);
//            }
////            free(humanoid);
//        }
//    }
//    
//}

void VAPHumanoidMarry(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if ((man->_gender == VAPGenderMale && woman->_gender == VAPGenderFemale)  ) {
            if (!(VAPHumanGetPartner(man) || VAPHumanGetPartner(woman))) {
                VAPHumanSetMarried(man, true);
                VAPHumanSetMarried(woman, true);
                VAPHumanSetPartner(man, woman);
                VAPHumanSetPartner(woman, man);
                printf("%s and %s MARRIED1\n",VAPStringGetName(man->_name),VAPStringGetName(woman->_name));
            } else {
                printf("can't\n");
            }
            
        } else {
            printf("can't\n");
        }
    }
}

void VAPHumanoidDivorce(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if (man->_partner == woman && woman->_partner == man) {
            VAPHumanSetMarried(man, false);
            VAPHumanSetMarried(woman, false);
            VAPHumanSetPartner(man, NULL);
            VAPHumanSetPartner(woman, NULL);
            printf("%s and %s deMARRIED\n",VAPHumanGetName(woman), VAPHumanGetName(man));
            
        } else {
            printf("%s and %s can't demarried\n",VAPHumanGetName(woman), VAPHumanGetName(man));
        }
    }
}

void VAPHumanFamalyBirthChild(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if (VAPHumanGetPartner(man) == woman && VAPHumanGetPartner(woman) == man) {
            VAPHuman *child = VAPHumanCreate("unname", 0, rand()%3);
            VAPHumanSetChild(man, child);
            VAPHumanSetChild(woman, child);
            VAPHumanSetFather(child, man);
            VAPHumanSetMother(child, woman);
            
        }
    }
}

#pragma mark -
#pragma mark Accesors

VAPHuman** VAPHumanGetArrayOfChildren(VAPHuman *humanoid) {
    VAPHuman **childr = humanoid->_children;
    return childr;
}

void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner) {
    if (humanoid) {
        humanoid->_partner = partner;
    }
}

VAPHuman *VAPHumanGetPartner(VAPHuman *humanoid) {
//    if (humanoid) {
//        return NULL;
//    }
    return humanoid ? humanoid->_partner :NULL;
}

void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother) {
    if (humanoid) {
        humanoid->_mother = mother;
    }
}

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father) {
    if (humanoid) {
        humanoid->_father = father;
    }
}

void VAPHumanSetName(VAPHuman *humanoid, char *name) {
    if (humanoid != NULL) {
       VAPStringSetName(humanoid->_name, name);
    }
    
}

char* VAPHumanGetName(VAPHuman *humanoid) {
    
    return humanoid ? VAPStringGetName(humanoid->_name) : 0;
    
}

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age) {
    if (humanoid) {
        humanoid->_age = age;
    }
}

uint16_t VAPHumanGetAge(VAPHuman *humanoid) {

    return humanoid ? humanoid->_age : 0;
}

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender) {
    if (humanoid) {
        humanoid->_gender = gender;
    }
}

VAPGender VAPHumanGetGender(VAPHuman *humanoid) {
    if (!humanoid) {
        return 0;
    }
    
    return humanoid->_gender;
}

void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t count) {
    if (humanoid){
        humanoid->_childrenCount = count;
    }
}

uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid) {
    
    return humanoid ? humanoid->_childrenCount : 0;

}

void VAPHumanSetMarried(VAPHuman *humanoid, bool isMarried) {
    if (humanoid){
        humanoid->_isMarried = isMarried;
    }
}

#pragma mark -
#pragma mark Private Implementation

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) {
    if (humanoid != NULL && child != NULL) {
        if ( VAPHumanGetChildrenCount(humanoid) < kMaxchildrenCount) {
            for (int i = 0; i <= humanoid->_childrenCount; i++) {
                if(i == humanoid->_childrenCount) {
                    humanoid->_children[i] = child;
                    uint8_t incrementValue = 0;
                    incrementValue = humanoid->_childrenCount;
                    incrementValue++;
                    VAPHumanSetChildrenCount(humanoid, incrementValue);
                    break;
                }
            }
        } else {
            printf("Famaly tired\n");
        }
    }
}

void __VAPHumanDeallocate(void *object) {
    
    __VAPObjectDeallocate(object);
}

