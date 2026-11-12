#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/font/TUnk_8049CA54.h"
#include "pso/ui/window/TWindowCtrlMain_800FC91C.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/unk/text_800FCC78.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/task/TObject.h"

struct VBase_18_7b3651 { char pad[0x18]; };

struct VObj_18_7b3651 : VBase_18_7b3651 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 * m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual s32 m14();
};

typedef struct Ent_800FC968 { u8 pad0[4]; char name[0x100]; u16 a; u8 pad106[6]; u16 b; u8 pad10E[0x11C - 0x10E]; } Ent_800FC968;

extern "C" {
s32 get_shared_text_buffer(void);
char *TWindowSubStatusDisp__sub_80071820(char *);
s32 get_card_status_bits__20TWindowShortListCtrlFv();
s32 TObjPlayer__sub_801AFD8C(void *);
VObj_18_7b3651 *get_player_by_client_id(s32);
void TWindowSubStatusDisp__sub_80228F5C(s32);
void text_builder_append(void *);
}
void append_text_space(void);
void append_padded_number(s32 v, u8 n);
void text_builder_reset(void);
extern char lbl_805DA9E0[];
extern char lbl_805DA9E4[];
extern char lbl_805DA9E8[];
extern char lbl_805DA9EC[];
extern char lbl_805DA9F0[];
char *status_text_label_table[5] = { lbl_805DA9E0, lbl_805DA9E4, lbl_805DA9E8, lbl_805DA9EC, lbl_805DA9F0 };
extern Ent_800FC968 lobby_player_status_records[];
extern char lbl_805DA9F4[4];
extern char lbl_805DA9F8[4];
extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__14TFontSmallHelpFv(void *, int);
void *__nw__7TObjectFUl(int);
s32 get_status_index_or_default__20TWindowSubStatusDispFPUs(void *, s32);
s32 run_task__14TFontSmallHelpFv(void *);

    extern int TWindowCtrlMain__instance;
int TWindowCtrlMain::get_instance() {  return TWindowCtrlMain__instance; }

void TWindowCtrlMain::advance_card_status(s32 arg0) {
    s32 var_r4;

    var_r4 = get_card_status_bits__20TWindowShortListCtrlFv() + 1;
    if (var_r4 >= 5) {
        var_r4 = 0;
    }
    fn_800FCCC8(arg0, var_r4);
}
s32 TWindowSubStatusDisp::build_status_text(s32 arg0) {
    s32 mode;
    s32 *name;
    u8 *info;
    s32 idx;
    s32 lvl;
    VObj_18_7b3651 *p;
    mode = get_card_status_bits__20TWindowShortListCtrlFv();
    p = get_player_by_client_id(arg0);
    if (p == NULL) {
        return 0;
    }
    info = (u8 *)p + 0x85C;
    if (info == NULL) {
        return 0;
    }
    name = p->m10();
    idx = TObjPlayer__sub_801AFD8C(p);
    lvl = p->m14();
    text_builder_reset();
    switch (mode) {
    case 0:
        text_builder_append(name);
        break;
    case 1:
        text_builder_append(name);
        append_text_space();
        text_builder_append(status_text_label_table[idx]);
        append_padded_number(lvl + 1, 3);
        break;
    case 2:
        if ((s8)info[0x33] < 2) {
            return 0;
        }
        text_builder_append(lbl_805DA9F4);
        TWindowSubStatusDisp__sub_80228F5C(lobby_player_status_records[arg0].a);
        text_builder_append(lbl_805DA9F8);
        TWindowSubStatusDisp__sub_80228F5C(lobby_player_status_records[arg0].b);
        break;
    case 3:
        if ((s8)info[0x33] < 2) {
            return 0;
        }
        text_builder_append(TWindowSubStatusDisp__sub_80071820(lobby_player_status_records[arg0].name));
        break;
    case 4:
        return 0;
    }
    return get_shared_text_buffer();
}

void *TFontSmallLobby::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        o = fn_800FCC78((u8 *)o, (s32)arg0);
    }
    return o;
}

void TUnk_8049CA54::run_task() {
    s32 temp_r3_2;
    s32 temp_r4;
    u32 temp_r3_3;
    s32 temp_r3;

    temp_r3 = (s32)get_player_by_client_id(*(s32 *)&this->player_id);
    if (temp_r3 == 0) {
        queue_destruction();
        return;
    }
    temp_r3_2 = ((s32 (*)(s32))get_card_status_bits__20TWindowShortListCtrlFv)(*(s32 *)&this->player_id);
    if ((s32) *(s32 *)&this->unk_60 != temp_r3_2) {
        *(s32 *)&this->unk_60 = temp_r3_2;
        temp_r3_3 = (u32)TWindowSubStatusDisp::build_status_text(*(s32 *)&this->player_id);
        set_help_text((const char *)temp_r3_3);
        if (temp_r3_3 != 0U) {
            if ((s32) *(s32 *)&this->unk_60 == 3) {
                temp_r4 = *(s32 *)&this->player_id;
                set_color(get_status_index_or_default__20TWindowSubStatusDispFPUs((s8 *)lobby_player_status_records + (temp_r4 * 0x11C) + 4, temp_r4));
            } else {
                set_color(fn_800FCCF4((void *)temp_r3));
            }
        }
    }
    run_task__14TFontSmallHelpFv(this);
}


}
TUnk_8049CA54::~TUnk_8049CA54() {

}

struct RecoveredGlobal_800FCC78_lbl_8049CA54 {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
u8 * __ct__14TFontSmallHelpFUlUllUl(void *, s32, s32, s32, s32);
extern RecoveredGlobal_800FCC78_lbl_8049CA54 __vt__13TUnk_8049CA54;
typedef char RecoveredGlobal_800FCC78_lbl_8049CA54_size[sizeof(RecoveredGlobal_800FCC78_lbl_8049CA54) == 0x1C ? 1 : -1];
u8 *fn_800FCC78(u8 *arg0, s32 arg1) {
    __ct__14TFontSmallHelpFUlUllUl(arg0, arg1, -1, -1, 0);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_8049CA54.value;
    *(s32 *)((s8 *)arg0 + 0x60) = 5;
    return arg0;
}

}
