#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/ui/TAdChrSelBSlotGC_8030E354.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdChrSelBSlotGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TAdPlyChrSelPlateGC.h"
#include "pso/ui/TAdChrSelSlotGC.h"

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

struct RecoveredGlobal_8030E6E0_lbl_804758E8 {
    s32 value;
    u8 remaining[0x1C];
};

struct G_8030E3BC { s32 a; s32 b; s32 c; f32 v[2]; };

struct S_8030E3BC { s32 x; s32 y; };

extern "C" {
u32 TAdChrSelASlotGC__sub_8030CB08(TAdChrSelASlotGC *arg0, s32 kind, s32 text);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_8030EBD0_lbl_8050E3B8 controller_physical_port_bank;
s32 push_plate_position__19TAdPlyChrSelPlateGCFv(int, void *);
s32 get_global_state__16TAdChrSelBSlotGCFv(void *);
extern RecoveredGlobal_8030E6E0_lbl_804758E8 lbl_804758E8;
extern G_8030E3BC chr_select_b_slot_entry;
G_8030E3BC *TAdChrSelBSlotGC__sub_8030E3BC(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern const CharacterSlotPosition lbl_80475908;
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
            set_entry_text__15TAdSubPlyItemGCFPvPv(*(void **)((s8 *)self + 0x30), TAdChrSelBSlotGC__sub_8030E3BC(slot, i, i, (u8 *)&lbl_804758E8.value + i * 8));
            if (is_slot_state_one__16TAdChrSelBSlotGCFlUl(slot, i)) {
                add_plate_rect__20TAdChrSelMovePlateGCFPvPv(self->m_34, (u8 *)&lbl_804758E8.value + i * 8);
            }
        }
        self->m_1c = 0x14;
    }
}

typedef char RecoveredGlobal_8030E6E0_lbl_804758E8_size[sizeof(RecoveredGlobal_8030E6E0_lbl_804758E8) == 0x20 ? 1 : -1];
void TAdChrSelBSlotGC::reset_plate_positions() {
    u8 *arg0 = (u8 *)this;
    if (get_global_state__16TAdChrSelBSlotGCFv(arg0) == 0x19) {
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, &lbl_804758E8.value);
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *) ((u8 *)&lbl_804758E8.value + 8));
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *) ((u8 *)&lbl_804758E8.value + 0x10));
        push_plate_position__19TAdPlyChrSelPlateGCFv(this->m_2c, (void *) ((u8 *)&lbl_804758E8.value + 0x18));
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
