CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -L/usr/lib/x86_64-linux-gnu
LDLIBS = -lssl -lcrypto -lsqlite3 -lboost_unit_test_framework

SRCDIR = source
OBJDIR = obj
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET = $(BINDIR)/build

TESTDIR = tests
TESTSRCS = $(wildcard $(TESTDIR)/*.cpp)
TESTOBJS = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTSRCS))
TESTMAINOBJ = $(OBJDIR)/test_main.o
TESTTARGET = $(BINDIR)/test_executable

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDLIBS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TESTTARGET): $(filter-out $(OBJDIR)/main.o, $(OBJS)) $(TESTOBJS) $(TESTMAINOBJ)
	$(CXX) $(filter-out $(OBJDIR)/main.o, $(OBJS)) $(TESTMAINOBJ) $(LDLIBS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TESTMAINOBJ): $(TESTDIR)/test_main.cpp
	$(CXX) $(CXXFLAGS) -DBOOST_TEST_DYN_LINK -c $< -o $@

test: $(TESTTARGET)
	$(TESTTARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TESTOBJS) $(TESTMAINOBJ) $(TESTTARGET)

.PHONY: all test clean
