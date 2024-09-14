

#ifndef SG90_H_
#define SG90_H_

#include <stdio.h>
#include <sys/_intsup.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "hal/ledc_types.h"
#include "portmacro.h"
#include "esp_log.h"

//PWM settings
#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (13) 
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_15_BIT 
#define LEDC_DUTY               (2457) 
#define LEDC_FREQUENCY          (50)  


void servo_init(void);
void servo_swerve(void);
void servo_pos(int pos);


#endif 

