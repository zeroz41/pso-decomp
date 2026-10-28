#include "types.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/misc/TScene.h"

#include "pso/misc/TSceneMaterial.h"

struct Rec_80203510 { s32 id; f32 pos[3]; u8 pad[0xC]; f32 radius; u8 pad2[0x14]; };

struct Root_80203510 { u8 pad[8]; s16 count; u8 pad2[6]; Rec_80203510 *recs; };

struct Root_80204024 { u8 pad[0x178]; f32 x; f32 y; f32 z; };

struct Vec_80204024 { f32 x, y, z; };

struct Inner_802040D4 { u8 pad[0x20]; f32 radius; };

struct Obj_802040D4 { u8 pad[4]; Inner_802040D4 *inner; u8 pos[1]; };

struct Rec_8020430C { u8 pad0[4]; f32 pos[3]; u8 pad1[0x20]; u32 flags; };

struct Root_8020430C { u8 pad[8]; s16 count; u8 pad2[2]; f32 radius; Rec_8020430C *recs; };

struct W_8020430C { s32 a, b, c; };

struct Cam_8020430C { u8 pad[0x178]; W_8020430C pos; };

struct Obj_802040D4;

struct Obj_80204B78 { u8 pad0[4]; f32 x; f32 y; f32 z; u8 pad10[0xC]; f32 radius; u8 pad20[0x10]; u32 flags; };

typedef void (*RecoveredCallback_2be3cacebb2e)(void);
struct SceneMaterialRoot;
struct Motion_80203F0C { u8 pad[4]; u32 frames; };

struct Anim_80203F0C {
    u8 pad0[4];
    Motion_80203F0C *motion;
    u8 pad8[4];
    f32 frame;
    f32 speed;
    u8 pad14[8];
    u32 flags;
};

struct Group_80203F0C {
    u8 pad0[0x24];
    Anim_80203F0C *anims;
    u8 pad28[4];
    s32 count;
    u8 pad30[4];
};

struct Root_80203F0C { u8 pad[8]; s16 count; u8 pad2[6]; Group_80203F0C *groups; };

struct Vec_802043CC { f32 x, y, z; };

struct W_802043CC { s32 a, b, c; };

struct Cam_802043CC { u8 pad[0x178]; Vec_802043CC pos; u8 pad2[0x10]; s32 angY; u8 pad3[4]; s32 f19C; };

struct Ent_802043CC { s32 id; s32 n; s32 start; };

struct Tbl_802043CC { u32 pad; s32 count; Ent_802043CC ents[1]; };

extern SceneMaterialRoot* TScene__data_805D5FCC;
extern "C" {
SceneMaterialSection *find_scene_room_by_id(s32 id);
void matrix_mult_vec(int, void *, void *);
extern const f32 TScene__data_805DC5D8;
bool is_in_view_depth__6TSceneFf(f32 farg0);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
extern const f32 lbl_805DC5D0;
f32 vec3_dot(void *, void *);
f32 project_point_onto_line(void *, void *, void *);
extern Root_80204024 *camera_ctrl_instance;
s32 TScene__sub_80204024(f32 thr, s32 unused, void *a, void *b, Vec_80204024 *c);
f32 xz_distance_squared(void *, void *);
s32 TScene__sub_802040D4(void *arg0, Obj_802040D4 *o, f32 f0, f32 f1);
extern f32 TScene__visibility_radius_margin;

SceneMaterialNode* resolve_indirect_node_record(void*,SceneMaterialStatic*);
SceneMaterialNode* resolve_indirect_object_record(void*,SceneMaterialAnimated*);
extern const f32 lbl_805DC5DC;
extern const f32 lbl_805DC5E0;
extern const f32 TScene__data_805DC600;
extern u8 identity_matrix[];
void normalize_vector(Vec_80204024 *);
void push_matrix_from(void *);
void rotate_matrix_y(s32, s32);
void rotate_vector_by_matrix(s32, void *, Vec_80204024 *);
void pop_matrix(void);
s32 check_object_in_view_cone__6TSceneFiPvPvPvi(s32 arg0, Obj_80204B78 *obj, Vec_80204024 *pos, void *arg3, s32 arg4);
extern RecoveredCallback_2be3cacebb2e TScene__render_callback;
extern s32 model_render_flags;
extern s32 saved_model_render_flags;
void prepare_ginja_model(void);
void push_matrix(void);
void post_translate_matrix(f32 *);
void rotate_matrix_by_node_angles(s32 *, s32);
void advance_scene_object_animations(void);
extern void* TScene__texture_animation_buffer;
s32 load_texture_sequence_frame(void*,SceneMaterialCycle*);
f32 fabs_float(f32);
void PPCSync();
extern const f32 lbl_805DC5D4;

void scroll_ginja_mesh_uvs(void *, s32, s32, u16, s32);

struct Vec_8020533C { f32 x, y, z; };
struct Ang_8020533C { s32 x, y, z; };
struct Node_8020533C { u8 pad0[8]; Vec_8020533C pos; Ang_8020533C ang; };
struct Model_8020533C { u8 pad0[4]; void *tex; s32 f8; u8 padC[2]; u8 fE; u8 fF; };
struct Lobby_8020533C { Vec_8020533C v; Ang_8020533C a; void *param; Node_8020533C *node; s16 scene; u8 id; };

void render_projected_shadow_receiver(void *, void *);
void draw_field_1c__6TSceneFlll(void *, s32, s32, s32);
void release_indexed_entry__6TLobbyFl(Lobby_8020533C *);
void vec3_add_to(void *, void *);
void draw_ginja_object(void *);
void set_material_alpha_compare_reference(s32 reference);
extern s32 TScene__data_805D5FE0;
extern void (*TScene__map_section_render_callback)(Vec_8020533C *, Ang_8020533C *, u32);
extern void (*TScene__active_scene_callback)(u32);

void VecCopy__FP3VecPC3Vec(void *, void *);

void subtract_vector(void *, void *);
}
void end_ginja_model_draw(void);
extern W_802043CC lbl_8044A858[];
extern Tbl_802043CC *TScene__data_805D6020;
extern const f32 lbl_805DC5E4;

