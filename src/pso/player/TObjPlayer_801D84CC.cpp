#include "types.h"
#include "pso/item/TItem.h"
#include "pso/TPlyCharData.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/system/vector.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerClassStats.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/map/FloorArea.h"
struct Stack_801D8664 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 rest[0x11];
};

struct Player_801D88C8;
struct Src_801D88C8;
struct Rec_801D86F8 { s32 a[0x50 / 4]; s32 b[0x38 / 4]; s32 c[0x40 / 4]; };

extern "C" {
void init__9TItemDataFv(void *);
void process_trade_target__10TObjPlayerFiPv(s32 arg0, void *arg1);
void TObjPlayer__sub_801D8664(s32 arg0, s8 arg1, s8 arg2);
void copy_data__6TLobbyFPvPv(void *arg0, void *arg1);
s32 copy_player_visual_record(void *, void *);
s32 fn_801D40D4(void *, void *, void *);
Player_801D88C8 *create_ending_sequence_player(Player_801D88C8 *self, void *parent, Src_801D88C8 *src);
s32 __nw__7TObjectFUl(int);
extern s32 tl_03;
struct VObj_84Base_801d859c_801D84CC { char pad[0x18]; };
struct VObj_84_801d859c_801D84CC : VObj_84Base_801d859c_801D84CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30();
    virtual s8 m31();
};

s32 advance_item_id_counter();
void send_6x29_delete_item__10TObjPlayerFPvii(void *obj, s32 a, s32 b);
void *pickup_item__10TObjPlayerFP5TItem(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801BE9A8(s32 arg0);
void set_equip_slot_entry(s32 arg0, s32 arg1, s32 arg2);
s32 get_item_id__5TItemFv();
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);
u16 get_entity_id(void *);
void set_flag_20000__10TObjPlayerFi(s32 arg0);

void process_trade_target__10TObjPlayerFiPv(s32 arg0, void *player) {
    void *temp_r3;

    ((s32 (*)())get_entity_id)();
    *(s32 *)((s8 *)player + 0xC) = advance_item_id_counter();
    temp_r3 = create_item((TItemData *)player);
    if (temp_r3 != NULL) {
        s8 val = ((VObj_84_801d859c_801D84CC *)temp_r3)->m31();
        s32 val_ext = (s32)val;
        if (get_slot_value__10TObjPlayerFPvi((s32 *)(arg0 + 0xD04), val_ext) != 0U) {
            send_6x29_delete_item__10TObjPlayerFPvii((void *)arg0, get_item_id__5TItemFv(), 1);
            set_equip_slot_entry(arg0 + 0xD04, val_ext, 0);
        }
        if (pickup_item__10TObjPlayerFP5TItem((u8 *)arg0, (u8 *)temp_r3) != 0U) {
            set_flag_20000__10TObjPlayerFi(arg0);
            ((TObjPlayer *)arg0)->equip_item_to_slot(temp_r3, 0);
            TObjPlayer__sub_801BE9A8(arg0);
        }
    }
}
void TObjPlayer__sub_801D8664(s32 arg0, s8 arg1, s8 arg2) {
    typedef char sp8_offset[(offsetof(Stack_801D8664, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_801D8664, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_801D8664, spA) == 0x2) ? 1 : -1];
    Stack_801D8664 stack;
    init__9TItemDataFv(&stack.sp8);
    stack.sp9 = arg1;
    stack.sp8 = 0;
    stack.spA = arg2;
    process_trade_target__10TObjPlayerFiPv(arg0, &stack.sp8);
}

