#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo15_TYPE2_WAIT.h"
#include "pso/math/AngleLookup.h"

struct RecoveredGlobal_8033FE30_lbl_80478554 {
    s32 value;
    u8 remaining[0x8];
};

extern "C" {
extern RecoveredGlobal_8033FE30_lbl_80478554 lbl_80478554;
extern const f32 lbl_805DFAFC;
extern const f32 lbl_805DFB00;
extern const f32 lbl_805DFB04;
#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8033FE30_lbl_80478554_size[sizeof(RecoveredGlobal_8033FE30_lbl_80478554) == 0xC ? 1 : -1];
void TBoss6Demo15_TYPE2_WAIT::sub_8033FE30() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    temp_f29 = (lbl_805DFB00 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x5C))) + lbl_805DFAFC;
    temp_f30 = sin_table_lookup(*(s32 *)&this->m_58);
    temp_f31 = cos_table_lookup(*(s32 *)&this->m_58);
    VecCopy((Vec *)&this->m_40, (const Vec *)&lbl_80478554.value);
    this->m_40 = (f32) ((temp_f30 * temp_f29) + this->m_40);
    this->m_48 = (f32) ((temp_f31 * temp_f29) + this->m_48);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) (*(f32 *)((s8 *)arg0 + 0x44) + lbl_805DFB04);
}
#pragma pop

}
