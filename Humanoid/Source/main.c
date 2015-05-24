//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

// void [*obj(structura)]
// void *[*obj] = [*obj][index]
#include <stdio.h>
#include <stdlib.h>

#include "VAPHumanoidObjectTests.h"
#include "VAPArrayTests.h"
#include "VAPStringTests.h"

int main(int argc, const char * argv[]) {

    VAPStringTests();
    VAPArrayTests();
    VAPHumanoidObjectTest();
    return 0;
}
