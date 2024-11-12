#include "uartcommunication.h"
#include "driver/uart.h"
#include "esp_log.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

static const int RX_BUF_SIZE = 1024;

void uart_init() {
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
}

uint32_t get_user_angle() {
    uint8_t data[RX_BUF_SIZE];
    int len = uart_read_bytes(UART_NUM_1, data, RX_BUF_SIZE, 20 / portTICK_RATE_MS);
    if (len > 0) {
        data[len] = '\0'; // Kết thúc chuỗi dữ liệu nhận được
        return atoi((char*)data); // Chuyển đổi chuỗi sang số nguyên
    }
    return 0; // Trả về 0 nếu không có dữ liệu
}
