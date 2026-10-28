#include "types.h"
#include "pso/misc/TShopGenerator.h"
#include "pso/misc/THunterGuildSeqOffline_80213788.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TQuestListOnline_80218310.h"
#include "pso/quest/TQuestThread.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/misc/TShopSequence.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include <stddef.h>
#include "pso/TObject.h"
#include "pso/TProtocol.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TWindowSubComCard.h"

namespace part0 {

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define PADV virtual void CAT(f,__LINE__)();
struct Base_A_80213788 { char pad[0x18]; };
struct V_A_80213788 : Base_A_80213788 {
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m7(s32, s32);
    virtual s32 m8();
};
struct Base_A_8021383c_80213788 { char pad[0x18]; };
struct V_A_8021383c_80213788 : public Base_A_8021383c_80213788 {
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void m7(int, int);
    virtual s32 m8();
};
struct Base_802138F0_80213788 { char pad[0x18]; };
struct VObj_802138F0_80213788 : Base_802138F0_80213788 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct VBase_18_97738d { char pad[0x18]; };

struct VObj_18_97738d : VBase_18_97738d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
};

struct Stack_80213B18 {
    f32 sp8;
    f32 spC;
};

struct RecoveredGlobal_80213CCC_lbl_804C9740 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80213CCC_lbl_804C9740_size[sizeof(RecoveredGlobal_80213CCC_lbl_804C9740) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80213CCC_lbl_80513E70 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80213CCC_lbl_80513E70_size[sizeof(RecoveredGlobal_80213CCC_lbl_80513E70) == 0x10 ? 1 : -1];

struct Seq_80213D84 {
    s32 f0; u8 pad4[0x14]; void *vt; s32 f1c; s32 f20; s32 f24; u8 pad28[4]; s32 f2c; s32 f30; s32 f34; s32 f38; s32 f3c;
};

struct VBase_18_80213BE0 { char pad[0x18]; };

struct VObj_80213BE0 : VBase_18_80213BE0 {
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
    virtual void m10();
    virtual void m11();
};

struct Seq_80213BE0 : VObj_80213BE0 {
    u32 pad1c;
    u32 state;
};

struct Base_80213980 { char pad[0x18]; };

struct V_80213980 : Base_80213980 {
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    PADV
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct Obj_80213980 : V_80213980 { char pad1c[0x14]; s32 state; s32 f34; s32 thread; };

extern "C" {
s32 get_window_layout_position(int, f32);
extern const f32 lbl_805DC658;
extern const f32 lbl_805DC65C;
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80213CCC_lbl_804C9740 __vt__28THunterGuildSeqOnline_Client;
extern RecoveredGlobal_80213CCC_lbl_80513E70 lbl_80513E70;
extern s32 hunter_guild_seq_online_client_instance;
extern RecoveredGlobal_80213CCC_lbl_80513E70 lbl_80513E70;
extern RecoveredGlobal_80213CCC_lbl_80513E70 lbl_80513E70;
u8 *TShopSequence__ct(u8 *);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
extern RecoveredGlobal_80213CCC_lbl_804C9740 __vt__28THunterGuildSeqOnline_Client;
extern RecoveredGlobal_80213CCC_lbl_80513E70 lbl_80513E70;
extern s32 THunterGuildSeqOnline_Client__name;
extern s32 hunter_guild_seq_online_client_instance;
Seq_80213D84 *THunterGuildSeqOnline_Client__ct(Seq_80213D84 *arg0, s32 arg1, s32 arg2);
void THunterGuildSeqOffline__sub_80213BE0(Seq_80213BE0 *arg0);
int is_quest_active(void);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern s32 quest_mission_manager;
void THunterGuildSeqOffline__sub_80213980(Obj_80213980 *self);
s32 set_service_counter_camera(void *, s32);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 restore_player_state__13TShopSequenceFv();

void update_shop_close__22THunterGuildSeqOfflineFPv(void *shop_sequence) {
    void *object;

    object = *(void **)((s8 *)shop_sequence + 0x38);
    if (object != NULL) {
        if (((TObject *)object)->all_parents_unqueued_for_destruction() != 1) {
            *(u32 *)((s8 *)shop_sequence + 0x38) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
            ((V_A_80213788 *) shop_sequence)->m7(0xC, 1);
            *(s32 *)((s8 *)shop_sequence + 0x34) = 1;
            ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
        }
    }
}

void update_close_shop__22THunterGuildSeqOfflineFPv(void *shop_sequence) {
    void *p = *(void **)((s8 *)shop_sequence + 0x38);
    if (p != 0) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() == 0) {
            *(u32 *)((s8 *)shop_sequence + 0x38) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
            ((V_A_8021383c_80213788 *) shop_sequence)->m7(0xC, 1);
            *(s32 *)((s8 *)shop_sequence + 0x34) = 1;
            ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
        }
    }
}

void handle_close__22THunterGuildSeqOfflineFPv(void *shop_sequence) {
    if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
        ((VObj_802138F0_80213788 *)shop_sequence)->m7(0xC, 1);
        *(s32 *)((s8 *)shop_sequence + 0x34) = 0;
        ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
    }
}

