#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TWindowSubComCard.h"

struct Base_80288C78_80288B5C { char pad[0x18]; };
struct VObj_80288C78_80288B5C : Base_80288C78_80288B5C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
};
struct Entry_80288C78_80288B5C {
    u8 pad00[0xC];
    s32 fieldC;
};

class VBase_80288FDC { public: u8 pad[0x18]; };
class VObj_80288FDC : public VBase_80288FDC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v8();
};

struct RecoveredGlobal_80289200___vt__19TQuestListChallenge {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80289200_lbl_8045080C {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_80289200_lbl_80450910 {
    s32 value;
    u8 remaining[0x8C];
};

struct RecoveredGlobal_80289200_lbl_80450A20 {
    s32 value;
    u8 remaining[0x7C];
};

class TQuestListChallenge {
public:
    u8 pad[0x20];
    s32 state;
    void create_quest_list_window();
    void update_selection();
    void handle_confirm_select();
    void invoke_callback_and_destroy();
    void destroy();
    void sub_80288BE4();
};

typedef void (TQuestListChallenge::*Handler_802890AC)();

struct VBase_80288DA4 { char pad[0x18]; };

struct VObj_80288DA4 : VBase_80288DA4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct Ent_80288DA4 { s32 id; s32 f4; s32 f8; s32 fC; };

struct Pair_80288DA4 { s32 a; s32 b; };

struct QLC_80288DA4 {
    u8 pad[0x24];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    VObj_80288DA4 *obj;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    u8 pad44[0x4C - 0x44];
    s32 f4C;
    s32 f50;
    s32 count;
    Ent_80288DA4 *entries;
};

extern "C" {

s32 get_entity_id(s32);
s32 get_quest_list_text(int, int, int);
f32 get_scale__15TShopWindowBaseFv(void *);
void *create_yes_no_window(s32, u16, s32, s32);
s32 get_cursor_value__19TWindowMenuIconLineFv(s32);
void *create__14TWindowMessageFllUls(s32, Pair_80288DA4 *, s32, u16);
s32 get_window_layout_position(s32);
void update_selection__19TQuestListChallengeFv(QLC_80288DA4 *self);
s32 lbl_805D64A8;
s32 lbl_805D64AC;
s32 TQuestListChallenge__active_instance;
s32 get_selected_quest_text__19TQuestListChallengeFv(void);
s32 get_game_play_mode();
s32 __ct__15TShopWindowBaseFv();
extern s32 TQuestListChallenge__active_instance;
extern void *__vt__19TQuestListChallenge[];
u8 *TQuestListChallenge__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
}
struct Entry_80288FDC { s32 id; u8 pad[0xC]; };
struct QLC_80288FDC {
    u8 pad[0x24];
    s32 f24;
    u8 pad2[0x30 - 0x28];
    VObj_80288FDC *obj;
    u8 pad3[0x38 - 0x34];
    u32 list;
    u8 pad4[0x50 - 0x3C];
    s32 f50;
    s32 count;
    Entry_80288FDC *entries;
};

s32 get_guild_text(s32);
extern "C" {
u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2);
void create_quest_list_window__19TQuestListChallengeFv(QLC_80288FDC *arg0);
void * TObjNpcKenkyu__create(void *arg0);
void sub_80288BE4__19TQuestListChallengeFv(void);
void *__dt__19TQuestListChallengeFv(void *arg0, s16 arg1);
void close_windows__19TQuestListChallengeFPv(void *arg0);
void destroy__19TQuestListChallengeFv(void *arg0);
void handle_confirm_select__19TQuestListChallengeFv(void *arg0);
void invoke_callback_and_destroy__19TQuestListChallengeFv(void *arg0);
void reset_globals2__19TQuestListChallengeFv(void);
void reset_globals__19TQuestListChallengeFv(void);
s32 prepare_offline_quest_filenames(s32, s32);
void *__ct__11TObjControlFP7TObject(void *, void *);
u8 *TObjNpcKenkyu__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 __dl__7TObjectFPv(void *);
void *__dt__15TShopWindowBaseFv(void *self, s16 m);
void *__nw__7TObjectFUl(int);
void queue_destruction__7TObjectFv(void *arg0);

extern "C" {
struct QLCStage_80289200 { s32 a; s32 b; s32 c; const char *name; };
struct PairPad_80288DA4 { s32 a; s32 b; s32 c; };
extern __declspec(section ".rodata") const QLCStage_80289200 TQuestListChallenge__stage_table[5];
extern __declspec(section ".rodata") const QLCStage_80289200 quest_list_challenge_stage_table[9];
extern __declspec(section ".rodata") const QLCStage_80289200 quest_list_battle_stage_table[8];
extern const char *TQuestListChallenge__name;
extern __declspec(section ".rodata") const PairPad_80288DA4 lbl_80450AB4[1];
}
#define TQuestListChallenge__stage_table (*(RecoveredGlobal_80289200_lbl_8045080C *)TQuestListChallenge__stage_table)
#define quest_list_challenge_stage_table (*(RecoveredGlobal_80289200_lbl_80450910 *)quest_list_challenge_stage_table)
#define quest_list_battle_stage_table (*(RecoveredGlobal_80289200_lbl_80450A20 *)quest_list_battle_stage_table)
#define lbl_80450AB4 ((const Pair_80288DA4 *)lbl_80450AB4)

#pragma push
#pragma opt_common_subs off
s32 get_selected_quest_text__19TQuestListChallengeFv(void) {
    u32 temp_r3;
    if ((void *) (*(u8 * *)&TQuestListChallenge__active_instance) != NULL) {
        temp_r3 = *(u32 *)((s8 *)(*(u8 * *)&TQuestListChallenge__active_instance) + 0x38);
        if (temp_r3 != 0U) {
            return get_quest_list_text((int) (*(s32 *)((s8 *)(*(u8 * *)&TQuestListChallenge__active_instance) + 0x50)), (int) (*(s32 *)((s8 *)(*(s32 *)((s8 *)(*(u8 * *)&TQuestListChallenge__active_instance) + 0x58) + (get_cursor_value__19TWindowMenuIconLineFv(temp_r3) * 0x10)) + 0)), (int) ((*(u8 * *)&TQuestListChallenge__active_instance)));
        }
    }
    return 0;
}
#pragma pop

void close_windows__19TQuestListChallengeFPv(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close();
        *(u32 *)((s8 *)arg0 + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
        *(u32 *)((s8 *)arg0 + 0x38) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x3C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x3C)))->close();
        *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x40) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x40)))->close();
        *(u32 *)((s8 *)arg0 + 0x40) = 0U;
    }
}
void sub_80288BE4__19TQuestListChallengeFv(void) {  }

