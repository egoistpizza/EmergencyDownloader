cmake_minimum_required(VERSION 3.10)
project(EmergencyDownloader)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/Downloader.cpp
    src/Downloader.h
    src/resource.rc
)

include_directories(src)

add_executable(EmergencyDownloader ${SOURCES})

if (WIN32)
    set_source_files_properties(src/resource.rc PROPERTIES LANGUAGE RC)
    target_link_libraries(EmergencyDownloader PRIVATE urlmon)
endif()
