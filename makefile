.PHONY: all clean
MKDIR = mkdir
RM = rm
RMFLAGS = -rf

CC = g++
GDBFLAGS = -g3
STDC11 = -std=c11

DIR_OBJS = objs
DIR_EXES = exes
DIR_DEPS = deps
DIRS = $(DIR_OBJS) $(DIR_EXES) $(DIR_DEPS)

EXE = test1.exe
EXE := $(addprefix $(DIR_EXES)/, $(EXE))

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))
DEPS = $(SRCS:.cpp=.dep)
DEPS := $(addprefix $(DIR_DEPS)/, $(DEPS))

all: $(EXE)


ifeq ("$(wildcard $(DIR_DEPS))","")
DEPS_DIR_DEPS := $(DIR_DEPS)
endif

ifneq ($(MAKECMDGOALS), clean)
include $(DEPS)
endif

$(DIRS):
	$(MKDIR) $@
$(EXE): $(DIR_EXES) $(OBJS)
	$(CC) $(GDBFLAGS) -o $@ $(filter %.o, $^)
$(DIR_OBJS)/%.o: $(DIR_OBJS) %.cpp
	$(CC) $(GDBFLAGS) -o $@ -c $(filter %.cpp, $^)
$(DIR_DEPS)/%.dep: $(DEPS_DIR_DEPS) %.cpp
	@echo "Making $@ ..."
	@set -e; \
	$(RM) $(RMFLAGS) $@.tmp ; \
	$(CC) $(GDBFLAGS) -E -MM $(filter %.cpp, $^) > $@.tmp ; \
	sed 's,\(.*\)\.o[ :]*,objs/\1.o $@: ,g' < $@.tmp > $@ ; \
	$(RM) $(RMFLAGS) $@.tmp
clean:
	$(RM) $(RMFLAGS) $(DIRS)
