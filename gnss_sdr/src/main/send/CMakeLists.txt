# GNSS-SDR is a Global Navigation Satellite System software-defined receiver.
# This file is part of GNSS-SDR.
#
# SPDX-FileCopyrightText: 2010-2020 C. Fernandez-Prades cfernandez(at)cttc.es
# SPDX-License-Identifier: BSD-3-Clause

###haint
set(SEND_DATA_SOURCES
    send_data.cc
)

set(SEND_DATA_HEADERS
    send_data.h
)

list(SORT SEND_DATA_HEADERS)
list(SORT SEND_DATA_SOURCES)

if(USE_CMAKE_TARGET_SOURCES)
    add_library(send_data_libs STATIC)
    target_sources(send_data_libs
        PRIVATE
            ${SEND_DATA_SOURCES}
        PUBLIC
            ${SEND_DATA_HEADERS}
    )
else()
    source_group(Headers FILES ${SEND_DATA_HEADERS})
    add_library(send_data_libs ${SEND_DATA_SOURCES} ${SEND_DATA_HEADERS})
endif()

target_link_libraries(send_data_libs
    PUBLIC
        tracking_libs
        tracking_gr_blocks
)

target_include_directories(send_data_libs
    PUBLIC
        ${GNSSSDR_SOURCE_DIR}/src/main/send
)

set_property(TARGET send_data_libs
    APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

###haint
