#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdMcCheckGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/ui/TAdChrSelASlotGC.h"

struct RecoveredGlobal_8033F1C4___vt__12TAdMcCheckGC {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __dt__7TObjectFv(void *, int);
s32 __dl__7TObjectFPv(void *);
extern s32 memcard_cursor_instance_table[];
extern s32 __vt__12TAdMcCheckGC[];
s32 GXSetTexCoordGen2(s32, s32, s32, s32, s32, s32);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, s32, s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
}

void set_tex_coord_gen2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    GXSetTexCoordGen2(arg0, arg1, arg2, arg3, 0, 0x7D);
}
void TLobby__sub_8033EE38(void* p) { *(s32*)((char*)p + 0x18) = 0; *(s32*)((char*)p + 0x1c) = 0; }
void TAdMcCheckGC::render() {  }

extern u8 lbl_804783B8[];
extern f32 lbl_805DFAD8;

s32 TAdMcCheckGC::create(s32 arg1) {
    s32 temp_r31;
    s32 temp_r5;

    temp_r5 = this->m_28 * 8;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(lbl_804783B8 + temp_r5, 1, temp_r5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0x16, arg1)), 0x20, 0);
    ((TAdChrSelASlotGC *)temp_r31)->set_flag_40();
    TQuestThread::set_status_flag_80((void *)temp_r31);
    ((TWindowSubComCard *)temp_r31)->calc_layout_height(lbl_805DFAD8);
    return temp_r31;
}

void TAdMcCheckGC::run_task() {

    if (TAdPlayerLoadGC::probe_card_slot(this->m_28) == 0) {
        this->m_1c = 0;
        if ((u32) this->m_2c != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_2c);
            this->m_2c = 0U;
        }
        if ((u32) this->m_34 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_34);
            this->m_34 = 0U;
        }
        if ((u32) this->m_30 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_30);
            this->m_30 = 0U;
        }
        if ((u32) this->m_38 != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_38);
            this->m_38 = 0U;
        }
    }
    switch (this->m_1c) {
    case 0:
        if (TAdPlayerLoadGC::probe_card_slot(this->m_28) != 0) {
            this->m_1c = 1;
        }
        break;
    case 1:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->m_28) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result((void *)this->m_28) + 0x10000) == 0xFF83U)) {
            if (((s32) this->m_24 > 0xA) && ((u32) this->m_2c == 0U)) {
                this->m_2c = create(this->m_28 + 2);
            }
        } else {
            this->m_1c = 2;
            if ((u32) this->m_2c != 0U) {
                queue_destruction__7TObjectFv(*(void * *)&this->m_2c);
                this->m_2c = 0U;
            }
        }
        break;
    case 2:
        if ((TAdPlayerLoadGC::probe_and_check_card(this->m_28) == 0) && ((u32) (TAdPlayerLoadGC::get_load_result((void *)this->m_28) + 0x10000) == 0xFF21U)) {
            if (((s32) this->m_24 > 0xA) && ((u32) this->m_30 == 0U)) {
                this->m_30 = create(this->m_28 + 4);
            }
        } else {
            this->m_1c = 3;
            if ((u32) this->m_30 != 0U) {
                queue_destruction__7TObjectFv(*(void * *)&this->m_30);
                this->m_30 = 0U;
            }
        }
        break;
    case 3:
        if (TAdPlayerLoadGC::probe_and_check_card(this->m_28) != 0) {
            if ((s32) this->m_28 == 1) {
                this->m_1c = 5;
            } else {
                this->m_1c = 4;
            }
            if ((u32) this->m_34 != 0U) {
                queue_destruction__7TObjectFv(*(void * *)&this->m_34);
                this->m_34 = 0U;
            }
        } else if (((s32) this->m_24 > 0xA) && ((u32) this->m_34 == 0U)) {
            this->m_34 = create(this->m_28 + 6);
        }
        break;
    case 4:
        if (TAdPlayerLoadGC::check_memcard_status(this->m_28) == 0) {
            this->m_1c = 5;
            if ((u32) this->m_38 != 0U) {
                queue_destruction__7TObjectFv(*(void * *)&this->m_38);
                this->m_38 = 0U;
            }
        } else if (((s32) this->m_24 > 0xA) && ((u32) this->m_38 == 0U)) {
            this->m_38 = create(this->m_28 + 8);
        }
        break;
    case 5:
        break;
    }
    if ((s32) this->m_20 != (s32) this->m_1c) {
        this->m_24 = 0;
    } else {
        this->m_24 = (this->m_24 + 1);
    }
    this->m_20 = (s32) this->m_1c;
}

extern void *TAdMcCheckGC__name;

typedef char RecoveredGlobal_8033F1C4___vt__12TAdMcCheckGC_size[sizeof(RecoveredGlobal_8033F1C4___vt__12TAdMcCheckGC) == 0x18 ? 1 : -1];
u8 *__dt__12TAdMcCheckGCFv(TAdMcCheckGC *arg0, s16 arg1) {
    s32 temp_r4;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8033F1C4___vt__12TAdMcCheckGC *)&__vt__12TAdMcCheckGC).value;
        temp_r4 = arg0->m_28 * 4;
        if ((u32) *(u32 *)((s8 *)((u8 *)memcard_cursor_instance_table + temp_r4) + 0) != 0U) {
            *(s32 *)((s8 *)((u8 *)memcard_cursor_instance_table + temp_r4) + 0) = 0;
        }
        if ((u32) arg0->m_2c != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x2C));
            arg0->m_2c = 0U;
        }
        if ((u32) arg0->m_30 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x30));
            arg0->m_30 = 0U;
        }
        if ((u32) arg0->m_34 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x34));
            arg0->m_34 = 0U;
        }
        if ((u32) arg0->m_38 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x38));
            arg0->m_38 = 0U;
        }
        __dt__7TObjectFv((void *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((void *)arg0);
        }
    }
    return (u8 *)arg0;
}
TAdMcCheckGC::TAdMcCheckGC(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TAdMcCheckGC__name;
    *(void **)((s8 *)this + 0x28) = arg2;
    this->m_1c = 0;
    *(void **)((s8 *)this + 0x20) = *(void **)((s8 *)this + 0x1C);
    this->m_24 = 0;
    this->m_2c = 0;
    this->m_30 = 0;
    this->m_34 = 0;
    this->m_38 = 0;
}