void THunterGuildSeqOffline__sub_80213980(Obj_80213980 *self) {
    if (self->m8() == 0) {
        return;
    }
    switch (self->state) {
    case 1:
        return;
    case 0:
        if (is_quest_active() != 0) {
            if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFF) != 0) {
                self->m7(0xB, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                    self->thread = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                }
                ((TShopWindowBase *)self)->set_field_20(4);
            } else if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFD) != 0) {
                self->m7(0x12, 1);
                if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                    self->thread = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                }
                ((TShopWindowBase *)self)->set_field_20(5);
            } else {
                self->m7(2, 1);
                ((TShopWindowBase *)self)->set_field_20(6);
            }
        } else if (sub_80223A48__15TShopWindowBaseFv(self) != 0 || sub_802239EC__13TShopSequenceFv(self) != 0) {
            self->m7(0x15, 1);
            ((TShopWindowBase *)self)->set_field_20(0xB);
        }
        break;
    }
}

void THunterGuildSeqOffline__sub_80213B18(u8 *shop_sequence) {
    Stack_80213B18 stack;
    stack.sp8 = lbl_805DC658;
    stack.spC = lbl_805DC65C;
    ((TShopSequence *)shop_sequence)->create_message_window((s32)(get_window_layout_position(0x2C, lbl_805DC658)), (s32)((s32) &stack.sp8));
    ((VObj_18_97738d *)(shop_sequence))->m7(1, 1);
    *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
    ((TShopWindowBase *)shop_sequence)->set_field_20(2);
}

void restore_and_init_quest_list__22THunterGuildSeqOfflineFPv(void *shop_window_base) {
    restore_player_state__13TShopSequenceFv();
    *(s32 *)((s8 *)shop_window_base + 0x2C) = set_service_counter_camera(shop_window_base, 1);
    ((TShopWindowBase *)shop_window_base)->set_field_20(1);
}

    extern int evt2_random_enemies_mode;

void THunterGuildSeqOffline__sub_80213BE0(Seq_80213BE0 *shop_sequence) {
    switch (shop_sequence->state) {
    case 0: shop_sequence->m10(); break;
    case 1: THunterGuildSeqOffline__sub_80213B18((u8 *)shop_sequence); break;
    case 2: THunterGuildSeqOffline__sub_80213980((Obj_80213980 *)(shop_sequence)); break;
    case 11: handle_close__22THunterGuildSeqOfflineFPv(shop_sequence); break;
    case 4: update_close_shop__22THunterGuildSeqOfflineFPv(shop_sequence); break;
    case 5: update_shop_close__22THunterGuildSeqOfflineFPv(shop_sequence); break;
    case 6: ((THunterGuildSeqOffline *)shop_sequence)->open_judgment_item_window(); break;
    case 7: ((THunterGuildSeqOffline *)shop_sequence)->handle_confirm_window(); break;
    case 12: shop_sequence->m11(); break;
    case 14: return;
    }
}

void clear_slots__22THunterGuildSeqOfflineFv(void) {
    s32 i;
    for (i = 0; i < 4; i++) ((s32 *)&lbl_80513E70)[i] = 0;
}

