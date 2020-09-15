include_directories("../solver/include/")
add_executable (example main.cpp)
target_link_libraries (example LINK_PUBLIC solver)
target_compile_features(example PRIVATE cxx_std_17)