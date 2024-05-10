#include "engine.h"

AmongUs engine;

std::vector<PlayerControl*> AmongUs::Client::World::GetPlayers()
{
	std::vector<PlayerControl*> entity_list;

    auto list = PlayerControl::GetPlayers();
    if (!list) return entity_list;
    if (list->Count() == 0) return entity_list;
    auto arr = list->GetValues();
    if (!arr) return entity_list;
    for (uint8_t i = 0; i < list->Count(); i++) {
        PlayerControl* p = arr->GetValue(i);
        if (!p) continue;
        entity_list.push_back(p);
    }

    return entity_list;
}

void AmongUs::Client::LocalPlayer::SetRole(RoleTypes role)
{
    PlayerControl* p = PlayerControl::GetLocalPlayer();
    if (!p) return;

    p->RpcSetRole(role);
}

void AmongUs::Client::LocalPlayer::SetCanVent(bool rV)
{
    PlayerControl* p = PlayerControl::GetLocalPlayer();
    if (!p) return;

    PlayerInfo* pInfo = p->GetInfo();
    if (!pInfo) return;

    RoleBehaviour* rB = pInfo->GetRoleBehaviour();
    if (!rB) return;

    rB->GetField("CanVent")->SetValue<bool>(rB, rV);
}

void AmongUs::Client::LocalPlayer::SendToChat(const char* Txt)
{
    PlayerControl* p = PlayerControl::GetLocalPlayer();
    if (!p) return;

    p->RpcSendChat(Txt);
}

void AmongUs::Client::LocalPlayer::SetName(const char* Txt)
{
    PlayerControl* p = PlayerControl::GetLocalPlayer();
    if (!p) return;

    p->RpcSetName(Txt);
    p->RpcSetNamePlate(Txt);
}
