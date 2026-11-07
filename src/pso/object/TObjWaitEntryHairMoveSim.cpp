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
extern void *lbl_8049CBA8[16];
extern void *lbl_8049CBE8[20];
extern void *lbl_8049CC38[16];
extern void *lbl_8049CC78[36];
extern void *lbl_8049CD08[24];
extern void *lbl_8049CD68[8];
extern void *lbl_8049CD88[16];
extern void *lbl_8049CDC8[8];
extern void *lbl_8049CDE8[16];
extern void *lbl_8049CE28[20];
extern void *lbl_8049CE78[28];
extern void *lbl_8049CEE8[20];
extern void *lbl_8049CF38[16];
extern void *lbl_8049CF78[24];
extern void *lbl_8049CFD8[12];
extern void *lbl_8049D008[12];
extern void *lbl_8049D038[20];
extern void *lbl_8049D088[16];
extern void *lbl_8049D0C8[12];
extern void *lbl_8049D0F8[20];
extern void *lbl_8049D148[32];
extern void *lbl_8049D1C8[36];
extern void *lbl_8049D258[12];
extern void *lbl_8049D288[12];
extern void *lbl_8049D2B8[20];
extern void *lbl_8049D308[20];
extern void *lbl_8049D358[8];
extern void *lbl_8049D378[8];
extern void *lbl_8049D398[12];
extern void *lbl_8049D3C8[20];
extern void *lbl_8049D418[16];
extern void *lbl_8049D458[8];
extern void *lbl_8049D478[16];
extern void *lbl_8049D4B8[24];
extern void *lbl_8049D518[16];
extern void *lbl_8049D558[12];
extern void *lbl_8049D588[8];
extern void *lbl_8049D5A8[16];
extern void *lbl_8049D5E8[20];
extern void *lbl_8049D638[16];
extern void *hair_bone_rotation_desc_00[5];
extern void *hair_bone_rotation_desc_01[5];
extern void *hair_bone_rotation_desc_02[5];
extern void *hair_bone_rotation_desc_03[5];
extern void *hair_bone_rotation_desc_04[5];
extern void *hair_bone_rotation_desc_05[5];
extern void *hair_bone_rotation_desc_06[5];
extern void *hair_bone_rotation_desc_07[5];
extern void *lbl_8049D718[5];
extern void *lbl_8049D72C[5];
extern void *lbl_8049D740[5];
extern void *lbl_8049D754[5];
extern void *lbl_8049D768[5];
extern void *lbl_8049D77C[5];
extern void *lbl_8049D790[5];
extern void *lbl_8049D7A4[5];
extern void *lbl_8049D7B8[5];
extern void *lbl_8049D7CC[5];
extern void *lbl_8049D7E0[5];
extern void *lbl_8049D7F4[5];
extern void *lbl_8049D808[5];
extern void *lbl_8049D81C[5];
extern void *lbl_8049D830[5];
extern void *lbl_8049D844[5];
extern void *lbl_8049D858[5];
extern void *lbl_8049D86C[5];
extern void *lbl_8049D880[5];
extern void *lbl_8049D894[5];
extern void *lbl_8049D8A8[5];
extern void *lbl_8049D8BC[5];
extern void *lbl_8049D8D0[5];
extern void *lbl_8049D8E4[5];
extern void *lbl_8049D8F8[5];
extern void *lbl_8049D90C[5];
extern void *lbl_8049D920[5];
extern void *lbl_8049D934[5];
extern void *lbl_8049D948[5];
extern void *lbl_8049D95C[5];
extern void *lbl_8049D970[5];
extern void *lbl_8049D984[5];
extern void *lbl_8049DC28[20];
void *lbl_8049CBA8[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CBE8[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CC38[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CC78[36] = {
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
void *lbl_8049CD08[24] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xc, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CD68[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CD88[16] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CDC8[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CDE8[16] = {
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CE28[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CE78[28] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x9, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CEE8[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CF38[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CF78[24] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x9, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049CFD8[12] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x3e800000,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x3e800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D008[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3ee66666, (void *)0xbee66666,
    (void *)0x2, (void *)0x3f800000, (void *)0xbee66666, (void *)0x3ee66666,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D038[20] = {
    (void *)0x1, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x2, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x3, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0x4, (void *)0x3dcccccd, (void *)0x0, (void *)0x3f35c28f,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D088[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D0C8[12] = {
    (void *)0x6, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0x7, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D0F8[20] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D148[32] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xc, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xf, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x10, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D1C8[36] = {
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
void *lbl_8049D258[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x3ee66666, (void *)0xbee66666,
    (void *)0x2, (void *)0x3f800000, (void *)0xbee66666, (void *)0x3ee66666,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D288[12] = {
    (void *)0x2, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D2B8[20] = {
    (void *)0x6, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0xa, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xb, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D308[20] = {
    (void *)0x6, (void *)0x3f800000, (void *)0x3f000000, (void *)0x0,
    (void *)0x7, (void *)0x3f99999a, (void *)0x3f333333, (void *)0x0,
    (void *)0xa, (void *)0xbf800000, (void *)0x3f000000, (void *)0x0,
    (void *)0xb, (void *)0xbf99999a, (void *)0x3f333333, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D358[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D378[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D398[12] = {
    (void *)0x6, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0x7, (void *)0x0, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D3C8[20] = {
    (void *)0x1, (void *)0xbf800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x2, (void *)0xbf800000, (void *)0x3e800000, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0xbe800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D418[16] = {
    (void *)0x3, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x4, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x5, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D458[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D478[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D4B8[24] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x5, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D518[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D558[12] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0xbf800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D588[8] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D5A8[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D5E8[20] = {
    (void *)0x1, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x2, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x3, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0x4, (void *)0x3f800000, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049D638[16] = {
    (void *)0x6, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x7, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x8, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *hair_bone_rotation_desc_00[5] = {
    (void *)0xa00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CBA8,
};
void *hair_bone_rotation_desc_01[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CBE8,
};
void *hair_bone_rotation_desc_02[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CC38,
};
void *hair_bone_rotation_desc_03[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CC78,
};
void *hair_bone_rotation_desc_04[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CD08,
};
void *hair_bone_rotation_desc_05[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CD68,
};
void *hair_bone_rotation_desc_06[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CD88,
};
void *hair_bone_rotation_desc_07[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CDC8,
};
void *lbl_8049D718[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CDE8,
};
void *lbl_8049D72C[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CE28,
};
void *lbl_8049D740[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CE78,
};
void *lbl_8049D754[5] = {
    (void *)0x280, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CEE8,
};
void *lbl_8049D768[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CF38,
};
void *lbl_8049D77C[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CF78,
};
void *lbl_8049D790[5] = {
    (void *)0x800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049CFD8,
};
void *lbl_8049D7A4[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D008,
};
void *lbl_8049D7B8[5] = {
    (void *)0x1400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D038,
};
void *lbl_8049D7CC[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D088,
};
void *lbl_8049D7E0[5] = {
    (void *)0xc00, (void *)0x1400, (void *)0x1800, (void *)0x3f733333,
    (void *)&lbl_8049D0C8,
};
void *lbl_8049D7F4[5] = {
    (void *)0xa00, (void *)0x1800, (void *)0x3800, (void *)0x3f733333,
    (void *)&lbl_8049D0F8,
};
void *lbl_8049D808[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D148,
};
void *lbl_8049D81C[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D1C8,
};
void *lbl_8049D830[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D258,
};
void *lbl_8049D844[5] = {
    (void *)0x600, (void *)0xa00, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D288,
};
void *lbl_8049D858[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D2B8,
};
void *lbl_8049D86C[5] = {
    (void *)0x400, (void *)0x1800, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D308,
};
void *lbl_8049D880[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D358,
};
void *lbl_8049D894[5] = {
    (void *)0x800, (void *)0x1400, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D378,
};
void *lbl_8049D8A8[5] = {
    (void *)0x340, (void *)0x1400, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D398,
};
void *lbl_8049D8BC[5] = {
    (void *)0x1800, (void *)0x1000, (void *)0x2000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D3C8,
};
void *lbl_8049D8D0[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D418,
};
void *lbl_8049D8E4[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D458,
};
void *lbl_8049D8F8[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f99999a,
    (void *)&lbl_8049D478,
};
void *lbl_8049D90C[5] = {
    (void *)0x200, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D4B8,
};
void *lbl_8049D920[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D518,
};
void *lbl_8049D934[5] = {
    (void *)0xc00, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D558,
};
void *lbl_8049D948[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D588,
};
void *lbl_8049D95C[5] = {
    (void *)0x300, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D5A8,
};
void *lbl_8049D970[5] = {
    (void *)0x400, (void *)0x1000, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049D5E8,
};
void *lbl_8049D984[5] = {
    (void *)0x600, (void *)0x1000, (void *)0x2000, (void *)0x3f99999a,
    (void *)&lbl_8049D638,
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
    (void *)0x6ff00ff, (void *)&lbl_8049D718, (void *)0x0, (void *)0x0,
    (void *)0x602ffff, (void *)&lbl_8049D72C, (void *)0x0, (void *)0x0,
    (void *)0x603ffff, (void *)&lbl_8049D740, (void *)0x0, (void *)0x0,
    (void *)0x6ff03ff, (void *)&lbl_8049D754, (void *)0x0, (void *)0x0,
    (void *)0x6ff05ff, (void *)&lbl_8049D768, (void *)0x0, (void *)0x0,
    (void *)0x6ff06ff, (void *)&lbl_8049D77C, (void *)0x0, (void *)0x0,
    (void *)0x609ffff, (void *)&lbl_8049D790, (void *)0x0, (void *)0x0,
    (void *)0x701ffff, (void *)&lbl_8049D7A4, (void *)0x0, (void *)0x0,
    (void *)0x7ff05ff, (void *)&lbl_8049D7B8, (void *)0x0, (void *)0x0,
    (void *)0x7ff07ff, (void *)&lbl_8049D7CC, (void *)0x0, (void *)0x0,
    (void *)0x709ffff, (void *)&lbl_8049D7E0, (void *)0x0, (void *)0x0,
    (void *)0x800ffff, (void *)&lbl_8049D7F4, (void *)0x0, (void *)0x0,
    (void *)0x8ff00ff, (void *)&lbl_8049D808, (void *)0x0, (void *)0x0,
    (void *)0x8ff03ff, (void *)&lbl_8049D81C, (void *)0x0, (void *)0x0,
    (void *)0x805ffff, (void *)&lbl_8049D830, (void *)0x0, (void *)0x0,
    (void *)0x806ffff, (void *)&lbl_8049D844, (void *)0x0, (void *)0x0,
    (void *)0x8ff06ff, (void *)&lbl_8049D858, (void *)0x0, (void *)0x0,
    (void *)0x809ffff, (void *)&lbl_8049D86C, (void *)0x0, (void *)0x0,
    (void *)0x9ffff00, (void *)&lbl_8049D880, (void *)0x0, (void *)0x0,
    (void *)0x9ffff02, (void *)&lbl_8049D894, (void *)0x0, (void *)0x0,
    (void *)0xa02ffff, (void *)&lbl_8049D8A8, (void *)0x0, (void *)0x0,
    (void *)0xa03ffff, (void *)&lbl_8049D8BC, (void *)0x0, (void *)0x0,
    (void *)0xaff05ff, (void *)&lbl_8049D8D0, (void *)0x0, (void *)0x0,
    (void *)0xaff07ff, (void *)&lbl_8049D8E4, (void *)0x0, (void *)0x0,
    (void *)0xa08ffff, (void *)&lbl_8049D8F8, (void *)0x0, (void *)0x0,
    (void *)0xaff09ff, (void *)&lbl_8049D90C, (void *)0x0, (void *)0x0,
    (void *)0xbff01ff, (void *)&lbl_8049D920, (void *)0x0, (void *)0x0,
    (void *)0xbff03ff, (void *)&lbl_8049D934, (void *)0x0, (void *)0x0,
    (void *)0xbff04ff, (void *)&lbl_8049D948, (void *)0x0, (void *)0x0,
    (void *)0xbff06ff, (void *)&lbl_8049D95C, (void *)0x0, (void *)0x0,
    (void *)0xbff07ff, (void *)&lbl_8049D970, (void *)0x0, (void *)0x0,
    (void *)0xb09ffff, (void *)&lbl_8049D984, (void *)0x0, (void *)0x0,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8049DC28[20] = {
    (void *)0x1, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x2, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x3, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0x4, (void *)0x3f000000, (void *)0x0, (void *)0x3f800000,
    (void *)0xffffffff, (void *)0x0, (void *)0x0, (void *)0x3e800000,
};
void *hair_bone_rotation_descriptor[5] = {
    (void *)0x400, (void *)0xc00, (void *)0x1000, (void *)0x3f8ccccd,
    (void *)&lbl_8049DC28,
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