struct SceneFormatEntry {
    const char *name;
    s32 format;
};
struct SceneMemberPointerBits {
    s32 thisAdjustment;
    s32 virtualOffset;
    void (*function)();
};
struct SceneDispatchPrefix {
    SceneFormatEntry formats[3];
    SceneMemberPointerBits initializeTemplate[2];
    SceneMemberPointerBits initializeStorage[2];
    SceneMemberPointerBits cleanupTemplate[2];
    SceneMemberPointerBits cleanupStorage[2];
};
typedef char SceneDispatchPrefix_size[sizeof(SceneDispatchPrefix) == 0x78 ? 1 : -1];
struct Task_80204688;
extern "C" {
extern const char lbl_8044A7F0[];
extern const char lbl_8044A7F8[];
void initialize_fmt1_materials__6TSceneFv(void *);
void initialize_fmt2_materials__6TSceneFv();
void TScene__sub_80205FD0(void);
void TScene__sub_80205ECC(void);

extern s32 TScene__data_805D5FE8;
SceneDispatchPrefix scene_format_dispatch_tables = {
    {{lbl_8044A7F0, 0}, {lbl_8044A7F8, 1}, {NULL, -1}},
    {{0, -1, (void (*)())initialize_fmt1_materials__6TSceneFv},
     {0, -1, (void (*)())initialize_fmt2_materials__6TSceneFv}},
    {{0, 0, NULL}, {0, 0, NULL}},
    {{0, -1, (void (*)())TScene__sub_80205FD0},
     {0, -1, (void (*)())TScene__sub_80205ECC}},
    {{0, 0, NULL}, {0, 0, NULL}}
};
s32 TScene__sub_80205874(void*);
extern s8 TScene__floor_scene_ready_flag;
void *get_player_by_client_id(s32 i);

}

#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Cam_80204688 { u8 pad[0x178]; f32 x; f32 y; f32 z; u8 pad184[0x194 - 0x184]; s32 a194; u8 pad198[4]; s32 a19C; };
struct Task_80204688 { u8 pad[0x1C]; s32 count; };
struct Model_80204688 { u8 pad[0x14]; f32 x, y, z; };
struct Node_80204688 { u32 flags; Model_80204688 *model; f32 x, y, z; };

extern "C" {
extern const f32 lbl_805DC5E8;
extern const f32 lbl_805DC5EC;
extern const f32 lbl_805DC5F0;
extern const f32 lbl_805DC5F4;
extern const f32 lbl_805DC5F8;
extern const f32 lbl_805DC5FC;
extern Vec_80204024 lbl_8044A84C[];
void pop_matrices(s32);
s32 is_split_screen(void);

#define CAM ((Cam_80204688 *)camera_ctrl_instance)
#define TEST ((s32 (*)(f32, void *, void *, void *, Vec_80204024 *))TScene__sub_80204024)
#define VIS ((s32 (*)(void *, void *, f32, f32))is_in_view_depth__6TSceneFf)

}

 s8 scene_initialize_materials_guard; s8 scene_cleanup_materials_guard;
s32 TScene::find_section_at_position() {
    Rec_80203510 *r;
    s32 best = -1;
    s32 i;
    f32 bestd;
    if ((*(Root_80203510 * *)&TScene__data_805D5FCC) == NULL) {
        return -1;
    }
    bestd = lbl_805DC5D0;
    r = (*(Root_80203510 * *)&TScene__data_805D5FCC)->recs;
    for (i = 0; i < (*(Root_80203510 * *)&TScene__data_805D5FCC)->count; i++, r++) {
        if (r->id >= 0) {
            f32 d = xyz_distance_squared((u8 *)this, (u8 *)r->pos);
            if (!(d > r->radius * r->radius) && d < bestd) {
                bestd = d;
                best = r->id;
            }
        }
    }
    return best;
}
s32 TScene::get_player_ctrl_field(u16 arg0) {
    u32 player;

    player = (u32)get_player_by_client_id((arg0));
    if (player != 0U) {
        return ((TScene *)(player + 0x38))->find_section_at_position();
    }
    return -1;
}
SceneMaterialSection *find_scene_room_by_id(s32 id) {
    s32 i;
    s16 count = TScene__data_805D5FCC->count;
    for (i = 0; i < count; i++) {
        if (TScene__data_805D5FCC->sections[i].id == id) {
            return &TScene__data_805D5FCC->sections[i];
        }
    }
    return NULL;
}

