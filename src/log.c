/* copyright 2012 - 2013 Sascha Kruse and contributors (see LICENSE for licensing information) */

#include "log.h"

#include <glib.h>

static const char *log_level_to_string(GLogLevelFlags level)
{
        switch (level) {
        case G_LOG_LEVEL_ERROR: return "ERROR";
        case G_LOG_LEVEL_CRITICAL: return "CRITICAL";
        case G_LOG_LEVEL_WARNING: return "WARNING";
        case G_LOG_LEVEL_MESSAGE: return "MESSAGE";
        case G_LOG_LEVEL_INFO: return "INFO";
        case G_LOG_LEVEL_DEBUG: return "DEBUG";
        default: return "UNKNOWN";
        }
}

/*
 * Log handling function for GLib's logging wrapper
 */
static void dunst_log_handler(
                const gchar    *log_domain,
                GLogLevelFlags  message_level,
                const gchar    *message,
                gpointer        user_data)
{
        const char *log_level_str =
                log_level_to_string(message_level & G_LOG_LEVEL_MASK);

        /* Use stderr for warnings and higher */
        if (message_level <= G_LOG_LEVEL_WARNING)
                g_printerr("%s: %s\n", log_level_str, message);
        else
                g_print("%s: %s\n", log_level_str, message);
}

/*
 * Initialise log handling. Can be called any time.
 */
void dunst_log_init(void)
{
        g_log_set_default_handler(dunst_log_handler, NULL);
}

/* vim: set tabstop=8 shiftwidth=8 expandtab textwidth=0: */
