#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/PadRumble.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjFish.h"


#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"


#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TTecRaBarta.h"

extern "C" {

s32 get_nth_view_player_id__11TCameraCtrlFl(s32);
void request_follow_camera_offsets(void *, void *, s32);
void matrix_mult_vec(int, void *, void *);
f32 vector_length(void *);
void translate_matrix_vec3(int, void *);
void set_matrix_identity(int);
int rotate_matrix_y(void *, void *);

typedef struct Params_80052CDC {
    s32 owner;
    s16 a[3];
    s16 b;
    s16 c;
    u8 pad[0x14 - 0xE];
    Vec pos;
    u8 pad20[0x48 - 0x20];
} Params_80052CDC;

typedef struct Spot_80052CDC {
    Vec pos;
    u8 padc[0x18 - 0xC];
} Spot_80052CDC;

typedef struct Obj_80052CDC {
    u8 pad0[0x38C];
    saddr owner;
    u8 pad390[0x398 - 0x390];
    s32 timer;
    u8 pad39c[0x3A8 - 0x39C];
    s32 idx;
    u8 pad3ac[0x3C4 - 0x3AC];
    s32 max;
    s32 count;
    u8 pad3cc[0x3D0 - 0x3CC];
    s32 f3d0;
    u8 pad3d4[0x444 - 0x3D4];
    Spot_80052CDC spots[1];
} Obj_80052CDC;


struct Obj_8005294C { u8 pad[0x484]; Vec ents[1]; };

typedef struct { char pad[0x444]; struct { char b[0x18]; } arr[1]; } Foo;

typedef struct Obj_80053440 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x374 - 0x44];
    s32 state;
    ModelNodeTables node_tables;
    u8 pad38c[0x3F8 - 0x38C];
    void *a[4];
    void *b[4];
} Obj_80053440;

struct Obj_80053CEC { u8 pad[0x38C]; void *target; u8 pad390[0x10]; s32 f3a0; u8 pad3a4[4]; s32 f3a8; u8 pad3ac[4]; s32 f3b0; s32 f3b4; };

struct S_80053B48 { u8 pad0[0x3a0]; s32 f3a0; };

struct Obj_80053AD4 { u8 pad0[0x3B0]; s32 i3B0; s32 i3B4; f32 f3B8; f32 f3BC; f32 f3C0; };

typedef struct Spot_80053D4C {
    Vec pos;
    u8 padc[0x18 - 0xC];
} Spot_80053D4C;

typedef struct Part_80053D4C {
    Vec pos;
    u8 padc[0x1C - 0xC];
    Vec local;
    u8 pad28[0x2C - 0x28];
} Part_80053D4C;

typedef struct Obj_80053D4C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0x394 - 0x64];
    Part_80053D4C *parts;
    u8 pad398[0x438 - 0x398];
    Spot_80053D4C spots[3];
} Obj_80053D4C;

struct XZ_80053E40 { f32 x, z; };

struct Obj_80053E40 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    void *x60;
    u8 pad64[0x3D0 - 0x64];
    s32 count;
};

struct S_80054224 { u8 pad0[0x38]; Vec pos; u8 pad44[0x39c - 0x44]; f32 f39c; };

struct Boss_800542B0 {
    u8 pad0[0x374];
    s32 state;
    u8 pad378[0x3D0 - 0x378];
    s32 f3d0;
    u8 pad3d4[0x3F8 - 0x3D4];
    void *items[13];
};

// One state of the first-form controller.
struct Entry_800542B0 {
    const char *f0;
    s32 f4;
    void (TBoss4Type1::*enter)();
    void (TBoss4Type1::*update_idle)();
    void (TBoss4Type1::*update)();
};

struct O_80052EF8 {
    u8 pad0[0x38];
    u8 f38[0x398 - 0x38];
    s32 f398;
    f32 f39c;
    s32 f3a0;
    s32 f3a4;
    s32 f3a8;
    s32 f3ac;
    u8 pad3b0[0x3CC - 0x3B0];
    s32 f3cc;
};

typedef struct Obj_800530C0 {
    u8 pad0[0x398];
    s32 timer;
    f32 f39c;
} Obj_800530C0;

struct Stack_80053670 {
    f32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
};

