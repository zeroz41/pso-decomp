#include "types.h"
#include "pso/misc/TShopGenerator.h"
#include "pso/misc/TRaderMapCore.h"

struct RecoveredGlobal_8021E110_TShopGenerator__data_80513ED0 {
    s32 value;
    u8 remaining[0xC];
};

#include <stddef.h>
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TMedicalCenterMes.h"
#include "pso/object/TObjMotion.h"
struct Stack_8021DC30 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
};

struct RecoveredGlobal_8021DC30_lbl_8044C140 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8021DC30_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct E_8021E1FC { u8 pad0[8]; void (*fn)(void); u8 pad1[8]; };

struct Tbl_8021E1FC { E_8021E1FC e[8]; };

struct Ent_8021DDB8 {
    void (*f0)(void);
    void (*f4)(void);
    void (*f8)(void);
    void (*fc)(s32);
    s32 (*f10)(u16);
};

extern "C" {
s32 TShopGenerator__sub_80222DAC(s32);
extern RecoveredGlobal_8021E110_TShopGenerator__data_80513ED0 TShopGenerator__slot_active_table;
u8 is_slot_active__14TShopGeneratorFi(s32 arg0);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
f32 vec3_dot(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
f32 normalize_vector(void *);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern RecoveredGlobal_8021DC30_lbl_8044C140 shop_service_facing_vec;
extern RecoveredGlobal_8021DC30_lbl_8058D490 identity_matrix;
extern const f32 lbl_805DC6E8;
bool is_player_in_service_range__14TShopGeneratorFPUcf(u8 *arg0, u8 *arg1, f32 farg0);
void THunterGuildSeqOffline__sub_8021E180(s32 arg0);
extern Tbl_8021E1FC TShopGenerator__service_dispatch_table;
s32 get_entity_id(s32);
s8 get_chr_select_state__23TAdSinglePlyChrSelectGCFv(void);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
int is_flag_400_set__10TObjPlayerFPv(void *p);
int check_flag_100__10TObjPlayerFPv(void *p);
void *get_player_by_client_id(s32 i);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
extern u8 controller_input_state[];
extern s32 local_client_id;
extern s32 lbl_805D55C0;
extern const f32 lbl_805DC6EC;
void run_task__14TShopGeneratorFv(u8 *self);
void TMedicalCenterMes__sub_80216260(void);
void *TShopGenerator__create(void *arg0);
void *TShopGenerator__ct(void *arg0, s32 arg1);
void *__dt__14TShopGeneratorFv(void *arg0, s16 arg1);
s32 __ct__13TUnk_804B9870FP7TObject(void *, s32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void queue_destruction__7TObjectFv(void *arg0);

extern s32 __vt__14TShopGenerator[];

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
typedef char RecoveredGlobal_8021DC30_lbl_8044C140_size[sizeof(RecoveredGlobal_8021DC30_lbl_8044C140) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8021DC30_lbl_8058D490_size[sizeof(RecoveredGlobal_8021DC30_lbl_8058D490) == 0x30 ? 1 : -1];
bool TShopGenerator::is_player_in_service_range(u8 *arg1, f32 farg0) {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_8021DC30, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8021DC30, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8021DC30, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8021DC30, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8021DC30, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_8021DC30, sp1C) == 0x14) ? 1 : -1];
    Stack_8021DC30 stack;
    if (xyz_distance_squared((arg1 + 0x38), ((u8 *)&this->position)) > (farg0 * farg0)) {
        return 0;
    }
    stack.sp8 = *(s32 *)((s8 *)&shop_service_facing_vec.value + 0);
    stack.spC = *(s32 *)((s8 *)&shop_service_facing_vec.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&shop_service_facing_vec.value + 8);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg1 + 0x60)));
    rotate_vector_by_matrix(0, (void *)&stack.sp8, (void *)&stack.sp8);
    pop_matrix();
    stack.sp14 = *(f32 *)((s8 *)arg0 + 0x38) - *(f32 *)((s8 *)arg1 + 0x38);
    stack.sp18 = *(f32 *)((s8 *)arg0 + 0x3C) - *(f32 *)((s8 *)arg1 + 0x3C);
    stack.sp1C = *(f32 *)((s8 *)arg0 + 0x40) - *(f32 *)((s8 *)arg1 + 0x40);
    normalize_vector((void *)&stack.sp14);
    return (vec3_dot((void *)&stack.sp8, (void *)&stack.sp14) > lbl_805DC6E8) == 0;
}
#pragma pop

s32 TShopGenerator::is_no_service_active(void *self, s32 player) {
    s32 i;
    s32 (*fn)(u16);
    for (i = 0; i < 7; i++) {
        fn = *(s32 (**)(u16))((s8 *)&TShopGenerator__service_dispatch_table.e[i] + 0x10);
        if (fn(TShopGenerator__sub_80222DAC(get_entity_id(player))) == 1) {
            return 0;
        }
    }
    return 1;
}

