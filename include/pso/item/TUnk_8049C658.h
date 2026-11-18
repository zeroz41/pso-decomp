#ifndef PSO_ITEM_TUNK_8049C658_H
#define PSO_ITEM_TUNK_8049C658_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8049C658 : public TObject {
public:
    virtual ~TUnk_8049C658();
    void *construct();
    void *ct_object();
    u8 unk_1C[0x20];
};
typedef char TUnk_8049C658_size[sizeof(TUnk_8049C658) == 0x3C ? 1 : -1];

extern "C" {
// TUnk_8049C658::~TUnk_8049C658(), called by the destructors that are still written by hand.
void *__dt__13TUnk_8049C658Fv(void *p, s16 flags);
}

#endif
