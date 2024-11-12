set(app_src wifi.c)
set(pre_req esp_wifi esp_event nvs_flash log freertos)

idf_component_register(SRCS ${app_src}
                    INCLUDE_DIRS "."
                    REQUIRES ${pre_req})