void invoke_callback_and_destroy__19TQuestListChallengeFv(void *object) {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)object + 0x2C);
    if (temp_r12 != NULL) {
        temp_r12(*(s32 *)((s8 *)object + 0x30));
    }
    queue_destruction__7TObjectFv(object);
}

void destroy__19TQuestListChallengeFv(void *object) {
    s32 (*temp_r12)(s32);

    temp_r12 = *(s32 (**)(s32))((s8 *)object + 0x28);
    if (temp_r12 != NULL) {
        temp_r12(*(s32 *)((s8 *)object + 0x30));
    }
    queue_destruction__7TObjectFv(object);
}

void handle_confirm_select__19TQuestListChallengeFv(void *quest_list_challenge) {
    s32 temp_r0;
    s32 selected_menu_value;
    Entry_80288C78_80288B5C *identity;
    VObj_80288C78_80288B5C *temp_r3_3;
    VObj_80288C78_80288B5C *temp_r3_4;

    if ((*(VObj_80288C78_80288B5C **)((s8 *)quest_list_challenge + 0x30))->m8() != 0) {
        if ((*(void **)((s8 *)quest_list_challenge + 0x34) != NULL) && (((TWindowMenu *)(*(void **)((s8 *)quest_list_challenge + 0x34)))->is_decided() == 1)) {
            selected_menu_value = ((TWindowMenu *)(*(u32 *)((s8 *)quest_list_challenge + 0x34)))->get_selected_value();
            if (selected_menu_value == 0) {
                temp_r0 = get_cursor_value__19TWindowMenuIconLineFv(*(s32 *)((s8 *)quest_list_challenge + 0x38));
                identity = *(Entry_80288C78_80288B5C **)((s8 *)quest_list_challenge + 0x58);
                prepare_offline_quest_filenames(identity[temp_r0].fieldC, (s32) identity);
                ((TShopWindowBase *)quest_list_challenge)->set_field_20(3);
                return;
            }
            if (selected_menu_value == 1) {
                close_windows__19TQuestListChallengeFPv(quest_list_challenge);
                temp_r3_3 = *(VObj_80288C78_80288B5C **)((s8 *)quest_list_challenge + 0x30);
                if (temp_r3_3 != NULL) {
                    temp_r3_3->m7(0x19, 0x80);
                }
                ((TShopWindowBase *)quest_list_challenge)->set_field_20(0);
                return;
            }
            goto block_9;
        }
block_9:
        if ((*(void **)((s8 *)quest_list_challenge + 0x34) != NULL) && (((TWindowMenu *)(*(void **)((s8 *)quest_list_challenge + 0x34)))->is_cancelled() == 1)) {
            close_windows__19TQuestListChallengeFPv(quest_list_challenge);
            temp_r3_4 = *(VObj_80288C78_80288B5C **)((s8 *)quest_list_challenge + 0x30);
            if (temp_r3_4 != NULL) {
                temp_r3_4->m7(0x19, 0x80);
            }
            ((TShopWindowBase *)quest_list_challenge)->set_field_20(0);
        }
    }
}