void VecCopy__FP3VecPC3Vec(void *, void *);
u16 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
s32 TBoss4DarkFalz__sub_8004AF5C(s32, s16 *, s16 *);
void TBoss4DarkFalz__sub_8004B4F0(void *, void *);
void *create__16TObjDFBeamCursorFPvPv(void *parent, void *arg1);
s32 TBoss4Type3__sub_8005254C(u16);
void TBoss4Type2__sub_80053504(TBoss4Type1 *arg0);
void set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv(S_80054224 *o, void *src, Vec *in);
u8 * TBoss4Type2__sub_80054384(void *self, s32 i, s32 j);
void TBoss4Type2__sub_80054FC0(u8 *center, f32 min_dist);
void TBoss4Type2__sub_80055300(void);
void * create__9TBoss4UroFi(Params_80052CDC *);
void free_collision_body_parts(void *);
s32 project_actor_to_ground(void *, void *, int);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 hp_ratio);
void vec3_add_to(Vec *, Vec *);
void subtract_vector(Vec *, Vec *);
int post_translate_matrix(void*);
f32 xyz_distance(Vec *, Vec *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

extern u8 TBoss4DarkFalz__data_804FF1E8[];
Vec TBoss4Type2__tenchu_furu_array[64];
extern s32 registered_player_count;
struct Cam_800531C8 { u8 pad[0x178]; Vec pos; };
extern Cam_800531C8 *camera_ctrl_instance;

struct P2_80052E10 { s32 a, b; };
struct S_80052E10 {
    u8 pad0[0x374];
    s32 f374;
    u8 pad378[0x398 - 0x378];
    s32 f398;
    u8 pad39c[0x3a8 - 0x39c];
    s32 idx;
    u8 pad3ac[0x3c8 - 0x3ac];
    s32 f3c8;
    u8 pad3cc[4];
    s32 f3d0;
};
const char *TBoss4Type1__name = "TBoss4Type1";
void *lbl_80485AE0[10] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0x40000000, (void *)0x41c80000, (void *)0x3f000000, (void *)0x3f000000,
    (void *)0x3f000000, (void *)0x3f000000,
};
s32 lbl_80485B08[2] = { 0xFB, 0xFC };
Entry_800542B0 lbl_80485C48[11] = {
    { "APPEAR", 0, &TBoss4Type1::init_appear_state, &TBoss4Type1::check_state_if_idle, &TBoss4Type1::sub_800530C0 },
    { "WAITNEXT", 0, 0, &TBoss4Type1::update_flag800_state, 0 },
    { "MOVESTNDPOS", 0, &TBoss4Type1::init_movestndpos_state, &TBoss4Type1::update_state_transition, &TBoss4Type1::sub_80052EF8 },
    { "DEAD", 1, &TBoss4Type1::init_dead_state, &TBoss4Type1::update_dead_idle, &TBoss4Type1::tick_state_398_timer },
    { "WAITKILL", -1, 0, 0, 0 },
    { "HAKILOOP", 2, &TBoss4Type1::start_motion_for_index, 0, &TBoss4Type1::update_spawn_uro },
    { "PAKULOOP", 2, &TBoss4Type1::start_motion_for_index, 0, &TBoss4Type1::tick_countdown_set_state7 },
    { "HAKIEND", 4, &TBoss4Type1::set_motion_for_state, &TBoss4Type1::update_state, &TBoss4Type1::update_attack_countdown },
    { "BEAM_L", 11, &TBoss4Type1::init_child_and_set_timer, &TBoss4Type1::update_scale_state, &TBoss4Type1::update_tech_charge },
    { "BEAM_R", 12, &TBoss4Type1::init_child_and_set_timer, &TBoss4Type1::update_scale_state, &TBoss4Type1::update_tech_charge },
    { "TENCHU", 13, &TBoss4Type1::init_timer, &TBoss4Type1::sub_800528B8, &TBoss4Type1::sub_800525AC },
};
CollisionBody lbl_80485E2C[3] = {
    { { 135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 25.0f, 135.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { -135.0f, 25.0f, 0.0f }, 30.0f, 0.0f, 0, 0x801B, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
void *lbl_80485EB0[6] = {
    (void *)0x9, (void *)0x7, (void *)0x5, (void *)0x4,
    (void *)0x6, (void *)0x3,
};
void *boss4_type1_motion_states[120] = {
    (void *)0x0, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x4c,
    (void *)0x1, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x15, (void *)0x15, (void *)0x15, (void *)0x14,
    (void *)0x2, (void *)0x3, (void *)0x50, (void *)0x4e,
    (void *)0x2a, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x0, (void *)0x4, (void *)0x50, (void *)0x4e,
    (void *)0x28, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x2c, (void *)0x4d, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x6, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x2a, (void *)0x4d, (void *)0x14,
    (void *)0x0, (void *)0x7, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x28, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x2c, (void *)0x4d, (void *)0x14,
    (void *)0x2, (void *)0x9, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x2a, (void *)0x14,
    (void *)0x0, (void *)0xa, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x28, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x2c, (void *)0x14,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x0,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x4,
    (void *)0x2, (void *)0xe, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x43,
    (void *)0x2, (void *)0x0, (void *)0x50, (void *)0x4e,
    (void *)0x4d, (void *)0x4d, (void *)0x4d, (void *)0x3d,
};
void *player_collider_radius_table[6] = {
    (void *)0x42960000, (void *)0x42700000, (void *)0x42700000, (void *)0x42700000,
    (void *)0x42200000, (void *)0x41f00000,
};
void *boss4_type1_xz_offset_table[12] = {
    (void *)0x0, (void *)0x0, (void *)0x42480000, (void *)0x0,
    (void *)0x0, (void *)0x42480000, (void *)0xc2480000, (void *)0x0,
    (void *)0x0, (void *)0xc2a00000, (void *)0x0, (void *)0x0,
};
ModelNodePositionEntry lbl_804860F0[3] = {
    {0x1A, {-15.0f, 0.0f, 0.0f}},
    {0x1A, {0.0f, 7.5f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
ModelNodePositionEntry lbl_80486120[3] = {
    {0xE, {0.0f, 0.0f, 0.0f}},
    {0x54, {0.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
Vec lbl_80486150 = { 0.0f, 0.0f, -120.0f };
void *lbl_8048615C[14] = {
    (void *)0x0, (void *)0xc000, (void *)0x8000, (void *)0x4000,
    (void *)0x3e800000, (void *)0x3e800000, (void *)0x3f000000, (void *)0x8,
    (void *)0x9, (void *)0xa, (void *)0x3f000000, (void *)0x3f000000,
    (void *)0x8, (void *)0x9,
};
void *boss4_type1_vec_table[12] = {
    (void *)0x42480000, (void *)0x41200000, (void *)0x0, (void *)0xc2480000,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x42480000, (void *)0x0, (void *)0x41200000, (void *)0xc2480000,
};
void *boss4_type2_motion_vec_table[12] = {
    (void *)0x0, (void *)0x0, (void *)0xc32f0000, (void *)0x432f0000,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x432f0000, (void *)0xc32f0000, (void *)0x0, (void *)0x0,
};
void *lbl_804861F4[3] = {
    (void *)0x2, (void *)0x5, (void *)0x8,
};
void *lbl_80486200[6] = {
    (void *)0x43020000, (void *)0x0, (void *)0x0, (void *)0x43020000,
    (void *)0xc3020000, (void *)0x0,
};
void *boss4_type2_state_motion_index_table[3] = {
    (void *)0x4, (void *)0x7, (void *)0xa,
};
#define lbl_80485AE0 ((u8 *)lbl_80485AE0)
#define lbl_80485EB0 ((s32 *)lbl_80485EB0)
#define player_collider_radius_table ((f32 *)player_collider_radius_table)
#define boss4_type1_xz_offset_table ((XZ_80053E40 *)boss4_type1_xz_offset_table)
#define lbl_8048615C ((u8 * *)lbl_8048615C)
#define boss4_type1_vec_table ((Vec *)boss4_type1_vec_table)
#define boss4_type2_motion_vec_table ((Vec *)boss4_type2_motion_vec_table)
}


extern "C" s32 init_collision_body_parts(void *, void *, int);
extern const s32 boss4_type1_emitter_id_table[8] = { 0x144, 0x144, 0x144, 0x144, 0x145, 0x145, 0x145, 0x145 };
extern const ModelNodeSpec boss4_type1_model_node_table[7] = {
    { 9, 1, 0 }, { 7, 1, 0 }, { 5, 2, 0 }, { 4, 2, 0 }, { 6, 2, 0 }, { 3, 5, 0 }, { 3, 0x5E, 0 },
};

extern "C" {
void TBoss4Type2__sub_80055300(void) { TBoss4Type2__sub_80054FC0(NULL, 0.0f); }

s32 is_split_screen(void);
extern s32 local_client_id;

extern "C" void TBoss4Type2__sub_80054FC0(u8 *center, f32 min_dist) {
  u8 *out;
  s32 total;
  s32 cnt;
  s32 i;
  s32 k;
  s32 ang;
  s32 j;
  u8 *arr[4];
  s32 tries;
  f32 f24;
  f32 zero;
  Vec w;
  Vec v;
  out = reinterpret_cast<u8 *>(TBoss4Type2__tenchu_furu_array);
  for (total = 0; total < 0x40; total++, out += 0xc)
  {
    VecCopy__FP3VecPC3Vec((Vec *) out, lbl_80485AE0);
  }

  total = 0;
  out = reinterpret_cast<u8 *>(TBoss4Type2__tenchu_furu_array);
  cnt = 0;
  if (is_split_screen())
  {
    cnt = TLobby::get_game_mode();
    if (cnt > 4)
    {
      cnt = 4;
    }
    for (i = 0; i < cnt; i++)
    {
      arr[i] = (u8 *) TObjPlayer::get_player_data(i);
      if (arr[i] == 0)
      {
        break;
      }
    }

  }
  else
  {
    arr[0] = (u8 *) get_player_by_client_id(local_client_id);
    if (arr[0] != 0)
    {
      cnt = 1;
    }
  }
  f24 = 40.0f;
  for (k = 0; k < cnt; k++)
  {
    total++;
    ((Vec *) out)->x = *((f32 *) (arr[k] + 0x38));
    ((Vec *) out)->z = *((f32 *) (arr[k] + 0x40));
    out += 0xc;
    for (ang = 0, j = 0; j < 8; j++, ang += 0x2000)
    {
      ((Vec *) out)->x = (*((f32 *) (arr[k] + 0x38))) + (f24 * sin_table_lookup(ang));
      (*((Vec *) out)).z = (*((f32 *) (arr[k] + 0x40))) + (f24 * cos_table_lookup(ang));
      out += 0xc;
      total++;
    }

  }

  tries = 0;
  while ((tries < 0x100) && (total < 0x40))
  {
    w.x = 460.0f * ((3.0517578e-05f * ((f32) rand())) - 0.5f);
    w.z = 460.0f * ((3.0517578e-05f * ((f32) rand())) - 0.5f);
    w.y = 0.0f;
    if (((w.x * w.x) + (w.z * w.z)) >= 52900.0f)
    {
      goto next;
    }
    if (center != 0)
    {
      VecCopy__FP3VecPC3Vec(&v, center);
      subtract_vector((Vec *) (&v), (Vec *) (&w));
      v.y = 0.0f;
      if (vector_length(&v) <= min_dist)
      {
        goto next;
      }
    }
    u8 *p;
    s32 found;
    s32 m;
    found = 0;
    p = reinterpret_cast<u8 *>(TBoss4Type2__tenchu_furu_array);
    for (m = 0; m < total; m++)
    {
      if (xyz_distance(&w, (Vec *) p) <= 12.5f)
      {
        found = 1;
        break;
      }
      p += 0xc;
    }

    if (found == 0)
    {
      ((Vec *) out)->x = w.x;
      ((Vec *) out)->z = w.z;
      out += 0xc;
      total++;
    }
    next:
    tries++;
  }
}

void spawn_tenchu_furu(TObject *parent) {
    Vec *spot = TBoss4Type2__tenchu_furu_array;
    s32 i = 0;
    do {
        TObjDFTenchuFuru::create(parent, spot);
        i += 1;
        spot++;
    } while (i < 64);
}

void apply_tenchu_hits(TObject *source) {
    Vec *spot;
    s32 i;
    s32 n;
    TObjPlayer *player;
    s32 hit;
    s32 count;
    Vec *target;
    s32 j;
    f32 power;
    Vec pos;

    power = (f32)((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->power;
    spot = TBoss4Type2__tenchu_furu_array;
    for (i = 0; i < 0x40; i++) {
        TParticleCtrl *effect = spawn_particle_effect(spot, lbl_80485B08[i & 1]);
        if (effect != NULL) {
            effect->set_flags(0x40);
        }
        spot++;
    }
    count = TLobby::get_game_mode();
    for (n = 0; n < count; n++) {
        player = TObjPlayer::get_player_data(n);
        hit = 0;
        if (player == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(get_entity_id(player)) == 0) {
            continue;
        }
        target = TBoss4Type2__tenchu_furu_array;
        VecCopy__FP3VecPC3Vec(&pos, player->get_position_ptr());
        pos.y = 0.0f;
        for (j = 0; j < 0x40; j++) {
            if (xyz_distance(&pos, target) < 25.0f) {
                hit = 1;
                break;
            }
            target++;
        }
        if (hit != 0) {
            DirectAttackPayload h;
            h.kind = 0;
            h.power = power;
            player->receive_direct_attack(source, h, 0, -1, -1);
        }
    }
    play_sound_effect(0x4003A818, 0, 0, 0);
    start_pad_rumble_all(0xC0, 0xF);
}

s32 TBoss4Type1::create(saddr arg0) {
    return (saddr)new TBoss4Type1(new TObjControl(tl_04), (saddr *)arg0);
}

}

TBoss4Type1::TBoss4Type1(TObject *parent, saddr *params) : TObjEnemy(parent) {
    s32 i;
    s32 j;

    m_name = TBoss4Type1__name;
    add_flags_2e4(8);
    owner = (TBoss4DarkFalz *)params[0];
    apply_set_data(params + 1);
    clear_lobby_object_state();
    archive = reinterpret_cast<BmlResource *>(TBoss4Uro::get_instance_count());
    texlist = 0;
    model = 0;
    VecCopy(&position, &lbl_80486150);
    rotation_y = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    unk_394 = init_collision_body_parts(this, lbl_80485E2C, 3);
    VecCopy(&body_center, &position);
    x_speed = y_speed = m_310 = 0.0f;
    target = 0;
    bind_enemy_combat_stats((u8 *)TLobby::register_boss(0x36), (u8 *)TLobby::dispatch_shared_handler_b(0x36), (u8 *)TLobby::register_object(0x36));
    referenceHp = hp;
    ((TBoss3Volopt *)this)->reset_photon_effect();
    set_param(0x2F);
    unk_3ec = 0.4f;
    for (i = 0; i < 3; i++) {
        fx[i] = ModelNodePositionCapture::create(lbl_804860F0, unk_438[i]);
    }
    unk_480 = ModelNodePositionCapture::create(lbl_80486120, unk_484);
    for (j = 0; j < 8; j++) {
        parts[j] = create_particle_emitter(&position, boss4_type1_emitter_id_table[j]);
    }
    for (; j < 13; j++) {
        parts[j] = 0;
    }
    model_nodes.init(boss4_type1_model_node_table, 7);
    unk_3a4 = 0;
    unk_3a0 = 0;
    unk_3ac = 1;
    unk_3a8 = 1;
    move_frames = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36))->move_seconds;
    if (move_frames < 1 || move_frames > 60) {
        move_frames = 25;
    }
    move_frames *= 30.0f;
    unk_3c4 = ((TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x39))->rafoie_level;
    if (unk_3c4 < 1) {
        unk_3c4 = 1;
    } else if (unk_3c4 > 6) {
        unk_3c4 = 6;
    }
    unk_3c8 = 0;
    unk_3d0 = 5;
    unk_3d4 = 0;
    unk_3d8 = hp / 2;
    unk_3dc = 0.0f;
    hp_ratio = 1.0f;
    set_state(0);
}


TBoss4Type1::~TBoss4Type1() {
    s32 i;
    s32 j;
    model_nodes.destroy();
    for (i = 0; i < 13; i++) {
        if (parts[i] != 0) {
            TParticleCtrl::release(parts[i]);
            parts[i] = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        ModelNodePositionCapture::destroy(fx[j]);
        fx[j] = 0;
    }
    ModelNodePositionCapture::destroy((ModelNodePositionCapture *)unk_480);
    unk_480 = 0;
    free_collision_body_parts(this);
    unk_394 = 0;
}

void TBoss4Type1::run_hit_reaction() {
    actorFlags &= ~0x200;
    unk_3d4 = 1;
    unk_3dc = 1.0f;
    play_sound_effect(0x4003A822, &position, 0, 1);
}

void TBoss4Type1::run_death_reaction() {
    if (state != 3 && state != 4) {
        set_state(3);
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss4Type1::run_task() {
    void (TBoss4Type1::*act)();
    if (owner->is_field378_zero() != 0) {
        act = lbl_80485C48[state].update_idle;
        if (act) {
            (this->*act)();
        }
    }
    act = lbl_80485C48[state].update;
    if (act) {
        (this->*act)();
    }
    update_boss4_phase_timer();
    snapshot_position();
    sub_80053D4C();
    ((TObjPlayer *)this)->update_collisions();
    submit_cursor_candidate(this, -1);
    sub_80053670();
    sub_80053440();
    unk_3dc += -0.06666667f;
    if (unk_3dc < 0.0f) {
        unk_3dc = 0.0f;
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}

#pragma pop
void TBoss4Type1::render() {
    push_players_out_of_colliders();
    render_effects();
    update_follow_camera_offsets();
}

void TBoss4Type1::snapshot_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy__FP3VecPC3Vec((u8 *)&this->body_center, arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) += 50.0f;
}

void TBoss4Type1::render_effects() { TObjPlayer::toggle_particle_effect(); push_matrix(); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x60)); this->draw_parts(); pop_matrix(); TParticleCtrl::end_effect_render(); }

#pragma push
#pragma opt_common_subs off
void TBoss4Type1::update_boss4_phase_timer() {
    f32 temp_f1;
    f32 temp_f1_2;
    *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 0;
    *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) + *(f32 *)((s8 *)((u8 *)this) + 0x3EC));
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x3F0)) {
    case 0:
        temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x3E8);
        if (temp_f1 >= 30.0f) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) (temp_f1 - 30.0f);
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) >= 29.0f) {
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) 29.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    case 2:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x3E8) >= 29.0f) {
            *(s32 *)((s8 *)((u8 *)this) + 0x3E4) = (s32) *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states + (*(s32 *)((s8 *)((u8 *)this) + 0x3E4) << 5)) + 4);
            *(s32 *)((s8 *)((u8 *)this) + 0x3F0) = (s32) *(s32 *)((s8 *)&boss4_type1_motion_states + (*(s32 *)((s8 *)((u8 *)this) + 0x3E4) << 5));
            *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) 0.0f;
            *(s32 *)((s8 *)((u8 *)this) + 0x3F4) = 1;
        }
        break;
    }
    temp_f1_2 = *(f32 *)((s8 *)((u8 *)this) + 0x3E8);
    if ((temp_f1_2 < 0.0f) || (temp_f1_2 >= 30.0f)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x3E8) = (f32) 0.0f;
    }
}

