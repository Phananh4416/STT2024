set(app_src thinkboard.c)
set(pre_req mqtt log)
idf_component_register(SRCS ${app_src}
                    INCLUDE_DIRS "." "E:/Espressif/frameworks/esp-idf-v5.1.4/components/mqtt/esp-mqtt/include"
                    REQUIRES ${pre_req})



