#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC_8030E354.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdChrSelBSlotGC_8030ED88.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/frontend/TAdChrSelMovePlateGC.h"
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"

static const ChrSelPlateLayout chr_sel_b_slot_plate_layout = { 180.0f, 38.0f, { 0xBC, 0x98, 0x36, 0x00 }, 0 };
// Plate positions of the four entries
static const CharacterSlotPosition lbl_804758E8[4] = {
    { 434.0f, 182.0f }, { 434.0f, 225.0f }, { 434.0f, 268.0f }, { 434.0f, 311.0f },
};
static const CharacterSlotPosition lbl_80475908 = { 429.0f, 156.0f };
static const CharacterSlotPosition lbl_80475910 = { 441.0f, 117.0f };
const char *TAdChrSelBSlotGC__name = "TAdChrSelBSlotGC";

struct RecoveredGlobal_8030EBD0_lbl_8050E3B8
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredGlobal_8030ECB8_lbl_8050E3B8
{
  s32 value;
  u8 remaining[0x1AC];
};


struct G_8030E3BC { s32 a; s32 b; s32 c; f32 v[2]; };

struct S_8030E3BC { s32 x; s32 y; };

extern "C" {
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_8030EBD0_lbl_8050E3B8 controller_physical_port_bank;
s32 push_plate_position__19TAdPlyChrSelPlateGCFv(int, void *);
s32 get_global_state__16TAdChrSelBSlotGCFv(void *);
extern G_8030E3BC chr_select_b_slot_entry;
G_8030E3BC *TAdChrSelBSlotGC__sub_8030E3BC(s32 arg0, s32 arg1, s32 arg2, void *arg3);
void set_entry_text__15TAdSubPlyItemGCFPvPv(void *item, G_8030E3BC *entry);
void add_plate_rect__20TAdChrSelMovePlateGCFPvPv(void *plate, void *position);
void TAdChrSelBSlotGC__sub_8030E624(TAdChrSelBSlotGC *self);
s32 is_slot_value_ready__19TAdPlyChrSelPlateGCFl(s32 plate, s32 i);
s32 is_slot_state_one__16TAdChrSelBSlotGCFlUl(s32 arg0, u32 i);

void TAdChrSelBSlotGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

bool TAdChrSelBSlotGC::is_slot_state_one(s32 arg0, u32 i) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(TAdSinglePlyChrSelectGC__sub_801FE3E4(i));
    if (temp_r3 == 0) {
        return 0;
    }
    return *(s32 *)((s8 *)temp_r3 + 8) == 1;
}

G_8030E3BC *TAdChrSelBSlotGC__sub_8030E3BC(s32 arg0, s32 arg1, s32 i, void *arg3) {
    S_8030E3BC *e = (S_8030E3BC *)TAdSinglePlyChrSelectGC__sub_801FE3E4(i);
    chr_select_b_slot_entry.a = arg1;
    chr_select_b_slot_entry.b = e != NULL ? e->x : get_localized_text_entry(0x16, 0x1C);
    chr_select_b_slot_entry.c = e != NULL ? e->y + 1 : 0;
    ((TWindowSubSymbolChatPartsSet *)(chr_select_b_slot_entry.v))->copy_vec2(arg3);
    return &chr_select_b_slot_entry;
}

void TAdChrSelBSlotGC__sub_8030E458(void) {  }
void TAdChrSelBSlotGC::set_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        this->m_1c = 0x1D;
    }
}
void TAdChrSelBSlotGC::init() {
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
    this->m_1c = 0x1C;
}
void TAdChrSelBSlotGC::reset_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        this->m_1c = 0;
    }
}
void TAdChrSelBSlotGC::reset_slot_state() {
    if (get_global_state__16TAdChrSelBSlotGCFv(this) <= 0xD) {
        this->m_24 = 0;
        this->m_1c = 1;
    }
}
void TAdChrSelBSlotGC__sub_8030E550(void) {  }
void TAdChrSelBSlotGC::update_load_state() {
    if (TAdPlayerLoadGC::get_instance() == 0) {
        if ((u32) (TAdPlayerLoadGC::get_load_result((void *)1) + 0x10000) == 0xFF83U) {
            this->m_1c = 0x18;
            return;
        }
        this->m_1c = 0x19;
    }
}
void TAdChrSelBSlotGC::set_state_confirm() {
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
    this->m_1c = 0x1A;
}
void TAdChrSelBSlotGC::enter_state17() {
    encrypt_and_save__23TAdSinglePlyChrSelectGCFv();
    open_confirm_window__23TAdSinglePlyChrSelectGCFv();
    this->m_1c = 0x17;
}
void TAdChrSelBSlotGC__sub_8030E620(void) {  }

