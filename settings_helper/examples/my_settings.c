#include "my_settings.h"



uint8_t MY_SETTING_AGE



// === Default values ===
uint8_t MY_SETTING_AGE_DEFAULT = 21;



struct settings_manager_entry_identifier my_settings_identifiers[] = {
    {
        .pointer = &MY_SETTING_AGE,
        .len = sizeof(MY_SETTING_AGE),
        .default_value = &MY_SETTING_AGE_DEFAULT,
    }
};