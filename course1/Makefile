#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      	WSL Ubuntu
#		MSP432 Dev Board
#
# Platform Overrides:
#      	Defaults for PLATFOM = HOST
#
#------------------------------------------------------------------------------
include sources.mk

# Flags
FLAGS =	-Wall \
		-Werror \
		-g \
		-O0 \
		-std=c99 \

# MSP432 Specfic Flags
MSP432_FLAGS =	-mcpu=$(CPU) \
		-mthumb \
		-march=$(ARCH) \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16 \
		--specs=nosys.specs \


# Target
TARGET = final_assessment
# Platform Overrides
PLATFORM = HOST

# Switches
VERBOSE = false
COURSE1 = false


# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
# Architectures Specific Flags
	CC = gcc
	CFLAGS = $(FLAGS)
	CPPFLAGs = -DHOST
	SIZE = size

else ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
	CC = arm-none-eabi-gcc
	CPU = cortex-m4
	ARCH = armv7e-m
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(FLAGS) \
				$(MSP432_FLAGS)
	CPPFLAGs = -DMSP432

endif

# Add flag for COURSE1
ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif

# Add flag for VERBOSE
ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

# Define Parameters
OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all build clean

# Complile all object files and link into a final executable
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGs) $(LDFLAGS) -o $@
	$(SIZE) $@

# Preprocessed output of all c-program implementation files (-E flag)
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGs) -o $@

# Generate the asssembly files using -S flag
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGs) -o $@


# Generate the object files using -S flag
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGs) -o $@

# Generate dependency files for each source file
%.d: %.c
	$(CC) -E -M $< $(CFLAGS) $(CPPFLAGs) -o $@

# Compile all objects without linking
compile-all: $(OBJS)

# Remove all compiled objects, build files, assembly and executable filees
clean:
	rm -f *.i *.map *.o *.asm *.i
