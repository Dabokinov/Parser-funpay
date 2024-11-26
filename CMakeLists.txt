cmake_minimum_required(VERSION 3.10)
project(FunpayRentalBot)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCE_FILES
    src/main.cpp
    src/http_client.cpp
    src/html_parser.cpp
    src/funpay_api.cpp
)
include_directories(include)
find_package(Gumbo REQUIRED)
include_directories(${GUMBO_INCLUDE_DIR})
add_executable(FunpayRentalBot ${SOURCE_FILES})
target_link_libraries(FunpayRentalBot ${GUMBO_LIBRARIES} curl)
