#ifndef PSO_NETWORK_NETWORKWAITICON_H
#define PSO_NETWORK_NETWORKWAITICON_H

#include "types.h"

// The spinning icon drawn while a socket call blocks (connect, resolve, connection test).
void draw_wait_icon_quad(f32 *pos, f32 *scale, s32 angle, s32 uv_angle);
void draw_network_wait_icon(void);
void advance_network_wait_icon(void);
// Steps the icon animation and draws it; called while a socket call waits.
void update_network_wait_icon(void);

#endif
