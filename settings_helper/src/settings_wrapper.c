// Module
#define MODULE settings_wrapper

// Headder
#include "settings_wrapper.h"

// Zephyr Header
#ifdef CONFIG_LOG
#include "logging/log.h"
#endif
#include <settings/settings.h>
#include <zephyr.h>

// Logging
#ifdef CONFIG_LOG
LOG_MODULE_REGISTER(MODULE);
#endif

struct direct_immediate_value {
    size_t len;
    void *dest;
    uint8_t fetched;  // boolean
};

static int settings_wrapper_direct_loader_immediate_value(const char *name, size_t len, settings_read_cb read_cb, void *cb_arg, void *param) {
    const char *next;
    size_t name_len;
    int err;
    struct direct_immediate_value *dov = (struct direct_immediate_value *)param;

    name_len = settings_name_next(name, &next);

    if (name_len == 0) {
        if (len == dov->len) {
            err = read_cb(cb_arg, dov->dest, len);
            if (err >= 0) {
                dov->fetched = 1;
                return 0;
            }
            return err;
        }
        return -EINVAL;
    }

    /* other keys aren't served by the callback
     * Return success in order to skip them
     * and keep storage processing.
     */
    return 0;
}

int settings_wrapper_load_single_value(const char *name, void *dest, size_t len) {
    int err;
    struct direct_immediate_value dov;

    dov.fetched = 0;
    dov.len = len;
    dov.dest = dest;

    err = settings_load_subtree_direct(name, settings_wrapper_direct_loader_immediate_value, (void *)&dov);
    if (!err) {
        if (!dov.fetched) {
            err = -ENOENT;
        }
    }

    return err;
}

/**
 * @brief Set the tings wrapper save single value object
 *
 * @param name
 * @param value
 * @param len
 * @return int
 */
int settings_wrapper_save_single_value(const char *name, void *value, size_t len) {
    int err = settings_save_one(name, value, len);
    return err;
}