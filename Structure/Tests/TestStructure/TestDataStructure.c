//
//  TestDataStructure.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 11.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "TestDataStructure.h"
#include "DataStructure.h"
#pragma mark -
#pragma mark Private Declarations

void VAPLocationItemsOfDataStructure();
void VAPSizeOfDataStructure();

#pragma mark -
#pragma mark Public Implementations

void VAPOutputTestDataStructures(){
    VAPLocationItemsOfDataStructure();
    VAPSizeOfDataStructure();
}


#pragma mark -
#pragma mark Private Implementations

void VAPLocationItemsOfDataStructure(){
    
    printf("Print DataStructureOne \n");
    printf("bool1 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool1));
    printf("floatVar offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, floatVar));
    printf("longVar offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, longVar));
    printf("bool2 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool2));
    printf("bool3 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool3));
    printf("intValue offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, intValue));
    printf("shortVar1 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, shortVar1));
    printf("bool4 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool4));
    printf("shortVar2 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, shortVar2));
    printf("doubleValue offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, doubleValue));
    printf("string offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, string));
    printf("bool5 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool5));
    printf("bool6 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, bool6));
    printf("shortVar3 offset = %lu byte in address structure.\n",
           offsetof( DataStructureOne, shortVar3));

 
}

void VAPSizeOfDataStructure() {

    printf("Size of structure one - %lu\n",sizeof(DataStructureOne));
    printf("Size of structure two - %lu\n",sizeof(DataStructureTwo));
    printf("Size of structure three - %lu\n",sizeof(DataStructureThree));
    printf("Size of structure four - %lu\n",sizeof(DataStructureFour));
}