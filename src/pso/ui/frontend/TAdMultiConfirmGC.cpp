#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiConfirmGC.h"
#include "pso/ui/frontend/TAdMultiOkGC.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdMultiPlayerNoGC.h"
#include "pso/system/task/TObject.h"

typedef struct Obj_802FF87C {
    u8 pad0[0x1C];
    s32 state;
    u32 count;
    u8 pad24[0x34 - 0x24];
    TAdChrSelPlayerGC *players[4];
    u8 pad44[4];
    s32 x48;
} Obj_802FF87C;

struct TAdMultiConfirmGC_802FFA3C {
    s32 x0;
    u8 pad4[0x14];
    void *vt;
    s32 state;
    u32 count;
    s32 ids[4];
    TAdChrSelPlayerGC *players[4];
    void *guide;
    TAdMultiOkGC *ok;
};

extern "C" {
void TAdMultiConfirmGC__sub_802E03D0(void *);
void TAdMultiConfirmGC__sub_802E0448(void *);
s32 fn_802E0454(void *);
}
extern "C" {
saddr get_localized_text_entry(s32 arg0, s32 arg1);
}
s32 is_multiplayer_character_slot_selected(s32 arg0);
extern "C" {
void fn_802FF7EC(void *);
extern const char *TAdMultiConfirmGC__name;
extern const u8 lbl_805DEF30 = 0;
void fn_802FF760(void *);
}

void TAdMultiConfirmGC::render() {  }

void TAdMultiConfirmGC::run_task() {
    Obj_802FF87C *arg0 = (Obj_802FF87C *)this;
    u32 j;
    u32 i;
    switch (this->m_1c) {
    case 0:
        this->m_1c = 1;
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            if (arg0->players[i] != NULL) {
                arg0->players[i]->set_field_100(2);
            }
        }
        this->m_1c = 2;
        break;
    case 2:
        i = 1;
        for (j = 0; j < this->m_20; j++) {
            if (arg0->players[j] != NULL && fn_802E0454(arg0->players[j]) == 0) {
                i = 0;
                break;
            }
        }
        if ((s32)i == 1) {
            for (i = 0; i < this->m_20; i++) {
                if (arg0->players[i] != NULL) {
                    TAdMultiConfirmGC__sub_802E0448(arg0->players[i]);
                    TAdMultiConfirmGC__sub_802E03D0(arg0->players[i]);
                }
            }
            this->m_1c = 3;
        }
        break;
    case 3:
        if (ok->multi_confirm_cancel_requested() != 0) {
            TAdMultiChgGameModeGC::set_change_game_mode();
        } else if (ok->are_all_entries_finished() != 0) {
            TAdMultiChgGameModeGC::set_state_0xc();
        }
        break;
    }
}
TAdMultiConfirmGC::~TAdMultiConfirmGC() {
    fn_802FF760(this);
}
#pragma push
#pragma opt_common_subs off
TAdMultiConfirmGC::TAdMultiConfirmGC(TObject *parent) : TObject(parent) {
    TAdMultiOkSetup arg;
    u32 i;
    u32 j;
    u32 n;
    void *p;
    m_name = TAdMultiConfirmGC__name;
    ((TAdMultiConfirmGC_802FFA3C *)this)->state = 0;
    ((TAdMultiConfirmGC_802FFA3C *)this)->guide = 0;
    for (i = 0; i < 4; i++) {
        ((TAdMultiConfirmGC_802FFA3C *)this)->players[i] = 0;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdTitleGC(this, 0x10);
    new TAdTitleTexGC(this);
    ((TAdMultiConfirmGC_802FFA3C *)this)->count = 0;
    for (i = 0; i < 4; i++) {
        ((TAdMultiConfirmGC_802FFA3C *)this)->ids[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (is_multiplayer_character_slot_selected(i) != 0) {
            ((TAdMultiConfirmGC_802FFA3C *)this)->ids[((TAdMultiConfirmGC_802FFA3C *)this)->count] = i;
            ((TAdMultiConfirmGC_802FFA3C *)this)->count++;
        }
    }
    arg.count = ((TAdMultiConfirmGC_802FFA3C *)this)->count;
    arg.mask = 0;
    for (j = 0; j < (n = ((TAdMultiConfirmGC_802FFA3C *)this)->count); j++) {
        ((TAdMultiConfirmGC_802FFA3C *)this)->players[j] = TAdMultiPlyChrSelectGC::get_or_create_player(this, n + 1, j, ((TAdMultiConfirmGC_802FFA3C *)this)->ids[j]);
        new TAdMultiPlayerNoGC(this, ((TAdMultiConfirmGC_802FFA3C *)this)->count, j, ((TAdMultiConfirmGC_802FFA3C *)this)->ids[j]);
        arg.mask |= 1 << ((TAdMultiConfirmGC_802FFA3C *)this)->ids[j];
    }
    ((TAdMultiConfirmGC_802FFA3C *)this)->ok = new TAdMultiOkGC(this, &arg);
    p = new TAdGuideTxtGC(reinterpret_cast<TObject *>(((TAdMultiConfirmGC_802FFA3C *)this)));
    ((TAdMultiConfirmGC_802FFA3C *)this)->guide = p;
    ((TAdGuideTxtGC *)(((TAdMultiConfirmGC_802FFA3C *)this)->guide))->set_line(0, reinterpret_cast<const char *>((get_localized_text_entry(0x25, 0))));
    ((TAdGuideTxtGC *)(((TAdMultiConfirmGC_802FFA3C *)this)->guide))->set_line(1, reinterpret_cast<const char *>(&lbl_805DEF30));
    fn_802FF7EC(((TAdMultiConfirmGC_802FFA3C *)this));
}

#pragma pop
