#ifndef PSO_UNK_TEXT_80223B98_H
#define PSO_UNK_TEXT_80223B98_H

#include "types.h"

extern "C" {
s32 get_tool_pool_table_row(s32 arg0);
}
s32 classify_tool_shop_level_bracket(s32 arg0);
void clear_shop_tool_flags(void);
extern "C" {
s32 get_shop_technique_pool_count(s32 arg0);
s32 get_shop_rare_tool_pool_count(s32 arg0);
}
void generate_shop_common_tool_pool(s32 arg0);
void generate_shop_rare_tool_pool(s32 arg0);
void generate_shop_technique_pool(s32 arg0);
void mark_shop_tool_sold_out(s32 a, s32 b);

// --- C functions defined in text_80223B98.cpp ---
extern "C" {
s32 get_tool_pool_table_row(s32 arg0);
s32 get_shop_technique_pool_count(s32 arg0);
s32 get_shop_rare_tool_pool_count(s32 arg0);
}
// --- end of C functions

#endif
