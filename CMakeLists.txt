cmake_minimum_required(VERSION 2.6)

# Note: the 'C' seems necessary for CMake 3.2.2 but might not be necessary with
# later versions of CMake.
project(Template C CXX)

# Only from gcc 4.9 and cland 3.5 are the options -std=c++11 and -std=c++14 available.
# See:
#   https://gcc.gnu.org/projects/cxx-status.html
#   http://clang.llvm.org/cxx_status.html
# Since CMAKE_CXX_COMPILER_VERSION is only available from CMake 2.8.10 on, we currently comment
# this check out.
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
#        message(FATAL_ERROR "GCC version must be at least 4.9!")
#    endif()
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
#        message(FATAL_ERROR "Clang version must be at least 3.5!")
#    endif()
#else()
#    message(WARNING "You are using an unsupported compiler!  Compilation has only been tested with Clang and GCC.")
#endif()

set(CMAKE_CXX_FLAGS "-std=c++2a")

find_package(Threads REQUIRED)

add_subdirectory(basics)
add_subdirectory(bridge)
add_subdirectory(debugging)
add_subdirectory(deduce)
add_subdirectory(details)
add_subdirectory(exprtmpl)
add_subdirectory(inherit)
add_subdirectory(meta)
add_subdirectory(names)
add_subdirectory(overload)
add_subdirectory(poly)
add_subdirectory(traits)
add_subdirectory(tuples)
add_subdirectory(typeoverload)
add_subdirectory(utils)
add_subdirectory(variant)

