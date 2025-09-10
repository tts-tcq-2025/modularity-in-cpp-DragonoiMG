# Makefile for Telecommunication Color Coder

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinc
SRCDIR = src
INCDIR = inc
TESTDIR = tests
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(SRCDIR)/ColorDefinitions.cpp $(SRCDIR)/ColorPair.cpp $(SRCDIR)/ColorCoder.cpp $(SRCDIR)/ReferenceManual.cpp
MAIN_SRC = $(SRCDIR)/main.cpp
TEST_SOURCES = $(TESTDIR)/ColorPairTests.cpp $(TESTDIR)/ReferenceManualTests.cpp $(TESTDIR)/TestRunner.cpp

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
MAIN_OBJ = $(OBJDIR)/main.o
TEST_OBJECTS = $(TEST_SOURCES:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

# Targets
TARGET = $(BINDIR)/color_coder
TEST_TARGET = $(BINDIR)/test_runner

.PHONY: all clean test directories

all: directories $(TARGET)

test: directories $(TEST_TARGET)
	./$(TEST_TARGET)

directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

$(TARGET): $(OBJECTS) $(MAIN_OBJ)
	$(CXX) $(OBJECTS) $(MAIN_OBJ) -o $@

$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(OBJECTS) $(TEST_OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: $(TARGET)
	./$(TARGET)

.SECONDARY: $(OBJECTS) $(MAIN_OBJ) $(TEST_OBJECTS)
