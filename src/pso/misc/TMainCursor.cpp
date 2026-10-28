#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/TObject.h"
#include "pso/misc/TLOC_ListClear.h"
#include "pso/misc/TMainCursor_8013AE18.h"
#include "pso/misc/TMainCursor_8013B690.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TAdRicoRing.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TMainCursor_8013F104.h"
#include "pso/system/vector.h"
#include "pso/misc/TMainCursor_8013BEB8.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TLockOnCursor.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TPlyPhotonChair.h"
#include "pso/map/CurrentArea.h"

extern "C" {
s32 check_visible__11TMainCursorFv(void *, void *, s32, s32);
void *find_entity_by_id(u16 id);
u8 get_cast_technique_level(void *, s32);
void *calc_technique_parameters(s32, s32, s32);
s16 TObjPlayer__sub_801B5AF8(TObjPlayer *player, s32 index);
TObjPlayer *get_player_by_client_id(u32 id);
s32 get_record_at__11TMainCursorFPvi(void *, int);
void set_cursor_id__11TMainCursorFs(void *, s32);
void set_target_index__11TMainCursorFs(void *, s32);
u8 TMainCursor__sub_8013E900(void *);
u8 get_active__11TMainCursorFv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, s32);
s32 test_action_mask__10TObjPlayerFl(void *, s32);
int matches_type_and_enabled__11TMainCursorFiUcUc(void *, void *a1 = 0, void *a2 = 0);
u8 *TMainCursor__ct(u8 *main_cursor, s32 parent, s32 target_index, s32 target_id, s32 action_palette, s32 active,
                    u16 offset_y, f32 size);
void setup_action_channel__11TMainCursorFiPviii(TMainCursor *cursor, u8 *player, s32 slot, s32 kind, s32 id);
}

struct Target_8013B70C {
    u8 pad0[0x32E];
    s16 f32E;
    u8 pad330[0x424 - 0x330];
    u8 *f424;
};

extern "C" {
s32 is_split_screen();
s32 get_split_screen_view_index__11TCameraCtrlFUs();
s32 get_mode__11TCameraCtrlFPv(void *);
s32 render__11TMainCursorFPv(void *);
extern u8 shared_effect_texture_list[];
s32 get_entity_id(void *);
s32 TMainCursor__sub_8013E310(void *);
u8 TMainCursor__sub_8013E338(void *);
u8 TMainCursor__sub_8013E358(void *);
s8 fn_8013F24C(void *, s32);
s32 check_flag_100__10TObjPlayerFPv(void *);
s32 is_invalid_slot__10TObjPlayerFUc(u8);
s32 play_sound_effect(s32, void *, s32, s32);
s32 can_pickup_item_by_id__10TObjPlayerFP5TItem(u32, s32);

extern "C" u8 lbl_8043F090[];
extern "C" u8 lbl_8043F0A4[];
extern "C" u8 lbl_8043F0B8[];
extern "C" u8 lbl_8043F0D0[];
extern "C" u8 bm_ply_lock_on_cursor_motion_names[];
extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void run_task__14TLOC_ListClearFv();
extern void *bm_ply_lock_on_cursor_model_names[4];
void *bm_ply_lock_on_cursor_model_names[4] = {
    (void *)&lbl_8043F090, (void *)&lbl_8043F0A4, (void *)&lbl_8043F0B8, (void *)0x0,
};
void *target_cursor_resource_descriptor[4] = {
    (void *)&lbl_8043F0D0, (void *)&bm_ply_lock_on_cursor_model_names, (void *)&bm_ply_lock_on_cursor_motion_names, (void *)0x30000,
};
u8 cursor_action_priority_table[20] = {
    3, 8, 11, 5, 10, 13, 4, 9, 12, 7, 21, 22, 19, 20, 0, 16, 17, 14, 6, 0,
};
f32 target_cursor_color_table[6][4] = {
    {1.0f, 0.0f, 0.78f, 0.0f},
    {1.0f, 0.0f, 0.78f, 0.0f},
    {1.0f, 0.7f, 0.7f, 0.7f},
    {1.0f, 1.0f, 0.0f, 0.0f},
    {1.0f, 0.0f, 0.39f, 0.0f},
    {1.0f, 0.0f, 0.0f, 0.0f},
};
void *lbl_804A71C4[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__14TLOC_ListClearFv, (void *)&run_task__14TLOC_ListClearFv,
    (void *)&render__7TObjectFv, (void *)&render_shadows__7TObjectFv,
};

s32 TMainCursor::check_can_pickup() {
    s32 temp_r3;
    u32 temp_r3b;
    s32 arg0 = (s32)this;

    temp_r3 = (s32)find_entity_by_id(((TMainCursor *)(arg0 + 0x60))->get_id());
    if ((temp_r3 != 0) && ((u32) (obj_testFlags30__13TUnk_804AF8A0FUl((void *)temp_r3, 0x80000000) + 0x80000000) == 0U) && ((temp_r3b = ((TMainCursor *)arg0)->check_field_24()) != 0U) && (can_pickup_item_by_id__10TObjPlayerFP5TItem(temp_r3b, temp_r3) == 0)) {
        return 1;
    }
    return 0;
}

extern const f32 TMainCursor__data_805DB0C0;
extern const f32 TMainCursor__data_805DB0CC;
extern const f32 lbl_805DB0D0;

#pragma push
#pragma opt_common_subs off
void TMainCursor::validate_target() {
    Target_8013B70C *t;
    ((FlagWord *)(((u8 *)this) + 0x20))->clear(0xB);
    t = (Target_8013B70C *)this->check_field_24();
    if (t == NULL) {
        this->update_target_sub();
        return;
    }
    if (t->f424 == NULL) {
        this->update_target_sub();
        return;
    }
    if (((TMainCursor *)(((u8 *)this) + 0x60))->is_same_target(((TMainCursor *)(t->f424 + 0x4EC))->get_list()) == 0) {
        this->update_target_sub();
        return;
    }
    if (TMainCursor__sub_8013E358(((u8 *)this) + 0x60) != 1) {
        if (check_visible__11TMainCursorFv((u8 *)t + 0x500, t, TMainCursor__sub_8013E358(((u8 *)this) + 0x60),
                                            TMainCursor__sub_8013E338(((u8 *)this) + 0x60)) == -1) {
            set_target_index__11TMainCursorFs(t->f424 + 0x4F8, 0xFFFF);
            this->update_target_sub();
            return;
        }
    }
    if (TObjPlayer::is_any_teammate_in_state() != 0) {
        TMainCursor__sub_8013E310(this);
        return;
    }
    switch (TMainCursor__sub_8013E358(((u8 *)this) + 0x60)) {
    case 0:
        this->update_target_sub();
        return;
    case 1:
        return;
    case 2:
        if (((TObjPlayer *)t)->can_perform_physical_action() == 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 3:
        if (is_invalid_slot__10TObjPlayerFUc(get_cast_technique_level((u8 *)t + 0x428, TMainCursor__sub_8013E338(((u8 *)this) + 0x60))) != 0) {
            this->update_target_sub();
            return;
        }
        if (check_flag_100__10TObjPlayerFPv(t) == 0 && obj_testFlags30__13TUnk_804AF8A0FUl(t, 0x20006) != 0) {
            this->update_target_sub();
            return;
        }
        if (test_action_mask__10TObjPlayerFl(t, 0x548000) != 0) {
            this->update_target_sub();
            return;
        }
        if (are_items_enabled_here() == 0) {
            this->update_target_sub();
            return;
        }
        if (t->f32E - *(s16 *)((u8 *)calc_technique_parameters(TMainCursor__sub_8013E338(((u8 *)this) + 0x60),
                                                      get_cast_technique_level((u8 *)t + 0x428, TMainCursor__sub_8013E338(((u8 *)this) + 0x60)),
                                                      get_entity_id(t)) + 0x10) < 0) {
            this->update_target_sub();
            return;
        }
        return;
    case 4:
        return;
    case 5:
        if (fn_8013F24C((u8 *)t + 0x4AC, TMainCursor__sub_8013E338(((u8 *)this) + 0x60)) != (s8)TMainCursor__sub_8013F244()) {
            this->update_target_sub();
            return;
        }
        if (test_action_mask__10TObjPlayerFl(t, 0x548000) != 0) {
            this->update_target_sub();
            return;
        }
        if (are_items_enabled_here() == 0) {
            this->update_target_sub();
        }
        return;
    case 6:
    case 7:
        return;
    }
}
#pragma pop

void TMainCursor::render() {
    u8 *arg0 = (u8 *)this;
    s32 cam;
    s32 no;
    if (((TMainCursor *)arg0)->init_render_flags() != 0) {
        return;
    }
    switch (((TMainCursor *)arg0)->test_flag_2_at_20()) {
    case 0:
        break;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        ((TMainCursor *)arg0)->get_render_flag();
        cam = get_split_screen_view_index__11TCameraCtrlFUs();
        no = TCameraCtrl::get_camera_no();
        if (no != cam) {
            return;
        }
    } else if (get_mode__11TCameraCtrlFPv(((u8 *)&main_task)) & 0x10) {
        return;
    }
    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
    case 1:
        ((TMainCursor *)arg0)->update_position();
        break;
    case 2:
        break;
    default:
        return;
    }
    TObjFish::set_global_param((s32)shared_effect_texture_list);
    render__11TMainCursorFPv(arg0);
}

void TMainCursor::run_task() {
    u8 *arg0 = (u8 *)this;

    if ((s32) this->m_1c != 2) {
        ((TMainCursor *)arg0)->validate_target();
        if (((TMainCursor *)arg0)->check_flag_1() != 0) {
            this->m_1c = 2;
        }
    }
    switch (this->m_1c) {
    case 0:
        *(f32 *)&this->unk_30 = (f32) (*(f32 *)&this->unk_30 - TMainCursor__data_805DB0CC);
        if (!(*(f32 *)&this->unk_30 > *(f32 *)&this->m_34)) {
            *(f32 *)&this->unk_30 = (f32) *(f32 *)&this->unk_28;
            this->m_1c = 1;
            if (((TMainCursor *)arg0)->init_render_flags() == 0) {
                if (((TMainCursor *)arg0)->update() != 0) {
                    play_sound_effect(0x3816, (u8 *)&this->m_40, 0, 1);
                    return;
                }
                play_sound_effect(0x3111, (u8 *)&this->m_40, 0, 1);
            }
        }
    case 1:
        return;
    case 2: {
        f32 distance = ((TMainCursor *)(arg0 + 0x4C))->get_pos() - lbl_805DB0D0;
        if (distance > TMainCursor__data_805DB0C0) {
            TMainCursor__sub_8013F180((u8 *)&this->m_4c, distance);
            return;
        }
        queue_destruction__7TObjectFv(arg0);
        break;
    }
    }
}

}