#pragma pop
void TBoss4Type1::set_motion_index(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    if (arg1 != -1) {
        *(s32 *)((s8 *)arg0 + 0x3E4) = arg1;
        *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) 0.0f;
        *(s32 *)((s8 *)arg0 + 0x3F0) = (s32) *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states + (arg1 << 5)) + 0);
    }
}

#pragma push
#pragma opt_propagation off
void TBoss4Type1::draw_parts() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    s32 off;
    saddr a;
    set_motion_packed_rotation();
    for (i = 0; i < 6; i++) {
        TObjFish::set_global_param((saddr)(get_bml_texlist(archive, lbl_80485EB0[i])));
        switch (i) {
        case 2:
        case 3:
        case 4:
            TBoss6PlotFalz__sub_802AC008(*(f32 *)((s8 *)arg0 + 0x3DC), this->hp_ratio);
            off = (i - 2) * 4 + 0x42C;
            ((ModelNodePositionCapture *)(*(saddr *)(arg0 + off)))->install();
            a = (saddr)get_bml_model(archive, lbl_80485EB0[i]);
            draw_model_motion((void *)a, (void *)(get_bml_motion(archive, *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            ((ModelNodePositionCapture *)(*(saddr *)(arg0 + off)))->clear();
            TBoss6PlotFalz::update_camera_target();
            break;
        case 5:
            ((ModelNodePositionCapture *)(*(saddr *)((s8 *)arg0 + 0x480)))->install();
            draw_model_motion((void *)(get_bml_model(archive, lbl_80485EB0[i])), (void *)(get_bml_motion(archive, *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            ((ModelNodePositionCapture *)(*(saddr *)((s8 *)arg0 + 0x480)))->clear();
            break;
        default:
            draw_model_motion((void *)(get_bml_model(archive, lbl_80485EB0[i])), (void *)(get_bml_motion(archive, *(s32 *)((s8 *)((u8 *)&boss4_type1_motion_states + (*(s32 *)((s8 *)arg0 + 0x3E4) << 5) + i * 4) + 8))), *(f32 *)((s8 *)arg0 + 0x3E8));
            break;
        }
    }
    clear_motion_packed_rotation();
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
}

#pragma pop
u8 *TBoss4Type2__sub_80054384(void *self, s32 i, s32 j) {
    return lbl_8048615C[i] + (j - 1) * 0x4000;
}

void TBoss4Type1::set_state(s32 arg1) {
    s32 i;
    void **p;

    ((Boss_800542B0 *)this)->state = arg1;
    for (i = 8; i < 13; i++) {
        p = &((Boss_800542B0 *)this)->items[i];
        if (*p != NULL) {
            TParticleCtrl::release(*p);
            *p = NULL;
        }
    }
    ((Boss_800542B0 *)this)->f3d0 = 5;
    set_motion_index(lbl_80485C48[((Boss_800542B0 *)this)->state].f4);
    void (TBoss4Type1::*f)() = lbl_80485C48[((Boss_800542B0 *)this)->state].enter;
    if (f) {
        (this->*f)();
    }
}

void set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv(S_80054224 *o, void *src, Vec *in) {
    Vec v = *in;
    ((void (*)(void *))subtract_vector)(&v);
    v.x *= o->f39c;
    v.y *= o->f39c;
    v.z *= o->f39c;
    VecCopy__FP3VecPC3Vec(&o->pos, src);
    ((void (*)(void *, void *))vec3_add_to)(&o->pos, &v);
}

void TBoss4Type1::calc_scaled_field(s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)this + 0x60) = (s32) (arg1 + (s32) (*(f32 *)((s8 *)this + 0x39C) * (f32) angle_diff_s16(arg1, arg2)));
}

f32 TBoss4Type1::calc_wave_offset(f32 farg0) {
    return 0.5f * (1.0f - cos_table_lookup((s32) (32768.0f * farg0)));
}

void TBoss4Type1::push_players_out_of_colliders() {
    Obj_80053E40 *o = (Obj_80053E40 *)this;
    XZ_80053E40 pts[7];
    Vec in;
    Vec out;
    s32 i;
    s32 p;
    u8 *pl;
    s32 j;

    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, &o->pos);
    rotate_matrix_y(0, o->x60);
    for (i = 0; i < o->count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = 0.0f;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    for (p = 0; p < registered_player_count; p++) {
        pl = (u8 *)TObjPlayer::get_player_data(p);
        if (pl != NULL && ((TObjPlayer *)pl)->get_area() == 0xE) {
            Vec pos = *(Vec *)((TObjPlayer *)pl)->get_position_ptr();
            Vec d;
            Vec q;
            for (j = 0; j < o->count; j++) {
                f32 r = player_collider_radius_table[j];
                f32 dist;
                VecCopy__FP3VecPC3Vec(&d, &pos);
                d.x = d.x - pts[j].x;
                d.y = 0.0f;
                d.z = d.z - pts[j].z;
                dist = vector_length(&d);
                if (!(dist > r)) {
                    if (0.0f == dist) {
                        VecCopy__FP3VecPC3Vec(&d, &pos);
                        d.y = 0.0f;
                        if (0.0f == vector_length(&d)) {
                            d.y = 0.0f;
                            d.x = 1.0f;
                            d.z = 0.0f;
                        }
                    }
                    normalize_vector(&d);
                    {
                        f32 s = 0.75f + r;
                        d.x *= s;
                        d.z *= s;
                    }
                    pos.x = d.x + pts[j].x;
                    pos.z = d.z + pts[j].z;
                    VecCopy__FP3VecPC3Vec(&q, &pos);
                    for (;;) {
                        f32 m;
                        q.y += 5.0f;
                        if (project_actor_to_ground(o, &q, 0) != 0) {
                            break;
                        }
                        q.y = 0.0f;
                        m = vector_length(&q) - 0.25f;
                        normalize_vector(&q);
                        q.x *= m;
                        q.z *= m;
                    }
                    VecCopy__FP3VecPC3Vec(&pos, &q);
                }
            }
            if (((f32 (*)(void *, void *))xyz_distance)(((TObjPlayer *)pl)->get_position_ptr(), &pos) > 0.0f) {
                ((TObjBase *)pl)->set_position_from(&pos);
                ((TObjBase *)pl)->save_previous_position();
                ((TObjCollidable *)pl)->set_indexed_flags(0, 0x900000);
                *(u32 *)(pl + 0x30) &= ~0x20;
            }
        }
    }
}

void TBoss4Type1::sub_80053D4C() {
    Obj_80053D4C *arg0 = (Obj_80053D4C *)this;
    Part_80053D4C *q;
    s32 i;
    f32 s;
    f32 c;
    q = arg0->parts;
    for (i = 0; i < 3; i++, q++) {
        Vec v = arg0->spots[i].pos;
        VecCopy__FP3VecPC3Vec(&q->local, &v);
        subtract_vector(&v, &arg0->pos);
        s = sin_table_lookup(-this->rotation_y);
        c = cos_table_lookup(-this->rotation_y);
        Vec t = v;
        v.x = c * t.x + s * t.z;
        v.z = -s * t.x + c * t.z;
        VecCopy__FP3VecPC3Vec(q, &v);
    }
}

void TBoss4Type1::send_state_to_target(s32 arg1) {
    Obj_80053CEC *self = (Obj_80053CEC *)this;
    if (self->target != 0) {
        ((TBoss4DarkFalz *)(self->target))->send_code_25_4((arg1 & 0xF) | ((self->f3a0 & 3) << 4) | ((self->f3a0 & 3) << 6) | ((self->f3a8 & 3) << 8) | ((self->f3a8 & 3) << 10) | ((self->f3b0 & 0xF) << 12) | ((self->f3b4 & 0xF) << 16));
    }
}

void TBoss4Type1::send_darkfalz_code(s32 arg1, s32 arg2, s32 arg3) {
    u8 *arg0 = (u8 *)this;
    u8 *boss4_dark_falz;
    boss4_dark_falz = (u8 *)(*(u8 **)((s8 *)arg0 + 0x38C));
    if (boss4_dark_falz != NULL) {
        ((TBoss4DarkFalz *)boss4_dark_falz)->send_code_25_4(((((((((((((*(s32 *)((s8 *)arg0 + 0x3A0) * 0x10) & 0x30 & ~0xF) | (arg1 & 0xF)) & ~0xC0) | ((arg2 << 6) & 0xC0)) & ~0x300) | ((*(s32 *)((s8 *)arg0 + 0x3A8) << 8) & 0x300)) & ~0xC00) | ((arg3 << 0xA) & 0xC00)) & ~0xF000) | ((*(s32 *)((s8 *)arg0 + 0x3B0) << 0xC) & 0xF000)) & ~0xF0000) | ((*(s32 *)((s8 *)arg0 + 0x3B4) << 0x10) & 0xF0000));
    }
}

void TBoss4Type1::apply_packed_state(u32 arg1) {
    s32 n;
    *(s32 *)((s8 *)this + 0x3A4) = (s32) ((arg1 >> 4U) & 3);
    *(s32 *)((s8 *)this + 0x3A0) = (s32) ((arg1 >> 6U) & 3);
    *(s32 *)((s8 *)this + 0x3AC) = (s32) ((arg1 >> 8U) & 3);
    *(s32 *)((s8 *)this + 0x3A8) = (s32) ((arg1 >> 0xAU) & 3);
    if (*(s32 *)((s8 *)this + 0x3AC) > 2 || *(s32 *)((s8 *)this + 0x3A8) > 2) {
        return;
    }
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((arg1 >> 0xCU) & 0xF);
    *(s32 *)((s8 *)this + 0x3B4) = (s32) ((arg1 >> 0x10U) & 0xF);
    calc_target_position();
    n = arg1 & 0xF;
    if (n < 0 || n >= 0xB) {
        return;
    }
    set_state(n);
}

void TBoss4Type1::calc_scale_slot_indices(s32 *a, s32 *b) {
    f32 s;
    s32 v;
    v = ((S_80053B48 *)this)->f3a0 + (s32)(2.97f * ((TObjChara *)((S_80053B48 *)this))->random_ratio());
    v += 1;
    if (v >= 4) {
        v -= 4;
    }
    *a = v;
    s = ((TObjChara *)this)->random_ratio();
    if (s <= 0.1f) {
        *b = 0;
    } else if (s <= 0.90000004f) {
        *b = 1;
    } else {
        *b = 2;
    }
}

void TBoss4Type1::calc_target_position() {
    Obj_80053AD4 *arg0 = (Obj_80053AD4 *)this;
    arg0->f3B8 = 29.375f * (0.5f + (f32)arg0->i3B0) - 235.0f;
    arg0->f3BC = 0.0f;
    arg0->f3C0 = 29.375f * (0.5f + (f32)arg0->i3B4) - 235.0f;
}

void TBoss4Type1::set_map_position(void *arg1) {
    *(s32 *)((s8 *)this + 0x3B0) = (s32) ((235.0f + *(f32 *)((s8 *)arg1 + 0)) / 29.375f);
    *(s32 *)((s8 *)this + 0x3B4) = (s32) ((235.0f + *(f32 *)((s8 *)arg1 + 8)) / 29.375f);
}

#pragma push
#pragma opt_propagation off
void TBoss4Type1::pick_target_position(Vec *out) {
    s32 a1;
    TObjPlayer *found;
    s32 i;
    TObjPlayer *p;
    f32 best;
    f32 d;
    f32 s;
    s32 ang;
    s32 b;
    Vec res;
    best = 0.0f;
    found = NULL;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p == NULL) {
            continue;
        }
        if (TBoss4Type3__sub_8005254C(get_entity_id(p)) == 0) {
            continue;
        }
        {
            Vec v = p->position;
            v.y = 0.0f;
            d = xyz_distance(&v, &position);
            if (d <= 460.0f && d > best) {
                best = d;
                found = p;
                ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)(&res, &v);
            }
        }
    }
    if (found != NULL) {
        ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)(out, &res);
        return;
    }
    s = 200.625f * random_ratio();
    a1 = (s32)(10430.38043493439 * atan2_float(-position.x, -position.z));
    b = (s32)(49152.0f * random_ratio());
    ang = b + a1;
    ang -= 0x6000;
    out->x = s * sin_table_lookup(ang);
    out->y = 0.0f;
    out->z = s * cos_table_lookup(ang);
}

