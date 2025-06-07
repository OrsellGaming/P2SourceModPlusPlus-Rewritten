#include "Hud.hpp"

class ScrollSpeedHud : public Hud {
public:
	ScrollSpeedHud()
		: Hud(HudType_InGame, true) {}

	bool ShouldDraw() override;

	void Paint(int slot) override;

	bool GetCurrentSize(int &xSize, int &ySize) override {
		return false;
	}

	void OnJump(int slot, bool grounded);
};

extern ScrollSpeedHud *scrollSpeedHud;

extern Variable p2sm_scrollspeed;
extern Variable p2sm_scrollspeed_x;
extern Variable p2sm_scrollspeed_y;
extern Variable p2sm_scrollspeed_bar_x;
extern Variable p2sm_scrollspeed_bar_y;
