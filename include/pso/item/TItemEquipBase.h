#ifndef PSO_ITEM_TITEMEQUIPBASE_H
#define PSO_ITEM_TITEMEQUIPBASE_H

#include "types.h"
#include "pso/item/TItem.h"

struct TItemEquipBase : public TItem {
    virtual ~TItemEquipBase();
    virtual void equip();
    virtual s8 get_attach_slot();
    void refresh_owner_stats();
    void request_model_load(s32);
    void sub_8010A948();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void release();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    u8 unk_F8[0x2];
    s16 m_fa;
    u8 unk_FC[0x2];
    s16 m_fe;
    u8 unk_100[0x2];
    s16 m_102;
    u8 unk_104[0x48];
    s16 m_14c;
    u8 unk_14E[0x2];
    s16 m_150;
    u8 unk_152[0x2];
    s16 m_154;
    u8 unk_156[0x2];
    u32 m_158;
    u8 unk_15C[0xC];
    s32 m_168;
    u8 unk_16C[0x2];
    s16 m_16e;
    u8 m_170;
    u8 m_171;
    u16 m_172;
    u32 m_174;
    void* m_178;
    u32 m_17c;
    u32 m_180;
    u32 m_184;
    u32 m_188;
    void*get_stat_bonus_ptr();
    void bind_loaded_resources();
    void remove_equip_effects();
    s32 apply_ad_rico_ring(s32 arg1);
    void set_equip_flag(s32 v);
    void set_attach_slot(s8 arg1);
    static void deduct_cap_excess(s32 unused, s16 *arg1, s16 arg2);
    void subtract_equip_stats(s32 arg1, u8 *arg2, u8 *arg3);
    void subtract_item_stat_bonus(s32 arg1, s32 arg2, s16 *out);
    void reset();
    void update_equip();
    virtual void unequip();
    void update_with_player();
    void init_slot();
    int check_flag_32();
    int clear_flag_c_bit5();
    static void apply_equip_effect_slot(u16 arg0, u32 arg1);
    static void apply_equip_slot_effect(u16 arg0, u32 arg1);
    void set_slot(s32 arg1, s32 arg2);
    void init_slots();
    void remove_equip_stats(s32 arg1);
    void add_equip_stats(s32 arg1);
};

typedef char TItemEquipBase_size[sizeof(TItemEquipBase) == 0x18C ? 1 : -1];
#endif
