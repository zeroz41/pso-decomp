#ifndef PSO_OBJECT_WARP_TOBJWARPSTRING_H
#define PSO_OBJECT_WARP_TOBJWARPSTRING_H
#include "pso/system/task/TObject.h"
#include "types.h"

// The warp id text ("%xF") a forced map warp shows: fades in, holds, fades out.
class TObjWarpString : public TObject {
public:
    static const char *class_name;
    TObjWarpString(TObject *parent, char *text, u16 client_id);
    virtual ~TObjWarpString();
    void delay_before_fade_in();
    void update_fade_in();
    void delay_before_fade_out();
    void fade_and_destroy();
    virtual void run_task();
    virtual void render();

    char text[0x20];
    s32 pad_3C;  // set to -1 by the ctor
    s32 timer;
    f32 alpha;
    u16 client_id;
    s32 state;
};
LAYOUT_ASSERT(TObjWarpStringSize, sizeof(TObjWarpString) == 0x50);

TObjWarpString *create_TObjWarpString(char *text, u16 client_id);

#endif