void THunterGuildSeqOffline__sub_80213CA4(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&lbl_80513E70)[i] = 0;
    }
}

u8 *__dt__28THunterGuildSeqOnline_ClientFv(u8 *arg0, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__28THunterGuildSeqOnline_Client.value;
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x2C);
        if (temp_r3 != 0U) {
            queue_destruction__7TObjectFv((void *)temp_r3);
            *(u32 *)((s8 *)arg0 + 0x2C) = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x3C);
        if (temp_r3_2 != 0U) {
            TWindow__close((u8 *)temp_r3_2);
            *(u32 *)((s8 *)arg0 + 0x3C) = 0U;
        }
        *(s32 *)((s8 *)&lbl_80513E70.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        hunter_guild_seq_online_client_instance = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_propagation off
Seq_80213D84 *THunterGuildSeqOnline_Client__ct(Seq_80213D84 *shop_window_base, s32 arg1, s32 arg2) {
    s32 one;
    TShopSequence__ct((u8 *)shop_window_base);
    shop_window_base->vt = ((u8 *)&__vt__28THunterGuildSeqOnline_Client);
    one = 1;
    shop_window_base->f0 = THunterGuildSeqOnline_Client__name;
    shop_window_base->f20 = 0;
    shop_window_base->f24 = arg2;
    shop_window_base->f2c = 0;
    shop_window_base->f30 = 0;
    shop_window_base->f34 = 0;
    shop_window_base->f3c = 0;
    shop_window_base->f38 = 0;
    {
        s32 idx = sub_8022397C__15TShopWindowBaseFv(shop_window_base);
        (*(void * *)&hunter_guild_seq_online_client_instance) = shop_window_base;
        ((s32 *)&lbl_80513E70)[idx] = one;
    }
    return shop_window_base;
}
#pragma pop

void reset_random_enemies_mode(void) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }

}

}

struct Base_80213E64_80213E38 { char pad[0x18]; };
struct VObj_80213E64_80213E38 : Base_80213E64_80213E38 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};

    extern int evt2_random_enemies_mode;
void set_random_enemies_mode(void) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 2; TKeyBoardControl__sub_8000F950(); }

extern struct VObj_80213E64_80213E38 *offline_quest_list_vm;
extern "C" {

void THunterGuildSeqOffline__sub_80213E64(void) {
    if (offline_quest_list_vm != NULL) {
        offline_quest_list_vm->m7(6, 1);
        ((TShopWindowBase *)offline_quest_list_vm)->set_field_20(0xC);
        *(s32 *)((s8 *)offline_quest_list_vm + 0x34) = 2;
    }
}
}

namespace part2 {

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32, s32);
};
extern "C" {

struct Base_80213EBC { char pad[0x18]; };
struct VObj_80213EBC : Base_80213EBC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};
extern struct VObj_80213EBC *offline_quest_list_vm;

void THunterGuildSeqOffline__sub_80213EBC(void) {
    if (offline_quest_list_vm != NULL) {
        offline_quest_list_vm->m7(0xC, 1);
        ((TShopWindowBase *)offline_quest_list_vm)->set_field_20(0xA);
        *(s32 *)((s8 *)offline_quest_list_vm + 0x34) = 2;
    }
}
void reset_quest_list_vm__22THunterGuildSeqOfflineFv(void) {
    if ((void *) (*(u8 * *)&offline_quest_list_vm) != NULL) {
        ((VObj_18 *)((*(u8 * *)&offline_quest_list_vm)))->m5(TQuestVmDownLoadServer__sub_8006EF6C(0x43), 1);
        ((TShopWindowBase *)(*(u8 * *)&offline_quest_list_vm))->set_field_20(9);
        *(s32 *)((s8 *)(*(u8 * *)&offline_quest_list_vm) + 0x34) = 0;
    }
}

}

}

