#include "types.h"
#include <string.h>
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_26c590
{
  char pad[0x18];
};

struct VObj_18_26c590 : VBase_18_26c590 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual s32 m10();
};

extern "C" {
s32 __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *);
}
s32 fill_guild_card_from_player(u8 *ply_guild_card_tag, u32 client);
typedef struct VBase_18_26c590 VBase_18_26c590;
typedef struct VObj_18_26c590 VObj_18_26c590;
s32 fill_guild_card_from_player(u8 *ply_guild_card_tag, u32 client) {
  unsigned char new_var;
  saddr player;
  u8 *temp_r4;
  player = (saddr)get_player_by_client_id(client);
  if (player == 0)
  {
    return 0;
  }
  *((u8 *) (((s8 *) ply_guild_card_tag) + 0x8C)) = (u8) ((*((u8 *) (((s8 *) ply_guild_card_tag) + 0x8C))) | 3);
  strncpy((char *)(ply_guild_card_tag + 8), (const char *)((TPlyPhotonChair *)(player))->get_name(), 0x17);
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x1F)) = 0;
  *((u8 *) (((s8 *) ply_guild_card_tag) + 0x8F)) = (u8) (*((u8 *) (((s8 *) player) + 0x88D)));
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x8E)) = ((TPlyPhotonChair *)player)->get_actor_section_id();
  new_var = ((TObjPlayer *)player)->get_language();
  temp_r4 = (u8 *)(player + 0xDAC);
  *((s8 *) (((s8 *) ply_guild_card_tag) + 0x8D)) = new_var;
  if (temp_r4 == 0)
  {
    return 0;
  }
  if (((u32) (*((u32 *) (((s8 *) temp_r4) + 4)))) == 0U)
  {
    return 0;
  }
  __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag((void *) ply_guild_card_tag);
  return 1;
}
