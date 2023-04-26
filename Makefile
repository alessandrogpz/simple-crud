CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -L/usr/lib/x86_64-linux-gnu
LDLIBS = -lssl -lcrypto

SRCDIR = source
OBJDIR = obj
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET = $(BINDIR)/build

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDLIBS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
