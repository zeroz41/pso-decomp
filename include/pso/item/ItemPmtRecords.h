#ifndef PSO_ITEM_ITEMPMTRECORDS_H
#define PSO_ITEM_ITEMPMTRECORDS_H

#include "types.h"

// An armor or shield record of ItemPMT.prs (lookup_item_pmt_record): the DFP
// and EVP it adds and its five resistances, in the file's order.
struct PmtArmorRecord {
    s32 name;  // text collection index
    u8 pad_4[4];
    s16 dfp;
    s16 evp;
    u8 block_particle;
    s8 block_effect;
    u16 class_flags;
    u8 required_level;
    s8 efr;
    s8 eth;
    s8 eic;
    s8 edk;
    s8 elt;
};

// A unit record: the stat it raises (0-14, as apply_unit_stat_bonus reads it)
// and by how much.
struct PmtUnitRecord {
    s32 name;
    u8 pad_4[4];
    s16 stat;
    s16 amount;
};

// A weapon record: its attack power range, ATA, the MST it adds and the
// grind it stops at.
struct PmtWeaponRecord {
    u8 pad_0[8];
    u16 class_flags;
    u16 atp_min;
    u16 atp_max;
    u16 atp_required;
    u16 mst_required;
    u16 ata_required;
    u16 mst;
    u8 max_grind;
    u8 pad_17[2];
    u8 ata;
};

// A mag record: the classes that can equip it.
struct PmtMagRecord {
    u8 pad_0[0x14];
    u16 class_flags;
};

// A tool record: its price and flags (bit 0x80: rare).
struct PmtToolRecord {
    s32 name;
    u8 pad_4[8];
    s32 price;
    u32 flags;
};

// One record of the table get_item_stat_boost_record returns: the stat boost kind (1-16)
// an item applies and its amount.
struct PmtStatBoost {
    u8 kind;
    u8 pad_1;
    s16 amount;
};

#endif