#define SUB_80222C28(a, b) ((s32 (*)(s32, s32))get_quest_list_text)(a, b)
void update_selection__19TQuestListChallengeFv(QLC_80288DA4 *self) {
    Pair_80288DA4 p;
    s32 sel;
    s32 id;
    s32 text;
    s32 text2;
    if (self->obj->m8() == 0) {
        return;
    }
    if (self->f38 != NULL && self->f3C != NULL) {
        sel = ((TWindowMenuIconLine *)self->f38)->get_cursor_value();
        if (sel != self->f4C) {
            text = SUB_80222C28(self->f50, self->entries[sel].f4);
            ((TWindowMessage *)(self->f3C))->append_line(text, 0x80);
            self->f4C = sel;
            if (self->f40 != NULL) {
                ((TWindowBase *)self->f40)->close();
                self->f40 = NULL;
            }
        }
    }
    if (self->f38 != NULL && ((TWindowMenuIconLine *)(self->f38))->is_cancelled() == 1) {
        ((TShopWindowBase *)self)->set_field_20(4);
        return;
    }
    if (self->f38 != NULL && ((TWindowMenuIconLine *)(self->f38))->is_decided() == 1) {
    sel = ((TWindowMenuIconLine *)self->f38)->get_cursor_value();
    if (self->f40 == NULL) {
        p.a = lbl_80450AB4[0].a;
        p.b = lbl_80450AB4[0].b;
        id = (u16)get_entity_id(self->f24);
        self->f40 = create__14TWindowMessageFllUls(get_window_layout_position(0x2E), &p, 1, id);
        text2 = SUB_80222C28(self->f50, self->entries[sel].f8);
        ((TWindowMessage *)(self->f40))->append_line(text2, 0x80);
        ((TWindowBase *)(self->f40))->set_depth(37000.0f);
        if (TCameraCtrl::get_camera_id() >= 2) {
            ((TWindowAddition *)(self->f40))->set_position_xy(0.75f, 0.75f);
        }
    }
    if (self->f34 == NULL) {
        id = (u16)get_entity_id(self->f24);
        self->f34 = create_yes_no_window(get_window_layout_position(0x2B), id, 0, 0);
        ((TWindowAddition *)(self->f34))->set_position_xy(get_scale__15TShopWindowBaseFv(self), get_scale__15TShopWindowBaseFv(self));
        if (self->obj != NULL) {
            self->obj->m7(5, 0x80);
        }
        ((TShopWindowBase *)self)->set_field_20(2);
    }
    }
}

void create_quest_list_window__19TQuestListChallengeFv(QLC_80288FDC *arg0) {
    u16 id;
    s32 i;
    s32 e;

    if (arg0->obj->v8() != 0 && arg0->list == 0) {
        id = get_entity_id(arg0->f24);
        arg0->list = (u32)create_item_list_window(get_guild_text(0), 0x40, id);
        for (i = 0; i < arg0->count; i++) {
            e = ((s32 (*)(s32, s32))get_quest_list_text)(arg0->f50, arg0->entries[i].id);
            ((TWindowMenuIconLine *)(arg0->list))->add_list_entry(0x2C, e, i);
        }
        ((TWindowMenuIconLine *)arg0->list)->calc_content_extent();
        ((TShopWindowBase *)arg0)->set_field_20(1);
    }
}

