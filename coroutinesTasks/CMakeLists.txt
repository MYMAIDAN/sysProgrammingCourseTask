cmake_minimum_required ( VERSION 3.2 FATAL_ERROR )
 
project( coroutineLibrary )

set( CMAKE_CXX_STANDART 17 )
set( CMAKE_CXX_STANDART_REQUIRED ON )

add_executable( coro Scheduler.cpp CoroTask.h CoroTask.cpp CoroFunction.h main.cpp)
