#include "pso/object/T_OWEHMS_Exp.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjWaitEntryHairMoveSim.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
extern void* __vt__12T_OWEHMS_Exp[6];
void destroy__12T_OWEHMS_ExpFs();
void run_task__12T_OWEHMS_ExpFv();
}

#pragma push

#include "types.h"

struct RecoveredGlobal_800FE364_lbl_8049DC78 {
    s32 value;
    u8 remaining[0x10];
};

struct H_800FE32C { u8 pad[0x878]; u8 state; u8 pad879[0x88E - 0x879]; s8 flags; };

extern "C" {
s32 get_move_done_result__24TObjWaitEntryHairMoveSimFPv(H_800FE32C *h);
extern void *hair_bone_rotation_descriptor[];
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

int is_move_done__24TObjWaitEntryHairMoveSimFv(void) {
    return (~((int (*)(void))get_move_done_result__24TObjWaitEntryHairMoveSimFPv)()) != 0 ? 1 : 0;
}

s32 get_move_done_result__24TObjWaitEntryHairMoveSimFPv(H_800FE32C *h) {
    if (!(h->flags & 0xA)) {
        return -1;
    }
    switch (h->state) {
    case 6:
        return 0;
    }
    return -1;
}

typedef char RecoveredGlobal_800FE364_lbl_8049DC78_size[sizeof(RecoveredGlobal_800FE364_lbl_8049DC78) == 0x14 ? 1 : -1];
}
void T_OWEHMS_Exp::start_bone_rotation() {
    s32 bone = (s32)player->m_8ac;
    TObjWaitEntryHairMoveSim__sub_800FE3BC(bone);
    TObjEZBoneRotPlayer::create((void *)player, (void *)bone, (void *)((u8*)&(*(RecoveredGlobal_800FE364_lbl_8049DC78 *)&hair_bone_rotation_descriptor).value + descriptor_index * 0x14));
}

void TObjWaitEntryHairMoveSim__sub_800FE3BC(int _w0) {  }