s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s32 calc_joint_matrices__10TObjMotionFP10NJS_MOTIONfl(void *, s32, f32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 TObjPlayer__sub_801BAC48(void *);
}
void save_render_material_state(u8 *arg0);
extern "C" {
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
void TObjPlayer__sub_801D877C(u8 *arg0);
void TObjPlayer__sub_801D8864(void);

int TUnk_804C4540::set_position_from(void *pos) { return TObjBase::set_position_from(pos); }
void TUnk_804C4540::set_animation_default(s16 index) { set_animation(index); }

TUnk_804C4540 *TUnk_804C4540::create(TPlyCharData *data) {
    Rec_801D86F8 sp8;
    TUnk_804C4540 *player;
    ((TObjPlayer *)(&sp8))->init_inventory();
    copy_player_visual_record(&sp8, &data->m_disp_data.m_disp_part2);
    copy_data__6TLobbyFPvPv(sp8.c, &data->m_disp_data);
    fn_801D40D4((void *)data->m_inventory.m_num_items, (void *)((TObjPlayer *)data)->get_ptr_4(), sp8.b);
    player = (TUnk_804C4540 *)TObject::operator new(0xDB8);
    if (player != NULL) {
        player = (TUnk_804C4540 *)create_ending_sequence_player((Player_801D88C8 *)player, (void *)tl_03, (Src_801D88C8 *)&sp8);
    }
    return player;
}

void TObjPlayer__sub_801D877C(u8 *arg0) {
    if ((obj_testFlags30__14TObjCollidableFUl(arg0, 0x02000000) == 0) && ((s32) ((TUnk_804C4540 *)arg0)->m_cfc == 0)) {
        select_actor_lighting((s32)arg0);
        push_matrix();
        translate_matrix_vec3(0, (arg0 + 0x38));
        rotate_matrix_y(0, (int) (((TUnk_804C4540 *)arg0)->rotation_y));
        save_render_material_state((arg0 + 0x608));
        ((TObjPlayer *)arg0)->apply_material_color_override();
        TObjFish::set_global_param((s32)(arg0 + 0xCF4));
        TObjPlayer::set_global_flag();
        ((TObjPlayer *)arg0)->draw_saving_joints_checked();
        TObjPlayer::clear_global_state();
        ((TObjPlayer *)(arg0 + 0x608))->write_ids();
        ((TObjPlayer *)arg0)->draw_head_attachments();
        pop_matrix();
        TObjPlayer__sub_801BAC48(arg0);
        restore_scene_lighting();
        return;
    }
    push_matrix();
    translate_matrix_vec3(0, (arg0 + 0x38));
    rotate_matrix_y(0, (int) (((TUnk_804C4540 *)arg0)->rotation_y));
    ((TUnk_804C4540 *)arg0)->calc_joint_matrices(((TUnk_804C4540 *)arg0)->current_motion, ((TUnk_804C4540 *)arg0)->frame, *(s32 *)((s8 *)arg0 + 0xE0));
    pop_matrix();
}

void TObjPlayer__sub_801D8864(void) {  }

    extern int player_ending_motion_object;
void TObjPlayer::free_shared_lobby_data() { TLobby::free_nodes_with_id(player_ending_motion_object); player_ending_motion_object = 0; TObjPlayer::free_shared_data(); }
}

#include "pso/boss/TBoss4DarkFalz.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_801D8ADC_lbl_8044929C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492AC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492BC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492CC {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_801D8B8C_lbl_8044925C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044926C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044927C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044928C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8C6C_lbl_8044923C {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801D8D8C_lbl_804C49B0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_801D8E60_lbl_804C4980 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801D9328_lbl_80447430 {
    s32 value;
    u8 remaining[0x17C];
};

struct RecoveredGlobal_801A51C0_lbl_80446980 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801D92F4_lbl_804475B0 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredGlobal_801D9004_lbl_80447970 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_801D8DCC_lbl_804C4998
{
  s32 value;
  u8 remaining[0x14];
};

struct RecoveredGlobal_801D8E1C_lbl_804C498C
{
  s32 value;
  u8 remaining[0x8];
};

struct RecoveredGlobal_801D8FB4_lbl_804C495C
{
  s32 value;
  u8 remaining[0x14];
};

struct Vec_801D8CCC { f32 x, y, z; };

typedef struct Src_801D88C8 {
    u8 pad0[0x50];
    u8 slot0[0x1C];
    u8 slot1[0x40];
    u8 sub[0x18];
    f32 frame;
} Src_801D88C8;

typedef struct Player_801D88C8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x38 - 0x1C];
    u8 pos[12];
    u8 pad44[0x60 - 0x44];
    s32 ang;
    u8 pad64[0xC0 - 0x64];
    f32 frame;
    u8 padc4[0xE0 - 0xC4];
    u8 *model;
    u8 pade4[0xF8 - 0xE4];
    void *motion;
} Player_801D88C8;

typedef struct Rec_801D8F0C { f32 a, b, c; } Rec_801D8F0C;

typedef struct Rec_801D8F60 { f32 a, b, c; } Rec_801D8F60;

