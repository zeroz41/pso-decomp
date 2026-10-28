#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TMainTask.h"
#include "pso/unk/text_80141550.h"
#include "pso/TObject.h"
#include "pso/misc/TOTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TOTrapSeabed01.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer_80083594.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"

#include "pso/object/TObjDoorJung.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOTrapAncient02.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"

extern "C" {
__declspec(section ".sdata2") extern const f32 lbl_805DE640[1] = { 1.0f };
__declspec(section ".sdata2") extern const f32 TOTrapSeabed01__data_805DE644[1] = { 0.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DE648[1] = { 0.5f };
__declspec(section ".sdata2") extern const f32 lbl_805DE64C[1] = { 15.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DE650[1] = { 0.1f };
__declspec(section ".sdata2") extern const f32 lbl_805DE654[1] = { 10.0f };
__declspec(section ".sdata2") extern const f32 lbl_805DE658[2] = { 30.0f, 0.0f };
}

#define lbl_805DE640 (lbl_805DE640[0])
#define TOTrapSeabed01__data_805DE644 (TOTrapSeabed01__data_805DE644[0])
#define lbl_805DE648 (lbl_805DE648[0])
#define lbl_805DE64C (lbl_805DE64C[0])
#pragma push

struct VBase_18_f37bb9 { char pad[0x18]; };

struct VObj_18_f37bb9 : VBase_18_f37bb9 {
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
    virtual s32 m20(s32, f32);
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
    virtual void m63();
    virtual void m64();
    virtual s32 m65(f32);
};

struct Vec_802C9E3C { f32 x, y, z; };

struct Mtx_802C9E3C { f32 m[3][4]; };

struct SeabedTrapFragmentSpawn {
    s32 id;
    Vec_802C9E3C pos;
    s32 arg;
};

struct Params_802C9E3C {
    u8 pad0[0xC];
    Vec_802C9E3C pos;
    u8 pad18[0x40 - 0x18];
    s32 model;
    s32 f44;
    u8 pad48[0x50 - 0x48];
    s32 arg;
    u8 pad54[0x64 - 0x54];
};

struct Trap_802C9E3C {
    u8 pad0[0x38];
    Vec_802C9E3C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
};

struct Pair_802C9F70 { s32 a; s32 b; };

struct VBase_802C9F70 { char pad[0x18]; };

struct VObj_802C9F70 : VBase_802C9F70 {
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
    virtual void m21(void *, Pair_802C9F70 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
};

struct Trap_802C9F70 {
    u8 pad0[0x350];
    Pair_802C9F70 pair;
};

extern "C" {
s32 submit_cursor_candidate(void *, int);
void vfunc_82__14TOTrapSeabed01Fv(u8 *arg0);
u16 find_nearest_visible_player(void *, int, f32);
f32 horizontal_distance_squared(void *, void *);
f32 TObjPlayer__sub_8017A1A4(int, int);
s32 send_6x2C_impose_hold(int, void *, int, int, f32);
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
void check_hold_player__14TOTrapSeabed01FPv(u8 *arg0);
void vfunc_81__14TOTrapSeabed01Fv(u8 *arg0);
s32 get_bml_model(int, int);
s32 set_position_xy__10TObjPlayerFff(f32, f32);
void *spawn_particle_effect(void *pos, s32 id);
u8 *copy_transform__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
void *__nw__7TObjectFUl(int);
s32 __ct__13TObjSuisoChipFv(void *, void *, void *);
s32 matrix_mult_vec(void *, void *, void *);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void set_matrix_identity(u8 *arg0);
s32 rotate_matrix_y(void *, int);
extern u8 TOTrapSeabed01__transform_params[];
extern SeabedTrapFragmentSpawn seabed_trap_fragment_spawns[];
extern s32 TOTrapSeabed01__bml_resource;
extern s32 TOTrapSeabed01__texture_file;
void TOTrapSeabed01__vt83(Trap_802C9E3C *self);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
s32 is_valid_and_active__10TObjPlayerFUl();
extern s32 lbl_805D3530;
s32 vfunc_67__14TOTrapSeabed01Ff(Trap_802C9F70 *self);
void TOTrapSeabed01__vt20(s32 arg0, s32 arg1, f32 farg0);
s32 receive_physical_attack__6TOTrapFPvf(s32, s32, f32);
s32 sub_802C9D38__14TOTrapSeabed01Fv();

void TOTrapSeabed01__vt20(s32 arg0, s32 arg1, f32 farg0) {
    sub_802C9D38__14TOTrapSeabed01Fv();
    receive_physical_attack__6TOTrapFPvf(arg0, arg1, farg0);
}

extern u32 TOTrapSeabed01__ginja_model;

void TOTrapSeabed01__vt83(Trap_802C9E3C *self) {
    Mtx_802C9E3C m;
    Params_802C9E3C p;
    SeabedTrapFragmentSpawn *e;
    s32 i;
    f32 y;
    void *o;
    copy_transform__8TObjChipFPvPv((u8 *)&p, (u8 *)TOTrapSeabed01__transform_params);
    y = TOTrapSeabed01__data_805DE644;
    p.f44 = TOTrapSeabed01__texture_file;
    for (i = 0; i < 6; i++) {
        e = &seabed_trap_fragment_spawns[i];
        VecCopy((Vec *)&p.pos, (const Vec *)&e->pos);
        p.model = get_bml_model(TOTrapSeabed01__bml_resource, e->id);
        p.arg = e->arg;
        o = __nw__7TObjectFUl(0x24C);
        if (o != NULL) {
            __ct__13TObjSuisoChipFv(o, self, &p);
        }
        Vec_802C9E3C v = p.pos;
        v.y = y;
        set_matrix_identity((u8 *)&m);
        translate_matrix_vec3((u8 *)&m, (u8 *)&self->pos);
        rotate_matrix_y(&m, self->rotY);
        matrix_mult_vec(&m, &v, &v);
        if (spawn_particle_effect(&v, 0x8B) != 0) {
            set_position_xy__10TObjPlayerFff(lbl_805DE648, lbl_805DE648);
        }
    }
    ((TOTrapSeabed01 *)self)->sub_802C9C18(1);
}

int TOTrapSeabed01::vfunc_67(f32) {
    s32 i;
    VObj_802C9F70 *o;
    for (i = 0; i < 0x10; i++) {
        o = (VObj_802C9F70 *)TObjPlayer::get_battle_param(i);
        if (is_valid_and_active__10TObjPlayerFUl() != 0 && check_value_equals__13TUnk_804B6C24Fl(o, lbl_805D3530) != 0) {
            Pair_802C9F70 p = ((Trap_802C9F70 *)this)->pair;
            o->m21(this, &p, 0, -1, -1);
            if (((Trap_802C9F70 *)this)->pair.a < 5) {
                o->m23(((Trap_802C9F70 *)this), TOTrapSeabed01__data_805DE644);
            }
        }
    }
    return 1;
}

#pragma push
#pragma fp_contract on
void check_hold_player__14TOTrapSeabed01FPv(u8 *trap_seabed01) {
    f32 temp_f0;
    f32 temp_f31;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 id;
    *(u32 *)((s8 *)trap_seabed01 + 0x2A8) = 0U;
    ((TOTrapSeabed01 *)trap_seabed01)->player = find_nearest_visible_player(trap_seabed01, 0, (f32) (((TOTrapSeabed01 *)trap_seabed01)->range));
    id = ((TOTrapSeabed01 *)trap_seabed01)->player;
    if ((id != 0xFFFF) && (temp_r3 = (u32)get_player_by_client_id(id), *(u32 *)((s8 *)trap_seabed01 + 0x2A8) = temp_r3, temp_r3_2 = *(u32 *)((s8 *)trap_seabed01 + 0x2A8), ((temp_r3_2 == 0U) == 0))) {
        temp_f31 = horizontal_distance_squared((void *)(temp_r3_2 + 0x38), (void *)(trap_seabed01 + 0x38));
        ((TOTrapSeabed01 *)trap_seabed01)->dist = (f32) (((TOTrapSeabed01 *)trap_seabed01)->dist - TObjPlayer__sub_8017A1A4(temp_r3, 0));
        temp_f0 = ((TOTrapSeabed01 *)trap_seabed01)->dist;
        if (temp_f31 < (temp_f0 * temp_f0)) {
            if (TRaderMapCore::is_not_split_screen() == 1) {
                send_6x2C_impose_hold(temp_r3, trap_seabed01 + 0x38, -1, 0, (f32) (((TOTrapSeabed01 *)trap_seabed01)->dist));
            } else if ((s32) ((TOTrapSeabed01 *)trap_seabed01)->player == (s32) local_client_id) {
                send_6x2C_impose_hold(temp_r3, trap_seabed01 + 0x38, -1, 0, (f32) (((TOTrapSeabed01 *)trap_seabed01)->dist));
            }
            ((TOTrapSeabed01 *)trap_seabed01)->sub_802C9C18(0);
            return;
        }
        ((TOTrapSeabed01 *)trap_seabed01)->player = 0xFFFFU;
        *(u32 *)((s8 *)trap_seabed01 + 0x2A8) = 0U;
    }
}
#pragma pop

void TOTrapSeabed01::vfunc_82() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = this->m_348 - 1;
    this->m_348 = temp_r0;
    if (temp_r0 < 0) {
        *(f32 *)((s8 *)this->m_a4 + 0xC) = (f32) lbl_805DE64C;
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 0x100);
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)arg0)->check_object_collisions();
        ((VObj_18_f37bb9 *)(arg0))->m65(lbl_805DE640);
        this->receive_physical_attack((void *)(*(s32 *)((s8 *)arg0 + 0x2A8)), lbl_805DE640);
    }
    submit_cursor_candidate(arg0, -1);
}

