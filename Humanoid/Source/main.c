//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//
#include "VAPString.h"
#include "VAPObject.h"
#include "VAPArray.h"
#include "VAPHumanoidObject.h"

#include <stdio.h>
#include <stdlib.h>



int main(int argc, const char * argv[]) {
    
//    VAPHumanoidObjectTest();
    VAPHuman *Roger = VAPHumanCreate("Roger", 32, VAPGenderMale);
    VAPHuman *Huegur = VAPHumanCreate("Huegur", 43, VAPGenderMale);
    VAPArray *array = VAPArrayCreate(Roger);
    VAPArrayAddElement(array, Huegur);
    void *returArr = VAPArrayGetObjects(array);
    

    return 0;
}
