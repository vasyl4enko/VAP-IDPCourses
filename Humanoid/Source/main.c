//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//
#include "VAPHumanoidObject.h"
#include <stdio.h>
#include <stdlib.h>

void testChild() ;

int main(int argc, const char * argv[]) {
//    VAPHuman *Kirill = VAPHumanCreate("Kirill", 22, Male , );
    uint16_t age = 50;
    uint8_t count = 0;
    char *name = "Kirill";
    VAPHuman *Kirill = VAPHumanCreate(name, age, Male, count);
    VAPHuman *child = VAPHumanCreate(name, age, Female, count);
   
     VAPMarriedHumanoid(Kirill, child);
     VAPDivorceHumanoid(Kirill, child);
    printf("%d\n",rand()%2);
    int i = 0;
    while (i < 1000) {
        printf("%d\n",rand()%2);
        i++;
    }
    return 0;
}
void testChild(VAPHuman *hum) {
    VAPHuman *humf = VAPHumanGetChild(hum);
    printf("%d\n",VAPHumanGetAge(humf));
}