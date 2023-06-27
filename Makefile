CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

SRCDIR = src
BINDIR = .

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
EXECUTABLE = file_transfer.exe

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	del $(EXECUTABLE)