struct RecoveredGlobal_8013BDCC___vt__11TMainCursor { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8013BDCC___vt__11TMainCursor_size[sizeof(RecoveredGlobal_8013BDCC___vt__11TMainCursor) == 0x18 ? 1 : -1];


extern "C" {
s32 set_offset_y__11TMainCursorFs(void *, u16);
s32 init_field_60__11TMainCursorFv(void *, u8);
s32 TMainCursor__sub_8013E6E0(void *, u8);
s32 set_target_id_at_60__11TMainCursorFUc(void *, u8);
s32 TMainCursor__sub_8013E800(void *);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__11TMainCursor[];
extern s32 main_cursor_class_name;
s32 check_field_24__11TMainCursorFv();
u8 update_sub_60__11TMainCursorFv(void *);
s32 get_rader_map__11TMainCursorFv(void *, void *);
extern const f32 TMainCursor__data_805DB0CC;
extern const f32 lbl_805DB0D4;
extern const f32 lbl_805DB0D8;
extern const f32 lbl_805DB0DC;
void *__dt__11TMainCursorFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 destroy__11TMainCursorFis(s32 arg0, s16 arg1);

void TMainCursor::update_position() {
    s32 arg0 = (s32)this;
    void *entity;

    entity = find_entity_by_id(((TMainCursor *)(arg0 + 0x60))->get_id());
    if (entity != NULL) {
        s32 base = *(s32 *)((s8 *)entity + 0xA4) + ((TMainCursor *)arg0)->is_position_moved() * 0x2C;
        VecCopy((Vec *)(arg0 + 0x40), (const Vec *)(base + 0x1C));
    }
}

void TMainCursor::refresh_target_marker() {
    s32 temp_r3;
    s32 temp_r3_2;
    temp_r3 = check_field_24__11TMainCursorFv();
    if (temp_r3 == 0) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    temp_r3_2 = check_visible__11TMainCursorFv((void *)(temp_r3 + 0x500), (void *)temp_r3, update_sub_60__11TMainCursorFv((void *)this), (u8) this->forward_13E338_at_60());
    if (temp_r3_2 == -1) {
        queue_destruction__7TObjectFv((this));
        return;
    }
    this->m_1c = 0;
    *(f32 *)&this->unk_28 = (f32) lbl_805DB0D4;
    *(f32 *)&this->m_34 = *(f32 *)&this->unk_28 - TMainCursor__data_805DB0CC;
    *(f32 *)&this->unk_38 = lbl_805DB0D8 + *(f32 *)&this->unk_28;
    *(f32 *)&this->unk_30 = *(f32 *)&this->unk_38;
    this->m_3c = lbl_805DB0DC;
    this->update_position();
    if (check_can_pickup() != 0) {
        this->check_flag_4();
    }
    if (this->update() != 0) {
        get_rader_map__11TMainCursorFv((void *) (((u8 *)this) + 0x4C), (void *)target_cursor_color_table[4]);
        return;
    }
    get_rader_map__11TMainCursorFv((void *) (((u8 *)this) + 0x4C), (void *)target_cursor_color_table[temp_r3_2]);
}

void *__dt__11TMainCursorFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TMainCursor;
        destroy__11TMainCursorFis((s32)((s8 *)arg0 + 0x60), -1);
        ((TMainCursor *)((s8 *)arg0 + 0x4C))->destroy(-1);
        ((TMainCursor *)((s8 *)arg0 + 0x24))->delete_this(-1);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TMainCursor__ct(u8 *main_cursor, s32 parent, s32 target_index, s32 target_id, s32 action_palette, s32 active,
                    u16 offset_y, f32 size) {
    __ct__7TObjectFP7TObject((void *)main_cursor, (void *)parent);
    *(s32 **)((s8 *)main_cursor + 0x18) = &(*(RecoveredGlobal_8013BDCC___vt__11TMainCursor *)&__vt__11TMainCursor).value;
    __ct__8FlagWordFv((main_cursor + 0x20));
    TMainCursor__sub_8013E800(main_cursor + 0x24);
    TMainCursor__sub_8013F1F0((main_cursor + 0x4C));
    ((TMainCursor *)(main_cursor + 0x60))->reset();
    *(s32 *)((s8 *)main_cursor + 0) = (s32) main_cursor_class_name;
    ((TMainCursor *)main_cursor)->set_target_index_at_60((void *)target_index);
    set_target_id_at_60__11TMainCursorFUc((void *)main_cursor, target_id);
    ((TMainCursor *)main_cursor)->sub_8013E724(size);
    TMainCursor__sub_8013E6E0(main_cursor, action_palette);
    init_field_60__11TMainCursorFv(main_cursor, active);
    set_offset_y__11TMainCursorFs((void *)main_cursor, offset_y);
    return main_cursor;
}

int TMainCursor::check_type_and_enabled(void* _w1, void* _w2) { return matches_type_and_enabled__11TMainCursorFiUcUc(this, _w1, _w2); }

}

typedef struct Vec_8013BF0C { f32 x, y, z; } Vec_8013BF0C;

typedef struct Vec_8013C0A0 { f32 x, y, z; } Vec_8013C0A0;

struct Vec_8013BF0C;
struct Vec_8013C0A0;
struct Coll_8013C288 { u8 pad0[0xC]; f32 radius; u8 pad10[0x18 - 0x10]; u32 flags; u8 pos[0x2C - 0x1C]; };

struct Best_8013C288 { s32 index; u8 pad4[2]; u16 id; u8 pad8[4]; f32 dist; };

extern "C" {
u8 * csnVector(s32, s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 vec3_dot(void *, void *);
extern const f32 TMainCursor__data_805DB0C0;
extern const f32 TMainCursor__data_805DB0CC;
extern const f32 lbl_805DB0E0;
s32 target_in_vertical_cone(Vec_8013BF0C *p, Vec_8013BF0C *q, s32 yaw, f32 range, f32 dist);
extern Vec_8013C0A0 lbl_8050BEE0;
s32 target_in_xz_cone(Vec_8013C0A0 *p, Vec_8013C0A0 *q, Vec_8013C0A0 *r, s32 yaw, f32 range, f32 dist);
s32 get_entity_id(void *);
s32 set_size__11TMainCursorFf(f32);
s32 TMainCursor__sub_8013F168(void *);
f32 horizontal_distance_squared(void *, void *);
s32 set_flag_bit__11TMainCursorFlUs(void *, int, int);
s32 is_technique_ready__8TTecCtrlFv();
s32 try_add_target_candidate__11TMainCursorFPvPvPvPv(u8 *cursor, u8 *player, u8 *target, Best_8013C288 *best);
struct Ent_8013C678 { u32 id; f32 key; };
void *fn_8004438C(void *p);
s32 quick_sort_partition__11TMainCursorFiPvii(s32 self, Ent_8013C678 *a, s32 lo, s32 hi);
s32 is_channel_active__11TMainCursorFv(void *self);
void TMainCursor__sub_8013F170(void *p, s32 v);
void fn_80044330(void *p);

s32 try_move__11TMainCursorFiii(s32 arg0, s32 arg1, s32 arg2) {
    if (is_channel_active__11TMainCursorFv((void *)arg0) != 0) {
        return matches_type_and_enabled__11TMainCursorFiUcUc((void*)arg0, (void*)arg1, (void*)arg2);
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 target_in_vertical_cone(Vec_8013BF0C *p, Vec_8013BF0C *q, s32 yaw, f32 range, f32 dist) {
    Vec_8013BF0C a;
    Vec_8013BF0C b;
    f32 x;
    f32 y;
    f32 z;
    if (lbl_805DB0E0 < range && range < TMainCursor__data_805DB0CC) {
        if (TMainCursor__data_805DB0C0 == dist) {
            a.x = q->x - p->x;
            a.y = TMainCursor__data_805DB0C0;
            a.z = q->z - p->z;
            b.x = a.x;
            b.y = q->y - p->y;
            b.z = a.z;
            ((TObjBoss2Tunnel *)(&a))->update_scale();
            ((TObjBoss2Tunnel *)(&b))->update_scale();
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        } else {
            x = dist * sin_table_lookup(yaw + 0x8000) + p->x;
            y = p->y;
            z = dist * cos_table_lookup(yaw + 0x8000) + p->z;
            a.x = q->x - x;
            a.y = TMainCursor__data_805DB0C0;
            a.z = q->z - z;
            b.x = a.x;
            b.y = q->y - y;
            b.z = a.z;
            ((TObjBoss2Tunnel *)(&a))->update_scale();
            ((TObjBoss2Tunnel *)(&b))->update_scale();
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 target_in_xz_cone(Vec_8013C0A0 *p, Vec_8013C0A0 *q, Vec_8013C0A0 *r, s32 yaw, f32 range, f32 dist) {
    Vec_8013C0A0 a;
    Vec_8013C0A0 b;
    f32 x;
    f32 z;
    if (lbl_805DB0E0 < range && range < TMainCursor__data_805DB0CC) {
        a.x = sin_table_lookup(yaw);
        a.y = TMainCursor__data_805DB0C0;
        a.z = cos_table_lookup(yaw);
        if (TMainCursor__data_805DB0C0 == dist) {
            b.x = q->x - p->x;
            b.y = TMainCursor__data_805DB0C0;
            b.z = q->z - p->z;
            ((TObjBoss2Tunnel *)(&b))->update_scale();
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
        } else {
            x = dist * sin_table_lookup(yaw + 0x8000) + p->x;
            z = dist * cos_table_lookup(yaw + 0x8000) + p->z;
            b.x = q->x - x;
            b.y = TMainCursor__data_805DB0C0;
            b.z = q->z - z;
            ((TObjBoss2Tunnel *)(&b))->update_scale();
            if (vec3_dot(&a, &b) < range) {
                return 0;
            }
            lbl_8050BEE0.x = q->x - r->x;
            lbl_8050BEE0.y = TMainCursor__data_805DB0C0;
            lbl_8050BEE0.z = q->z - r->z;
            ((TObjBoss2Tunnel *)(&lbl_8050BEE0))->update_scale();
            if (vec3_dot(&a, &lbl_8050BEE0) < TMainCursor__data_805DB0C0) {
                return 0;
            }
        }
    }
    return 1;
}
#pragma pop

void init_target_vector__11TMainCursorFiii(s32 arg0, s32 arg1, s32 arg2) {
    csnVector(arg2, arg1, 0x28A0);
}

s32 try_add_target_candidate__11TMainCursorFPvPvPvPv(u8 *cursor, u8 *player, u8 *target, Best_8013C288 *best) {
    f32 dist;
    s32 slot;
    s32 found;
    s32 i;
    Coll_8013C288 *c;
    s32 yaw;
    s32 stat;
    s32 j;
    slot = 0;
    found = 0;
    if (target == NULL) {
        return 0;
    }
    if ((u16)get_entity_id(target) == (u16)get_entity_id(player)) {
        return 0;
    }
    if (is_technique_ready__8TTecCtrlFv() == 0) {
        if (((TUnk_804B9870 *)target)->get_stat_by_key_state() != (stat = ((TUnk_804B9870 *)player)->get_stat_by_key_state()) && (*(u32 *)(player + 0x30) & 0x60000000) == 0x20000000 && stat != -1) {
            return 0;
        }
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(target, 0xA00) != 0) {
        return 0;
    }
    if (player == NULL || ((TObject *)player)->all_parents_unqueued_for_destruction() == 0) {
        return 0;
    }
    if (obj_testFlags30__13TUnk_804AF8A0FUl(player, ((TMainCursor *)cursor)->get_actor_include_mask()) == 0 ||
        obj_testFlags30__13TUnk_804AF8A0FUl(player, ((TMainCursor *)cursor)->get_actor_exclude_mask()) != 0) {
        return 0;
    }
    yaw = *(s32 *)(target + 0x60);
    for (i = 0; i < *(s32 *)(player + 0xA8); i++) {
        c = &(*(Coll_8013C288 **)(player + 0xA4))[i];
        if (c == NULL) {
            continue;
        }
        c->flags &= ~0x10000000;
        set_flag_bit__11TMainCursorFlUs(player, i, get_entity_id(target));
        if (!(c->flags & 1)) {
            continue;
        }
        if (!(c->flags & ((TMainCursor *)cursor)->get_body_include_mask())) {
            continue;
        }
        if (c->flags & ((TMainCursor *)cursor)->get_body_exclude_mask()) {
            continue;
        }
        dist = horizontal_distance_squared(cursor + 0x1C, c->pos);
        if (!(c->flags & 0x22000) && best->dist > dist) {
            best->dist = dist;
            best->id = get_entity_id(player);
            best->index = i;
        }
        {
            f32 r = *(f32 *)(cursor + 0x28) + c->radius;
            if (dist > r * r) {
                continue;
            }
        }
        if (is_technique_ready__8TTecCtrlFv() != 0 && (c->flags & 0xA000) &&
            ((u32 (*)(u8 *, void *, s32))init_target_vector__11TMainCursorFiii)(cursor, c->pos, *(s32 *)(target + 0xA4) + 0x1C) != 0) {
            continue;
        }
        if (target_in_xz_cone((Vec_8013C0A0 *)(cursor + 0x1C), (Vec_8013C0A0 *)c->pos, (Vec_8013C0A0 *)(target + 0x38), yaw,
                              *(f32 *)(cursor + 0x2C), *(f32 *)(cursor + 0x3C)) == 0) {
            continue;
        }
        if (target_in_vertical_cone((Vec_8013BF0C *)(cursor + 0x1C), (Vec_8013BF0C *)c->pos, yaw, *(f32 *)(cursor + 0x30),
                                      *(f32 *)(cursor + 0x3C)) == 0) {
            continue;
        }
        if (*(f32 *)(cursor + 0x18) < dist) {
            *(f32 *)(cursor + 0x18) = dist;
        }
        if (TMainCursor__sub_8013F168(cursor + 0x40) >= 10) {
            for (j = 0; j <= TMainCursor__sub_8013F168(cursor + 0x40); j++) {
                if (*(f32 *)(cursor + 0x18) == TMainCursor__sub_8013F14C((void *)get_record_at__11TMainCursorFPvi(cursor + 0x40, j))) {
                    *(f32 *)(cursor + 0x18) = dist;
                    slot = j;
                    break;
                }
            }
        } else {
            slot = TMainCursor__sub_8013F168(cursor + 0x40);
            TMainCursor__sub_8013F13C((s32 *)(cursor + 0x40));
        }
        ((void (*)(s32, f32))set_size__11TMainCursorFf)(get_record_at__11TMainCursorFPvi(cursor + 0x40, slot), dist);
        ((TMainCursor *)(get_record_at__11TMainCursorFPvi(cursor + 0x40, slot)))->set_field2(i);
        set_cursor_id__11TMainCursorFs((void *)get_record_at__11TMainCursorFPvi(cursor + 0x40, slot), get_entity_id(player));
        found = 1;
    }
    return found;
}

void TMainCursor::reset_cursor_parts() {
    u8 *arg0 = (u8 *)this;
    s32 var_r30;

    TMainCursor__sub_8013F170(((u8 *)&this->m_40), 0);
    var_r30 = 0;
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) TMainCursor__data_805DB0C0;
    do {
        get_record_at__11TMainCursorFPvi((u8 *)&this->m_40, var_r30);
        set_size__11TMainCursorFf(TMainCursor__data_805DB0C0);
        set_cursor_id__11TMainCursorFs((void *)get_record_at__11TMainCursorFPvi((u8 *)&this->m_40, var_r30), 0xFFFF);
        var_r30 += 1;
    } while (var_r30 < 0xA);
}

s32 quick_sort_partition__11TMainCursorFiPvii(s32 self, Ent_8013C678 *a, s32 lo, s32 hi) {
    Ent_8013C678 tmp;
    f32 pivot;
    s32 i;
    s32 j;

    fn_8004438C(&tmp);
    j = hi;
    i = lo - 1;
    pivot = a[hi].key;
    for (;;) {
        while (a[++i].key < pivot) {
        }
        while (i < --j && pivot < a[j].key) {
        }
        if (i >= j) {
            break;
        }
        TMainCursor::store_sorted_record((void*)self, &a[i], &tmp);
        TMainCursor::store_sorted_record((void*)self, &a[j], &a[i]);
        TMainCursor::store_sorted_record((void*)self, &tmp, &a[j]);
    }
    TMainCursor::store_sorted_record((void*)self, &a[i], &tmp);
    TMainCursor::store_sorted_record((void*)self, &a[hi], &a[i]);
    TMainCursor::store_sorted_record((void*)self, &tmp, &a[hi]);
    return i;
}

void TMainCursor::quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    if (arg2 < arg3) {
        temp_r3 = ((s32 (*)(void))quick_sort_partition__11TMainCursorFiPvii)();
        TMainCursor::quick_sort(arg0, arg1, arg2, temp_r3 - 1);
        TMainCursor::quick_sort(arg0, arg1, temp_r3 + 1, arg3);
    }
}

void TMainCursor::reset_slots() {
    s32 arg0 = (s32)this;
    s32 i;
    s32 base;

    base = arg0 + 0x5C;
    i = 0;
    do {
        fn_80044330((void *)(base + 0x40));
        ((TMainCursor *)(base + 0x9C))->reset_slot();
        i += 1;
        base += 0x124;
    } while (i < 4);
}

void TMainCursor::init_slots() { { int i; for (i = 0; i < 4; i++) { init_slot((s32)((void*)i)); } } }

s32 TMainCursor::find_by_pos(s16 arg1, s16 arg2) {
    s32 arg0 = (s32)this;
    s32 i;
    s32 ptr;

    i = 0;
    ptr = arg0 + 0x5C;
loop_1:
    if ((arg1 == (s32) TMainCursor__sub_8013E900((void *)ptr)) && (arg2 == (s32) get_active__11TMainCursorFv((void *)ptr)) && (((TMainCursor *)ptr)->get_selected_entry() != 0)) {
        return ptr;
    }
    i += 1;
    ptr += 0x124;
    if (i >= 4) {
        return 0;
    }
    goto loop_1;
}

s32 check_flag_100__10TObjPlayerFPv(void *player);
s32 is_key_machine_ready__10TObjPlayerFv();
s32 TMainCursor__sub_8013E2A0(void *list);
s16 TMainCursor__sub_8013E298(void *entry);
s16 TMainCursor__sub_8013E920(void *entry);
void TMainCursor__sub_8013E928(void *entry, s16 v);
void TMainCursor__sub_8013E930(void *entry, s8 v);
}

struct ActionCursor_8013C924 {
    u8 pad0[0x24];
    TMainCursor actions;
    u8 pad8C[0x520 - 0x24 - sizeof(TMainCursor)];
    TMainCursor channel;
};

s32 TMainCursor::bind_action_channels() {
    ActionCursor_8013C924 *self = (ActionCursor_8013C924 *)this;
    s32 i;
    s32 player;
    u8 type;
    s32 slot;
    s32 count;
    u8 enabled;
    u8 *entry;

    if (is_cursor_clear() == 0) {
        return;
    }
    if (TCameraCtrl::get_mode() != 0) {
        return;
    }
    player = (s32)get_player_by_client_id(((TLockOnCursor *)this)->get_target_id());
    if (player == 0) {
        return;
    }
    if (check_flag_100__10TObjPlayerFPv((void *)player) != 0 && is_channel_active__11TMainCursorFv(&self->channel) != 0) {
        type = self->channel.get_type();
        enabled = self->channel.get_enabled();
        if (are_items_enabled_here() == 0) {
            if (is_key_machine_ready__10TObjPlayerFv() == 0) {
                return;
            }
            if (type != 4) {
                return;
            }
            if (enabled != 10) {
                return;
            }
        }
        setup_action_channel__11TMainCursorFiPviii(this, (u8 *)player, 0, type, enabled);
        return;
    }
    count = TMainCursor__sub_8013E2A0(&self->actions);
    entry = (u8 *)self->actions.get_index();
    for (i = 0; i < count; i++) {
        TMainCursor__sub_8013E930(entry, get_action_cursor_priority(this, player, i));
        TMainCursor__sub_8013E928(entry, i);
        entry += 4;
    }
    self->actions.sort_actions_by_priority();
    entry = (u8 *)self->actions.get_index();
    slot = 0;
    for (i = 0; i < count; i++) {
        if (TMainCursor__sub_8013E298(entry) != 0) {
            setup_action_channel__11TMainCursorFiPviii(this, (u8 *)player, slot, TObjPlayer__sub_801B5AF8((TObjPlayer *)player, TMainCursor__sub_8013E920(entry)), (s16)((TObjPlayer *)player)->get_action_palette_entry(TMainCursor__sub_8013E920(entry)));
            slot++;
        }
        entry += 4;
    }
}

struct TLockOnCursor;
struct Item_8013D4A0 { u16 id; s16 idx; f32 size; };

struct Part_8013D4A0 { u8 pad0[0xC]; f32 fC; u8 pad10[8]; s32 flags; u8 pad1C[0x10]; };

struct Sub_8013D4A0 { u8 pad0[0x40]; u8 x40[0x5C]; u8 x9C[0x88]; };

struct Self_8013D4A0 { u8 pad0[0x5C]; Sub_8013D4A0 subs[3]; u8 pad3C8[0x124]; u8 x4EC[0xC]; u8 x4F8[0x10]; u16 x508; s16 x50A; };

struct Ent_8013D4A0 { u8 pad0[0xA4]; Part_8013D4A0 *parts; };

struct Cursor_8013CDE4 {
    u8 pad0[0x1C];
    f32 pos[3];
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 f34;
    s32 f38;
    f32 f3c;
    u8 f40[0x9C - 0x40];
    u8 f9c[0x124 - 0x9C];
};

struct Main_8013CDE4 { u8 pad0[0x5C]; Cursor_8013CDE4 cursors[4]; };

struct Tech_8013CDE4 { u8 pad0[8]; f32 f8; f32 fc; u8 pad10[0x18 - 0x10]; s32 f18; s32 f1c; u8 pad20[2]; s8 f22; };

struct Weapon_8013CDE4 { f32 f0; f32 f4; s32 f8; s32 fc; s32 f10; };

extern "C" {
int TLockOnCursor__sub_8013EB34(void);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
s32 draw_chunk_object();
extern u8 shared_effect_texture_list[];
extern u8 *camera_ctrl_instance;
extern const f32 TMainCursor__data_805DB0C0;
s32 is_effect_channel_active__10TObjPlayerFll(s32, s32);
void *TObjPlayer__sub_80116620(void *, s32);
void get_action_palette__11TMainCursorFv(void *, u8);
void update_action_palette__11TMainCursorFv(void *, u8);
void TMainCursor__sub_8013E9C0(void *, s32);
void TMainCursor__sub_8013EA00(void *, s32);
s32 update_cursor_pos__13TLockOnCursorFv(void *);
s32 TLockOnCursor__sub_8013EB2C(void *);
s32 TMainCursor__sub_8013F168(void *p);
void TMainCursor__sub_80154230(void *arg0, s32 arg1, u16 arg2);
void *__nw__7TObjectFUl(u32);
extern s32 tl_loc_end;
void publish_target_list__11TMainCursorFPvi(Self_8013D4A0 *arg0, s32 arg1);
s32 obj_isState3_324__13TUnk_804806E8Fv(void *);
s32 get_entity_id(void *);
void *get_item_field_6__10TObjPlayerFPv(void *);
s32 get_type__10TObjPlayerFPv(void *p);
void fn_80044330(void *p);
Weapon_8013CDE4 *get_weapon_range_record(void *, s32);
s32 check_type_and_enabled__11TMainCursorFPvPv(Cursor_8013CDE4 *, u8, u8);
int TMainCursor__sub_8013E9A0(void *p);
s32 TMainCursor__sub_8013E9E0(Cursor_8013CDE4 *, u8);
Tech_8013CDE4 *get_photon_blast_entry__10TObjPlayerFi(s16);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern f32 lbl_8050BF60[3];
extern const f32 interaction_cursor_radius;
extern const f32 ryuker_cursor_forward_offset;
s32 TMainCursor__sub_8013E970(s32, u16, s32, s32);
s32 TObjPlayer__sub_801B066C(s32);
s32 get_selected_entry__11TMainCursorFv(s32, s32);
s32 is_technique_ready__8TTecCtrlFv();

void TMainCursor::set_cursor_pos(u16 arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    u32 eq = (u32) __cntlzw((u32) ((u16) ((TMainCursor *)(arg0 + 0x4F8))->get_id() - (u16) arg1)) >> 5;
    TMainCursor__sub_8013E970(arg0 + 0x508, arg1, arg2, eq + 1);
}

s32 TMainCursor::get_action_cursor_priority(void *arg0, s32 player, s32 index) {
    u16 kind;
    u16 sub;
    kind = TObjPlayer__sub_801B5AF8((TObjPlayer *)player, index);
    sub = ((TObjPlayer *)player)->get_action_palette_entry(index);
    switch (kind) {
    case 1:
        if (is_effect_channel_active__10TObjPlayerFll(player, 0) != 0) {
            return 1;
        }
        break;
    case 2:
        if (((TObjPlayer *)player)->check_mode_action(sub) != 0) {
            return 2;
        }
        break;
    case 3:
        if (TObjPlayer::try_camera_action(player, sub) != 0) {
            return cursor_action_priority_table[sub];
        }
        break;
    case 4:
        if (is_effect_channel_active__10TObjPlayerFll(player, index) != 0 && are_items_enabled_here() != 0 && test_action_mask__10TObjPlayerFl((void *)player, 0x43001E) != 0 && ((s32)sub == 0xA || (s32)sub == 9)) {
            return 0xF;
        }
        break;
    case 5:
        return (s8)(sub + 3);
    default:
        return 0;
    }
    return 0;
}

void TMainCursor::set_cursor_color(s32 arg0, s32 arg1, s32 arg2) {
    if (get_type__10TObjPlayerFPv((void *)(arg1 + 0x828)) != 0) {
        ((TMainCursor *)arg2)->set_color(0xA000);
        ((TMainCursor *)arg2)->set_color_mode(0x70000000);
        return;
    }
    ((TMainCursor *)arg2)->set_color(0x8000);
    ((TMainCursor *)arg2)->set_color_mode(0x60000000);
}

void TMainCursor::set_display_flags(s32 arg0, s32 arg1, s32 arg2) {
    ((TMainCursor *)arg2)->set_color(0x2000);
    ((TMainCursor *)arg2)->set_color_mode(0x10000000);
    ((TMainCursor *)arg2)->set_flags(0xE0000800);
    if (is_technique_ready__8TTecCtrlFv() == 0) {
        ((TMainCursor *)arg2)->set_field_0c(0x30000);
        return;
    }
    if (TObjPlayer__sub_801B066C(arg1) == 1) {
        ((TMainCursor *)arg2)->set_field_0c(0x40030000);
        return;
    }
    ((TMainCursor *)arg2)->set_field_0c(0x40030000);
}

void TMainCursor::setup_flags(s32 arg0, s32 arg1, s32 arg2) {
    ((TMainCursor *)arg2)->set_color(0x2000);
    ((TMainCursor *)arg2)->set_field_0c(0x3C000);
    ((TMainCursor *)arg2)->set_color_mode(0x800);
    ((TMainCursor *)arg2)->set_flags(0xE0000000);
}

#pragma push
#pragma fp_contract on
#define C_8013CDE4 ((s32)cur)
#define TECH_8013CDE4(t)                                          \
    cur->f3c = (t)->fc;                                           \
    cur->f28 = (t)->f8 + cur->f3c;                                \
    cur->f34 = (t)->f18;                                          \
    cur->f2c = cos_table_lookup(cur->f34);              \
    cur->f38 = (t)->f1c;                                          \
    cur->f30 = cos_table_lookup(cur->f38);
void setup_action_channel__11TMainCursorFiPviii(TMainCursor *self, u8 *player, s32 slot, s32 kind, s32 id) {
    Cursor_8013CDE4 *cur;
    Tech_8013CDE4 *tech;
    Weapon_8013CDE4 *wpn;
    s16 sid;
    if (player == NULL) {
        return;
    }
    cur = &((Main_8013CDE4 *)self)->cursors[slot];
    if (check_type_and_enabled__11TMainCursorFPvPv(cur, kind, id) == 0) {
        fn_80044330(cur->f40);
        ((TMainCursor *)(cur->f9c))->reset_slot();
    }
    TMainCursor__sub_8013E9E0(cur, kind);
    ((void (*)(void *, u8))TMainCursor__sub_8013E9C0)(cur, id);
    switch ((s16)kind) {
    case 1:
        if (obj_isState3_324__13TUnk_804806E8Fv(player) == 0) {
            TMainCursor__sub_8013E9A0(cur);
            ((TMainCursor *)C_8013CDE4)->set_color(0x20000);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0xC0000000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x30040800);
            ((TMainCursor *)cur)->set_type(1);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            cur->f3c = TMainCursor__data_805DB0C0;
            cur->f28 = interaction_cursor_radius;
            cur->f34 = 0x8000;
            cur->f38 = 0x8000;
            cur->f2c = cos_table_lookup(cur->f34);
            cur->f30 = cos_table_lookup(cur->f38);
        }
        break;
    case 4:
        switch ((s16)id) {
        case 10:
            tech = (Tech_8013CDE4 *)calc_technique_parameters(0xF, 0xE, get_entity_id(player));
            TMainCursor__sub_8013E9A0(cur);
            TECH_8013CDE4(tech)
            ((TMainCursor *)cur)->set_type(tech->f22);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::set_display_flags((s32)self, (s32)player, C_8013CDE4);
            break;
        case 9:
            tech = (Tech_8013CDE4 *)calc_technique_parameters(0x11, 0xE, get_entity_id(player));
            TMainCursor__sub_8013E9A0(cur);
            TECH_8013CDE4(tech)
            ((TMainCursor *)cur)->set_type(tech->f22);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::setup_flags((s32)self, (s32)player, C_8013CDE4);
            break;
        }
        break;
    case 2:
        wpn = get_weapon_range_record(get_item_field_6__10TObjPlayerFPv(player), id);
        TMainCursor__sub_8013E9A0(cur);
        TMainCursor::set_cursor_color((s32)self, (s32)player, C_8013CDE4);
        ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
        ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
        VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
        cur->f3c = wpn->f4;
        cur->f28 = wpn->f0 + cur->f3c;
        cur->f34 = wpn->f8;
        cur->f38 = wpn->fc;
        cur->f2c = cos_table_lookup(cur->f34);
        cur->f30 = cos_table_lookup(cur->f38);
        ((TMainCursor *)cur)->set_type(wpn->f10);
        break;
    case 3: {
        s32 f1c = get_entity_id(player);
        s32 lvl = get_cast_technique_level(player + 0x428, id);
        sid = id;
        tech = (Tech_8013CDE4 *)calc_technique_parameters(sid, lvl, f1c);
        TMainCursor__sub_8013E9A0(cur);
        TECH_8013CDE4(tech)
        ((TMainCursor *)cur)->set_type(tech->f22);
        switch (sid) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 18:
            TMainCursor::set_cursor_color((s32)self, (s32)player, C_8013CDE4);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            break;
        case 14:
            ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x60000000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0x40800);
            lbl_8050BF60[0] = ryuker_cursor_forward_offset * sin_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x2FC);
            lbl_8050BF60[1] = *(f32 *)(player + 0x300);
            lbl_8050BF60[2] = ryuker_cursor_forward_offset * cos_table_lookup(*(s32 *)(player + 0x60)) + *(f32 *)(player + 0x304);
            VecCopy((Vec *)cur->pos, (const Vec *)lbl_8050BF60);
            break;
        case 10:
        case 13:
        case 15:
        case 16:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::set_display_flags((s32)self, (s32)player, C_8013CDE4);
            break;
        case 11:
        case 12:
            if (get_type__10TObjPlayerFPv((player + 0x828)) != 0) {
                ((TMainCursor *)C_8013CDE4)->set_color(0xA000);
                ((TMainCursor *)C_8013CDE4)->set_color_mode(0x30000000);
            } else {
                ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
                ((TMainCursor *)C_8013CDE4)->set_color_mode(0x20000000);
            }
            ((TMainCursor *)C_8013CDE4)->set_field_0c(0x30000);
            ((TMainCursor *)C_8013CDE4)->set_flags(0xC0040800);
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            break;
        case 17:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            TMainCursor::setup_flags((s32)self, (s32)player, C_8013CDE4);
            break;
        }
        break;
    }
    case 5: {
        s16 pid = id;
        tech = get_photon_blast_entry__10TObjPlayerFi(pid);
        TMainCursor__sub_8013E9A0(cur);
        if (get_type__10TObjPlayerFPv((player + 0x828)) == 0) {
            ((TMainCursor *)C_8013CDE4)->set_color(0x8000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x20000000);
        } else {
            ((TMainCursor *)C_8013CDE4)->set_color(0xA000);
            ((TMainCursor *)C_8013CDE4)->set_color_mode(0x30000000);
        }
        ((TMainCursor *)C_8013CDE4)->set_field_0c(0);
        ((TMainCursor *)C_8013CDE4)->set_flags(0xD0040800);
        TECH_8013CDE4(tech)
        switch (pid) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            VecCopy((Vec *)cur->pos, (const Vec *)(player + 0x2FC));
            ((TMainCursor *)cur)->set_type(0xA);
            break;
        }
        break;
    }
    }
}
#pragma pop

void TMainCursor::sort_list(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r4;

    temp_r4 = arg1 * 0x124;
    temp_r30 = arg0 + temp_r4 + 0x5C;
    if (get_selected_entry__11TMainCursorFv(temp_r30, temp_r4) != 0) {
        temp_r31 = TMainCursor__sub_8013F168((void *)(temp_r30 + 0x40));
        TMainCursor::quick_sort(temp_r30, get_record_at__11TMainCursorFPvi((void *)(temp_r30 + 0x40), 0), 0, temp_r31 - 1);
    }
}
void publish_target_list__11TMainCursorFPvi(Self_8013D4A0 *arg0, s32 arg1) {
    s32 count;
    s32 i;
    Sub_8013D4A0 *sub;
    Item_8013D4A0 *item;
    s32 n;
    Ent_8013D4A0 *ent;
    Part_8013D4A0 *part;
    s32 mode;
    void *cur;
    void *list;
    sub = &arg0->subs[arg1];
    count = 0;
    item = (Item_8013D4A0 *)get_record_at__11TMainCursorFPvi(sub->x40, 0);
    n = TMainCursor__sub_8013F168(sub->x40);
    for (i = 0; i < n; i++, item++) {
        if (item->id == 0xFFFF) {
            continue;
        }
        ent = (Ent_8013D4A0 *)find_entity_by_id(item->id);
        if (ent == NULL) {
            continue;
        }
        part = &ent->parts[item->idx];
        if (part == NULL) {
            continue;
        }
        if (count >= TLockOnCursor__sub_8013EB2C(sub)) {
            break;
        }
        mode = 0;
        if (arg0->x508 != 0xFFFF) {
            if (arg0->x508 == item->id && arg0->x50A == item->idx) {
                if (((TMainCursor *)(arg0->x4F8))->get_id() == 0xFFFF) {
                    mode = 2;
                } else {
                    mode = 1;
                }
            } else if (TLockOnCursor__sub_8013EB2C(sub) > 1) {
                mode = 1;
            }
        } else if (((TMainCursor *)(arg0->x4F8))->get_id() == 0xFFFF) {
            mode = 2;
        } else {
            mode = 1;
        }
        if (mode == 0) {
            continue;
        }
        if (TMainCursor__sub_8013E900(sub) == 1) {
            if (mode == 1) {
                continue;
            }
            TMainCursor__sub_8013E9C0(sub, (u8)((TUnk_804AF8A0 *)ent)->get_cursor_action());
        }
        cur = TObjPlayer__sub_80116620(sub->x9C, count);
        set_cursor_id__11TMainCursorFs(cur, item->id);
        ((TMainCursor *)cur)->set_size(item->size);
        ((TMainCursor *)cur)->set_field2(item->idx);
        ((TLockOnCursor *)cur)->update_ring_sub();
        if (((TLockOnCursor *)arg0)->is_inactive() == 0 || ((TMainCursor *)ent)->test_button(item->idx, ((TLockOnCursor *)arg0)->get_target_id()) != 0 || (part->flags & 0x08000000)) {
            ((TLockOnCursor *)cur)->is_bit1_set();
        }
        if (mode == 1) {
            ((TLockOnCursor *)cur)->update_ring();
        } else {
            ((TLockOnCursor *)cur)->set_flag_8_bit0();
            if (((TMainCursor *)ent)->test_button(item->idx, ((TLockOnCursor *)arg0)->get_target_id()) == 0) {
                list = ((TMainCursor *)(arg0->x4EC))->get_list();
                set_target_index__11TMainCursorFs(list, item->id);
                update_action_palette__11TMainCursorFv(list, TMainCursor__sub_8013E900(sub));
                get_action_palette__11TMainCursorFv(list, get_active__11TMainCursorFv(sub));
                ((TMainCursor *)list)->set_target_id(item->idx);
                if (update_cursor_pos__13TLockOnCursorFv(arg0->x4EC) == 0 && ((TLockOnCursor *)cur)->render_part() == 0) {
                    cur = __nw__7TObjectFUl(0x68);
                    if (cur != NULL) {
                        cur = TMainCursor__ct((u8 *)cur, tl_loc_end, item->id, item->idx, (s32)TMainCursor__sub_8013E900(sub), (s32)get_active__11TMainCursorFv(sub), ((TLockOnCursor *)arg0)->get_target_id(), part->fC);
                    }
                    if (cur != NULL) {
                        ((TMainCursor *)cur)->refresh_target_marker();
                    }
                }
            }
        }
        part->flags |= 0x10000000;
        TMainCursor__sub_80154230(ent, item->idx, ((TLockOnCursor *)arg0)->get_target_id());
        count++;
    }
    TMainCursor__sub_8013EA00(sub->x9C, count);
    set_cursor_id__11TMainCursorFs(TObjPlayer__sub_80116620(sub->x9C, count), 0xFFFF);
}
}
void offset_point_toward_camera(u8 *arg0, u8 *arg1, f32 farg0);

