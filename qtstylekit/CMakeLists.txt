cmake_minimum_required(VERSION 3.16)

project(qtstylekit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Designer)

set(PROJECT_SOURCES
        inc/button.h
        src/button.cpp
        inc/button_p.h
        common/common.h
)

# ===================== Qt 6 / Qt 5 共享库 =====================
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    # Qt 6 下生成动态库
    find_package(Qt6 REQUIRED COMPONENTS Core)

    add_library(qtstylekit SHARED
        ${PROJECT_SOURCES}
        plugins/qskwidgetscollection.h plugins/qskwidgetscollection.cpp
    )
else()
    if(ANDROID)
        add_library(qtstylekit SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_library(qtstylekit SHARED
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# ===================== 链接 Qt 库 =====================
target_link_libraries(qtstylekit
    PUBLIC Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core
)
target_link_libraries(qtstylekit PRIVATE Qt6::Core)

target_compile_definitions(qtstylekit
    PRIVATE QSK_LIBRARY_BUILD
)

target_include_directories(qtstylekit
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

# ===================== 安装 =====================
include(GNUInstallDirs)
install(TARGETS qtstylekit
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ===================== Qt 6 finalize =====================
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qtstylekit)  # qt_finalize_executable 也可用于库
endif()