namespace part3 {

extern "C" {

struct Base_80213F78 { char pad[0x18]; };
struct VObj_80213F78 : Base_80213F78 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(int, int);
};

extern struct VObj_80213F78 *offline_quest_list_vm;

void THunterGuildSeqOffline__sub_80213F78(void) {
    if (offline_quest_list_vm != NULL) {
        offline_quest_list_vm->m7(0xC, 1);
        ((TShopWindowBase *)offline_quest_list_vm)->set_field_20(9);
        *(s32 *)((s8 *)offline_quest_list_vm + 0x34) = 0;
    }
}

}

}

struct Base_80213FD0 { char pad[0x18]; };
struct VObj_80213FD0 : Base_80213FD0 {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int m6();
    virtual int m7(int, int);
    virtual int m8();
};

extern "C" {

int sub_802239EC__13TShopSequenceFv(void *);
int sub_80223A48__15TShopWindowBaseFv(void *);

void TShopWindowBase::confirm_and_close_if_valid() {
    VObj_80213FD0 *o = (VObj_80213FD0 *)this;
    if (o->m8() != 0 && (sub_80223A48__15TShopWindowBaseFv(this) != 0 || sub_802239EC__13TShopSequenceFv(this) != 0)) {
        o->m7(0xc, 1);
        this->set_field_20(0xc);
    }
}

}

namespace part5 {

struct VBase_18_80214058 { char pad[0x18]; };

struct VObj_80214058 : VBase_18_80214058 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
};

struct Seq_80214058 : VObj_80214058 {
    u8 pad1c[8];
    s32 f24;
};

struct List_80214058 { u8 pad[0x28]; void *f28; void *f2c; void *f30; void *f34; };

extern "C" {
void *__nw__7TObjectFUl(u32);
extern s32 tl_05;
void fn_80214058(Seq_80214058 *arg0);
void fn_80214058(Seq_80214058 *arg0) {
    List_80214058 *l;
    void *e;
    l = (List_80214058 *)__nw__7TObjectFUl(0x70);
    if (l != 0) {
        l = (List_80214058 *)TQuestListOnline__ct((TQuestListOnline *)l, (void *)((void *)tl_05), (void *)arg0, (void *)((void *)arg0->f24));
    }
    if (l != 0) {
        arg0->m7(4, 1);
        l->f28 = (void *)THunterGuildSeqOffline__sub_80213F78;
        l->f2c = (void *)THunterGuildSeqOffline__sub_80213EBC;
        l->f30 = (void *)THunterGuildSeqOffline__sub_80213E64;
        l->f34 = (void *)reset_quest_list_vm__22THunterGuildSeqOfflineFv;
        ((TShopWindowBase *)arg0)->set_field_20(0xE);
    }
}

}

}

namespace part6 {

struct Base_80214104 { char pad[0x18]; };

struct Seq_80214104 : Base_80214104 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    u8 pad1c[8];
    void *player;
    u8 pad28[0xC];
    s32 mode;
    u8 pad38[4];
    void *child;
};

extern "C" {
void *get_entity_id(void *);
void queue_destruction__7TObjectFv(void *);
int is_quest_active(void);
void close_window__13TShopSequenceFv(void *);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
void *__nw__7TObjectFUl(u32);
extern s32 TLobby__protocol_instance;
extern s32 tl_00;
void handle_random_enemies_choice__6TLobbyFPv(Seq_80214104 *self);
void handle_random_enemies_choice__6TLobbyFPv(Seq_80214104 *self) {
    void *mem;
    if (self->child != NULL) {
        if (((TObject *)(self->child))->all_parents_unqueued_for_destruction() != 0) return;
        self->child = NULL;
    }
    if (self->m8() == 0) return;
    switch (self->mode) {
    case 0:
        if (sub_80223A48__15TShopWindowBaseFv(self) == 0 && sub_802239EC__13TShopSequenceFv(self) == 0) return;
        if (is_quest_active() == 0) {
            ((TProtocol *)TLobby__protocol_instance)->send_quest_menu_closed();
        }
        close_window__13TShopSequenceFv(self);
        queue_destruction__7TObjectFv(self);
        break;
    case 1:
        mem = __nw__7TObjectFUl(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)reset_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((s32)(get_entity_id(self->player)));
        close_window__13TShopSequenceFv(self);
        queue_destruction__7TObjectFv(self);
        break;
    case 2:
        mem = __nw__7TObjectFUl(0x28);
        if (mem != NULL) ((THunterGuildSeqOffline *)mem)->init((void *)tl_00, (void *)set_random_enemies_mode);
        THunterGuildSeqOffline__sub_8021E180((s32)(get_entity_id(self->player)));
        close_window__13TShopSequenceFv(self);
        queue_destruction__7TObjectFv(self);
        break;
    }
}

}

}

