#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80308294.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/system/task/TObject.h"

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;


extern saddr tl_05;
extern "C" {
s32 create_fire_explosion_effect(void *, void *, s32, saddr, f32);
void *TObjPlayer__sub_802E449C(void *a0);
}
extern s32 tl_particle;
s32 spawn_fire_explosion_at(uaddr a0, saddr a1) {
    S_802E449C info;
    void *o;
    TObjPlayer__sub_802E449C(&info);
    ((TItemWeapon *)a0)->fill_status_info(&info);
    VecCopy(&info.position, (const Vec *)a1);
    info.hits = 10;
    new TUnk_804A2548((TObject *)tl_05, &info);
    o = TObject::operator new(0x64);
    if (o != NULL) {
        ((s32 (*)(f32, void *, void *, s32, s32))create_fire_explosion_effect)(10.0f, o, &info, 0, tl_particle);
    }
}
