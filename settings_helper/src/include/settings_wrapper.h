#pragma once

// C Headers
#include <stddef.h>  // size_t

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief
 *
 * @param name - The setting name that should be loaded
 * @param dest - The destination buffer where the returned value is saved
 * @param len
 * @return int
 */
int settings_wrapper_load_single_value(const char *name, void *dest, size_t len);

/**
 * @brief
 *
 * @param name - The setting name that should be loaded
 * @param dest - The destination buffer where the returned value is saved
 * @param len
 * @return int
 */
int settings_wrapper_save_single_value(const char *name, void *value, size_t len);

#ifdef __cplusplus
}
#endif