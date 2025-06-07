#include "Event.hpp"
#include "Modules/Engine.hpp"
#include "Variable.hpp"
#include "Utils.hpp"

#include <thread>

Variable p2sm_metronome("p2sm_metronome", "0", "Enable metronome.\n");
Variable p2sm_metronome_beats("p2sm_metronome_beats", "4", 1, 16, "Set the number of beats per bar for the metronome.\n");
Variable p2sm_metronome_bpm("p2sm_metronome_bpm", "60", 1, 1000, "Set the beats per minute for the metronome.\n");
Variable p2sm_metronome_sound("p2sm_metronome_sound", "ui/ui_coop_hud_focus_01", "Set the sound to play for the metronome.\n");
Variable p2sm_metronome_sound_bar("p2sm_metronome_sound_bar", "ui/ui_coop_hud_unfocus_01", "Set the sound to play for the metronome bar.\n");
Variable p2sm_metronome_volume("p2sm_metronome_volume", "1", 0, 1, "Set the volume for the metronome.\n");

static std::thread metronomeThread;
static int metronomeBeat = 0;

static void bpmTick() {
    while (true) {
        while (p2sm_metronome.GetBool()) {
            auto interval = std::chrono::milliseconds(1000);
            auto isBar = metronomeBeat == 0;
            metronomeBeat = (metronomeBeat + 1) % p2sm_metronome_beats.GetInt();
            auto sound = isBar ? p2sm_metronome_sound_bar.GetString() : p2sm_metronome_sound.GetString();
            engine->ExecuteCommand(Utils::ssprintf("playvol \"%s\" %f", sound, p2sm_metronome_volume.GetFloat()).c_str());
            if (p2sm_metronome_bpm.GetFloat() > 0) {
                interval = std::chrono::milliseconds((int)(60000 / p2sm_metronome_bpm.GetFloat()));
            }
            std::this_thread::sleep_for(interval);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

ON_INIT {
    metronomeThread = std::thread(bpmTick);
}

ON_EVENT(P2SM_UNLOAD) {
    if (metronomeThread.joinable()) metronomeThread.detach();
}
