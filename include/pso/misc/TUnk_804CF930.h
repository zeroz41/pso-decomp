#ifndef PSO_MISC_TUNK_804CF930_H
#define PSO_MISC_TUNK_804CF930_H
#include "types.h"
#include <stddef.h>
#include "pso/misc/TUnk_804CF918.h"

class TUnk_804CF930 : public TUnk_804CF918 {
public:
    virtual ~TUnk_804CF930();
    virtual void update();
    virtual void render(TWindowKeyBoardSoft *context);
    virtual void calc_bar_width();

    f32 depth;
    f32 x;
    f32 y;
    f32 scale;
    u32 color;
    f32 width;
    f32 maximum;
    f32 target;

    void*init_from(void*, int);
    void draw_status_gauge_bar(void *, void *, f32, f32);
    void sub_80256BDC(s16);
    void *destroy(s16);
};

typedef char TUnk_804CF930_size[sizeof(TUnk_804CF930) == 0x28 ? 1 : -1];
typedef char TUnk_804CF930_target_offset[offsetof(TUnk_804CF930, target) == 0x24 ? 1 : -1];

#endif
