cmake_minimum_required(VERSION 3.1)
set(CMAKE_BUILD_TYPE Debug)    # Turn off compiler optimization

project (ettest)
enable_language(Fortran)
set(CMAKE_CXX_STANDARD 11)

list (APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Everytrace)
include_directories (${EVERYTRACE_INCLUDE_DIR})

set(VARIANTS c cf c_mpi cf_mpi)

foreach (VARIANT ${VARIANTS})
    add_library (ettestlib_${VARIANT} SHARED
        ${EVERYTRACE_${VARIANT}_REFADDR}
        ettestlib.cpp)
    target_link_libraries(ettestlib_${VARIANT} ${EVERYTRACE_LIBRARY})


    add_executable(test_et_${VARIANT} test_et.cpp)
    target_link_libraries(test_et_${VARIANT} ettestlib_${VARIANT})

    install(TARGETS ettestlib_${VARIANT} DESTINATION lib)
    install(TARGETS test_et_${VARIANT} DESTINATION bin)

endforeach()