void TScene::tick_material_fmt2() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    SceneMaterialNode *node;
    SceneMaterialUv *uv;
    if ((*(void * *)&TScene__texture_animation_buffer) == NULL || (*(SceneMaterialRoot * *)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        SceneMaterialStatic *o2;
        s32 k;
        o2 = room->objects;
        for (k = 0; k < room->count; k++, o2++) {
            o2->flags &= ~0x20000;
        }
        {
            SceneMaterialAnimated *a2;
            s32 k2;
            a2 = room->animated;
            for (k2 = 0; k2 < room->animatedCount; k2++, a2++) {
                a2->flags &= ~0x20000;
            }
        }
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20000) {
                continue;
            }
            if (object->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object)));
            if (object->flags & 0x20) {
                uv = object->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (fabs_float(uv->u) >= lbl_805DC5D4 || fabs_float(uv->v) >= lbl_805DC5D4) {
                    if (uv->buffer != NULL) {
                        ((TScene *)(uv->buffer))->offset_position((s32)((s32)uv->u), (s32)((s32)uv->v));
                    }
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (object->flags & 0x40) {
                object->cycle->timer--;
                if (object->cycle->timer < 0) {
                    (*(s16 *)&object->cycle->index)++;
                    load_texture_sequence_frame(this, (SceneMaterialCycle*)(object->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)object->cycle->texture);
                    if (object->flags & 0x20) {
                        object->uv->texture = object->cycle->texture;
                    }
                }
            }
            object->flags |= 0x20000;
        }
        anim = room->animated;
        for (i = 0; i < room->animatedCount; i++, anim++) {
            if (anim->flags & 0x20000) {
                continue;
            }
            if (anim->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim)));
            if (anim->flags & 0x20) {
                uv = anim->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (uv->u >= 1.0f || uv->v >= 1.0f) {
                    if (uv->buffer != NULL) {
                        ((TScene *)(uv->buffer))->offset_position((s32)((s32)uv->u), (s32)((s32)uv->v));
                    }
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (anim->flags & 0x40) {
                anim->cycle->timer--;
                if (anim->cycle->timer < 0) {
                    (*(s16 *)&anim->cycle->index)++;
                    load_texture_sequence_frame(this, (SceneMaterialCycle*)(anim->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)anim->cycle->texture);
                }
            }
            anim->flags |= 0x20000;
        }
    }
    PPCSync();
}

