#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TObjPlayer.h"

void TObjPlayer::draw_status_icons(void* a1, void* a2) { ((TItemWeapon *)this)->draw_weapon_model(); draw_status_icon((s32)a1); draw_weapon_at_joint((s32)this, (s8)((void*)35)); draw_status_icon((s32)a2); }
