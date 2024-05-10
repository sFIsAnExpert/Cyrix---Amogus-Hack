#pragma once
#include "../../cyrix/drawing/drawing.h"

namespace Menu {
	extern bool bMenuOpened;
	enum Tabs {
		NONE,
		VISUALS,
		MOVEMENT,
		WEAPON,
		EXPLOITS
	};
	void Draw();
	void Exploits();
}