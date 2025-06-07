# SAR: Cvars

|Name|Default|Description|
|---|---|---|
|<i title="The Stanley Parable">+bhop</i>|cmd|Client sends a key-down event for the in_jump state.|
|<i title="The Stanley Parable">-bhop</i>|cmd|Client sends a key-up event for the in_jump state.|
|cl_crosshair_t|0|Removes the top line from the crosshair :0: normal crosshair,1: crosshair without top.|
|cl_crosshairalpha|255|Change the amount of transparency.|
|cl_crosshaircolor_b|255|Changes the color of the crosshair.|
|cl_crosshaircolor_g|255|Changes the color of the crosshair.|
|cl_crosshaircolor_r|255|Changes the color of the crosshair.|
|cl_crosshairdot|1|Decides if there is a dot in the middle of the crosshair|
|cl_crosshairgap|9|Changes the distance of the crosshair lines from the center of screen.|
|cl_crosshairsize|1|Changes the size of the crosshair.|
|cl_crosshairthickness|0|Changes the thickness of the crosshair lines.|
|cl_quickhud_alpha|255|Change the amount of transparency.|
|cl_quickhudleftcolor_b|86|Changes the color of the left quickhud.|
|cl_quickhudleftcolor_g|184|Changes the color of the left quickhud.|
|cl_quickhudleftcolor_r|255|Changes the color of the left quickhud.|
|cl_quickhudrightcolor_b|255|Changes the color of the right quickhud.|
|cl_quickhudrightcolor_g|184|Changes the color of the right quickhud.|
|cl_quickhudrightcolor_r|111|Changes the color of the right quickhud.|
|cond|cmd|cond \<condition> \<command> [args]... - runs a command only if a given condition is met|
|conds|cmd|conds [\<condition> \<command>]... [else] - runs the first command which has a satisfied condition|
|ghost_chat|cmd|ghost_chat - open the chat HUD for messaging other players|
|ghost_connect|cmd|ghost_connect \<ip address> \<port> - connect to the server<br>ex: 'localhost 53000' - '127.0.0.1 53000' - '89.10.20.20 53000'.|
|ghost_debug|cmd|ghost_debug - output a fuckton of debug info about network ghosts|
|ghost_delete_all|cmd|ghost_delete_all - delete all ghosts|
|ghost_delete_by_ID|cmd|ghost_delete_by_ID \<ID> - delete the ghost selected|
|ghost_demo_color|cmd|ghost_demo_color \<color> \<ID>  - sets the color of ghost|
|ghost_disconnect|cmd|ghost_disconnect - disconnect|
|ghost_draw_through_walls|0|Whether to draw ghosts through walls. 0 = none, 1 = names, 2 = names and ghosts.|
|ghost_height|16|Height of the ghosts. (For prop models, only affects their position).|
|+ghost_leaderboard|cmd|+ghost_leaderboard - enable the ghost leaderboard HUD|
|-ghost_leaderboard|cmd|-ghost_leaderboard - disable the ghost leaderboard HUD|
|ghost_leaderboard_font|68|The font to use for the ghost leaderboard.|
|ghost_leaderboard_max_display|10|The maximum number of names to display on the leaderboard.|
|ghost_leaderboard_mode|0|The mode for the leaderboard. 0 = CM, 1 = race|
|ghost_leaderboard_reset|cmd|ghost_leaderboard_reset - reset all leaderboard entries to "no time".|
|ghost_leaderboard_x|10|The x position of the leaderboard.|
|ghost_leaderboard_y|10|The x position of the leaderboard.|
|+ghost_list|cmd|+ghost_list - enable the ghost list HUD|
|-ghost_list|cmd|-ghost_list - disable the ghost list HUD|
|ghost_list|cmd|ghost_list - list all players in the current ghost server|
|ghost_list_font|0|Font index for ghost list HUD.|
|ghost_list_mode|0|Mode for ghost list HUD. 0 = all players, 1 = current map|
|ghost_list_show_map|0|Show the map name in the ghost list HUD.|
|ghost_list_x|2|X position of ghost list HUD.|
|ghost_list_y|-2|Y position of ghost list HUD.|
|ghost_message|cmd|ghost_message - send message to other players|
|ghost_name|cmd|ghost_name - change your online name|
|ghost_name_font_size|5.0|The size to render ghost names at.|
|ghost_name_proximity_fade|200|Distance from ghosts at which their names fade out.|
|ghost_net_dump|0|Dump all ghost network activity to a file for debugging.|
|ghost_net_dump_mark|cmd|Mark a point of interest in the ghost network activity dump.|
|ghost_offset|cmd|ghost_offset \<offset> \<ID> - delay the ghost start by \<offset> frames|
|ghost_opacity|255|Opacity of the ghosts.|
|ghost_ping|cmd|Pong!|
|ghost_prop_model|cmd|ghost_prop_model \<filepath> - set the prop model. Example: models/props/metal_box.mdl|
|ghost_proximity_fade|100|Distance from ghosts at which their models fade out.|
|ghost_recap|cmd|ghost_recap - recap all ghosts setup|
|ghost_reset|cmd|ghost_reset - reset ghosts|
|ghost_set_color|cmd|ghost_set_color \<hex code> - sets the ghost color to the specified sRGB color code|
|ghost_set_demo|cmd|ghost_set_demo \<demo> [ID] - ghost will use this demo. If ID is specified, will create or modify the ID-th ghost|
|ghost_set_demos|cmd|ghost_set_demos \<first_demo> [first_id] [ID] - ghost will setup a speedrun with first_demo, first_demo_2, etc.<br>If first_id is specified as e.g. 5, will instead start from first_demo_5, then first_demo_6, etc. Specifying first_id as 1 will use first_demo, first_demo_2 etc as normal.<br>If ID is specified, will create or modify the ID-th ghost.|
|ghost_shading|1|Enable simple light level based shading for overlaid ghosts.|
|ghost_show_advancement|3|Show the advancement of the ghosts. 1 = show finished runs on the current map, 2 = show all finished runs, 3 = show all finished runs and map changes|
|ghost_show_names|1|Whether to show names above ghosts.|
|ghost_show_spec_chat|1|Show chat messages from spectators when not spectating.|
|ghost_spec_connect|cmd|ghost_spec_connect \<ip address> \<port> - connect to the server as a spectator<br>ex: 'localhost 53000' - '127.0.0.1 53000' - '89.10.20.20 53000'.|
|ghost_spec_next|cmd|ghost_spec_next [samemap] - spectate the next ghost|
|ghost_spec_pov|cmd|ghost_spec_pov \<name\|none> - spectate the specified ghost|
|ghost_spec_prev|cmd|ghost_spec_prev - spectate the previous ghost|
|ghost_spec_see_spectators|0|Whether to see other spectators while spectating.|
|ghost_spec_thirdperson|0|Whether to spectate ghost from a third-person perspective.|
|ghost_spec_thirdperson_dist|300|The maximum distance from which to spectate in third-person.|
|ghost_start|cmd|ghost_start - start ghosts|
|ghost_sync|0|When loading a new level, pauses the game until other players load it.|
|ghost_sync_countdown|3|The number of seconds of countdown to show at the start of every synced map. 0 to disable.|
|ghost_TCP_only|0|Uses only TCP for ghost servers. For people with unreliable internet.|
|ghost_text_offset|7|Offset of the name over the ghosts.|
|ghost_type|cmd|ghost_type \<0/1/2/3/4>:<br>0: Colored circle<br>1: Colored pyramid<br>2: Colored pyramid with portal gun (RECORDED IN DEMOS)<br>3: Prop model (RECORDED IN DEMOS)<br>4: Bendy|
|ghost_update_rate|50|Milliseconds between ghost updates. For people with slow/metered internet.|
|hwait|cmd|hwait \<tick> \<command> [args...] - run a command after the given number of host ticks|
|nop|cmd|nop [args]... - nop ignores all its arguments and does nothing|
|p2sm_about|cmd|p2sm_about - prints info about SAR plugin|
|p2sm_achievement_tracker_ignore_coop|0|When set, achievement tracker ignores coop-specific achievements.|
|p2sm_achievement_tracker_reset|cmd|p2sm_achievement_tracker_reset - resets the status of achievement tracker.|
|p2sm_achievement_tracker_show|0|Enables achievement tracker toasts (using tag "achievements").|
|p2sm_achievement_tracker_status|cmd|p2sm_achievement_tracker_status - shows achievement completion status.|
|p2sm_aim_point_add|cmd|p2sm_aim_point_add - add frozen aimpoint at current position|
|p2sm_aim_point_clear|cmd|p2sm_aim_point_clear - clear all frozen aimpoints|
|p2sm_aim_point_hud|0|Overlays a marker with coordinates at the point you're aiming at|
|p2sm_aircontrol|0|Enables more air-control on the server.|
|p2sm_alias|cmd|p2sm_alias \<name> [command] [args]... - create an alias, similar to the 'alias' command but not requiring quoting. If no command is specified, prints the given alias|
|p2sm_alias_run|cmd|p2sm_alias_run \<name> [args]... - run a SAR alias, passing on any additional arguments|
|p2sm_allow_resizing_window|0|EXPERIMENTAL! Forces resizing on game's window.|
|p2sm_always_transmit_heavy_ents|0|Always transmit large but seldom changing edicts to clients to prevent lag spikes.|
|<i title="The Stanley Parable">p2sm_anti_anti_cheat</i>|cmd|p2sm_anti_anti_cheat - turns on cheats without the Narrator noticing|
|p2sm_auto_voidclip_pause|cmd|p2sm_auto_voidclip_pause \<command> - runs the specified command, and automatically voidclip-pauses on the next load|
|p2sm_autoaim_point|cmd|p2sm_autoaim_point \<x> \<y> \<z> - automatically aims at a point in space. Requires cheats|
|p2sm_autojump|0|Enables automatic jumping on the server.|
|p2sm_autorecord|0|Enables or disables automatic demo recording.|
|p2sm_autostrafe|0|Automatically strafes in your current wishdir.|
|p2sm_avg_result|cmd|p2sm_avg_result - prints result of average|
|p2sm_avg_start|cmd|p2sm_avg_start - starts calculating the average when using timer|
|p2sm_avg_stop|cmd|p2sm_avg_stop - stops average calculation|
|p2sm_bink_respect_host_time|1|Make BINK video playback respect host time.|
|p2sm_cam_control|0|p2sm_cam_control \<type>: Change type of camera control.<br>0 = Default (camera is controlled by game engine),<br>1 = Drive mode (camera is separated and can be controlled by user input),<br>2 = Cinematic mode (camera is controlled by predefined path).<br>3 = Follow mode (Camera is following the player but not rotating, useful when strafing on gel).|
|p2sm_cam_drive|1|Enables or disables camera drive mode in-game (turning it on is not required for demo player)|
|p2sm_cam_force_eye_pos|0|Forces camera to be placed exactly on the player's eye position|
|p2sm_cam_ortho|0|Enables or disables camera orthographic projection.|
|p2sm_cam_ortho_nearz|1|Changes the near Z plane of orthographic projection.|
|p2sm_cam_ortho_scale|1|Changes the scale of orthographic projection (how many units per pixel).|
|p2sm_cam_path_draw|0|Draws a representation of the camera path in the world. Disabled in cinematic mode.|
|p2sm_cam_path_export|cmd|p2sm_cam_path_export \<filename> [format] [framerate] - exports current camera path to a given file in given format.<br>Available formats:<br>kf - default, exports commands that can be used to recreate camera path. Does not use rate parameter.<br>raw - exports a dump of raw camera position for each frame in given framerate (60 by default).<br>davinci - exports a script for DaVinci Resolve's Camera 3D Fusion component based on raw camera dump.|
|p2sm_cam_path_getkfs|cmd|p2sm_cam_path_getkfs - exports commands for recreating currently made camera path|
|p2sm_cam_path_goto|cmd|p2sm_cam_path_goto \<frame> [skipto] - sends the camera to a specified frame of the camera path. If skipto is 1, goto the tick in the demo.|
|p2sm_cam_path_interp|2|Sets interpolation type between keyframes for cinematic camera.<br>0 = Linear interpolation<br>1 = Cubic spline<br>2 = Piecewise Cubic Hermite Interpolating Polynomial (PCHIP)|
|p2sm_cam_path_remkf|cmd|p2sm_cam_path_remkf \<frame> - removes camera path keyframe at specified frame|
|p2sm_cam_path_remkfs|cmd|p2sm_cam_path_remkfs - removes all camera path keyframes|
|p2sm_cam_path_setkf|cmd|p2sm_cam_path_setkf [frame] [x] [y] [z] [pitch] [yaw] [roll] [fov] - sets the camera path keyframe|
|p2sm_cam_path_showkf|cmd|p2sm_cam_path_showkf \<frame> - display information about camera path keyframe at specified frame|
|p2sm_cam_reset|cmd|p2sm_cam_reset - resets camera to its default position|
|p2sm_cam_setang|cmd|p2sm_cam_setang \<pitch> \<yaw> [roll] - sets camera angle (requires camera Drive Mode)|
|p2sm_cam_setfov|cmd|p2sm_cam_setfov \<fov> - sets camera field of view (requires camera Drive Mode)|
|p2sm_cam_setpos|cmd|p2sm_cam_setpos \<x> \<y> \<z> - sets camera position (requires camera Drive Mode)|
|p2sm_cfg_message|cmd|p2sm_cfg_message \<message> - sends a config message to the other player in coop|
|p2sm_challenge_autostop|0|Automatically stops recording demos when the leaderboard opens after a CM run. If 2, automatically appends the run time to the demo name.|
|p2sm_challenge_autosubmit_reload_api_key|cmd|p2sm_challenge_autosubmit_reload_api_key - reload the boards API key from its file.|
|p2sm_chat|cmd|p2sm_chat - open the chat HUD|
|p2sm_cheat_hud|2|Display a warning in the HUD when cheats are active. 0 = disable, 1 = display if sv_cheats off, 2 = display always|
|p2sm_cheat_hud_x|-4|X position of the cheat warning HUD.|
|p2sm_cheat_hud_y|4|Y position of the cheat warning HUD.|
|p2sm_check_update|cmd|p2sm_check_update [release\|pre\|canary] - check whether the latest version of SAR is being used|
|p2sm_clear_lines|cmd|p2sm_clear_lines - clears all active drawline overlays|
|p2sm_cm_rightwarp|0|Fix CM wrongwarp.|
|p2sm_command_debug|0|Output debugging information to the console related to commands. **Breaks svar_capture**|
|p2sm_con_filter|0|Enable the console filter|
|p2sm_con_filter_allow|cmd|p2sm_con_filter_allow \<string> [end] - add an allow rule to the console filter, allowing until 'end' is matched|
|p2sm_con_filter_block|cmd|p2sm_con_filter_block \<string> [end] - add a disallow rule to the console filter, blocking until 'end' is matched|
|p2sm_con_filter_debug|cmd|p2sm_con_filter_debug - print the console filter rule list|
|p2sm_con_filter_default|0|Whether to allow text through the console filter by default|
|p2sm_con_filter_reset|cmd|p2sm_con_filter_reset - clear the console filter rule list|
|p2sm_con_filter_suppress_blank_lines|0|Whether to suppress blank lines in console|
|p2sm_coop_reset_progress|cmd|p2sm_coop_reset_progress - resets all coop progress|
|p2sm_cps_add|cmd|p2sm_cps_add - saves current time of timer|
|p2sm_cps_clear|cmd|p2sm_cps_clear - resets saved times of timer|
|p2sm_cps_result|cmd|p2sm_cps_result - prints result of timer checkpoints|
|p2sm_crosshair_mode|0|Set the crosshair mode :<br>0: Default crosshair<br>1: Customizable crosshair<br>2: Crosshair from .png|
|p2sm_crosshair_P1|0|Use the P1 crosshair style.|
|p2sm_crosshair_set_texture|cmd|p2sm_crosshair_set_texture \<filepath>|
|p2sm_cvarlist|cmd|p2sm_cvarlist - lists all SAR cvars and unlocked engine cvars|
|p2sm_cvars_dump|cmd|p2sm_cvars_dump [all\|game\|p2sm] - dumps all cvars to a file|
|p2sm_cvars_dump_doc|cmd|p2sm_cvars_dump_doc - dumps all SAR cvars to a file|
|p2sm_cvars_lock|cmd|p2sm_cvars_lock - restores default flags of unlocked cvars|
|p2sm_cvars_unlock|cmd|p2sm_cvars_unlock - unlocks all special cvars|
|p2sm_debug_listener|0|Prints event data of registered listener.|
|p2sm_debug_step_slope_boost|0|Debugs step slope boosts|
|p2sm_delete_alias_cmds|cmd|p2sm_delete_alias_cmds - deletes all alias commands|
|p2sm_demo_blacklist|0|Stop a set of commands from being run by demo playback.|
|p2sm_demo_blacklist_addcmd|cmd|p2sm_demo_blacklist_addcmd \<command> - add a command to the demo blacklist|
|p2sm_demo_blacklist_all|0|Stop all commands from being run by demo playback.|
|p2sm_demo_overwrite_bak|0|Rename demos to (name)_bak if they would be overwritten by recording|
|p2sm_demo_portal_interp_fix|1|Fix eye interpolation through portals in demo playback.|
|p2sm_demo_remove_broken|1|Whether to remove broken frames from demo playback|
|p2sm_demo_replay|cmd|p2sm_demo_replay - play the last recorded or played demo|
|<i title="Portal 2">p2sm_disable_challenge_stats_hud</i>|0|Disables opening the challenge mode stats HUD. Greater than 1 specifies a custom amount of ticks to leave leaderboard open. -1 closes instantly.|
|<i title="Portal 2">p2sm_disable_challenge_stats_hud_partner</i>|1|Closes the challenge mode stats HUD after your coop partner does.|
|p2sm_disable_coop_score_hud|0|Disables the coop score HUD which appears in demo playback.|
|p2sm_disable_no_focus_sleep|0|Does not yield the CPU when game is not focused.|
|p2sm_disable_progress_bar_update|0|Disables excessive usage of progress bar.|
|p2sm_disable_save_status_hud|0|Disables the saving/saved HUD which appears when you make a save.|
|p2sm_disable_steam_pause|0|Prevents pauses from steam overlay.|
|<i title="Portal 2&#10;Portal Stories: Mel&#10;Portal Reloaded">p2sm_disable_viewmodel_shadows</i>|0|Disables the shadows on the viewmodel.|
|<i title="Portal 2">p2sm_disable_weapon_sway</i>|0|Disables the viewmodel lagging behind.|
|p2sm_discord_rpc_app_id|1084419823737524294|Defines Discord Rich Presence's application ID.|
|p2sm_discord_rpc_enabled|0|Enables Discord Rich Presence integration.|
|p2sm_dpi_scale|1|Fraction to scale mouse DPI down by.|
|p2sm_drawline|cmd|p2sm_drawline \<x> \<y> \<z> \<x> \<y> \<z> [r] [g] [b] - overlay a line in the world|
|p2sm_drawline_clear|cmd|p2sm_drawline_clear - clear all active p2sm_drawlines|
|p2sm_duckjump|0|Allows duck-jumping even when fully crouched, similar to prevent_crouch_jump.|
|p2sm_dump_client_classes|cmd|p2sm_dump_client_classes - dumps all client classes to a file|
|p2sm_dump_client_datamap|cmd|p2sm_dump_client_datamap - dumps client datamap to a file|
|p2sm_dump_events|cmd|p2sm_dump_events - dumps all registered game events of the game event manager|
|p2sm_dump_server_classes|cmd|p2sm_dump_server_classes - dumps all server classes to a file|
|p2sm_dump_server_datamap|cmd|p2sm_dump_server_datamap - dumps server datamap to a file|
|p2sm_echo|cmd|p2sm_echo \<color> \<string...> - echo a string to console with a given color|
|p2sm_echo_nolf|cmd|p2sm_echo_nolf \<color> \<string...> - echo a string to console with a given color and no trailing line feed|
|p2sm_ehm_hud|0|Enables EHM debug HUD.|
|p2sm_ehm_hud_autofill|1|Whether to listen for changed slot and use it to replace the oldest one in EHM debug HUD.|
|p2sm_ehm_hud_font|2|Font used by the EHM debug HUD.|
|p2sm_ehm_hud_list_length|20|How many slots to show in the EHM debug HUD.|
|p2sm_ehm_hud_push|cmd|p2sm_ehm_hud_push \<slot> - push slot on top of the EHM debug HUD.|
|p2sm_ehm_hud_refill|cmd|p2sm_ehm_hud_refill [slot] - fills EHM debug HUD with slots starting from a given one.|
|p2sm_ehm_hud_x|-10|The X position of the EHM debug HUD.|
|p2sm_ehm_hud_y|10|The Y position of the EHM debug HUD.|
|p2sm_ei_hud|0|Draws entity inspection data.|
|p2sm_ei_hud_font_color|255 255 255 255|RGBA font color of entity inspection HUD when not recording.|
|p2sm_ei_hud_font_color2|153 23 9 255|RGBA font color of entity inspection HUD when recording.|
|p2sm_ei_hud_font_index|1|Font index of entity inspection HUD.|
|p2sm_ei_hud_x|0|X offset of entity inspection HUD.|
|p2sm_ei_hud_y|0|Y offset of entity inspection HUD.|
|p2sm_ei_hud_z|0|Z offset of entity inspection HUD.|
|p2sm_ensure_slope_boost|0|Ensures a successful slope boost.|
|p2sm_ent_info|cmd|p2sm_ent_info [selector] - show info about the entity under the crosshair or with the given name|
|p2sm_ent_slot_serial|cmd|p2sm_ent_slot_serial \<id> [value] - prints entity slot serial number, or sets it if additional parameter is specified.<br>Banned in most categories, check with the rules before use!|
|p2sm_exit|cmd|p2sm_exit - removes all function hooks, registered commands and unloads the module|
|p2sm_expand|cmd|p2sm_expand [cmd]... - run a command after expanding svar substitutions|
|p2sm_export_stats|cmd|p2sm_export_stats \<filepath> -  export the stats to the specified path in a .csv file|
|p2sm_fast_load_preset|cmd|p2sm_fast_load_preset \<preset> - sets all loading fixes to preset values|
|p2sm_fcps_anim_start|cmd|p2sm_fcps_anim_start \<id> - start animating the ID'th FCPS call.|
|p2sm_fcps_anim_step|cmd|p2sm_fcps_anim_step - step the FCPS animation forward.|
|p2sm_fcps_autostep|0|Time between automatic steps of FCPS animation. 0 to disable automatic stepping.|
|p2sm_fcps_clear|cmd|p2sm_fcps_clear - clear the FCPS event history.|
|p2sm_fcps_override|0|Override FCPS for tracing results.|
|p2sm_find_client_class|cmd|p2sm_find_client_class \<class_name> - finds specific client class tables and props with their offset|
|p2sm_find_ents|cmd|p2sm_find_ents \<selector> - finds entities in the entity list by class name|
|p2sm_find_server_class|cmd|p2sm_find_server_class \<class_name> - finds specific server class tables and props with their offset|
|<i title="Portal Reloaded">p2sm_fix_reloaded_cheats</i>|1|Overrides map execution of specific console commands in Reloaded in order to separate map usage from player usage for these commands.|
|p2sm_fix_viewmodel_bug|0|Fixes the viewmodel seemingly randomly disappearing.|
|p2sm_floor_reportals|0|Toggles floor reportals. Requires cheats.|
|p2sm_font_get_name|cmd|p2sm_font_get_name \<id> - gets the name of a font from its index|
|p2sm_font_list|cmd|p2sm_font_list - lists all available fonts|
|p2sm_force_fov|cmd|p2sm_force_fov \<fov> - forces player FOV|
|p2sm_force_qc|0|When ducking, forces view offset to always be at standing height. Requires sv_cheats to work.|
|p2sm_force_viewmodel_fov|cmd|p2sm_force_viewmodel_fov \<fov> - forces viewmodel FOV|
|p2sm_frametime_debug|0|Output debugging information to the console related to frametime.|
|p2sm_frametime_uncap|0|EXPERIMENTAL - USE AT OWN RISK. Removes the 10-1000 FPS cap on frametime. More info https://wiki.portal2.sr/Frametime|
|p2sm_function|cmd|p2sm_function \<name> [command] [args]... - create a function, replacing $1, $2 etc in the command string with the respective argument, and more. If no command is specified, prints the given function|
|p2sm_function_run|cmd|p2sm_function_run \<name> [args]... - run a function with the given arguments|
|p2sm_get_partner_id|cmd|p2sm_get_partner_id - Prints your coop partner's steam id|
|p2sm_geteyepos|cmd|p2sm_geteyepos [slot] - get the view position (portal shooting origin) and view angles of a certain player.|
|p2sm_getpos|cmd|p2sm_getpos [slot] [server\|client] - get the absolute origin and angles of a particular player from either the server or client. Defaults to slot 0 and server.|
|p2sm_give_betsrighter|cmd|p2sm_give_betsrighter [n] - gives the player in slot n (0 by default) betsrighter.|
|p2sm_give_fly|cmd|p2sm_give_fly [n] - gives the player in slot n (0 by default) preserved crouchfly.|
|p2sm_groundframes_reset|cmd|p2sm_groundframes_reset - reset recorded groundframe statistics.|
|p2sm_groundframes_total|cmd|p2sm_groundframes_total [slot] - output a summary of groundframe counts for the given player slot.|
|p2sm_hud_angles|0|Draws absolute view angles of the client.<br>0 = Default,<br>1 = XY,<br>2 = XYZ,<br>3 = X,<br>4 = Y.|
|p2sm_hud_avg|0|Draws calculated average of timer.|
|p2sm_hud_bg|0|Enable the SAR HUD background.|
|p2sm_hud_cps|0|Draws latest checkpoint of timer.|
|p2sm_hud_demo|0|Draws name, tick and time of current demo.|
|p2sm_hud_duckstate|0|Draw the state of player ducking.<br>1 - shows either ducked or standing state<br>2 - shows detailed report (requires sv_cheats)|
|p2sm_hud_ent_slot_serial|0|Draw the serial number of given entity slot.|
|p2sm_hud_eyeoffset|0|Draws player's eye offset.<br>0 = Default,<br>1 = eye offset including precision error,<br>2 = raw eye offset.|
|p2sm_hud_font_color|255 255 255 255|RGBA font color of HUD.|
|p2sm_hud_font_index|0|Font index of HUD.|
|p2sm_hud_fps|0|Show fps (frames per second) on the SAR hud.<br>1 - Show fps<br>2 - Show fps with fps cap|
|p2sm_hud_frame|0|Draws current frame count.|
|p2sm_hud_ghost_spec|0|Show the name of the ghost you're currently spectating.|
|p2sm_hud_grounded|0|Draws the state of player being on ground.|
|p2sm_hud_groundframes|0|Draws the number of ground frames since last landing. Setting it to 2 preserves the value.|
|p2sm_hud_groundspeed|0|Draw the speed of the player upon leaving the ground.|
|p2sm_hud_hide_text|cmd|p2sm_hud_hide_text \<id\|all> - hides the nth text value in the HUD|
|p2sm_hud_inspection|0|Draws entity inspection data.|
|p2sm_hud_jump|0|Draws current jump distance.|
|p2sm_hud_jump_peak|0|Draws longest jump distance.|
|p2sm_hud_jumps|0|Draws total jump count.|
|p2sm_hud_last_frame|0|Draws last saved frame value.|
|p2sm_hud_last_session|0|Draws value of latest completed session.|
|p2sm_hud_orange_only|0|Only display the SAR HUD for orange, for solo coop (fullscreen PIP).|
|p2sm_hud_order_bottom|cmd|p2sm_hud_order_bottom \<name> - orders hud element to bottom|
|p2sm_hud_order_reset|cmd|p2sm_hud_order_reset - resets order of hud elements|
|p2sm_hud_order_top|cmd|p2sm_hud_order_top \<name> - orders hud element to top|
|p2sm_hud_pause_timer|0|Draws current value of pause timer.|
|p2sm_hud_portal_angles|0|Draw the camera angles of the last primary portal shot.|
|p2sm_hud_portal_angles_2|0|Draw the camera angles of the last secondary portal shot.|
|p2sm_hud_portals|0|Draws total portal count.|
|p2sm_hud_position|0|Draws absolute position of the client.<br>0 = Default,<br>1 = Player position,<br>2 = Camera (shoot) position.|
|p2sm_hud_precision|2|Precision of HUD numbers.|
|p2sm_hud_rainbow|-1|Enables the rainbow HUD mode. -1 = default, 0 = disable, 1 = enable.|
|p2sm_hud_session|0|Draws current session tick.|
|p2sm_hud_set_text|cmd|p2sm_hud_set_text \<id> \<text>... - sets and shows the nth text value in the HUD|
|p2sm_hud_set_text_color|cmd|p2sm_hud_set_text_color \<id> [color] - sets the color of the nth text value in the HUD. Reset by not giving color.|
|p2sm_hud_shorthand|0|Whether to hide the text part of HUD elements.|
|p2sm_hud_show_text|cmd|p2sm_hud_show_text \<id\|all> - shows the nth text value in the HUD|
|p2sm_hud_spacing|1|Spacing between elements of HUD.|
|p2sm_hud_steps|0|Draws total step count.|
|p2sm_hud_strafesync_color|0 150 250 255|RGBA font color of strafesync HUD.|
|p2sm_hud_strafesync_font_index|1|Font index of strafesync HUD.|
|p2sm_hud_strafesync_offset_x|0|X offset of strafesync HUD.|
|p2sm_hud_strafesync_offset_y|1000|Y offset of strafesync HUD.|
|p2sm_hud_strafesync_split_offset_y|1050|Y offset of strafesync HUD.|
|p2sm_hud_sum|0|Draws summary value of sessions.|
|p2sm_hud_tastick|0|Draws current TAS playback tick.|
|p2sm_hud_tbeam|0|Draw the name of the funnel player is currently in (requires sv_cheats).|
|p2sm_hud_tbeam_count|0|Draw the player's funnel count (requires sv_cheats).|
|p2sm_hud_timer|0|Draws current value of timer.|
|p2sm_hud_toggle_text|cmd|p2sm_hud_toggle_text \<id> - toggles the nth text value in the HUD|
|p2sm_hud_trace|0|Draws info about current trace bbox tick.|
|p2sm_hud_velang|0|Draw the angle of the player's horizontal velocity vector.<br>0 = Default,<br>1 = yaw,<br>2 = pitch yaw.|
|p2sm_hud_velocity|0|Draws velocity of the client.<br>0 = Default,<br>1 = X, Y, Z<br>2 = X:Y<br>3 = X:Y, Z<br>4 = X:Y:Z<br>5 = X, Y, X:Y, Z|
|p2sm_hud_velocity_peak|0|Draws last saved velocity peak.|
|p2sm_hud_velocity_precision|2|Precision of velocity HUD numbers.|
|p2sm_hud_x|2|X padding of HUD.|
|p2sm_hud_y|2|Y padding of HUD.|
|p2sm_ihud|0|Enables or disables movement inputs HUD of client.|
|p2sm_ihud_add_key|cmd|p2sm_ihud_add_key \<key>|
|p2sm_ihud_analog_image_scale|0.6|Scale of analog input images against max extent.|
|p2sm_ihud_analog_view_deshake|0|Try to eliminate small fluctuations in the movement analog.|
|p2sm_ihud_clear_background|cmd|p2sm_ihud_clear_background|
|p2sm_ihud_grid_padding|2|Padding between grid squares of input HUD.|
|p2sm_ihud_grid_size|60|Grid square size of input HUD.|
|p2sm_ihud_modify|cmd|p2sm_ihud_modify \<element\|all> [param=value]... - modifies parameters in given element.<br>Params: enabled, text, pos, x, y, width, height, font, background, highlight, textcolor, texthighlight, image, highlightimage, minhold.|
|p2sm_ihud_preset|cmd|p2sm_ihud_preset \<preset> - modifies input hud based on given preset|
|p2sm_ihud_set_background|cmd|p2sm_ihud_set_background \<path> \<grid x> \<grid y> \<grid w> \<grid h>|
|p2sm_ihud_setpos|cmd|p2sm_ihud_setpos \<top\|center\|bottom\|y\|y%> \<left\|center\|right\|x\|x%> - automatically sets the position of input HUD.|
|p2sm_ihud_x|2|X position of input HUD.|
|p2sm_ihud_y|-2|Y position of input HUD.|
|p2sm_import_stats|cmd|p2sm_import_stats \<filePath> - import the stats from the specified .csv file|
|p2sm_inspection_export|cmd|p2sm_inspection_export \<file_name> - saves recorded entity data to a csv file|
|p2sm_inspection_index|cmd|p2sm_inspection_index - sets entity index for inspection|
|p2sm_inspection_print|cmd|p2sm_inspection_print - prints recorded entity data|
|p2sm_inspection_save_every_tick|0|Saves inspection data even when session tick does not increment.|
|p2sm_inspection_start|cmd|p2sm_inspection_start - starts recording entity data|
|p2sm_inspection_stop|cmd|p2sm_inspection_stop - stops recording entity data|
|p2sm_jumpboost|0|Enables special game movement on the server.<br>0 = Default,<br>1 = Orange Box Engine,<br>2 = Pre-OBE.|
|p2sm_list_client_classes|cmd|p2sm_list_client_classes - lists all client classes|
|p2sm_list_ents|cmd|p2sm_list_ents - lists entities|
|p2sm_list_server_classes|cmd|p2sm_list_server_classes - lists all server classes|
|p2sm_load_delay|0|Delay for this number of milliseconds at the end of a load.|
|p2sm_loads_norender|0|Temporarily set mat_norendering to 1 during loads|
|p2sm_loads_uncap|0|Temporarily set fps_max to 0 during loads|
|p2sm_lphud|0|Enables or disables the portals display on screen.|
|p2sm_lphud_font|92|Change font of portal counter.|
|p2sm_lphud_reset|cmd|p2sm_lphud_reset - resets lp counter|
|p2sm_lphud_reset_on_changelevel|0|Reset the lp counter on any changelevel or restart_level. Useful for ILs.|
|p2sm_lphud_set|cmd|p2sm_lphud_set \<number> - sets lp counter to given number|
|p2sm_lphud_setpos|cmd|p2sm_lphud_setpos \<top\|center\|bottom\|y\|y%> \<left\|center\|right\|x\|x%> - automatically sets the position of least portals HUD.|
|p2sm_lphud_x|-10|x pos of lp counter.|
|p2sm_lphud_y|-10|y pos of lp counter.|
|p2sm_metronome|0|Enable metronome.|
|p2sm_metronome_beats|4|Set the number of beats per bar for the metronome.|
|p2sm_metronome_bpm|60|Set the beats per minute for the metronome.|
|p2sm_metronome_sound|ui/ui_coop_hud_focus_01|Set the sound to play for the metronome.|
|p2sm_metronome_sound_bar|ui/ui_coop_hud_unfocus_01|Set the sound to play for the metronome bar.|
|p2sm_metronome_volume|1|Set the volume for the metronome.|
|p2sm_minimap_load|cmd|p2sm_minimap_load \<filename> - load a minimap from a JSON file.|
|p2sm_minimap_max_height|1000|The maximum height of the minimap.|
|p2sm_minimap_max_width|500|The maximum width of the minimap.|
|p2sm_minimap_player_color|255 0 0 255|The color of the circle representing the player on the minimap.|
|p2sm_minimap_x|-10|The X position of the minimap.|
|p2sm_minimap_y|10|The Y position of the minimap.|
|p2sm_mtrigger_legacy|0||
|p2sm_mtrigger_legacy_format|!seg -> !tt (!st)|Formatting of the text that is displayed in the chat (!map - for map name, !seg - for segment name, !tt - for total time, !st - for split time).|
|p2sm_mtrigger_legacy_textcolor|255 176 0|The color of the text that is displayed in the chat.|
|p2sm_netmessage_debug|0|Debug NetMessages.|
|p2sm_netmessage_enable|1|Enable sending NetMessages. Disabling this can break other features.|
|p2sm_nextdemo|cmd|p2sm_nextdemo - plays the next demo in demo queue|
|p2sm_on_cfg_message|cmd|p2sm_on_cfg_message \<command> [args]... - registers a command to be run when partner sends a custom message (_p2sm_cfg_message svar)|
|p2sm_on_cfg_message_clear|cmd|p2sm_on_cfg_message_clear - clears commands registered on event "cfg_message"|
|p2sm_on_cfg_message_list|cmd|p2sm_on_cfg_message_list - lists commands registered on event "cfg_message"|
|p2sm_on_config_exec|cmd|p2sm_on_config_exec \<command> [args]... - registers a command to be run on config.cfg exec|
|p2sm_on_config_exec_clear|cmd|p2sm_on_config_exec_clear - clears commands registered on event "config_exec"|
|p2sm_on_config_exec_list|cmd|p2sm_on_config_exec_list - lists commands registered on event "config_exec"|
|p2sm_on_coop_reset_done|cmd|p2sm_on_coop_reset_done \<command> [args]... - registers a command to be run when coop reset is completed|
|p2sm_on_coop_reset_done_clear|cmd|p2sm_on_coop_reset_done_clear - clears commands registered on event "coop_reset_done"|
|p2sm_on_coop_reset_done_list|cmd|p2sm_on_coop_reset_done_list - lists commands registered on event "coop_reset_done"|
|p2sm_on_coop_reset_remote|cmd|p2sm_on_coop_reset_remote \<command> [args]... - registers a command to be run when coop reset run remotely|
|p2sm_on_coop_reset_remote_clear|cmd|p2sm_on_coop_reset_remote_clear - clears commands registered on event "coop_reset_remote"|
|p2sm_on_coop_reset_remote_list|cmd|p2sm_on_coop_reset_remote_list - lists commands registered on event "coop_reset_remote"|
|p2sm_on_coop_spawn|cmd|p2sm_on_coop_spawn \<command> [args]... - registers a command to be run on coop spawn|
|p2sm_on_coop_spawn_clear|cmd|p2sm_on_coop_spawn_clear - clears commands registered on event "coop_spawn"|
|p2sm_on_coop_spawn_list|cmd|p2sm_on_coop_spawn_list - lists commands registered on event "coop_spawn"|
|p2sm_on_demo_start|cmd|p2sm_on_demo_start \<command> [args]... - registers a command to be run when demo playback starts|
|p2sm_on_demo_start_clear|cmd|p2sm_on_demo_start_clear - clears commands registered on event "demo_start"|
|p2sm_on_demo_start_list|cmd|p2sm_on_demo_start_list - lists commands registered on event "demo_start"|
|p2sm_on_demo_stop|cmd|p2sm_on_demo_stop \<command> [args]... - registers a command to be run when demo playback stops|
|p2sm_on_demo_stop_clear|cmd|p2sm_on_demo_stop_clear - clears commands registered on event "demo_stop"|
|p2sm_on_demo_stop_list|cmd|p2sm_on_demo_stop_list - lists commands registered on event "demo_stop"|
|p2sm_on_exit|cmd|p2sm_on_exit \<command> [args]... - registers a command to be run on game exit|
|p2sm_on_exit_clear|cmd|p2sm_on_exit_clear - clears commands registered on event "exit"|
|p2sm_on_exit_list|cmd|p2sm_on_exit_list - lists commands registered on event "exit"|
|p2sm_on_flags|cmd|p2sm_on_flags \<command> [args]... - registers a command to be run when CM flags are hit|
|p2sm_on_flags_clear|cmd|p2sm_on_flags_clear - clears commands registered on event "flags"|
|p2sm_on_flags_list|cmd|p2sm_on_flags_list - lists commands registered on event "flags"|
|p2sm_on_load|cmd|p2sm_on_load \<command> [args]... - registers a command to be run on session start|
|p2sm_on_load_clear|cmd|p2sm_on_load_clear - clears commands registered on event "load"|
|p2sm_on_load_list|cmd|p2sm_on_load_list - lists commands registered on event "load"|
|p2sm_on_not_pb|cmd|p2sm_on_not_pb \<command> [args]... - registers a command to be run when auto-submitter detects not PB|
|p2sm_on_not_pb_clear|cmd|p2sm_on_not_pb_clear - clears commands registered on event "not_pb"|
|p2sm_on_not_pb_list|cmd|p2sm_on_not_pb_list - lists commands registered on event "not_pb"|
|p2sm_on_pb|cmd|p2sm_on_pb \<command> [args]... - registers a command to be run when auto-submitter detects PB|
|p2sm_on_pb_clear|cmd|p2sm_on_pb_clear - clears commands registered on event "pb"|
|p2sm_on_pb_list|cmd|p2sm_on_pb_list - lists commands registered on event "pb"|
|p2sm_on_renderer_finish|cmd|p2sm_on_renderer_finish \<command> [args]... - registers a command to be run when renderer finishes|
|p2sm_on_renderer_finish_clear|cmd|p2sm_on_renderer_finish_clear - clears commands registered on event "renderer_finish"|
|p2sm_on_renderer_finish_list|cmd|p2sm_on_renderer_finish_list - lists commands registered on event "renderer_finish"|
|p2sm_on_renderer_start|cmd|p2sm_on_renderer_start \<command> [args]... - registers a command to be run when renderer starts|
|p2sm_on_renderer_start_clear|cmd|p2sm_on_renderer_start_clear - clears commands registered on event "renderer_start"|
|p2sm_on_renderer_start_list|cmd|p2sm_on_renderer_start_list - lists commands registered on event "renderer_start"|
|p2sm_on_session_end|cmd|p2sm_on_session_end \<command> [args]... - registers a command to be run on session end|
|p2sm_on_session_end_clear|cmd|p2sm_on_session_end_clear - clears commands registered on event "session_end"|
|p2sm_on_session_end_list|cmd|p2sm_on_session_end_list - lists commands registered on event "session_end"|
|p2sm_on_speedrun_finish|cmd|p2sm_on_speedrun_finish \<command> [args]... - registers a command to be run when a speedrun finishes|
|p2sm_on_speedrun_finish_clear|cmd|p2sm_on_speedrun_finish_clear - clears commands registered on event "speedrun_finish"|
|p2sm_on_speedrun_finish_list|cmd|p2sm_on_speedrun_finish_list - lists commands registered on event "speedrun_finish"|
|p2sm_on_stuck|cmd|p2sm_on_stuck \<command> [args]... - registers a command to be run when the player gets stuck (singleplayer) (requires cheats)|
|p2sm_on_stuck_clear|cmd|p2sm_on_stuck_clear - clears commands registered on event "stuck"|
|p2sm_on_stuck_list|cmd|p2sm_on_stuck_list - lists commands registered on event "stuck"|
|p2sm_on_tas_end|cmd|p2sm_on_tas_end \<command> [args]... - registers a command to be run when TAS script playback ends|
|p2sm_on_tas_end_clear|cmd|p2sm_on_tas_end_clear - clears commands registered on event "tas_end"|
|p2sm_on_tas_end_list|cmd|p2sm_on_tas_end_list - lists commands registered on event "tas_end"|
|p2sm_on_tas_start|cmd|p2sm_on_tas_start \<command> [args]... - registers a command to be run when TAS script playback starts|
|p2sm_on_tas_start_clear|cmd|p2sm_on_tas_start_clear - clears commands registered on event "tas_start"|
|p2sm_on_tas_start_list|cmd|p2sm_on_tas_start_list - lists commands registered on event "tas_start"|
|p2sm_paint_reseed|cmd|p2sm_paint_reseed \<seed> - re-seed all paint sprayers in the map to the given value (-9999 to 9999 inclusive)|
|p2sm_patch_bhop|0|Patches bhop by limiting wish direction if your velocity is too high.|
|p2sm_patch_cfg|0|Patches Crouch Flying Glitch.|
|p2sm_patch_major_angle_decay|0|Patches major pitch angle decay. Requires cheats.|
|p2sm_patch_minor_angle_decay|0|Patches minor pitch angle decay present on Windows version of the game.|
|p2sm_patch_small_angle_decay|0|Patches small angle decay (not minor decay).|
|p2sm_patch_viewcontrol|1|Disable camera controllers before changing levels to prevent visual glitches.|
|p2sm_pause_at|-1|Pause at the specified tick. -1 to deactivate it.|
|p2sm_pause_for|0|Pause for this amount of ticks.|
|p2sm_performance_hud|0|Enables the performance HUD.<br>1 = normal,<br>2 = stats only.|
|p2sm_performance_hud_clear|cmd|Clears the performance HUD data.|
|p2sm_performance_hud_duration|60|How long (in frames) to measure performance for.|
|p2sm_performance_hud_font_index|6|Font index of the performance HUD.|
|p2sm_performance_hud_x|20|X position of the performance HUD.|
|p2sm_performance_hud_y|300|Y position of the performance HUD.|
|p2sm_pip_align|cmd|p2sm_pip_align \<top\|center\|bottom> \<left\|center\|right> - aligns the remote view.|
|p2sm_placement_helper_hud|0|Visually displays all portal placement helpers (requires sv_cheats).|
|p2sm_portalcolor_enable|0|Enable custom portal colors.|
|p2sm_portalcolor_mp1_1|31 127 210|Portal color for Atlas (blue)'s left portal.|
|p2sm_portalcolor_mp1_2|19 0 210|Portal color for Atlas (blue)'s right portal.|
|p2sm_portalcolor_mp2_1|255 179 31|Portal color for P-Body (orange)'s left portal.|
|p2sm_portalcolor_mp2_2|57 2 2|Portal color for P-Body (orange)'s right portal.|
|p2sm_portalcolor_rainbow|0|Rainbow portals!|
|p2sm_portalcolor_sp_1|64 160 255|Portal color for Chell's left portal. r_portal_fastpath 0 required.|
|p2sm_portalcolor_sp_2|255 160 32|Portal color for Chell's right portal. r_portal_fastpath 0 required.|
|p2sm_portalgun_hud|0|Enables the portalgun HUD.|
|p2sm_portalgun_hud_x|5|The x position of the portalgun HUD.|
|p2sm_portalgun_hud_y|5|The y position of the portalgun HUD.|
|p2sm_portals_thru_portals|0|Allow firing portals through portals.|
|p2sm_pp_hud|0|Enables or disables the portals placement HUD.|
|p2sm_pp_hud_font|0|Change font of portal placement hud.|
|p2sm_pp_hud_opacity|100|Opacity of portal previews.|
|p2sm_pp_hud_show_blue|0|Enables or disables blue portal preview.|
|p2sm_pp_hud_show_orange|0|Enables or disables orange portal preview.|
|p2sm_pp_hud_x|5|x pos of portal placement hud.|
|p2sm_pp_hud_y|5|y pos of portal placement hud.|
|p2sm_pp_scan_reset|cmd|p2sm_pp_scan_reset - reset ppscan.|
|p2sm_pp_scan_set|cmd|p2sm_pp_scan_set - set the ppscan point where you're aiming.|
|p2sm_prevent_ehm|0|Prevents Entity Handle Misinterpretation (EHM) from happening.|
|p2sm_prevent_mat_snapshot_recompute|0|Shortens loading times by preventing state snapshot recomputation.|
|p2sm_print_stats|cmd|p2sm_print_stats - prints your statistics if those are loaded|
|p2sm_quickhud_mode|0|Set the quickhud mode :<br>0: Default quickhud<br>1: Customizable quickhud<br>2: quickhud from .png|
|p2sm_quickhud_set_texture|cmd|p2sm_quickhud_set_texture \<filepath> - enter the base name, it will search for \<filepath>1.png, \<filepath>2.png, \<filepath>3.png and \<filepath>4.png<br>ex: p2sm_quickhud_set_texture "crosshair/basic" looks for "crosshair/basic1.png", etc|
|p2sm_record_at|-1|Start recording a demo at the tick specified. Will use p2sm_record_at_demo_name.|
|p2sm_record_at_demo_name|chamber|Name of the demo automatically recorded.|
|p2sm_record_at_increment|0|Increment automatically the demo name.|
|p2sm_record_mkdir|1|Automatically create directories for demos if necessary.|
|p2sm_record_prefix||A string to prepend to recorded demo names. Can include strftime format codes.|
|p2sm_rename|cmd|p2sm_rename \<name> - changes your name|
|p2sm_render_abitrate|160|Audio bitrate used in renders (kbit/s)|
|p2sm_render_acodec|aac|Audio codec used in renders (aac, ac3, vorbis, opus, flac)|
|p2sm_render_autostart|0|Whether to automatically start when demo playback begins|
|p2sm_render_autostart_extension|mp4|The file extension (and hence container format) to use for automatically started renders.|
|p2sm_render_autostop|1|Whether to automatically stop when `__END__` is seen in demo playback|
|p2sm_render_blend|0|How many frames to blend for each output frame; 1 = do not blend, 0 = automatically determine based on host_framerate|
|p2sm_render_blend_mode|1|What type of frameblending to use. 0 = linear, 1 = Gaussian|
|p2sm_render_finish|cmd|p2sm_render_finish - stop rendering frames|
|p2sm_render_fps|60|Render output FPS|
|p2sm_render_merge|0|When set, merge all the renders until p2sm_render_finish is entered|
|p2sm_render_quality|35|Render output quality, higher is better (50=lossless)|
|p2sm_render_sample_rate|44100|Audio output sample rate|
|p2sm_render_shutter_angle|360|The shutter angle to use for rendering in degrees.|
|p2sm_render_skip_coop_videos|1|When set, don't include coop loading time in renders|
|p2sm_render_start|cmd|p2sm_render_start \<file> - start rendering frames to the given video file|
|p2sm_render_vbitrate|40000|Video bitrate used in renders (kbit/s)|
|p2sm_render_vcodec|h264|Video codec used in renders (h264, hevc, vp8, vp9, dnxhd)|
|p2sm_rhythmgame|0|Show a HUD indicating your groundframes as rhythm game like popups.|
|p2sm_rhythmgame_combo|1|Show a combo counter on the rhythm game HUD.|
|p2sm_rhythmgame_font|64|The font to use for the rhythm game HUD.|
|p2sm_rng_load|cmd|p2sm_rng_load [filename] - load RNG seed data on next session start. If filename isn't given, use last TAS script path|
|p2sm_rng_save|cmd|p2sm_rng_save [filename] - save RNG seed data to the specified file. If filename isn't given, use last TAS script path|
|p2sm_ruler_add|cmd|p2sm_ruler_add \<x> \<y> \<z> \<x> \<y> \<z> - adds a ruler to a set of currently drawn rulers.|
|p2sm_ruler_clear|cmd|p2sm_ruler_clear - clear all created rulers|
|p2sm_ruler_creator|0|Enables or disables ruler creator<br>0 = Ruler creator disabled<br>1 = Point-to-point ruler creator<br>2 = Player-to-point ruler creator|
|p2sm_ruler_creator_set|cmd|p2sm_ruler_creator_set - sets the point, progressing the ruler creation process.|
|p2sm_ruler_draw|1|Sets the drawing mode of the ruler<br>0 = rulers are not drawn<br>1 = lines, length and angles are drawn (default)<br>2 = only lines and length are drawn<br>3 = only lines are drawn<br>4 = lines, deltas, angles and point origins are drawn|
|p2sm_ruler_grid_align|1|Aligns ruler creation point to the grid of specified size.|
|p2sm_ruler_max_trace_dist|16384|Sets maximum trace distance for placing ruler points.|
|p2sm_scrollspeed|0|Show a HUD indicating your scroll speed for coop.<br>1 = bar and tiles,<br>2 = bar only,<br>3 = tiles only.|
|p2sm_scrollspeed_bar_x|30|Scroll speed bar x offset.|
|p2sm_scrollspeed_bar_y|210|Scroll speed bar y offset.|
|p2sm_scrollspeed_x|0|Scroll speed HUD x offset.|
|p2sm_scrollspeed_y|210|Scroll speed HUD y offset.|
|p2sm_seamshot_finder|0|Enables or disables seamshot finder overlay.|
|p2sm_session|cmd|p2sm_session - prints the current tick of the server since it has loaded|
|p2sm_show_entinp|0|Print all entity inputs to console.|
|p2sm_skiptodemo|cmd|p2sm_skiptodemo \<demoname> - skip demos in demo queue to this demo|
|p2sm_speedrun_autoreset_clear|cmd|p2sm_speedrun_autoreset_clear - stop using the autoreset file|
|p2sm_speedrun_autoreset_invert|0|Invert the autoreset behavior. If set to 1, automatically reset if the last split was *faster* than the defined time.|
|p2sm_speedrun_autoreset_load|cmd|p2sm_speedrun_autoreset_load \<file> - load the given file of autoreset timestamps and use it while the speedrun timer is active|
|p2sm_speedrun_autostop|0|Automatically stop recording demos when a speedrun finishes. If 2, automatically append the run time to the demo name.|
|p2sm_speedrun_category|cmd|p2sm_speedrun_category [category] - get or set the speedrun category|
|p2sm_speedrun_category_add_rule|cmd|p2sm_speedrun_category_add_rule \<category> \<rule> - add a rule to a speedrun category|
|p2sm_speedrun_category_create|cmd|p2sm_speedrun_category_create \<category> - create a new speedrun category with the given name|
|p2sm_speedrun_category_remove|cmd|p2sm_speedrun_category_remove \<category> - delete the given speedrun category|
|p2sm_speedrun_category_remove_rule|cmd|p2sm_speedrun_category_remove_rule \<category> \<rule> - remove a rule from a speedrun category|
|p2sm_speedrun_cc_finish|cmd|p2sm_speedrun_cc_finish - finish the category creator|
|p2sm_speedrun_cc_place|cmd|p2sm_speedrun_cc_place - place a trigger-ey rule in the world|
|p2sm_speedrun_cc_place_start|cmd|p2sm_speedrun_cc_place_start \<rule name> \<rule type> [options]... - start placing a trigger-ey rule in the world|
|p2sm_speedrun_cc_rule|cmd|p2sm_speedrun_cc_rule \<rule name> \<rule type> [options]... - add a rule to the category currently being created|
|p2sm_speedrun_cc_start|cmd|p2sm_speedrun_cc_start \<category name> [default options]... - start the category creator|
|p2sm_speedrun_draw_triggers|0|Draw the triggers associated with speedrun rules in the world.|
|p2sm_speedrun_export|cmd|p2sm_speedrun_export \<filename> - export the speedrun result to the specified CSV file|
|p2sm_speedrun_export_all|cmd|p2sm_speedrun_export_all \<filename> - export the results of many speedruns to the specified CSV file|
|p2sm_speedrun_get_mtriggers|cmd|p2sm_speedrun_get_mtriggers \<rank=wr> - prints mtriggers of specific run.|
|p2sm_speedrun_get_mtriggers_map|cmd|p2sm_speedrun_get_mtriggers_map \<map=current> \<rank=wr> - prints mtriggers of specific run on specific map.|
|p2sm_speedrun_offset|0|Start speedruns with this time on the timer.|
|p2sm_speedrun_pause|cmd|p2sm_speedrun_pause - pause the speedrun timer|
|p2sm_speedrun_recover|cmd|p2sm_speedrun_recover \<ticks\|time> - recover a crashed run by resuming the timer at the given time on next load|
|p2sm_speedrun_reset|cmd|p2sm_speedrun_reset - reset the speedrun timer|
|p2sm_speedrun_reset_categories|cmd|p2sm_speedrun_reset_categories - delete all custom categories and rules, reverting to the builtin ones|
|p2sm_speedrun_reset_export|cmd|p2sm_speedrun_reset_export - reset the log of complete and incomplete runs to be exported|
|p2sm_speedrun_result|cmd|p2sm_speedrun_result - print the speedrun result|
|p2sm_speedrun_resume|cmd|p2sm_speedrun_resume - resume the speedrun timer|
|p2sm_speedrun_rule|cmd|p2sm_speedrun_rule [rule] - show information about speedrun rules|
|p2sm_speedrun_rule_create|cmd|p2sm_speedrun_rule_create \<name> \<type> [option=value]... - create a speedrun rule with the given name, type, and options|
|p2sm_speedrun_rule_remove|cmd|p2sm_speedrun_rule_remove \<rule> - delete the given speedrun rule|
|p2sm_speedrun_skip_cutscenes|0|Skip Tube Ride and Long Fall in Portal 2.|
|p2sm_speedrun_smartsplit|1|Only split the speedrun timer a maximum of once per map.|
|p2sm_speedrun_split|cmd|p2sm_speedrun_split - perform a split on the speedrun timer|
|p2sm_speedrun_start|cmd|p2sm_speedrun_start - start the speedrun timer|
|p2sm_speedrun_start_on_load|0|Automatically start the speedrun timer when a map is loaded. 2 = restart if active.|
|p2sm_speedrun_stop|cmd|p2sm_speedrun_stop - stop the speedrun timer|
|p2sm_speedrun_stop_in_menu|0|Automatically stop the speedrun timer when the menu is loaded.|
|p2sm_speedrun_time_pauses|0|Include time spent paused in the speedrun timer.|
|p2sm_speedrun_triggers_info|0|Print player velocity (and position) upon mtrigger activation.<br>1 - position and velocity<br>2 - only horizontal velocity|
|p2sm_sr_hud|0|Draws speedrun timer. 1 = speedrun timer, 2 = speedrun and split timer.|
|p2sm_sr_hud_bg|0|Draw a background behind the speedrun timer.|
|p2sm_sr_hud_font_color|255 255 255 255|RGBA font color of speedrun timer HUD.|
|p2sm_sr_hud_font_index|70|Font index of speedrun timer HUD.|
|p2sm_sr_hud_font_index_2|71|Font index of speedrun split timer HUD.|
|p2sm_sr_hud_x|0|X offset of speedrun timer HUD.|
|p2sm_sr_hud_y|100|Y offset of speedrun timer HUD.|
|p2sm_startdemos|cmd|p2sm_startdemos \<demoname> - improved version of startdemos. Use 'stopdemo' to stop playing demos|
|p2sm_startdemosfolder|cmd|p2sm_startdemosfolder \<folder name> - plays all the demos in the specified folder by alphabetic order|
|p2sm_statcounter_filePath|Stats/phunkpaiDWPS.csv|Path to the statcounter .csv file.|
|p2sm_stats_auto_reset|0|Resets all stats automatically.<br>0 = Default,<br>1 = Restart or disconnect only,<br>2 = Any load & p2sm_timer_start.<br>Note: Portal counter is not part of the "stats" feature.|
|p2sm_stats_jump|cmd|p2sm_stats_jump - prints jump stats|
|p2sm_stats_jumps_reset|cmd|p2sm_stats_jumps_reset - resets total jump count and jump distance peak|
|p2sm_stats_jumps_xy|0|Saves jump distance as 2D vector.|
|p2sm_stats_reset|cmd|p2sm_stats_reset - resets all saved stats|
|p2sm_stats_steps|cmd|p2sm_stats_steps - prints total amount of steps|
|p2sm_stats_steps_reset|cmd|p2sm_stats_steps_reset - resets total step count|
|p2sm_stats_velocity|cmd|p2sm_stats_velocity - prints velocity stats|
|p2sm_stats_velocity_peak_xy|0|Saves velocity peak as 2D vector.|
|p2sm_stats_velocity_reset|cmd|p2sm_stats_velocity_reset - resets velocity peak|
|p2sm_stitcher|0|Enable the image stitcher.|
|p2sm_stitcher_reset|cmd|p2sm_stitcher_reset - reset the stitcher.|
|p2sm_stop|cmd|p2sm_stop \<name> - stop recording the current demo and rename it to 'name' (not considering p2sm_record_prefix)|
|p2sm_strafe_quality|0|Enables or disables the strafe quality HUD.|
|p2sm_strafe_quality_height|50|The height of the strafe quality HUD.|
|p2sm_strafe_quality_ticks|40|The number of ticks to average over for the strafe quality HUD.|
|p2sm_strafe_quality_width|300|The width of the strafe quality HUD.|
|p2sm_strafehud|0|Enables or disables strafe hud.|
|p2sm_strafehud_avg_sample_count|60|How many samples to use for average counter.|
|p2sm_strafehud_detail_scale|4|The detail scale for the lines of hud.|
|p2sm_strafehud_font|13|Font used by strafe hud.|
|p2sm_strafehud_lock_mode|1|Lock mode used by strafe hud:<br>0 - view direction<br>1 - velocity direction<br>2 - absolute angles|
|p2sm_strafehud_match_accel_scale|0|Match the scales for minimum and maximum deceleration.|
|p2sm_strafehud_size|256|The width and height of the strafe hud.|
|p2sm_strafehud_use_friction|0|Use ground friction when calculating acceleration.|
|p2sm_strafehud_x|-10|The X position of the strafe hud.|
|p2sm_strafehud_y|10|The Y position of the strafe hud.|
|p2sm_strafesync|0|Shows strafe sync stats.|
|p2sm_strafesync_noground|1|0: Always run.<br>1: Do not run when on ground.|
|p2sm_strafesync_pause|cmd|p2sm_strafesync_pause - pause strafe sync session|
|p2sm_strafesync_reset|cmd|p2sm_strafesync_reset - reset strafe sync session|
|p2sm_strafesync_resume|cmd|p2sm_strafesync_resume - resume strafe sync session|
|p2sm_strafesync_session_time|0|In seconds. How much time should pass until session is reset.<br>If 0, you'll have to reset the session manually.|
|p2sm_strafesync_split|cmd|p2sm_strafesync_split - makes a new split|
|p2sm_sum_during_session|1|Updates the summary counter automatically during a session.|
|p2sm_sum_here|cmd|p2sm_sum_here - starts counting total ticks of sessions|
|p2sm_sum_result|cmd|p2sm_sum_result - prints result of summary|
|p2sm_sum_stop|cmd|p2sm_sum_stop - stops summary counter|
|p2sm_tas_advance|cmd|p2sm_tas_advance - advances TAS playback by one tick|
|p2sm_tas_autosave_raw|1|Enables automatic saving of raw, processed TAS scripts.|
|p2sm_tas_check_disable|0|Globally disable the 'check' TAS tool.|
|p2sm_tas_check_max_replays|15|Maximum replays for the 'check' TAS tool until it gives up.|
|p2sm_tas_debug|0|Debug TAS information. 0 - none, 1 - basic, 2 - all.|
|p2sm_tas_dump_player_info|0|Dump player info for each tick of TAS playback to a file.|
|p2sm_tas_dump_usercmd|0|Dump TAS-generated usercmds to a file.|
|p2sm_tas_interpolate|0|Preserve client interpolation in TAS playback.|
|p2sm_tas_pause|cmd|p2sm_tas_pause - pauses TAS playback|
|p2sm_tas_pauseat|0|Pauses the TAS playback on specified tick.|
|p2sm_tas_play|cmd|p2sm_tas_play \<filename> [filename2] - plays a TAS script with given name. If two script names are given, play coop|
|p2sm_tas_play_single|cmd|p2sm_tas_play_single \<filename> [slot] - plays a single coop TAS script, giving the player control of the other slot.|
|p2sm_tas_playback_rate|1.0|The rate at which to play back TAS scripts.|
|p2sm_tas_protocol_connect|cmd|p2sm_tas_protocol_connect \<ip address> \<port> - connect to the TAS protocol server.<br>ex: '127.0.0.1 5666' - '89.10.20.20 5666'.|
|p2sm_tas_protocol_reconnect_delay|0|A number of seconds after which reconnection to TAS protocol server should be made.<br>0 means no reconnect attempts will be made.|
|p2sm_tas_protocol_send_msg|cmd|p2sm_tas_protocol_send_msg \<message> - sends a message over TAS protocol.|
|p2sm_tas_protocol_server|cmd|p2sm_tas_protocol_server [port] - starts a TAS protocol server. Port is 6555 by default.|
|p2sm_tas_protocol_stop|cmd|p2sm_tas_protocol_stop - stops every TAS protocol related connection.|
|p2sm_tas_real_controller_debug|0|Debugs controller.|
|p2sm_tas_replay|cmd|p2sm_tas_replay - replays the last played TAS|
|p2sm_tas_restore_fps|1|Restore fps_max and host_framerate after TAS playback.|
|p2sm_tas_resume|cmd|p2sm_tas_resume - resumes TAS playback|
|p2sm_tas_save_raw|cmd|p2sm_tas_save_raw - saves a processed version of just processed script|
|p2sm_tas_skipto|0|Fast-forwards the TAS playback until given playback tick.|
|p2sm_tas_stop|cmd|p2sm_tas_stop - stop TAS playing|
|p2sm_tas_tools_enabled|1|Enables tool processing for TAS script making.|
|p2sm_tas_tools_force|0|Force tool playback for TAS scripts; primarily for debugging.|
|p2sm_teleport|cmd|p2sm_teleport [noportals] - teleports the player to the last saved location|
|p2sm_teleport_setpos|cmd|p2sm_teleport_setpos - saves current location for teleportation|
|p2sm_tick_debug|0|Output debugging information to the console related to ticks and frames.|
|p2sm_time_demo|cmd|p2sm_time_demo \<demo_name> - parses a demo and prints some information about it|
|p2sm_time_demo_dev|0|Printing mode when using p2sm_time_demo.<br>0 = Default,<br>1 = Console commands,<br>2 = Console commands & packets.|
|p2sm_time_demos|cmd|p2sm_time_demos \<demo_name> [demo_name2]... - parses multiple demos and prints the total sum of them|
|p2sm_timeline_show_completed|0|Only show speedrun starts and splits with matching finishes.|
|p2sm_timeline_splits|1|Add split markers to the Steam Timeline.|
|p2sm_timer_always_running|1|Timer will save current value when disconnecting.|
|p2sm_timer_result|cmd|p2sm_timer_result - prints result of timer|
|p2sm_timer_start|cmd|p2sm_timer_start - starts timer|
|p2sm_timer_stop|cmd|p2sm_timer_stop - stops timer|
|p2sm_timer_time_pauses|1|Timer adds non-simulated ticks when server pauses.|
|p2sm_toast_align|0|The side to align toasts to horizontally. 0 = left, 1 = center, 2 = right.|
|p2sm_toast_anchor|1|Where to put new toasts. 0 = bottom, 1 = top.|
|p2sm_toast_background|1|Sets the background highlight for toasts. 0 = no background, 1 = text width only, 2 = full width.|
|p2sm_toast_compact|0|Enables a compact form of the toasts HUD.|
|p2sm_toast_create|cmd|p2sm_toast_create \<tag> \<text> - create a toast|
|p2sm_toast_disable|0|Disable all toasts from showing.|
|p2sm_toast_dismiss_all|cmd|p2sm_toast_dismiss_all - dismiss all active toasts|
|p2sm_toast_font|6|The font index to use for toasts.|
|p2sm_toast_net_create|cmd|p2sm_toast_net_create \<tag> \<text> - create a toast, also sending it to your coop partner|
|p2sm_toast_net_disable|0|Disable network toasts.|
|p2sm_toast_setpos|cmd|p2sm_toast_setpos \<bottom\|top> \<left\|center\|right> - set the position of the toasts HUD|
|p2sm_toast_tag_dismiss_all|cmd|p2sm_toast_tag_dismiss_all \<tag> - dismiss all active toasts with the given tag|
|p2sm_toast_tag_set_color|cmd|p2sm_toast_tag_set_color \<tag> \<color> - set the color of the specified toast tag to an sRGB color|
|p2sm_toast_tag_set_duration|cmd|p2sm_toast_tag_set_duration \<tag> \<duration> - set the duration of the specified toast tag in seconds. The duration may be given as 'forever'|
|p2sm_toast_width|250|The maximum width for toasts.|
|p2sm_toast_x|10|The horizontal position of the toasts HUD.|
|p2sm_toast_y|10|The vertical position of the toasts HUD.|
|p2sm_togglewait|cmd|p2sm_togglewait - enables or disables "wait" for the command buffer|
|p2sm_trace_autoclear|1|Automatically clear the trace on session start|
|p2sm_trace_bbox_at|-1|Display a player-sized bbox at the given tick.|
|p2sm_trace_bbox_ent_dist|200|Distance from which to capture entity hitboxes.|
|p2sm_trace_bbox_ent_draw|1|Draw hitboxes of nearby entities in the trace.|
|p2sm_trace_bbox_ent_record|1|Record hitboxes of nearby entities in the trace. You may want to disable this if memory consumption gets too high.|
|p2sm_trace_bbox_use_hover|0|Move trace bbox to hovered trace point tick on given trace.|
|p2sm_trace_clear|cmd|p2sm_trace_clear \<name> - Clear player trace with a given name|
|p2sm_trace_clear_all|cmd|p2sm_trace_clear_all - Clear all the traces|
|p2sm_trace_compare|cmd|p2sm_trace_compare \<trace 1> \<trace 2> - compares two given recorded traces and shows where differences occurred.|
|p2sm_trace_draw|0|Display the recorded player trace. Requires cheats|
|p2sm_trace_draw_hover|1|Display information about the trace at the hovered tick.|
|p2sm_trace_draw_speed_deltas|0|Display the speed deltas. Requires p2sm_trace_draw|
|p2sm_trace_draw_through_walls|1|Display the player trace through walls. Requires p2sm_trace_draw|
|p2sm_trace_draw_time|3|Display tick above trace hover info<br>0 = hide tick info<br>1 = ticks since trace recording started<br>2 = session timer<br>3 = TAS timer (if no TAS was played, uses 1 instead)|
|p2sm_trace_dump|cmd|p2sm_trace_dump \<tick> [player slot] [trace name] - dump the player state from the given trace tick on the given trace ID (defaults to 1) in the given slot (defaults to 0).|
|p2sm_trace_export|cmd|p2sm_trace_export \<filename> [trace name] - Export trace data into a csv file.|
|p2sm_trace_font_size|3.0|The size of text overlaid on recorded traces.|
|p2sm_trace_hide|cmd|p2sm_trace_hide [trace name] - hide the trace with the given name|
|p2sm_trace_override|1|Clears old trace when you start recording to it instead of recording on top of it.|
|p2sm_trace_portal_opacity|100|Opacity of trace portal previews.|
|p2sm_trace_portal_oval|0|Draw trace portals as ovals rather than rectangles.|
|p2sm_trace_portal_record|1|Record portal locations.|
|p2sm_trace_record|0|Record the trace to a slot. Set to 0 for not recording|
|p2sm_trace_show|cmd|p2sm_trace_show [trace name] - show the trace with the given name|
|p2sm_trace_teleport_at|cmd|p2sm_trace_teleport_at \<tick> [player slot] [trace name] - teleports the player at the given trace tick on the given trace ID (defaults to hovered one or the first one ever made) in the given slot (defaults to 0).|
|p2sm_trace_teleport_eye|cmd|p2sm_trace_teleport_eye \<tick> [player slot] [trace name] - teleports the player to the eye position at the given trace tick on the given trace (defaults to hovered one or the first one ever made) in the given slot (defaults to 0).|
|p2sm_trace_use_shot_eyeoffset|1|Uses eye offset and angles accurate for portal shooting.|
|p2sm_transition_timer|0|Output how slow your dialogue fade was.|
|p2sm_twitch_chat_channel||The Twitch channel to connect to.|
|p2sm_twitch_chat_color|255 255 255|The color of the Twitch chat messages.|
|p2sm_twitch_chat_enabled|0|Enables Twitch chat integration.|
|p2sm_unlocked_chapters|-1|Max unlocked chapter.|
|p2sm_update|cmd|p2sm_update [release\|pre\|canary] [exit\|restart] [force] - update SAR to the latest version. If exit is given, exit the game upon successful update; if force is given, always re-install, even if it may be a downgrade|
|p2sm_velocitygraph|0|Shows velocity graph.|
|p2sm_velocitygraph_background|0|Background of velocity graph.|
|p2sm_velocitygraph_font_index|21|Font index of velocity graph.|
|p2sm_velocitygraph_rainbow|0|Rainbow mode of velocity graph text.|
|p2sm_velocitygraph_show_line|1|Shows line for velocity graph.|
|p2sm_velocitygraph_show_speed_on_graph|1|Show speed between jumps.|
|p2sm_velocitygraph_text_color|1|Whether to color the text of the velocity graph.|
|p2sm_velocitygraph_text_groundspeed|1|Whether to show the ground speed on the velocity graph text.|
|p2sm_velocitygraph_x|-250|Velocity graph x axis offset.|
|p2sm_velocitygraph_y|-175|Velocity graph y axis offset.|
|p2sm_vphys_hud|0|Enables or disables the vphys HUD.|
|p2sm_vphys_hud_font|1|Sets font of the vphys HUD.|
|p2sm_vphys_hud_precision|3|Sets decimal precision of the vphys HUD.|
|p2sm_vphys_hud_show_hitboxes|2|Sets visibility of hitboxes when vphys hud is active.<br>0 = hitboxes are not drawn<br>1 = only active vphys hitbox is drawn<br>2 = active vphys and player's bounding box are drawn<br>3 = both vphys hitboxes and player's bounding box are drawn|
|p2sm_vphys_hud_x|0|The x position of the vphys HUD.|
|p2sm_vphys_hud_y|0|The y position of the vphys HUD.|
|p2sm_vphys_setangle|cmd|p2sm_vphys_setangle \<hitbox> \<angle> [component = z] - sets rotation angle for specified havok collision shadow. Hitboxes:<br>0 - Standing Chell/Atlas<br>1 - Crouching Chell/Atlas<br>2 - Standing Pbody<br>3 - Crouching Pbody|
|p2sm_vphys_setasleep|cmd|p2sm_vphys_setasleep \<hitbox> \<asleep> - sets whether the specified havok collision shadow is asleep. Hitboxes:<br>0 - Standing Chell/Atlas<br>1 - Crouching Chell/Atlas<br>2 - Standing Pbody<br>3 - Crouching Pbody|
|p2sm_vphys_setgravity|cmd|p2sm_vphys_setgravity \<hitbox> \<enabled> - sets gravity flag state for specified havok collision shadow. Hitboxes:<br>0 - Standing Chell/Atlas<br>1 - Crouching Chell/Atlas<br>2 - Standing Pbody<br>3 - Crouching Pbody|
|p2sm_vphys_setspin|cmd|p2sm_vphys_setspin \<hitbox> \<angvel> [component = x] - sets rotation speed for specified havok collision shadow. Hitboxes:<br>0 - Standing Chell/Atlas<br>1 - Crouching Chell/Atlas<br>2 - Standing Pbody<br>3 - Crouching Pbody|
|<i title="Portal 2&#10;Aperture Tag">p2sm_workshop</i>|cmd|p2sm_workshop \<file> [ss/changelevel] - same as "map" command but lists workshop maps|
|<i title="Portal 2&#10;Aperture Tag">p2sm_workshop_list</i>|cmd|p2sm_workshop_list - prints all workshop maps|
|<i title="Portal 2&#10;Aperture Tag">p2sm_workshop_skip</i>|cmd|p2sm_workshop_skip - Skips to the next level in workshop|
|<i title="Portal 2&#10;Aperture Tag">p2sm_workshop_update</i>|cmd|p2sm_workshop_update - updates the workshop map list|
|seq|cmd|seq \<commands>... - runs a sequence of commands one tick after one another|
|svar_abs|cmd|svar_abs \<variable> - perform the given operation on an svar|
|svar_add|cmd|svar_add \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_capture|cmd|svar_capture \<variable> \<command> [args]... - capture a command's output and place it into an svar, removing newlines|
|svar_ceil|cmd|svar_ceil \<variable> - perform the given operation on an svar|
|svar_count|cmd|svar_count - prints a count of all the defined svars|
|svar_div|cmd|svar_div \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_fadd|cmd|svar_fadd \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_fdiv|cmd|svar_fdiv \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_floor|cmd|svar_floor \<variable> - perform the given operation on an svar|
|svar_fmod|cmd|svar_fmod \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_fmul|cmd|svar_fmul \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_from_cvar|cmd|svar_from_cvar \<variable> \<cvar> - capture a cvar's value and place it into an svar, removing newlines|
|svar_fsub|cmd|svar_fsub \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_get|cmd|svar_get \<variable> - get the value of a svar|
|svar_mod|cmd|svar_mod \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_mul|cmd|svar_mul \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_no_persist|cmd|svar_no_persist \<variable> - unmark an svar as persistent|
|svar_persist|cmd|svar_persist \<variable> - mark an svar as persistent|
|svar_round|cmd|svar_round \<variable> - perform the given operation on an svar|
|svar_set|cmd|svar_set \<variable> \<value> - set a svar (SAR variable) to a given value|
|svar_sub|cmd|svar_sub \<variable> \<variable\|value> - perform the given operation on an svar|
|svar_substr|cmd|svar_substr \<variable> \<from> [len] - sets a svar to its substring.|
|wait|cmd|wait \<tick> \<commands> - wait for the amount of ticks specified|
|wait_for|cmd|wait_for \<tick> \<commands> - wait for the amount of ticks specified|
|wait_mode|0|When the pending commands should be executed. 0 is absolute, 1 is relative to when you entered the wait command.|
|wait_persist_across_loads|0|Whether pending commands should be carried across loads (1) or just be dropped (0).|
|wait_to|cmd|wait_to \<tick> \<commands> - run this command on the specified session tick|