void TOTrapSeabed01::vfunc_81() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r0;
    *(f32 *)((s8 *)arg0 + 0xC0) = (f32) (*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8));
    temp_r0 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xF8)) + 4) - 1;
    if (*(f32 *)((s8 *)arg0 + 0xC0) > (f32) temp_r0) {
        *(f32 *)((s8 *)arg0 + 0xC0) = (f32) temp_r0;
        *(s16 *)((s8 *)arg0 + 0x326) = 3;
        ((TUnk_804806E8 *)arg0)->calc_attach_pos();
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 0x08001F04U);
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 0x8003);
        ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x40000U);
        check_hold_player__14TOTrapSeabed01FPv(arg0);
    }
}

void TOTrapSeabed01::trigger_by_id(u32 arg0) {
    if (arg0 == (u32) TOTrapSeabed01__ginja_model) {
        TParticleCtrl::begin_effect_render();
        return;
    }
    TParticleCtrl::end_effect_render();
}

}

#pragma pop

#undef lbl_805DE640
#undef TOTrapSeabed01__data_805DE644
#undef lbl_805DE648
#undef lbl_805DE64C
#pragma push

struct S_802CA550 {
    u8 pad0[0x326];
    s16 f326;
    u8 pad328[0x340 - 0x328];
    s32 f340;
    u8 pad344[0x34C - 0x344];
    s32 f34C;
};

