#ifndef PSO_UI_FRONTEND_TADCHRSELSLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELSLOTGC_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>

struct CharacterSlotQuad { f32 left, top, right, bottom, u0, v0, u1, v1; };
struct CharacterSlotPosition { f32 x, y; };
class TAdChrSelSlotGC : public TObject {
public:
    TAdChrSelSlotGC(TObject*_w1);
    virtual ~TAdChrSelSlotGC();
    virtual void run_task();
    virtual void render();
    s32 frame;
    CharacterSlotQuad quads[5];
    CharacterSlotPosition positions[5];
    u32 alpha[5];
    u32 colors[5];
    s32 visible[5];
    s32 enabled;
public:
    void draw_slot_icons();
    void reset_all_slots();
    void init_slot_entry(s32 arg1, void *arg2);
};
typedef char SlotQuadsOffset[offsetof(TAdChrSelSlotGC, quads) == 0x20 ? 1 : -1];
typedef char SlotPositionsOffset[offsetof(TAdChrSelSlotGC, positions) == 0xC0 ? 1 : -1];
typedef char SlotAlphaOffset[offsetof(TAdChrSelSlotGC, alpha) == 0xE8 ? 1 : -1];
typedef char SlotColorsOffset[offsetof(TAdChrSelSlotGC, colors) == 0xFC ? 1 : -1];
typedef char SlotVisibleOffset[offsetof(TAdChrSelSlotGC, visible) == 0x110 ? 1 : -1];
typedef char SlotObjectSize[sizeof(TAdChrSelSlotGC) == 0x128 ? 1 : -1];

extern "C" {
void TLobby__sub_802C78EC(void);
void TLobby__sub_802C7920(void);
void *__dt__13TUnk_804E0B28Fv(void *arg0, s16 arg1);
}

#endif