void TQuestListChallenge__vt9(TQuestListChallenge *quest_list_challenge) {
    static Handler_802890AC tbl[] = {
        &TQuestListChallenge::create_quest_list_window,
        &TQuestListChallenge::update_selection,
        &TQuestListChallenge::handle_confirm_select,
        &TQuestListChallenge::invoke_callback_and_destroy,
        &TQuestListChallenge::destroy,
        &TQuestListChallenge::sub_80288BE4,
    };
    (quest_list_challenge->*tbl[quest_list_challenge->state])();
}

extern "C" void run_task__15TShopWindowBaseFv();
extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void vfunc_6__15TShopWindowBaseFv();
extern "C" void vfunc_7__15TShopWindowBaseFv();
extern "C" void vfunc_8__15TShopWindowBaseFv();
extern "C" void vfunc_9__15TShopWindowBaseFv();
extern "C" void vfunc_10__15TShopWindowBaseFv();
void *__vt__19TQuestListChallenge[12] = {
    0, 0, (void *)&__dt__19TQuestListChallengeFv, (void *)&run_task__15TShopWindowBaseFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__15TShopWindowBaseFv,
    (void *)&vfunc_7__15TShopWindowBaseFv, (void *)&vfunc_8__15TShopWindowBaseFv,
    (void *)&vfunc_9__15TShopWindowBaseFv, (void *)&vfunc_10__15TShopWindowBaseFv,
    (void *)&TQuestListChallenge__vt9,
};

void *__dt__19TQuestListChallengeFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__19TQuestListChallenge;
        close_windows__19TQuestListChallengeFPv((void *)((s32 *)arg0));
        TQuestListChallenge__active_instance = 0;
        __dt__15TShopWindowBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_805D64A8;
extern s32 lbl_805D64AC;

typedef char RecoveredGlobal_80289200___vt__19TQuestListChallenge_size[sizeof(RecoveredGlobal_80289200___vt__19TQuestListChallenge) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_80289200_lbl_8045080C_size[sizeof(RecoveredGlobal_80289200_lbl_8045080C) == 0x50 ? 1 : -1];
typedef char RecoveredGlobal_80289200_lbl_80450910_size[sizeof(RecoveredGlobal_80289200_lbl_80450910) == 0x90 ? 1 : -1];
typedef char RecoveredGlobal_80289200_lbl_80450A20_size[sizeof(RecoveredGlobal_80289200_lbl_80450A20) == 0x80 ? 1 : -1];
u8 *TQuestListChallenge__ct(u8 *shop_window_base, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;
    s32 var_r3;
    __ct__15TShopWindowBaseFv();
    *(s32 **)((s8 *)shop_window_base + 0x18) = &(*(RecoveredGlobal_80289200___vt__19TQuestListChallenge *)&__vt__19TQuestListChallenge).value;
    *(s32 *)((s8 *)shop_window_base + 0) = (s32) (*(s32 *)&TQuestListChallenge__name);
    if ((void *) (*(u8 * *)&TQuestListChallenge__active_instance) != NULL) {
        return shop_window_base;
    }
    *(s32 *)((s8 *)shop_window_base + 0x28) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x2C) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x30) = arg2;
    *(s32 *)((s8 *)shop_window_base + 0x34) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x38) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x3C) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x40) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x24) = arg3;
    *(s32 *)((s8 *)shop_window_base + 0x44) = 0;
    *(s32 *)((s8 *)shop_window_base + 0x48) = 0;
    temp_r3 = get_game_play_mode();
    switch (temp_r3) {
    case 1:
        if (TLobby::get_instance() == 0) {
            *(s32 **)((s8 *)shop_window_base + 0x58) = &quest_list_challenge_stage_table.value;
        } else {
            *(s32 **)((s8 *)shop_window_base + 0x58) = &TQuestListChallenge__stage_table.value;
        }
        *(s32 *)((s8 *)shop_window_base + 0x50) = 0xF;
        *(s32 *)((s8 *)shop_window_base + 0x54) = (s32) (TLobby::calc_min_challenge_progress() + 1);
        temp_r3 = TLobby::get_instance();
        var_r3 = 5;
        if (temp_r3 == 0) {
            var_r3 = 9;
        }
        if ((s32) *(s32 *)((s8 *)shop_window_base + 0x54) > var_r3) {
            *(s32 *)((s8 *)shop_window_base + 0x54) = var_r3;
        }
        break;
    case 2:
        *(s32 *)((s8 *)shop_window_base + 0x50) = 0x10;
        *(s32 **)((s8 *)shop_window_base + 0x58) = &quest_list_battle_stage_table.value;
        *(s32 *)((s8 *)shop_window_base + 0x54) = 8;
        break;
    }
    ((TShopWindowBase *)shop_window_base)->set_field_20(0);
    (*(u8 * *)&TQuestListChallenge__active_instance) = shop_window_base;
    return shop_window_base;
}