struct VBase_18_97738d { char pad[0x18]; };

struct VObj_18_97738d : VBase_18_97738d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
};

struct RecoveredGlobal_80214254_THunterGuildSeqOffline__data_80513DC8 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 get_selected_menu_value(void *);
extern RecoveredGlobal_80214254_THunterGuildSeqOffline__data_80513DC8 THunterGuildSeqOffline__quest_result_callbacks;
typedef char RecoveredGlobal_80214254_THunterGuildSeqOffline__data_80513DC8_size[sizeof(RecoveredGlobal_80214254_THunterGuildSeqOffline__data_80513DC8) == 0x10 ? 1 : -1];
void fn_80214254(u8 *shop_window_base) {
    s32 selected_menu_value;
    u8 *window_menu;
    u8 *window_sub_com_card;
    window_menu = (u8 *)(*(u8 **)((s8 *)shop_window_base + 0x38));
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_visible() != 0)) {
        selected_menu_value = get_selected_menu_value(*(u8 **)((s8 *)shop_window_base + 0x38));
        switch (selected_menu_value) {
        case 0:
            TWindow__close(*(u8 **)((s8 *)shop_window_base + 0x38));
            *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
            ((VObj_18_97738d *)(shop_window_base))->m7(9, 1);
            *(s32 *)((s8 *)shop_window_base + 0x34) = 1;
            if ((s32) *(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks.value + 8) != -1) {
                *(s32 *)((s8 *)shop_window_base + 0x3C) = (s32)TQuestThread::create_in_root(*(s32 *)((s8 *)&THunterGuildSeqOffline__quest_result_callbacks.value + 8));
            }
            ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
            break;
        case 1:
            TWindow__close(*(u8 **)((s8 *)shop_window_base + 0x38));
            *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
            ((VObj_18_97738d *)(shop_window_base))->m7(0xA, 1);
            *(s32 *)((s8 *)shop_window_base + 0x34) = 0;
            ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
            break;
        }
    }
    window_sub_com_card = (u8 *)(*(u8 **)((s8 *)shop_window_base + 0x38));
    if ((window_sub_com_card != NULL) && (((TWindowSubComCard *)window_sub_com_card)->get_status_flag() != 0)) {
        TWindow__close(*(u8 **)((s8 *)shop_window_base + 0x38));
        *(u8 **)((s8 *)shop_window_base + 0x38) = NULL;
        ((VObj_18_97738d *)(shop_window_base))->m7(0xA, 1);
        *(s32 *)((s8 *)shop_window_base + 0x34) = 0;
        ((TShopWindowBase *)shop_window_base)->set_field_20(0xC);
    }
}

}

namespace part8 {

struct Base_802143AC { char pad[0x18]; };
struct VObj_802143AC : Base_802143AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32, s32);
    virtual s32 m8r();
};
struct Base_A_80214490_802143AC { char pad[0x18]; };
struct V_A_80214490_802143AC : Base_A_80214490_802143AC {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
};
struct Base_A_80214544_802143AC { char pad[0x18]; };
struct V_A_80214544_802143AC : Base_A_80214544_802143AC {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void m7(s32, s32);
    virtual s32 m8();
};

struct VBase_18_97738d { char pad[0x18]; };

struct VObj_18_97738d : VBase_18_97738d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
};

struct Stack_8021488C {
    f32 sp8;
    f32 spC;
};

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7(s32, s32);
    virtual s32 m8();
};

