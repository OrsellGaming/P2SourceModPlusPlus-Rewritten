#pragma once
#include "Hud.hpp"
#include "Variable.hpp"

class VelocityGraph : public Hud {
public:
	VelocityGraph();
	bool ShouldDraw() override;
	void GatherData(int slot, bool on_ground);
	Color HSVtoRGB(float H, float S, float V);
	void Paint(int slot) override;
	bool GetCurrentSize(int &xSize, int &ySize) override;
};

extern VelocityGraph *velocityGraph;

extern Variable p2sm_velocitygraph;
extern Variable p2sm_velocitygraph_font_index;
extern Variable p2sm_velocitygraph_show_line;
extern Variable p2sm_velocitygraph_x;
extern Variable p2sm_velocitygraph_y;
extern Variable p2sm_velocitygraph_background;
extern Variable p2sm_velocitygraph_show_speed_on_graph;
extern Variable p2sm_velocitygraph_rainbow;
