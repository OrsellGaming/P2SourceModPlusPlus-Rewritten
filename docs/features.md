
# Features

This file contains a detailed list of all features implemented by SourceAutoRecord up to version [1.12.8-pre6](https://github.com/p2sr/SourceAutoRecord/releases/tag/1.12.8-pre6).

## Essentials

- **Automatic demo recording**:
  - Demo sequence continuance after session change (`p2sm_autorecord`).
  - Configurable directory, prefix and name of the demo (`p2sm_record_prefix`, `p2sm_record_at_demo_name`).
  - Demo recording automatically starting on session start (`p2sm_record_at`).
  - Toggleable autorecording incrementation (`p2sm_record_at_increment`).
  - Back-upping the demo if attempting to overwrite it (`p2sm_demo_overwrite_bak`).

- **Config+**, an extension for config files and in-game console:
  - Adds a way to create advanced aliases (`p2sm_alias`) and command functions (`p2sm_function`) which can take parameters.
  - Allows the usage of nested quotation marks (`p2sm_expand`).
  - Adds custom variable system and basic arithmetics which can be used by aliases and functions (`svar_*`).
  - Allows conditional execution of commands (`cond` or `conds`).
  - Exposes several in-game variables for use in conditional configs.

- **Advanced console filtering** (`p2sm_con_filter`):
  - Allows to set more specific console filter. Multiple filters are also supported.

- **Toasts** - pop-up notifications used by other features (`p2sm_toast_*`):
  - Customizable color and duration, specific for tag.
  - Ability to create your own tags and toasts with it.

- **Updater** (`p2sm_update`):
  - Detects a new version of the plugin and updates it for you.

## Speedrun-based features

- **Speedrun timer system**:
  - Accurate in-game timing, correctly timing pauses and menus if needed.
  - Co-op integration.
  - Category management with an ability to create custom categories and rules, which can be triggered by various level or entity-based events or special trigger zones (mtriggers).
  - Presets for most popular categories.
  - Integration with LiveSplit.
  - Speedrun timer HUD (`p2sm_sr_hud`) with customizable position, color and font.

- **Auto Submit**:
  - Integration with [P2SR Challenge Mode Boards](boards.portal2.sr) for automatic CM demo submission.

- **Ghosts** - an in-game ghost racers, managed by `ghost_*` console commands:
  - An ability to **play demos as ghosts** (one or multiple at once) in current session.
  - **Customization** of ghost's color and type (procedurally drawn Bendy, small circle or pyramid, in-game model).
  - **Ghost client** for joining servers and racing with other players. Along with that, **custom chat** communication (`ghost_chat`), **leaderboard** HUD  (`ghost_leaderboard_*`) and **spectator** commands (`ghost_spec_*`).

- **Challenge Mode stats HUD override** (`p2sm_disable_challenge_stats_hud`):
  - Prevents the Challenge Mode stats HUD from appearing at the beginning of the CM run.

- **Teleporter** (`p2sm_teleport`):
  - Functionality for saving and loading player and portals' position for practice purposes.

## Text-based HUDs

- **Text-based HUD element system** handled by `p2sm_hud_`-prefixed console commands:
  - The entire HUD block is customizable (default text color, font, position, background toggle).
  - Every plugin-defined text-based HUD can be toggled and ordered.
  - Custom HUD text support (`p2sm_hud_set_text`), along with color coding support (`#<hex>text`).

- Basic player-based information:
  - player's position (`position`),
  - player's view angles (`angles`),
  - player's velocity (`velocity`).

- Currently recorded/played demo name and its time (`demo`)

- Time HUDs (`timer`, `pause_timer`,  `frame`, `last_frame`, `session`, `last_session`, `sum`).

- Portal angles (`portal_angles`, `portal_angles_2`).

- Various game-based information (`eyeoffset`, `groundspeed`, `portals`, `ent_slot_serial`).

- **Funnel debug**:
  - Displays current funnel handle (`tbeam`) and funnel count (`tbeam_count`).

- **Duck state** (`duckstate`):
  - Shows basic ducked state information.
  - When `sv_cheats` is enabled, shows detailed information about ducking state, remaining duck/unduck time, forced duck and quantum crouch (with type specification).

- **Grounded frames** (`groundframes`):
  - Shows how many ticks the player has been affected by the ground friction since the last time they landed on the ground.

- **Velocity angles** (`velang`):
  - Calculates and displays angles towards which current velocity vector is pointing at.

- **FPS** (`fps`):
  - Displays the current FPS.

## User interface

- **Input HUD** (`p2sm_ihud`):
  - Displays the state of every in-game input in a very customizable HUD.
  - Adjustability of how each game input is displayed (text, position and size on grid, background and text color for both neutral and pressed states).
  - Key grid size, padding and position on screen.
  - Analog joystick display for both movement and view angles.
  - Simple presets for casuals and TAS makers.
  - Image display support for entire HUD and each button.

- **Strafe Quality HUD** (`p2sm_strafe_quality`):
  - Gives you a graph indicating groundframes and how good your strafing sync is over time.

- **Strafe Sync HUD** (`p2sm_strafesync`):
  - Gives you a constantly-updating percentage for how good your strafing sync is.

- **Custom crosshair** (`p2sm_crosshair_*` and `p2sm_quickhud_*`):
  - Allows user to display customized crosshair in the middle of the screen as a replacement for a default one.
  - Ability to change color, size, quickhud modes, and to set custom images for both crosshair and quickhud.

- **Velocity graph** (`p2sm_velocitygraph`):
  - Shows a graph displaying horizontal velocity over time.

- **Least Portals HUD** (`p2sm_lphud`):
  - Portal counter stylized to look like Challenge Mode HUD which accurately keeps track of placed portals in current session, trying to take save-loading into consideration.

- **Cheat Warn HUD** (`p2sm_cheat_hud`):
  - warms you if a setting that is forbidden in speedruns is changed.

- **Aim point HUD** (`p2sm_aim_point_hud`):
  - Overlays a marker with coordinates at the point you're aiming at.
  - Commands for adding and removing frozen aimpoints (`p2sm_aim_point_add/clear`).

- **Portal Placement HUD** (`p2sm_pp_hud`):
  - Displays info about portalability of the surface you're currently aiming towards.
  - Optionally overlays a portal shape which shows where the portal would be placed when shot. (`p2sm_pp_hud_show_blue/orange`).

- **Portal Gun HUD** (`p2sm_portalgun_hud`):
  - Displays linkage ID of currently held portal gun and portals connected to it.

- **Scroll Speed HUD** (`p2sm_scrollspeed`):
  - Shows a scroll speed indicator.

- **Minimap** (`p2sm_minimap`):
  - Displays an image HUD showing where you (and optionally your co-op partner) is on the map. Requires top-down image with proper .json configuration file that can be exported from Stitcher feature.

## Tool-Assisted Speedrunning (TAS) tools

- **Virtual TAS Controller**:
  - Accepts inputs programmatically for TAS script playback.
  - Acts as the only way of injecting inputs into the game, keeping the legitimacy at the highest level.

- **Custom `.p2tas` scripting language** support.

- **TAS playback system**:
  - Feeds inputs from parsed script to the virtual controller.
  - Has ability to pause, skip, slow down, speed up and tick-advance the script playback.

- **Automation tools**:
  - A special set of tools that allows the script to autonomously react to in-game events where performed action can be automated:
    - **Auto Strafer** - finds the most optimal way to strafe on current tick, given user-defined parameters;
    - **Auto Aim** - automatically aims towards given point in 3D space, instantly or over time.
    - **Auto Jump** - automatically jumps on impact with ground.
    - **Absolute Move Tool** - moves towards specified absolute direction.
    - **Set Angle Tool** - automatically aims towards specified view angle, instantly or over time.
    - **Decel Tool** - moves the opposite direction to your current velocity.
    - **Check Tool** - checks for player velocity or angles in given tick and restarts the playback when deviation occurs.

  - A special system for tool-based script verification - **raw scripts**, which are generated after a successful playback.

- Integration with **VS Code extension [p2tas-lang](https://github.com/RainbowwPhoenixx/p2tas-lang)**, which gives you full control over TAS playback and live debugging.

## Other major features

- **Free Camera** (`p2sm_cam_control`):
  - Manual control using controls similar to ones from demo's Drive mode or commands.
  - Follow camera, which follows given entity.
  - Cinematic camera (demos only):
    - Commands for defining path points and interpolation mode.
    - Possibility of exporting and importing paths using game's config system.
  - Optional orthographic projection.

- **Ruler** (`p2sm_ruler_*`):
  - A tool for measuring distances and angles between two points.
  - Ability to create rulers manually or using a creator (placing points where you look at).

- **Renderer** (`p2sm_render_*`):
  - Video renderer, fully configurable in terms of video and audio codec, quality and bitrate through console commands.
  - Frame blending.
  - Configurable autostart location and extension.

- **Stitcher** (`p2sm_stitcher`):
  - Custom in-game editor for capturing, stitching and exporting top-down images of the map.

- **Achievement Tracker** (`p2sm_achievement_tracker_*`):
  - Keeps track of achievements in current session, with ability to reset progress and isolate co-op achievements.
  - Other mods, like Portal Stories: Mel, are also supported.

- **Player Trace** (`p2sm_trace_*`):
  - Records and displays the path of player movement. Multiple paths are supported.
  - Colors the path depending on ground state and speedlock type.
  - Can show hitbox of the player as well as hitboxes of surrounding objects at given point on path.

## Routing/technical features

- **Placement scanner** (`p2sm_pp_scan_*`)
  - Overlay-based tool for checking the portalability of selected surface by generating its spark map.

- **VPhys HUD** (`p2sm_vphys_hud`):
  - Displays information about standing and crouched Vphys collision boxes.

- **Seamshot Finder** (`p2sm_seamshot_finder`):
  - An overlay tool which shows whether the corner you're currently aiming to is seamshottable.

- **FindClosestPassableSpace debug tools**.

- **Demo parsing features** (`p2sm_time_demo` and `p2sm_time_demos`):
  - Prints details and length of one or multiple demos.

- **Entity list**:
  - Commands for listing all entities or entities meeting given name/classname criteria (`p2sm_find_ents`, `p2sm_find_ent`, `p2sm_list_ents`).
  - Command for displaying details about given entity (`p2sm_ent_info`).

- **Inspection tool** (`p2sm_inspection`):
  - Records data of selected entity, which then can be printed in the console or saved as a .csv file.
  - Entity Inspection HUD (`p2sm_ei_hud`), displaying selected piece of information near inspected entity.

- **Various statistics manager**:
  - Keeps track of many session-related statistics, including retries of Challenge Mode, full game retries, total time spent in the game (SP, CM, co-op), average reset time and more.
  - Ability to export and import statistics to/from .csv file.
  - Velocity peak tracker (with text-based HUD `velocity_peak`).
  - Portals tracker (with text-based HUD `portals`).
  - Jump distance, distance peak and jump counter tracker (with text-based HUDs `jump`, `jumps` and `jump_peak`).
  - Step tracker (with text-based HUD `steps`).

- **Entity inputs debug** (`p2sm_show_entinp`):
  - Prints entity inputs that are happening in currently played map in the console (alternative to `developer 2`).

- **Class and datamap dumpers** (`p2sm_dump_*`):
  - Dumps all exposed client and server datamaps and classes into JSON files.

## Minor features
  
- **Seasonal ASCII messages**:
  - Prints seasonal message in the console on specific times of the year.

- **Cheat commands**:
  - Prevent airlock and allow air control (`p2sm_aircontrol`).
  - Crouch Flying Glitch on demand (`p2sm_give_cfg`).
  - Betsrighter (invulnerability) on demand (`p2sm_give_betsrighter`).
  - Force Quantum Crouch (`p2sm_force_qc`).
  - Crouch Flying Glitch patch (`p2sm_patch_cfg`).
  - Bunnyhopping patch (`p2sm_patch_bhop`).

- **Segmented tools**:
  - Delayed execution of commands through `hwait` command.
  - Sequential execution of commands through `seq` command.

## Tweaks and patches

- **Level loading optimisations**:
  - Eliminates majority of GUI animations which blocks the game from loading (mainly by modifying `ui_loadingscreen_`-prefixed commands).
  - Uncaps FPS and disables rendering completely on loading (using `p2sm_loads_uncap` and `p2sm_loads_norender`).
  - Several pre-defined fast loading presets to use (`p2sm_fast_load_preset`).

- **Demo playback tweaks**:
  - Attempts to remove broken frames at the beginning of the demo (`p2sm_demo_remove_broken`).
  - Attempts to interpolate player view correctly when passing through the portal (`p2sm_demo_portal_interp_fix`).

- **Better file-based commands autocompletion**
  - Autocompletion for commands like `playdemo`, `map` etc. works recursively in a directory.

- **`sv_cheats` patch for Portal: Reloaded** (`p2sm_fix_reloaded_cheats`):
  - allows a normal use of `sv_cheats` without affecting gameplay mechanics.

- **Improved co-op network communication** (`p2sm_always_transmit_heavy_ents`):
  - Force heavy edict transmit to prevent lag spikes

- **BINK video timing tweak** (`p2sm_bink_respect_host_time`):
  - Makes all BINK videos respect host time. This prevents elevator screens being sped up on renders due to them running real-time.

- **Disable weapon sway** (`p2sm_disable_weapon_sway`):
  - Prevents the weapon sway when the player looks around.

- **FOV Changer** (`p2sm_force_fov`):
  - prevents the game from resetting user-defined field of view value.

- **Prevent lag on unfocused window** (`p2sm_disable_no_focus_sleep`):
  - Prevents the power-saving FPS limit when the game window is unfocused.

- **Window Resizer** (`p2sm_allow_resizing_window`):
  - Allows to resize the game's window (experimental, Windows only).

- **Disable save indicator** (`p2sm_disable_save_status_hud`):
  - Hides save indicator HUD that appears when you save the game.

- **Patch Entity Handle Manipulation (EHM)** (`p2sm_prevent_ehm`):
  - Prevents the very rare glitch where object can lose collision (deemed forbidden in regular runs).

- **Patch CM Wrong Warp** (`p2sm_cm_rightwarp`):
  - Prevents Challenge Mode Wrong Warp from happening, since it can happen accidentally on NoSLA run, where it's prohibited.

- **Easier Co-op progress reset** (`p2sm_coop_reset_progress`):
  - Allows the player to completely reset their co-op progress.
