//
//  DataStructure.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 10.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef VAP_IDPCources_DataStructure_h
#define VAP_IDPCources_DataStructure_h

//there are all very very bad names in structures. >_< it's very hard to come with up new names. for all theese datas...


typedef struct DataStructureOne DataStructureOne;

struct DataStructureOne {
    _Bool bool1;
    float floatVar;
    long long longVar;
    _Bool bool2;
    _Bool bool3;
    int intValue;
    short shortVar1;
    _Bool bool4;
    short shortVar2;
    double doubleValue;
    char *string;
    _Bool bool5;
    _Bool bool6;
    short shortVar3;
};

typedef struct DataStructureTwo DataStructureTwo;

struct DataStructureTwo {
    _Bool bool1;
    _Bool bool4;
    short shortVar2;
    long long longVar;
    _Bool bool2;
    int intValue;
    short shortVar1;
    double doubleValue;
    _Bool bool3;
    char *string;
    _Bool bool5;
    _Bool bool6;
     float floatVar;
    short shortVar3;
};

typedef struct DataStructureThree DataStructureThree;

struct DataStructureThree {
    char *string;
    double doubleValue;
    long long longVar;
    float floatVar;
    int intValue;
    short shortVar1;
    short shortVar2;
    short shortVar3;
    _Bool bool1;
    _Bool bool2;
    _Bool bool3;
    _Bool bool4;
    _Bool bool5;
    _Bool bool6;
};

typedef struct DataStructureFour DataStructureFour;

struct DataStructureFour {
    char *string;
    double doubleValue;
    long long longVar;
    float floatVar;
    int intValue;
    short shortVar1;
    short shortVar2;
    short shortVar3;
    union Data {
        struct {
            _Bool bool1:1;
            _Bool bool2:1;
            _Bool bool3:1;
            _Bool bool4:1;
            _Bool bool5:1;
            _Bool bool6:1;
        };
        char ch;
        
    } data;
};


#endif
