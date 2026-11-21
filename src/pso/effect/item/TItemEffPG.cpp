#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/weapon/TItemWeapon.h"
#include "types.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804F0A00.h"
#include "pso/weapon/TUnk_804F0AF8.h"
#include "pso/weapon/TUnk_804F0908.h"
#include "pso/weapon/TUnk_804F0810.h"
#include "pso/player/TUnk_804A2548.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/effect/item/TUnk_804F0C08.h"
#include "pso/effect/item/TItemEffPG.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

extern "C" {
void TItemEffPG__begin_visual_fade(void *p);
TParticleCtrl *create_particle_emitter(const void *pos, s32 id);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804F0BF0[];
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
}
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
// Built with -inline off,deferred: functions are written last to first, so
// the vtables come out 0BF0, 0C08, 0C28 as in the original.
// The functions from 0x8034FE28 on were a separate unit; their literals continue
// this TU's .sdata2 pool at 0x805DFE14 (a 4-mod-8 address, so no TU starts there).
const char *TItemEffPG__name = "TItemEffPG";

S_8035016C *S_8035016C::init_params() {
    TObjPlayer__sub_802E451C(this);
    hits = 10;
    pad_28 = 50.0f;
    required_charge = 1.0f;
    pad_30 = 2.5f;
    return this;
}

void TItemEffPG::create(void *arg0, void *arg1) {
    new TItemEffPG((TObject *)arg0, (S_8035016C *)arg1);
}

TItemEffPG::TItemEffPG(TObject *parent, S_8035016C *params) : TUnk_804E355C(parent, params) {
    void *visual;
    m_name = TItemEffPG__name;
    pad_C4 = params->pad_28;
    if (50.0f < pad_C4) {
        pad_C4 = 50.0f;
    }
    m_c8 = params->pad_30;
    required_charge = params->required_charge;
    pad_B0 *= 3.0f;
    visual = operator new(0x68);
    if (visual != NULL) {
        visual = TItemEffPG__visual_ct((u8 *)visual, (u8 *)this, (u8 *)params);
    }
    m_d0 = (uaddr)visual;
}

TItemEffPG::~TItemEffPG() {}

void TItemEffPG::run_task() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_r31;

    var_r31 = 1;
    if (has_game_join_id() == 0) {
        var_r31 = 0;
    }
    if (this->vfunc_7() == 0) {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        temp_f1 = this->body.radius;
        if (temp_f1 < this->pad_C4) {
            this->body.radius = (f32) (temp_f1 + this->m_c8);
            temp_f1_2 = this->pad_C4;
            if (temp_f1_2 < this->body.radius) {
                this->body.radius = temp_f1_2;
            }
        }
        check_hits();
        return;
    }
    if ((uaddr) this->m_down == 0U) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if ((u32) this->m_d0 != 0U) {
        TItemEffPG__begin_visual_fade(*(void * *)&this->m_d0);
        this->m_d0 = 0U;
    }
}

s32 TItemEffPG::vfunc_7() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (player->get_photon_blast_charge() < required_charge) {
        return 0;
    }
    player->vfunc_76(required_charge);
    return 1;
}

void TItemEffPG::create(void *parent, void *params, void *count) {
    new TUnk_804F0C08((TObject *)parent, (S_8035016C *)params, (saddr)count);
}

TUnk_804F0C08::TUnk_804F0C08(TObject *parent, S_8035016C *params, s32 count) : TItemEffPG(parent, params) {
    pad_D4 = count;
}

TUnk_804F0C08::~TUnk_804F0C08() {}

s32 TUnk_804F0C08::vfunc_7() {
    s32 temp_r4;

    temp_r4 = this->pad_D4;
    if (temp_r4 > 0) {
        this->pad_D4 = (temp_r4 - 1);
        return 1;
    }
    return 0;
}

u8 *TItemEffPG__visual_ct(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f1;
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804F0BF0;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg2 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg2 + 0x34);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)arg2 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) *(f32 *)((s8 *)arg2 + 0x30);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) *(f32 *)((s8 *)arg2 + 0x28);
    VecCopy((Vec *)(arg0 + 0x5C), (const Vec *)arg2);
    temp_f1 = *(f32 *)((s8 *)arg2 + 0xC);
    ((TUnk_804F0BF0 *)arg0)->m_50 = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x4C) = temp_f1;
    ((TUnk_804F0BF0 *)arg0)->m_48 = temp_f1;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    ((TUnk_804F0BF0 *)arg0)->m_40 = 0;
    ((TUnk_804F0BF0 *)arg0)->m_28 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
    ((TUnk_804F0BF0 *)arg0)->m_30 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x34) = 0.0f;
    *(saddr *)((s8 *)arg0 + 0x38) = (saddr)create_particle_emitter((arg0 + 0x5C), 0x83);
    ((TUnk_804F0BF0 *)arg0)->m_58 = 0;
    return arg0;
}

TUnk_804F0BF0::~TUnk_804F0BF0() {
    if (this->m_38 != NULL) { ((TObject *)this->m_38)->queue_destruction(); *(s32 *)((s8 *)this + 0x38) = 0; }
}

void TUnk_804F0BF0::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + 0x71C);
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) (*(s32 *)((s8 *)arg0 + 0x40) - 0xE38);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x58) == 0) {
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x50);
        if (temp_f1 < *(f32 *)((s8 *)arg0 + 0x44)) {
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) (temp_f1 + *(f32 *)((s8 *)arg0 + 0x54));
            temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x44);
            if (temp_f1_2 < *(f32 *)((s8 *)arg0 + 0x50)) {
                *(f32 *)((s8 *)arg0 + 0x50) = temp_f1_2;
            }
        }
        temp_f0 = *(f32 *)((s8 *)arg0 + 0x50);
        *(f32 *)((s8 *)arg0 + 0x4C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x48) = temp_f0;
    } else {
        temp_f1_3 = *(f32 *)((s8 *)arg0 + 0x28);
        if (temp_f1_3 <= -1.0f) {
            ((TObject *)arg0)->queue_destruction();
            ((TObject *)arg0)->disallow_rendering();
        } else {
            *(f32 *)((s8 *)arg0 + 0x28) = (f32) (temp_f1_3 - 0.06666667f);
        }
    }
    play_persistent_sound(0x4001A343, (saddr)arg0, (uaddr)(arg0 + 0x5C), 0, 0);
}

void TUnk_804F0BF0::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32)this->all_parents_unqueued_for_destruction() == 0 || find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x1C))) == 0U) {
        return;
    }
    {
        if (((void *) this->m_20 != NULL) && (TMainTask::get_render_pass() == 1)) {
            set_draw_list_mask(3);
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
            model_render_flags |= 0x20;
            set_constant_material((const NJS_ARGB *)(((u8 *)&this->m_28)));
            TParticleCtrl::begin_effect_render();
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
            push_matrix();
            post_translate_matrix((u8 *)&this->unk_5C);
            push_matrix();
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x3C)));
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model(reinterpret_cast<NJS_OBJECT *>(m_20)->model);
            pop_matrix();
            push_matrix();
            rotate_matrix_y(0, this->m_40);
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model(reinterpret_cast<NJS_OBJECT *>(m_20)->child->model);
            pop_matrix();
            pop_matrix();
            TParticleCtrl::end_effect_render();
            copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}

void TItemEffPG__begin_visual_fade(void* p) { *(s32*)((char*)p + 0x58) = 1; }
