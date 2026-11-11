#include "types.h"
#include "pso/unk/text_80308294.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"

struct RecoveredGlobal_8034F754_lbl_804F0A00 {
    s32 value;
    u8 remaining[0xF4];
};

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;


extern s32 tl_05;
extern "C" {
void *__nw__7TObjectFUl(u32);
s32 create_fire_explosion_effect(void *, void *, s32, s32, f32);
void *TObjPlayer__sub_802E449C(void *a0);
}
extern s32 tl_particle;
s32 spawn_fire_explosion_at(u32 a0, s32 a1) {
    S_802E449C info;
    void *o;
    TObjPlayer__sub_802E449C(&info);
    ((TObjPlayer *)a0)->fill_status_info(&info);
    VecCopy(&info.position, (const Vec *)a1);
    info.hits = 10;
    new TUnk_804A2548((TObject *)tl_05, &info);
    o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        ((s32 (*)(f32, void *, void *, s32, s32))create_fire_explosion_effect)(10.0f, o, &info, 0, tl_particle);
    }
}
typedef char RecoveredGlobal_8034F754_lbl_804F0A00_size[sizeof(RecoveredGlobal_8034F754_lbl_804F0A00) == 0xF8 ? 1 : -1];