void TScene::tick_material_fmt1() {
    SceneMaterialSection *room;
    s32 section;
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    SceneMaterialNode *node;
    SceneMaterialUv *uv;
    if ((*(void * *)&TScene__texture_animation_buffer) == NULL || (*(SceneMaterialRoot * *)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        SceneMaterialStatic *o2;
        s32 k;
        o2 = room->objects;
        for (k = 0; k < room->count; k++, o2++) {
            o2->flags &= ~0x20000;
        }
        {
            SceneMaterialAnimated *a2;
            s32 k2;
            a2 = room->animated;
            for (k2 = 0; k2 < room->animatedCount; k2++, a2++) {
                a2->flags &= ~0x20000;
            }
        }
    }
    room = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
    for (section = 0; section < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; section++, room++) {
        object = room->objects;
        for (i = 0; i < room->count; i++, object++) {
            if (object->flags & 0x20000) {
                continue;
            }
            if (object->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object)));
            if (object->flags & 0x20) {
                uv = object->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (fabs_float(uv->u) >= lbl_805DC5D4 || fabs_float(uv->v) >= lbl_805DC5D4) {
                    scroll_ginja_mesh_uvs(node->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (object->flags & 0x40) {
                object->cycle->timer--;
                if (object->cycle->timer < 0) {
                    (*(s16 *)&object->cycle->index)++;
                    load_texture_sequence_frame(this, (SceneMaterialCycle*)(object->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)object->cycle->texture);
                    if (object->flags & 0x20) {
                        object->uv->texture = object->cycle->texture;
                    }
                }
            }
            object->flags |= 0x20000;
        }
        anim = room->animated;
        for (i = 0; i < room->animatedCount; i++, anim++) {
            if (anim->flags & 0x20000) {
                continue;
            }
            if (anim->flags & 0x04000000) {
                continue;
            }
            node = ((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim)));
            if (anim->flags & 0x20) {
                uv = anim->uv;
                uv->u += uv->du;
                uv->v += uv->dv;
                if (uv->u >= 1.0f || uv->v >= 1.0f) {
                    scroll_ginja_mesh_uvs(node->model, (s32)uv->u, (s32)uv->v, uv->texture, 1);
                    uv->u -= (f32)(s32)uv->u;
                    uv->v -= (f32)(s32)uv->v;
                }
            }
            if (anim->flags & 0x40) {
                anim->cycle->timer--;
                if (anim->cycle->timer < 0) {
                    (*(s16 *)&anim->cycle->index)++;
                    load_texture_sequence_frame(this, (SceneMaterialCycle*)(anim->cycle));
                    ((TObjDoorJung *)(node->model))->free_children((void *)anim->cycle->texture);
                }
            }
            anim->flags |= 0x20000;
        }
    }
    PPCSync();
}

#pragma defer_codegen on
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TScene::render() {
    static void (TScene::*tbl[4])() = {
        &TScene::sub_80204D7C, &TScene::cull_sections, &TScene::update_room_visibility_from_camera, &TScene::update_records_in_range,
    };
    s32 i;

    if (TScene__floor_scene_ready_flag != 0 && TScene__data_805D5FCC != NULL) {
        if (TMainTask::get_render_pass() == 0) {
            for (i = 0; i < TScene__data_805D5FCC->count; i++) {
                TScene__data_805D5FCC->sections[i].flags &= ~0x10000;
            }
            (this->*tbl[TScene__sub_80205874(this)])();
        }
        render_map_sections();
        set_material_alpha_compare_reference(0xBF);
    }
}
#pragma pop

extern "C" {
s32 get_main_phase(void);

s32 TScene__sub_80205874(void *) {
    if (TScene__data_805D6020 != NULL) {
        return 2;
    }
    if (TScene__data_805D5FE0 == 1) {
        return 3;
    }
    s32 phase = get_main_phase();
    if (phase == 14) {
        if (is_split_screen() == 1 && TOKeyMachine01::get_global_state() == 1) {
            return 1;
        }
        return 0;
    } else if (phase == 15) {
        switch (TOKeyMachine01::get_global_state()) {
        case 1:
        case 2:
            return 1;
        }
        return 0;
    }
    return 0;
}
void TScene::render_map_sections() {
    SceneMaterialSection *sec;
    s32 i;
    if (TScene__data_805D5FCC != NULL) {
        TObjPlayer::draw_if_all_ready();
        if (TScene__render_callback != NULL) {
            TScene__render_callback();
        }
        if (*(void **)((u8 *)TScene__data_805D5FCC + 0x14) != NULL) {
            TObjFish::set_global_param((s32)(*(void **)((u8 *)TScene__data_805D5FCC + 0x14)));
        }
        sec = TScene__data_805D5FCC->sections;
        prepare_ginja_model();
        saved_model_render_flags = model_render_flags;
        for (i = 0; i < TScene__data_805D5FCC->count; i++, sec++) {
            if (sec->flags & 0x10000) {
                if (sec->flags & 0x80000) {
                    push_matrix();
                    switch (TOKeyMachine01::get_global_state()) {
                    case 0:
                    case 0xF:
                    case 0x12:
                        render_static_map_section(sec, 0);
                        render_animated_map_section(sec, 0);
                        break;
                    default:
                        render_static_map_section(sec, 1);
                        render_animated_map_section(sec, 1);
                        break;
                    }
                    pop_matrix();
                } else if (sec->flags & 0x100000) {
                    push_matrix();
                    post_translate_matrix(sec->position);
                    rotate_matrix_by_node_angles(sec->angles, 1);
                    render_static_map_section(sec, 1);
                    render_animated_map_section(sec, 1);
                    pop_matrix();
                } else {
                    push_matrix();
                    post_translate_matrix(sec->position);
                    rotate_matrix_by_node_angles(sec->angles, 1);
                    render_static_map_section(sec, 0);
                    render_animated_map_section(sec, 0);
                    pop_matrix();
                }
            }
        }
        model_render_flags = saved_model_render_flags;
        end_ginja_model_draw();
    }
}
void TScene::render_static_map_section(SceneMaterialSection *scene_material_section, s32 arg2) {
    SceneMaterialStatic *e;
    s32 i;
    Node_8020533C *node;
    void *tex;

    for (i = 0, e = scene_material_section->objects; i < scene_material_section->count; i++, e++) {
        if (arg2 != 0 && !(e->flags & 0x10000)) {
            continue;
        }
        if (e->node == NULL) {
            continue;
        }
        if (TScene__data_805D5FE0 == 1 && !(e->flags & 0x100)) {
            continue;
        }
        if (TScene__data_805D5FE0 == 0 && (e->flags & 0x100)) {
            continue;
        }
        if (e->flags & 1) {
            TParticleCtrl::begin_effect_render();
        }
        if (e->flags & 2) {
            model_render_flags |= 1;
        }
        if (e->flags & 0x10) {
            Node_8020533C *sh = (Node_8020533C *)resolve_indirect_node_record(this, e);
            if (sh != NULL) {
                Vec_8020533C v;
                Ang_8020533C a;
                v.x = sh->pos.x;
                v.y = sh->pos.y;
                v.z = sh->pos.z;
                vec3_add_to(&v, scene_material_section->position);
                a.x = sh->ang.x + scene_material_section->angles[0];
                a.y = sh->ang.y + scene_material_section->angles[1];
                a.z = sh->ang.z + scene_material_section->angles[2];
                render_projected_shadow_receiver(&v, &a);
            }
        }
        node = (Node_8020533C *)resolve_indirect_node_record(this, e);
        if (TScene__map_section_render_callback != NULL) {
            Vec_8020533C v;
            Ang_8020533C a;
            v.x = node->pos.x;
            v.y = node->pos.y;
            v.z = node->pos.z;
            vec3_add_to(&v, scene_material_section->position);
            a.x = node->ang.x + scene_material_section->angles[0];
            a.y = node->ang.y + scene_material_section->angles[1];
            a.z = node->ang.z + scene_material_section->angles[2];
            TScene__map_section_render_callback(&v, &a, e->flags);
        }
        if (e->flags & 0x200) {
            if (e->flags & 0x80) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    TObjEneRecon::notify_scene(m->fF);
                } else {
                    TObjEneRecon::notify_scene(-1);
                }
                TObjFish::set_global_param((s32)((void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14)));
                set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
                draw_ginja_object(node);
                TObjEneRecon::update_particle_if_active();
            } else if (e->flags & 0x400) {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL && TMainTask::get_render_pass() == 1) {
                    Lobby_8020533C l;
                    l.v.x = node->pos.x;
                    l.v.y = node->pos.y;
                    l.v.z = node->pos.z;
                    vec3_add_to(&l.v, scene_material_section->position);
                    l.a.x = node->ang.x + scene_material_section->angles[0];
                    l.a.y = node->ang.y + scene_material_section->angles[1];
                    l.a.z = node->ang.z + scene_material_section->angles[2];
                    l.param = (void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14);
                    l.node = node;
                    l.scene = TScene__data_805D5FCC->flags;
                    l.id = m->fF;
                    release_indexed_entry__6TLobbyFl(&l);
                }
            } else {
                Model_8020533C *m = (Model_8020533C *)e->node;
                if (m != NULL) {
                    if (m->tex != NULL) {
                        draw_field_1c__6TSceneFlll(tex = m->tex, m->f8, m->fE, 0);
                        TObjFish::set_global_param((s32)((void *)*(s32 *)((s8 *)TScene__data_805D5FCC + 0x14)));
                        set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
                        draw_ginja_object(node);
                        TScene::set_indirect_tev((u32)tex, 0);
                    }
                }
            }
        } else {
            set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
            draw_ginja_object(node);
        }
        if (e->flags & 0x10) {
            TScene::apply_single_screen_state();
        }
        if (e->flags & 2) {
            model_render_flags &= ~1;
        }
        if (e->flags & 1) {
            TParticleCtrl::end_effect_render();
        }
        if (TScene__active_scene_callback != NULL) {
            TScene__active_scene_callback(e->flags);
        }
    }
}
void draw_ginja_model_with_motion(void *, void *, f32);
void TScene::render_animated_map_section(SceneMaterialSection *scene_material_section, s32 arg2) {
  void *texture;
  SceneMaterialAnimated *e;
  s32 i;
  Node_8020533C *node;
  for (i = 0, e = scene_material_section->animated; i < scene_material_section->animatedCount; i++, e++)
  {
    if ((arg2 != 0) && (!(e->flags & 0x10000)))
    {
      continue;
    }
    if (e->node == 0)
    {
      continue;
    }
    if (e->motion == 0)
    {
      continue;
    }
    if ((TScene__data_805D5FE0 == 1) && (!(e->flags & 0x100)))
    {
      continue;
    }
    if ((TScene__data_805D5FE0 == 0) && (e->flags & 0x100))
    {
      continue;
    }
    if (e->flags & 1)
    {
      TParticleCtrl::begin_effect_render();
    }
    if (e->flags & 2)
    {
      model_render_flags |= 1;
    }
    node = (Node_8020533C *) resolve_indirect_object_record(this, e);
    if (e->flags & 0x10)
    {
      Vec_8020533C v;
      Ang_8020533C a;
      v.x = node->pos.x;
      v.y = node->pos.y;
      v.z = node->pos.z;
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->ang.x + scene_material_section->angles[0];
      a.y = node->ang.y + scene_material_section->angles[1];
      a.z = node->ang.z + scene_material_section->angles[2];
      render_projected_shadow_receiver(&v, &a);
    }
    if (TScene__map_section_render_callback != 0)
    {
      Vec_8020533C v;
      Ang_8020533C a;
      v.x = node->pos.x;
      v.y = node->pos.y;
      v.z = node->pos.z;
      vec3_add_to(&v, scene_material_section->position);
      a.x = node->ang.x + scene_material_section->angles[0];
      a.y = node->ang.y + scene_material_section->angles[1];
      a.z = node->ang.z + scene_material_section->angles[2];
      TScene__map_section_render_callback(&v, &a, e->flags);
    }
    if (e->flags & 0x200)
    {
      Model_8020533C *m = (Model_8020533C *) e->node;
      if (m != 0)
      {

        void *tex = m->tex;
        if (tex != 0)
        {
          draw_field_1c__6TSceneFlll(texture = tex, m->f8, m->fE, 0);
          TObjFish::set_global_param((s32)((void *) (*((s32 *) (((s8 *) TScene__data_805D5FCC) + 0x14)))));
          set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
          draw_ginja_model_with_motion(node, e->motion, e->frame);
          TScene::set_indirect_tev((u32) texture, 0);
        }

      }
    }
    else
      if (TRaderMapCore::is_not_split_screen() == 1)
    {
      set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
      draw_ginja_object(node);
    }
    else
    {
      set_material_alpha_compare_reference(TScene__data_805D5FCC->flags);
      draw_ginja_model_with_motion(node, e->motion, e->frame);
    }
    if (e->flags & 0x10)
    {
      TScene::apply_single_screen_state();
    }
    if (e->flags & 2)
    {
      model_render_flags &= ~1;
    }
    if (e->flags & 1)
    {
      TParticleCtrl::end_effect_render();
    }
    if (TScene__active_scene_callback != 0)
    {
      TScene__active_scene_callback(e->flags);
    }
  }

}
extern "C" {
extern Vec_80204024 lbl_8044A840[];
}

