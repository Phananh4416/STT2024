#ifndef THINKBOARD_H
#define THINKBOARD_H

#include <stdint.h>

void mqtt_app_start(void);
void send_data_to_thinkboard(uint32_t angle, uint32_t speed, uint32_t desired_angle);

#endif // THINKBOARD_H
