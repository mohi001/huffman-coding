cmake_minimum_required(VERSION 3.0.0)
project(final_prj VERSION 0.1.0)


add_executable(final_prj main.cpp binary_huffman.cpp ternay_huffman.cpp)
target_precompile_headers(final_prj PUBLIC pch.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
