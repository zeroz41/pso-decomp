#ifndef PSO_PLAYER_TUNK_804B08BC_H
#define PSO_PLAYER_TUNK_804B08BC_H
#include "types.h"
#include "pso/player/TObjContainerCommon.h"

class TUnk_804B08BC : public TObjContainerCommon {
public:
    TUnk_804B08BC(void *set_data);
    virtual ~TUnk_804B08BC();
    virtual void vfunc_81();
    virtual void vfunc_80();
    virtual void vfunc_79() const;
};

#endif
