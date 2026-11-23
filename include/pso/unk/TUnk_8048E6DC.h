#ifndef PSO_UNK_TUNK_8048E6DC_H
#define PSO_UNK_TUNK_8048E6DC_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// Map object 0x001E: the screen glare of a light source at its position (particle definition 31), larger the
// more the camera faces it and dimmed while the map hides it. scale.x picks the tint (below 0 grey, 10 and up
// dark orange, orange otherwise).
class TUnk_8048E6DC : public TObjBase {
public:
    TUnk_8048E6DC(void *set_data, TObject *parent);
    virtual ~TUnk_8048E6DC();
    virtual void render();
    virtual void run_task();
    // The object factory entry; none in split screen.
    static void *create(void *set_data);
    f32 glare_size;          // 0x90, 25 to 55: half the sprite size in definition units
    f32 facing;              // 0x94, dot of the camera's forward axis and the direction to the glare
    s32 occluded;            // 0x98, the map lies between the camera and the glare
    f32 screen_position[2];  // 0x9C
    f32 alpha;               // 0xA4, eases towards 225 (50 while occluded)
    u8 pad_A8[4];
};
LAYOUT_ASSERT(TUnk_8048E6DC_size, sizeof(TUnk_8048E6DC) == 0xAC);

// The glares draw only while this is set; TUnk_8048E6A8 switches it.
extern s32 light_glare_enabled;

#endif
