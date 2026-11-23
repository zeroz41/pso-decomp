#ifndef PSO_UNK_TUNK_804D1160_H
#define PSO_UNK_TUNK_804D1160_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;

class TUnk_804D1160 : public TObject {
public:
    TUnk_804D1160(TWindowMainMenu *parent, s32 client);
    virtual ~TUnk_804D1160();
    void update_customize_help_text(void *);
    virtual void render();
    virtual void run_task();
    s8 state;
    u8 pad_1D[0x3];
    s32 m_20;
    TWindowMainMenu *main_menu;
    uaddr m_28;
    uaddr m_2c;
    uaddr m_30;
    s16 help_kind;
    s16 help_id;
};
LAYOUT_ASSERT(TUnk_804D1160_size, sizeof(TUnk_804D1160) == 0x38);

#endif
