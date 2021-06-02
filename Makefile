CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/BFS.o ./obj/main.o ./obj/DFS.o ./obj/Appearance.o ./obj/make_maze.o ./obj/bidirectional_bfs.o
TARGET = main
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/make_maze.o: ./cpp/make_maze.cpp
	$(CXX) $(CXXFLAGS) ./cpp/make_maze.cpp -o ./obj/make_maze.o
./obj/Appearance.o: ./cpp/Appearance.cpp
	$(CXX) $(CXXFLAGS) ./cpp/Appearance.cpp -o ./obj/Appearance.o
./obj/BFS.o: ./cpp/BFS.cpp
	$(CXX) $(CXXFLAGS) ./cpp/BFS.cpp -o ./obj/BFS.o
./obj/DFS.o: ./cpp/DFS.cpp
	$(CXX) $(CXXFLAGS) ./cpp/DFS.cpp -o ./obj/DFS.o
./obj/bidirectional_bfs.o: ./cpp/bidirectional_bfs.cpp
	$(CXX) $(CXXFLAGS) ./cpp/bidirectional_bfs.cpp -o ./obj/bidirectional_bfs.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)