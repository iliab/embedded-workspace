# Example Hello World Makefile for both PC (simulation) and ARM platforms
#

#------------- Configuration -------------------
VERSION = 054 #Format as accepted in the project
BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
TAG := $(shell git describe --tags | sed 's/-.*//')
#VERSION =$(shell git describe --tags | sed 's/-.*//' | sed 's/\.// g')

ROOT := $(shell pwd)/
BUILD_ROOT := $(ROOT)build
REPO_ROOT := $(shell git rev-parse --show-toplevel)/
COMMON_INC := $(REPO_ROOT)common/
LIB_INC := $(COMMON_INC)lib/
COMMON_SRC := $(REPO_ROOT)common/lib/

ifeq "$(ARCH)" "arm" #32bit arm arch
CROSS_TOOLS_PATH = 
CROSS_TOOLS_PREFIX = arm-linux-gnueabihf-
ARCH = arm
ARCH_FLAG=ARM
else 	#x86-64 arch (default)
CROSS_TOOLS_PATH = 
CROSS_TOOLS_PREFIX = 
ARCH = x86
ARCH_FLAG=X86
endif

# Tools 
CC = $(CROSS_TOOLS_PATH)$(CROSS_TOOLS_PREFIX)gcc
AR = $(CROSS_TOOLS_PATH)$(CROSS_TOOLS_PREFIX)ar
STRIP = $(CROSS_TOOLS_PATH)$(CROSS_TOOLS_PREFIX)strip
LINT = cppcheck
#LINT = splint

# Where to build the artifacts 
CURR_BUILD_DIR = $(BUILD_ROOT)/$(ARCH)

#Generate the needed directories under the CURR_BUILD_DIR
ifeq "$(wildcard $(CURR_BUILD_DIR))" ""
$(shell mkdir -p $(CURR_BUILD_DIR))
endif

#Main target
EXEC = hello

DBG_FLAGS := -O0 -g -D_DEBUG -ffunction-sections -fdata-sections
GCC_FLAGS := -std=gnu99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -fno-common -fstack-usage -Wconversion -Wstrict-overflow -Wstrict-aliasing #-Werror Until the "Fixed reporting" will be fixed
IDIR := -I./
CFLAGS :=$(DBG_FLAGS) -D$(ARCH_FLAG) $(GCC_FLAGS) $(IDIR)
LIBS_PATH := 

LINTFLAGS = --cppcheck-build-dir=$(CURR_BUILD_DIR) -D$(ARCH_FLAG) $(IDIR) 

#Objects to build
APP_OBJS = hello.o
APP_OBJS_PATH := $(patsubst %,$(CURR_BUILD_DIR)/%,$(APP_OBJS))

#Libs ToDo: insert the project libs BEFORE the system ones
LIBS = -lpthread -lm

.PHONY: all clean
all: $(CURR_BUILD_DIR)/$(EXEC)

$(CURR_BUILD_DIR)/$(EXEC): $(CURR_BUILD_DIR)/$(EXEC).elf Makefile
	$(STRIP) $(CURR_BUILD_DIR)/$(EXEC).elf -o $(CURR_BUILD_DIR)/$(EXEC)

$(CURR_BUILD_DIR)/$(EXEC).elf: $(APP_OBJS_PATH) Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(APP_OBJS_PATH) $(LDLIBS$(LDLIBS_$@)) $(LIBS_PATH) $(LIBS)

$(CURR_BUILD_DIR)/%.o: %.c Makefile
	$(LINT) $(LINTFLAGS) $<
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(CURR_BUILD_DIR)/*
