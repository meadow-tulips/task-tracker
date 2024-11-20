cmake_minimum_required(VERSION 3.9.1)

project(TaskRunnerCLI VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(task-cli src/main.cpp src/taskReader.cpp src/task.cpp)