void setup_particle_tev(s32 arg0);
extern "C" {
f32 rotate_matrix_by_node_angles(void *, void *);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
s32 is_split_screen();
s32 dispatch_input_to_instance__18TAdEnterPasswordGCFi(void *);
void render__14TOTrapSeabed01Fv(S_802CA550 *arg0);
s32 PPCSync();
s32 scroll_ginja_mesh_uvs(int, int, int, void *, int);
void vfunc_84__14TOTrapSeabed01Fv(void);
s32 draw_ginja_model_with_motion(int, int, f32);

void restore_saved_depth_alpha_state(void);
void set_model_node_callback(s32 arg0);

extern s32 actor_frame_tick;
extern s32 lbl_805D681C;
extern s32 seabed01_ginja_mesh_index;

void TOTrapSeabed01::render_effect_layers() {
    TObjFish::set_global_param(TOTrapSeabed01__texture_file);
    if ((s32) actor_frame_tick != (s32) lbl_805D681C) {
        if (((void *) (*(u8 **)&TOTrapSeabed01__ginja_model) != NULL) && ((s32) seabed01_ginja_mesh_index != -1)) {
            scroll_ginja_mesh_uvs((int) (*(s32 *)((s8 *)(*(u8 **)&TOTrapSeabed01__ginja_model) + 4)), 0, -0x14, (void *) ((u16) seabed01_ginja_mesh_index), 1);
            PPCSync();
        }
        lbl_805D681C = actor_frame_tick;
    }
    set_model_node_callback((s32)TOTrapSeabed01::trigger_by_id);
    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    ((s32 (*)(int, int))rotate_matrix_y)(0, this->rotation_y);
    set_depth_buffer_settings_3();
    set_depth_buffer_settings_id(1);
    draw_ginja_model_with_motion((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)), this->unknownF8, this->m_c0);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    TParticleCtrl::begin_effect_render();
    set_depth_buffer_settings_1();
    set_depth_buffer_settings_id(2);
    draw_ginja_model_with_motion((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)), this->unknownF8, this->m_c0);
    restore_draw_list_mask();
    restore_saved_depth_alpha_state();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    set_model_node_callback((NULL));
}