void TScene::sub_80204D7C() {
    Vec_80204024 dir;
    Vec_80204024 d;
    Vec_80204024 up = lbl_8044A840[0];
    Vec_80204024 p;
    f32 far2;
    SceneMaterialSection *sec;
    s32 i;

    if (TScene__data_805D5FCC == NULL) {
        return;
    }
    m_1c = 0;
    far2 = TScene__data_805D5FCC->radius * TScene__data_805D5FCC->radius;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, CAM->a194);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrices(1);

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++) {
        if (sec->flags & 0x80000) {
            update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = TScene__data_805DC5D8;
            p.z = sec->position[2];
            d.x = p.x - CAM->x;
            d.y = TScene__data_805DC5D8;
            d.z = p.z - CAM->z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                m_1c++;
            } else if (dist > far2) {
                sec->flags &= ~0x10000;
                sec++;
            } else {
                normalize_vector(&d);
                dot = vec3_dot(&dir, &d);
                if (dot < TScene__data_805DC5D8) {
                    sec->flags &= ~0x10000;
                    sec++;
                } else if (dot >= TScene__data_805DC5D8 && dot < TScene__data_805DC600) {
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, CAM->a19C);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (TEST(sec->radius, this, &p, &d, &up) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        m_1c++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -CAM->a19C);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (TEST(sec->radius, this, &p, &d, &up) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            m_1c++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    m_1c++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }
}


s32 check_object_in_view_cone__6TSceneFiPvPvPvi(s32 unused, Obj_80204B78 *obj, Vec_80204024 *pos, void *arg3, s32 arg4) {
    Vec_80204024 c;
    Vec_80204024 a;
    Vec_80204024 b;
    f32 r2;
    f32 g2;
    f32 k;
    f32 z;
    f32 x;
    f32 dist2;
    f32 d;
    k = TScene__data_805DC5D8;
    x = obj->x;
    a.x = x;
    a.y = k;
    z = obj->z;
    a.z = z;
    b.x = x - pos->x;
    b.y = k;
    b.z = z - pos->z;
    dist2 = b.x * b.x + b.y * b.y + b.z * b.z;
    r2 = obj->radius * obj->radius;
    g2 = TScene__data_805D5FCC->radius * TScene__data_805D5FCC->radius;
    if (dist2 < r2) {
        obj->flags |= 0x10000;
        return 1;
    }
    if (dist2 > g2) {
        obj->flags &= ~0x10000;
        return 0;
    }
    normalize_vector(&b);
    d = vec3_dot(arg3, &b);
    if (d < TScene__data_805DC5D8) {
        obj->flags &= ~0x10000;
        return 0;
    }
    if (d >= TScene__data_805DC5D8 && d < TScene__data_805DC600) {
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, arg4);
        rotate_vector_by_matrix(0, arg3, &c);
        normalize_vector(&c);
        pop_matrix();
        if (TScene__sub_80204024(obj->radius, unused, &a, &b, &c) != 0) {
            obj->flags |= 0x10000;
            return 1;
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, -arg4);
        rotate_vector_by_matrix(0, arg3, &c);
        normalize_vector(&c);
        pop_matrix();
        if (TScene__sub_80204024(obj->radius, unused, &a, &b, &c) != 0) {
            obj->flags |= 0x10000;
            return 1;
        }
    } else {
        obj->flags |= 0x10000;
        return 1;
    }
    obj->flags &= ~0x10000;
    return 0;
}
}

