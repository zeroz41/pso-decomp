#ifndef PSO_UI_TUNK_804E3008_H
#define PSO_UI_TUNK_804E3008_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TAdPlyStatusGC;

// One player model of the multi-player character select; get_or_create_player
// keeps them in multi_chr_select_player_slot_table.
class TUnk_804E3008 : public TObjMotion {
public:
    TUnk_804E3008(TObject *parent, s32, s32, s32 slot);
    virtual ~TUnk_804E3008();
    void sub_802E0CB0();
    void sub_802E0784();
    void set_cursor_index(s32);
    virtual void run_task();
    virtual void render();
    void update_chara_making();
    void draw_model_with_arg(void *model);
    void sub_802E0F58(s32);
    s32 state;  // run_task switches on it; render draws in state 3
    s32 m_100;
    u8 pad_104[0x4];
    s32 m_108;
    s32 slot;  // its index in multi_chr_select_player_slot_table
    s32 m_110;
    u8 pad_114[0xC];
    u8 visual_record[0x31];  // copy_player_visual_record fills it
    u8 m_151;
    u8 pad_152[0x2];
    s32 m_154;
    u8 pad_158[0x18];
    TAdPlyStatusGC *m_170;
};
extern TUnk_804E3008 *multi_chr_select_player_slot_table[4];
typedef char TUnk_804E3008_size[sizeof(TUnk_804E3008) == 0x174 ? 1 : -1];

#endif
