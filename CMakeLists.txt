project(WebView2Cpp)

include_directories(include)
add_executable(${PROJECT_NAME} WIN32 HelloWebView.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Version ${PROJECT_SOURCE_DIR}/lib/WebView2LoaderStatic.lib)