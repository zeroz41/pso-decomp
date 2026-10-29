#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/misc/TOContainerAncientEnemy.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8015BD68_lbl_804B00C8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy {
    s32 value;
    u8 remaining[0x148];
};

struct Obj_8015BCC0 { u8 pad[0x326]; s16 a326; u8 pad2[0x364 - 0x328]; s32 a364; };

struct Obj_80188814 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };

struct Spawn_8015B94C {
    u8 pad0[0xC];
    f32 x, y, z;
    u8 pad18[0x38 - 0x18];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};
struct Obj_8015B94C { u8 pad[0x38]; f32 x, y, z; u8 pad44[0x326 - 0x44]; s16 f326; };
struct Ref_8015B94C { u8 pad[4]; s32 a; s32 b; };

struct O_8015BAE0 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; u32 f80; s32 f84; };

struct Pk_8015BAE0 { u8 pad[2]; u16 id; s32 a; s32 b; s32 c; };

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 init_collision_body_parts(void *, void *, int);
u8 *init_container_base(u8 *arg0, s32 arg1, s32 arg2);
extern RecoveredGlobal_8015BD68_lbl_804B00C8 TOContainerAncientEnemy__collision_body_params;
extern s32 __vt__23TOContainerAncientEnemy[];
extern s32 lbl_805D2F08;
extern s32 tl_05;
u8 *TOContainerAncientEnemy__ct(u8 *arg0, s32 arg1);
void submit_cursor_candidate(Obj_8015BCC0 *self, s32 x);
void debug_printf_at(s32 id, const char *fmt, ...);
extern char lbl_80440830[];
extern const f32 lbl_805DB3A0;
s32 get_current_floor();
void byteswap_and_send__6TLobbyFv(void *, int);
extern s32 local_client_id;
extern const f32 lbl_805DB39C;
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
void *spawn_particle_effect(void *pos, s32 id);
u8 *__ct__8TObjChipFP7TObjectP14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
}
void play_container_break_sound(s32 arg0);
extern "C" {
void *__nw__7TObjectFUl(int);
extern Spawn_8015B94C ancient_enemy_break_debris_desc;
extern Spawn_8015B94C ancient_enemy_break_debris_desc_b;
extern s32 lbl_805D2F10;
extern Ref_8015B94C *ancient_container_fragment_texture_lists;
void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void queue_destruction__7TObjectFv(void *arg0);

void TOContainerAncientEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

void TOContainerAncientEnemy::vfunc_79() {
    Obj_8015B94C *self = (Obj_8015B94C *)this;
    extern const u32 ancient_container_resource_bundle;
    void *o;
    if (this->mode != 1) {
        Spawn_8015B94C a = ancient_enemy_break_debris_desc;
        a.x = self->x;
        a.y = self->y;
        a.z = self->z;
        a.f38 = self->y;
        a.f40 = get_bml_model((void *)ancient_container_resource_bundle, 1);
        a.f44 = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 1);
        Spawn_8015B94C b = ancient_enemy_break_debris_desc_b;
        b.x = self->x;
        b.y = self->y;
        b.z = self->z;
        b.f38 = self->y;
        b.f40 = get_bml_model((void *)ancient_container_resource_bundle, 2);
        b.f44 = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 2);
        if (check_value_equals__13TUnk_804B6C24Fl(self, lbl_805D2F10) != 0) {
            a.f44 = ancient_container_fragment_texture_lists->a;
            b.f44 = ancient_container_fragment_texture_lists->b;
        }
        spawn_particle_effect(&self->x, 0x45);
        spawn_particle_effect(&self->x, 0x46);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

f32 TOContainerAncientEnemy::receive_physical_attack(void *, f32) {
    O_8015BAE0 *arg0 = (O_8015BAE0 *)this;
    s16 sp8;
    s32 r4;
    Pk_8015BAE0 pk;
    if (this->entity_id >= 0x1000U && arg0->f80 != 0U && ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pk))->init_packet_67_04();
        pk.id = this->entity_id;
        pk.a = get_current_floor();
        r4 = this->set_params[0];
        pk.b = r4;
        pk.c = local_client_id;
        byteswap_and_send__6TLobbyFv(&pk, r4);
    }
    return lbl_805DB39C;
}

void TOContainerAncientEnemy::debug_print_item_box_info() {
    Obj_80188814 *self = (Obj_80188814 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80440830, this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DB3A0);
}

void TOContainerAncientEnemy::vfunc_81() {
    extern u32 ancient_container_resource_bundle;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if ((u32) ancient_container_resource_bundle != 0U) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            temp_r31 = (unsigned char *) (this->model);
            push_matrix();
            post_translate_matrix(temp_r31 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientEnemy::vfunc_80() {
    Obj_8015BCC0 *self = (Obj_8015BCC0 *)this;
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(self, -1);
        }
        break;
    }
}

void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TOContainerAncientEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015BD68_lbl_804B00C8_size[sizeof(RecoveredGlobal_8015BD68_lbl_804B00C8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy_size[sizeof(RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy) == 0x14C ? 1 : -1];
u8 *TOContainerAncientEnemy__ct(u8 *arg0, s32 arg1) {
    extern u32 ancient_container_resource_bundle;
    init_container_base((arg0), (tl_05), (arg1));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy *)&__vt__23TOContainerAncientEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F08;
    ((TOContainerAncientEnemy *)arg0)->mode = 0;
    ((TOContainerAncientEnemy *)arg0)->actorFlags = (s32) (((TOContainerAncientEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&TOContainerAncientEnemy__collision_body_params.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&TOContainerAncientEnemy__collision_body_params.value + 4));
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    ((TOContainerAncientEnemy *)arg0)->texlist = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    return arg0;
}
}
