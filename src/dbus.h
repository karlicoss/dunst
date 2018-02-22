/* copyright 2013 Sascha Kruse and contributors (see LICENSE for licensing information) */

#ifndef DUNST_DBUS_H
#define DUNST_DBUS_H

#include "notification.h"

/// The reasons according to the notification spec
enum reason {
        REASON_MIN = 1,   /**< Minimum value, useful for boundary checking */
        REASON_TIME = 1,  /**< The notification timed out */
        REASON_USER = 2,  /**< The user closed the notification */
        REASON_SIG = 3,   /**< The daemon received a `NotificationClose` signal */
        REASON_UNDEF = 4, /**< Undefined reason not matching the previous ones */
        REASON_MAX = 4,   /**< Maximum value, useful for boundary checking */
};

int initdbus(void);
void dbus_tear_down(int id);
/* void dbus_poll(int timeout); */
void signal_notification_closed(notification *n, enum reason reason);
void signal_action_invoked(notification *n, const char *identifier);

#endif
/* vim: set tabstop=8 shiftwidth=8 expandtab textwidth=0: */
