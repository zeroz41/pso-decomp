#ifndef PSO_ITEM_TITEMPROSHIELD_H
#define PSO_ITEM_TITEMPROSHIELD_H

#include "types.h"
#include "pso/item/TItemEquipBase.h"

struct TItem;
struct TItemData;
struct TechniqueBoostParam;

// A shield's ItemPMT record (lookup_item_pmt_record), the fields this class
// reads.
struct ShieldPmtEntry {
    u8 pad_0[0xD];
    s8 block_effect;     // index into TItemProShield::shield_table
    u8 pad_e[0x8];
    u8 evp_range;        // the largest EVP bonus the item keeps
    u8 dfp_range;        // the largest DFP bonus the item keeps
    u8 pad_18;
    u8 technique_boost;  // TObjPlayer::get_shield_pmt_entry's index
    u8 model_type;       // 1 refreshes the owner's stats, 3 draws two models
};

// One entry of ItemShieldEntry.dat (byte-swapped by load_data).
struct ShieldEffectEntry {
    u32 words[11];
};

// TItemProShield::shield_flags bits.
enum {
    SHIELD_FLAG_BLOCK_RECOVERY = 0x1, // a block restores HP (and TP)
    SHIELD_FLAG_EFFECT_RENDER = 0x2,  // drawn inside the particle effect pass
    SHIELD_FLAG_REFRESH_STATS = 0x4,  // update_equipped refreshes the owner's stats
    SHIELD_FLAG_TWO_MODELS = 0x8,     // drawn at two joints, the second model at the other
};

// An equipped shield: the DFP/EVP bonuses kept in its item data, its
// technique boosts and the effect a block plays.
struct TItemProShield : public TItemEquipBase {
    TItemProShield(TObject *parent, u8 *item);
    virtual ~TItemProShield();
    virtual void update_owned();
    virtual void update_equipped();
    virtual void write_item_data(TItemData *data);
    virtual void render_equipped();
    virtual void perform_action();
    virtual void on_equip();
    virtual void on_unequip();
    virtual void request_equipped_model();
    // Called first by update_equipped; nothing to do for a shield.
    virtual void on_update_equipped();

    // Copies what an item of this class keeps when it is replaced by a new
    // item code (replace_item_with_new_code) into the new item's data.
    static void carry_over_stats(TItemData *data, TItem *item);
    // The shield entry of construct_item's table: NULL without data.
    static TItem *create(u8 *item);
    // The shield entries of the item class load/unload table.
    static void free();
    static void load_data();
    static void create_shield_effect(s32 parent, u16 client, u32 entry);
    // Sets the attach joint and shield_flags the item index and the PMT
    // model type ask for.
    void apply_shield_effect_flags();
    // Draws item_model at the owner's joint.
    void draw_at_joint(s32 joint);
    s16 get_field_2b8();

    static ShieldEffectEntry *shield_table;

    ShieldPmtEntry *pmt;
    ShieldEffectEntry *effect_entry;
    const TechniqueBoostParam *technique_boosts;
    u8 dfp_bonus;
    u8 evp_bonus;
    u8 dfp_range;
    u8 evp_range;
    u32 shield_flags;
};

typedef char TItemProShield_size[sizeof(TItemProShield) == 0x1A0 ? 1 : -1];
#endif
