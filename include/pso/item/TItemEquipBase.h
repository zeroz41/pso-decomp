#ifndef PSO_ITEM_TITEMEQUIPBASE_H
#define PSO_ITEM_TITEMEQUIPBASE_H

#include "types.h"
#include "pso/item/TItem.h"
#include "pso/system/FlagWord.h"
#include "pso/player/PlayerAttackParams.h"

class TItemHeapObject;
struct TechniqueBoostParam;

// What an equipped item adds to its owner's stats; TItemData::apply_equip_effects
// fills it and add_equip_stats hands each stat to TObjPlayer::add_<stat>.
struct EquipStatBonus {
    s16 atp;
    s16 mst;
    s16 evp;
    s16 hp;
    s16 dfp;
    s16 ata;
    s16 lck;
    u8 pad_e[0x16];
};

// What an equipped item adds to its owner's HP and TP maxima
// (add_actor_hp_bonus / add_actor_tp_bonus).
struct EquipHpTpBonus {
    s16 hp;
    s16 tp;
};

// effect_flags bits: each equip effect has a "wanted" bit and, one above it,
// a "started" bit (start_effect / stop_effect); bit 0 records that the
// equipped model was requested.
enum {
    EQUIP_EFFECT_MODEL_REQUESTED = 0x1,
};

// The base of every item that can be equipped: weapons, armor, shields,
// units and mags. It keeps the stat bonuses the item gives its owner and the
// model drawn on the owner while equipped.
struct TItemEquipBase : public TItem {
    TItemEquipBase(TObject *parent, u8 *item);
    virtual ~TItemEquipBase();
    virtual void set_attach_slot(s8 slot);
    virtual void equip();
    virtual void unequip();
    virtual void add_equip_stats(s32 apply);
    virtual void remove_equip_stats(s32 apply);
    virtual void subtract_item_stat_bonus(s32 player, s32 unused, s16 *stats);
    virtual void subtract_equip_stats(void *atp, s16 *stats, s16 *stats2);
    virtual void destroy();
    virtual s8 get_attach_slot();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void release();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();

    void refresh_owner_stats();
    void request_model_load(u8 group);
    EquipHpTpBonus *get_stat_bonus_ptr();
    s8 get_attach_joint();
    void bind_loaded_resources();
    void clear_technique_boosts();
    void register_technique_boosts(const TechniqueBoostParam *params);
    void apply_equip_effects();
    void remove_equip_effects();
    s32 start_effect(u32 wanted, u32 started);
    s32 stop_effect(u32 started);
    void set_attach_joint(s32 joint);
    static void deduct_cap_excess(s32 item, s16 *stat, s16 excess);
    void reset();
    void update_with_player();
    static void apply_equip_effect_slot(u16 client, u32 slot);
    static void apply_equip_slot_effect(u16 client, u32 slot);

    EquipStatBonus stat_bonus;
    AttackParams attack_bonus;
    ActorParamBlock param_bonus;
    EquipHpTpBonus hp_tp_bonus;
    u8 attach_slot;
    u8 attach_joint;                 // the owner joint the model hangs from
    s16 model_resource_id;           // TItemLoad resource, -1 while none
    TItemHeapObject *effect_objects; // parent of the objects the equip effects create
    FlagWord effect_flags;
    void *model_motion;              // drawn with draw_model_motion
    void *model_data[2];
    NJS_OBJECT *second_model;
};

typedef char TItemEquipBaseFlagsOffset[(offsetof(TItemEquipBase, effect_flags) == 0x178) ? 1 : -1];
typedef char TItemEquipBase_size[sizeof(TItemEquipBase) == 0x18C ? 1 : -1];

// A weapon's hit callback: a small burst at the target hit.
void play_target_impact_effect(s32 unused0, s32 unused1, u16 actor_id, s16 collider);

extern "C" {
// TItemEquipBase's constructor and destructor under their own symbols, for
// the derived classes still written as C functions.
void *__ct__14TItemEquipBaseFP7TObjectPUc(void *item, void *parent, void *data);
void *__dt__14TItemEquipBaseFv(void *item, s16 deleting);
}

#endif
