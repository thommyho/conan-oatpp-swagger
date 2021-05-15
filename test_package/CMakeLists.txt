cmake_minimum_required(VERSION 3.1)
project(test_package)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS) # Silenceing warning for std::getenv
add_executable(${PROJECT_NAME} tests.cpp AsyncControllerTest.cpp ControllerTest.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::oatpp-swagger)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
