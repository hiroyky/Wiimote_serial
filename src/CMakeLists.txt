cmake_minimum_required(VERSION 2.6)

file(GLOB_RECURSE SRC_FILES
    "*.h"
    "*.c"
    "*.hpp"
    "*.cpp"
)

set(APP_NAME wiimote_serial)

add_executable(${APP_NAME} ${SRC_FILES})
add_definitions(-std=c++0x)

target_link_libraries(${APP_NAME} ${Boost_LIBRARIES})
target_link_libraries(${APP_NAME} optimized ${Wiiuse_LIBRARIES} debug ${Wiiuse_DEBUG_LIBRARIES})
