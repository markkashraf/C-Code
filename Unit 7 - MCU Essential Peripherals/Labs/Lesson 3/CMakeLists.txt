cmake_minimum_required(VERSION 3.26)
project(Lesson_3 C)

set(CMAKE_C_STANDARD 11)

include_directories(STM32_F103C6_Drivers/inc)

add_executable(Lesson_3
        Src/main.c
        Src/syscalls.c
        Src/sysmem.c
        STM32_F103C6_Drivers/inc/GPIO_Driver.h
        STM32_F103C6_Drivers/inc/stm32f103x6.h
        STM32_F103C6_Drivers/GPIO_Driver.c)
