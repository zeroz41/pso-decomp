#ifndef PSO_MISC_TSHOPGENERATOR_H
#define PSO_MISC_TSHOPGENERATOR_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TShopGenerator : public TObjBase {
    virtual ~TShopGenerator();
    bool is_player_in_service_range(u8 *, f32);
    virtual void run_task();
    u32 m_90;
    u32 m_94;
    static s32 is_no_service_active(void *self, s32 player);
    static void clear_slot_active(s32 arg0);
    static void run_fn_table_reverse();
    static void run_fn_table_forward();
};

typedef char TShopGenerator_size[sizeof(TShopGenerator) == 0x98 ? 1 : -1];

extern "C" {
void THunterGuildSeqOffline__sub_8021E180(s32 arg0);
void *TShopGenerator__create(void *arg0);
void *TShopGenerator__ct(void *arg0, s32 arg1);
void *__dt__14TShopGeneratorFv(void *arg0, s16 arg1);
u8 is_slot_active__14TShopGeneratorFi(s32 arg0);
void run_task__14TShopGeneratorFv(u8 *self);
}

#endif
