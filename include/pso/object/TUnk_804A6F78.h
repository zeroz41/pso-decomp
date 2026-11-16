#ifndef PSO_OBJECT_TUNK_804A6F78_H
#define PSO_OBJECT_TUNK_804A6F78_H
#include "types.h"
#include "pso/object/TUnk_804A6FC0.h"

class TUnk_804A6F78 : public TUnk_804A6FC0 {
public:
    TUnk_804A6F78(TObject *parent);
    virtual void render();
    virtual ~TUnk_804A6F78();
};
typedef char TUnk_804A6F78_size[sizeof(TUnk_804A6F78) == 0x1C ? 1 : -1];

#endif