void TAdChrSelBSlotGC__sub_8030E624(TAdChrSelBSlotGC *self) {
    u32 i;
    s32 slot;

    if (is_slot_value_ready__19TAdPlyChrSelPlateGCFl(self->m_2c, 2)) {
        ((TAdChrSelSlotGC *)*(void **)((s8 *)self + 0x28))->init_slot_entry(2, (void *)&lbl_80475908);
        slot = (s32)self;
        for (i = 0; i < 4; i++) {
            set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)self + 0x30), TAdChrSelBSlotGC__sub_8030E3BC(slot, i, i, (void *)&lbl_804758E8[i]));
            if (is_slot_state_one__16TAdChrSelBSlotGCFlUl(slot, i)) {
                add_plate_rect__20TAdChrSelMovePlateGCFPvPv(self->m_34, (void *)&lbl_804758E8[i]);
            }
        }
        self->m_1c = 0x14;
    }
}

void TAdChrSelBSlotGC::reset_plate_positions() {
    u8 *arg0 = (u8 *)this;
    if (get_global_state__16TAdChrSelBSlotGCFv(arg0) == 0x19) {
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *)&lbl_804758E8[0]);
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *)&lbl_804758E8[1]);
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *)&lbl_804758E8[2]);
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *)&lbl_804758E8[3]);
        this->m_1c = 0x13;
    }
}

void TAdChrSelBSlotGC__sub_8030E768(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x18) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x64)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0x12;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0x13);
    }
}
void TAdChrSelBSlotGC__sub_8030E824(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x17) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x68)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0x11;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0x15);
    }
}
void TAdChrSelBSlotGC__sub_8030E8E0(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x15) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x60)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0x10;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0x11);
    }
}
void TAdChrSelBSlotGC__sub_8030E99C(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x14) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x5C)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xF;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xF;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0xF);
    }
}
void TAdChrSelBSlotGC__sub_8030EA58(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x13) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x58)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xE;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xF;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0xD);
    }
}
void TAdChrSelBSlotGC__sub_8030EB14(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x12) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x54)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xD;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xF;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 0xB);
    }
}
typedef struct RecoveredGlobal_8030EBD0_lbl_8050E3B8 RecoveredGlobal_8030EBD0_lbl_8050E3B8;
typedef char RecoveredGlobal_8030EBD0_lbl_8050E3B8_size[((sizeof(RecoveredGlobal_8030EBD0_lbl_8050E3B8)) == 0x1B0) ? (1) : (-1)];
void TAdChrSelBSlotGC__sub_8030EBD0(u8 *arg0) {
  u32 temp_r3;
  u32 temp_r3_2;
  u8 *temp_r31;
  temp_r3 = *((u32 *) (((s8 *) arg0) + 0x70));
  if (temp_r3 != 0U)
  {
    ((TWindowSubComCard *)temp_r3)->close();
    *((u32 *) (((s8 *) arg0) + 0x70)) = 0U;
  }
  temp_r31 = ((u8 *)&controller_physical_port_bank.value) + (((TAdMultiPlyChrSelectGC *)((int) TAdMultiPlyChrSelectGC::get_state()))->get_state_result() * 0x50);
  temp_r31 = temp_r31 + 0x20;
  if ((((TWindowShortListCtrl__check_controller_button((int) temp_r31, 4) != 0) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 2) != 0)) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 0x400) != 0)) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 0x200) != 0))
  {
    *((s32 *) (((s8 *) arg0) + 0x1C)) = 1;
    return;
  }
  if (get_global_state__16TAdChrSelBSlotGCFv((void *)((void *) arg0)) < 0xC)
  {
    temp_r3_2 = *((u32 *) (((s8 *) arg0) + 0x40));
    if (temp_r3_2 != 0U)
    {
      ((TWindowBase *)((int) temp_r3_2))->close();
      *((u32 *) (((s8 *) arg0) + 0x40)) = 0U;
    }
    *((s32 *) (((s8 *) arg0) + 0x1C)) = 1;
  }
}
typedef struct RecoveredGlobal_8030ECB8_lbl_8050E3B8 RecoveredGlobal_8030ECB8_lbl_8050E3B8;
typedef char RecoveredGlobal_8030ECB8_lbl_8050E3B8_size[((sizeof(RecoveredGlobal_8030ECB8_lbl_8050E3B8)) == 0x1B0) ? (1) : (-1)];
void TAdChrSelBSlotGC::check_cancel_and_close() {
    u8 *arg0 = (u8 *)this;
  u32 temp_r3;
  s32 new_var;
  u8 *temp_r31;
  new_var = ((TAdMultiPlyChrSelectGC *)((int) TAdMultiPlyChrSelectGC::get_state()))->get_state_result();
  temp_r31 = (((u8 *) (&(*(RecoveredGlobal_8030ECB8_lbl_8050E3B8 *)&controller_physical_port_bank).value)) + (new_var * 0x50)) + 0x20;
  if ((((TWindowShortListCtrl__check_controller_button((int) temp_r31, 4) != 0) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 2) != 0)) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 0x400) != 0)) || (TWindowShortListCtrl__check_controller_button((int) temp_r31, 0x200) != 0))
  {
    this->m_1c = 1;
    return;
  }
  if (get_global_state__16TAdChrSelBSlotGCFv((void *)((void *) arg0)) < 0xC)
  {
    temp_r3 = *((u32 *) (((s8 *) arg0) + 0x40));
    if (temp_r3 != 0U)
    {
      ((TWindowBase *)((int) temp_r3))->close();
      *((u32 *) (((s8 *) arg0) + 0x40)) = 0U;
    }
    this->m_1c = 1;
  }
}

}

