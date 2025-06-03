# ~/Dev/ReplicaEngine/engine/CMakeLists.txt
add_library(engine STATIC
	core/Log.cpp core/Log.hpp
    core/config.hpp
)


# Public headers are visible to anything that links against “engine”
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link third-party libs we’ll use immediately
find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(engine
    PUBLIC
        spdlog::spdlog_header_only
        fmt::fmt
        glfw
        OpenGL::GL
)

if (USE_VSYNC_ENABLED)
    target_compile_definitions(engine PUBLIC USE_VSYNC=1)
endif()

set_target_properties(engine PROPERTIES CXX_STANDARD 23)


