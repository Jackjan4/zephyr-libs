#include "settings_manager.h"

// Library Header
#include "settings_wrapper.h"



int settings_manager_load_all(struct settings_manager_entry_identifier entries[], size_t entry_count) {
    int err = 0;
    for (uint8_t i = 0; i < entry_count; i++) {
        struct settings_manager_entry_identifier id = entries[i];
        err = settings_wrapper_load_single_value((const char[]){i + 1, '\0'}, id.pointer, id.len);
        if (err) {
            break;
        }
    }
    return err;
}



int settings_manager_persist_all(struct settings_manager_entry_identifier entries[], size_t entry_count) {
    int err = 0;
    for (uint8_t i = 0; i < entry_count; i++) {
        struct settings_manager_entry_identifier id = entries[i];
        err = settings_wrapper_save_single_value((const char[]){i + 1, '\0'}, id.pointer, id.len);
        if (err) {
            break;
        }
    }
    return err;
}



int settings_manager_persist_single(struct settings_manager_entry_identifier entries[], uint8_t setting_id) {
    int err = 0;
    struct settings_manager_entry_identifier id = entries[setting_id];
    err = settings_wrapper_save_single_value((const char[]){setting_id + 1, '\0'}, id.pointer, id.len);
    if (err) {
        // TODO: Correct error
        err = -1;
    }
    return err;
}



void settings_manager_set_all_default(struct settings_manager_entry_identifier entries[], size_t entry_count) {
    for (uint8_t i = 0; i < entry_count; i++) {
        struct settings_manager_entry_identifier id = entries[i];
        switch (id.len) {
            case (1): {
                char* ptr = (char*)id.pointer;
                *ptr = *((char*)id.default_value);
                break;
            }
            case (2): {
                // TODO: Check what happens if this is actually a string with 2 byte
                short* ptr = (short*)id.pointer;
                *ptr = *((short*)id.default_value);
                break;
            }
            case (4): {
                long* ptr = (long*)id.pointer;
                *ptr = *((long*)id.default_value);
                break;
            }
        }
    }
}