#pragma pop
void TBoss4Type1::sub_80053670() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80053670, sp8) == 0x0);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80053670, sp10) == 0x8);
    Stack_80053670 stack;

    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f29;
    f32 temp_f30;
    s32 temp_r30;
    s32 var_r29;
    s32 var_r28;
    u8 *arg0 = (u8 *)this;

    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&this->unk_438[0][0], -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&this->unk_438[1][0], -0x5DB4, 1, 1, 5.0f);
    add_radar_scaled_marker(&this->unk_438[2][0], -0x5DB4, 1, 1, 5.0f);
    temp_f29 = sin_table_lookup(this->rotation_y);
    temp_f30 = cos_table_lookup(this->rotation_y);
    temp_f27 = 37.5f;
    var_r29 = 0;
    var_r28 = 0x25;
    do {
        ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)((Vec *)&stack.sp8, (Vec *)(arg0 + 0x38));
        stack.sp8 += (f32)(-var_r28) * temp_f30;
        stack.sp10 += (f32)var_r28 * temp_f29;
        add_radar_scaled_marker((Vec *)&stack.sp8, -0x5DB4, 1, 1, 5.0f);
        ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)((Vec *)&stack.sp8, (Vec *)(arg0 + 0x38));
        stack.sp8 += (f32)var_r28 * temp_f29;
        stack.sp10 += (f32)var_r28 * temp_f30;
        add_radar_scaled_marker((Vec *)&stack.sp8, -0x5DB4, 1, 1, 5.0f);
        ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)((Vec *)&stack.sp8, (Vec *)(arg0 + 0x38));
        stack.sp8 += (f32)var_r28 * temp_f30;
        stack.sp10 += (f32)(-var_r28) * temp_f29;
        add_radar_scaled_marker((Vec *)&stack.sp8, -0x5DB4, 1, 1, 5.0f);
        if (var_r29 < 2) {
            ((s32 (*)(Vec *, Vec *))VecCopy__FP3VecPC3Vec)((Vec *)&stack.sp8, (Vec *)(arg0 + 0x38));
            stack.sp8 += (f32)(-var_r28) * temp_f29;
            stack.sp10 += (f32)(-var_r28) * temp_f30;
            add_radar_scaled_marker((Vec *)&stack.sp8, -0x5DB4, 1, 1, 5.0f);
        }
        var_r29 += 1;
        var_r28 = (s32) ((f32) var_r28 + temp_f27);
    } while (var_r29 < 3);
}

