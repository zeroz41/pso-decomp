#ifndef PSO_ITEM_TITEMPROARMOR_H
#define PSO_ITEM_TITEMPROARMOR_H

#include "types.h"
#include "pso/item/TItemEquipBase.h"

struct TItem;
struct TItemData;

// An armor's ItemPMT record (lookup_item_pmt_record), the fields this class
// reads.
struct ArmorPmtEntry {
    u8 pad_0[0x16];
    u8 dfp_range;   // the largest DFP bonus the item keeps
    u8 evp_range;   // the largest EVP bonus the item keeps
    u8 pad_18[0x2];
    u8 model_type;  // 1 refreshes the owner's stats, 2 is a TItemProArmorParticle
};

// TItemProArmor::armor_flags bits.
enum {
    ARMOR_FLAG_REFRESH_STATS = 0x1, // update_equipped refreshes the owner's stats
};

// The most slots an armor can have.
#define ARMOR_MAX_SLOTS 4

// An equipped armor (frame): the DFP/EVP bonuses and the slot count kept in
// its item data, and the timer effect some armors start on their owner.
struct TItemProArmor : public TItemEquipBase {
    TItemProArmor(TObject *parent, u8 *item);
    virtual ~TItemProArmor();
    virtual void update_owned();
    virtual void update_equipped();
    virtual void write_item_data(TItemData *data);
    virtual u8 get_slot_count();
    virtual void add_slot();
    virtual void on_equip();
    // Plays the owner's appearance effect instead of loading a model.
    virtual void request_equipped_model();

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    // The armor entry of construct_item's table: a TItemProArmor or, for the
    // PMT model type 2, a TItemProArmorParticle; NULL without data.
    static TItem *create(u8 *item);
    // The armor entries of the item class load/unload table: nothing to do.
    static void free();
    static void load_data();
    // Sets the effect_flags and armor_flags the item index and the PMT
    // model type ask for.
    void apply_armor_effect_flags();

    ArmorPmtEntry *pmt;
    u16 armor_flags;   // ARMOR_FLAG_*
    u8 slot_count;     // data1 byte 5, at most ARMOR_MAX_SLOTS
    u8 dfp_bonus;
    u8 evp_bonus;
    u8 dfp_range;
    u8 evp_range;
};

typedef char TItemProArmor_size[sizeof(TItemProArmor) == 0x198 ? 1 : -1];
#endif