extern "C" {
s8 TObjPlayer__sub_801AFDBC(s8);
s32 get_main_phase();
s32 obj_isState3_324__9TObjCharaFv(int);
extern RecoveredGlobal_801D8ADC_lbl_8044929C getup_protection_ticks_table_a;
extern RecoveredGlobal_801D8ADC_lbl_804492AC getup_protection_ticks_table_b;
extern RecoveredGlobal_801D8ADC_lbl_804492BC player_getup_protection_ticks_table;
extern RecoveredGlobal_801D8ADC_lbl_804492CC player_getup_protection_ticks_table_flagged;
extern s32 game_difficulty_selection;
extern RecoveredGlobal_801D8B8C_lbl_8044925C player_hurt_protection_ticks_table;
extern RecoveredGlobal_801D8B8C_lbl_8044926C player_hurt_protection_ticks_table_flagged;
extern RecoveredGlobal_801D8B8C_lbl_8044927C player_hurt_protection_ticks_table_phase15;
extern RecoveredGlobal_801D8B8C_lbl_8044928C hurt_protection_ticks_table;
extern RecoveredGlobal_801D8C6C_lbl_8044923C lobby_entry_table;
extern RecoveredGlobal_801D8D8C_lbl_804C49B0 class_starting_inventory_table;
s32 get_class_starting_inventory(s8 arg0);
extern RecoveredGlobal_801D8E60_lbl_804C4980 player_clamped_index_table_pointers;
extern RecoveredGlobal_801D9328_lbl_80447430 class_defense_template_table;
u8 *get_class_defense_template(TObjPlayer *arg0);
extern RecoveredGlobal_801A51C0_lbl_80446980 lbl_80449254;
s32 TObjPlayer__sub_801D8C3C(void);
extern RecoveredGlobal_801A51C0_lbl_80446980 lbl_80449234;
extern RecoveredGlobal_801A51C0_lbl_80446980 lbl_804491CC;
player_stats *get_class_stat_caps(s8 arg0);
extern RecoveredGlobal_801D92F4_lbl_804475B0 class_attack_template_table;
u8 *get_class_attack_template(TObjPlayer *arg0);
stats *get_class_base_stats(s8 arg0);
extern const f32 lbl_805DC400;
extern RecoveredGlobal_801D9004_lbl_80447970 attack_recovery_count_table;
extern RecoveredGlobal_801D8DCC_lbl_804C4998 player_cast_motion_record_table;
s32 TObjPlayer__sub_801D8DCC(TObjPlayer *arg0);
extern RecoveredGlobal_801D8E1C_lbl_804C498C player_anim_table_pointers;
extern RecoveredGlobal_801D8FB4_lbl_804C495C photon_blast_motion_timing_tables;
extern u8 *hospital_position_table_by_episode[];
s32 get_max_level__10TObjPlayerFv(s32);
s32 TObjPlayer__sub_801D91B8(s32 arg0);
extern Vec_801D8CCC *guild_return_position_table_by_episode[];
Vec_801D8CCC *get_guild_return_position__10TObjPlayerFPv(void *player);
void TObjPlayer__ct(void *, void *);
extern s32 ending_sequence_player_vtable[];
extern u8 *TObjPlayer__shared_model_buffer;
extern const float lbl_805DC3F8;
s32 classify_action_state__10TObjPlayerFv(void *);
extern s32 (*player_footstep_floor_table[])[5];
s32 TBoss4DarkFalz__sub_801D94C0(void* p);
void *__dt__13TUnk_804C4540Fv(void *arg0, s16 arg1);
void TObjPlayer__sub_801D8A38(void* a0);
void TObjPlayer__sub_801D92A4(void);
void TObjPlayer__sub_801BFF80(u8 *arg0);
s32 get_contact_surface_type(s32 arg0);
void __dl__7TObjectFPv(void *);
void *__dt__10TObjPlayerFv(void *arg0, s16 arg1);
int load_encrypted_archive_data(void*);
void init__17TPlyInventoryItemFv(u8 *arg0);
}
extern int ply_level_table;
s32 get_ply_level_table_row(s8 arg0, s32 arg1);
f32 lookup_attack_marker(s32, s16, s16, s32);
extern s32 attack_marker_table[];
extern s32 attack_marker_table_dagger[];
extern s32 attack_marker_table_double_saber[];
extern s32 twin_sword_male_marker_table[];
extern s32 twin_sword_female_marker_table[];
void create_player_ending_motion(void);
void load_ply_level_tbl(void);
s32 create_named_object(s32 arg0);
    extern unsigned char lbl_80447190[];
