#ifndef PSO_BOSS_TUNK_80481B34_H
#define PSO_BOSS_TUNK_80481B34_H
#include "types.h"
#include "pso/player/TUnk_804928CC.h"

class TUnk_80481B34 : public TUnk_804928CC {
public:
    virtual ~TUnk_80481B34();
    virtual void apply_hit_if_active(void *, f32 *);
    virtual void area_attack_receive_direct(void *, f32 *, void *);
    void *init_base();
};
typedef char TUnk_80481B34_size[sizeof(TUnk_80481B34) == 0xB0 ? 1 : -1];

#endif
