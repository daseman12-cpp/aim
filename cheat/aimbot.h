#pragma once
#include "cstrike.h"
#include "cfg.h"
#include "sdk.h"

namespace aimbot {
    void AimAtClosestEnemy(int hotkey, float fov, float smooth, int aimBone) {
        float closestDistance = FLT_MAX;
        ImVec2 bestTarget(-1, -1);
        view_matrix_t viewMatrix = memory->read<view_matrix_t>(client + Offsets::dwViewMatrix);

        for (const auto& actor : entities::entities) {
            if (actor.health <= 0) continue;
            if (cfg::teamCheck)
                if (actor.team == localplayer::teamid) continue;

            ImVec2 bonePos = SDK::getBonePosition(actor, viewMatrix, aimBone, nullptr);
            if (!SDK::IsOnScreen(bonePos)) continue;

            float distance = sqrt(pow(bonePos.x - SDK::screenCenter.x, 2) + pow(bonePos.y - SDK::screenCenter.y, 2));
            if (distance <= fov && distance < closestDistance) {
                closestDistance = distance;
                bestTarget = bonePos;
            }
        }

        if (bestTarget.x > 0 && bestTarget.y > 0) {
            float screenX = bestTarget.x - SDK::screenCenter.x;
            float screenY = bestTarget.y - SDK::screenCenter.y;

            float smoothFactor = max(1.0f - (smooth / 100.0f), 0.01f);
            screenX *= smoothFactor;
            screenY *= smoothFactor;

            INPUT input = { 0 };
            input.type = INPUT_MOUSE;
            input.mi.dx = (LONG)screenX;
            input.mi.dy = (LONG)screenY;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            SendInput(1, &input, sizeof(INPUT));
        }
    }

    void doAimbot() {
        if (GetAsyncKeyState(cfg::aimKey) & 0x8000)
            AimAtClosestEnemy(cfg::aimKey, cfg::fovSize, cfg::smoothing, cfg::aimBone);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