void TBoss4Type1::choose_next_attack() {
    Vec target;
    s32 r;
    u8 *tbl = lbl_80485AE0;
    if (unk_3a8 == 1) {
        if (hp <= unk_3d8) {
            r = TBoss4Type2::pick_weighted_random(3, (f32 *)(tbl + 0x68C), (s32 *)(tbl + 0x698));
        } else {
            r = TBoss4Type2::pick_weighted_random(2, (f32 *)(tbl + 0x6A4), (s32 *)(tbl + 0x6AC));
        }
        switch (r) {
        case 8:
        case 9:
            pick_target_position(&target);
            set_map_position(&target);
            send_state_to_target(r);
            break;
        default:
            send_state_to_target(0xA);
            break;
        }
    } else {
        check_state_transition();
    }
}

void TBoss4Type1::check_state_transition() {
    if (((TBoss4DarkFalz *)*(saddr *)((s8 *)this + 0x38C))->sub_8004D990() <= (s32) (0xC - *(s32 *)((s8 *)this + 0x3C4))) {
        send_state_to_target(5);
        return;
    }
    send_state_to_target(6);
}

void TBoss4Type2__sub_80053504(TBoss4Type1 *boss4_type2) {
    s32 spC;
    s32 sp8;
    boss4_type2->calc_scale_slot_indices(&spC, &sp8);
    boss4_type2->send_darkfalz_code(2, spC, sp8);
}

