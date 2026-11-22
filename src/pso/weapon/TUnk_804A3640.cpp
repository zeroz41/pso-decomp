#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/weapon/TUnk_804A3640.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"


struct Self_80127BE0 { u8 pad[0xF0]; saddr fF0; };

struct Item_80127BE0 { u16 a; s16 b; };

struct Tec_80127BE0 { s32 kind; u16 a; s16 b; u8 rest[0x58]; };

extern "C" {
Item_80127BE0 *get_captured_target_entry(s32, s32);
void TUnk_804A3640::emit_marker_effects() {
    Item_80127BE0 *item;
    saddr kind;
    saddr ext;
    s32 i;
    Tec_80127BE0 tec;
    u8 buf[0xC];
    switch (((TObjPlayer *)(((Self_80127BE0 *)this)->fF0))->is_status_subsystem_ready()) {
    case 1:
        kind = 8;
        break;
    case 0:
        kind = 3;
        break;
    default:
        kind = 8;
        break;
    }
    if (get_joint_position(1, buf) != 0) {
        ext = (saddr)((TObjPlayer *)(((Self_80127BE0 *)this)->fF0))->get_extended_state();
        if (ext != 0) {
            for (i = 0; i != get_captured_target_count((s32 *)ext); i++) {
                item = get_captured_target_entry(ext, i);
                if (item != NULL) {
                    __ct__16TargetCursorListFv((&tec));
                    tec.kind = 1;
                    tec.a = item->a;
                    tec.b = item->b;
                    TTecGiZonde::create((void *)((Self_80127BE0 *)this)->fF0, (Vec *)buf, &tec, kind);
                }
            }
        }
    }
}

}

TUnk_804A3640::~TUnk_804A3640() {}

TUnk_804A3640::TUnk_804A3640(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TObjPlayer::create_with_id_2(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3640(tl_05, item);
    }
    return NULL;
}
