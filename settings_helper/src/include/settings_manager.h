#pragma once

#include "stddef.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif



struct settings_manager_entry_identifier {
    void* pointer;
    size_t len;
    void* default_value;
};


/// @brief Loads all settings from persistent memory into the current application by using an array that identifies the settings.
/// @param entries An array containing setting entries
/// @param entry_count The length of the array
/// @return 0 when successful, otherwise zephyr error number
int settings_manager_load_all(struct settings_manager_entry_identifier entries[], size_t entry_count);



/// @brief Saves all specified setttings into persistent memory
/// @param entries An array containing setting entries
/// @param entry_count The length of the array
/// @return 0 when successful, otherwise zephyr error number
int settings_manager_persist_all(struct settings_manager_entry_identifier entries[], size_t entry_count);



/// @brief Saves a single setting into persistent memory
/// @param entries An array containing setting entries
/// @param setting_id The array position of the setting that is to be stored
/// @return 0 when successful, otherwise zephyr error number
int settings_manager_persist_single(struct settings_manager_entry_identifier entries[], uint8_t setting_id);



/// @brief Sets all setting values to their default value. This function only affects setting values in the setting array. To persist them into persistent memory, settings_manager_persist_all(..) must be called aftter.
/// @param entries An array containing setting entries
/// @param entry_count The length of the array
void settings_manager_set_all_default(struct settings_manager_entry_identifier entries[], size_t entry_count);

#ifdef __cplusplus
}
#endif