void TScene::cull_sections() {
    Task_80204688 *task = (Task_80204688*)this;
    static f32 s_near = lbl_805DC5E8;
    static f32 s_far = lbl_805DC5EC;
    static f32 s_pad = lbl_805DC5F0;
    Vec_80204024 dir;
    Vec_80204024 d;
    Vec_80204024 up = lbl_8044A84C[0];
    Vec_80204024 p;
    Vec_80204024 v;
    s32 i;
    SceneMaterialSection *sec;

    if (TScene__data_805D5FCC == NULL) {
        return;
    }
    if (is_split_screen() != 0) {
        s_near = lbl_805DC5F4;
        s_far = lbl_805DC5F8;
    } else {
        s_near = lbl_805DC5FC;
        s_far = TScene__data_805D5FCC->radius;
    }
    task->count = 0;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, CAM->a194);
    rotate_vector_by_matrix(0, &up, &dir);
    normalize_vector(&dir);
    pop_matrix();

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++) {
        if (sec->flags & 0x80000) {
            ((TScene *)task)->update_room_object_visibility(sec);
            sec++;
        } else {
            f32 dist;
            f32 dot;
            p.x = sec->position[0];
            p.y = TScene__data_805DC5D8;
            p.z = sec->position[2];
            d.x = p.x - CAM->x;
            d.y = TScene__data_805DC5D8;
            d.z = p.z - CAM->z;
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < sec->radius * sec->radius) {
                sec->flags |= 0x10000;
                sec++;
                task->count++;
            } else if (dist > s_far * s_far) {
                sec->flags &= ~0x10000;
                sec++;
            } else {
                normalize_vector(&d);
                dot = vec3_dot(&dir, &d);
                if (dot < TScene__data_805DC5D8) {
                    sec->flags &= ~0x10000;
                    sec++;
                } else if (dot >= TScene__data_805DC5D8 && dot < TScene__data_805DC600) {
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, CAM->a19C);
                    rotate_vector_by_matrix(0, &dir, &up);
                    normalize_vector(&up);
                    pop_matrices(1);
                    if (TEST(sec->radius, task, &p, &d, &up) != 0) {
                        sec->flags |= 0x10000;
                        sec++;
                        task->count++;
                    } else {
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, -CAM->a19C);
                        rotate_vector_by_matrix(0, &dir, &up);
                        normalize_vector(&up);
                        pop_matrices(1);
                        if (TEST(sec->radius, task, &p, &d, &up) != 0) {
                            sec->flags |= 0x10000;
                            sec++;
                            task->count++;
                        } else {
                            goto clear;
                        }
                    }
                } else {
                    sec->flags |= 0x10000;
                    sec++;
                    task->count++;
                }
            }
        }
        continue;
    clear:
        sec->flags &= ~0x10000;
        sec++;
    }

    sec = TScene__data_805D5FCC->sections;
    for (i = 0; i < TScene__data_805D5FCC->count; i++, sec++) {
        if (sec->flags & 0x100000) {
            SceneMaterialStatic *st = sec->objects;
            s32 j;
            for (j = 0; j < sec->count; j++, st++) {
                Node_80204688 *n = (Node_80204688 *)resolve_indirect_node_record(task, st);
                v.x = n->model->x + (sec->position[0] + n->x);
                v.y = n->model->y + (sec->position[1] + n->y);
                v.z = n->model->z + (sec->position[2] + n->z);
                if (VIS(task, &v, s_near + s_pad, lbl_805DC5E0) != 0) {
                    st->flags |= 0x10000;
                } else {
                    st->flags &= ~0x10000;
                }
            }
            {
                SceneMaterialAnimated *an = sec->animated;
                for (j = 0; j < sec->animatedCount; j++, an++) {
                    Node_80204688 *n = (Node_80204688 *)resolve_indirect_object_record(task, an);
                    v.x = sec->position[0] + n->x;
                    v.y = sec->position[1] + n->y;
                    v.z = sec->position[2] + n->z;
                    if (VIS(task, &v, s_near + s_pad, lbl_805DC5E0) != 0) {
                        an->flags |= 0x10000;
                    } else {
                        an->flags &= ~0x10000;
                    }
                }
            }
        }
    }
}

