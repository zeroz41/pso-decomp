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
    u8 sub_80342268();
    s32 sub_80342254();
    u8 unk_1C[0x8];
    TWindowDDWordEntryList entries;
    u8 unk_2C[0x14];
    f32 pad_40; // window rectangle x, y, w, h (read by the strip draw 0x80341674)
    f32 pad_44;
    f32 pad_48;
    f32 pad_4C;
    u8 pad_50[0x4];
    f32 pad_54; // depth: fed to the depth helper TWindowDD__sub_80348AD4
    u8 pad_58[0x8];
    s32 m_60;
    s32 pad_64; // point table index for the strips; 0 also picks the first v range
    s32 m_68;
    s32 m_6c;
    u8 unk_70[0x4];
    s32 m_74;
    s32 pad_78; // visible row count
    s32 m_7c;
    void * m_80;
    u8 unk_84[0x4];
    f32 pad_88; // scroll offset (fraction of a 20-unit row drawn as partial strips)
    s32 m_8c;
};
class TWindowKeyBoardSoft;

extern "C" {
void TWindowDD__sub_80341674(TWindowDD_WS_Word *self, TWindowKeyBoardSoft *rect);
}

typedef char TWindowDD_WS_Word_size[sizeof(TWindowDD_WS_Word) == 0x90 ? 1 : -1];

#endif