void create_player_ending_motion(void) { TObjPlayer::alloc_shared_buffers(); player_ending_motion_object = create_named_object((s32)lbl_80447190); }

Player_801D88C8 *create_ending_sequence_player(Player_801D88C8 *self, void *parent, Src_801D88C8 *src) {
    TObjPlayer__ct(self, parent);
    self->vt = ((s32 *)&ending_sequence_player_vtable);
    ((TObjPlayer *)self)->set_floor_index(1);
    ((TObjPlayer *)self)->set_floor_index(1);
    VecCopy((Vec *)self->pos, (const Vec *)(((TObjPlayer *)(src->sub))->get_sub_object()));
    self->ang = ((TObjPlayer *)(src->sub))->get_lock_timer();
    ((TObjPlayer *)self)->select_class_action_provider();
    self->model = TObjPlayer__shared_model_buffer + get_entity_id(self) * 0xC00;
    ((TObjPlayer *)self)->init_motion((TObjMotionAction *)((TObjPlayer *)self)->get_table_entry_by_clamped_index(), (BmlMotionEntry *)*(s32 *)player_ending_motion_object, 1);
    self->frame = src->frame;
    ((TObjPlayer *)self)->set_action_flag_40();
    push_matrix();
    translate_matrix_vec3(0, self->pos);
    rotate_matrix_y(0, self->ang);
    ((void (*)(void *, void *, f32, void *))calc_joint_matrices__10TObjMotionFP10NJS_MOTIONfl)(self, self->motion, (*(const f32 *)&lbl_805DC3F8), self->model);
    pop_matrix();
    TObjPlayer::assign_lobby_slot_if_flagged((s32)self, src->slot0);
    TObjPlayer::assign_lobby_slot_if_flagged((s32)self, src->slot1);
    return self;
}

void *__dt__13TUnk_804C4540Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = ending_sequence_player_vtable;
        __dt__10TObjPlayerFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjPlayer__sub_801D8A38(void* a0) { *(short*)((char*)a0 + 0x0) = 1; *(float*)((char*)a0 + 0x4) = lbl_805DC3F8; }

void*TObjPlayer::init_inventory() { TObjPlayer::init_inventory_items((s32)((s32)((char*)this + 0x50))); TObjPlayer__sub_801BFF80((u8 *)((char*)this + 0xac)); TObjPlayer__sub_801D8A38((void*)((void*)((char*)this + 0xc0))); return this; }

s32 TObjPlayer::init_inventory_items(s32 arg0) {
    s32 var_r30;
    s32 var_r31;

    var_r31 = 0;
    var_r30 = 0;
    do {
        init__17TPlyInventoryItemFv((u8 *)(arg0 + var_r30));
        var_r31 += 1;
        var_r30 += 0x1C;
    } while (var_r31 < 2);
    return arg0;
}