G_8030E3BC chr_select_b_slot_entry;

extern "C" {
s32 get_state_result__22TAdMultiPlyChrSelectGCFv();
s32 get_global_state__16TAdChrSelBSlotGCFv(void *);
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
s32 TAdChrSelASlotGC__sub_8030C4F8(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C5C0(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelASlotGC__sub_8030C688(TAdChrSelASlotGC *self, s32 kind);
s32 TAdChrSelSlotGC__sub_802C7498(s32, s32);
u32 create_draw_line_ctrl__13TAdMcSelectGCFiif(void *, s32, f32);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 TAdPlayerLoadGC__sub_801E24F8(s32, s32, s32, s32, s32);
s32 TAdSubPlyItemGC__sub_802D6D88(s32);

void update_slot_state__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if ((u32) (TAdPlayerLoadGC__sub_801E1B50(1) + 0x10000) != 0xFFFFU) {
        if ((((TAdPlayerLoadGC *)1)->check_card_result_code() != 0) && (TAdPlayerLoadGC__sub_801E1B50(1) == 0)) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 = TAdChrSelASlotGC__sub_8030C688((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xA;
            return;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = TAdChrSelASlotGC__sub_8030C4F8((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xB;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
    }
}

void update_card_select__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {

    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if (((TWindowMessageYesNo *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->get_slot_or_neg1()) {
        case 1:
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        case 0:
            if (TAdPlayerLoadGC__sub_801E24F8(1, 0, 0, 0, 0) == 0) {
                ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 9;
                return;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = TAdChrSelASlotGC__sub_8030C4F8((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xB;
            return;
        }
    } else {
        if (((TWindowSubComCard *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->get_card_data() != 0) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        }
        if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
            if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        }
    }
}

void TAdChrSelBSlotGC__sub_8030EF74(void *ad_chr_sel_b_slot_gc) {
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) = TAdChrSelASlotGC__sub_8030C5C0((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1);
    }
}

void update_card_confirm__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    s32 var_r31;

    if (((TWindowMessageYesNo *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->is_child_visible() != 0) {
        switch (((TWindowSubComCard *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->get_slot_or_neg1()) {
        case 1:
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        case 0:
            if (((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
                if (TAdMultiPlyChrSelectGC::get_state() != 0U) {
                    TAdMultiPlyChrSelectGC::get_state();
                    var_r31 = get_state_result__22TAdMultiPlyChrSelectGCFv();
                } else {
                    var_r31 = 0;
                }
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = ((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()))->open_confirm_message(1, var_r31);
                ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 8;
                return;
            }
            break;
        }
    } else {
        if (((TWindowSubComCard *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c))->get_card_data() != 0) {
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 7;
            return;
        }
        if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
            if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
                *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
            }
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        }
    }
}

void TAdChrSelBSlotGC__sub_8030F13C(u8 *ad_chr_sel_b_slot_gc) {
    s32 var_r31;
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x11) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x50)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 0xC;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c == 0U) && (TAdChrSelBSlotGC::get_global_slot_data() != 0U)) {
        if (TAdMultiPlyChrSelectGC::get_state() != 0U) {
            TAdMultiPlyChrSelectGC::get_state();
            var_r31 = get_state_result__22TAdMultiPlyChrSelectGCFv();
        } else {
            var_r31 = 0;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = ((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()))->create_message_window(1, var_r31);
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 6;
    }
}

void TAdChrSelBSlotGC__sub_8030F228(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0x10) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x4C)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 5;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 7);
    }
}

void TAdChrSelBSlotGC__sub_8030F2E4(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xF) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x48)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 4;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 5);
    }
}

void TAdChrSelBSlotGC__sub_8030F3A0(u8 *ad_chr_sel_b_slot_gc) {
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xE) {
        if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x44)))->close();
            ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 3;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)((void *)(((s32)TAdChrSelBSlotGC::get_global_slot_data()))), 1, 3);
    }
}

