#include "types.h"
#include "pso/unk/TUnk_804A5838.h"
#include "pso/player/TObjPlayer_8012D034.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

int rotate_matrix_z(void*, void*);
int get_player_list__10TObjPlayerFv(void*);

void TUnk_804A5838::update_idle() { *(s32*)((char*)this + 0x1f8) = 0; }
void TUnk_804A5838::vfunc_60() { if (get_player_list__10TObjPlayerFv(this) == 0) { rotate_matrix_z((void*)0, *(void* *)&this->unk_1F8); } }

}
