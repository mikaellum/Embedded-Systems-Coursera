/******************************************************************************
 * Copyright (C) 2025 by Michael Asfaw
 *****************************************************************************/
/**
 * @file data.c
 * @brief Conversion from ASCII to Integer and Backwards defined here
 *
 * This implementation file provives the abstraction for converting from ASCII
 * to Integer and From Integer to ASCII
 *
 * @author Michael Asfaw
 * @date February 16 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/common/data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	// Check if the Pointer to memory is NULL
	if (ptr == NULL){
		return NULL;
	}
	// Logic to check that the base is within limits
	if (base < 2 || base > 16){
		// A base of <2 or >16 is unsupported
		printf("ERROR: the base is unsupported");
		return NULL;
	}
	// Determine if the number is negative
	uint8_t isNegative = 0;
	if(data < 0){
		isNegative = 1;
		data = -data;
	}
	// Calculate max digits needed
	uint8_t numDigits = 0;
	uint8_t temp = data;
	do {
		temp /= base;
		numDigits++;
	} while(temp > 0);

	// Add space for sign and null terminator
	uint8_t ptrSize = numDigits + 1 + (isNegative);

	uint8_t * current = ptr + ptrSize - 1;
	*current = '\0';

	do {
		uint8_t digit = data % base;
		data /= base;
		if (digit < 10){
			*(--current) = digit + '0';
		} else {
			*(--current) = digit - 10 + 'A';
		}
	} while (data > 0);

	if (isNegative) {
		*(--current) = '-';
	}

	return current;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	// Check if the pointer to memory is NULL
	if (ptr == NULL){
		return NULL;
	}
	// Logic to check that the base is within limits
	if (base < 2 || base > 16){
		printf("ERROR: the base is unsupported");
		return NULL;
	}
	// Logic if digits is 0
	if (digits == 0){
		return 0;
	}
	// Determine if the number is negative
	uint8_t isNegative = 0;
	if (*ptr == '-'){
		isNegative = 1;
		digits--;
		ptr++;
	}
	// Conversion to int32_t
	int32_t val = 0; // Initialize return val to 0
	do {
		uint8_t digit;
		if (*ptr >= '0' && *ptr <= '9'){
			digit = *ptr - '0';
		} else if (*ptr >= 'A' && *ptr <= 'Z'){
			digit = *ptr - 'A' + 10;
		} else if (*ptr >= 'a' && *ptr <= 'z') {
			digit = *ptr - 'a' + 10;
		} else {
			break;
		}
		if (digit >= base) {
			break;
		}

		val = val * base + digit;
		*ptr++;
		digits--;

	} while(*ptr && digits > 0);

	if (isNegative){
		val = -val;
	}

	return val;
}