void run_task__14TShopGeneratorFv(u8 *self) {
    Ent_8021DDB8 *e;
    s32 i;
    s32 p;
    s32 (*fn)(u16);
    e = (Ent_8021DDB8 *)&TShopGenerator__service_dispatch_table.e[((TShopGenerator *)self)->set_params[0]];
    if (*(s32 *)&((TShopGenerator *)self)->m_94 > 0) {
        (*(s32 *)&((TShopGenerator *)self)->m_94)--;
        return;
    }
    if (lbl_805D55C0 != 0) {
        return;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(get_chr_select_state__23TAdSinglePlyChrSelectGCFv()) != 0) {
        return;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            p = (s32)get_player_by_client_id(i);
            if (p == 0) continue;
            if (((s32 (*)(u8 *, u8 *, f32))is_player_in_service_range__14TShopGeneratorFPUcf)(self, (u8 *)p, lbl_805DC6EC) == 0) continue;
            if (((s32 (*)(s32))is_slot_active__14TShopGeneratorFi)(get_entity_id(p)) == 1) continue;
            if (TMedicalCenterMes::get_slot_flag(get_entity_id(p)) == 1) continue;
            if (is_flag_400_set__10TObjPlayerFPv((void *)p) == 1) continue;
            if (check_flag_100__10TObjPlayerFPv((void *)p) == 1) continue;
            fn = e->f10;
            if (fn(TShopGenerator__sub_80222DAC(get_entity_id(p))) == 1) continue;
            if (TWindowShortListCtrl__check_controller_button(controller_input_state + ((TRaderMapCore *)p)->get_map_id() * 0x50 + 0x20, 4) == 0) continue;
            e->fc(p);
        }
    } else {
        s32 q;
        s32 (*fn2)(u16);
        q = (s32)get_player_by_client_id(local_client_id);
        if (q == 0) return;
        if (((s32 (*)(s32))is_slot_active__14TShopGeneratorFi)(get_entity_id(q)) == 1) return;
        if (TMedicalCenterMes::get_slot_flag(get_entity_id(q)) == 1) return;
        if (is_flag_400_set__10TObjPlayerFPv((void *)q) == 1) return;
        if (check_flag_100__10TObjPlayerFPv((void *)q) == 1) return;
        if (TShopGenerator::is_no_service_active(self, q) == 0) return;
        fn2 = e->f10;
        if (fn2(TShopGenerator__sub_80222DAC(get_entity_id(q))) == 1) return;
        if (((s32 (*)(u8 *, u8 *, f32))is_player_in_service_range__14TShopGeneratorFPUcf)(self, (u8 *)q, lbl_805DC6EC) == 0) return;
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + ((TRaderMapCore *)q)->get_map_id() * 0x50 + 0x20, 4) == 0) return;
        e->fc(q);
    }
}

void *__dt__14TShopGeneratorFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TShopGenerator;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TShopGenerator__class_name;
extern s32 tl_05;

void *TShopGenerator__ct(void *shop_generator, s32 arg1) {
    s32 temp_r0;

    __ct__13TUnk_804B9870FP7TObject(shop_generator, tl_05);
    *(s32 **)((s8 *)shop_generator + 0x18) = __vt__14TShopGenerator;
    *(s32 *)((s8 *)shop_generator + 0) = (s32) TShopGenerator__class_name;
    ((TShopGenerator *)shop_generator)->apply_object_set_data((void *)arg1);
    ((TShopGenerator *)shop_generator)->m_90 = 0;
    ((TShopGenerator *)shop_generator)->m_94 = 5;
    temp_r0 = ((TShopGenerator *)shop_generator)->set_params[0];
    if (temp_r0 < 0) {
        queue_destruction__7TObjectFv(shop_generator);
        return shop_generator;
    }
    if (temp_r0 > 6) {
        queue_destruction__7TObjectFv(shop_generator);
        return shop_generator;
    }
    return shop_generator;
}

typedef char RecoveredGlobal_8021E110_TShopGenerator__data_80513ED0_size[sizeof(RecoveredGlobal_8021E110_TShopGenerator__data_80513ED0) == 0x10 ? 1 : -1];
u8 is_slot_active__14TShopGeneratorFi(s32 arg0) {
    return (u8) (*(s32 *)((s8 *)&TShopGenerator__slot_active_table.value + ((TShopGenerator__sub_80222DAC(arg0) * 4) & 0x3FFFC)) == 1);
}

void TShopGenerator::clear_slot_active(s32 arg0) {
    u16 idx = TShopGenerator__sub_80222DAC(arg0);
    ((s32 *)&TShopGenerator__slot_active_table)[idx] = 0;
}

void THunterGuildSeqOffline__sub_8021E180(s32 arg0) {
    u16 idx = TShopGenerator__sub_80222DAC(arg0);
    ((s32 *)&TShopGenerator__slot_active_table)[idx] = 1;
}

void *TShopGenerator__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TShopGenerator__ct((void *)o, (s32)arg0);
    }
    return o;
}
void TShopGenerator::run_fn_table_reverse() {
    E_8021E1FC *p;
    s32 n;
    s32 i;
    TMedicalCenterMes::clear_slot_flags();
    p = &TShopGenerator__service_dispatch_table.e[7];
    n = 7;
    do {
        void (*f)(void) = (p - 1)->fn;
        p--;
        f();
    } while (--n > 0);
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopGenerator__slot_active_table)[i] = 0;
    }
}
void TShopGenerator::run_fn_table_forward() {
    E_8021E1FC *p;
    s32 n;
    s32 i;
    n = 7;
    p = &TShopGenerator__service_dispatch_table.e[0];
    do {
        (*(void (**)(void))((s8 *)p + 4))();
        p++;
    } while (--n > 0);
    TMedicalCenterMes__sub_80216260();
    for (i = 0; i < 4; i++) {
        ((s32 *)&TShopGenerator__slot_active_table)[i] = 0;
    }
}

}
