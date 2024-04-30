#pragma once



/// Zephyr Headers
#include <zephyr/drivers/display.h>



/// Library Headers
// display_gfx
#include "display_adapter.h"



#ifdef __cplusplus
extern "C" {
#endif



/// @brief Creates a display_adapter (to be used in the display_gfx library) for the SSD1327 OLED configured as a Zephyr display
/// @param bitmode The grayscale bitmode othat should be used
/// @param rotation The desired rotation of the display
/// @param display_device The zephyr display device to which the SSD1327 is configured to
/// @return The initialized display adapter for the given display
struct display_adapter_descriptor display_adapter_create_zephyr_ssd1327(enum display_adapter_bitmode_t bitmode, enum display_adapter_rotation_t rotation, const struct device* display_device);



/// @brief Creates a display_adapter (to be used in the display_gfx library) for the SSD1306A OLED configured as a Zephyr display
/// @param addressing_mode The addressing mode of the OLED driver
/// @param rotation The desired rotation of the display
/// @param display_device The zephyr display device to which the SSD1306A is configured to 
/// @return The initialized display adapter for the given display
struct display_adapter_descriptor display_adapter_create_zephyr_ssd1306_heap(enum display_adapter_buffer_addressing_mode_t addressing_mode, enum display_adapter_rotation_t rotation, const struct device* display_device);



#ifdef __cplusplus
}
#endif