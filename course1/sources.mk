#******************************************************************************
# Copyright (C) 2025 Michael Asfaw
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************


# Initial Source Files and Includes
SOURCES =	./src/main.c \
		./src/memory.c \

INCLUDES =	-I ./include/common \

ifeq ($(PLATFORM), HOST)
# Add your include paths to this variable
	INCLUDES +=	-I ./include/CMSIS \
				

else ifeq ($(PLATFORM), MSP432)
# Add your Source files to this variable
	SOURCES += 	./src/interrupts_msp432p401r_gcc.c \
			./src/startup_msp_432p401r_gcc.c \
			./src/system_msp432p401r.c \

# Add your include paths to this variable
	INCLUDES +=	-I ./include/msp432 \	

endif



