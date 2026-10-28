#ifndef PSO_ITEM_TITEMOBJECT_H
#define PSO_ITEM_TITEMOBJECT_H

#include "types.h"
#include <stddef.h>
#include "pso/item/TItem.h"

struct TItemData;

// A tool's ItemPMT entry (lookup_item_pmt_record).
struct ItemToolPmt {
    u32 id;
    s16 type;       // ground model - 4, 0 for the default one
    s16 skin;
    u16 amount;     // what using it gives (HP restored, grinds added, ...)
    s16 technique;
    s32 cost;
    u32 flags;      // bit 0: used up when used (ITEM_FLAG_CONSUMABLE)
};

// A tool: a stackable item used from the inventory. Each kind of tool is a
// subclass whose apply_use_effect does what using it does.
struct TItemObject : public TItem {
    TItemObject(TObject *parent, u8 *item);
    virtual ~TItemObject();
    virtual void *vfunc_9();
    virtual void update_owned();
    virtual void write_item_data(TItemData *data);
    virtual void use();
    virtual s32 get_amount();
    virtual s32 remove_amount(s32 count);
    virtual s32 add_amount(s32 count);
    // What using the tool does. use() plays the use effect and sound unless
    // this sets skip_use_feedback.
    virtual void apply_use_effect();

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    static TItemObject *create(u8 *item);
    // Builds the tool an item code names, through the tool factory table.
    static TItem *create_tool(u8 *item);
    void set_amount(s32 amount);
    u8 get_technique();
    u8 get_pmt_amount();

    ItemToolPmt *pmt;
    s32 encoded_amount;     // the stack count, xor its own address
    u8 technique;           // a technique disk's technique (item code byte 4)
    u8 skip_use_feedback;
};

typedef char ItemObjectPmtOffset[(offsetof(TItemObject, pmt) == 0xF8) ? 1 : -1];
typedef char ItemObjectAmountOffset[(offsetof(TItemObject, encoded_amount) == 0xFC) ? 1 : -1];
typedef char ItemObjectTechniqueOffset[(offsetof(TItemObject, technique) == 0x100) ? 1 : -1];
typedef char ItemObjectSize[(sizeof(TItemObject) == 0x104) ? 1 : -1];

// The action palette slot a usable tool goes to (0..12), -1 for none.
s32 get_tool_palette_index(TItem *item);

#endif
