#pragma once



// C Header
#include "stddef.h"
#include "stdint.h"



/// Library Header
#include "settings_manager.h"



#ifdef __cplusplus
extern "C" {
#endif



enum my_settings_id_t {
    MY_SETTINGS_ID_AGE = 0x00,
};



// === Setting Definitions ===

// We would like to save an age into persitent memory
extern uint8_t MY_SETTING_AGE;



extern struct settings_manager_entry_identifier global_settings_identifiers[1];


#ifdef __cplusplus
}
#endif