void TOTrapSeabed01::draw_object_tree(u8 *arg1) {
    s32 temp_r31;
    u8 *temp_r4;
    u8 *var_r30;
    var_r30 = arg1;
    do {
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        push_matrix();
        if (!(temp_r31 & 1)) {
            post_translate_matrix(var_r30 + 8);
        }
        if (!(temp_r31 & 2)) {
            rotate_matrix_by_node_angles(var_r30 + 0x14, (void *) (temp_r31 & 0x20));
        }
        if (!(temp_r31 & 4)) {
            scale_current_matrix(var_r30 + 0x20);
        }
        if (!(temp_r31 & 8)) {
            if ((s32) this->m_34c != 0) {
                setup_particle_tev(0);
                TObjFish::set_global_param(TOTrapSeabed01__texture_file);
                load_projection_tex_matrix(0x38E);
                draw_ginja_model((*(s32 *)((s8 *)var_r30 + 4)));
                TParticleCtrl::disable_if_single_screen();
            } else {
                draw_ginja_model((*(s32 *)((s8 *)var_r30 + 4)));
            }
        }
        if (!(temp_r31 & 0x10)) {
            temp_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x2C));
            if (temp_r4 != NULL) {
                draw_object_tree(temp_r4);
            }
        }
        pop_matrix();
        var_r30 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x30));
    } while (var_r30 != NULL);
}

void TOTrapSeabed01::draw() {
    if ((TRaderMapCore::is_not_split_screen() != 1) || ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x34C) == 0)) {
        set_depth_buffer_settings_3();
        set_depth_buffer_settings_id(1);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(TOTrapSeabed01__texture_file);
        push_matrix();
        post_translate_matrix(((u8 *)this) + 0x38);
        ((s32 (*)(int, int))rotate_matrix_y)(0, (int)(*(s32 *)((s8 *)((u8 *)this) + 0x60)));
        this->draw_object_tree((u8 *)(*(s32 *)((s8 *)((u8 *)this) + 0x34)));
        pop_matrix();
        TParticleCtrl::end_effect_render();
        restore_draw_list_mask();
        restore_saved_depth_alpha_state();
    }
}
void render__14TOTrapSeabed01Fv(S_802CA550 *arg0) {
    if (TMainTask::get_render_pass() != 1 && (arg0->f34C == 0 || is_split_screen() != 0 || dispatch_input_to_instance__18TAdEnterPasswordGCFi(arg0) == 0) && arg0->f340 == 1) {
        switch (arg0->f326) {
        case 0:
        case 1:
            ((TOTrapSeabed01 *)arg0)->draw();
            break;
        case 2:
        case 3:
            ((TOTrapSeabed01 *)arg0)->render_effect_layers();
            break;
        }
    }
}
}

