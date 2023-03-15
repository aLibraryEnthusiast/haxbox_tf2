//tf2 cheat engine for tux/linux

#include <iostream>
#include "./header_files/version_info.h"
#include "./header_files/Vector3.h" 
#include "./header_files/fuck_you_VAC.h" //changes the sha256sum of the program ;)

using namespace std;

namespace offset //TODO: update later, these are for CS:GO
{
	// client
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDB25DC;
	constexpr ::std::ptrdiff_t dwEntityList = 0x4DCDE7C;

	// engine
	constexpr ::std::ptrdiff_t dwClientState = 0x58CFC4;
	constexpr ::std::ptrdiff_t dwClientState_ViewAngles = 0x4D90;
	constexpr ::std::ptrdiff_t dwClientState_GetLocalPlayer = 0x180;

	// entity
	constexpr ::std::ptrdiff_t m_dwBoneMatrix = 0x26A8;
	constexpr ::std::ptrdiff_t m_bDormant = 0xED;
	constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
	constexpr ::std::ptrdiff_t m_lifeState = 0x25F;
	constexpr ::std::ptrdiff_t m_vecOrigin = 0x138;
	constexpr ::std::ptrdiff_t m_vecViewOffset = 0x108;
	constexpr ::std::ptrdiff_t m_aimPunchAngle = 0x303C;
	constexpr ::std::ptrdiff_t m_bSpottedByMask = 0x980;
}

constexpr Vector3 CalculateAngle(
    const Vector3& localPositon,
    const Vector3& enemyPosition,
    const Vector3& viewAngles) noexcept
    {
        return ((enemyPosition - localPositon).ToAngle() - viewAngles);
    }

int main(){
    cout << "hello, world\n";
    cout << "this is totaly sketch but whatever\n";
    return 0;
}