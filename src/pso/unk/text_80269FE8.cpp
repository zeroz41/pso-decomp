#include "types.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/text_80269FE8.h"
extern "C" {
s32 __nw__7TObjectFUl(int);
s32 TLobby__sub_80269DA4(void *, int);
s32 TWindowMessageInfomation__ct(int, void *, void *);
}
s32 create_message_information_window(s32 arg0, s32 arg1, s32 arg2) {
  s32 temp_r3_2;
  u8 *temp_r3;
  s32 phi_r4;
  temp_r3 = (u8 *) TLobby__sub_80269CB4();
  *((s32 *) (((s8 *) temp_r3) + 0x10)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x10))) | 0x20);
  TLobby__sub_80269DA4((void *) arg1, 0x10);
  temp_r3_2 = (phi_r4 = __nw__7TObjectFUl(0x90));
  if (temp_r3_2 != 0)
  {
    phi_r4 = TWindowMessageInfomation__ct((int) temp_r3_2, (void *) arg0, (void *) arg2);
  }
  *((s32 *) (((s8 *) temp_r3) + 0x10)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x10))) & 0xFFFFFFDF);
  return phi_r4;
}
