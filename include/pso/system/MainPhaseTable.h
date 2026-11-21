#ifndef PSO_SYSTEM_MAIN_PHASE_TABLE_H
#define PSO_SYSTEM_MAIN_PHASE_TABLE_H

typedef void (*MainPhaseCallback)();

struct MainPhaseEntry {
    MainPhaseCallback init;
    MainPhaseCallback update;
    MainPhaseCallback exit;
};

extern "C" MainPhaseEntry main_phase_table[];

#endif
