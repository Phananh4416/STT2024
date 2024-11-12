#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "servo_control.h"
#include "thinkboard.h"
#include "wifi_connect.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "nvs_flash.h" // Đảm bảo bao gồm thư viện này

static const char *TAG = "main";

void app_main() {
    ESP_LOGI(TAG, "ESP32 Servo Control Project Starting...");

    // Kiểm tra và khởi tạo NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Khởi tạo WiFi
    ret = wifi_init_sta();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize WiFi: %s", esp_err_to_name(ret));
        return;
    }

    // Thiết lập servo
    setup_servo();

    // Khởi động MQTT
    ret = mqtt_app_start();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start MQTT: %s", esp_err_to_name(ret));
        return;
    }

    uint32_t angle = CONFIG_USER_SERVO_ANGLE; // Lấy góc quay từ menuconfig
    uint32_t speed = 100; // Tốc độ giả định
    uint32_t desired_angle = CONFIG_USER_SERVO_ANGLE; // Góc mong muốn từ menuconfig

    while (true) {
        set_servo_angle(angle);
        send_data_to_thinkboard(angle, speed, desired_angle);
        ESP_LOGI(TAG, "Current angle: %" PRIu32 ", Speed: %u, Desired angle: %" PRIu32, angle, speed, desired_angle);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Chờ 1 giây
    }
}
