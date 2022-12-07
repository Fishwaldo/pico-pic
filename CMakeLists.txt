cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)
# initialize the Raspberry Pi Pico SDK
pico_sdk_init()
add_subdirectory(bootloader)

add_compile_options("-g")
add_compile_options("-O0")
add_compile_options("-Wall")

project(blink)
add_executable(blink
        blink.c
        image_info.c
        )
set_target_properties(blink PROPERTIES COMPILE_FLAGS "-fpie -fno-plt -Wall -g -O0 -fpic -mpic-register=r9 -msingle-pic-base -mno-pic-data-is-text-relative")
target_link_libraries(blink "-fpie -fno-plt -Wall -g -O0 -fpic -mpic-register=r9 -msingle-pic-base -mno-pic-data-is-text-relative"  pico_stdlib )
pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)
bootloader_build_combined(blink)
pico_add_extra_outputs(blink)

project(blink-standalone)
add_executable(blink-standalone
        blink.c
        image_info.c
        )
set_target_properties(blink-standalone PROPERTIES COMPILE_FLAGS "-fpie -fno-plt -Wall -g -O0 -fpic -mpic-register=r9 -msingle-pic-base -mno-pic-data-is-text-relative")
target_link_libraries(blink-standalone  pico_stdlib)
target_link_options(blink-standalone PUBLIC -fpie -fno-plt -Wall -g -O0 -fpic -mpic-register=r9 -msingle-pic-base -mno-pic-data-is-text-relative)
pico_enable_stdio_usb(blink-standalone 1)
pico_enable_stdio_uart(blink-standalone 0)
bootloader_build_standalone(blink-standalone)
pico_add_extra_outputs(blink-standalone)
        
