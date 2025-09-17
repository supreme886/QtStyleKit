cmake_minimum_required(VERSION 3.16)

project(QtStyleKit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 设置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)  # 或 Qt5

# 添加子目录
add_subdirectory(examples)
add_subdirectory(qtstylekit)
