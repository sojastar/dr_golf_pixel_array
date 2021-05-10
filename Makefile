OS := $(shell uname)

CEXT_NAME=golf_pixel_array
CEXT_EXTENSION=.h
CEXT_PATH=lib/
CEXT_FILES=golf_pixel_array.c
CEXT_SRC=$(addprefix $(CEXT_PATH),$(CEXT_FILES))
BINDER=../dragonruby-bind
BINDER_FFI_MODULE=GolfPixelArray
BINDER_CFLAGS='-I /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include -I../include -I.'
BINDER_OUTPUT_EXTENSION=-bindings.c
CC=clang
CFLAGS=-shared -isystem include -lc -I../include -I. -fPIC
PRODUCTION_FLAGS=-O2
DEBUG_FLAGS=-g -O0
ifeq ($(OS),Darwin)
	DYLIB_PATH=native/macos/
	DYLIB_EXTENSION=.dylib
else
	DYLIB_PATH=native/linux-amd64/
	DYLIB_EXTENSION=.so
endif
DYLIB_DSYM=.dSYM

golf_pixel_array:
	$(BINDER) --compiler-flags=$(BINDER_CFLAGS) --ffi-module=$(BINDER_FFI_MODULE) --output=$(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION) $(CEXT_PATH)$(CEXT_NAME)$(CEXT_EXTENSION)
	$(CC) $(PRODUCTION_FLAGS) $(CFLAGS) -o $(DYLIB_PATH)$(CEXT_NAME)$(DYLIB_EXTENSION) $(CEXT_SRC) $(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION)

clean:
	rm -f $(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION) $(DYLIB_PATH)$(CEXT_NAME)$(DYLIB_EXTENSION)
	rm -rf $(DYLIB_PATH)$(CEXT_NAME)$(DYLIB_EXTENSION)$(DYLIB_DSYM)
