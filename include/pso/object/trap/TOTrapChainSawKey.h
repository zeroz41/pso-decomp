#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAWKEY_H

#include "types.h"
#include "pso/object/trap/TOTrapChainSaw.h"

struct AnimationMotion;
struct NJS_OBJECT;

struct TOTrapChainSawKey : public TOTrapChainSaw {
    TOTrapChainSawKey(TObject *parent, void *set_data);
    virtual ~TOTrapChainSawKey();
    virtual void update_state();
    virtual void decode_params();
    virtual void vfunc_16();
    virtual void vfunc_18(TObjPlayer *player);
    virtual void vfunc_14();
    virtual void vfunc_25();
    virtual void check_player_contact();
    virtual void vfunc_27();
    u32 m_f8;
    u32 m_fc;
    u32 m_100;
    static void *create(void *set_data);
    static AnimationMotion *get_motion(s32 index);
    static NJS_OBJECT *get_model(s32 index);
    u8 unk_104[0x8];
};

LAYOUT_ASSERT(TOTrapChainSawKey_size, sizeof(TOTrapChainSawKey) == 0x10C);
#endif
