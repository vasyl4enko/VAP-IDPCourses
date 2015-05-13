//
//  VAPHumanoidObjectTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObjectTests.h"
#include "VAPHumanoidObject.h"

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
    VAPHuman *Roger = VAPHumanCreate("Roger", 32, Male);
    VAPHuman *Natasha = VAPHumanCreate("Natasha", 25, Female);
    VAPHuman *Nikita = VAPHumanCreate("Nikita", 20, Male);
    VAPHuman *Olya = VAPHumanCreate("Olya", 23, Female);
    VAPHuman *Vladik = VAPHumanCreate("Vladik", 54, Male);
    VAPHuman *Katya = VAPHumanCreate("Kate", 30, Female);
    VAPHuman *Katy;
    VAPMarriedHumanoid(Roger, Natasha);
    VAPMarriedHumanoid(Roger, Katya);
    VAPMarriedHumanoid(Nikita, Vladik);
    VAPMarriedHumanoid(Nikita, Katya);
    VAPMarriedHumanoid(Vladik, Olya);
    
    VAPHumanFamalyBirthChild(Vladik, Olya);
    printf("Count child %d\n", VAPHumanGetChildrenCount(Vladik));
    printf("Count child %d\n", VAPHumanGetChildrenCount(Olya));
    VAPHumanFamalyBirthChild(Vladik, Olya);
    printf("Count child %d\n", VAPHumanGetChildrenCount(Vladik));
    printf("Count child %d\n", VAPHumanGetChildrenCount(Olya));
    printf("Count child %d\n", VAPHumanGetChildrenCount(Katy));
    
    
    VAPDivorceHumanoid(Vladik, Olya);
    VAPDivorceHumanoid(Roger, Katya);
    VAPDivorceHumanoid(Roger, Natasha);
    VAPMarriedHumanoid(Roger, Olya);
    VAPMarriedHumanoid(Vladik, Natasha);
    
    VAPHumanSetChild(Vladik, Roger);
    VAPHumanSetChild(Vladik, Natasha);
    
    VAPHumanFamalyBirthChild(Roger, Olya);
    printf("Roger Count child %d\n", VAPHumanGetChildrenCount(Roger));
    printf("olya Count child %d\n", VAPHumanGetChildrenCount(Olya));
    VAPHumanFamalyBirthChild(Vladik, Natasha);
    printf("Vladik Count child %d\n", VAPHumanGetChildrenCount(Vladik));
    printf("Natasha Count child %d\n", VAPHumanGetChildrenCount(Natasha));
    
    
    uint8_t childCount = VAPHumanGetChildrenCount(Vladik);
    VAPHuman **children = VAPHumanGetArrayOfChildren(Vladik);
    
    for (int i = 0; i < childCount; i++, children++) {
        printf("child name %s\n", VAPHumanGetName(*children));
        printf("%s gender %u\n ",VAPHumanGetName(*children),VAPHumanGetGender(*children));
        printf("%s age %d\n",VAPHumanGetName(*children),VAPHumanGetAge(*children));
    }

    

    
    
    
    
}