extern "C" {
int is_quest_active(void);
s32 __ct__12TMemberCheckFP7TObject(int, void *);
u32 __nw__7TObjectFUl(int);
s32 get_window_layout_position(s32);
extern const f32 lbl_805DC658;
extern const f32 lbl_805DC65C;
int is_quest_active(void);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
extern s32 THunterGuildSeqOffline__quest_result_callbacks[];
extern s32 quest_mission_manager;
s32 set_service_counter_camera(void *, s32);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 sub_802239EC__13TShopSequenceFv(void *);
s32 sub_80223A48__15TShopWindowBaseFv(void *);
s32 get_window_layout_position(s32);
f32 get_scale__15TShopWindowBaseFv(void *);
u16 get_entity_id(s32);
s32 restore_player_state__13TShopSequenceFv();

void create_judgment_item_window__15TShopWindowBaseFPv(void *shop_sequence) {
    VObj_802143AC *vobj = (VObj_802143AC *)shop_sequence;

    if ((vobj->m8r() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
        *(s32 *)((s8 *)shop_sequence + 0x38) = (s32)create_yes_no_window(get_window_layout_position(0x2B), (u16)get_entity_id(*(s32 *)((s8 *)shop_sequence + 0x24)), 0, 0);
        ((TWindowSubComCardList *)(*(s32 *)((s8 *)shop_sequence + 0x38)))->set_selected_index(1);
        ((TUnk_804CDFE8 *)(*(s32 *)((s8 *)shop_sequence + 0x38)))->set_position_xy(get_scale__15TShopWindowBaseFv(shop_sequence), get_scale__15TShopWindowBaseFv(shop_sequence));
        vobj->m7(8, 1);
        ((TShopWindowBase *)shop_sequence)->set_field_20(7);
    }
}

void update__15TShopWindowBaseFPv(void *shop_sequence) {
    u32 v = *(u32 *)((s8 *)shop_sequence + 0x3C);
    if (v != 0U) {
        if (((TObject *)v)->all_parents_unqueued_for_destruction() != 1) {
            *(u32 *)((s8 *)shop_sequence + 0x3C) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
            ((V_A_80214490_802143AC *) shop_sequence)->m7(0xC, 1);
            *(s32 *)((s8 *)shop_sequence + 0x34) = 1;
            ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
        }
    }
}

void update_confirm_input__15TShopWindowBaseFPv(void *shop_sequence) {
    void *parent = *(void **)((s8 *)shop_sequence + 0x3C);
    if (parent != NULL) {
        if (((TObject *)parent)->all_parents_unqueued_for_destruction() == 0) {
            *(u32 *)((s8 *)shop_sequence + 0x3C) = 0U;
            goto block_3;
        }
    } else {
block_3:
        if ((((TShopWindowBase *)shop_sequence)->vfunc_10() != 0) && ((sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) || (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0))) {
            ((V_A_80214544_802143AC *) shop_sequence)->m7(0xC, 1);
            *(s32 *)((s8 *)shop_sequence + 0x34) = 1;
            ((TShopWindowBase *)shop_sequence)->set_field_20(0xC);
        }
    }
}

void THunterGuildSeqOffline__sub_802145F8(u8 *shop_sequence) {
    if (((TShopWindowBase *)(shop_sequence))->vfunc_10() != 0) {
        if (sub_80223A48__15TShopWindowBaseFv(shop_sequence) != 0) {
            *(s32 *)((s8 *)shop_sequence + 0x40) = 0;
        }
        if ((s32) *(s32 *)((s8 *)shop_sequence + 0x40) == 0) {
            switch (*(s32 *)((s8 *)shop_sequence + 0x30)) {
            case 3:
                break;
            case 0:
                if (is_quest_active() != 0) {
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                    return;
                }
                switch (THunterGuildSeqOffline::check_party_gathered()) {
                case 1:
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                    return;
                case 0:
                    ((VObj_18 *)(shop_sequence))->m7(0x11, 1);
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 1;
                    return;
                case 2:
                    ((VObj_18 *)(shop_sequence))->m7(0xD, 1);
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 1;
                    return;
                }
                break;
            case 1:
                if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                    *(s32 *)((s8 *)shop_sequence + 0x30) = 2;
                }
                if (sub_802239EC__13TShopSequenceFv(shop_sequence) != 0) {
                    ((VObj_18 *)(shop_sequence))->m7(0x10, 1);
                    ((TShopWindowBase *)shop_sequence)->set_field_20(0xD);
                    return;
                }
                break;
            case 2:
                if (is_quest_active() != 0) {
                    if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFF) != 0) {
                        ((VObj_18 *)(shop_sequence))->m7(0xB, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[1] != -1) {
                            *(s32 *)((s8 *)shop_sequence + 0x3C) = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[1]);
                        }
                        ((TShopWindowBase *)shop_sequence)->set_field_20(4);
                        return;
                    }
                    if (TQuestThread::get_register((u8 *)quest_mission_manager, 0xFD) != 0) {
                        ((VObj_18 *)(shop_sequence))->m7(0x12, 1);
                        if (THunterGuildSeqOffline__quest_result_callbacks[0] != -1) {
                            *(s32 *)((s8 *)shop_sequence + 0x3C) = (s32)TQuestThread::create_in_root(THunterGuildSeqOffline__quest_result_callbacks[0]);
                        }
                        ((TShopWindowBase *)shop_sequence)->set_field_20(5);
                        return;
                    }
                    ((VObj_18 *)(shop_sequence))->m7(2, 1);
                    ((TShopWindowBase *)shop_sequence)->set_field_20(6);
                    return;
                }
                ((VObj_18 *)(shop_sequence))->m7(4, 1);
                *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
                ((TShopWindowBase *)shop_sequence)->set_field_20(8);
                break;
            }
        }
    }
}

