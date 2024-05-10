#pragma once
#include "../cyrix.h"

class AmongUs {
public:
	struct Client {
		struct LocalPlayer {
			void SetRole(RoleTypes role);
			void SetCanVent(bool rV);
			void SendToChat(const char* Txt);
			void SetName(const char* Txt);
		};
		struct World {
			std::vector<PlayerControl*> GetPlayers();
		};
		LocalPlayer LocalPlayer;
		World World;
	};
	Client Client;
}extern engine;