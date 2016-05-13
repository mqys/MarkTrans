project(MarkTrans)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Scanner.cpp Scanner.h Document.cpp Document.h Types.h Elements.h Types.cpp Elements.cpp)

add_executable(MarkTrans ${SOURCE_FILES})