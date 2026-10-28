#ifndef PSO_ITEM_TITEMOBJECT_H
#define PSO_ITEM_TITEMOBJECT_H

#include "types.h"

struct TItem;
struct TItemData;
#include <stddef.h>
#include "pso/item/TItem.h"

struct TItemObject : public TItem {
    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    virtual ~TItemObject();
    virtual s32 remove_amount(s32 count);
    virtual s32 add_amount(s32 count);
    virtual void vfunc_44();
    virtual void update_owned();
    virtual s32 get_amount();
    virtual void use();
    u8 get_tool_pmt_amount_byte();
    u8 sub_80115D7C();
    void*vfunc_9();
    void store_encoded_value(s32 value);
    u32 m_f8;
    s32 encoded_value;
    u8 m_100;
    u8 m_101;
    u8 *create();
    static s32 call_dispatch(s32 arg0);
};

typedef char ItemObjectDataOffset[(offsetof(TItemObject, m_f8) == 0xF8) ? 1 : -1];
typedef char ItemObjectEncodedValueOffset[(offsetof(TItemObject, encoded_value) == 0xFC) ? 1 : -1];
typedef char ItemObjectTypeOffset[(offsetof(TItemObject, m_100) == 0x100) ? 1 : -1];

#endif
