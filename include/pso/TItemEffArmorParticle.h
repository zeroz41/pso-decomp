#ifndef PSO_TITEMEFFARMORPARTICLE_H
#define PSO_TITEMEFFARMORPARTICLE_H

#include "pso/TObject.h"
#include "types.h"

class TItemEffArmorParticle : public TObject {
public:
 s32 m_item_id;
 void* m_20;
 u16 m_player_id;
 u8 _pad26[2];
 u32 m_item_ctrl;

    TItemEffArmorParticle(TObject *parent, s32 item_id, u16 client, s32 particle);
    virtual ~TItemEffArmorParticle();
    virtual void run_task();
};

#endif
