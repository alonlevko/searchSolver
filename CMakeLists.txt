cmake_minimum_required(VERSION 3.12)
project(searchSolver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(searchSolver main.cpp mySocket.h Server.h mySerialServer.cpp mySerialServer.h ClientHandler.h myTestClientHandler.cpp myTestClientHandler.h Solver.h CacheManager.h problem.h solution.h FileCacheManager.cpp FileCacheManager.h StringReverser.h state.cpp state.h path.cpp path.h searchable.h graph.cpp graph.h searcher.h searchSolver.h searchSolver.cpp myClientHandler.cpp myClientHandler.h BestFirstSearch.cpp BestFirstSearch.h DFS.cpp DFS.h BFS.cpp BFS.h aStar.cpp aStar.h)