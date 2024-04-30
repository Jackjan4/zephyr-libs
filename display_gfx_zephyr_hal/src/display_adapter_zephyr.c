#include "display_adapter_zephyr.h"



void display_adapter_zephyr_write_buffer_to_display(const struct display_adapter_descriptor* adapter, uint8_t x, uint8_t y, void* payload) {
    int err = 0;

    // Create buffer description
    const struct display_buffer_descriptor buf_desc = {
        .buf_size = adapter->buffer_size,
        .width = adapter->width,
        .height = adapter->height,
        .pitch = adapter->width,
    };


    err = display_write((const struct device*)payload, 0, 0, &buf_desc, adapter->display_buffer);
}



struct display_adapter_descriptor display_adapter_create_zephyr_ssd1327(enum display_adapter_bitmode_t bitmode, enum display_adapter_rotation_t rotation, const struct device* display_device) {
    struct display_capabilities cap;
    display_get_capabilities(display_device, &cap);

    uint16_t buffer_size = 0;
    switch (bitmode) {
        case (DISPLAY_ADAPTER_BITMODE_GRAYSCALE_1_BIT): {
            buffer_size = (128 * 128) >> 3;
            break;
        }
        case (DISPLAY_ADAPTER_BITMODE_GRAYSCALE_2_BIT): {
            buffer_size = (128 * 128) >> 2;
            break;
        }
        case (DISPLAY_ADAPTER_BITMODE_GRAYSCALE_4_BIT): {
            buffer_size = (128 * 128) >> 1;
            break;
        }
        case (DISPLAY_ADAPTER_BITMODE_COLOR_8_BIT): {
            // TODO: Error
            break;
        }
    }

    struct display_adapter_descriptor result = {
        .display_buffer = (uint8_t*)k_calloc(buffer_size, sizeof(uint8_t)),
        .buffer_size = buffer_size,
        .fn_write_buffer_to_display = display_adapter_zephyr_write_buffer_to_display,
        .payload = display_device,
        .width = cap.x_resolution,
        .height = cap.y_resolution,
        .rotation = rotation,
        .bitmode = bitmode,
        .addressing_mode = DISPLAY_ADAPTER_BUFFER_ADDRESSING_MODE_HORIZONTAL,
        .device_id = DISPLAY_ADAPTER_DEVICE_ID_ZEPHYR_SSD1327,
    };

    return result;
}



struct display_adapter_descriptor display_adapter_create_zephyr_ssd1306_heap(enum display_adapter_buffer_addressing_mode_t addressing_mode, enum display_adapter_rotation_t rotation, const struct device* display_device) {
    struct display_capabilities cap;
    display_get_capabilities(display_device, &cap);

    uint16_t buffer_size = (128 * 64) >> 3;

    struct display_adapter_descriptor result = {
        .display_buffer = (uint8_t*)k_calloc(buffer_size, sizeof(uint8_t)),
        .buffer_size = buffer_size,
        .fn_write_buffer_to_display = display_adapter_zephyr_write_buffer_to_display,
        .payload = display_device,
        .width = cap.x_resolution,
        .height = cap.y_resolution,
        .rotation = rotation,
        .bitmode = DISPLAY_ADAPTER_BITMODE_GRAYSCALE_1_BIT,
        .addressing_mode = addressing_mode,
        .device_id = DISPLAY_ADAPTER_DEVICE_ID_ZEPHYR_SSD1306A,
    };

    return result;
}