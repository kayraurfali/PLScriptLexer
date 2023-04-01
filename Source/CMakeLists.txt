cmake_minimum_required(VERSION 3.22)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})

set_target_properties(
    ${PROJECT_NAME}
        PROPERTIES
            LINKER_LANGUAGE CXX
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED True
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE "-ll")

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

install(
    FILES program.pls
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
