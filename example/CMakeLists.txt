include_directories("../solver/include/")
add_executable (example main.cpp)
target_link_libraries (example LINK_PUBLIC solver)