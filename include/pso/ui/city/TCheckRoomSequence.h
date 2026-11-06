#ifndef PSO_UI_CITY_TCHECKROOMSEQUENCE_H
#define PSO_UI_CITY_TCHECKROOMSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TCheckRoomSequence : public TShopSequence {
    virtual ~TCheckRoomSequence();
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    void set_ready_flag();
    void set_position(f32 a, f32 b);
    static int get_room_data(int a0);
    static int get_room_table_entry(int a0);
    static void *create(void *arg0);
    static s32 get_item_def(u32 arg0);
    u8 unk_30[0x1C];
};

typedef char TCheckRoomSequence_size[sizeof(TCheckRoomSequence) == 0x4C ? 1 : -1];
#endif
