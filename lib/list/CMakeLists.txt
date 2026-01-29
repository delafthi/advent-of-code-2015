add_library(list STATIC list.c)

target_include_directories(list PUBLIC ${CMAKE_SOURC_DIR}/include
  PRIVATE ${CMAKE_SOURCE_DIR}/include/lib
)
