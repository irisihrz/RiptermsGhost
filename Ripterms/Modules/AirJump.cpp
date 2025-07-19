#include "Modules.h"
#include <Windows.h>
#include "../../net/minecraft/network/play/client/C03PacketPlayer/C03PacketPlayer.h"

void Ripterms::Modules::AirJump::onUpdateWalkingPlayer(JNIEnv* env, EntityPlayerSP& this_player, bool* cancel)
{
	if (!enabled) return;

	C03PacketPlayer packet = C03PacketPlayer::newObject(true, env);
	this_player.getInstance();

	static bool wasSpacePressed = false;
	bool isSpacePressed = (GetAsyncKeyState(VK_SPACE) & 0x8000);

	if (!this_player.isOnGround() && isSpacePressed && !wasSpacePressed) {
		Ripterms::Maths::Vector3d motion = this_player.getMotion();
		motion.y = 0.42;
		this_player.setMotion(motion);
	}

	wasSpacePressed = isSpacePressed;
}
