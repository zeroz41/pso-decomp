#ifndef PSO_MISC_TOTRAPCHAINSAWEDGE_H
#define PSO_MISC_TOTRAPCHAINSAWEDGE_H

#include "types.h"
#include "pso/misc/TOTrapChainSaw.h"

struct TOTrapChainSawEdge : public TOTrapChainSaw {
    virtual ~TOTrapChainSawEdge();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void vfunc_25();
    virtual void vfunc_16();
    virtual int check_player_contact();
    u8 unk_F8[0x10];
};

typedef char TOTrapChainSawEdge_size[sizeof(TOTrapChainSawEdge) == 0x108 ? 1 : -1];

extern "C" {
void *TOTrapChainSawDamage__ct(void *arg0, void *arg1, void *arg2);
void TOTrapChainSawDamage__vt16(u8 *arg0, u8 *arg1);
void update_state__20TOTrapChainSawDamageFv(void *arg0);
u8 *TOTrapChainSawEdge__ct(u8 *arg0);
u8 *TOTrapChainSawKey__ct(u8 *arg0, void *_w1, void *_w2);
void update_state__17TOTrapChainSawKeyFv(u8 *arg0);
u8 *__ct__14TOTrapChainSawFP7TObjectPv(u8 *arg0, s32 arg1, s32 arg2);
void TParticleCtrl__sub_802C8464(u32 arg0);
void *__dt__14TOTrapChainSawFv(void *arg0, s16 arg1);
void *__dt__17TOTrapChainSawKeyFv(void *arg0, s16 arg1);
void *__dt__18TOTrapChainSawEdgeFv(void *arg0, s16 arg1);
void *__dt__20TOTrapChainSawDamageFv(void *arg0, s16 arg1);
s32 get_area_table_value__17TOTrapChainSawKeyFii(s32 arg0, s32 arg1);
void update_state__14TOTrapChainSawFv(u8 *arg0);
}

// The unit's C-named helpers (formerly the text_802C9924 / text_802C99D8 /
// TOTrapChainSawDamage_802C9BF8 sub files).
extern "C" {
u8 *fn_802C9924(s32 arg0);
void fn_802C99D8(void);
void TOTrapChainSawDamage__sub_802C9C00(u8 *arg0, s32 arg1);
}

#endif
