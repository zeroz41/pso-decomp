#ifndef PSO_PLAYER_TPLYITEM_H
#define PSO_PLAYER_TPLYITEM_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemList;

// The item list a TPlyItem owns at +0x20. Placeholder names: TUnk_<vtable> for the three
// list levels; Unk_801C2098 (4 bytes, ctor 0x801C2098) and Unk_801D5CB8 (0x10 bytes, ctor 0x801D5CB8)
// for the element types. The 0x1C-byte element is DeathDropRecord's layout (same ctor 0x801C2068,
// same size, see TObjPlayer::drop_items_on_death); kept as a placeholder here.
struct Unk_801C2098 {
    s32 state;
    Unk_801C2098();
};
struct Unk_801D5CB8 {
    Unk_801C2098 head;
    f32 x, y, z;
    Unk_801D5CB8();
};
struct Unk_801C2068 {
    Unk_801C2098 head;
    u8 pad_4[0x18];
    Unk_801C2068();
};
class TUnk_804C4444 {
public:
    s32 count;
    Unk_801C2098 entries[8];
    TUnk_804C4444();
    virtual ~TUnk_804C4444();
};
class TUnk_804C4450 : public TUnk_804C4444 {
public:
    Unk_801D5CB8 positions[8];
    TUnk_804C4450();
    virtual ~TUnk_804C4450();
};
class TUnk_804C445C : public TUnk_804C4450 {
public:
    Unk_801C2068 records[9];
    TUnk_804C445C();
    virtual ~TUnk_804C445C();
};
class TPlyItem : public TObject {
public:
    u16 pad_1C;
    u16 pad_1E;
    TUnk_804C445C list;
    TItemList *pad_1C4;
    TObject *pad_1C8;
    TPlyItem(TObject *parent);
    virtual ~TPlyItem();
    s32 count_items_by_id(saddr arg1);
    void remove_equipped_item(s32 player, void *node);
    s32 update_inventory_item(saddr player, s32 arg2, saddr pos, s32 arg4, s32 client);
    void *start_inventory_update(int key);
    void destroy_subobjects(int a1);
    void *set_mode_and_refresh_object(void *item_data);
    void find_first_inventory_entry(int a1);
    void set_flag_and_update(int a1);
    int apply_shop_judgment(void *owners);
    int count_matching_items(void *owners);
    int run_state_query(int a1);
    int run_and_get_result(saddr ids);
};

#endif
