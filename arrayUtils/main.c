//
//  main.c
//  arrayUtils
//
//  Created by Dylan Gray on 11/5/15.
//  Copyright © 2015 Dylan Gray. All rights reserved.
//

#include <stdio.h>
#include "array_utils.h"

int main(int argc, const char * argv[]) {
    int modes = 1;
    int arraysize = 1;
    int* a = makeArray(arraysize);
    a[0] = 3;
    
    /*
    a[0] = 3;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 2;
    */
    
    int* result = makeArray(modes);
    getAllModes(a, arraysize, result);
    
    int i;
    for (i = 0; i<modes; i++){
        printf("%d", result[i]);
    }
    
    return 0;
}
