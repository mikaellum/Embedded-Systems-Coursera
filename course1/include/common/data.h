/********************************************************************************
 * Copyright (C) 2025 by Michael Asfaw
 *
 *******************************************************************************/

#ifdef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts Integer to ASCII
 *
 * 
 *
 * @param data Signed 32 bit integer
 * @param ptr Pointer to the output string
 * @param base Base of the integer 2(binary) to 16(hex)
 *
 * @return uint8_t
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Converts ASCII to Integer
 *
 * 
 *
 * @param ptr Pointer to the output string
 * @param digits Number of digits in the character
 * @param base Base of the integer 2(binary) to 16(hex)
 *
 * @return int32_t 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
