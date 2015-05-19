//
//  VAPHumanoidObjectTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObjectTests.h"
#include "VAPHumanoidObject.h"
#include "VAPArray.h"

#pragma mark -
#pragma mark Private Declaration

static
void VAPHumanoidFamallyTest(void);

#pragma mark -
#pragma mark Public impl


void VAPHumanoidObjectTest() {
    VAPHumanoidFamallyTest();
}

#pragma mark -
#pragma mark Private Implement

void VAPHumanoidFamallyTest(void) {
    // childcount need make private
    VAPHuman *Roger = VAPHumanCreate("Roger", 32, VAPGenderMale);
    VAPHuman *Natasha = VAPHumanCreate("Natasha", 25, VAPGenderFemale);
    VAPHuman *Nikita = VAPHumanCreate("Nikita", 20, VAPGenderMale);
    VAPHuman *Olya = VAPHumanCreate("Olya", 23, VAPGenderFemale);
    VAPHuman *Vladik = VAPHumanCreate("Vladik", 54, VAPGenderMale);
    VAPHuman *Katya = VAPHumanCreate("Kate", 30, VAPGenderFemale);
    VAPHuman *Junk;
    VAPHumanoidMarry(Roger, Natasha);
    VAPHumanoidMarry(Roger, Katya);
    VAPHumanoidMarry(Nikita, Vladik);
    VAPHumanoidMarry(Nikita, Katya);
    VAPHumanoidMarry(Vladik, Olya);
    
    VAPHumanFamalyBirthChild(Vladik, Olya);
//    printf("Count child %d\n", VAPHumanGetChildrenCount(Vladik));
//    printf("Count child %d\n", VAPHumanGetChildrenCount(Olya));
    VAPHumanFamalyBirthChild(Vladik, Olya);
//    printf("Count child %d\n", VAPHumanGetChildrenCount(Vladik));
//    printf("Count child %d\n", VAPHumanGetChildrenCount(Olya));
//    printf(" \"Bug with junk\" Count child %d\n", VAPHumanGetChildrenCount(Junk)); // little bug with junk
    
    VAPHumanoidDivorce(Vladik, Olya);
    VAPHumanoidDivorce(Roger, Katya);
    VAPHumanoidDivorce(Roger, Natasha);
    VAPHumanoidMarry(Roger, Olya);
    VAPHumanoidMarry(Vladik, Natasha);
    
    VAPHumanSetChild(Vladik, Roger);
    VAPHumanSetChild(Vladik, Natasha);
    
    VAPHumanFamalyBirthChild(Roger, Olya);
    VAPHumanFamalyBirthChild(Vladik, Natasha);

    
    
  
    VAPArray *children = VAPArrayGetObjects(Vladik);
    ((VAPArray *)children)->_elements;
    for (int i = 0; i < 5; i++, ((VAPArray *)children)->_elements++) {
        printf("child name %s\n", VAPHumanGetName(((VAPArray *)children)->_elements));
        printf("%s gender %u\n ",VAPHumanGetName(((VAPArray *)children)->_elements));
        printf("%s age %d\n",VAPHumanGetName(((VAPArray *)children)->_elements));
    }

//    VAPHumanDealoc(Roger);
//    VAPHumanDealoc(Natasha);
//    VAPHumanDealoc(Nikita);
//    VAPHumanDealoc(Olya);
//    VAPHumanDealoc(Vladik);
//    VAPHumanDealoc(Katya);

 
}


