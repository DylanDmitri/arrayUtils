//
//  array_utils.h
//  arrayUtils
//
//  Created by Dylan Gray on 11/5/15.
//

#include <stdio.h>

/*
 * returns an empty int array of size n
 */
int* makeArray(int n);

/*
 * returns an empty double array of size n
 */
double* makeDoubleArray(int n);

/*
 * returns an empty matrix with given number of rows and columns
 */
int** makeMatrix(int rows, int columns);

/*
 * returns the mean of array a
 * @parameter a : array to be averaged
 * @parameter n : size of array a
 */
double mean(const int *a, int n);

/*
 * returns an array full of rolling means
 * return array is of length (length of array a - window size + 1)
 *
 * e.g. with a window size of 3:
 * input (a [2 4 3 5 7 6]
 *           |=3=|
 *             |=4=|
 *               |=5=|
 *                 |=6=|
 * output    [ 3 4 5 6 ]
 *
 * @parameter a : array to be operated on
 * @parameter n : length of array a
 * @parameter m : size of windows to average over
 */
double * windowMeans(const int *a, int n, int m);

/*
 * returns one mode from array a of length n
 *
 * when mutiple modes have equal instances;
 *     returns the mode with the biggest value
 *
 * @parameter a : array to find the modes of
 * @parameter n : size of array a
 */
int mode(const int *a, int n);

/*
 * fills array with all the modes from input array
 * modes are sorted in increasing numeric order
 *
 * @parameter a : input array
 * @parameter n : size of input a
 * @parameter resultSize : the array to be filled with modes
 */
int * getAllModes(const int *a, int n, int *resultSize);

/*
 * returns an array of <all values greater than threshold> from array a
 * returned values are in the same order as as they are in input array
 *
 * @parameter a : input array
 * @parameter n : size of input a
 * @parameter resultSize : the array to be filled with modes
 */
//int * filter(const int *a, int n, int threshold, int *resultSize);

/*
 * returns an array containing the elements of a, then the elements of b
 */
int * append(const int *a, int sizeA, int *b, int sizeB);
