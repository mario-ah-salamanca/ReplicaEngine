cmake_minimum_required(VERSION 3.29)
project(ENIGMA_ENGINE LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)


# Read external config
set(CONFIG_FILE "${CMAKE_SOURCE_DIR}/config.txt")
if(NOT EXIST "$(CONFIG_FILE}")
    message(FATAL_ERROR "config.txt not found at project root")
endif()

file(READ "${CONFIG_FILE}" CONFIG_CONTENT)

# Detect vsync:true
string(FIND "${CONFIG_CONTENT}" "vsync:true" VSYNC_FOUND)
if (NOT VSYNC_FOUND EQUAL -1)
    message(STATUS "Config: VSync enabled")
    set(USE_VSYNC_ENABLED TRUE)
else()
    message(STATUS "Config: VSync disabled")
    set(USE_VSYNC_ENABLED FALSE)
endif()

# Make value accessible to subdirectories
set(USE_VSYNC_ENABLED ${USE_VSYNC_ENABLED} CACHE INTERNAL "Use vsync from config.txt")

add_subdirectory(engine)
add_subdirectory(apps/sandbox)