#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void TScene::update_room_visibility_from_camera() {
    Vec_802043CC dir;
    Vec_802043CC fwd;
    Vec_802043CC out;
    Tbl_802043CC *tbl;
    s32 j;
    Ent_802043CC *e;
    s16 *ids;
    SceneMaterialSection *room;
    s32 sec;
    s32 i;
    f32 d;
    sec = ((TScene *)(&(*(Cam_802043CC * *)&camera_ctrl_instance)->pos))->find_section_at_position();
    if (sec < 0) {
        sub_80204D7C();
        return;
    }
    tbl = TScene__data_805D6020;
    for (i = 0, e = tbl->ents; i < tbl->count; e++, i++) {
        if (e->id == sec) {
            break;
        }
    }
    if (i >= tbl->count) {
        sub_80204D7C();
        return;
    }
    room = find_scene_room_by_id(sec);
    if (room != NULL) {
        room->flags |= 0x10000;
    }
    tbl = (Tbl_802043CC *)((u8 *)tbl + tbl->count * 0xC);
    ids = (s16 *)tbl->ents;
    for (j = 0; j < e->n; j++) {
        room = find_scene_room_by_id(ids[e->start + j]);
        if (room != NULL) {
            d = xz_distance_squared(room->position, &(*(Cam_802043CC * *)&camera_ctrl_instance)->pos);
            if (d < room->radius * room->radius) {
                room->flags |= 0x10000;
            } else {
                VecCopy__FP3VecPC3Vec(&dir, room->position);
                subtract_vector(&dir, &(*(Cam_802043CC * *)&camera_ctrl_instance)->pos);
                normalize_vector((Vec_80204024 *)(&dir));
                fwd.x = TScene__data_805DC5D8;
                fwd.y = TScene__data_805DC5D8;
                fwd.z = lbl_805DC5E4;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, (*(Cam_802043CC * *)&camera_ctrl_instance)->angY);
                rotate_vector_by_matrix(0, &fwd, (Vec_80204024 *)(&out));
                pop_matrix();
                normalize_vector((Vec_80204024 *)(&out));
                if (vec3_dot(&dir, &out) < TScene__data_805DC5D8) {
                    room->flags &= ~0x10000;
                } else if (d < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->radius * (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->radius) {
                    room->flags |= 0x10000;
                } else {
                    room->flags &= ~0x10000;
                }
            }
        }
    }
    {
        W_802043CC w = lbl_8044A858[0];
        Vec_802043CC out2;
        SceneMaterialSection *s;
        s32 k;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, (*(Cam_802043CC * *)&camera_ctrl_instance)->angY);
        rotate_vector_by_matrix(0, &w, (Vec_80204024 *)(&out2));
        normalize_vector((Vec_80204024 *)(&out2));
        pop_matrix();
        s = (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->sections;
        for (k = 0; k < (*(SceneMaterialRoot * *)&TScene__data_805D5FCC)->count; k++, s++) {
            if (s->flags & 0x80000) {
                update_room_object_visibility(s);
            } else if (s->id < 0) {
                check_object_in_view_cone__6TSceneFiPvPvPvi((s32)this, (Obj_80204B78 *)(s), (Vec_80204024 *)(&(*(Cam_802043CC * *)&camera_ctrl_instance)->pos), &out2, (s32)((*(Cam_802043CC * *)&camera_ctrl_instance)->f19C));
            }
        }
    }
}
#pragma pop

