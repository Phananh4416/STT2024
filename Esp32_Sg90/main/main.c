#include <stdint.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sg90.h"  // Đảm bảo tệp này chứa định nghĩa của servo_init, servo_swerve, servo_pos

void task(void *arg)
{
    servo_init();  // Khởi tạo servo
    while(1)
    {
        servo_swerve();  // Thực hiện hành động xoay servo
        servo_pos(20);   // Đặt vị trí servo về 12 độ
        
        vTaskDelay(pdMS_TO_TICKS(100));  // Chờ 100ms để tránh chiếm dụng toàn bộ CPU
    }
}

void app_main(void)
{
    // Kiểm tra kết quả trả về của xTaskCreatePinnedToCore để xác định có tạo task thành công hay không
    if (xTaskCreatePinnedToCore(&task, "test", 4096, NULL, 5, NULL, 1) != pdPASS) {
        printf("Failed to create task!\n");
    }
}

