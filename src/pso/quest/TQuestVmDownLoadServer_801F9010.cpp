#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_801F9010.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/render/TDLGraph.h"

void TQuestVmDownLoadServer::reset_download() {
    reset_download_graph();
}
void reset_download_graph(void) {
    TDLGraph::update_graph(1, 1);
}