typedef char RecoveredGlobal_801D8ADC_lbl_8044929C_size[sizeof(RecoveredGlobal_801D8ADC_lbl_8044929C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492AC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492AC) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492BC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492BC) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492CC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492CC) == 0x14 ? 1 : -1];
s32 *TObjPlayer::get_getup_protection_ticks() {
    s32 *arg0 = (s32 *)this;
    s32 *var_r31;
    s32 *var_r3;
    var_r31 = arg0;
    if (get_main_phase() == 0xF) {
        var_r3 = var_r31;
        if (obj_isState3_324__9TObjCharaFv((int)var_r3) != 0) {
            var_r3 = (s32 *)&player_getup_protection_ticks_table_flagged.value;
            var_r3 = (s32 *)&player_getup_protection_ticks_table_flagged.value;
            var_r3 = (s32 *)(*(s32 *)((s8 *)&player_getup_protection_ticks_table_flagged.value + (game_difficulty_selection * 4)));
            return var_r3;
        }
        var_r3 = (s32 *)&player_getup_protection_ticks_table.value;
        var_r3 = (s32 *)&player_getup_protection_ticks_table.value;
        var_r3 = (s32 *)(*(s32 *)((s8 *)&player_getup_protection_ticks_table.value + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = var_r31;
    if (obj_isState3_324__9TObjCharaFv((int)var_r3) != 0) {
        var_r3 = (s32 *)&getup_protection_ticks_table_b.value;
        var_r3 = (s32 *)&getup_protection_ticks_table_b.value;
        var_r3 = (s32 *)(*(s32 *)((s8 *)&getup_protection_ticks_table_b.value + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = (s32 *)&getup_protection_ticks_table_a.value;
    var_r3 = (s32 *)&getup_protection_ticks_table_a.value;
    var_r3 = (s32 *)(*(s32 *)((s8 *)&getup_protection_ticks_table_a.value + (game_difficulty_selection * 4)));
    return var_r3;
}

typedef char RecoveredGlobal_801D8B8C_lbl_8044925C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044925C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044926C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044926C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044927C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044927C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044928C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044928C) == 0x10 ? 1 : -1];
s32 *TObjPlayer::get_hurt_protection_ticks() {
    s32 *arg0 = (s32 *)this;
    s32 *var_r31;
    s32 *var_r3;
    var_r31 = arg0;
    if (get_main_phase() == 0xF) {
        var_r3 = var_r31;
        if (obj_isState3_324__9TObjCharaFv((int)var_r3) != 0) {
            var_r3 = (s32 *)&hurt_protection_ticks_table.value;
            var_r3 = (s32 *)&hurt_protection_ticks_table.value;
            var_r3 = (s32 *)(*(s32 *)((s8 *)&hurt_protection_ticks_table.value + (game_difficulty_selection * 4)));
            return var_r3;
        }
        var_r3 = (s32 *)&player_hurt_protection_ticks_table_phase15.value;
        var_r3 = (s32 *)&player_hurt_protection_ticks_table_phase15.value;
        var_r3 = (s32 *)(*(s32 *)((s8 *)&player_hurt_protection_ticks_table_phase15.value + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = var_r31;
    if (obj_isState3_324__9TObjCharaFv((int)var_r3) != 0) {
        var_r3 = (s32 *)&player_hurt_protection_ticks_table_flagged.value;
        var_r3 = (s32 *)&player_hurt_protection_ticks_table_flagged.value;
        var_r3 = (s32 *)(*(s32 *)((s8 *)&player_hurt_protection_ticks_table_flagged.value + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = (s32 *)&player_hurt_protection_ticks_table.value;
    var_r3 = (s32 *)&player_hurt_protection_ticks_table.value;
    var_r3 = (s32 *)(*(s32 *)((s8 *)&player_hurt_protection_ticks_table.value + (game_difficulty_selection * 4)));
    return var_r3;
}

typedef char RecoveredGlobal_801D8C6C_lbl_8044923C_size[sizeof(RecoveredGlobal_801D8C6C_lbl_8044923C) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_801A51C0_lbl_80446980_size[sizeof(RecoveredGlobal_801A51C0_lbl_80446980) == 0x18 ? 1 : -1];
s32 TObjPlayer__sub_801D8C3C(void) {
    return *(s32 *)((s8 *)&lbl_80449254.value + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_lobby_entry_ptr() {
    return (u8 *)&lobby_entry_table.value + (TLobby::get_instance() * 0xC);
}

typedef char RecoveredGlobal_801D8D8C_lbl_804C49B0_size[sizeof(RecoveredGlobal_801D8D8C_lbl_804C49B0) == 0x30 ? 1 : -1];

s32 TObjPlayer::get_guild_return_yaw() {
    return *(s32 *)((s8 *)&lbl_80449234.value + (TLobby::get_instance() * 4));
}

Vec_801D8CCC *get_guild_return_position__10TObjPlayerFPv(void *player) {
    return guild_return_position_table_by_episode[TLobby::get_instance()] + get_entity_id(player);
}

s32 TObjPlayer::get_hospital_yaw() {
    return *(s32 *)((s8 *)&lbl_804491CC.value + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_hospital_position() {
    return hospital_position_table_by_episode[TLobby::get_instance()] + (get_entity_id(this) * 0xC);
}

s32 get_class_starting_inventory(s8 arg0) {
    TObjPlayer__sub_801AFDBC(arg0);
    return *(s32 *)((s8 *)&class_starting_inventory_table.value + (arg0 * 4));
}

typedef char RecoveredGlobal_801D8E60_lbl_804C4980_size[sizeof(RecoveredGlobal_801D8E60_lbl_804C4980) == 0xC ? 1 : -1];

typedef struct RecoveredGlobal_801D8DCC_lbl_804C4998 RecoveredGlobal_801D8DCC_lbl_804C4998;
typedef char RecoveredGlobal_801D8DCC_lbl_804C4998_size[((sizeof(RecoveredGlobal_801D8DCC_lbl_804C4998)) == 0x18) ? (1) : (-1)];
s32 TObjPlayer__sub_801D8DCC(TObjPlayer *player) {
  s32 temp_r31;
  s8 *new_var;
  temp_r31 = player->get_handle_value() * 0x14;
  new_var = ((s8 *)&player_cast_motion_record_table.value) + (player->has_valid_handle() * 4);
  return (*((s32 *) new_var)) + temp_r31;
}

typedef struct RecoveredGlobal_801D8E1C_lbl_804C498C RecoveredGlobal_801D8E1C_lbl_804C498C;
typedef char RecoveredGlobal_801D8E1C_lbl_804C498C_size[((sizeof(RecoveredGlobal_801D8E1C_lbl_804C498C)) == 0xC) ? (1) : (-1)];
long TObjPlayer::get_anim_table_entry(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  int new_var;
  new_var = ((TObjPlayer *)arg0)->get_clamped_index() * 4;
  return (*((s32 *) (((s8 *)&player_anim_table_pointers.value) + new_var))) + (arg1 * 4);
}

s32 TObjPlayer::get_table_entry_by_clamped_index() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)&player_clamped_index_table_pointers.value + (((TObjPlayer *)arg0)->get_clamped_index() * 4));
}

typedef char RecoveredGlobal_801D9004_lbl_80447970_size[sizeof(RecoveredGlobal_801D9004_lbl_80447970) == 0x3C ? 1 : -1];

typedef struct RecoveredGlobal_801D8FB4_lbl_804C495C RecoveredGlobal_801D8FB4_lbl_804C495C;
typedef char RecoveredGlobal_801D8FB4_lbl_804C495C_size[((sizeof(RecoveredGlobal_801D8FB4_lbl_804C495C)) == 0x18) ? (1) : (-1)];

s32 TObjPlayer::get_footstep_floor_index() {
    s32 floor;
    s32 (*table)[5];
    floor = get_current_floor_area();
    table = player_footstep_floor_table[classify_action_state__10TObjPlayerFv(this)];
    if (floor == 0xE && TBoss4DarkFalz::get_instance_count() == 0) {
        floor = 1;
    }
    {
        s32 surf = get_floor_surface_type();
        return table[floor][surf];
    }
}

f32 TObjPlayer::get_photon_blast_complete_threshold() {
  return ((Rec_801D8F0C * *)&photon_blast_motion_timing_tables)[has_valid_handle()][get_handle_value()].c;
}

f32 TObjPlayer::get_photon_blast_upper_bound() {
  return ((Rec_801D8F60 * *)&photon_blast_motion_timing_tables)[has_valid_handle()][get_handle_value()].b;
}

f32 TObjPlayer::get_photon_blast_hold_frame() {
    s32 arg0 = (s32)this;
  s32 temp_r31;
  s32 *new_var;
  temp_r31 = ((TObjPlayer *)arg0)->get_handle_value() * 0xC;
  new_var = (s32 *) (((s8 *) (((u8 *)&photon_blast_motion_timing_tables.value) + (((s32)((TObjPlayer *)arg0)->has_valid_handle()) * 4))) + 0);
  return *((f32 *) (((s8 *) ((*new_var) + temp_r31)) + 0));
}

f32 TObjPlayer::get_attack_recovery_count() {
    s32 arg0 = (s32)this;
    s32 falz_phase;
    falz_phase = get_falz_phase();
    return (f32) (s8) *(u8 *)((s8 *)((u8 *)(((u8 *)&attack_recovery_count_table.value + (((TObjPlayer *)arg0)->get_handle_value() * 3))) + falz_phase) + 0);
}

#pragma push
#pragma scheduling off
void TObjPlayer::select_normal_attack_marker() {
  s16 temp_r30;
  s16 falz_phase;
  s16 new_var;
  s32 class_flags;
  class_flags = get_class_flags();
  new_var = ((TObjPlayer *)(((u8 *)this) + 0x7CC))->get_stage_strike_count();
  temp_r30 = new_var;
  falz_phase = this->get_falz_phase();
  lookup_attack_marker((s32) get_handle_value(), falz_phase, temp_r30, class_flags);
}

#pragma pop

f32 lookup_attack_marker(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    switch (arg0) {
    case 3:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table_dagger + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    case 14:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table_double_saber + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    case 15:
        if (arg3 & CLASS_FLAG_MALE) {
            return *(f32 *)((s8 *)((u8 *)(((u8 *)twin_sword_male_marker_table + (arg2 * 0xC))) + (arg1 * 4)) + 0);
        }
        return *(f32 *)((s8 *)((u8 *)(((u8 *)twin_sword_female_marker_table + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    default:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table + (arg0 * 0xC))) + (arg1 * 4)) + 0);
    }
}

s32 TObjPlayer__sub_801D91B8(s32 arg0) {
    return TObjPlayer::get_current_state_field(((TObjPlayer *)arg0)->get_class_index(), get_max_level__10TObjPlayerFv(arg0));
}

s32 TObjPlayer::get_current_state_field(s8 _w0, s32 _w1) {
    return *(s32 *)((s8 *)(get_ply_level_table_row(_w0, _w1)) + 8);
}

s32 TObjPlayer::get_class_state_field(s32 arg1) {
    s32 arg0 = (s32)this; return TObjPlayer::get_current_state_field(((TObjPlayer *)arg0)->get_class_index(), arg1); }

s32 get_ply_level_table_row(s8 arg0, s32 arg1) {
  s32 temp_r30;
  s32 temp_r31;
  temp_r30 = *(*(s32 * *)&ply_level_table);
  ;
  return (*((s32 *) (((s8 *) temp_r30) + (TObjPlayer__sub_801AFDBC(arg0) * 4)))) + (TObjPlayer::clamp_index_to_max(arg1) * 0xC);
}

void TObjPlayer__sub_801D92A4(void) { TLobby::free_nodes_with_id(ply_level_table); }

    extern unsigned char lbl_804492E8[];
void load_ply_level_tbl(void) { ply_level_table = load_encrypted_archive_data(lbl_804492E8); }

typedef char RecoveredGlobal_801D9328_lbl_80447430_size[sizeof(RecoveredGlobal_801D9328_lbl_80447430) == 0x180 ? 1 : -1];

typedef char RecoveredGlobal_801D92F4_lbl_804475B0_size[sizeof(RecoveredGlobal_801D92F4_lbl_804475B0) == 0x240 ? 1 : -1];

u8 *get_class_attack_template(TObjPlayer *player) {
    return (u8 *)&class_attack_template_table.value + (player->get_class_index() * 0x30);
}

u8 *get_class_defense_template(TObjPlayer *player) {
    return (u8 *)&class_defense_template_table.value + (player->get_class_index() << 5);
}

stats *get_class_base_stats(s8 arg0) {
    return player_class_base_stat_tables[TObjPlayer__sub_801AFDBC(arg0)];
}

player_stats *get_class_stat_caps(s8 arg0) {
    return (player_stats*)&player_class_stat_caps[TObjPlayer__sub_801AFDBC(arg0)];
}

player_stats *TObjPlayer::get_class_stat_entry(u8 *player) {
    return (player_stats*)&player_class_stat_caps[((TObjPlayer *)player)->get_class_index()];
}

f32 TObjPlayer::get_tp_class_factor() {
    u8 *arg0 = (u8 *)this;
    if (this->class_flags & CLASS_FLAG_ANDROID) {
        return lbl_805DC400;
    }
    return player_profession_stat_factors[((TObjPlayer *)arg0)->get_clamped_index()].tp;
}

f32 TObjPlayer::get_class_hp_factor() {
    return player_profession_stat_factors[get_clamped_index()].hp;
}

int TObjPlayer::get_floor_surface_type() { return get_contact_surface_type((s32)((char*)this + 0x360)); }
s32 TObjPlayer::get_falz_phase() { return TBoss4DarkFalz__sub_801D94C0((void*)((char*)this + 0x7cc)); }

    extern int dark_falz_form_index;
int TBoss4DarkFalz::get_instance_count() {  return dark_falz_form_index; }

s32 TBoss4DarkFalz__sub_801D94C0(void* p) { return *(s32*)((char*)p + 0x14); }
