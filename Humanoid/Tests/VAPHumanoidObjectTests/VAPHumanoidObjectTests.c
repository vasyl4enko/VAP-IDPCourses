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
    VAPHuman *Roger = VAPHumanCreate("Roger", 32, Male, 0);
    VAPHuman *Natasha = VAPHumanCreate("Natasha", 25, Female, 0);
    VAPHuman *Nikita = VAPHumanCreate("Nikita", 20, Male, 0);
    VAPHuman *Olya = VAPHumanCreate("Olya", 23, Female, 0);
    VAPHuman *Vladik = VAPHumanCreate("Vladik", 54, Male, 0);
    VAPHuman *Katya = VAPHumanCreate("Kate", 30, Female, 0);
    
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
    
    
    VAPDivorceHumanoid(Vladik, Olya);
    VAPDivorceHumanoid(Roger, Katya);
    VAPDivorceHumanoid(Roger, Natasha);
    VAPMarriedHumanoid(Roger, Olya);
    VAPMarriedHumanoid(Vladik, Natasha);
    
    VAPHumanFamalyBirthChild(Roger, Olya);
    printf("Roger Count child %d\n", VAPHumanGetChildrenCount(Roger));
    printf("olya Count child %d\n", VAPHumanGetChildrenCount(Olya));
    VAPHumanFamalyBirthChild(Vladik, Natasha);
    printf("Vladik Count child %d\n", VAPHumanGetChildrenCount(Vladik));
    printf("Natasha Count child %d\n", VAPHumanGetChildrenCount(Natasha));

    
    
    
    
}


