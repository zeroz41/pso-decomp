#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/object/TObjQuestColBase_80196BFC.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjQuestColBase.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct VBase_18_551843 { char pad[0x18]; };

struct VObj_18_551843 : VBase_18_551843 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual s32 m13();
    virtual u8 * m14();
};

struct RecoveredGlobal_80196D50___vt__16TObjQuestColBase { s32 value; u8 remaining[0x44]; };
typedef char RecoveredGlobal_80196D50___vt__16TObjQuestColBase_size[sizeof(RecoveredGlobal_80196D50___vt__16TObjQuestColBase) == 0x48 ? 1 : -1];

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

struct RecoveredGlobal_80196C60_lbl_804A7438 {
    s32 value;
    u8 remaining[0xC];
};

struct VBase_18_1a504b
{
  char pad[0x18];
};

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct RecoveredGlobal_80196DB4___vt__16TObjQuestColBase
{
  s32 value;
  u8 remaining[0x44];
};

struct RecoveredFields_80196DB4_arg0
{
  s32 field_0;
  u8 unknown_4[0x2];
  u16 field_6;
  u8 unknown_8[0x10];
  s32 *field_18;
  u16 field_1C;
  u8 unknown_1E[0x4A];
  f32 field_68;
  u8 unknown_6C[0x18];
  s32 field_84;
  u8 unknown_88[0x24];
  f32 field_AC;
  s32 field_B0;
  s32 field_B4;
  s32 field_B8;
};

extern "C" {
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80196D50___vt__16TObjQuestColBase __vt__16TObjQuestColBase;
extern s32 TObjQuestColBase__instance_count;
s32 TObjRoomId__sub_80141CF4(void *, void *, f32);
extern RecoveredGlobal_80196C60_lbl_804A7438 lbl_804A7438;
extern const f32 lbl_805DBEF8;
extern const f32 lbl_805DBEFC;
extern const f32 lbl_805DBF00;
extern s32 quest_col_base_class_name;
extern u16 quest_collision_next_id;
void *get_player_by_client_id(s32 i);

extern s32 local_client_id;

s32 TObjQuestColBase::is_within_range(f32 farg0) {
    s32 arg0 = (s32)this;
    u32 player;

    player = (u32)get_player_by_client_id(local_client_id);
    if ((player != 0U) && (xyz_distance_squared((Vec *)(player + 0x38), (Vec *)(arg0 + 0x38)) < farg0)) {
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_80196C60_lbl_804A7438_size[sizeof(RecoveredGlobal_80196C60_lbl_804A7438) == 0x10 ? 1 : -1];
void TObjQuestColBase::update_room_id_check() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBEF8, lbl_805DBEFC) != 0) {
        TObjRoomId__sub_80141CF4((u8 *)&this->position, &lbl_804A7438.value, (f32) (lbl_805DBF00 * *(f32 *)&this->unk_AC));
    }
}

void TObjQuestColBase::render() {  }
void TObjQuestColBase::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)this->m_b8;
    if ((temp_r3 != NULL) && (((TObject *)temp_r3)->all_parents_unqueued_for_destruction() == 0)) {
        this->m_b8 = NULL;
    }
    if (((void *) this->m_b8 == NULL) && (this->vfunc_15() != 0)) {
        *(u8 * *)&this->m_b8 = ((VObj_18_551843 *)(arg0))->m14();
    }
}
u8 *__dt__16TObjQuestColBaseFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__16TObjQuestColBase.value;
        TObjQuestColBase__instance_count -= 1;
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef struct RecoveredFields_80196DB4_arg0 RecoveredFields_80196DB4_arg0;
typedef struct RecoveredGlobal_80196DB4___vt__16TObjQuestColBase RecoveredGlobal_80196DB4___vt__16TObjQuestColBase;
typedef struct VBase_18_1a504b VBase_18_1a504b;
typedef struct VObj_18_1a504b VObj_18_1a504b;
typedef char RecoveredGlobal_80196DB4___vt__16TObjQuestColBase_size[((sizeof(RecoveredGlobal_80196DB4___vt__16TObjQuestColBase)) == 0x48) ? (1) : (-1)];
u8 *TObjQuestColBase__ct(u8 *quest_col_base, s32 arg1, s32 arg2) {
  u16 temp_r6;
  __ct__14TObjCollidableFP7TObject(quest_col_base, arg1);
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_18 = &(*(RecoveredGlobal_80196DB4___vt__16TObjQuestColBase *)&__vt__16TObjQuestColBase).value;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_0 = quest_col_base_class_name;
  (((TObjQuestColBase *)(quest_col_base))->apply_object_set_data((void *)arg2));
  temp_r6 = -1;
  if (((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_1C == temp_r6)
  {
    ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_1C = TLobby::alloc_actor_ids(0);
  }
  temp_r6 = quest_collision_next_id;
  quest_collision_next_id = temp_r6 + 1;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_6 = temp_r6;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_AC = ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_68;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_B0 = ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_84;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_B4 = 1;
  ((RecoveredFields_80196DB4_arg0 *) quest_col_base)->field_B8 = 0;
  TObjQuestColBase__instance_count += 1;
  return quest_col_base;
}

}
