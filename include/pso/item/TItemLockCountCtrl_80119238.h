#ifndef PSO_ITEM_TITEMLOCKCOUNTCTRL_80119238_H
#define PSO_ITEM_TITEMLOCKCOUNTCTRL_80119238_H

#include "types.h"

extern "C" {
void remove_freeze_immunity(int client);
void remove_slow_immunity(int client);
void remove_shock_immunity(int client);
void remove_paralysis_immunity(int client);
void remove_poison_immunity(int client);
void remove_status_cleanse(int client);
void add_freeze_immunity(int client);
void add_confusion_immunity(int client);
void add_paralysis_immunity(int client);
}
void add_shock_immunity(int client);
void add_slow_immunity(int client);
void remove_confusion_immunity(int client);

// --- C functions defined in TItemLockCountCtrl_80119238.cpp ---
extern "C" {
void remove_freeze_immunity(int client);
void remove_slow_immunity(int client);
void remove_shock_immunity(int client);
void remove_paralysis_immunity(int client);
void remove_poison_immunity(int client);
void remove_status_cleanse(int client);
void add_freeze_immunity(int client);
void add_confusion_immunity(int client);
void add_paralysis_immunity(int client);
}
// --- end of C functions

#endif
