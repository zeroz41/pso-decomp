#ifndef PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H
#define PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class THunterGuildSeqOnlineTask : public TObject {
public:
    THunterGuildSeqOnlineTask(TObject *parent);
    virtual ~THunterGuildSeqOnlineTask();
    virtual void run_task();
};

// TObject::m_name strings of the online hunter-guild sequence classes (.sdata, defined in
// THunterGuildSeqOnlineTask.cpp in this order).
extern const char *hunter_guild_seq_online_task_name;
extern const char *hunter_guild_seq_online_server_name;
extern const char *hunter_guild_seq_online_client_name;

void handle_6x73_exit_quest(void);

// Clears the online quest download windows and download state.
void reset_globals(void);


void close_windows_and_reset();
void release_resources();

#endif
