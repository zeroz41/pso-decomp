#include "types.h"
#include "pso/misc/TQuestVmDownLoadServer_803E6970.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowKeyBoardBase.h"
#include "pso/misc/TWindowDD.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

struct RecoveredGlobal_8025E9E4_lbl_804CFA70 { s32 value; u8 remaining[0x10]; };
typedef char RecoveredGlobal_8025E9E4_lbl_804CFA70_size[sizeof(RecoveredGlobal_8025E9E4_lbl_804CFA70) == 0x14 ? 1 : -1];

struct RecoveredGlobal_8025E9E4___vt__19TWindowKeyBoardBase { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8025E9E4___vt__19TWindowKeyBoardBase_size[sizeof(RecoveredGlobal_8025E9E4___vt__19TWindowKeyBoardBase) == 0x18 ? 1 : -1];

extern "C" {
void *mem_alloc(u32 size);
u8 * get_window_layout_position(s32);
}
void init_keyboard_text_buffer(u8 *arg0, u32 arg1, u32 arg2);
extern "C" {
extern RecoveredGlobal_8025E9E4_lbl_804CFA70 TWindowKeyBoardBase__window_descriptor;
extern s32 __vt__19TWindowKeyBoardBase[];
extern s32 keyboard_base_type_name_pointer;
u8 *TWindowKeyBoardBase__ct(u8 *arg0);
s32 set_stream_and_load_file__6TLobbyFi(s32 *);
s32 Dolphin_ARAlloc(s32);
s32 TQuestVmDownLoadServer__sub_803F0C04(s32, s32, s32, s32, s32);
extern s32 lbl_8044F098[];
void *__dt__19TWindowKeyBoardBaseFv(void *arg0, s16 arg1);
s32 sub_8025CB10__19TWindowKeyBoardBaseFv(void *);
s32 sub_8025EB68__19TWindowKeyBoardBaseFv();
void __dl__7TObjectFPv(void *);
u32 *destroy__19TWindowKeyBoardBaseFPvs(u32 *arg0, s16 arg1);
void mem_free(void *);
int initialize_subwindow__9TWindowDDFv(void*);

void TWindowKeyBoardBase::render() {
    s32 temp_r31;

    if ((sub_8025EB68__19TWindowKeyBoardBaseFv() == 0) && ((sub_8025CB10__19TWindowKeyBoardBaseFv(this) != 0) || (this->m_62 & 2))) {
        temp_r31 = TWindowDD::draw_default_entry((s32)this);
        if (this->m_62 & 2) {
            draw_window_frame((void *)temp_r31);
        }
        sub_8025E6DC((u8 *)temp_r31);
    }
}

void TWindowKeyBoardBase::run_task() { initialize_subwindow__9TWindowDDFv(this); update_fade(); }

void *__dt__19TWindowKeyBoardBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowKeyBoardBase;
        mem_free(*(void **)((s8 *)arg0 + 0x9C));
        destroy__19TWindowKeyBoardBaseFPvs((u32 *)((s8 *)arg0 + 0x84), -1);
        destroy__19TWindowKeyBoardBaseFPvs((u32 *)((s8 *)arg0 + 0x6C), -1);
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowKeyBoardBase__ct(u8 *arg0) {
    s32 temp_r31;
    ((TWindowDD *)arg0)->construct_base((u8 *)&TWindowKeyBoardBase__window_descriptor.value, (s16)(4), (u8 *)(get_window_layout_position(0xB7)));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8025E9E4___vt__19TWindowKeyBoardBase *)&__vt__19TWindowKeyBoardBase).value;
    ((TWindowKeyBoardBase *)(arg0 + 0x6C))->init_text_buffer_holder();
    ((TWindowKeyBoardBase *)(arg0 + 0x84))->init_text_buffer_holder();
    *(s32 *)((s8 *)arg0 + 0) = (s32) keyboard_base_type_name_pointer;
    temp_r31 = current_language;
    ((TWindowKeyBoardBase *)arg0)->init_keyboard_text_field(0, 0);
    init_keyboard_text_buffer((arg0 + 0x84), 0, 0);
    *(u8 **)((s8 *)arg0 + 0x68) = (unsigned char *) (arg0 + 0x6C);
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_b4 = 0;
    *(s16 *)&((TWindowKeyBoardBase *)arg0)->m_62 = 0;
    *(s8 *)&((TWindowKeyBoardBase *)arg0)->m_65 = -1;
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_9c = 0;
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_a0 = 0;
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_a4 = 0;
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_a8 = 0;
    *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_ac = 0;
    if (temp_r31 == 0) {
        init_keyboard_text_buffer((arg0 + 0x84), 0x24, 0);
        *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_9c = (s32)mem_alloc((u32)((void *)0x194));
        *(s32 *)&((TWindowKeyBoardBase *)arg0)->m_b0 = 0x94;
    }
    return arg0;
}
void TLobby::load_ask_dictionary() {
    s32 data;
    s32 size;
    s32 aligned;
    s32 aram;
    size = ((TLobby *)lbl_8044F098)->get_resource_file_size();
    aligned = (size + 0x1F) & ~0x1F;
    aram = Dolphin_ARAlloc(aligned);
    data = set_stream_and_load_file__6TLobbyFi(lbl_8044F098);
    TLobby::aram_transfer_sync(3, data, aram, aligned);
    TAdSinglePlyChrSelectGC::safe_free(data);
    TQuestVmDownLoadServer__sub_803F0C04(aram, size, 3, 1, 0x2710);
    TQuestVmDownLoadServer__sub_803F09A4();
}
}
