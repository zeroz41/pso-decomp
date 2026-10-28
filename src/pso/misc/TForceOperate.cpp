#include "pso/system/NinjaTypes.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TForceOperate.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TMainCursor.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
__declspec(section ".sdata2") extern const f32 lbl_805DC320[1] = { 1.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DC324[1] = { 3.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DC328[1] = { -4.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DC32C[1] = { 0.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DC330[1] = { 0.1f };
}

struct Base_801C57D0 { char pad[0x18]; };
struct VObj_801C57D0 : Base_801C57D0 {
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
    virtual void m11(s32);
};

struct VBase_18_f1aa6a { char pad[0x18]; };

struct VObj_18_f1aa6a : VBase_18_f1aa6a {
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
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(s32, void *);
};

struct Actor_801C58CC : VObj_18_f1aa6a {
    u8 pad1C[0x20];
    f32 f3c;
};

typedef struct Out_801C58CC {
    u8 pad0[4];
    f32 v;
} Out_801C58CC;

extern "C" {
void calc_death_pose_height_offset(Out_801C58CC *arg0, Actor_801C58CC *arg1);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(int, int);
s32 is_inactive__10TObjPlayerFv();
s32 is_on_current_floor__10TObjPlayerFi(int);
s32 check_flag_40000__10TObjPlayerFv(int);
u8 *get_player_by_client_id(u16);
s32 set_flag_2000000_alt__10TObjPlayerFv();
s32 check_flag_04000000__10TObjPlayerFv(int);
}
void update_player_appear_fade(u8 *arg0);
struct VOff_801C5870_arg0_801C57D0 { char pad_0[0x1C]; char f_1C[1]; };
extern "C" {

void *TForceOperate__ct(void *arg0, void *arg1, void *arg2);
void run_task__13TForceOperateFv(s32 arg0);
s32 TObjPlayer__sub_801C6DAC(u8 *arg0);
void *find_entity_by_id();
void __ct__7TObjectFP7TObject(void *);
void fn_8013E020(void *);
void *get_state__11TMainCursorFv(s32);
s32 is_target_valid__10TObjPlayerFv();
s32 get_entity_id(void *);
void queue_destruction__7TObjectFv(void *arg0);
void set_field_0__13TForceOperateFs(void *, void *);

void run_task__13TForceOperateFv(s32 arg0) {
    void *temp_r31;
    void *entity;

    if (TObjPlayer__sub_801C6DAC((u8 *)(arg0 + 0x1C)) != 0) {
        temp_r31 = get_state__11TMainCursorFv(arg0 + 0x1C);
        if ((is_target_valid__10TObjPlayerFv() != 0) && (((TObjPlayer *)temp_r31)->has_action_palette_entry() != 0)) {
            ((TMainCursor *)(((TObjPlayer *)temp_r31)->m_424 + 0x4F8))->get_id();
            entity = find_entity_by_id();
            if (entity != NULL) {
                ((VObj_801C57D0 *)entity)->m11(get_entity_id(temp_r31));
                queue_destruction__7TObjectFv((void *)arg0);
            }
        }
    }
}

extern s32 __vt__13TForceOperate[];
extern void *lbl_805D3560;

void *TForceOperate__ct(void *force_operate, void *arg1, void *arg2) {
    struct VOff_801C5870_arg0_801C57D0 *self = (struct VOff_801C5870_arg0_801C57D0 *)force_operate;
    __ct__7TObjectFP7TObject(force_operate);
    *(s32 **)((s8 *)force_operate + 0x18) = __vt__13TForceOperate;
    fn_8013E020(self->f_1C);
    *(void * *)&((TForceOperate *)force_operate)->m_name = lbl_805D3560;
    set_field_0__13TForceOperateFs(self->f_1C, arg2);
    return force_operate;
}

#pragma push
#pragma opt_common_subs off
void calc_death_pose_height_offset(Out_801C58CC *arg0, Actor_801C58CC *arg1) {
    f32 sp[4];
    arg1->m63(1, sp);
    arg0->v = (lbl_805DC320[0] + arg1->f3c) - sp[1];
    if (arg0->v > lbl_805DC324[0]) {
        arg0->v = lbl_805DC324[0];
    }
    if (arg0->v < lbl_805DC328[0]) {
        arg0->v = lbl_805DC328[0];
    }
}
}
void calc_death_sink_offset(void *arg0);
#pragma pop

void calc_death_sink_offset(void *arg0) {
    *(f32 *)((s8 *)arg0 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 4) * *(f32 *)((s8 *)arg0 + 8));
}
#pragma push
#pragma opt_common_subs off
void update_player_appear_fade(u8 *arg0) {
    f32 var_f31;
    s16 temp_r3_2;
    u8 *temp_r3;
    temp_r3 = (u8 *)(get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0)));
    if (temp_r3 != NULL) {
        switch (*(s32 *)((s8 *)arg0 + 4)) {
        case 2:
        default:
            break;
        case 0:
            if ((is_inactive__10TObjPlayerFv() != 0) && (check_flag_40000__10TObjPlayerFv((int)temp_r3) == 0) && (check_flag_04000000__10TObjPlayerFv((int)temp_r3) != 0) && (is_on_current_floor__10TObjPlayerFi((int)temp_r3) != 0)) {
                if (--*(s16 *)((s8 *)arg0 + 2) < 0) {
                    if (TCameraCtrl::get_mode() != 0) {
                        ((TObjPlayer *)temp_r3)->render_material_state.alpha = (f32) lbl_805DC320[0];
                        *(s32 *)((s8 *)arg0 + 4) = 2;
                        return;
                    }
                    *(s32 *)((s8 *)arg0 + 4) = 1;
                    ((TObjPlayer *)temp_r3)->activate_body_collision();
                    if (obj_testFlags30__13TUnk_804AF8A0FUl((int)temp_r3, 0x800) == 0) {
                        TObjPlayer::spawn_appearance_effect((int) (*(u16 *)((s8 *)arg0 + 0)));
                    }
                    ((TObjPlayer *)temp_r3)->render_material_state.alpha = (f32) lbl_805DC32C[0];
                    ((TObjPlayer *)temp_r3)->refresh_equipment_slot();
                    return;
                }
            }
            break;
        case 1:
            var_f31 = ((TObjPlayer *)temp_r3)->render_material_state.alpha;
            var_f31 += lbl_805DC330[0];
            if (var_f31 >= lbl_805DC320[0]) {
                var_f31 = lbl_805DC320[0];
                *(s32 *)((s8 *)arg0 + 4) = 2;
                set_flag_2000000_alt__10TObjPlayerFv();
                ((TObjPlayer *)temp_r3)->activate_body_collision();
            }
            ((TObjPlayer *)temp_r3)->render_material_state.alpha = var_f31;
            break;
        }
    }
}
#pragma pop

