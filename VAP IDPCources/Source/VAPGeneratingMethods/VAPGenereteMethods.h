//
//  VAPGenereteMethods.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 06.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPGenereteMethods__
#define __VAP_IDPCources__VAPGenereteMethods__


#include <stdio.h>

#define generetingMethodToPrintType(type, spec) void otput_##type(var) { \
;\
printf(spec,var);\
}
#define callGenereted(type,var) otput_##type(var)

generetingMethodToPrintType(int, "%d");

generetingMethodToPrintType(char, "%c");

#endif /* defined(__VAP_IDPCources__VAPGenereteMethods__) */
