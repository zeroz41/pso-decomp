#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/item/TUnk_804A3640.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

struct Self_80127BE0 { u8 pad[0xF0]; s32 fF0; };

struct Item_80127BE0 { u16 a; s16 b; };

struct Tec_80127BE0 { s32 kind; u16 a; s16 b; u8 rest[0x58]; };

extern "C" {
s16 is_status_subsystem_ready__10TObjPlayerFv(s32);
s32 get_extended_state__10TObjPlayerFv(s32);
Item_80127BE0 *get_captured_target_entry(s32, s32);
void TUnk_804A3640::emit_marker_effects() {
    Item_80127BE0 *item;
    s32 kind;
    s32 ext;
    s32 i;
    Tec_80127BE0 tec;
    u8 buf[0xC];
    switch (is_status_subsystem_ready__10TObjPlayerFv(((Self_80127BE0 *)this)->fF0)) {
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
        ext = get_extended_state__10TObjPlayerFv(((Self_80127BE0 *)this)->fF0);
        if (ext != 0) {
            for (i = 0; i != get_captured_target_count((s32 *)ext); i++) {
                item = get_captured_target_entry(ext, i);
                if (item != NULL) {
                    ((TObjPlayer *)(&tec))->construct_target_cursor_records();
                    tec.kind = 1;
                    tec.a = item->a;
                    tec.b = item->b;
                    ((TTecGiZonde *)(((Self_80127BE0 *)this)->fF0))->create((void *)buf, &tec, (void *)kind);
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

u8 *TObjPlayer::create_with_id_2(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3640(tl_05, arg0);
    }
    return NULL;
}
