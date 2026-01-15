add_library(algorithm STATIC)

target_include_directories(algorithm
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PRIVATE .)
target_sources(algorithm PRIVATE sort.c)