void TBoss4Type1::sub_80053440() {
    Vec v;
    s32 i;
    Obj_80053440 *arg0 = (Obj_80053440 *)this;
    if (this->state == 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        VecCopy__FP3VecPC3Vec(&v, &arg0->pos);
        vec3_add_to(&v, &boss4_type1_vec_table[i]);
        if (arg0->a[i] != NULL) {
            ((TParticleCtrl *)arg0->a[i])->set_position(&v);
        }
        if (arg0->b[i] != NULL) {
            ((TParticleCtrl *)arg0->b[i])->set_position(&v);
        }
    }
    arg0->node_tables.scroll_strips();
    play_persistent_sound(0x4003BC0E, (saddr)arg0, (uaddr)&arg0->pos, 0x40, 2);
}

void TBoss4Type1::update_follow_camera_offsets() {
    Obj_80053E40 *o = (Obj_80053E40 *)this;
    XZ_80053E40 pts[7];
    Vec in;
    Vec out;
    f32 best;
    s32 i;
    s32 j;
    f32 t;
    s32 cn;
    best = 0.0f;
    push_matrix();
    set_matrix_identity(0);
    translate_matrix_vec3(0, &o->pos);
    rotate_matrix_y(0, o->x60);
    for (i = 0; i < o->count; i++) {
        in.x = boss4_type1_xz_offset_table[i].x;
        in.y = 0.0f;
        in.z = boss4_type1_xz_offset_table[i].z;
        matrix_mult_vec(0, &in, &out);
        pts[i].x = out.x;
        pts[i].z = out.z;
    }
    pop_matrix();
    {
        Vec cam = camera_ctrl_instance->pos;
        Vec d;
        for (j = 0; j < o->count; j++) {
            f32 r = 50.0f + player_collider_radius_table[j];
            f32 len;
            d.x = cam.x - pts[j].x;
            d.y = 0.0f;
            d.z = cam.z - pts[j].z;
            len = vector_length(&d);
            if (!(len >= r)) {
                r -= len;
                if (best < r) {
                    best = r;
                }
            }
        }
    }
    {
        Vec a = { 0.0f, 19.8f, -5.0f };
        Vec b = { 0.0f, 12.93f, 55.42f };
        if (best > 40.42f) {
            best = 40.42f;
        }
        t = best / 40.42f;
        if (t > 0.0f) {
            a.y = -6.869999f * t + 19.8f;
            a.z = -5.0f;
            b.y = 12.93f;
            b.z = -40.42f * t + 55.42f;
        }
        cn = get_nth_view_player_id__11TCameraCtrlFl(TCameraCtrl::get_camera_no());
        request_follow_camera_offsets(&a, &b, cn);
    }
}

void TBoss4Type1::init_appear_state() { *(s32 *)((char *)this + 0x398) = 75; }

void TBoss4Type1::check_state_if_idle() {
    if (*(int *)((char *)this + 0x398) == 0) {
        check_state_transition();
    }
}