#pragma pop

#define lbl_805DE640 (lbl_805DE640[0])
#define lbl_805DE658 (lbl_805DE658[0])
#pragma push

#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Base_802CA8C8_eabed01 { char pad[0x18]; };
struct VObj_802CA8C8_eabed01 : Base_802CA8C8_eabed01 {
#define V(n) virtual void m##n();
    V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)
    V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
    V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)
    V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
    V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)
    V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
    V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)
    V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
    V(80)V(81)V(82)
#undef V
    virtual void m83();
};

struct SeabedTrapResourceDescriptor {
    const char *bml_filename;
    const char *const *model_filenames;
    const char *const *motion_filenames;
    s16 model_count;
    s16 motion_count;
};
struct SeabedTrapCollisionBody {
    f32 local_center[3];
    f32 radius;
    f32 field_10;
    s32 field_14;
    u32 flags;
    f32 world_center[3];
    f32 field_28;
};
typedef char SeabedTrapResourceDescriptor_size[(sizeof(SeabedTrapResourceDescriptor) == 0x10) ? 1 : -1];
typedef char SeabedTrapCollisionBody_size[(sizeof(SeabedTrapCollisionBody) == 0x2C) ? 1 : -1];

struct RecoveredGlobal_802CA9AC___vt__14TOTrapSeabed01 { s32 value; u8 remaining[0x168]; };

#pragma inline_depth(4)
#pragma dont_inline off
extern "C" {
s32 get_bml_motion(int, int);
s32 init_collision_body_parts(void *, void *, int);
s32 TOTrap__ct(void *);
extern SeabedTrapCollisionBody seabed_trap_collision_body;
extern void *__vt__14TOTrapSeabed01[];
extern s32 TOTrapSeabed01_class_name;
u8 *TOTrapSeabed01__ct(TOTrapSeabed01 *arg0, s32 arg1, s32 arg2);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_804720E8[];
extern u8 lbl_80472100[];
extern SeabedTrapResourceDescriptor seabed_trap_resource_descriptor;

extern s32 trap_seabed01_param_index_table[];
void vfunc_6__14TOTrapSeabed01FPsl(void *arg0, s16 *arg1, s32 arg2);
void *__dt__14TOTrapSeabed01Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void stop_sound_request(s32 idx);
s32 release_texture_list(void*);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__6TOTrapFv(void *arg0, s16 arg1);

void queue_destruction__7TObjectFv(void *arg0);

void TOTrapSeabed01::vfunc_84() {  }


inline f32 clampf_802CA5F4(f32 lo, f32 hi, f32 v) {
    f32 r;
    if (lo > v) {
        r = lo;
    } else if (hi < v) {
        r = hi;
    } else {
        r = v;
    }
    return r;
}
inline s32 CLAMPI(s32 v, s32 lo, s32 hi) {
    s32 r;
    if (v < lo) {
        r = lo;
    } else {
        r = hi;
        if (v <= hi) {
            r = v;
        }
    }
    return r;
}
inline s32 clampi_802CA5F4(s32 lo, s32 hi, s32 v) {
    if (v < lo) {
        return lo;
    }
    if (v > hi) {
        return hi;
    }
    return v;
}
#pragma push
#pragma opt_common_subs off
void TOTrapSeabed01::clamp_params_and_init() {
    this->scale = clampf_802CA5F4(lbl_805DE650[0], lbl_805DE654[0], this->scale);
    this->m_84 = CLAMPI(this->m_84, 1, 0x3C);
    *(s32 *)&this->m_88 = CLAMPI(*(s32 *)&this->m_88, 0, 1);
    this->mode = 0;
    this->range = lbl_805DE64C[0];
    this->dist = lbl_805DE64C[0];
    *(s32 *)&this->m_348 = (s32) (lbl_805DE658 * (f32) this->m_84);
    if (*(s32 *)&this->m_88 != 0) {
        *(s32 *)&this->m_34c = 1;
    } else {
        *(s32 *)&this->m_34c = 0;
    }
    this->m_c8 = this->scale;
    if (this->target_scale < TOTrapSeabed01__data_805DE644[0]) {
        this->target_scale = TOTrapSeabed01__data_805DE644[0];
    }
    *(f32 *)&this->m_354 = this->vfunc_87(this->target_scale);
    *(s32 *)&this->m_8c = CLAMPI(*(s32 *)&this->m_8c, 0, 5);
    *(s32 *)&this->m_350 = trap_seabed01_param_index_table[*(s32 *)&this->m_8c];
}
#pragma pop

void *TOTrapSeabed01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x35C);
    if (o != NULL) {
        o = TOTrapSeabed01__ct((TOTrapSeabed01 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOTrapSeabed01::free_static_resources() {
    if ((u32) (*(u32 *)&TOTrapSeabed01__texture_file) != 0U) {
        release_texture_list((void*)(*(u32 *)&TOTrapSeabed01__texture_file));
        TAdSinglePlyChrSelectGC::safe_free((*(u32 *)&TOTrapSeabed01__texture_file));
        (*(u32 *)&TOTrapSeabed01__texture_file) = 0U;
    }
    if ((u32) (*(u32 *)&TOTrapSeabed01__bml_resource) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TOTrapSeabed01__bml_resource), 1);
        (*(u32 *)&TOTrapSeabed01__bml_resource) = 0U;
    }
}

void TOTrapSeabed01::load_resources() {
    void *p = ::operator new(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 5, (void *)&seabed_trap_resource_descriptor, 0, 0, 0);
    }
    (*(u32 *)&TOTrapSeabed01__bml_resource) = (u32)p;
    (*(u32 *)&TOTrapSeabed01__texture_file) = (u32)load_gvm_texture_file((s32)lbl_804720E8);
    s32 n = (s32)find_object_node((NJS_OBJECT *)(get_bml_model((*(u32 *)&TOTrapSeabed01__bml_resource), 0)), 5);
    u32 t = (*(u32 *)&TOTrapSeabed01__texture_file);
    (*(s32 *)&TOTrapSeabed01__ginja_model) = n;
    lbl_805D681C = 0;
    seabed01_ginja_mesh_index = -1;
    if (t != 0U) {
        seabed01_ginja_mesh_index = ((TObjDoorJung *)t)->find_entry_by_name((const char *)lbl_80472100);
    }
}

