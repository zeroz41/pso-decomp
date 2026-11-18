#ifndef PSO_PLAYER_TUNK_804CCC68_H
#define PSO_PLAYER_TUNK_804CCC68_H
#include "types.h"
#include "pso/effect/TEffect.h"

struct TechniqueContactActor;
struct TechniqueContactBody;

class TUnk_804CCC68 : public TEffect {
public:
    TUnk_804CCC68(s32 arg1, u8 *arg2, u8 *arg3, s32 arg4);
    virtual ~TUnk_804CCC68();
    void check_technique_projectile_wall_hit();
    void move_technique_projectile();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_6();
    virtual void debug_print_tech_params();
    virtual void vfunc_8(void *);
    void advance_lifetime_or_destroy();
    void dispatch_all_technique_contacts();
    void dispatch_technique_contact();
    u8 *query_technique_player_contacts(s32);
    u8 *query_technique_enemy_contacts(s32);
    f32 range;
    f32 traveled;
    f32 previous[3];
    u8 beforeLevel[0x40];
    s16 level;
    s16 band;
    u16 sourceId;
    u8 unk_CA[0x2];
    f32 power;
    u8 parameters[0x28];
    TechniqueContactBody* contact;
    u8 beforeProxy[0x2c];
    TechniqueContactActor* proxy;
    f32 halfWidth;
};

extern "C" {
// TUnk_804CCC68::~TUnk_804CCC68(), called by the destructors that are still written by hand.
void *__dt__13TUnk_804CCC68Fv(void *p, s16 flags);
}

#endif
