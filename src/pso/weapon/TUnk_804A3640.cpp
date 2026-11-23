#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/weapon/TUnk_804A3640.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"


struct Self_80127BE0 { u8 pad[0xF0]; saddr caster; };


struct Tec_80127BE0 { s32 kind; u16 a; s16 b; u8 rest[0x58]; };

extern "C" {
void TUnk_804A3640::emit_marker_effects() {
    CapturedTarget *item;
    saddr kind;
    CapturedTargetList *ext;
    s32 i;
    Tec_80127BE0 tec;
    u8 buf[0xC];
    switch (((TObjPlayer *)(((Self_80127BE0 *)this)->caster))->is_status_subsystem_ready()) {
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
        ext = ((TObjPlayer *)(((Self_80127BE0 *)this)->caster))->get_extended_state();
        if (ext != 0) {
            for (i = 0; i != ext->get_captured_target_count(); i++) {
                item = ext->get_captured_target_entry(i);
                if (item != NULL) {
                    __ct__16TargetCursorListFv((&tec));
                    tec.kind = 1;
                    tec.a = item->uid;
                    tec.b = item->collider_index;
                    TTecGiZonde::create((void *)((Self_80127BE0 *)this)->caster, (Vec *)buf, &tec, kind);
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
