#pragma once
#include "Command.hpp"
#include "Hud.hpp"
#include "Variable.hpp"

#include <climits>


class LPHud : public Hud {
public:
	LPHud();
	bool ShouldDraw() override;
	void Paint(int slot) override;
	bool GetCurrentSize(int &xSize, int &ySize) override;
	void Set(int count);
};

extern LPHud lpHud;

extern Variable p2sm_lphud;
extern Variable p2sm_lphud_x;
extern Variable p2sm_lphud_y;
extern Variable p2sm_lphud_font;

extern Command p2sm_lphud_set;
