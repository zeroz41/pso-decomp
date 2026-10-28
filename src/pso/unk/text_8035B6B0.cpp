#include "types.h"
#include "pso/unk/text_8035B6B0.h"

#include <stddef.h>
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct Stack_8035B6B0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, int, void *, f32, f32);
}
extern s32 chao_npc_spawn_descriptor[];
extern s32 bm_ene_npc_chao_resource_descriptor[];
extern u8 *chao_npc_instance_handle;
extern const f32 lbl_805E0138;
extern const f32 lbl_805E013C;
void load_and_spawn_chao_npc(void) {
    typedef char sp8_offset[(offsetof(Stack_8035B6B0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8035B6B0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8035B6B0, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8035B6B0, sp14) == 0xC) ? 1 : -1];
    Stack_8035B6B0 stack;
    u8 *temp_r5;
    u8 *var_r9;
    var_r9 = (u8 *)((int)::operator new(0x440));
    if (var_r9 != NULL) {
        var_r9 = (u8 *)(load_resource_from_descriptor(var_r9, 1, bm_ene_npc_chao_resource_descriptor, 0, 0, 0));
    }
    chao_npc_instance_handle = var_r9;
    stack.sp8 = *(s32 *)((s8 *)chao_npc_spawn_descriptor + 0);
    stack.spC = *(s32 *)((s8 *)chao_npc_spawn_descriptor + 4);
    stack.sp10 = *(s32 *)((s8 *)chao_npc_spawn_descriptor + 8);
    stack.sp14 = *(s32 *)((s8 *)chao_npc_spawn_descriptor + 0xC);
    stack.sp8 = *(s32 *)((s8 *)var_r9 + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)var_r9 + 0x42C));
    spawn_npc_enemy__6TLobbyFslllff(0xB, (int) (*(s32 *)((s8 *)temp_r5 + 8)), (int) (*(s32 *)((s8 *)temp_r5 + 0xC)), &stack.sp8, (int) (*(s32 *)((s8 *)chao_npc_spawn_descriptor + 0)), chao_npc_spawn_descriptor, lbl_805E0138, lbl_805E013C);
}