void init_window__22THunterGuildSeqOfflineFPv(u8 *shop_sequence) {
    typedef char sp8_offset[(offsetof(Stack_8021488C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8021488C, spC) == 0x4) ? 1 : -1];
    Stack_8021488C stack;
    u32 temp_r3;
    stack.sp8 = lbl_805DC658;
    stack.spC = lbl_805DC65C;
    ((TShopSequence *)shop_sequence)->create_message_window((s32)((int) (get_window_layout_position(0x2C))), (s32)&stack.sp8);
    if (is_quest_active() == 0) {
        temp_r3 = __nw__7TObjectFUl(0x80);
        if (temp_r3 != 0U) {
            __ct__12TMemberCheckFP7TObject(temp_r3, shop_sequence);
        }
    }
    ((VObj_18_97738d *)(shop_sequence))->m7(1, 1);
    *(s32 *)((s8 *)shop_sequence + 0x30) = 0;
    ((TShopWindowBase *)shop_sequence)->set_field_20(3);
}

void restore_shop_and_init_quest_state(void *shop_window_base) {
    restore_player_state__13TShopSequenceFv();
    *(s32 *)((s8 *)shop_window_base + 0x2C) = set_service_counter_camera(shop_window_base, 1);
    ((TShopWindowBase *)shop_window_base)->set_field_20(1);
}

}

}

