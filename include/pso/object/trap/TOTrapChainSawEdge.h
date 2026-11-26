#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWEDGE_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWEDGE_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct TOTrapChainSawEdge : public TOTrapChainSaw {
    TOTrapChainSawEdge(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawEdge();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void vfunc_25();
    virtual void vfunc_16();
    virtual void check_player_contact();
    s32 extent;         // the extent of the current move (max_offset when a start is taken)
    s32 variant;        // scale.z clamped to 0-1: which model and motion
    s32 pending_starts; // starts queued by the damage saw (TOTrapChainSawDamage tick 5 / 10)
    s32 phase;          // 0 waiting for a start, 1 moving
};

LAYOUT_ASSERT(TOTrapChainSawEdge_size, sizeof(TOTrapChainSawEdge) == 0x108);

class TObjPlayer;
struct TOTrapChainSawDamage;
struct NJS_TEXLIST;
struct NJS_OBJECT;

extern "C" {
void update_state__20TOTrapChainSawDamageFv(void *arg0);
void update_state__17TOTrapChainSawKeyFv(u8 *arg0);
u8 *__ct__14TOTrapChainSawFP7TObjectPv(u8 *arg0, s32 arg1, s32 arg2);
void TParticleCtrl__sub_802C8464(NJS_OBJECT *arg0);
void *__dt__14TOTrapChainSawFv(void *object, s16 delete_flag);
void update_state__14TOTrapChainSawFv(u8 *arg0);
}

// The unit's C-named helpers (formerly the text_802C9924 / text_802C99D8 /
// TOTrapChainSawDamage_802C9BF8 sub files).
extern "C" {
NJS_TEXLIST *fn_802C9924(s32 index);
void TOTrapChainSawDamage__sub_802C9C00(u8 *arg0, s32 arg1);
}

#endif
