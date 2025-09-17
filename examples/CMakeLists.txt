cmake_minimum_required(VERSION 3.19)
project(example LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(example
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(example
    PRIVATE
        Qt::Core
        Qt::Widgets
        qtstylekit
)

target_include_directories(example
    PRIVATE
        ${CMAKE_SOURCE_DIR}/qtstylekit/include/
)

include(GNUInstallDirs)

install(TARGETS example
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET example
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