namespace part9 {

struct RecoveredGlobal_80214A84_lbl_804C97F0 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_80214A84_lbl_804C97F0_size[sizeof(RecoveredGlobal_80214A84_lbl_804C97F0) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80214A84_lbl_80513E60 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80214A84_lbl_80513E60_size[sizeof(RecoveredGlobal_80214A84_lbl_80513E60) == 0x10 ? 1 : -1];

struct Seq_80214B3C {
    s32 f0; u8 pad4[0x14]; void *vt; s32 f1c; s32 f20; s32 f24; u8 pad28[4]; s32 f2c; u8 pad30[4]; s32 f34; s32 f38; s32 f3c; s32 f40;
};

struct VBase_18_80214978 { char pad[0x18]; };

struct VObj_80214978 : VBase_18_80214978 {
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
    virtual void m10();
    virtual void m11();
};

struct Seq_80214978 : VObj_80214978 {
    u32 pad1c;
    u32 state;
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__13TShopSequenceFv(void *arg0, s16 arg1);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80214A84_lbl_804C97F0 lbl_804C97F0;
extern RecoveredGlobal_80214A84_lbl_80513E60 lbl_80513E60;
extern s32 offline_quest_list_vm;
extern RecoveredGlobal_80214A84_lbl_80513E60 lbl_80513E60;
extern RecoveredGlobal_80214A84_lbl_80513E60 lbl_80513E60;
u8 *TShopSequence__ct(u8 *);
s32 sub_8022397C__15TShopWindowBaseFv(void *);
extern RecoveredGlobal_80214A84_lbl_804C97F0 lbl_804C97F0;
extern RecoveredGlobal_80214A84_lbl_80513E60 lbl_80513E60;
extern s32 lbl_805D3664;
extern s32 offline_quest_list_vm;
Seq_80214B3C *THunterGuildSeqOffline__sub_80214B3C(Seq_80214B3C *arg0, s32 arg1, s32 arg2);
void fn_80214058(void *);
void dispatch_state__22THunterGuildSeqOfflineFPv(Seq_80214978 *arg0);

void dispatch_state__22THunterGuildSeqOfflineFPv(Seq_80214978 *shop_sequence) {
    switch (shop_sequence->state) {
    case 0: shop_sequence->m10(); break;
    case 1: init_window__22THunterGuildSeqOfflineFPv((u8 *)shop_sequence); break;
    case 3: THunterGuildSeqOffline__sub_802145F8((u8 *)shop_sequence); break;
    case 8: fn_80214058(shop_sequence); break;
    case 4: update_confirm_input__15TShopWindowBaseFPv(shop_sequence); break;
    case 5: update__15TShopWindowBaseFPv(shop_sequence); break;
    case 6: create_judgment_item_window__15TShopWindowBaseFPv(shop_sequence); break;
    case 7: fn_80214254((u8 *)shop_sequence); break;
    case 9: ((TShopWindowBase *)shop_sequence)->set_field_20((s32)((void *)0xC)); break;
    case 10: ((TShopWindowBase *)shop_sequence)->set_field_20((s32)((void *)0xC)); break;
    case 12: shop_sequence->m11(); break;
    case 13: ((TShopWindowBase *)shop_sequence)->confirm_and_close_if_valid(); break;
    case 14: return;
    }
}

void clear_slot_flags__22THunterGuildSeqOfflineFv(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&lbl_80513E60)[i] = 0;
    }
}

void zero_four_slots__22THunterGuildSeqOfflineFv(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&lbl_80513E60)[i] = 0;
    }
}

u8 *__dt__28THunterGuildSeqOnline_ServerFv(u8 *arg0, s16 arg1) {
    u32 temp_r3;
    u32 temp_r3_2;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804C97F0.value;
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x2C);
        if (temp_r3 != 0U) {
            queue_destruction__7TObjectFv((void *)temp_r3);
            *(u32 *)((s8 *)arg0 + 0x2C) = 0U;
        }
        ((TShopSequence *)arg0)->close_message_window();
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x38);
        if (temp_r3_2 != 0U) {
            TWindow__close((u8 *)temp_r3_2);
            *(u32 *)((s8 *)arg0 + 0x38) = 0U;
        }
        *(s32 *)((s8 *)&lbl_80513E60.value + (sub_8022397C__15TShopWindowBaseFv(arg0) * 4)) = 0;
        offline_quest_list_vm = 0;
        __dt__13TShopSequenceFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_propagation off
Seq_80214B3C *THunterGuildSeqOffline__sub_80214B3C(Seq_80214B3C *shop_window_base, s32 arg1, s32 arg2) {
    s32 one;
    TShopSequence__ct((u8 *)shop_window_base);
    one = 1;
    shop_window_base->vt = ((u8 *)&lbl_804C97F0);
    shop_window_base->f0 = lbl_805D3664;
    shop_window_base->f20 = 0;
    shop_window_base->f24 = arg2;
    shop_window_base->f2c = 0;
    shop_window_base->f34 = 0;
    shop_window_base->f38 = 0;
    shop_window_base->f3c = 0;
    shop_window_base->f40 = one;
    {
        s32 idx = sub_8022397C__15TShopWindowBaseFv(shop_window_base);
        (*(void * *)&offline_quest_list_vm) = shop_window_base;
        ((s32 *)&lbl_80513E60)[idx] = one;
    }
    return shop_window_base;
}
#pragma pop

}

}
