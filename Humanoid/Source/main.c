//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//
//#include "VAPString.h"
//#include "VAPObject.h"
//#include "VAPArray.h"
//#include "VAPHumanoidObject.h"

#include <stdio.h>
#include <stdlib.h>

#include "VAPHumanoidObjectTests.h"

int main(int argc, const char * argv[]) {
//    
//    VAPHuman *Roger = VAPHumanCreate("Roger", 32, VAPGenderMale);
//    VAPHuman *Natasha = VAPHumanCreate("Natasha", 25, VAPGenderFemale);
//
//    VAPHumanMarry(Roger, Natasha);
//    VAPHumanFamalyBirthChild(Roger, Natasha);
    VAPStringTests();
    VAPArrayTests();
    return 0;
}