void TLockOnCursor::renderSecondaryCursor(u8 *arg1, s32 arg2, s32 arg3) {
    const s32 arg0 = (s32)this;
    f32 sp8[3];
    f32 temp_f31;
    s32 temp_r3_2;
    u32 player;
    if (is_inactive() != 0) {
        player = (u32)get_player_by_client_id((get_target_id()));
        if (player != 0U) {
            temp_r3_2 = check_visible__11TMainCursorFv((void *)(player + 0x500), (void *)player, arg2, arg3);
            if (temp_r3_2 != -1) {
                TObjFish::set_global_param((s32)&shared_effect_texture_list);
                temp_f31 = *(f32 *)((s8 *)arg1 + 0xC);
                push_matrix();
                offset_point_toward_camera(arg1 + 0x1C, (u8 *)&sp8, (f32)temp_f31);
                translate_matrix_vec3((u8 *)(0), (u8 *)&sp8);
                rotate_matrix_y(0, (int) (*(s32 *)((s8 *)camera_ctrl_instance + 0x194)));
                TParticleCtrl::begin_effect_render();
                push_matrix();
                translate_matrix(0, TMainCursor__data_805DB0C0, temp_f31, TMainCursor__data_805DB0C0);
                TPlyPhotonChair::update_parts2((void *)(arg0 + 0x48));
                TPlyPhotonChair::play_sound_with_arg((void *)(arg0 + 0x48), (void *)target_cursor_color_table[5]);
                TMainCursor::get_cursor_state();
                draw_chunk_object();
                TPlyPhotonChair::play_sound_with_arg((void *)(arg0 + 0x48), (void *)target_cursor_color_table[temp_r3_2]);
                TLockOnCursor__sub_8013EB34();
                draw_chunk_object();
                TPlyPhotonChair::update_parts((void *)(arg0 + 0x48));
                pop_matrix();
                TParticleCtrl::end_effect_render();
                pop_matrix();
            }
        }
    }
}
