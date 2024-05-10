#pragma once
#include "../sdk/sdk.hpp"
#include <vector>

typedef unsigned char byte;

namespace Cyrix {
	inline bool bEsp, bCanVent;
	inline int iRole;
	inline char sChatBuffer[255], sNameBuffer[255];
}