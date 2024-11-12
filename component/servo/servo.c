#include "servo.h"
#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"
#include "sdkconfig.h"
#include <stdint.h>  // Thêm file header này
#include <inttypes.h>

void setup_servo() {
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, CONFIG_SERVO_PWM_GPIO); // Sử dụng chân GPIO từ menuconfig
    mcpwm_config_t pwm_config = {
        .frequency = 50,
        .cmpr_a = 0,
        .duty_mode = MCPWM_DUTY_MODE_0,
        .counter_mode = MCPWM_UP_COUNTER,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
}

void set_servo_angle(uint32_t angle) {
    uint32_t duty = (angle * (2400 - 600) / 180) + 600;
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, duty);
}