void TOTrapSeabed01::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 4) {
        if (arg2 == 1) {
            ((VObj_802CA8C8_eabed01 *)this)->m83();
        }
        s32 tmp = this->m_358;
        if (tmp >= 0) {
            stop_sound_request(tmp);
            tmp = -1;
            this->m_358 = tmp;
        }
        ((s32 (*)(void *))sub_802C9D38__14TOTrapSeabed01Fv)(this);
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

void *__dt__14TOTrapSeabed01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__14TOTrapSeabed01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__6TOTrapFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TOTrapSeabed01__ct(TOTrapSeabed01 *trap_seabed01, s32 arg1, s32 arg2) {
    TOTrap__ct(trap_seabed01);
    *(s32 **)((s8 *)trap_seabed01 + 0x18) = &(*(RecoveredGlobal_802CA9AC___vt__14TOTrapSeabed01 *)&__vt__14TOTrapSeabed01).value;
    *(s32 *)((s8 *)trap_seabed01 + 0) = (s32) TOTrapSeabed01_class_name;
    ((TOTrapSeabed01 *)(trap_seabed01))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)trap_seabed01 + 0x34) = get_bml_model((int) ((*(s32 *)&(*(u32 *)&TOTrapSeabed01__bml_resource))), 0);
    trap_seabed01->unknownF8 = get_bml_motion((int) ((*(s32 *)&(*(u32 *)&TOTrapSeabed01__bml_resource))), 0);
    trap_seabed01->m_c8 = (f32) lbl_805DE640;
    trap_seabed01->m_c0 = (f32) TOTrapSeabed01__data_805DE644[0];
    trap_seabed01->clamp_params_and_init();
    init_collision_body_parts(trap_seabed01, &seabed_trap_collision_body, 1);
    ((TUnk_804AF8A0 *)trap_seabed01)->refresh_collision_body_centers();
    ((TObjPlayer *)trap_seabed01)->reset_photon_effect();
    trap_seabed01->actorFlags = (s32) (trap_seabed01->actorFlags | 0x60040000);
    trap_seabed01->m_344 = 0;
    trap_seabed01->m_358 = -1;
    return (u8 *)trap_seabed01;
}

