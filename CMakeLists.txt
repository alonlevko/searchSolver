cmake_minimum_required(VERSION 3.12)
project(searchSolver)

set(CMAKE_CXX_STANDARD 14)

add_executable(searchSolver main.cpp socket.h Server.h mySerialServer.cpp mySerialServer.h ClientHandler.h myTestClientHandler.cpp myTestClientHandler.h Solver.h CacheManager.h problem.h solution.h FileCacheManager.cpp FileCacheManager.h)