void close_windows__16TAdChrSelBSlotGCFPv(void *ad_chr_sel_b_slot_gc) {
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x44)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_44 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x48)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x48) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x4C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_4c = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x6C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x70)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x70) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x74)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_74 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x78)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x78) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x7C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_7c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x50)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x50) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x54)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_54 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x58)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x58) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x5C)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_5c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x60)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x60) = 0U;
    }
    if ((u32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x64)))->close();
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_64 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x68)))->close();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x68) = 0U;
    }
    ((TAdPlyChrSelPlateGC *)(((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_2c))->reset_selection_slots();
    TAdSubPlyItemGC__sub_802D6D88(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x30));
    ((TAdChrSelMovePlateGC *)(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x34)))->clear_entries();
    TAdChrSelSlotGC__sub_802C7498(*(s32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x28), 2);
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) > 0xD) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 2;
        return;
    }
    if (get_global_state__16TAdChrSelBSlotGCFv(ad_chr_sel_b_slot_gc) < 0xC) {
        if ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)ad_chr_sel_b_slot_gc + 0x40)))->close();
            *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = 0U;
        }
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 = 0;
        ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_1c = 1;
        return;
    }
    if (((s32) ((TAdChrSelBSlotGC *)ad_chr_sel_b_slot_gc)->m_24 > 0xA) && ((u32) *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) == 0U)) {
        TAdChrSelBSlotGC::get_global_slot_data();
        *(u32 *)((s8 *)ad_chr_sel_b_slot_gc + 0x40) = TAdChrSelASlotGC__sub_8030CB08((TAdChrSelASlotGC *)(TAdChrSelBSlotGC::get_global_slot_data()), 1, 1);
    }
}