void reset_globals__19TQuestListChallengeFv(void) {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    TQuestListChallenge__active_instance = 0;
}

void reset_globals2__19TQuestListChallengeFv(void) {
    lbl_805D64A8 = 0;
    lbl_805D64AC = 0;
    TQuestListChallenge__active_instance = 0;
}

extern void *tl_04;

void * TObjNpcKenkyu__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcKenkyu__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}
}

#undef TQuestListChallenge__stage_table
#undef quest_list_challenge_stage_table
#undef quest_list_battle_stage_table
#undef lbl_80450AB4
extern "C" const char lbl_804507A8[] = "challenge2_mlt_stg1";
extern "C" const char lbl_804507BC[] = "challenge2_mlt_stg2";
extern "C" const char lbl_804507D0[] = "challenge2_mlt_stg3";
extern "C" const char lbl_804507E4[] = "challenge2_mlt_stg4";
extern "C" const char lbl_804507F8[] = "challenge2_mlt_stg5";
extern "C" const QLCStage_80289200 TQuestListChallenge__stage_table[5] = {
    {27, 28, 29, lbl_804507A8},
    {30, 31, 32, lbl_804507BC},
    {33, 34, 35, lbl_804507D0},
    {36, 37, 38, lbl_804507E4},
    {39, 40, 41, lbl_804507F8},
};
extern "C" const char lbl_8045085C[] = "challenge_mlt_stg1";
extern "C" const char lbl_80450870[] = "challenge_mlt_stg2";
extern "C" const char lbl_80450884[] = "challenge_mlt_stg3";
extern "C" const char lbl_80450898[] = "challenge_mlt_stg4";
extern "C" const char lbl_804508AC[] = "challenge_mlt_stg5";
extern "C" const char lbl_804508C0[] = "challenge_mlt_stg6";
extern "C" const char lbl_804508D4[] = "challenge_mlt_stg7";
extern "C" const char lbl_804508E8[] = "challenge_mlt_stg8";
extern "C" const char lbl_804508FC[] = "challenge_mlt_stg9";
extern "C" const QLCStage_80289200 quest_list_challenge_stage_table[9] = {
    {0, 1, 2, lbl_8045085C},
    {3, 4, 5, lbl_80450870},
    {6, 7, 8, lbl_80450884},
    {9, 10, 11, lbl_80450898},
    {12, 13, 14, lbl_804508AC},
    {15, 16, 17, lbl_804508C0},
    {18, 19, 20, lbl_804508D4},
    {21, 22, 23, lbl_804508E8},
    {24, 25, 26, lbl_804508FC},
};
extern "C" const char lbl_804509A0[] = "battle_mlt_stg1";
extern "C" const char lbl_804509B0[] = "battle_mlt_stg2";
extern "C" const char lbl_804509C0[] = "battle_mlt_stg3";
extern "C" const char lbl_804509D0[] = "battle_mlt_stg4";
extern "C" const char lbl_804509E0[] = "battle_mlt_stg5";
extern "C" const char lbl_804509F0[] = "battle_mlt_stg6";
extern "C" const char lbl_80450A00[] = "battle_mlt_stg7";
extern "C" const char lbl_80450A10[] = "battle_mlt_stg8";
extern "C" const QLCStage_80289200 quest_list_battle_stage_table[8] = {
    {0, 1, 2, lbl_804509A0},
    {3, 4, 5, lbl_804509B0},
    {6, 7, 8, lbl_804509C0},
    {9, 10, 11, lbl_804509D0},
    {12, 13, 14, lbl_804509E0},
    {15, 16, 17, lbl_804509F0},
    {18, 19, 20, lbl_80450A00},
    {21, 22, 23, lbl_80450A10},
};
extern "C" const char lbl_80450AA0[] = "TQuestListChallenge";
extern "C" const char *TQuestListChallenge__name = lbl_80450AA0;

extern "C" const PairPad_80288DA4 lbl_80450AB4[1] = {{0x43A60000, 0x43520000, 0}};
