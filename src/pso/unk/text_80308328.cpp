#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/ui/TAdVIConfigGC_80308200.h"
#include "pso/player/TUnk_804E71F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdVIConfigGC.h"

struct T_80308328 { u8 pad0[0x40]; u32 flags; u8 pad44[0xC]; s32 f50; u8 pad54[0x1C]; void *f70; void *f74; s32 f78; s32 f7c; };

extern "C" {
void config_nug2000_attack_collider__10TObjPlayerFPvPv(void *self, T_80308328 *p);

void config_nug2000_attack_collider__10TObjPlayerFPvPv(void *self, T_80308328 *p) {
    p->f74 = (void *)spawn_nug2000_hit_explosion;
    p->f70 = (void *)TAdVIConfigGC::apply_config_if_valid;
    p->f50 = -0x4000;
    p->f78 = 0x1bb;
    p->f7c = 0x1bc;
    p->flags |= 0x80;
}

void TUnk_804E71F8::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TObjPlayer *)arg0)->draw_icon(1, (s32) &sp8);
    ((TItemWeapon *)arg0)->fire_shot_at_target((void *)(&sp8), (void *)(this->second_model), 0);
}

}
