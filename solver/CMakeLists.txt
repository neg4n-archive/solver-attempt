add_library (solver 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/token.cpp
)

set(CMAKE_CXX_STANDARD 20)

target_include_directories (solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(solver PRIVATE cxx_std_20)
