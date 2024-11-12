set(app_src servo.c)
set(pre_req driver soc)
idf_component_register(SRCS ${app_src}
                    INCLUDE_DIRS "."
                    REQUIRES ${pre_req})