#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TOVS2Wall01.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct VBase_14_1eb8da { char pad[0x14]; };

struct VObj_14_1eb8da : VBase_14_1eb8da {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
    virtual s32 m7();
};

extern "C" {
s32 TOVS2Wall01__sub_8017B9AC(void *);
s32 update_obstruction_fade(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void __ct__9TObjCharaFP7TObject(void *, void *);
void obj_setFlags30(void *, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void activate_and_dispatch__10TObjPlayerFv(void *, s32, f32);
void init_collision_body_parts(void *, void *, s32);
extern u8 ovs2wall01_collision_parts[];
extern s32 __vt__11TOVS2Wall01[];
extern s32 TOVS2Wall01__class_name;
extern s32 TOVS2Wall01__bml_resource;
extern void *tl_05;
extern const f32 lbl_805DBAAC;
extern const f32 lbl_805DBAB0;
void *TOVS2Wall01__ct(TOVS2Wall01 *arg0, void *arg1);
void *__dt__11TOVS2Wall01Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
int submit_cursor_candidate(void*, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void queue_destruction__7TObjectFv(void *arg0);

void TOVS2Wall01::release() { set_flag8(); queue_destruction__7TObjectFv(this); }
int TOVS2Wall01::interact_player_neg1() { return submit_cursor_candidate(this, -1); }

void TOVS2Wall01::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        TOVS2Wall01__sub_8017B9AC(arg0);
        return;
    }
    switch (this->mode) {
    default:
        this->mode = 0;
    case 0:
        interact_player_neg1();
        return;
    case 1:
        release();
        return;
    }
}

void TOVS2Wall01::render() {
    u8 *arg0 = (u8 *)this;
    s32 var_r31;
    update_obstruction_fade((u8 *)&this->m_340);
    *(s32 *)&this->m_35c = ((VObj_18_26a62c *)(arg0))->m8(*(f32 *)&this->unk_334, this->m_338);
    if ((s32) this->m_35c == 1) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            var_r31 = 0;
        } else {
            var_r31 = ((RenderFadeState *)(arg0 + 0x340))->updateFromCamera((const f32*)(arg0 + 0x38));
        }
        if (var_r31 != 0) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            ((VObj_14_1eb8da *)(arg0 + (832)))->m6(chunk_polygon_flags_and_mask, model_render_flags);
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
        if (var_r31 != 0) {
            ((VObj_14_1eb8da *)(arg0 + (832)))->m7();
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}

void *TOVS2Wall01::create() {
    void *o = __nw__7TObjectFUl(0x360);
    if (o != NULL) {
        o = TOVS2Wall01__ct((TOVS2Wall01 *)o, this);
    }
    return o;
}

void *__dt__11TOVS2Wall01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TOVS2Wall01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804949A8Fv((s8 *)arg0 + 0x340, -1);
        ((TObjChara *)arg0)->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_common_subs off
void *TOVS2Wall01__ct(TOVS2Wall01 *arg0, void *arg1) {
    s32 t;
    __ct__9TObjCharaFP7TObject(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TOVS2Wall01;
    ((TObjPlayer *)((u8 *)arg0 + 0x340))->init_and_activate();
    *(s32 *)((s8 *)arg0 + 0) = TOVS2Wall01__class_name;
    arg0->apply_object_set_data(arg1);
    ((TObjChara *)arg0)->calc_attach_pos();
    obj_setFlags30(arg0, 0x60000000);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(TOVS2Wall01__bml_resource, 6);
    arg0->texlist = TObjFish__sub_8001EDB0(TOVS2Wall01__bml_resource, 6);
    init_collision_body_parts(arg0, ovs2wall01_collision_parts + 0x108, 1);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x08000000);
    ((TObjPlayer *)arg0)->register_object_by_id();
    arg0->mode = 0;
    *(f32 *)((s8 *)arg0 + 0x334) = lbl_805DBAAC;
    arg0->m_338 = lbl_805DBAB0 + *(f32 *)((s8 *)(*(void **)((s8 *)arg0->model + 4)) + 0x14);
    t = arg0->set_params[0];
    arg0->m_33c = t + 0x100;
    activate_and_dispatch__10TObjPlayerFv((u8 *)arg0 + 0x340, t, lbl_805DBAB0);
    arg0->m_35c = 1;
    return arg0;
}
#pragma pop

}
