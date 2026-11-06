
#include "types.h"
void __ct__9TObjEnemyFP7TObject(void *);
void *__construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void);
void __dt__15RenderFadeStateFv(void);
void init_position_vectors__10TObjPlayerFv(void *);
void clamp_stat_354__10TObjPlayerFv(void *);
void select_rare_variant__11TObjEneMojaFv(void *);
void set_field_d8__10TObjMotionFl(void *, long);
void set_animation__10TObjMotionFs(void *, s16);
void set_field_b8__10TObjMotionFs(void *, s16);
void init_collision_body_parts(void *, void *, s32);
void bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(void *, u8 *, u8 *, u8 *);
void update_prev_position__9TObjEnemyFv(void *);
void copy_position__20TBoss3VoloptHiraisinFv(void *);
void register_object_by_id__14TObjCollidableFv(void *);
void add_flags_2e4__9TObjCharaFUl(void *, u32);
void *create__13TUnk_80494968FUlUl(u32, u32);
void activate_and_dispatch__15RenderFadeStateFv(void *);
extern s32 TObjEneMoja__name;
extern s8 lbl_80491828[];
extern s32 lbl_805D50C8;
extern s32 lbl_805D50CC;
extern s32 lbl_805D50D0;
extern s32 lbl_805D50D8;
extern f32 lbl_805D9BD8;
extern f32 lbl_805D9BDC;
extern f32 lbl_805D9C60;
extern f32 lbl_805D9C64;
extern "C" {
struct MojaVBase {
    char pad[0x18];
};
struct MojaVObj : MojaVBase {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void apply_set_data(void *);
    virtual void clear_lobby_object_state();
};
void *TObjEneMoja__ct(void *arg0, void *arg1, void *arg2) {
    s8 *self;
    s8 *desc;
    s8 *tbl;
    s32 i;

    self = (s8 *)arg0;
    desc = lbl_80491828;
    __ct__9TObjEnemyFP7TObject(self);
    *(u8 **)(self + 0x18) = (u8 *)(desc + 0x194);
    __construct_array(self + 0x39c, (void *)&__ct__15RenderFadeStateFv,
                      (void *)&__dt__15RenderFadeStateFv, 0x1c, 4);
    *(s32 *)self = TObjEneMoja__name;
    ((MojaVObj *)self)->apply_set_data(arg2);
    init_position_vectors__10TObjPlayerFv(self);
    *(s16 *)(self + 0x326) = 0;
    *(s16 *)(self + 0x328) = 0;
    *(f32 *)(self + 0x390) = lbl_805D9C60 + *(f32 *)(self + 0x358);
    if (*(f32 *)(self + 0x390) < lbl_805D9BD8) {
        *(f32 *)(self + 0x390) = lbl_805D9BD8;
    } else if (lbl_805D9BDC < *(f32 *)(self + 0x390)) {
        *(f32 *)(self + 0x390) = lbl_805D9BDC;
    }
    *(f32 *)(self + 0x394) = lbl_805D9C64 + *(f32 *)(self + 0x35c);
    if (*(f32 *)(self + 0x394) < lbl_805D9BD8) {
        *(f32 *)(self + 0x394) = lbl_805D9BD8;
    } else if (lbl_805D9BDC < *(f32 *)(self + 0x394)) {
        *(f32 *)(self + 0x394) = lbl_805D9BDC;
    }
    clamp_stat_354__10TObjPlayerFv(self);
    select_rare_variant__11TObjEneMojaFv(self);
    *(s32 *)(self + 0x334) = 1;
    *(s32 *)(self + 0xd8) = (s32)(desc + 0xa0);
    set_field_d8__10TObjMotionFl(self, *(s32 *)(self + 0xd8));
    *(s32 *)(self + 0xdc) = *(s32 *)((s8 *)lbl_805D50D8 + 0x430);
    *(s16 *)(self + 0xb8) = 0;
    set_animation__10TObjMotionFs(self, *(s16 *)(self + 0xb8));
    set_field_b8__10TObjMotionFs(self, *(s16 *)(self + 0xb8));
    init_collision_body_parts(self, desc + 0x168, 1);
    *(s32 *)(self + 0x380) = 0;
    bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(
        self, (u8 *)((s32 *)lbl_805D50C8)[*(s32 *)(self + 0x368)],
        (u8 *)((s32 *)lbl_805D50CC)[*(s32 *)(self + 0x380) + *(s32 *)(self + 0x368) * 3],
        (u8 *)((s32 *)lbl_805D50D0)[*(s32 *)(self + 0x368)]);
    tbl = desc + 0x130;
    *(s32 *)(self + 0x350) = (s32)tbl + *(s32 *)(self + 0x368) * 0x1c;
    *(s16 *)(self + 0x33e) = *(s16 *)(self + 0x32c);
    update_prev_position__9TObjEnemyFv(self);
    copy_position__20TBoss3VoloptHiraisinFv(self);
    register_object_by_id__14TObjCollidableFv(self);
    *(s16 *)(self + 0x33a) = 0;
    *(s16 *)(self + 0x33c) = *(s16 *)(self + 0x33a);
    *(s32 *)(self + 0x37c) = 0;
    *(s32 *)(self + 0x384) = -1;
    *(s32 *)(self + 0x388) = 1;
    add_flags_2e4__9TObjCharaFUl(self, 1);
    *(u32 *)(self + 0x30) |= 0x40000;
    *(f32 *)(self + 0x38c) = lbl_805D9BD8;
    *(s32 *)(self + 0x398) = (s32)create__13TUnk_80494968FUlUl(0xff303030, 0x0a303030);
    for (i = 0; i < 4; i++) {
        activate_and_dispatch__15RenderFadeStateFv(self + i * 0x1c + 0x39c);
    }
    ((MojaVObj *)self)->clear_lobby_object_state();
    return arg0;
}
}
