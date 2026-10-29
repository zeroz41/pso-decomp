#include "pso/effect/TEffStarLight2D.h"
#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/object/TObjCamera.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObjCamera_8017F80C.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOKey.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct V3_8017F624 { s32 x; s32 y; s32 z; };

struct Vec_8017F6C0 { f32 x, y, z; };

struct Obj_8017F6C0 { u8 pad[0x38]; Vec_8017F6C0 pos; };

struct Out_8017F6C0 { f32 x, y; };

extern "C" {
void get_camera_ctrl__9TObjEneDDFv(void *, void *);
extern s32 camera_slot_id_table[];
extern V3_8017F624 camera_slot_zero_vec_table[];
extern V3_8017F624 camera_slot_positions[];
extern s32 TObjCamera__camera_slot_scan_index;
void matrix_mult_vec(s32, Vec_8017F6C0 *, Vec_8017F6C0 *);
void project_world_to_screen(s32, Vec_8017F6C0 *, Out_8017F6C0 *);
extern Vec_8017F6C0 camera_right;

void TObjCamera::update_camera_slots() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (TObjCamera__camera_slot_scan_index == camera_slot_id_table[i]) {
            V3_8017F624 v = camera_slot_zero_vec_table[0];
            get_camera_ctrl__9TObjEneDDFv(&v, &camera_slot_positions[i]);
        }
    }
    TObjCamera__camera_slot_scan_index += 1;
}
#pragma push
#pragma fp_contract on
#pragma fp_contract on
s32 TObjCamera::update_object_view_visibility(f32 r, f32 d) {
    Obj_8017F6C0 *o = (Obj_8017F6C0 *)this;
    Vec_8017F6C0 v;
    Out_8017F6C0 out;
    matrix_mult_vec(0, &o->pos, &v);
    if (v.z < -r) {
        return 0;
    }
    if (v.x < 0.0f) {
        v.x = o->pos.x - camera_right.x * d;
        v.y = camera_right.y * d + o->pos.y;
        v.z = camera_right.z * d + o->pos.z;
        project_world_to_screen(0, &v, &out);
        if (out.x < 0.0f) {
            return 0;
        }
    } else {
        v.x = camera_right.x * d + o->pos.x;
        v.y = o->pos.y - camera_right.y * d;
        v.z = o->pos.z - camera_right.z * d;
        project_world_to_screen(0, &v, &out);
        if (out.x > 6.4e+02f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

}

struct RecoveredGlobal_8017FC78_lbl_804B5888 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8017FC78_lbl_804B5888_size[sizeof(RecoveredGlobal_8017FC78_lbl_804B5888) == 0x10 ? 1 : -1];

struct Vec_8017F80C { f32 x, y, z; };


struct Vec_8017F910 { f32 x, y, z; };

struct Obj_8017F910 {
    u8 pad[0x38];
    Vec_8017F910 pos;
    u8 pad44[0xB0 - 0x44];
    f32 time;
    f32 period;
    f32 speed;
    u8 padbc[0xC8 - 0xBC];
    s32 visible;
    void *lights[8];
};

struct Color_8017FCD0 { f32 a; s32 r; s32 g; s32 b; };

struct Piece_8017FCD0 {
    u8 pad0[0x18];
    s32 x18;
    s32 x1c;
    s32 x20;
    u8 pad24[0xC];
    f32 x30;
    u8 pad34[4];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Copy_8017FA9C { u32 w[5]; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8017FC78_lbl_804B5888 fe_obj_cam_resource_descriptor;
extern u32 TObjCamera__bml_resource;
extern s32 TObjCamera__camera_slot_scan_index;
s32 get_bml_motion(u32, int);
void TObjFish__sub_8001EDB0(u32, int);
s32 get_bml_model(u32, int);

void rotate_matrix_y(int, s32);
void push_matrix();
void pop_matrix();
void post_translate_matrix(void *);
void set_global_param__8TObjFishFl();
void set_model_node_callback(void *);
void draw_ginja_model_with_motion(s32, s32, f32);

void fn_8017F4AC(void *);
void fn_8017F52C();
Obj_8017F910 *get_player_by_client_id(s32);
f32 vec_squared_length(Vec_8017F910 *);
extern s32 local_client_id;

void run_task__10TObjCameraFv(Obj_8017F910 *self);
}
void rotate_matrix_yxz(s32 matrix, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
void scale_matrix(int, f32, f32, f32);
void draw_ginja_object(int);
void set_color_blend_mode(int, int, int, int, s32, s32);
extern Color_8017FCD0 chip_color_white_c;
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
s32 is_split_screen(void);
void *__ct__15TEffStarLight2DFPvPvP7TObject(void *, void *, void *, void *);
void fn_8017F550(void *);
void *__nw__7TObjectFUl(int);
extern Copy_8017FA9C camera_object_init_params;
extern s32 TObjCamera__name;

void TLobby__sub_8001FE7C(void*, int);

void TObjCamera::render() {
    s32 i;
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        TObjFish__sub_8001EDB0(TObjCamera__bml_resource, 0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix(&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjCamera__camera_slot_scan_index = 0;
        set_model_node_callback((void *)TObjCamera::update_camera_slots);
        draw_ginja_model_with_motion(get_bml_model(TObjCamera__bml_resource, 0),
                               get_bml_motion(TObjCamera__bml_resource, 0), this->m_b0);
        set_model_node_callback(NULL);
        pop_matrix();
        if (this->lights_visible != 0) {
            for (i = 0; i < 8; i++) {
                if (this->lights[i] != NULL) {
                    ((TEffStarLight2D *)this->lights[i])->copy_position((const Vec *)&camera_slot_positions[i]);
                }
            }
        }
    }
}

void run_task__10TObjCameraFv(Obj_8017F910 *self) {
    Vec_8017F910 d;
    Obj_8017F910 *pl;
    s32 i;
    s32 j;
    self->time += self->speed;
    if (self->time > self->period - 1.0f) {
        self->time = 0.0f;
        fn_8017F52C();
    }
    if (self->visible != 0) {
        fn_8017F4AC(self);
    }
    pl = get_player_by_client_id(local_client_id);
    if (pl != NULL) {
        d.x = pl->pos.x - self->pos.x;
        d.z = pl->pos.z - self->pos.z;
        d.y = 0.0f;
        if (vec_squared_length(&d) <= 1.44e+04f) {
            for (i = 0; i < 8; i++) {
                if (self->lights[i] != NULL) {
                    allow_rendering__7TObjectFv((TObject *)self->lights[i]);
                }
            }
            self->visible = 1;
        } else {
            for (j = 0; j < 8; j++) {
                if (self->lights[j] != NULL) {
                    disallow_rendering__7TObjectFv((TObject *)self->lights[j]);
                    ((TEffStarLight2D *)self->lights[j])->queue_child_destruction();
                }
            }
            self->visible = 0;
        }
    }
}

TObjCamera::~TObjCamera() {}

extern void *tl_05;

TObjCamera::TObjCamera(TObject *parent, void *set_data) : TObjMapObject(parent) {
    s32 i;
    void *obj;
    m_name = (const char *)TObjCamera__name;
    Copy_8017FA9C c = camera_object_init_params;
    apply_object_set_data(set_data);
    m_b0 = 0.0f;
    m_b8 = 0.8f;
    animation_end_frame = *(u32 *)(get_bml_motion(TObjCamera__bml_resource, 0) + 4);
    if (is_split_screen() != 0) {
        for (i = 0; i < 8; i++) {
            lights[i] = 0;
        }
    } else {
        for (i = 0; i < 8; i++) {
            obj = __nw__7TObjectFUl(0x4C);
            if (obj != 0) {
                obj = __ct__15TEffStarLight2DFPvPvP7TObject(obj, &position, &c, this);
            }
            lights[i] = obj;
        }
    }
    lights_visible = 0;
    fn_8017F550(this);
}

void *TObjCamera::create(void *arg0) {
    return new TObjCamera((TObject *)tl_05, arg0);
}

void TObjCamera::release_static_resource() {
    if ((u32) TObjCamera__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjCamera__bml_resource, 1);
        TObjCamera__bml_resource = 0U;
    }
}
void TObjCamera::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    TObjCamera__camera_slot_scan_index = 0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &fe_obj_cam_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjCamera__bml_resource) = var_r0;
}
void TObjChip__vt10(u8 *arg0) {
    Piece_8017FCD0 *p = (Piece_8017FCD0 *)(arg0 + 0x70);
    s32 i;
    s32 j;
    if (*(s32 *)(arg0 + 0x6C) & 4) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x8011;
        set_color_blend_mode(1, 4, 5, 0, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask);
        for (i = 0; i < *(s32 *)(arg0 + 0x54); i++, p++) {
            Color_8017FCD0 c = chip_color_white_c;
            c.a = p->x30;
            set_constant_material((const NJS_ARGB *)((&c)));
            push_matrix();
            post_translate_matrix(p);
            rotate_matrix_yxz(0, p->x18, p->x1c, p->x20);
            scale_matrix(0, *(f32 *)(arg0 + 0x60), *(f32 *)(arg0 + 0x60), *(f32 *)(arg0 + 0x60));
            draw_ginja_object(*(s32 *)(arg0 + 0x64));
            pop_matrix();
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        }
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    } else {
        for (j = 0; j < *(s32 *)(arg0 + 0x54); j++, p++) {
            push_matrix();
            post_translate_matrix(p);
            rotate_matrix_yxz(0, p->x18, p->x1c, p->x20);
            scale_matrix(0, *(f32 *)(arg0 + 0x60), *(f32 *)(arg0 + 0x60), *(f32 *)(arg0 + 0x60));
            draw_ginja_object(*(s32 *)(arg0 + 0x64));
            pop_matrix();
        }
    }
}
}
