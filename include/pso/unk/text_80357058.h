#ifndef PSO_UNK_TEXT_80357058_H
#define PSO_UNK_TEXT_80357058_H

#include "types.h"

struct TItemEffOrgaFlowShot;
extern "C" {
void clear_6xAD_action_buffer(s8 *buf);
void disable_olga_flow_subordinate_actions(void);
void enable_olga_flow_subordinate_actions(void);
}
void build_6xAD_olga_flow_subordinate_boss_actions(void *p);
void read_be16_field2_forward(void *p);
void send_6xAD_olga_flow_subordinate_boss_actions(u8 *arg0);

#endif
