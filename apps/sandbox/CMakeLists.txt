# ~/Dev/ReplicaEngine/apps/sandbox/CMakeLists.txt
add_executable(app_sandbox
    main.cpp
)

# Link against the engine lib we just defined one folder up
target_link_libraries(app_sandbox
    PRIVATE engine
)
set_target_properties(app_sandbox PROPERTIES CXX_STANDARD 23)

