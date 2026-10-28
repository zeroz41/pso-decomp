#include "types.h"
#include "pso/item/TItemData_80104D0C.h"
#include "pso/item/TItemMagSub_80114524.h"
#include "pso/unk/text_80104F4C.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItem.h"

struct ObjBase_80104DAC { u8 pad[0x18]; };

struct Obj_80104DAC : ObjBase_80104DAC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual s32 v14();
};

struct ItemData_80104DAC { u8 b[0x14]; };

struct MagData_80104DAC { u8 b[0x10]; };

struct Rec_80104DAC { u8 pad0[6]; u8 b6; u8 b7; u8 b8; u8 b9; u8 bA; u8 bB; u8 bC; };

extern "C" {
s32 get_actor_section_id__15TPlyPhotonChairFv(void *);
s32 check_equip_requirements(void *, void *, int);
void deserialize_mag__9TItemDataFPvPv(void *, void *);
void init__9TItemDataFv(void *);
Rec_80104DAC *find_item_combination_recipe(u8 *, void *);
s32 is_wrapped__9TItemDataFPv(u8 *);
void *lookup_item_pmt_record(u8 *);

u8 TItemData::is_item_usable(s32 arg0, u8 *item) {
    if (is_wrapped__9TItemDataFPv(item) != 0) {
        return 1U;
    }
    if ((u8) *item == 3) {
        if (*(s32 *)((s8 *)(lookup_item_pmt_record(item)) + 0x10) & 1) {
            return 1U;
        }
        return (u8) (find_eligible_combination_recipe(arg0, item) != 0);
    }
    return (u8) (find_eligible_combination_recipe(arg0, item) != 0);
}
}
#define o ((Obj_80104DAC *)arg0)
s32 find_eligible_combination_recipe(s32 arg0, u8 *item) {
    ItemData_80104DAC d;
    ItemData_80104DAC d2;
    MagData_80104DAC mag;
    s16 m;
    Rec_80104DAC *rec;
    void *it;
    u8 v;
    rec = NULL;
    if (o != NULL && item != NULL) {
        it = find_unique_combination_target((TObjPlayer *)o, (TItemData *)item);
        if (it != NULL) {
            init__9TItemDataFv(&d);
            ((TItem *)it)->copy_to_item_data((TItemData *)&d);
            rec = find_item_combination_recipe(item, it);
        } else {
            return 0;
        }
        if (rec->b9 != 0xFF) {
            if (d.b[0] != 2) {
                return 0;
            }
            ((TItemData *)(&mag))->initialize_mag_data();
            deserialize_mag__9TItemDataFPvPv(&d, &mag);
            m = rec->b9;
            if (get_mag_total_level(&mag) < m) {
                return 0;
            }
        }
        if (rec->bA != 0xFF) {
            if (d.b[0] != 0) {
                return 0;
            }
            if (d.b[3] < rec->bA) {
                return 0;
            }
        }
        v = rec->bB;
        if (v != 0xFF) {
            if (o->v14() < v - 1) {
                return 0;
            }
        }
        v = rec->bC;
        if (v != 0xFF) {
            if (v != get_actor_section_id__15TPlyPhotonChairFv(o)) {
                return 0;
            }
        }
        init__9TItemDataFv(&d2);
        d2.b[0] = rec->b6;
        d2.b[1] = rec->b7;
        d2.b[2] = rec->b8;
        if (check_equip_requirements(o, &d2, 0) == 0) {
            return 0;
        }
    }
    return (s32)rec;
}
