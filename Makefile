MAKEFILES := $(shell find ./solutions -type f -name Makefile)
L_PYTHON3 := python3
include $(MAKEFILES)

all: two-sum add-two-numbers longest-substring-without-repeating-characters
