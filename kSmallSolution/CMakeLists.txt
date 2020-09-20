cmake_minimum_required(VERSION 3.5)

project(kSmallSolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(kSmallSolution main.cpp arrayTracker.cpp arrayTracker.h ksmallRuleChecker.cpp ksmallRuleChecker.h ksmallSolution.cpp ksmallSolution.h ksmallTester.cpp ksmallTester.h)
