#
# Find the Wiiuse includes and library
#
# About wiiuse is https://github.com/rpavlik/wiiuse.
#
# This module defines
# Wiiuse_INCLUDE_DIR, where to find wiiuse.h, etc.
# Wiiuse_LIBRARIES, the libraries to link against to use Wiiuse.
# Wiiuse_LIBRARY, where to find the Wiiuse library(release build).
# Wiiuse_FOUND, If false, do not try to use Wiiuse.
#
# Wiiuse_DEBUG_LIBRARY, where to find the Wiiuse library(debug build.)


find_path(Wiiuse_INCLUDE_DIR
        NAMES wiiuse/wiiuse.h
        HINTS /usr/include /usr/local/include
)

if(WIN32)
    find_library(Wiiuse_LIBRARY wiiuse
        ${Wiiuse_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib
    )
    find_library(Wiiuse_DEBUG_LIBRARY wiiuse_debug
        ${Wiiuse_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib    
    )    
else(WIN32)
    find_library(Wiiuse_LIBRARY wiiuse
        ${Wiiuse_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib
    )
    find_library(Wiiuse_DEBUG_LIBRARY wiiuse
        ${Wiiuse_INCLUDE_DIR}/../lib
        /usr/local/lib
        /usr/lib    
    )    
endif(WIN32)

if(Wiiuse_INCLUDE_DIR AND Wiiuse_LIBRARY)
    set(Wiiuse_FOUND "YES")
    set(Wiiuse_LIBRARIES ${Wiiuse_LIBRARY} ${CMAKE_DL_LIBS})
    set(Wiiuse_DEBUG_LIBRARIES ${Wiiuse_DEBUG_LIBRARY} ${CMAKE_DL_LIBS})
endif()