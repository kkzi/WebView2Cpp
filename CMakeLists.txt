project(WebView2Cpp)

set(CMAKE_CXX_STANDARD 20)
include_directories(include $ENV{SIMPLE_CPP})
add_executable(${PROJECT_NAME} WIN32 HelloWebView.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Version ${PROJECT_SOURCE_DIR}/lib/WebView2LoaderStatic.lib)