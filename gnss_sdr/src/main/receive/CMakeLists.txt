# GNSS-SDR is a Global Navigation Satellite System software-defined receiver.
# This file is part of GNSS-SDR.
#
# SPDX-FileCopyrightText: 2010-2020 C. Fernandez-Prades cfernandez(at)cttc.es
# SPDX-License-Identifier: BSD-3-Clause

###haint
set(RECEIVE_DATA_SOURCES
    receive_data.cc
)

set(RECEIVE_DATA_HEADERS
    receive_data.h
)

list(SORT RECEIVE_DATA_HEADERS)
list(SORT RECEIVE_DATA_SOURCES)

if(USE_CMAKE_TARGET_SOURCES)
    add_library(receive_data_libs STATIC)
    target_sources(receive_data_libs
        PRIVATE
            ${RECEIVE_DATA_SOURCES}
        PUBLIC
            ${RECEIVE_DATA_HEADERS}
    )
else()
    source_group(Headers FILES ${RECEIVE_DATA_HEADERS})
    add_library(receive_data_libs ${RECEIVE_DATA_SOURCES} ${RECEIVE_DATA_HEADERS})
endif()

target_link_libraries(receive_data_libs
    PUBLIC
        core_receiver
)

target_include_directories(receive_data_libs
    PUBLIC
        ${GNSSSDR_SOURCE_DIR}/src/main/receiver
)

set_property(TARGET receive_data_libs
    APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

###haint
