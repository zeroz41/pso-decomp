#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/dragon/TObjBoss1Floor.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/dragon/TObjBoss1Crater_8002C6B4.h"
#include "pso/boss/dragon/TObjBoss1Floor_8002C838.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_8002C190.h"
#include "pso/unk/text_8002E174.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/unk/TLobby.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/scene/TScene.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_Solo.h"
#include "pso/system/MatrixStack.h"

struct Obj_8002CACC { s32 f0; u8 pad4[0x14]; void *vt; f32 f1c; f32 f20; f32 f24; s32 f28[4]; };

typedef struct Player_8002C968 {
    u8 pad0[0x38];
    Vec pos;
} Player_8002C968;

typedef struct Floor_8002C968 {
    u8 pad0[0x28];
    void *objs[4];
} Floor_8002C968;

struct Obj_8002CA38 { u8 pad[0x28]; uaddr slot[4]; };

extern "C" {
const char *TObjBoss1Floor__name = "TObjBoss1Floor";
void run_task__14TObjBoss1FloorFv(Floor_8002C968 *self);
void TBoss8Dragon__sub_8002D5F8(void);
void TObjBoss1Floor__sub_8002CB40(void);
void TObjBoss1Floor__sub_8002CB78(void);
void render_projected_shadow_receiver(u8 *arg0, saddr arg1);

void TLobby::update_boss1_objects() { TBoss8Dragon::free_resources(); TObjBoss1Rock__sub_8002E3CC(); TObjBoss1Crater__sub_8002C7B4(); TObjBoss1Floor__sub_8002CB40(); TLobby::free_char_select(); }
void TLobby::forward_floor_2CB44() { TObjBoss1Floor::create_instance(); }
void TLobby::init_bosses() { load_dragon_ground_assets(); TObjBoss1Floor__sub_8002CB78(); TObjBoss1Crater__sub_8002C7B8(); TObjBoss1Rock__sub_8002E3D0(); TBoss8Dragon__sub_8002D5F8(); }

extern u8 *lbl_805D4B50;
extern s32 dragon_common_texture_list;

void render__14TObjBoss1FloorFv(void) {
    u32 temp_r3;
    u8 *temp_r31;

    if ((TObjPlayer::is_any_teammate_in_state() == 0) && ((TObjEneDD::check_v2_mode() != 0) || (TMainTask::get_render_pass() != 1))) {
        temp_r3 = model_render_flags;
        saved_model_render_flags = temp_r3;
        model_render_flags = temp_r3 | 0x400;
        TParticleCtrl::end_effect_render();
        push_matrix();
        model_render_flags = 1;
        set_draw_list_mask(3);
        TObjPlayer::draw_if_all_ready();
        TObjFish::set_global_param(dragon_common_texture_list);
        temp_r31 = (unsigned char *) (*(void **)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x58));
        render_projected_shadow_receiver((u8 *)(temp_r31 + 8), (saddr)(temp_r31 + 0x14));
        draw_ginja_model(*(void **)(temp_r31 + 4));
        TScene::apply_single_screen_state();
        restore_draw_list_mask();
        pop_matrix();
        model_render_flags = saved_model_render_flags;
    }
}

void run_task__14TObjBoss1FloorFv(Floor_8002C968 *self) {
    s32 i;
    Player_8002C968 *pl;
    if (TObjEneDD::check_v2_mode() != 0) {
        for (i = 0; i < 4; i++) {
            pl = (Player_8002C968 *)get_player_by_client_id(i);
            if (pl != NULL) {
                Vec pos = pl->pos;
                pos.y -= 4.0f;
                if (self->objs[i] == NULL) {
                    self->objs[i] = create_particle_emitter(&pos, 0x144);
                } else {
                    ((TParticleCtrl *)self->objs[i])->set_position(&pos);
                }
            } else if (self->objs[i] != NULL) {
                ((TObject *)self->objs[i])->queue_destruction();
                self->objs[i] = NULL;
            }
        }
    }
}

}
TObjBoss1Floor::~TObjBoss1Floor() {
    s32 i;
    for (i = 0; i * 0x10 != 0; i++) {
        if (((Obj_8002CA38 *)this)->slot[i] != 0) {
            ((TObject *)(((Obj_8002CA38 *)this)->slot[i]))->queue_destruction();
            ((Obj_8002CA38 *)this)->slot[i] = 0;
        }
    }
}
TObjBoss1Floor::TObjBoss1Floor(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = TObjBoss1Floor__name;
    ((Obj_8002CACC *)this)->f1c = 0.0f;
    ((Obj_8002CACC *)this)->f20 = 0.0f;
    ((Obj_8002CACC *)this)->f24 = 0.0f;
    for (i = 0; i < 4; i++) {
        ((Obj_8002CACC *)this)->f28[i] = 0;
    }
}

extern "C" {

s32 update_dragon_trail_uvs(void *);

void TObjBoss1Floor__sub_8002CB40(void) {  }


void TObjBoss1Floor::create_instance() {
    void* obj = new TObjBoss1Floor((TObject *)tl_02);
}

void TObjBoss1Floor__sub_8002CB78(void) {  }


void TObjBoss1MokoHill_Solo::render() {
    u8 *self = (u8 *)this;
    TObjFish::set_global_param(dragon_common_texture_list);
    update_dragon_trail_uvs((u8 *)&this->m_28);
    push_matrix();
    translate_matrix(0, this->m_28, (f32) (*(f32 *)((s8 *)self + 0x34)), this->m_30);
    if ((s32) this->m_48 != 0) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x800;
        set_chunk_material_override_pair(0xFF00, 0x100);
        draw_chunk_object((void *)(*(saddr *)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x38)));
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    } else {
        draw_chunk_object((void *)(*(saddr *)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x38)));
    }
    pop_matrix();
}

}
