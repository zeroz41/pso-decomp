#include "types.h"
#include "pso/boss/TObjBoss1Floor.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TObjBoss1Crater_8002C6B4.h"
#include "pso/misc/TLobby_8002C838.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_8002C190.h"
#include "pso/unk/text_8002E174.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/depth_buffer.h"

#include "pso/misc/TLobby.h"
#include "pso/TMainTask.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TScene.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Obj_8002CACC { s32 f0; u8 pad4[0x14]; void *vt; f32 f1c; f32 f20; f32 f24; s32 f28[4]; };

typedef struct Vec_8002C968 {
    f32 x, y, z;
} Vec_8002C968;

typedef struct Player_8002C968 {
    u8 pad0[0x38];
    Vec_8002C968 pos;
} Player_8002C968;

typedef struct Floor_8002C968 {
    u8 pad0[0x28];
    void *objs[4];
} Floor_8002C968;

struct Obj_8002CA38 { u8 pad[0x28]; u32 slot[4]; };

extern "C" {
extern s32 TObjBoss1Floor__name;
extern const f32 lbl_805D8174;
void *get_player_by_client_id(s32 i);
extern const f32 lbl_805D8170;
void run_task__14TObjBoss1FloorFv(Floor_8002C968 *self);
int TBoss8Dragon__sub_8002D5F8(void);
void TObjBoss1Floor__sub_8002CB40(void);
void TObjBoss1Floor__sub_8002CB78(void);
void render_projected_shadow_receiver(u8 *arg0, s32 arg1);
s32 push_matrix();
int create_instance__14TObjBoss1FloorFv(void*);
s32 end_effect_render__13TParticleCtrlFv(int);

void TLobby::update_boss1_objects() { TBoss8Dragon::free_resources(); TObjBoss1Rock__sub_8002E3CC(); TObjBoss1Crater__sub_8002C7B4(); TObjBoss1Floor__sub_8002CB40(); TLobby::free_char_select(); }
int TLobby::forward_floor_2CB44() { return create_instance__14TObjBoss1FloorFv(this); }
void TLobby::init_bosses() { load_dragon_ground_assets(); TObjBoss1Floor__sub_8002CB78(); TObjBoss1Crater__sub_8002C7B8(); TObjBoss1Rock__sub_8002E3D0(); TBoss8Dragon__sub_8002D5F8(); }

extern u8 *lbl_805D4B50;
extern s32 dragon_common_texture_list;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void render__14TObjBoss1FloorFv(void) {
    s32 temp_r3;
    u8 *temp_r31;

    if ((TObjPlayer::is_any_teammate_in_state() == 0) && ((TObjEneDD::check_v2_mode() != 0) || (TMainTask::get_render_pass() != 1))) {
        temp_r3 = model_render_flags;
        saved_model_render_flags = temp_r3;
        model_render_flags = temp_r3 | 0x400;
        end_effect_render__13TParticleCtrlFv(temp_r3);
        push_matrix();
        model_render_flags = 1;
        set_depth_buffer_settings_id(3);
        TObjPlayer::draw_if_all_ready();
        TObjFish::set_global_param(dragon_common_texture_list);
        temp_r31 = (unsigned char *) (*(void **)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x58));
        render_projected_shadow_receiver((u8 *)(temp_r31 + 8), (s32)(temp_r31 + 0x14));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
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
                Vec_8002C968 pos = pl->pos;
                pos.y -= lbl_805D8170;
                if (self->objs[i] == NULL) {
                    self->objs[i] = create_particle_emitter(&pos, 0x144);
                } else {
                    ((TNowLoading *)(self->objs[i]))->copy_pos(&pos);
                }
            } else if (self->objs[i] != NULL) {
                queue_destruction__7TObjectFv(self->objs[i]);
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
            queue_destruction__7TObjectFv((void *)((Obj_8002CA38 *)this)->slot[i]);
            ((Obj_8002CA38 *)this)->slot[i] = 0;
        }
    }
}
TObjBoss1Floor::TObjBoss1Floor(TObject *parent) : TObject(parent) {
    s32 i;
    ((Obj_8002CACC *)this)->f0 = TObjBoss1Floor__name;
    ((Obj_8002CACC *)this)->f1c = lbl_805D8174;
    ((Obj_8002CACC *)this)->f20 = lbl_805D8174;
    ((Obj_8002CACC *)this)->f24 = lbl_805D8174;
    for (i = 0; i < 4; i++) {
        ((Obj_8002CACC *)this)->f28[i] = 0;
    }
}
