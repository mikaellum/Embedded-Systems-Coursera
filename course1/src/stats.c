/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Code for binary that manipulates an array
 *
 * This file contains definitions for functions and code 
 * that is used to print in the input array, calculate stats
 * including minimum, maximum, mean, median and sorts, returns and prints
 * the output array
 * 
 * @author Michael Asfaw
 * @date Feb 11, 2025
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Define the print_statistics funcion */
void print_statistics(unsigned char *arr, int len) {
  // print the mean
  printf("The mean of the array is: %u\n", find_mean(arr, len));
  printf("The median of the array is: %u\n", find_median(arr, len));
  printf("The maximum of the array is: %u\n", find_maximum(arr, len));
  printf("The minimum of the array is: %u\n", find_minimum(arr, len));

}

/* Define the print_array funcion */
void print_array(unsigned char *arr, int len) {
#ifdef VERBOSE
  for (int i =0; i < len; i++){
    PRINTF("Array elements are: %u ", arr[i]);
  }
  PRINTF("\n");
#endif
  return;
}

/* Define the find_median funcion */
unsigned char find_median(unsigned char *arr, int len) {
  // First Sort the Array
  unsigned char * sortArr = sort_array(arr, SIZE);
  // Calculate the median
  if (len % 2 == 0){
    // for even length arrays
    unsigned char median = (arr[len / 2 -1] + arr[len / 2]) / 2;
    return median;
  } else {
    // for odd length arrays
    unsigned char median = (arr[len / 2]);
    return median;
  }
  
}

/* Define the find_mean funcion */
unsigned char find_mean(unsigned char *arr, int len) {
	// Put in logic for len == 0
	if (len ==0) {
		return 0;
	}
  // Initialize a sum
  unsigned char sum = 0;
  for (int i = 0; i < len; i++){
    sum += arr[i];
  }
  // Calculate the mean
  return (unsigned char)(sum / len);
}

/* Define the find_maximum funcion */
unsigned char find_maximum(unsigned char *arr, int len) {
  unsigned char max = arr[0];
  for (int i = 1; i < len; i++){
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

/* Define the find_minimum funcion */
unsigned char find_minimum(unsigned char *arr, int len) {
  unsigned char min = arr[0];
  for (int i = 1; i < len; i++){
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

/* Define the sort_array funcion */
unsigned char * sort_array(unsigned char *arr, int len) {
  for (int i = 0; i < len - 1; i++){
    for (int j = 0; j < len - i - 1; j++){
      if (arr[j] < arr[j + 1]){
        // Swap arr[j] and arr[j+1] and impelement
        unsigned char temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Print the Outputs */
  print_array(test, SIZE);
  print_statistics(test, SIZE);

}
