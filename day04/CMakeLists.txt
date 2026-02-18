find_package(OpenSSL)

add_executable(day04 main.c)

target_link_libraries(day04 PRIVATE OpenSSL::Crypto)