void reset_windows__16TAdChrSelBSlotGCFPv(void *ad_mc_select_gc) {
    ((TAdChrSelSlotGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_28))->reset_all_slots();
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x38) != 0U) {
        ((TObject *)(*(void **)((s8 *)ad_mc_select_gc + 0x38)))->queue_destruction();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) != 0U) {
        ((TObject *)(*(void **)((s8 *)ad_mc_select_gc + 0x3C)))->queue_destruction();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x40) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x40)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x40) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x44) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x44)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x44) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x48) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x48)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x48) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x4C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x4C)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x4C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x50) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x50)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x50) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x54) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x54)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x54) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x58) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x58)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x58) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x5C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x5C)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x5C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x60) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x60)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x60) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x64) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x64)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x64) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)ad_mc_select_gc + 0x68) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)ad_mc_select_gc + 0x68)))->close();
        *(u32 *)((s8 *)ad_mc_select_gc + 0x68) = 0U;
    }
    ((TAdPlyChrSelPlateGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_2c))->reset_selection_slots();
    TAdSubPlyItemGC__sub_802D6D88(((TAdMcSelectGC *)ad_mc_select_gc)->m_30);
    ((TAdMcSelectGC *)(((TAdMcSelectGC *)ad_mc_select_gc)->m_28))->init_slot(1, (void *)&lbl_80475910);
    *(u32 *)((s8 *)ad_mc_select_gc + 0x38) = create_draw_line_ctrl__13TAdMcSelectGCFiif(ad_mc_select_gc, 0xE, 0.0f);
    *(u32 *)((s8 *)ad_mc_select_gc + 0x3C) = create_draw_line_ctrl__13TAdMcSelectGCFiif(ad_mc_select_gc, 0x15, 0.0f);
    ((TAdMcSelectGC *)ad_mc_select_gc)->m_24 = -1;
    ((TAdMcSelectGC *)ad_mc_select_gc)->m_1c = 1;
}

struct C_8030F874 {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
    s32 f24;
};
typedef void (C_8030F874::*Pmf_8030F874)();

