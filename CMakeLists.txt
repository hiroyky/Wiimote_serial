cmake_minimum_required(VERSION 2.6)
project(wiimote_serial)

# find_packageのパス追加
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules)

# 依存ライブラリ、ヘッダファイルの設定
## Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
if(NOT DEFINED BOOST_ROOT)
    set(BOOST_ROOT /usr/include)
endif()
find_package(Boost COMPONENTS system program_options thread regex serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

## Wiiuse
find_package(Wiiuse REQUIRED)
include_directories(${Wiiuse_INCLUDE_DIR})

add_subdirectory(src)

