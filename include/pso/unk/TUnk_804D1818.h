#ifndef PSO_UNK_TUNK_804D1818_H
#define PSO_UNK_TUNK_804D1818_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804D1818 : public TObject {
public:
    virtual ~TUnk_804D1818();
    void update_photon_selection();
    void *dt(s16);
    s32 create_option_menu_window();
    s32 sub_8027C884(s32);
    void update_quest_board_card_flags();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1];
    u8 m_1d;
    u8 unk_1E[0x2];
    s32 m_20;
    void * m_24;
    u8 unk_28[0x4];
    u32 m_2c;
};
typedef char TUnk_804D1818_size[sizeof(TUnk_804D1818) == 0x30 ? 1 : -1];

#endif
