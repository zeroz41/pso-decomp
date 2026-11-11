#include "types.h"
#include "pso/unk/TUnk_804F1C58.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_8035A860.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void mem_free(void *);

struct RecoveredGlobal_8035A860_lbl_804F1C58 {
    s32 value;
    u8 remaining[0x14];
};
extern RecoveredGlobal_8035A860_lbl_804F1C58 lbl_804F1C58;
typedef char RecoveredGlobal_8035A860_lbl_804F1C58_size[sizeof(RecoveredGlobal_8035A860_lbl_804F1C58) == 0x18 ? 1 : -1];

void *TUnk_804F1C58::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = &lbl_804F1C58.value;
        mem_free(*(void * *)&(this->m_28));
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}


extern "C" {
void *mem_alloc(u32 size);
s32 __ct__7TObjectFP7TObject(void *, void *);
u8 *fn_8035A860(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_804F1C58.value;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    ((TUnk_804F1C58 *)arg0)->m_20 = 0;
    *(f32 *)((s8 *)arg0 + 0x24) = 0.0f;
    ((TUnk_804F1C58 *)arg0)->m_30 = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = ((TObjBoss2Tunnel *)arg2)->count_tree_nodes();
    *(s32 *)((s8 *)arg0 + 0x28) = (s32)mem_alloc((*(s32 *)((s8 *)arg0 + 0x2C) * 0x30));
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    ((TUnk_804F1C58 *)arg0)->m_38 = 0;
    return arg0;
}
}