extern "C" void TAdChrSelBSlotGC__sub_8030E624(TAdChrSelBSlotGC *self);
extern "C" void reset_plate_positions__16TAdChrSelBSlotGCFv();
extern "C" void check_cancel_and_close__16TAdChrSelBSlotGCFv();
extern "C" void enter_state17__16TAdChrSelBSlotGCFv();
extern "C" void init__16TAdChrSelBSlotGCFv();
extern "C" void reset_load_state__16TAdChrSelBSlotGCFv();
extern "C" void reset_slot_state__16TAdChrSelBSlotGCFv();
extern "C" void set_load_state__16TAdChrSelBSlotGCFv();
extern "C" void set_state_confirm__16TAdChrSelBSlotGCFv();
extern "C" void update_load_state__16TAdChrSelBSlotGCFv();
void *lbl_804E7A48[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_windows__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A54[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_windows__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A60[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F3A0,
};
void *lbl_804E7A6C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F2E4,
};
void *lbl_804E7A78[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F228,
};
void *lbl_804E7A84[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030F13C,
};
void *lbl_804E7A90[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_confirm__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7A9C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EF74,
};
void *lbl_804E7AA8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7AB4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_slot_state__16TAdChrSelBSlotGCFPv,
};
void *lbl_804E7AC0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&check_cancel_and_close__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7ACC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EBD0,
};
void *lbl_804E7AD8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EB14,
};
void *lbl_804E7AE4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030EA58,
};
void *lbl_804E7AF0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E99C,
};
void *lbl_804E7AFC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E8E0,
};
void *lbl_804E7B08[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E824,
};
void *lbl_804E7B14[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E768,
};
void *lbl_804E7B20[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_plate_positions__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B2C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E624,
};
void *lbl_804E7B38[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E620,
};
void *lbl_804E7B44[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&enter_state17__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B50[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_state_confirm__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B5C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B68[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E550,
};
void *lbl_804E7B74[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_slot_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B80[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B8C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&init__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7B98[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&set_load_state__16TAdChrSelBSlotGCFv,
};
void *lbl_804E7BA4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdChrSelBSlotGC__sub_8030E458,
};
void *lbl_804E7BB0[90] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

int TAdChrSelBSlotGC__global_state;

void run_task__16TAdChrSelBSlotGCFv(C_8030F874 *self) {
    static s8 init;
    if (self->f1C < 0 || self->f1C >= 30) {
        self->f1C = 1;
    }
    self->f20 = self->f1C;
    if (get_global_state__16TAdChrSelBSlotGCFv(self) <= 0xD && self->f1C > 1) {
        self->f1C = 1;
    }
    if (!init) {
        ((Pmf_8030F874 *)lbl_804E7BB0)[0] = *(Pmf_8030F874 *)lbl_804E7A48;
        ((Pmf_8030F874 *)lbl_804E7BB0)[1] = *(Pmf_8030F874 *)lbl_804E7A54;
        ((Pmf_8030F874 *)lbl_804E7BB0)[2] = *(Pmf_8030F874 *)lbl_804E7A60;
        ((Pmf_8030F874 *)lbl_804E7BB0)[3] = *(Pmf_8030F874 *)lbl_804E7A6C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[4] = *(Pmf_8030F874 *)lbl_804E7A78;
        ((Pmf_8030F874 *)lbl_804E7BB0)[5] = *(Pmf_8030F874 *)lbl_804E7A84;
        ((Pmf_8030F874 *)lbl_804E7BB0)[6] = *(Pmf_8030F874 *)lbl_804E7A90;
        ((Pmf_8030F874 *)lbl_804E7BB0)[7] = *(Pmf_8030F874 *)lbl_804E7A9C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[8] = *(Pmf_8030F874 *)lbl_804E7AA8;
        ((Pmf_8030F874 *)lbl_804E7BB0)[9] = *(Pmf_8030F874 *)lbl_804E7AB4;
        ((Pmf_8030F874 *)lbl_804E7BB0)[10] = *(Pmf_8030F874 *)lbl_804E7AC0;
        ((Pmf_8030F874 *)lbl_804E7BB0)[11] = *(Pmf_8030F874 *)lbl_804E7ACC;
        ((Pmf_8030F874 *)lbl_804E7BB0)[12] = *(Pmf_8030F874 *)lbl_804E7AD8;
        ((Pmf_8030F874 *)lbl_804E7BB0)[13] = *(Pmf_8030F874 *)lbl_804E7AE4;
        ((Pmf_8030F874 *)lbl_804E7BB0)[14] = *(Pmf_8030F874 *)lbl_804E7AF0;
        ((Pmf_8030F874 *)lbl_804E7BB0)[15] = *(Pmf_8030F874 *)lbl_804E7AFC;
        ((Pmf_8030F874 *)lbl_804E7BB0)[16] = *(Pmf_8030F874 *)lbl_804E7B08;
        ((Pmf_8030F874 *)lbl_804E7BB0)[17] = *(Pmf_8030F874 *)lbl_804E7B14;
        ((Pmf_8030F874 *)lbl_804E7BB0)[18] = *(Pmf_8030F874 *)lbl_804E7B20;
        ((Pmf_8030F874 *)lbl_804E7BB0)[19] = *(Pmf_8030F874 *)lbl_804E7B2C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[20] = *(Pmf_8030F874 *)lbl_804E7B38;
        ((Pmf_8030F874 *)lbl_804E7BB0)[21] = *(Pmf_8030F874 *)lbl_804E7B44;
        ((Pmf_8030F874 *)lbl_804E7BB0)[22] = *(Pmf_8030F874 *)lbl_804E7B50;
        ((Pmf_8030F874 *)lbl_804E7BB0)[23] = *(Pmf_8030F874 *)lbl_804E7B5C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[24] = *(Pmf_8030F874 *)lbl_804E7B68;
        ((Pmf_8030F874 *)lbl_804E7BB0)[25] = *(Pmf_8030F874 *)lbl_804E7B74;
        ((Pmf_8030F874 *)lbl_804E7BB0)[26] = *(Pmf_8030F874 *)lbl_804E7B80;
        ((Pmf_8030F874 *)lbl_804E7BB0)[27] = *(Pmf_8030F874 *)lbl_804E7B8C;
        ((Pmf_8030F874 *)lbl_804E7BB0)[28] = *(Pmf_8030F874 *)lbl_804E7B98;
        ((Pmf_8030F874 *)lbl_804E7BB0)[29] = *(Pmf_8030F874 *)lbl_804E7BA4;
        init = 1;
    }
    (self->*((Pmf_8030F874 *)lbl_804E7BB0)[self->f1C])();
    if (self->f1C != self->f20) {
        self->f24 = 0;
    }
    self->f24++;
}
}

extern "C" {

void *__ct__19TAdPlyChrSelPlateGCFv(void *, void *, void *);
void *__ct__20TAdChrSelMovePlateGCFv(void *, void *);
void *__nw__7TObjectFUl(int);


void TAdChrSelBSlotGC::create_children() {
    void *o;
    void *o2;
    void *o4;
    o = new TAdChrSelSlotGC(this);
    *(void * *)&this->unk_28 = o;
    o2 = __nw__7TObjectFUl(0x3B4);
    if (o2 != NULL) {
        o2 = __ct__19TAdPlyChrSelPlateGCFv(o2, this, (void *)&chr_sel_b_slot_plate_layout);
    }
    *(void * *)&this->m_2c = o2;
    this->player_items = new TAdSubPlyItemGC(this);
    o4 = __nw__7TObjectFUl(0x208);
    if (o4 != NULL) {
        o4 = __ct__20TAdChrSelMovePlateGCFv(o4, this);
    }
    this->m_34 = o4;
}

void TAdChrSelBSlotGC::sub_8030FE04() {
    this->m_1c = 0;
    this->m_20 = 0;
    this->m_24 = -1;
    *(s32 *)&this->unk_28 = 0;
    this->m_2c = 0;
    this->player_items = 0;
    this->m_34 = 0;
    *(s32 *)&this->unk_38 = 0;
    this->m_3c = 0;
    *(s32 *)&this->unk_40 = 0;
    this->m_44 = 0;
    *(s32 *)&this->unk_48 = 0;
    this->m_4c = 0;
    *(s32 *)&this->unk_50 = 0;
    this->m_54 = 0;
    *(s32 *)&this->unk_58 = 0;
    this->m_5c = 0;
    *(s32 *)&this->unk_60 = 0;
    this->m_64 = 0;
    *(s32 *)&this->unk_68 = 0;
    this->m_6c = 0;
    *(s32 *)&this->unk_70 = 0;
    this->m_74 = 0;
    *(s32 *)&this->unk_78 = 0;
    this->m_7c = 0;
}

}



TAdChrSelBSlotGC::~TAdChrSelBSlotGC() {
    if ((u32) *(u32 *)((s8 *)this + 0x40) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x40)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x40) = 0U;
    }
    if ((u32) this->m_44 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x44)))->queue_destruction();
        this->m_44 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x48) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x48)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x48) = 0U;
    }
    if ((u32) this->m_4c != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x4C)))->queue_destruction();
        this->m_4c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x50) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x50)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x50) = 0U;
    }
    if ((u32) this->m_54 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x54)))->queue_destruction();
        this->m_54 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x58) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x58)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x58) = 0U;
    }
    if ((u32) this->m_5c != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x5C)))->queue_destruction();
        this->m_5c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x60) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x60)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x60) = 0U;
    }
    if ((u32) this->m_64 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x64)))->queue_destruction();
        this->m_64 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x68) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x68)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x68) = 0U;
    }
    if ((u32) this->m_6c != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x6C)))->queue_destruction();
        this->m_6c = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x70)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x70) = 0U;
    }
    if ((u32) this->m_74 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x74)))->queue_destruction();
        this->m_74 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x78) != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x78)))->queue_destruction();
        *(u32 *)((s8 *)this + 0x78) = 0U;
    }
    if ((u32) this->m_7c != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0x7C)))->queue_destruction();
        this->m_7c = 0U;
    }
}

TAdChrSelBSlotGC::TAdChrSelBSlotGC(TObject *parent) : TObject(parent) {
    m_name = TAdChrSelBSlotGC__name;
    sub_8030FE04();
    create_children();
}

extern "C" {
s32 are_split_screen_battle_players_tied(void *);
extern s32 TLobby__battle_ctrl_default_value;

void *TAdChrSelBSlotGC::create(void *ad_chr_sel_b_slot_gc) {
    return new TAdChrSelBSlotGC((TObject *)ad_chr_sel_b_slot_gc);
}

    extern int TAdChrSelBSlotGC__global_state;
int TAdChrSelBSlotGC::get_global_state() {  return TAdChrSelBSlotGC__global_state; }

    extern int TAdChrSel__global_slot_data;
int TAdChrSelBSlotGC::get_global_slot_data() {  return TAdChrSel__global_slot_data; }
s32 TLobby::get_battle_ctrl_default() {
    return are_split_screen_battle_players_tied(this) != 0 ? 0 : TLobby__battle_ctrl_default_value;
}

}
