# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Espressif/frameworks/esp-idf-v5.1.4/components/bootloader/subproject"
  "E:/STT2024/Esp32_Sg90/build/bootloader"
  "E:/STT2024/Esp32_Sg90/build/bootloader-prefix"
  "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/tmp"
  "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/src/bootloader-stamp"
  "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/src"
  "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/STT2024/Esp32_Sg90/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
