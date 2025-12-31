CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = gradeapp

SRCS = main.cpp GradeManager.cpp Persistence.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)