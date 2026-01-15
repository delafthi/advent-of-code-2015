add_executable(day02)

target_include_directories(day02 PRIVATE .)
target_sources(day02 PRIVATE main.c package.c)
target_link_libraries(day02 PRIVATE algorithm)
