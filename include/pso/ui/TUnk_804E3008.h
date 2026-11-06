#ifndef PSO_UI_TUNK_804E3008_H
#define PSO_UI_TUNK_804E3008_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804E3008 : public TObjMotion {
public:
    virtual ~TUnk_804E3008();
    void sub_802E0CB0();
    void sub_802E0784();
    void set_cursor_index(s32);
    virtual void run_task();
    void *init_player(void *, void *, void *, void *);
    void sub_802E0F58(s32);
    u8 unk_FC[0x4];
    s32 m_100;
    u8 unk_104[0x4];
    void * m_108;
    u8 unk_10C[0x4];
    s32 m_110;
    u8 unk_114[0x3D];
    u8 m_151;
    u8 unk_152[0x2];
    s32 m_154;
    u8 unk_158[0x18];
    s32 m_170;
};
typedef char TUnk_804E3008_size[sizeof(TUnk_804E3008) == 0x174 ? 1 : -1];

#endif
