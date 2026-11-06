#ifndef PSO_WEAPON_TUNK_804A4648_H
#define PSO_WEAPON_TUNK_804A4648_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A4648 : public TUnk_804A4948 {
public:
    TUnk_804A4648(TObject *parent, u8 *item);
    virtual ~TUnk_804A4648();
    virtual void emit_marker_effects();
};

#endif
