#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

    extern const float lbl_805DC098;
void TUnk_804B9870::reset_motion_fields() { *(int *)&this->m_20 = 0; *(float *)&this->m_4c = lbl_805DC098; (*(float *)&this->m_48) = lbl_805DC098; *(float *)&this->m_44 = lbl_805DC098; (*(float *)&this->m_58) = lbl_805DC098; *(float *)&this->m_54 = lbl_805DC098; (*(float *)&this->m_50) = lbl_805DC098; *(int *)&this->rotation_z = 0; *(int *)&this->rotation_y = 0; *(int *)&this->rotation_x = 0; *(float *)&this->m_7c = lbl_805DC098; (*(float *)&this->m_78) = lbl_805DC098; *(float *)&this->m_74 = lbl_805DC098; *(int *)&this->m_80 = 0; }
