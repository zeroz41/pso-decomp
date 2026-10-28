#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/player/TObjPlayer.h"

void TObjPlayer::draw_status_icons(void* a1, void* a2) { ((TItemWeapon *)this)->draw_weapon_model(); ((TItemWeapon *)this)->get_gun_point(a1); draw_weapon_at_joint((s32)this, (s8)((void*)35)); ((TItemWeapon *)this)->get_gun_point(a2); }
