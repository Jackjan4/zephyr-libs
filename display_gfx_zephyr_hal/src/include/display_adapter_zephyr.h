#pragma once

// Zephyr Headers
#include <zephyr/drivers/display.h>

/// Library Headers
// display_gfx
#include "display_adapter.h"

struct display_adapter_descriptor display_adapter_create_zephyr_ssd1327(enum display_adapter_bitmode_t bitmode, enum display_adapter_rotation_t rotation, const struct device* display_device);

struct display_adapter_descriptor display_adapter_create_zephyr_ssd1306_heap(enum display_adapter_rotation_t rotation, const struct device* display_device, enum display_adapter_buffer_addressing_mode_t addressing_mode);