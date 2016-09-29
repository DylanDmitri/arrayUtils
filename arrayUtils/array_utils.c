//
//  array_utils.c
//  arrayUtils
//
//  Created by Dylan Gray on 11/5/15.
//  Copyright © 2015 Dylan Gray. All rights reserved.
//

#include "array_utils.h"

int* makeArray(int n){
    if (n<1){
        printf("parameter n passed to function <makeArray> is too small");
        return NULL;
    }
    return (int*)malloc(sizeof(int) *n);
}

double* makeDoubleArray(int n){
    if (n<1){
        printf("parameter n passed to function <makeDoubleArray> is too small");
        return NULL;
    }
    return (double*)malloc(sizeof(double) *n);
}


double mean(const int *a, int n){
    if (a == NULL){
        printf("pointer a passed to function <mean> is NULL");
        return 0;
    }
    if (n < 1){
        printf("in function <mean>, n must be greater than 0");
        return 0;
    }
    int i;
    int sum = 0; //sum of array a
    for (i = 0; i<n; i++){
        sum += a[i];
    }
    return ((double)sum) / n;
}

double* windowMeans(const int *a, int n, int m){
    if (a == NULL){
        printf("pointer a passed to function <windowMeans> is NULL");
        return 0;
    }
    if (m < 1){
        printf("in function <windowMeans>, window must be greater than 0");
        return 0;
    }
    if (n < 1){
        printf("in function <windowMeans>, n must be greater than 0");
        return 0;
    }
    double* means = makeDoubleArray(n-m+1);
    int* temp = makeArray(n);
    int i, j;
    for (i=0; i<n-m+1; i++){  //for each spot in the input array
        for(j=0; j<m; j++){ //add the next <window> elements to temp array
            temp[j] = a[j+i];
        }
        means[i] = mean(temp, m); //average the temp array, add to means
    }
    return means;
    
    //note: this could have been more efficient
    //   each loop replaces the entire temp array
    //   would be better to replace only one value from the temp array
    //   makes it polynomial with respect window size not linear
}

int mode(const int *a, int n){
    if (a == NULL){
        printf("pointer a passed to function <mode> is NULL");
        return 0;
    }
    if (n < 1){
        printf("in function <mode>, n must be greater than 0");
        return 0;
    }
    int* occurences = makeArray(10000);
    //so occurences is a cheap man's hashmap
    //it maps the index (the number) to the number of occurences of that number
    
    int i;
    for(i=0; i<10000; i++){
        //fill our map with 0 occurrences for each number
        occurences[i] = 0;
    }
    for(i=0; i<n; i++){
        //tally each number that appears
        occurences[a[i]]++;
    }
    
    int modeValue = 0; //what the mode is
    int modeOccurences = -1; //how many times it occured
    for(i=0; i<10000; i++){
        //for each possible value
        //if that value has more occurences than current mode's occurences
        if (occurences[i] > modeOccurences){
            //set mode to the new mode
            modeValue = i;
            modeOccurences = occurences[i];
        }
    }
    return modeValue;
}


int * getAllModes(const int *a, int n, int *resultSize){
    if (a == NULL){
        printf("pointer <a> passed to function <getAllModes> is NULL");
        return 0;
    }
    if (n < 1){
        printf("in function <getAllModes>, n must be greater than 0");
        return 0;
    }
    if (resultSize == NULL){
        printf("pointer <resultSize> passed to function <getAllModes> is NULL");
        return 0;
    }
    int* occurences = makeArray(10000);
    //see function mode
    int i;
    for(i=0; i<10000; i++){
        occurences[i] = 0;
    }
    for(i=0; i<n; i++){
        occurences[a[i]]++;
    }
    int modeOccurences = 0;
    for(i=0; i<10000; i++){
        if (occurences[i] > modeOccurences){
            //we only need to find the maximum occurrences here
            modeOccurences = occurences[i];
        }
    }
    if (modeOccurences > 0){
        int resultPointer = 0;
        for(i=0; i<10000; i++){
            //and then check what values have the maximum occurences
            if (occurences[i] == modeOccurences){
                //and add them to the results array
                resultSize[resultPointer++] = i;
            }
        }
    }
    return resultSize;
}
/*
int * filter(const int *a, int n, int threshold, int *resultSize){
    if (a == NULL){
        printf("pointer <a> passed to function <filter> is NULL");
        return 0;
    }
    if (n < 1){
        printf("in function <filter>, n must be greater than 0");
        return 0;
    }
    if (resultSize == NULL){
        printf("pointer <resultSize> passed to function <filter> is NULL");
        return 0;
    }
    int i;
    int resultPointer = 0;
    for (i=0; i<n; i++){
        if (a[i]>threshold){
            resultSize[resultPointer++] = a[i];
        }
    }
    return resultSize;
}*/

int * append(const int *a, int sizeA, int *b, int sizeB){
    if (a == NULL){
        printf("pointer <a> passed to function <append> is NULL");
        return 0;
    }
    if (sizeA < 1){
        printf("in function <filter>, sizeA must be greater than 0");
        return 0;
    }
    if (b == NULL){
        printf("pointer <b> passed to function <append> is NULL");
        return 0;
    }
    if (sizeB < 1){
        printf("in function <filter>, sizeB must be greater than 0");
        return 0;
    }
    int* result = makeArray(sizeA+sizeB);
    int i;
    for (i = 0; i<sizeA; i++){
        result[i] = a[i];
    }
    for (i = 0; i<sizeB; i++){
        result[i+sizeA] = b[i];
    }
    return result;
}
