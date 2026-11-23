#include "pso/unk/TUnk_804CCB28.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80308294.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

typedef struct SlicerLaunchData_8012D9C8 {
    u16 player; u16 pad;
    void *textures; void *model; u32 weapon;
    s16 kind, stage; f32 multiplier; f32 color[4];
    s32 facing, spin; f32 first[3], second[3];
} SlicerLaunchData_8012D9C8;


void spawn_fire_explosion_at(uaddr item_weapon, saddr a1) {
    Desc_8011E5C4 info;
    TObjPlayer__sub_802E449C(&info);
    ((TItemWeapon *)item_weapon)->fill_status_info(&info);
    VecCopy(&info.position, (const Vec *)a1);
    info.hits = 10;
    new TUnk_804A2548(tl_05, &info);
    new TUnk_804CCB28(10.0f, &info.position, 0, tl_particle);
}