void TScene::update_records_in_range() {
    f32 r;
    f32 r2;
    s32 off;
    s32 i;
    W_8020430C v = (*(Cam_8020430C * *)&camera_ctrl_instance)->pos;
    i = 0;
    off = 0;
    r = (*(Root_8020430C * *)&TScene__data_805D5FCC)->radius + TScene__visibility_radius_margin;
    r2 = r * r;
    for (; i < (*(Root_8020430C * *)&TScene__data_805D5FCC)->count; i++, off += 0x34) {
        Rec_8020430C *rec = (Rec_8020430C *)((u8 *)(*(Root_8020430C * *)&TScene__data_805D5FCC)->recs + off);
        if (xz_distance_squared(&v, rec->pos) < r2) {
            rec->flags |= 0x10000;
        } else {
            rec->flags &= ~0x10000;
        }
    }
}

void TScene::update_room_object_visibility(SceneMaterialSection *room) {
    SceneMaterialStatic *object;
    s32 i;
    SceneMaterialAnimated *anim;
    i = 0;
    room->flags |= 0x10000;
    for (object = room->objects; i < room->count; i++, object++) {
        if (object->node != NULL) {
            if (TScene__sub_802040D4(this, (Obj_802040D4 *)((SceneMaterialNode *)resolve_indirect_node_record(this, (SceneMaterialStatic*)(object))), lbl_805DC5DC, lbl_805DC5E0) != 0) {
                object->flags |= 0x10000;
            } else {
                object->flags &= ~0x10000;
            }
        }
    }
    for (anim = room->animated, i = 0; i < room->animatedCount; i++, anim++) {
        if (anim->node != NULL) {
            if (TScene__sub_802040D4(this, (Obj_802040D4 *)((SceneMaterialNode *)resolve_indirect_object_record(this, (SceneMaterialAnimated*)(anim))), lbl_805DC5DC, lbl_805DC5E0) != 0) {
                anim->flags |= 0x10000;
            } else {
                anim->flags &= ~0x10000;
            }
        }
    }
}
bool is_in_view_depth__6TSceneFf(f32 farg0) {
    f32 sp[6];
    void *unused;
    matrix_mult_vec(0, unused, &sp[0]);
    if (sp[2] > TScene__data_805DC5D8) {
        return 0;
    }
    return (sp[2] < -farg0) == 0;
}
s32 TScene__sub_802040D4(void *arg0, Obj_802040D4 *o, f32 f0, f32 f1) {
    if (o->inner != NULL && (*(u8 * *)&camera_ctrl_instance) != NULL) {
        void *p = o->pos;
        if (xz_distance_squared((*(u8 * *)&camera_ctrl_instance) + 0x178, p) < o->inner->radius * o->inner->radius) {
            return 1;
        }
        return ((s32 (*)(void *, void *, f32, f32))is_in_view_depth__6TSceneFf)(arg0, p, f0, f1);
    }
    return 0;
}
s32 TScene__sub_80204024(f32 thr, s32 unused, void *a, void *b, Vec_80204024 *c) {
    struct { Vec_80204024 p, q; } s;
    Vec_80204024 o;
    if (vec3_dot(b, c) < TScene__data_805DC5D8) {
        return 0;
    }
    s.p.x = camera_ctrl_instance->x;
    s.p.y = TScene__data_805DC5D8;
    s.p.z = camera_ctrl_instance->z;
    s.q.x = c->x;
    s.q.y = c->y;
    s.q.z = c->z;
    return project_point_onto_line(a, &s, &o) <= thr;
}
void advance_scene_object_animations(void) {
    Group_80203F0C *g;
    s32 i;
    Anim_80203F0C *a;
    s32 j;
    if ((*(Root_80203F0C **)&TScene__data_805D5FCC) == NULL) {
        return;
    }
    g = (*(Root_80203F0C **)&TScene__data_805D5FCC)->groups;
    for (i = 0; i < (*(Root_80203F0C **)&TScene__data_805D5FCC)->count; i++, g++) {
        a = g->anims;
        for (j = 0; j < g->count; j++, a++) {
            a->flags &= ~0x40000;
        }
    }
    g = (*(Root_80203F0C **)&TScene__data_805D5FCC)->groups;
    for (i = 0; i < (*(Root_80203F0C **)&TScene__data_805D5FCC)->count; i++, g++) {
        a = g->anims;
        for (j = 0; j < g->count; j++, a++) {
            if (!(a->flags & 0x40000)) {
                a->frame += a->speed;
                if (a->motion != NULL && a->frame > (a->motion->frames - 1)) {
                    a->frame = TScene__data_805DC5D8;
                }
                a->flags |= 0x40000;
            }
        }
    }
}

void TScene::dispatch_material_animation() {
    typedef void (TScene::*MaterialTicker)();
    static MaterialTicker fns[2] = {
        &TScene::tick_material_fmt1,
        &TScene::tick_material_fmt2,
    };
    (this->*fns[TScene__data_805D5FE8])();
}

#pragma defer_codegen off
