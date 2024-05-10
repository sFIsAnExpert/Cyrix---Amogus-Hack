#include "drawing.h"

void Drawing::DrawPlayers(ImDrawList* draw)
{
	if (!Cyrix::bEsp) return;
	auto list = engine.Client.World.GetPlayers();
	if (list.empty()) return;

	Camera* mCam = Camera::GetMain();
	if (!mCam) return;

	PlayerControl* lP = PlayerControl::GetLocalPlayer();
	if (!lP) return;

	Transform* lTrans = lP->GetTransform();
	if (!lTrans) return;

	for (PlayerControl* p : list) {
		PlayerInfo* info = p->GetInfo();
		if (!info) continue;
		RoleBehaviour* role = info->GetRoleBehaviour();
		if (!role) continue;
		Transform* trans = p->GetTransform();
		if (!trans) continue;
		Vector3 pos = trans->GetPosition();
		Vector2 screen;

		Vector3 lPos = lTrans->GetPosition();
		Vector2 lScreen;

		mCam->WorldToScreen(screen, pos);
		mCam->WorldToScreen(lScreen, lPos);

		if (role->isImposter())
			draw->AddLine({ lScreen.x, lScreen.y }, { screen.x, screen.y }, ImColor(255, 0, 0), 2.0);
		else draw->AddLine({ lScreen.x, lScreen.y }, { screen.x, screen.y }, ImColor(255, 255, 255), 2.0);

		float dist = lPos.Distance(pos);
		std::string str = "[" + std::to_string((int)dist) + "]";

		draw->AddText({ screen.x, screen.y }, ImColor(212, 175, 55), str.c_str());
	}
}

void Drawing::Render(ImDrawList* draw)
{
	Drawing::DrawPlayers(draw);
}
