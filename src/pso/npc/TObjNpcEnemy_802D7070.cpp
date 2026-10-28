#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"

    extern const float lbl_805DE7D8;
void TObjNpcEnemy::reset_anim_fields() { *(short *)&this->m_name = 0; *(short*)((char*)this + 0x2) = 4; *(float *)&this->m_flags = lbl_805DE7D8; *(int *)&this->m_prev = 0; *(int *)&this->m_next = 0; *(float *)&this->m_up = lbl_805DE7D8; *(int *)&this->m_down = 0; *(int*)((char*)this + 0x18) = 0; *(short *)&this->entity_id = 0; *(short *)&this->visibility = 0; *(short *)&this->m_20 = 0; }
