#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/camera/TCameraCtrl_8006B3D8.h"
#include "pso/unk/TUnk_80488AD8.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_80488B08.h"
#include "pso/unk/TUnk_80488AF0.h"

#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"

struct RecoveredFields_8006B588_arg0
{
  u8 unknown_0[0x18];
  s32 *field_18;
  u8 unknown_1C[0x18];
  s32 field_34;
};

#define VIEW_8006B798 ((View_8006B798 *)camera_ctrl_instance)

struct View_8006B798 {
    u8 pad0[0x178];
    Vec pos;
    Vec tgt;
};

extern s32 local_client_id;
extern saddr tl_07;
u8 *create_conversation_camera(s32 arg0);

struct NpcCameraDestination {
    f32 position[3];
    f32 target[3];
};

extern const NpcCameraDestination fixed_npc_camera_destination_table[20];
const NpcCameraDestination fixed_npc_camera_destination_table[20] = {
    {-158.0f, 15.0f, 269.0f, -165.0f, 19.0f, 287.0f},
    {-206.0f, 15.0f, 262.0f, -210.0f, 18.0f, 290.0f},
    {-226.0f, 13.0f, 231.0f, -240.0f, 19.0f, 244.0f},
    {-127.0f, 12.0f, 240.0f, -114.0f, 24.0f, 276.0f},
    {-256.0f, 12.0f, -32.0f, -271.0f, 15.0f, -19.0f},
    {184.4f, 11.8f, 330.8f, 174.0f, 17.5f, 353.1f},
    {208.6f, 15.1f, -281.4f, 219.4f, 23.0f, -308.2f},
    {-4.8f, 11.7f, -2015.1f, 0.4f, 20.0f, -2032.5f},
    {-34.7f, 14.5f, -1994.0f, -58.0f, 18.8f, -2004.0f},
    {33.9f, 12.7f, -1996.6f, 71.4f, 22.4f, -2006.6f},
    {-158.8f, 13.5f, -125.4f, -189.3f, 19.8f, -150.5f},
    {-144.6f, 13.0f, -187.0f, -170.4f, 19.9f, -214.1f},
    {-93.0f, 14.6f, -197.7f, -99.8f, 20.0f, -236.8f},
    {-91.5f, 13.1f, -110.0f, -62.0f, 20.0f, -110.0f},
    {-122.0f, 12.7f, -73.8f, -164.3f, 21.9f, -26.6f},
    {-1.0f, 13.0f, 209.9f, -56.0f, 20.0f, 202.8f},
    {-0.58f, 12.0f, -210.3f, -32.26f, 16.64f, -221.77f},
    {-10000.0f, 48.0f, -198.4f, -10000.0f, 46.5f, -236.3f},
    {-10039.4f, 43.3f, -176.9f, -10063.5f, 53.8f, -212.1f},
    {-9953.2f, 42.4f, -168.1f, -9924.0f, 50.0f, -183.9f},
};

struct O_8006BAC8 { u8 pad[0xd4]; Vec arr[1]; };

struct O_8006BAB4 { u8 pad[0x104]; Vec arr[1]; };

extern "C" {
s32 TCameraCtrl__fixed_npc_camera_active;
void set_active_camera_pose(void *, void *);
s32 approach_camera_vector(void *, void *, f32);
s32 activate_camera_mode(int);
Vec *TCameraCtrl__sub_8006BAB4(O_8006BAB4 *self, s32 i);
Vec *TCameraCtrl__sub_8006BAC8(O_8006BAC8 *self, s32 i);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern const s32 __vt__13TUnk_80488AD8[];
extern uaddr camera_ctrl_instance;
s32 restore_player_cameras();

extern unsigned char TCameraCtrl__override_flags;

s32 TCameraCtrl__sub_8006BADC(void) { return TCameraCtrl__override_flags; }

Vec *TCameraCtrl__sub_8006BAC8(O_8006BAC8 *self, s32 i) {
    return &self->arr[i];
}

Vec *TCameraCtrl__sub_8006BAB4(O_8006BAB4 *self, s32 i) {
    return &self->arr[i];
}

}

TUnk_80488B08::TUnk_80488B08() : TUnk_80488A28() {
    m_38 = 4;
    TCameraCtrl__fixed_npc_camera_active = 0;
}

TUnk_80488B08::~TUnk_80488B08() {
    TCameraCtrl__fixed_npc_camera_active = 0;
}

void TUnk_80488B08::run_task() {  }

void TUnk_80488B08::vfunc_6() {
    void *temp_r3;

    if ((u32) camera_ctrl_instance != 0U) {
        temp_r3 = ((TCameraCtrl *)camera_ctrl_instance)->get_params();
        this->target.x = (f32) *(f32 *)((s8 *)temp_r3 + 0x28);
        this->target.y = (f32) *(f32 *)((s8 *)temp_r3 + 0x2C);
        this->target.z = (f32) *(f32 *)((s8 *)temp_r3 + 0x30);
        this->position.x = (f32) *(f32 *)((s8 *)temp_r3 + 0x1C);
        this->position.y = (f32) *(f32 *)((s8 *)temp_r3 + 0x20);
        this->position.z = (f32) *(f32 *)((s8 *)temp_r3 + 0x24);
        this->projection_angle = (s32) (182.04445f * (f32) *(s32 *)((s8 *)temp_r3 + 0x14));
        this->m_58 = (f32) *(f32 *)((s8 *)temp_r3 + 0x10);
    }
}

