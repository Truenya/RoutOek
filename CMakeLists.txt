cmake_minimum_required(VERSION 3.9)
project(ReadOekRoute)
# Optional: Defaults to C++ 17
set(CSV_CXX_STANDARD 17)
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_C_COMPILER "/usr/bin/clang")
add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fPIC"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
add_subdirectory(csv-parser)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++17> $<$<COMPILE_LANGUAGE:C>:-std=c99>)

# ...

add_library(ReadOekRoute SHARED ReadOekRoute.cpp ReadOekRoute.h RouteIncludes.h)
target_link_libraries(ReadOekRoute csv pthread )


install(FILES ReadOekRoute.h RouteIncludes.h
        DESTINATION /usr/include/
        )
install(FILES libReadOekRoute.so csv-parser/include/internal/libcsv.so
        DESTINATION /usr/lib/
        )
