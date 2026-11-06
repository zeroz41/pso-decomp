#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A3C20.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"


void TUnk_804A3C20::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); }

TUnk_804A3C20::TUnk_804A3C20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(1);
}

u8 *TObjPlayer::create_obj_80128580(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3C20(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A3C20::~TUnk_804A3C20() {}