#pragma pop

#undef lbl_805DE640
#undef lbl_805DE658

void vfunc_89__6TOTrapFv();
void vfunc_86__6TOTrapFv();
void vfunc_88__6TOTrapFv();
void try_start_action__6TOTrapFll();
u8 TOTrap__sub_801792CC(u8 *arg0, s32 arg1);
u8 TOTrap__sub_801792E4(u8 *arg0, s32 arg1);
u8 TOTrap__sub_801792FC(u8 *arg0, s32 arg1);
void apply_knockback_from_attacker__6TOTrapFPUc();
void vfunc_29__13TUnk_804806E8Fv();
void vfunc_74__13TUnk_804806E8Fl();
void recalc_stats__13TUnk_804806E8Fv();
void vfunc_28__13TUnk_804806E8Fv();
void vfunc_66__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_63__13TUnk_804806E8Fv();
void vfunc_62__13TUnk_804806E8Fv();
void vfunc_61__13TUnk_804806E8Fv();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_58__13TUnk_804806E8Fv();
void vfunc_43__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void interact__13TUnk_804AF8A0Fl();
void get_name__13TUnk_804B9870Fv();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_object_set_data__13TUnk_804B9870FPv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void check_trigger_range__6TOTrapFUl();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void consume_timer_field__13TUnk_804806E8Fl();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void find_target_player__6TOTrapFv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_pos__13TUnk_804806E8Fl();
void get_scale__6TOTrapFUl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_any_player_matching_stat__6TOTrapFv();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void render_shadows__7TObjectFv();
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void submit_cursor_and_notify__6TOTrapFv();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
void run_task__6TOTrapFv();
extern const char lbl_80471FB8[];
extern const char lbl_80471FD0[];
extern const char lbl_80471FF0[];
extern const char lbl_80472010[];
extern const char lbl_80472028[];
const char *seabed_trap_model_filenames[4] = { lbl_80471FB8, lbl_80471FD0, lbl_80471FF0, 0 };
__declspec(section ".data") const char *seabed_trap_motion_filenames[2] = { lbl_80472010, 0 };
SeabedTrapResourceDescriptor seabed_trap_resource_descriptor = { lbl_80472028, seabed_trap_model_filenames, seabed_trap_motion_filenames, 3, 1 };
SeabedTrapCollisionBody seabed_trap_collision_body = { { 0.0f, 20.0f, 0.0f }, 14.0f, 0.0f, 0, 0x08011F04, { 0.0f, 0.0f, 0.0f }, 0.0f };
SeabedTrapFragmentSpawn seabed_trap_fragment_spawns[6] = {
    { 2, { 9.0f, 21.0f, 9.0f }, -24576 },
    { 2, { 9.0f, 21.0f, -9.0f }, -8192 },
    { 2, { -9.0f, 21.0f, 9.0f }, 24576 },
    { 2, { -9.0f, 21.0f, -9.0f }, 8192 },
    { 1, { -4.0f, 0.0f, -4.0f }, 0 },
    { 1, { 4.0f, 0.0f, 4.0f }, 32768 },
};
void *__vt__14TOTrapSeabed01[91] = {
    0,
    0,
    (void *)&__dt__14TOTrapSeabed01Fv,
    (void *)&run_task__6TOTrapFv,
    (void *)&render__14TOTrapSeabed01Fv,
    (void *)&render_shadows__7TObjectFv,
    (void *)&vfunc_6__14TOTrapSeabed01FPsl,
    (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv,
    (void *)&vfunc_9__13TUnk_804806E8Fv,
    (void *)&update_object_view_visibility__13TUnk_804B9870Fff,
    (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv,
    (void *)&interact__13TUnk_804AF8A0Fl,
    (void *)&add_actor_exp__13TUnk_804806E8Fl,
    (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv,
    (void *)&update_actor_ground_y__13TUnk_804806E8Fv,
    (void *)&vfunc_18__13TUnk_804806E8FPUc,
    (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&TOTrap__sub_801792E4,
    (void *)&TOTrap__sub_801792FC,
    (void *)&TOTrapSeabed01__vt20,
    (void *)&check_trigger_range__6TOTrapFUl,
    (void *)&get_scale__6TOTrapFUl,
    (void *)&apply_knockback_from_attacker__6TOTrapFPUc,
    (void *)&try_start_action__6TOTrapFll,
    (void *)&TOTrap__sub_801792CC,
    (void *)&vfunc_28__13TUnk_804806E8Fv,
    (void *)&vfunc_29__13TUnk_804806E8Fv,
    (void *)&is_target_in_attack_range__13TUnk_804806E8Fv,
    (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv,
    (void *)&has_flag_0x800__13TUnk_804806E8Fv,
    (void *)&test_flag_1000__13TUnk_804806E8Fv,
    (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv,
    (void *)&vfunc_37__13TUnk_804806E8Fv,
    (void *)&update_flag30_timer__13TUnk_804806E8Fv,
    (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv,
    (void *)&update_attack_stat_status__13TUnk_804806E8Fv,
    (void *)&update_defense_stat_status__13TUnk_804806E8Fv,
    (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv,
    (void *)&apply_paralysis__13TUnk_804806E8Fv,
    (void *)&apply_slow_status__13TUnk_804806E8Fv,
    (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl,
    (void *)&apply_shock_status__13TUnk_804806E8Fv,
    (void *)&clear_harmful_statuses__13TUnk_804806E8Fv,
    (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv,
    (void *)&cure_poison_ailment__13TUnk_804806E8Fv,
    (void *)&cure_paralysis__13TUnk_804806E8Fv,
    (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff,
    (void *)&apply_anti_technique__13TUnk_804806E8Fl,
    (void *)&vfunc_58__13TUnk_804806E8Fv,
    (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv,
    (void *)&vfunc_61__13TUnk_804806E8Fv,
    (void *)&vfunc_62__13TUnk_804806E8Fv,
    (void *)&vfunc_63__13TUnk_804806E8Fv,
    (void *)&reset_pose__13TUnk_804806E8Fv,
    (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec,
    (void *)&vfunc_66__13TUnk_804806E8Fv,
    (void *)&vfunc_67__14TOTrapSeabed01Ff,
    (void *)&get_pos__13TUnk_804806E8Fl,
    (void *)&apply_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv,
    (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv,
    (void *)&recalc_stats__13TUnk_804806E8Fv,
    (void *)&vfunc_74__13TUnk_804806E8Fl,
    (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv,
    (void *)&vfunc_77__13TUnk_804806E8Fv,
    (void *)&vfunc_78__13TUnk_804806E8Fl,
    (void *)&find_target_player__6TOTrapFv,
    (void *)&submit_cursor_and_notify__6TOTrapFv,
    (void *)&vfunc_81__14TOTrapSeabed01Fv,
    (void *)&vfunc_82__14TOTrapSeabed01Fv,
    (void *)&is_any_player_matching_stat__6TOTrapFv,
    (void *)&vfunc_84__14TOTrapSeabed01Fv,
    (void *)&TOTrapSeabed01__vt83,
    (void *)&vfunc_86__6TOTrapFv,
    (void *)&TOTrap::scale_by_table_value,
    (void *)&vfunc_88__6TOTrapFv,
    (void *)&vfunc_89__6TOTrapFv,
    0
};
}
