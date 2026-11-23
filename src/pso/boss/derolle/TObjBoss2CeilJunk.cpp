#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/system/BmlResource.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/model_render_state.h"

struct Color_8003A1B4
{
  f32 a;
  s32 b;
  s32 c;
  s32 d;
};


const s32 boss2_ceil_junk_model_index_table[6] = { 0, 1, 2, 4, 3, 5 };
const f32 TObjBoss2CeilJunk__height_offset_table[6] = { 10.0f, 10.0f, 7.0f, 3.0f, 10.0f, 6.0f };
const f32 TObjBoss2CeilJunk__radius_table[6] = { 15.0f, 15.0f, 10.5f, 15.0f, 0.45000002f, 1.2f };
const char *TObjBoss2CeilJunk__name = "TObjBoss2CeilJunk";
const Color_8003A1B4 boss2_ceil_junk_render_color = { 0.0f, 0, 0, 0 };

extern "C" {
extern const f32 boss2_ceil_junk_water_level;
}

void TObjBoss2CeilJunk::render() {
  float new_var;
  if (state == 2)
  {
    Vec s;
    f32 t = TObjBoss2CeilJunk__radius_table[kind];
    new_var = (0.2f) * t;
    s.y = (1.0f);
    s.x = (s.z = new_var);
    TObjEneDD::draw_oriented_shadow(&prev_position, &ground_normal, 0, &s);
  }
  saved_model_render_flags = model_render_flags;
  if (alpha < 1.0f)
  {
    model_render_flags = saved_model_render_flags | 0x8820;
    {
      Color_8003A1B4 c = boss2_ceil_junk_render_color;
      c.a = -1.0f + alpha;
      set_constant_material((const NJS_ARGB *)(((f32 *)&c)));
    }
    set_chunk_material_override_pair(0xFF00, 0x800);
    set_chunk_blend(0x2500);
  }
  push_matrix();
  TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss2_common_texture_list));
  post_translate_matrix(&position.x);
  rotate_matrix_y(0, this->rotation_y);
  rotate_matrix_x(0, this->rotation_x);
  draw_ginja_object(boss2_common_resource->models[boss2_ceil_junk_model_index_table[kind]].model);
  pop_matrix();
  model_render_flags = saved_model_render_flags;
  set_chunk_material_override_pair(0xFF00, 0);
}

void TObjBoss2CeilJunk::run_task() {
    Vec p;
    Vec d;
    s32 id;
    s32 hit;
    s32 n;
    TObjPlayer *pl;
    s32 i;
    f32 top;
    f32 bottom;
    f32 rad;
    f32 h;
    switch (state) {
    case 0:
        velocity.y += -0.3f;
        if (velocity.y < -10.0f) {
            velocity.y = -10.0f;
        }
        position.y += velocity.y;
        if (position.y <= boss2_ceil_junk_water_level) {
            state = 1;
            VecCopy(&p, &position);
            switch (kind) {
            case 0:
            case 1:
            case 3:
                id = 0x170;
                break;
            case 2:
            case 4:
            case 5:
                id = 0x171;
                p.y += (5.0f);
                break;
            }
            TObjBoss2CeilJunk::create_particle(&p, id);
        }
        break;
    case 1:
        position.y -= (3.0f);
        if (position.y < (-5e+01f)) {
            queue_destruction();
        }
        break;
    case 2:
        velocity.y += -0.3f;
        if (velocity.y < -10.0f) {
            velocity.y = -10.0f;
        }
        position.y += velocity.y;
        if (position.y - home_position.y < (3e+01f)) {
            hit = 0;
            n = TLobby::get_game_mode();
            top = position.y - velocity.y;
            bottom = position.y - TObjBoss2CeilJunk__height_offset_table[kind];
            rad = (1e+01f) + TObjBoss2CeilJunk__radius_table[kind];
            for (i = 0; i < n; i++) {
                pl = TObjPlayer::get_player_data(i);
                if (((TObjEneDD *)pl)->is_valid_target() != 0) {
                    h = pl->base_stats.proportions + pl->position.y;
                    if (top > h && bottom < h) {
                        VecCopy(&d, &pl->position);
                        subtract_vector(&d, &position);
                        if (normalize_vector_xz(&d) < rad) {
                            hit = 1;
                            TBoss2DeRolLe::forward_switch_phase_stats((TObjChara *)pl);
                        }
                    }
                }
            }
            if (position.y <= home_position.y) {
                position.y = home_position.y;
                hit = 1;
                TObjBoss2CeilJunk::create_particle(&position, 0x160);
            }
            if (hit != 0) {
                velocity.y *= (-0.5f);
                velocity.x = (2.0f) * sin_table_lookup(rotation_y);
                velocity.z = (2.0f) * cos_table_lookup(rotation_y);
                state = 3;
                play_sound_effect(0x4003A801, &position, 0, 0);
                TCameraCtrl::set_shake_preset(0);
            }
        }
        break;
    case 3:
        velocity.y += -0.3f;
        if (velocity.y < -10.0f) {
            velocity.y = -10.0f;
        }
        rotation_x += 0x1323;
        vec3_add_to(&position, &velocity);
        fade_timer++;
        if (fade_timer >= 10) {
            alpha -= 0.04f;
            if (alpha <= 0.0f) {
                alpha = 0.0f;
                queue_destruction();
            }
        }
        break;
    }
}

TObjBoss2CeilJunk::~TObjBoss2CeilJunk() {

}

extern const f32 lbl_805D85A0 = 6.0f;
#pragma push
#pragma opt_dead_assignments off
TObjBoss2CeilJunk::TObjBoss2CeilJunk(TObject *parent, const Vec *position) : TObjBase(parent) {
    const volatile f32 *scale;
    f32 fraction;
    f32 random;
    m_name = TObjBoss2CeilJunk__name;
    VecCopy(&this->position, position);
    random = (f32) rand();
    fraction = 3.0517578e-05f * random;
    scale = &lbl_805D85A0;
    kind = (s32) (*scale * fraction);
    if (TObjBoss2Tunnel::spawn_effect(&this->position, &prev_position, &ground_normal) == 0) {
        state = 0;
    } else {
        state = 2;
        home_position.y = prev_position.y + TObjBoss2CeilJunk__height_offset_table[kind];
    }
    rotation_y = TObjPlayer::calc_random_scaled();
    rotation_x = (s32) (4096.0f * rand_signed_unit());
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    fade_timer = 0;
    alpha = 1.0f;
}
#pragma pop
