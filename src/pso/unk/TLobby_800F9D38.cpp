#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int load_sct_file__8TGStreamFll(void);
int load_file__8TGStreamFl(void);

    extern int disc_read_filename;
void TLobby::set_stream_and_load_file(int a0) { disc_read_filename = a0; load_file__8TGStreamFl(); }

void TLobby::set_stream_state(int a0) { disc_read_filename = a0; load_sct_file__8TGStreamFll(); }

}