void *TCameraCtrl__vt9(void) {
    void *o;
    o = new TUnk_80488B08();
    return o;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
TUnk_80488AF0::TUnk_80488AF0(Vec *goal, s32 frames, s32 hold, TObject *parent) : TObject(parent) {
    Vec d;
    f32 dist;
    dist = xyz_distance(&VIEW_8006B798->pos, &VIEW_8006B798->tgt);
    VecCopy(&look_goal, goal);
    VecCopy(&look_at, &VIEW_8006B798->tgt);
    if (frames == 0) {
        pan_frames = 1;
    } else {
        pan_frames = frames;
    }
    hold_frames = hold;
    d.x = look_goal.x - VIEW_8006B798->pos.x;
    d.y = look_goal.y - VIEW_8006B798->pos.y;
    d.z = look_goal.z - VIEW_8006B798->pos.z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    look_goal.x = d.x * dist + VIEW_8006B798->pos.x;
    look_goal.y = d.y * dist + VIEW_8006B798->pos.y;
    look_goal.z = d.z * dist + VIEW_8006B798->pos.z;
    step = xyz_distance(&look_goal, &VIEW_8006B798->tgt) / (f32)pan_frames;
    frame = 0;
    TCameraCtrl::set_fixed_position_and_target((u8 *)&VIEW_8006B798->pos, (u8 *)&VIEW_8006B798->tgt);
}
#pragma pop

TUnk_80488AF0::~TUnk_80488AF0() {
    TCameraCtrl::reset_to_local_player();
}

void TUnk_80488AF0::run_task() {
    approach_vector_fixed_distance(&look_at, &look_goal, &look_at, step);
    if (TCameraCtrl__sub_8006BADC() == 1) {
        TCameraCtrl::set_fixed_position_and_target((u8 *)(camera_ctrl_instance + 0x178), (u8 *)&look_at);
    }
    frame++;
    if (frame == pan_frames + hold_frames || TCameraCtrl__sub_8006BADC() == 0) {
        queue_destruction();
    }
}

void TCameraCtrl::create(saddr goal, s32 frames, s32 arg2) {
    new TUnk_80488AF0((Vec *)goal, frames, arg2, (TObject *)tl_07);
}

typedef struct RecoveredFields_8006B588_arg0 RecoveredFields_8006B588_arg0;
u8 *TCameraCtrl::init_conversation_camera(s32 i, s32 arg2, saddr parent) {
  void *new_var;
  __ct__7TObjectFP7TObject((void *) this, (void *) parent);
  ((RecoveredFields_8006B588_arg0 *) ((u8 *)this))->field_18 = ((s32 *)&__vt__13TUnk_80488AD8);
  ((RecoveredFields_8006B588_arg0 *) ((u8 *)this))->field_34 = arg2;
  activate_camera_mode(9);
  if (is_split_screen() != 0)
  {
    new_var = (void *) TCameraCtrl__sub_8006BAC8((O_8006BAC8 *)camera_ctrl_instance, i);
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)new_var);
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)((void *) TCameraCtrl__sub_8006BAB4((O_8006BAB4 *)camera_ctrl_instance, i)));
  }
  else
  {
    VecCopy((Vec *)(((u8 *)this) + 0x1C), (const Vec *)((*(saddr *)&camera_ctrl_instance) + 0x178));
    VecCopy((Vec *)(((u8 *)this) + 0x28), (const Vec *)((*(saddr *)&camera_ctrl_instance) + 0x184));
  }
  set_active_camera_pose((void *) (((u8 *)this) + 0x1C), (void *) (((u8 *)this) + 0x28));
  TCameraCtrl__fixed_npc_camera_active = 0;
  return ((u8 *)this);
}

TUnk_80488AD8::~TUnk_80488AD8() {
    restore_player_cameras();
    TCameraCtrl__fixed_npc_camera_active = 0;
}

void TUnk_80488AD8::run_task() {
    u8 *arg0 = (u8 *)this;
    approach_camera_vector((u8 *)&this->unk_1C, (u8 *)fixed_npc_camera_destination_table + (this->m_34 * 0x18), 0.725f);
    approach_camera_vector(arg0 + 0x28, (u8 *)fixed_npc_camera_destination_table + (this->m_34 * 0x18) + 0xC, 0.725f);
    TCameraCtrl__fixed_npc_camera_active = 1;
    set_active_camera_pose((u8 *)&this->unk_1C, arg0 + 0x28);
}

u8 *create_conversation_camera(s32 arg0) {
    s32 i;
    u8 *camera_ctrl;
    u8 *var_r0;
    if (is_split_screen() != 0) {
        return NULL;
    }
    i = local_client_id;
    camera_ctrl = (u8 *)(((u8 *)TObject::operator new(0x38)));
    var_r0 = camera_ctrl;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TCameraCtrl *)camera_ctrl)->init_conversation_camera(i, arg0, tl_07));
    }
    return var_r0;
}

void TCameraCtrl::update_battle_camera() {
    void *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TObjPlayer *)player)->deactivate_body_collision();
    }
}

void TCameraCtrl::update_active_player() {
    void *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        ((TObjPlayer *)player)->activate_body_collision();
    }
}
