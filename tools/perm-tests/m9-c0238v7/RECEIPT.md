# m9-c0238v7 — migration leg: 3c0238 v7 fused floor onto 721e0b3e chain

Seat: TLobby__sub_803C0238 (psov3/pso/unk/TLobby_803BFE50) — sealed champion
42556ea4 (f7 card-3c0238-v7, 98.4127 @ 0x3F0 GATE-EXACT, P@4 interleave fuse).

## Intake
- STEP 0 base-row screen: base-report-721e0b3e row present at era size 1008,
  NO fuzzy key = unpaired-open seat at base -> proceed (not paired-100).
- Zero-contact audit: git diff 721e0b3e..HEAD -- src/pso/unk/TLobby_803BFE50.cpp
  = ZERO lines; blob 1d4e1d2b identical at 721e0b3e == HEAD == fc62998f ==
  champion parent 998ca8f4 -> pure `git show 42556ea4 -- file | git apply`
  verbatim. The v7 file state lands WHOLE (wave10-drop v2 3dfa1b7a graft is
  inside the champion blob: seat body + vtable/struct restage + 7 phase-2
  externs + era-slot neighbors) — no twin state needed from f8 chain.
- Landing verification: working-tree blob edfad9c6 == champion tip blob EXACT
  (git diff 42556ea4 -- file = 0 lines).
- Naming surface: symbols.txt row for 0x803C0238 ABSENT at #198 tip (naming
  waves). Gate truth re-derived from lane era asm
  build/GPOE8P/asm/pso/unk/TLobby_803BFE50.s .fn TLobby__sub_803C0238
  (0x803C0238..0x803C0624, header size: 0x3F0) = 252 insns = 0x3F0. gnm sizes
  + era slot order decisive (adxf datum); row recorded for naming queue.
- Pin: GC/2.6 -O4,p -char signed -use_lmw_stmw on -inline off from live
  build.ninja TU row; config/** untouched.

## Gates (all on final committed-tree state)
- rm src .o + ninja unit rc=0, MWCC line printed (stale-.o law).
- gnm -S int-parse: seat 0x3e8 @ size 0x3f0 GATE-EXACT; 36 T-syms, 0 added,
  0 removed, size-drift 0 vs era roster (int-parse 36/36).
- one_shot PAIRED seat ORIG=OURS 98.4127, sizes 1008/1008, rows 252/252 =
  sealed floor echo ZERO decay; era reload row (slot 11 lwz) + cmpwi sandwich
  present, residual = champion 2-reg home-rotation color class.
- Full-unit echo: 35 siblings + [.data] 100.0, seat 98.4127 (37/37 paired).
- Full ninja rc=0: link Code 141/141, Data 100.00%, CHECK build.sha1 OK.
- report_delta --check vs base-report-721e0b3e: matched_functions 27363 +0,
  New exact 0, regressions 0, rc=0; matched_data +88, linked_units 2859 +0 =
  chain-inherited.
- ATTRIBUTION CONTROL (m9 method): tree re-stashed to tip WITHOUT leg, unit
  + full rebuild: report measures matched_functions 27363, report_delta +0/0,
  check_pr PASS — reproduces base exactly. Row-level diff control->mytip =
  EXACTLY 1 row: seat (1008,None) -> (1008,98.4127). Leg delta = 0 new-exact,
  0 regressions, seat unpaired->paired fuzzy coverage. Global fuzzy measures
  95.894226 (base) -> 95.98889 (tip control) -> 96.01168 (mytip, +0.02279 =
  this leg). NOTE: m9's recorded +2 chain-inherited (vfunc_118 +
  TLobby__sub_803FCF44) did NOT reproduce at control (both rows stable at
  99.75/99.81707 in base/control/mytip row tuples; measures constant 27363;
  first mytip report_delta run showed vfunc_118 "New exact" — two repeat runs
  at final state = +0/+0 => non-reproducible pairing flake, row diff is the
  ground truth).
- check_pr PASS (linked 2859, regressed 0, skipped 0, exact candidates 1 =
  known non-config); link_units check OK 2859 all exact.
- DOL byte-identical 0d85744b51d7379efb025a943d0cd5aaae2191a3: lane pre/post
  control + restored, == main checkout (unit unlinked, seat <100).

## Residual (champion-inherited, NO grind)
2-reg home-rotation colors {self r31<->r27, reload r29->r28} = sealed
bind-to-home stratum; v8 successor (rotation-rank probe) is the integrator's
ladder call. Unit stays 35/36 exact, seat fuzzy 98.4127.

Builds: unit x2 + full link x2 (control + restore relink); 40-min cap met.
Receipts: tools/perm-tests/f7_3c0238_v7/ (champion copy) + this dir.
Lane scratch: m10_gnm_new/final.txt, m10_oneshot*.txt, m10_unit_all.txt,
m10_report_{tip,mytip}.json, m10_rd_{control,mytip1,mytip2}.txt.
