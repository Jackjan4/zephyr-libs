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

int settings_manager_load_all(struct settings_manager_entry_identifier entries[], size_t entry_count);

int settings_manager_persist_all(struct settings_manager_entry_identifier entries[], size_t entry_count);

int settings_manager_persist_single(struct settings_manager_entry_identifier entries[], uint8_t setting_id);

void settings_manager_set_all_default(struct settings_manager_entry_identifier entries[], size_t entry_count);

#ifdef __cplusplus
}
#endif