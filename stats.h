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
 * @file stats.h 
 * @brief contains declarations for the functions in stats.c
 *
 * <Add Extended Description Here>
 *
 * @author Michael Asfaw
 * @date Feb 11, 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char *arr, int len);
/**
 * @brief Prints the Calculated Statistics of the Array
 *
 * Takes the return from the other functions and prints them
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return prints the values, returns NULL
 */
void print_array(unsigned char *arr, int len);
/**
 * @brief Prints the Array input into the function
 *
 * Prints the array for display purposes (formatted)
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return prints the values, returns NULL
 */
float find_median(unsigned char *arr, int len);
/**
 * @brief Calculates and returns the median value
 *
 * Median Value Calculator for an array
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return median value
 */
float find_mean(unsigned char *arr, int len);
/**
 * @brief Calculates and returns the mean value
 *
 * Mean Value Calculator for an array
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return mean value
 */
int find_maximum(unsigned char *arr, int len);
/**
 * @brief Calculates and returns the maximum value
 *
 * Maximum Value Calculator for an array
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return max value
 */
int find_minimum(unsigned char *arr, int len);
/**
 * @brief Calculates and returns the minimum value
 *
 * Minimum Value Calculator for an array
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return min value
 */
unsigned char * sort_array(unsigned char *arr, int len);
/**
 * @brief Sorts the array and returns a sorted Array
 *
 * Sorts the Array and returns a new sorted array
 *
 * @param arr Input Array to the Function
 * @param len Length of the Array
 * @return sortArr Sorted Array
 */




#endif /* __STATS_H__ */
