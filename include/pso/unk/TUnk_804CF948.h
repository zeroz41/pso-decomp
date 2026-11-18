#ifndef PSO_UNK_TUNK_804CF948_H
#define PSO_UNK_TUNK_804CF948_H
#include "types.h"
#include "pso/unk/TUnk_804CF930.h"

class TUnk_804CF948 : public TUnk_804CF930 {
public:
    virtual ~TUnk_804CF948();
    virtual void update();
    virtual void render(TWindowKeyBoardSoft *context);
    virtual void calc_bar_width();

    s16 shown;
    s16 timer;
    s32 m_2c;
    u8 unk_30[0x30];
    s32 m_60;
    s32 m_64;
};

typedef char TUnk_804CF948_size[sizeof(TUnk_804CF948) == 0x68 ? 1 : -1];

#endif
