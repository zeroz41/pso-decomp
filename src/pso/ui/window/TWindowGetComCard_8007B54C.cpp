#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowGetComCard_8007B54C.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/ui/window/TWindowGetComCard.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"

struct RecoveredGlobal_8007B54C_TWindowGetComCard__data_80500158 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredGlobal_8007B594_TWindowGetComCard__data_80500158 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158
{
  s32 value;
  u8 remaining[0x23C];
};

extern "C" {
RecoveredGlobal_8007B54C_TWindowGetComCard__data_80500158 TWindowGetComCard__received_guild_card_tags;
s32 TWindowSubComCard__sub_8007B26C(s32);
void __construct_array(void *ptr, void *ctor, void *dtor, u32 size, u32 n);

typedef char RecoveredGlobal_8007B54C_TWindowGetComCard__data_80500158_size[sizeof(RecoveredGlobal_8007B54C_TWindowGetComCard__data_80500158) == 0x240 ? 1 : -1];
void TWindowGetComCard__sub_8007B54C(void) {
    TWindowGetComCard::remove_entry(0, (s32) &TWindowGetComCard__received_guild_card_tags.value, 4);
    if (((TWindowSubComCard *)(&TWindowGetComCard__received_guild_card_tags.value))->is_active() == 0) {
        TWindowCtrl__sub_8024A08C();
    }
}

typedef char RecoveredGlobal_8007B594_TWindowGetComCard__data_80500158_size[sizeof(RecoveredGlobal_8007B594_TWindowGetComCard__data_80500158) == 0x240 ? 1 : -1];
s32 *TWindowGetComCard__sub_8007B594(void) {
    return &(*(RecoveredGlobal_8007B594_TWindowGetComCard__data_80500158 *)&TWindowGetComCard__received_guild_card_tags).value;
}

void TWindowGetComCard::remove_entry(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    if (arg0 < (arg2 - 1)) {
        temp_r3 = arg1 + (arg0 * 0x90);
        ((TLobby *)temp_r3)->move_words((u32 *)(temp_r3 + 0x90), (s32)((u32) (((arg2 - arg0) - 1) * 0x90) >> 2U));
    }
    arg1 += (arg2 - 1) * 0x90;
    TWindowSubComCard__sub_8007B26C(arg1);
}

typedef struct RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158 RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158;
typedef char RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158_size[((sizeof(RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158)) == 0x240) ? (1) : (-1)];
void TWindowGetComCard__sub_8007B60C(s32 _w0) {
  int new_var;
  s32 var_r29;
  s32 var_r31;
  TWindowCtrl__sub_8024A08C();
  var_r29 = 0;
  var_r31 = 0;
  do
  {
    new_var = 0xFFFFFFFFFFFFFFFF;
    TWindowSubComCard__sub_8007B26C((s32)((void *) (((u8 *) (&(*(RecoveredGlobal_8007B60C_TWindowGetComCard__data_80500158 *)&TWindowGetComCard__received_guild_card_tags).value)) + (var_r31 & new_var))));
    var_r29 += 1;
    var_r31 += 0x90;
  }
  while (var_r29 < 4);
}

void TWindowGetComCard__sub_8007B65C(void* p) { TWindowGetComCard__sub_8007B60C((s32)p); }
void TWindowGetComCard__sub_8007B67C(void* p) { TWindowGetComCard__sub_8007B60C((s32)p); }
void TWindowGetComCard::construct_card_tags() {
    __construct_array(((u8 *)&TWindowGetComCard__received_guild_card_tags), (void *)init_guild_card_tag__17TWindowSubComCardFi, 0, 0x90, 4);
}

}

__declspec(section ".ctors") static void *const __sinit_TWindowGetComCard_8007B54C_cpp_ref = (void *)TWindowGetComCard::construct_card_tags;
