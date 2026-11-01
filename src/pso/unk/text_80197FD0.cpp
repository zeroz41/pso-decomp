#include "types.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_80197FD0.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
void set_texture_name(void *, void *, int, int);
extern u32 TObjSinBoard__texture_buffer;
u8 TObjSinBoard__texture_name[0xC];
__declspec(section ".data") void *signboard_texture_list[2];
u8 TObjSinBoard__texture_surface[0x24];
void fn_80197FD0(void *arg0, void *quest_vm_down_load_server) {
    u32 t = (u32)TQuestVmDownLoadServer::alloc((u32)quest_vm_down_load_server);
    TObjSinBoard__texture_buffer = t;
    if (t != 0) {
        ((TLobby *)t)->move_data((const void *)arg0, (u32)quest_vm_down_load_server);
        signboard_texture_list[0] = TObjSinBoard__texture_name;
        signboard_texture_list[1] = (void *)1;
        ((TObjPlayer *)TObjSinBoard__texture_surface)->set_render_rect(TObjSinBoard__texture_buffer, 0, 0, 0);
        set_texture_name(TObjSinBoard__texture_name, TObjSinBoard__texture_surface, 0, 0x40000000);
        fn_8023E734((u32)signboard_texture_list);
    }
}

}
