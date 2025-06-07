#pragma once
#include "Command.hpp"
#include "Variable.hpp"

class Cheats {
public:
	void Init();
	void Shutdown();

	static void PatchBhop(int slot, void *player, CUserCmd *cmd);
	static void AutoStrafe(int slot, void *player, CUserCmd *cmd);
	static void EnsureSlopeBoost(const CHLMoveData *move, void *player, CGameTrace **tr);
	static void CheckFloorReportals();
};

extern Variable p2sm_autorecord;
extern Variable p2sm_autojump;
extern Variable p2sm_jumpboost;
extern Variable p2sm_aircontrol;
extern Variable p2sm_duckjump;
extern Variable p2sm_disable_challenge_stats_hud;
extern Variable p2sm_disable_challenge_stats_hud_partner;
extern Variable p2sm_disable_steam_pause;
extern Variable p2sm_disable_no_focus_sleep;
extern Variable p2sm_disable_progress_bar_update;
extern Variable p2sm_prevent_mat_snapshot_recompute;
extern Variable p2sm_challenge_autostop;
extern Variable p2sm_show_entinp;
extern Variable p2sm_force_qc;
extern Variable p2sm_patch_bhop;
extern Variable p2sm_patch_cfg;
extern Variable p2sm_prevent_ehm;
extern Variable p2sm_disable_weapon_sway;
extern Variable p2sm_disable_viewmodel_shadows;

extern Variable sv_laser_cube_autoaim;
extern Variable ui_loadingscreen_transition_time;
extern Variable ui_loadingscreen_fadein_time;
extern Variable ui_loadingscreen_mintransition_time;
extern Variable ui_transition_effect;
extern Variable ui_transition_time;
extern Variable ui_pvplobby_show_offline;
extern Variable mm_session_sys_delay_create_host;
extern Variable hide_gun_when_holding;
extern Variable r_flashlightbrightness;

extern Command p2sm_togglewait;
