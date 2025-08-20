# CMake file to simplify build process
# Created by Karol Zmijewski, karol.zmijewski@gmail.com.
# Released into the public domain.

# - general settings
cmake_minimum_required(VERSION 3.10)
project(cpyth)

# - compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# - source files
file(GLOB SOURCES "src/*.cpp")
add_library(cpyth_mod SHARED ${SOURCES})

# - build rules
# -- resolve external dependencies
message(STATUS "[STEP 1/3] Trying to resolve external dependencies...")
find_package(Python3 QUIET COMPONENTS Development)

if(Python3_FOUND)
    message(STATUS "[OK] Python3: components were found successfully, trying to find Python3 shared library...")
    # by default CMake prefers static libs over the shared libraries,
    # that is why Python3_LIBRARIES variable will hold path to static lib
    # and we have to find shared object on our own.
    find_library(Python3_SHARED_LIBRARY python3)
    if (Python3_SHARED_LIBRARY)
        message(STATUS "[OK] Python3: shared library was found successfully at: ${Python3_SHARED_LIBRARY}")
        set(PYTHON_LIB ${Python3_SHARED_LIBRARY})
    else()
        message(FATAL_ERROR "[FAIL] Python3: shared library cannot be found! It is mandatory Dependecy, cannot proceed with build process, terminating...")
    endif()
    if(Python3_INCLUDE_DIRS)
        message(STATUS "[OK] Python3: include directory was found successfully at: ${Python3_INCLUDE_DIRS}")
        set(PYTHON_INCLUDE ${Python3_INCLUDE_DIRS})
    else()
        message(FATAL_ERROR "[FAIL] Python3: include directory cannot be found! It contains mandatory header file, cannot proceed with build process, terminating...")
    endif()
else()
    message(WARNING "[WARN] Python3: components were not found, try to use default path")
    set(PYTHON_INCLUDE "/usr/include/python3.11")    
    message(STATUS "[OK] Python3: shared library was set to default path: ${PYTHON_INCLUDE}")
    set(PYTHON_LIB "/usr/lib/x86_64-linux-gnu/libpython3.11.so")
    message(STATUS "[OK] Python3: include directory was set to default path: ${PYTHON_LIB}")
endif()

# -- include external headers
message(STATUS "[STEP 2/3] Trying to include external headers...")
if(PYTHON_INCLUDE)
    target_include_directories(cpyth_mod PRIVATE ${PYTHON_INCLUDE})
    message(STATUS "[OK] Python3: included - ${PYTHON_INCLUDE}")
else()
    message(FATAL_ERROR "[FAIL]: Python3 include directory: ${PYTHON_INCLUDE} does not exists, cannot proceed with build process, terminating...")
endif()

# -- link external libraries
message(STATUS "[STEP 3/3] Trying to link external libraries...")
if(PYTHON_LIB)
    target_link_libraries(cpyth_mod PRIVATE ${PYTHON_LIB})
    message(STATUS "[OK] Python3: linked - ${PYTHON_LIB}")
else()
    message(FATAL_ERROR  "[FAIL] Python3 library directory: ${PYTHON_LIB} does not exists, cannot proceed with build process, terminating...")
endif()

set_target_properties(cpyth_mod PROPERTIES PREFIX "" SUFFIX ".so")
set_target_properties(cpyth_mod PROPERTIES POSITION_INDEPENDENT_CODE ON)
message(STATUS "Makefile generated sucessfully, call make command to build the project")
