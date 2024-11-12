#include "thinkboard.h"
#include "mqtt_client.h"
#include "esp_log.h"
#include <stdint.h>  // Thêm file header này
#include <stdarg.h>  // Thêm file header này nếu cần thiết
#include <inttypes.h>

static const char *TAG = "thinkboard";
esp_mqtt_client_handle_t client;

void mqtt_app_start() {
    const esp_mqtt_client_config_t mqtt_cfg = {
        .uri = "mqtt://broker.thinkboard.com",
    };
    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_start(client);
}

void send_data_to_thinkboard(uint32_t angle, uint32_t speed, uint32_t desired_angle) {
    char data[100];
    snprintf(data, sizeof(data), "{\"angle\": %" PRIu32 ", \"speed\": %" PRIu32 ", \"desired_angle\": %" PRIu32 "}", angle, speed, desired_angle);
    esp_mqtt_client_publish(client, "/topic/servo/data", data, 0, 1, 0);
}
