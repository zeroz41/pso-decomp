#include "types.h"
#include "pso/misc/TWindowSubQuestBoard.h"
#include "pso/quest/TQuestThread.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubQuestBoard_8027D148.h"
#include "pso/misc/TWindowSubQuestBoard_8027D1E8.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubQuestBoardSelect.h"
#include "pso/misc/TUnk_804D1818.h"

#include "pso/TObject.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubMagPhoton.h"

struct RecoveredGlobal_8027CE74_lbl_804D1818 {
    s32 value;
    u8 remaining[0x14];
};

struct VB_8027CCCC { u8 pad[0x18]; };

struct VO_8027CCCC : VB_8027CCCC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
};

struct VB_8027CFC8 { u8 pad[0x18]; };

struct VO_8027CFC8 : VB_8027CFC8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
};

struct Ent_8027CFC8 { u8 pad[0x20]; s32 f20; };

extern "C" {
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__19TWindowSubQuestBoard[];
s32 get_selected_menu_value(s32);
s8 get_page_index__20TWindowSubQuestBoardFv(s32);
s32 fn_8027D1E8(s32);
extern Ent_8027CFC8 quest_board_handlers[];
int set_card_window_flags__19TWindowKeyBoardHardFPvll(void*, int, int);

void TUnk_804D1818::render() {  }

void TUnk_804D1818::run_task() {
    s32 t;
    switch ((s8) *(u8 *)((s8 *)this + 0x1C)) {
    case 0:
    case 1:
        if (this->m_2c != 0U) {
            TWindow__close((u8 *)(*(void * *)&this->m_2c));
            this->m_2c = 0U;
        }
        ((TWindowSubComCard *)(*(s32 *)&this->unk_28))->clear_flag_and_release();
        *(u8 *)((s8 *)this + 0x1C) = 2;
    case 2:
        if (((TWindowSubComCard *)(*(s32 *)&this->unk_28))->get_status_flag() != 0) {
            (*(VO_8027CCCC * *)&this->m_24)->m7();
            *(u8 *)((s8 *)this + 0x1C) = 5;
            break;
        }
        if (((TWindowMenu *)(*(s32 *)&this->unk_28))->is_visible() != 0) {
            *(u8 *)((s8 *)this + 0x1C) = 3;
        }
        break;
    case 3:
        t = get_selected_menu_value(*(s32 *)&this->unk_28);
        this->m_2c = sub_8027C884(t);
        *(u8 *)((s8 *)this + 0x1C) = 4;
    case 4:
        this->update_photon_selection();
        update_quest_board_card_flags();
        if (((TLobby *)(this->m_2c))->get_flag_bit2() != 0) {
            *(u8 *)((s8 *)this + 0x1C) = 1;
        }
        break;
    }
}

void *TUnk_804D1818::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__19TWindowSubQuestBoard;
        if (this->m_2c != NULL) { TWindow__close((u8 *)this->m_2c); this->m_2c = 0; }
        if (*(void * *)&(this->unk_28) != NULL) { TWindow__close((u8 *)(*(void * *)&(this->unk_28))); *(s32 *)&(this->unk_28) = 0; }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

typedef char RecoveredGlobal_8027CE74_lbl_804D1818_size[sizeof(RecoveredGlobal_8027CE74_lbl_804D1818) == 0x18 ? 1 : -1];
u8 *TWindowSubQuestBoard__sub_8027CE74(u8 *arg0, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8027CE74_lbl_804D1818 *)&__vt__19TWindowSubQuestBoard).value;
    ((TUnk_804D1818 *)arg0)->m_24 = arg1;
    ((TUnk_804D1818 *)arg0)->m_20 = arg2;
    *(s32 *)((s8 *)arg0 + 0x28) = ((TUnk_804D1818 *)arg0)->create_option_menu_window();
    ((TUnk_804D1818 *)arg0)->m_2c = 0;
    *(s8 *)&((TUnk_804D1818 *)arg0)->unk_1C = 0;
    return arg0;
}

void TWindowSubQuestBoard::set_board_flags(s32 arg1) {
    s32 arg0 = (s32)this;
    set_card_window_flags__19TWindowKeyBoardHardFPvll((void*)arg0, arg1 << 0xA, -0x1C01);
}
void TWindowSubQuestBoard::set_card_window_flags(s32 arg1) {
    s32 arg0 = (s32)this;
    set_card_window_flags__19TWindowKeyBoardHardFPvll((void*)arg0, arg1 << 8, -0x301);
}
void TWindowSubQuestBoard::clear_card_window_flags(s32 arg1) {
    s32 arg0 = (s32)this;
    set_card_window_flags__19TWindowKeyBoardHardFPvll((void*)arg0, arg1 * 8, -9);
}
void TWindowSubQuestBoard__sub_8027CF50(s32 arg0, s32 arg1) {
    set_card_window_flags__19TWindowKeyBoardHardFPvll((void*)arg0, arg1 * 4, -5);
}
void TWindowSubQuestBoard::set_card_flags_scaled(s32 arg1) {
    s32 arg0 = (s32)this;
    set_card_window_flags__19TWindowKeyBoardHardFPvll((void*)arg0, arg1 * 2, -3);
}
int TWindowSubQuestBoard::set_card_flags_direct(int a1) { return set_card_window_flags__19TWindowKeyBoardHardFPvll(this, a1, -2); }
void TWindowSubQuestBoard::render() {  }

void TWindowSubQuestBoard::run_task() {
    switch (this->m_1c) {
    case 0:
    case 1:
        fn_8027D1E8(this->m_28);
        this->m_1c = 2;
    case 2:
        if (TWindowSubQuestBoard__sub_8027D1DC((void *)this->m_28) != 0) {
            (*(VO_8027CFC8 * *)&this->m_24)->m7();
            this->m_1c = 5;
            break;
        }
        if (((TWindowSubQuestBoardSelect *)(this->m_28))->is_open() != 0) {
            this->m_1c = 3;
        }
        break;
    case 3:
        this->quest_thread_board = TQuestThreadBoard::create_instance(
            quest_board_handlers[get_page_index__20TWindowSubQuestBoardFv(this->m_28)].f20);
        this->m_1c = 4;
    case 4:
        if (this->quest_thread_board->all_parents_unqueued_for_destruction() == 0) {
            this->quest_thread_board = NULL;
            this->m_1c = 1;
        }
        break;
    case 5:
        break;
    }
}

}
TWindowSubQuestBoard::~TWindowSubQuestBoard() {
    TWindowCtrl__sub_8027D1F8();
    if (*(void **)((s8 *)this + 0x28) != NULL) { TWindow__close((u8 *)(*(void **)((s8 *)this + 0x28))); this->m_28 = 0; }
}
