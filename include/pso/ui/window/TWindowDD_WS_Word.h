#ifndef PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#define PSO_UI_WINDOW_TWINDOWDD_WS_WORD_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TUnk_804CFA28;

struct TWindowDDWordEntryList {
    u32 count;
    TUnk_804CFA28 **items;
};

class TWindowDD_WS_Word : public TWindowBase {
public:
    virtual ~TWindowDD_WS_Word();
    virtual void render();
    s32 sub_80341AC0();
    s32 can_scroll(s32);
    void *destroy(s16);
    s32 sub_80342268();
    s32 sub_80342254();
    s32 m_60;
    s32 pad_64; // point table index for the strips; 0 also picks the first v range
    s32 m_68;
    s32 m_6c;
    s32 pad_70; // element list id, read by load_element_list
    s32 m_74;
    s32 pad_78; // visible row count
    s32 m_7c;
    void * m_80;
    f32 pad_84;
    f32 pad_88; // scroll offset (fraction of a 20-unit row drawn as partial strips)
    s32 m_8c;
};
struct WindowDrawContext;

extern "C" {
void TWindowDD__sub_80341674(TWindowDD_WS_Word *self, WindowDrawContext *rect);
}

LAYOUT_ASSERT(TWindowDD_WS_Word_size, sizeof(TWindowDD_WS_Word) == 0x90);

#endif