#include "pso/misc/TLobby.h"

struct RecoveredGlobal_801C5B68_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct Obj_801C5C38 { u8 pad[4]; s32 n; };

extern RecoveredGlobal_801C5B68_lbl_8058D4C0 model_material_color;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void save_render_material_state(u8 *arg0);
extern "C" {
s32 tick_battle_music_timer(Obj_801C5C38 *p);
void update_target_lock__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 get_current_floor();
s32 TObjPlayer__sub_801C6F90();
int clear__8FlagWordFUl(void*, void*);
s32 clear_target_lock_flag__10TObjPlayerFPv(s32);
s32 fn_801C6F2C(void *);
s32 is_room_free_of_active_enemies(s32, s32);
s32 get_stat_by_key_state__13TUnk_804B9870Fv(s32);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
s32 set_lock_flag__10TObjPlayerFPv(s32);
int set_lock_timer__10TObjPlayerFPvi(void*, void*);

void TObjPlayer::enter_battle_state() {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(u16))get_player_by_client_id)(*(u16 *)((s8 *)this + 0));
    if ((temp_r3 != 0) && (fn_801C6F2C(this) == 0)) {
        *(s32 *)((s8 *)this + 4) = 0;
        ((TObjPlayer *)temp_r3)->deactivate_body_collision();
        *(s16 *)((s8 *)this + 2) = 4;
    }
}
}
void reset_player_appearance_opacity(void* a0);
void reset_player_appearance_opacity(void* a0) { *(float*)((char*)a0 + 0x1c) = lbl_805DC320[0]; }

void TObjPlayer::write_ids() { set_model_render_flags((s32)this->m_name); set_chunk_material_override_pair((s32)(*(void**)((char*)this + 0x4)), (s32)this->m_prev); set_constant_material((const NJS_ARGB *)(((char*)this + 0xc))); }

typedef char RecoveredGlobal_801C5B68_lbl_8058D4C0_size[sizeof(RecoveredGlobal_801C5B68_lbl_8058D4C0) == 0x10 ? 1 : -1];
void save_render_material_state(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) model_render_flags;
    *(s32 *)((s8 *)arg0 + 4) = (s32) chunk_polygon_flags_and_mask;
    *(s32 *)((s8 *)arg0 + 8) = (s32) chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)(arg0 + 0xC), (NJS_ARGB *)&model_material_color.value);
}

void TObjPlayer::set_vec4_const() { *(float*)((char*)this + 0x1c) = lbl_805DC320[0]; *(float *)&this->m_20 = lbl_805DC320[0]; *(float *)&this->texture_id = lbl_805DC320[0]; *(float *)&this->room = lbl_805DC320[0]; }

void TObjPlayer::reset_ring() { clear__8FlagWordFUl(this, (void*)1); set_lock_timer__10TObjPlayerFPvi(this, (void*)((void*)-1)); TLobby::set_target_id((s32)((void*)0)); }

void TObjPlayer::clear_target_lock() { ((FlagWord *)this)->set((u32)((void*)1)); TLobby::set_target_id((s32)((void*)1)); }

s32 tick_battle_music_timer(Obj_801C5C38 *p) {
    if (p->n < 0) {
        return 1;
    }
    return --p->n < 0 ? 0 : 1;
}

void update_target_lock__10TObjPlayerFii(s32 arg0, s32 player) {

    if (TObjPlayer__sub_801C6F90() == 0) {
        if (is_room_free_of_active_enemies(get_current_floor(), get_stat_by_key_state__13TUnk_804B9870Fv(player)) != 0) {
            if (set_lock_flag__10TObjPlayerFPv(arg0) != 0) {
                clear_target_lock_flag__10TObjPlayerFPv(arg0);
                set_lock_timer__10TObjPlayerFPvi((void*)arg0, (void*)(0x5A));
                return;
            }
            if (tick_battle_music_timer((Obj_801C5C38 *)(arg0)) == 0) {
                ((TObjPlayer *)arg0)->reset_ring();
            }
        } else if (set_lock_flag__10TObjPlayerFPv(arg0) == 0) {
            ((TObjPlayer *)arg0)->clear_target_lock();
        }
    }
}