void T_OWEHMS_Exp::run_task() {
    if (player->m_cfc == 0) {
        start_bone_rotation();
        queue_destruction__7TObjectFv(this);
    }
}
T_OWEHMS_Exp* T_OWEHMS_Exp::destroy(s16 should_free) {
    if (this != NULL) {
        *(void**)((u8*)this + 0x18) = __vt__12T_OWEHMS_Exp;
        __dt__7TObjectFv(this, 0);
        if (should_free > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
#pragma pop

#pragma push

extern "C" {

int __ct__7TObjectFP7TObject(void);
void *__nw__7TObjectFUl(int);

    extern int T_OWEHMS_Exp__name;
}
T_OWEHMS_Exp* T_OWEHMS_Exp::construct(TObjPlayer* p) {
    ((void (*)(void*, void*))__ct__7TObjectFP7TObject)(this, p);
    *(void**)((u8*)this + 0x18) = __vt__12T_OWEHMS_Exp;
    m_name = (const char*)T_OWEHMS_Exp__name;
    player = p;
    descriptor_index = get_move_done_result__24TObjWaitEntryHairMoveSimFPv((H_800FE32C*)player);
    return this;
}
T_OWEHMS_Exp* T_OWEHMS_Exp::create(TObjPlayer* p) {
    if (((int (*)(TObjPlayer*))is_move_done__24TObjWaitEntryHairMoveSimFv)(p) == 0) {
        return NULL;
    }
    T_OWEHMS_Exp* o = (T_OWEHMS_Exp*)TObject::operator new(sizeof(T_OWEHMS_Exp));
    if (o != NULL) {
        o = o->construct(p);
    }
    return o;
}
#pragma pop

#pragma push

class TObjWaitEntryHairMoveSim : public TObject {
public:
    virtual ~TObjWaitEntryHairMoveSim();
    virtual void run_task();
};

#include "pso/object/TObjTailsTailsMove.h"
#include "pso/ui/charcreate/TCharaMaking.h"

struct Ent_800FE698 { s8 a; s8 b; s8 c; s8 d; u8 pad[0xC]; };

struct Obj_800FE698 {
    u8 pad0[0x88D];
    s8 lvl;
    s8 flags;
    u8 pad1[0xB];
    s16 v9A;
    s16 v9C;
};

struct EntX_800FE5A0 { s8 a; s8 b; s8 c; s8 d; void *p4; void *p8; s32 pc; };

struct Pl_800FE5A0 {
    u8 pad0[0x88D];
    s8 lvl;
    s8 flags;
    u8 pad1[0xB];
    s16 v9A;
    s16 v9C;
    u8 pad2[0x8AC - 0x89E];
    s32 vAC;
    s32 vB0;
    s32 vB4;
};

struct Self_800FE5A0 {
    u8 pad[0x1C];
    Pl_800FE5A0 *pl;
};

extern "C" {

s32 is_level_in_table__24TObjWaitEntryHairMoveSimFPv(Obj_800FE698 *o);

extern "C" void render__7TObjectFv();
extern "C" void render_shadows__7TObjectFv();
extern void *hair_bone_rotation_bone_list_00[16];
extern void *hair_bone_rotation_bone_list_01[20];
extern void *hair_bone_rotation_bone_list_02[16];
extern void *hair_bone_rotation_bone_list_03[36];
extern void *hair_bone_rotation_bone_list_04[24];
extern void *hair_bone_rotation_bone_list_05[8];
extern void *hair_bone_rotation_bone_list_06[16];
extern void *hair_bone_rotation_bone_list_07[8];
extern void *hair_bone_rotation_bone_list_08[16];
extern void *hair_bone_rotation_bone_list_09[20];
extern void *hair_bone_rotation_bone_list_10[28];
extern void *hair_bone_rotation_bone_list_11[20];
extern void *hair_bone_rotation_bone_list_12[16];
extern void *hair_bone_rotation_bone_list_13[24];
extern void *hair_bone_rotation_bone_list_14[12];
extern void *hair_bone_rotation_bone_list_15[12];
extern void *hair_bone_rotation_bone_list_16[20];
extern void *hair_bone_rotation_bone_list_17[16];
extern void *hair_bone_rotation_bone_list_18[12];
extern void *hair_bone_rotation_bone_list_19[20];
extern void *hair_bone_rotation_bone_list_20[32];
extern void *hair_bone_rotation_bone_list_21[36];
extern void *hair_bone_rotation_bone_list_22[12];
extern void *hair_bone_rotation_bone_list_23[12];
extern void *hair_bone_rotation_bone_list_24[20];
extern void *hair_bone_rotation_bone_list_25[20];
extern void *hair_bone_rotation_bone_list_26[8];
extern void *hair_bone_rotation_bone_list_27[8];
extern void *hair_bone_rotation_bone_list_28[12];
extern void *hair_bone_rotation_bone_list_29[20];
extern void *hair_bone_rotation_bone_list_30[16];
extern void *hair_bone_rotation_bone_list_31[8];
extern void *hair_bone_rotation_bone_list_32[16];
extern void *hair_bone_rotation_bone_list_33[24];
extern void *hair_bone_rotation_bone_list_34[16];
extern void *hair_bone_rotation_bone_list_35[12];
extern void *hair_bone_rotation_bone_list_36[8];
extern void *hair_bone_rotation_bone_list_37[16];
extern void *hair_bone_rotation_bone_list_38[20];
extern void *hair_bone_rotation_bone_list_39[16];
extern void *hair_bone_rotation_desc_00[5];
extern void *hair_bone_rotation_desc_01[5];
extern void *hair_bone_rotation_desc_02[5];
extern void *hair_bone_rotation_desc_03[5];
extern void *hair_bone_rotation_desc_04[5];
extern void *hair_bone_rotation_desc_05[5];
extern void *hair_bone_rotation_desc_06[5];
extern void *hair_bone_rotation_desc_07[5];
extern void *hair_bone_rotation_desc_08[5];
extern void *hair_bone_rotation_desc_09[5];
extern void *hair_bone_rotation_desc_10[5];
extern void *hair_bone_rotation_desc_11[5];
extern void *hair_bone_rotation_desc_12[5];
extern void *hair_bone_rotation_desc_13[5];
extern void *hair_bone_rotation_desc_14[5];
extern void *hair_bone_rotation_desc_15[5];
extern void *hair_bone_rotation_desc_16[5];
extern void *hair_bone_rotation_desc_17[5];
extern void *hair_bone_rotation_desc_18[5];
extern void *hair_bone_rotation_desc_19[5];
extern void *hair_bone_rotation_desc_20[5];
extern void *hair_bone_rotation_desc_21[5];
extern void *hair_bone_rotation_desc_22[5];
extern void *hair_bone_rotation_desc_23[5];
extern void *hair_bone_rotation_desc_24[5];
extern void *hair_bone_rotation_desc_25[5];
extern void *hair_bone_rotation_desc_26[5];
extern void *hair_bone_rotation_desc_27[5];
extern void *hair_bone_rotation_desc_28[5];
extern void *hair_bone_rotation_desc_29[5];
extern void *hair_bone_rotation_desc_30[5];
extern void *hair_bone_rotation_desc_31[5];
extern void *hair_bone_rotation_desc_32[5];
extern void *hair_bone_rotation_desc_33[5];
extern void *hair_bone_rotation_desc_34[5];
extern void *hair_bone_rotation_desc_35[5];
extern void *hair_bone_rotation_desc_36[5];
extern void *hair_bone_rotation_desc_37[5];
extern void *hair_bone_rotation_desc_38[5];
extern void *hair_bone_rotation_desc_39[5];
extern void *hair_bone_rotation_bone_list_of_descriptor[20];
void *hair_bone_rotation_bone_list_00[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_01[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_02[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_03[36] = {
    (void *)0x1, (void *)0x3e051eb8, (void *)0x0, (void *)0x3f851eb8,
    (void *)0x2, (void *)0x3df5c290, (void *)0x0, (void *)0x3f75c290,
    (void *)0x3, (void *)0x3de147af, (void *)0x0, (void *)0x3f6147af,
    (void *)0x4, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f4ccccd,
    (void *)0x5, (void *)0xbe051eb8, (void *)0x0, (void *)0x3f851eb8,
    (void *)0x6, (void *)0xbdf5c290, (void *)0x0, (void *)0x3f75c290,
    (void *)0x7, (void *)0xbde147af, (void *)0x0, (void *)0x3f6147af,
    (void *)0x8, (void *)0xbdcccccd, (void *)0x0, (void *)0x3f4ccccd,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_04[24] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xc, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_05[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_06[16] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_07[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_08[16] = {
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_09[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_10[28] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x9, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_11[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_12[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_13[24] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x9, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_14[12] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x3e800000,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x3e800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_15[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3ee66666, (void *)0xbee66666,
    (void *)0x2, (void *)0x3f800000, (void *)0xbee66666, (void *)0x3ee66666,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_16[20] = {
    (void *)0x1, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x2, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x3, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x4, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_17[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_18[12] = {
    (void *)0x6, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0x7, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_19[20] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_20[32] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xc, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xf, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x10, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_21[36] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x3e4ccccd,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x3e4ccccd,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x3e4ccccd,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x3e4ccccd,
    (void *)0x5, (void *)0xbf800000, (void *)0x0, (void *)0xbe4ccccd,
    (void *)0x6, (void *)0xbf800000, (void *)0x0, (void *)0xbe4ccccd,
    (void *)0x7, (void *)0xbf800000, (void *)0x0, (void *)0xbe4ccccd,
    (void *)0x8, (void *)0xbf800000, (void *)0x0, (void *)0xbe4ccccd,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_22[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3ee66666, (void *)0xbee66666,
    (void *)0x2, (void *)0x3f800000, (void *)0xbee66666, (void *)0x3ee66666,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_23[12] = {
    (void *)0x2, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_24[20] = {
    (void *)0x6, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_25[20] = {
    (void *)0x6, (void *)0x3f800000, (void *)0x3f000000, (void *)0x0,
    (void *)0x7, (void *)0x3f99999a, (void *)0x3f333333, (void *)0x0,
    (void *)0xa, (void *)0xbf800000, (void *)0x3f000000, (void *)0x0,
    (void *)0xb, (void *)0xbf99999a, (void *)0x3f333333, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_26[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_27[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_28[12] = {
    (void *)0x6, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0x7, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_29[20] = {
    (void *)0x1, (void *)0xbf800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x2, (void *)0xbf800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_30[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_31[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_32[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_33[24] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x5, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_34[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_35[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0xbf800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_36[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_37[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_38[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_39[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_desc_00[5] = {
    (void *)0xa00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_00,
};
void *hair_bone_rotation_desc_01[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_01,
};
void *hair_bone_rotation_desc_02[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_02,
};
void *hair_bone_rotation_desc_03[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_03,
};
void *hair_bone_rotation_desc_04[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_04,
};
void *hair_bone_rotation_desc_05[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_05,
};
void *hair_bone_rotation_desc_06[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_06,
};
void *hair_bone_rotation_desc_07[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_07,
};
void *hair_bone_rotation_desc_08[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_08,
};
void *hair_bone_rotation_desc_09[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_09,
};
void *hair_bone_rotation_desc_10[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_10,
};
void *hair_bone_rotation_desc_11[5] = {
    (void *)0x280, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_11,
};
void *hair_bone_rotation_desc_12[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_12,
};
void *hair_bone_rotation_desc_13[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_13,
};
void *hair_bone_rotation_desc_14[5] = {
    (void *)0x800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_14,
};
void *hair_bone_rotation_desc_15[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_15,
};
void *hair_bone_rotation_desc_16[5] = {
    (void *)0x1400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_16,
};
void *hair_bone_rotation_desc_17[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_17,
};
void *hair_bone_rotation_desc_18[5] = {
    (void *)0xc00, (void *)0x1400, (void *)0x1800, (void *)0x3f733333,
    (void *)&hair_bone_rotation_bone_list_18,
};
void *hair_bone_rotation_desc_19[5] = {
    (void *)0xa00, (void *)0x1800, (void *)0x3800, (void *)0x3f733333,
    (void *)&hair_bone_rotation_bone_list_19,
};
void *hair_bone_rotation_desc_20[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_20,
};
void *hair_bone_rotation_desc_21[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_21,
};
void *hair_bone_rotation_desc_22[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_22,
};
void *hair_bone_rotation_desc_23[5] = {
    (void *)0x600, (void *)0xa00, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_23,
};
void *hair_bone_rotation_desc_24[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_24,
};
void *hair_bone_rotation_desc_25[5] = {
    (void *)0x400, (void *)0x1800, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_25,
};
void *hair_bone_rotation_desc_26[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_26,
};
void *hair_bone_rotation_desc_27[5] = {
    (void *)0x800, (void *)0x1400, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_27,
};
void *hair_bone_rotation_desc_28[5] = {
    (void *)0x340, (void *)0x1400, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_28,
};
void *hair_bone_rotation_desc_29[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_29,
};
void *hair_bone_rotation_desc_30[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_30,
};
void *hair_bone_rotation_desc_31[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_31,
};
void *hair_bone_rotation_desc_32[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f99999a,
    (void *)&hair_bone_rotation_bone_list_32,
};
void *hair_bone_rotation_desc_33[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_33,
};
void *hair_bone_rotation_desc_34[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_34,
};
void *hair_bone_rotation_desc_35[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_35,
};
void *hair_bone_rotation_desc_36[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_36,
};
void *hair_bone_rotation_desc_37[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_37,
};
void *hair_bone_rotation_desc_38[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_38,
};
void *hair_bone_rotation_desc_39[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f99999a,
    (void *)&hair_bone_rotation_bone_list_39,
};
void *hair_effect_selection_table[164] = {
    (void *)0xff07ff, (void *)&hair_bone_rotation_desc_00, (void *)0x0, (void *)0x0,
    (void *)0xff09ff, (void *)&hair_bone_rotation_desc_01, (void *)0x0, (void *)0x0,
    (void *)0x1ff03ff, (void *)&hair_bone_rotation_desc_02, (void *)0x0, (void *)0x0,
    (void *)0x1ff04ff, (void *)&hair_bone_rotation_desc_03, (void *)0x0, (void *)0x0,
    (void *)0x1ff06ff, (void *)&hair_bone_rotation_desc_04, (void *)0x0, (void *)0x0,
    (void *)0x5ffff01, (void *)&hair_bone_rotation_desc_05, (void *)0x0, (void *)0x0,
    (void *)0x5ffff02, (void *)&hair_bone_rotation_desc_06, (void *)0x0, (void *)0x0,
    (void *)0x5ffff03, (void *)&hair_bone_rotation_desc_07, (void *)0x0, (void *)0x0,
    (void *)0x6ff00ff, (void *)&hair_bone_rotation_desc_08, (void *)0x0, (void *)0x0,
    (void *)0x602ffff, (void *)&hair_bone_rotation_desc_09, (void *)0x0, (void *)0x0,
    (void *)0x603ffff, (void *)&hair_bone_rotation_desc_10, (void *)0x0, (void *)0x0,
    (void *)0x6ff03ff, (void *)&hair_bone_rotation_desc_11, (void *)0x0, (void *)0x0,
    (void *)0x6ff05ff, (void *)&hair_bone_rotation_desc_12, (void *)0x0, (void *)0x0,
    (void *)0x6ff06ff, (void *)&hair_bone_rotation_desc_13, (void *)0x0, (void *)0x0,
    (void *)0x609ffff, (void *)&hair_bone_rotation_desc_14, (void *)0x0, (void *)0x0,
    (void *)0x701ffff, (void *)&hair_bone_rotation_desc_15, (void *)0x0, (void *)0x0,
    (void *)0x7ff05ff, (void *)&hair_bone_rotation_desc_16, (void *)0x0, (void *)0x0,
    (void *)0x7ff07ff, (void *)&hair_bone_rotation_desc_17, (void *)0x0, (void *)0x0,
    (void *)0x709ffff, (void *)&hair_bone_rotation_desc_18, (void *)0x0, (void *)0x0,
    (void *)0x800ffff, (void *)&hair_bone_rotation_desc_19, (void *)0x0, (void *)0x0,
    (void *)0x8ff00ff, (void *)&hair_bone_rotation_desc_20, (void *)0x0, (void *)0x0,
    (void *)0x8ff03ff, (void *)&hair_bone_rotation_desc_21, (void *)0x0, (void *)0x0,
    (void *)0x805ffff, (void *)&hair_bone_rotation_desc_22, (void *)0x0, (void *)0x0,
    (void *)0x806ffff, (void *)&hair_bone_rotation_desc_23, (void *)0x0, (void *)0x0,
    (void *)0x8ff06ff, (void *)&hair_bone_rotation_desc_24, (void *)0x0, (void *)0x0,
    (void *)0x809ffff, (void *)&hair_bone_rotation_desc_25, (void *)0x0, (void *)0x0,
    (void *)0x9ffff00, (void *)&hair_bone_rotation_desc_26, (void *)0x0, (void *)0x0,
    (void *)0x9ffff02, (void *)&hair_bone_rotation_desc_27, (void *)0x0, (void *)0x0,
    (void *)0xa02ffff, (void *)&hair_bone_rotation_desc_28, (void *)0x0, (void *)0x0,
    (void *)0xa03ffff, (void *)&hair_bone_rotation_desc_29, (void *)0x0, (void *)0x0,
    (void *)0xaff05ff, (void *)&hair_bone_rotation_desc_30, (void *)0x0, (void *)0x0,
    (void *)0xaff07ff, (void *)&hair_bone_rotation_desc_31, (void *)0x0, (void *)0x0,
    (void *)0xa08ffff, (void *)&hair_bone_rotation_desc_32, (void *)0x0, (void *)0x0,
    (void *)0xaff09ff, (void *)&hair_bone_rotation_desc_33, (void *)0x0, (void *)0x0,
    (void *)0xbff01ff, (void *)&hair_bone_rotation_desc_34, (void *)0x0, (void *)0x0,
    (void *)0xbff03ff, (void *)&hair_bone_rotation_desc_35, (void *)0x0, (void *)0x0,
    (void *)0xbff04ff, (void *)&hair_bone_rotation_desc_36, (void *)0x0, (void *)0x0,
    (void *)0xbff06ff, (void *)&hair_bone_rotation_desc_37, (void *)0x0, (void *)0x0,
    (void *)0xbff07ff, (void *)&hair_bone_rotation_desc_38, (void *)0x0, (void *)0x0,
    (void *)0xb09ffff, (void *)&hair_bone_rotation_desc_39, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_bone_list_of_descriptor[20] = {
    (void *)0x1, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x2, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x3, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x4, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3e800000,
};
void *hair_bone_rotation_descriptor[5] = {
    (void *)0x400, (void *)0xc00, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&hair_bone_rotation_bone_list_of_descriptor,
};
void* __vt__12T_OWEHMS_Exp[6] = {
    0, 0, (void*)&destroy__12T_OWEHMS_ExpFs, (void*)&run_task__12T_OWEHMS_ExpFv,
    (void*)&render__7TObjectFv, (void*)&render_shadows__7TObjectFv,
};
#define hair_effect_selection_table ((Ent_800FE698 *)hair_effect_selection_table)

}
void TObjWaitEntryHairMoveSim::run_task() {
    void *arg0 = this;
    if ((s32) *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x1C)) + 0xCFC) == 0) {
        create_hair_effects__24TObjWaitEntryHairMoveSimFPv(arg0);
        queue_destruction__7TObjectFv(arg0);
    }
}

extern s32 __vt__24TObjWaitEntryHairMoveSim[];
extern void *TObjWaitEntryHairMoveSim__name;

void *__ct__24TObjWaitEntryHairMoveSimFv(void *arg0, void *arg1) {
    ((void (*)(void *))__ct__7TObjectFP7TObject)(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TObjWaitEntryHairMoveSim;
    *(void **)((s8 *)arg0 + 0x0) = TObjWaitEntryHairMoveSim__name;
    *(void **)((s8 *)arg0 + 0x1C) = arg1;
    return arg0;
}

void create_hair_effects__24TObjWaitEntryHairMoveSimFPv(void *arg0) {
    Self_800FE5A0 *self = (Self_800FE5A0 *)arg0;
    EntX_800FE5A0 *e;
    s32 v;
    for (e = (EntX_800FE5A0 *)hair_effect_selection_table; e->a >= 0 && e->a <= self->pl->lvl; e++) {
        if (self->pl->lvl == e->a) {
            if (self->pl->v9C == e->b) {
                v = self->pl->vB0;
            } else if (self->pl->v9C == e->c) {
                v = self->pl->vAC;
            } else if (self->pl->v9A == e->d) {
                v = self->pl->vB4;
            } else {
                continue;
            }
            ((void (*)(s32))TObjWaitEntryHairMoveSim__sub_800FE3BC)(v);
            if (e->p4 != NULL) {
                TObjEZBoneRotPlayer::create(self->pl, (void *)v, e->p4);
            } else if (e->p8 != NULL) {
                ((TObjPlayer *)(self->pl))->create_hairmove((void *)e->p8, (void *)e->pc);
            }
        }
    }
}

s32 is_level_in_table__24TObjWaitEntryHairMoveSimFPv(Obj_800FE698 *o) {
    Ent_800FE698 *e;
    if (o->flags & 0xA) {
        return 0;
    }
    for (e = hair_effect_selection_table; e->a >= 0 && e->a <= o->lvl; e++) {
        if (o->lvl == e->a && (o->v9C == e->b || o->v9C == e->c || o->v9A == e->d)) {
            return 1;
        }
    }
    return 0;
}

s32 fn_800FE73C(TObjPlayer *player) {
    s32 temp_r3;
    s32 var_r0;
    if (((TCharaMaking *)((char *)player + 0x85C))->get_display_index() == 0xE) {
        TObjTailsTailsMove::create(player);
        return 0;
    }
    if (((s32 (*)(void *))is_move_done__24TObjWaitEntryHairMoveSimFv)((void *)player) != 0) {
        T_OWEHMS_Exp::create(player);
        return 0;
    }
    if (is_level_in_table__24TObjWaitEntryHairMoveSimFPv((Obj_800FE698 *)player) != 0) {
        temp_r3 = ((s32 (*)(int))__nw__7TObjectFUl)(0x20);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = ((s32)__ct__24TObjWaitEntryHairMoveSimFv((void *)temp_r3, (void *)player));
        }
        return var_r0;
    }
    return 0;
}
TObjWaitEntryHairMoveSim::~TObjWaitEntryHairMoveSim() {}

#pragma pop
