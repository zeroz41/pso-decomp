#ifndef PSO_SYSTEM_SWITCHERLAUNCH_H
#define PSO_SYSTEM_SWITCHERLAUNCH_H

#include "types.h"

s32 launch_switcher_dol(const char *url);
extern s16 disc_error_code;

void launch_browser(s32 use_modem_url);
void select_dial_image(s32, s32 x);

#endif