void TBoss4Type1::sub_800530C0() {
    Obj_800530C0 *self = (Obj_800530C0 *)this;
    self->f39c = calc_wave_offset(1.0f - (f32)self->timer / 75.0f);
    Vec a = { 0.0f, 0.0f, -120.0f };
    Vec b = { 0.0f, 0.0f, -175.0f };
    ((void (*)(void *, Vec *, Vec *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(this, &a, &b);
    if (--self->timer < 0) {
        set_state(1);
    }
}

void TBoss4Type1::update_flag800_state() {
    if (*(s32 *)((s8 *)this + 0x30) & 0x800) {
        send_state_to_target(4);
        return;
    }
    TBoss4Type2__sub_80053504(this);
}

void TBoss4Type1::init_movestndpos_state() { *(u32 *)((char *)this + 0x398) = *(u32 *)((char *)this + 0x3cc); }

void TBoss4Type1::update_state_transition() {
    if (*(int *)((char *)this + 0x398) == 0) {
        check_state_transition();
    }
}

void TBoss4Type1::sub_80052EF8() {
    O_80052EF8 *self = (O_80052EF8 *)this;

    self->f39c = calc_wave_offset(1.0f - (f32)self->f398 / (f32)self->f3cc);
    {
        Vec a = boss4_type2_motion_vec_table[self->f3a4];
        Vec b = boss4_type2_motion_vec_table[self->f3a0];
        ((s32 (*)(void *, Vec *, Vec *))set_pos_from_scaled_offset__11TBoss4Type2FPvPvPv)(this, &a, &b);
    }
    calc_scaled_field(((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(this, self->f3a4, self->f3ac), ((s32 (*)(void *, s32, s32))TBoss4Type2__sub_80054384)(this, self->f3a0, self->f3a8));
    play_persistent_sound(0x4003A80D, (saddr)this, (uaddr)self->f38, 0, 0);
    if (--self->f398 < 0) {
        self->f3a4 = self->f3a0;
        self->f3ac = self->f3a8;
        set_state(1);
    }
}

void TBoss4Type1::init_dead_state() { *(s32 *)((char *)this + 0x398) = 75; }

void TBoss4Type1::update_dead_idle() {  }

void TBoss4Type1::tick_state_398_timer() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        set_state(4);
    }
}

void copy_vec2(void *dst, void *src) {
    ((f32 *)dst)[0] = ((f32 *)src)[0];
    ((f32 *)dst)[1] = ((f32 *)src)[1];
}

void TBoss4Type1::start_motion_for_index() {
    S_80052E10 *self = (S_80052E10 *)this;
    set_motion_index(((s32 *)lbl_804861F4)[self->idx]);
    self->f3c8 = 0;
    copy_vec2(((u8 *)boss4_type1_xz_offset_table + 0x28), &((P2_80052E10 *)lbl_80486200)[self->idx]);
    self->f3d0 = 6;
    if (self->f374 == 5) {
        self->f398 = 0x12C;
    } else {
        self->f398 = 0x96;
    }
}

void TBoss4Type1::update_spawn_uro() {
    Params_80052CDC p;
    Spot_80052CDC *s;
    s32 t;
    Obj_80052CDC *self = (Obj_80052CDC *)this;
    s = &self->spots[self->idx];
    t = self->timer;
    if (t < 0x106 && (t & 0x1F) == 0 && self->count < self->max) {
        TBoss4DarkFalz__sub_8004B4F0(p.a, TBoss4DarkFalz__data_804FF1E8);
        if (TBoss4DarkFalz__sub_8004AF5C(self->owner, p.a, &p.b) != 0) {
            p.owner = self->owner;
            p.c = 1;
            VecCopy__FP3VecPC3Vec(&p.pos, s);
            if (create__9TBoss4UroFi(&p) != NULL) {
                spawn_particle_effect((const Vec *)s, 0x7D);
                play_sound_effect(0x4003A810, s, 0, 1);
                self->count++;
            }
        }
    }
    ((TBoss4DarkFalz *)self->owner)->sub_8004D990();
    if (self->timer == 0x106) {
        play_sound_effect(0x4003AD0F, s, 0, 1);
    }
    if (--self->timer < 0) {
        self->f3d0 = 5;
        set_state(7);
    }
}

void TBoss4Type1::tick_countdown_set_state7() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)this + 0x3D0) = 5;
        set_state(7);
    }
}

void TBoss4Type1::set_motion_for_state() {
    set_motion_index(*(s32 *)((s8 *)&boss4_type2_state_motion_index_table + (*(s32 *)((s8 *)this + 0x3A8) * 4)));
    *(s32 *)((s8 *)this + 0x398) = 0x3C;
}

void TBoss4Type1::update_state() {
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if ((s32) *(s32 *)((s8 *)this + 0x3A8) == 1) {
            choose_next_attack();
            return;
        }
        TBoss4Type2__sub_80053504(this);
    }
}

void TBoss4Type1::update_attack_countdown() {
    s32 temp_r0;
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0x2D) {
        play_sound_effect(0x4003AD11, (void *)(&((Foo *)this)->arr[*(s32 *)((s8 *)this + 0x3A8)]), 0, 1);
    }
    temp_r0 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0;
    if (temp_r0 < 0) {
        set_state(1);
    }
}

void TBoss4Type1::init_child_and_set_timer() {
    create__16TObjDFBeamCursorFPvPv(this, ((char *)this + 952));
    *(u32 *)((s8 *)this + 0x398) = 75;
}

void TBoss4Type1::update_scale_state() {
    Vec target;
    s32 var_r31;

    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if (((TObjChara *)this)->random_ratio() < 0.5) {
            ((s32 (*)(void *))TBoss4Type2__sub_80053504)(this);
            return;
        }
        var_r31 = 8;
        if ((s32) *(s32 *)((s8 *)this + 0x374) == 8) {
            var_r31 = 9;
        }
        pick_target_position(&target);
        set_map_position(&target);
        send_state_to_target(var_r31);
    }
}

