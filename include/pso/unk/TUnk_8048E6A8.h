#ifndef PSO_UNK_TUNK_8048E6A8_H
#define PSO_UNK_TUNK_8048E6A8_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// Map object 0x01A8: turns the light glares on (scale.x above 0) or off when the local player comes within 20
// units; drawn as a sphere in demo mode.
class TUnk_8048E6A8 : public TObjBase {
public:
    TUnk_8048E6A8(void *set_data, TObject *parent);
    virtual ~TUnk_8048E6A8();
    virtual void render();
    virtual void run_task();
    // The object factory entry; none in split screen.
    static void *create(void *set_data);
};
LAYOUT_ASSERT(TUnk_8048E6A8_size, sizeof(TUnk_8048E6A8) == 0x90);

#endif
