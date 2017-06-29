
#########################
# Configuration options #
#########################

# Build options: debug, release
BUILD_TYPE=debug

#####################
# Build Information #
#####################

TARGET=platformer

OBJDIR=obj

OBJS:=$(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

CXXFLAGS=-std=c++11
LDFLAGS=-LE:/SFML/lib
LIBS=sfml-graphics-s-d sfml-system-s-d sfml-window-s-d opengl32 freetype jpeg winmm gdi32
PREFIX=/usr/local
#######################
# Build Specific Data #
#######################

# Build type

ifeq ($(BUILD_TYPE), debut)
	CFLAGS+=-DDEBUG -O0 -g
endif
ifeq ($(BUILD_TYPE), release)
# when compiling for release, add the -O2 flag for optimizations.
	CFLAGS+=-O2
endif

#################
# Build Section #
#################

.PHONY: all mkdir doc doc-devel install uninstall clean

all: mkdir bin/$(TARGET)

bin/$(TARGET): $(addprefix , $(OBJS))
	@echo -ne " $(addsuffix \n, $(addprefix +, $^) $(addprefix +, $(LIBS)))"
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(addprefix -l, $(LIBS))
	@echo " =$@"

obj/%.o: src/%.cpp
	@echo -n "$^ -> "
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo "$@"

mkdir:
	@mkdir -p bin obj

doc:
	@mkdir -p doc
	@doxygen

doc-devel:
	@mkdir -p doc/devel
	@(cat Doxyfile; echo OUTPUT_DIRECTORY=doc/devel; echo EXTRACT_PRIVATE=YES) | doxygen -

install:
	install -Dm755 bin/$(TARGET) $(PREFIX)/bin/$(TARGET)

uninstall:
	rm $(PREFIX)/bin/$(TARGET)

clean:
	if [ -d obj ]; then rm -r obj; fi
	if [ -d bin ]; then rm -r bin; fi
	if [ -d doc ]; then rm -r doc; fi
