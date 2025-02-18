/******************************************************************************
 * Copyright (C) 2017 by Michael Asfaw
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main File for Final Assessment
 *
 * This file contains the main code for the Final Assessment
 *
 * @author Michael Asfaw
 * @date Feb 15, 2025
 *
 */
#include <stdio.h>

#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];

/* A pretty boring main file */
int main() {
	// Course deliverable
#ifdef COURSE1
	course1();
#endif
  return 0;
}