void TBoss4Type1::update_tech_charge() {
    s32 idx;
    Vec *ent;
    TParticleCtrl *particle;
    idx = *(s32 *)((s8 *)this + 0x374) - 8;
    ent = &((Obj_8005294C *)this)->ents[idx];
    if (*(f32 *)((s8 *)this + 0x3E8) > 17.0f) {
        if (*(u32 *)((s8 *)this + 0x418) != 0) {
            TParticleCtrl::release((void *)*(uaddr *)((s8 *)this + 0x418));
            *(u32 *)((s8 *)this + 0x418) = 0;
        }
    } else if (*(f32 *)((s8 *)this + 0x3E8) >= 8.0f && *(u32 *)((s8 *)this + 0x418) == 0) {
        if ((*(u32 *)((s8 *)this + 0x418) = (uaddr)create_particle_emitter(ent, 0xF7)) != 0) {
            ((TParticleCtrl *)((void *)*(uaddr *)((s8 *)this + 0x418)))->set_flags(0x40);
        }
    }
    if (*(f32 *)((s8 *)this + 0x3E8) >= 8.0f && *(f32 *)((s8 *)this + 0x3E8) <= 17.0f) {
        play_persistent_sound(0x4003B512, (saddr)this, (uaddr)this + 0x38, 0, 1);
    }
    if (*(s32 *)((s8 *)this + 0x398) == 0x26) {
        if ((particle = spawn_particle_effect(ent, 0xFD)) != 0) {
            particle->set_flags(0x40);
        }
        play_sound_effect(0x4003A813, (u8 *)this + 0x38, 0, 1);
        if (idx == 0) {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            TTecRaBarta::create(this, (u8 *)this + 0x3B8, (u8 *)this + 0x3B8, (void *)params->rabarta_level);
        } else {
            TBoss4Type2Params *params = (TBoss4Type2Params *)TLobby::dispatch_shared_handler_a(0x36);
            ((TTecRaFoie *)this)->create((u8 *)this + 0x3B8, (u8 *)this + 0x3B8, (void *)params->rafoie_level);
        }
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (--*(s32 *)((s8 *)this + 0x398) < 0) {
        set_state(1);
    }
}

void TBoss4Type1::init_timer() {
    TBoss4Type2__sub_80054FC0((u8 *)this + 0x38, 125.0f);
    *(s32 *)((s8 *)this + 0x398) = 0x96;
}

void TBoss4Type1::sub_800528B8() {
    if ((s32) *(s32 *)((s8 *)this + 0x398) == 0) {
        if (this->random_ratio() < 0.75f) {
            choose_next_attack();
            return;
        }
        TBoss4Type2__sub_80053504(this);
    }
}

void TBoss4Type1::sub_800525AC() {
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_r0;
    s32 temp_r0_2;
    uaddr temp_r3;
    uaddr temp_r3_10;
    u32 particle_emitter;
    u32 temp_r3_12;
    u32 temp_r3_13;
    u32 temp_r3_14;
    uaddr temp_r3_15;
    uaddr temp_r3_16;
    uaddr temp_r3_17;
    uaddr temp_r3_18;
    uaddr temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    uaddr temp_r3_5;
    uaddr temp_r3_6;
    uaddr temp_r3_7;
    uaddr temp_r3_8;
    uaddr temp_r3_9;
    u8 *temp_r31;
    u8 *temp_r30;
    temp_r31 = (u8 *)this + 0x484;
    temp_r30 = (u8 *)this + 0x490;
    temp_r0 = *(s32 *)((s8 *)this + 0x398);
    if (temp_r0 == 6) {
        spawn_tenchu_furu(this);
    } else if (temp_r0 == 1) {
        apply_tenchu_hits(this);
    }
    if ((s32) *(s32 *)((s8 *)this + 0x3E4) == 0xD) {
        temp_f1 = *(f32 *)((s8 *)this + 0x3E8);
        if (temp_f1 > 28.0f) {
            temp_r3 = *(u32 *)((s8 *)this + 0x41C);
            if (temp_r3 != 0) {
                TParticleCtrl::release((void *)temp_r3);
                *(u32 *)((s8 *)this + 0x41C) = 0U;
            }
            temp_r3_2 = *(u32 *)((s8 *)this + 0x424);
            if (temp_r3_2 != 0) {
                TParticleCtrl::release((void *)temp_r3_2);
                *(u32 *)((s8 *)this + 0x424) = 0U;
            }
        } else if (temp_f1 >= 15.0f) {
            if ((u32) *(u32 *)((s8 *)this + 0x41C) == 0) {
                temp_r3_3 = (uaddr)create_particle_emitter((temp_r31), 0x142);
                *(u32 *)((s8 *)this + 0x41C) = temp_r3_3;
                if (temp_r3_3 != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x41C)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x424) == 0) {
                temp_r3_4 = (uaddr)create_particle_emitter((temp_r30), 0x142);
                *(u32 *)((s8 *)this + 0x424) = temp_r3_4;
                if (temp_r3_4 != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x424)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_5 = *(u32 *)((s8 *)this + 0x41C);
        if (temp_r3_5 != 0) {
            ((TParticleCtrl *)temp_r3_5)->set_position(temp_r31);
        }
        temp_r3_6 = *(u32 *)((s8 *)this + 0x424);
        if (temp_r3_6 != 0) {
            ((TParticleCtrl *)temp_r3_6)->set_position(temp_r30);
        }
    }
    if ((s32) *(s32 *)((s8 *)this + 0x3E4) == 0xE) {
        temp_f1_2 = *(f32 *)((s8 *)this + 0x3E8);
        if (temp_f1_2 > 10.0f) {
            temp_r3_7 = *(u32 *)((s8 *)this + 0x41C);
            if (temp_r3_7 != 0) {
                TParticleCtrl::release((void *)temp_r3_7);
                *(u32 *)((s8 *)this + 0x41C) = 0U;
            }
            temp_r3_8 = *(u32 *)((s8 *)this + 0x420);
            if (temp_r3_8 != 0) {
                TParticleCtrl::release((void *)temp_r3_8);
                *(u32 *)((s8 *)this + 0x420) = 0U;
            }
            temp_r3_9 = *(u32 *)((s8 *)this + 0x424);
            if (temp_r3_9 != 0) {
                TParticleCtrl::release((void *)temp_r3_9);
                *(u32 *)((s8 *)this + 0x424) = 0U;
            }
            temp_r3_10 = *(u32 *)((s8 *)this + 0x428);
            if (temp_r3_10 != 0) {
                TParticleCtrl::release((void *)temp_r3_10);
                *(u32 *)((s8 *)this + 0x428) = 0U;
            }
        } else if (temp_f1_2 >= 2.0f) {
            if ((u32) *(u32 *)((s8 *)this + 0x41C) == 0) {
                particle_emitter = (uaddr)create_particle_emitter((temp_r31), 0x13A);
                *(u32 *)((s8 *)this + 0x41C) = particle_emitter;
                if (particle_emitter != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x41C)))->set_flags(0x40U);
                }
                play_sound_effect(0x40039717, (u8 *)this + 0x38, 0, 1);
            }
            if ((u32) *(u32 *)((s8 *)this + 0x420) == 0) {
                temp_r3_12 = (uaddr)create_particle_emitter((temp_r31), 0x13B);
                *(u32 *)((s8 *)this + 0x420) = temp_r3_12;
                if (temp_r3_12 != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x420)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x424) == 0) {
                temp_r3_13 = (uaddr)create_particle_emitter((temp_r30), 0x13A);
                *(u32 *)((s8 *)this + 0x424) = temp_r3_13;
                if (temp_r3_13 != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x424)))->set_flags(0x40U);
                }
            }
            if ((u32) *(u32 *)((s8 *)this + 0x428) == 0) {
                temp_r3_14 = (uaddr)create_particle_emitter((temp_r30), 0x13B);
                *(u32 *)((s8 *)this + 0x428) = temp_r3_14;
                if (temp_r3_14 != 0) {
                    ((TParticleCtrl *)((void *) *(uaddr *)((s8 *)this + 0x428)))->set_flags(0x40U);
                }
            }
        }
        temp_r3_15 = *(u32 *)((s8 *)this + 0x41C);
        if (temp_r3_15 != 0) {
            ((TParticleCtrl *)temp_r3_15)->set_position(temp_r31);
        }
        temp_r3_16 = *(u32 *)((s8 *)this + 0x420);
        if (temp_r3_16 != 0) {
            ((TParticleCtrl *)temp_r3_16)->set_position(temp_r31);
        }
        temp_r3_17 = *(u32 *)((s8 *)this + 0x424);
        if (temp_r3_17 != 0) {
            ((TParticleCtrl *)temp_r3_17)->set_position(temp_r30);
        }
        temp_r3_18 = *(u32 *)((s8 *)this + 0x428);
        if (temp_r3_18 != 0) {
            ((TParticleCtrl *)temp_r3_18)->set_position(temp_r30);
        }
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x398) - 1;
    *(s32 *)((s8 *)this + 0x398) = temp_r0_2;
    if (temp_r0_2 < 0) {
        set_state(1);
    }
}

