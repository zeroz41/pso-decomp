#ifndef PSO_MISC_TUNK_804CF918_H
#define PSO_MISC_TUNK_804CF918_H

#include "types.h"

class TWindowKeyBoardSoft;

class TUnk_804CF918 {
public:
    u8 unk_0[2];
    s16 m_2;

    virtual ~TUnk_804CF918();
    virtual void update();
    virtual void render(TWindowKeyBoardSoft *context);
    virtual void calc_bar_width() = 0;
};

typedef char TUnk_804CF918_size[sizeof(TUnk_804CF918) == 8 ? 1 : -1];

#endif
