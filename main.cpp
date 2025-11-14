#include <iostream>
#include "cheat/cstrike.h"
#include "cheat/aimbot.h"

void aimbotThread() {
    while (true) {
        if (cfg::aimbot)
            aimbot::doAimbot();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void setStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Alpha = 1.0f;
    style.DisabledAlpha = 1.0f;
    style.WindowPadding = ImVec2(12.0f, 12.0f);
    style.WindowRounding = 11.5f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(20.0f, 20.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Right;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(20.0f, 3.4f);
    style.FrameRounding = 7.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(10.0f, 8.0f);
    style.ItemInnerSpacing = ImVec2(6.0f, 6.0f);
    style.IndentSpacing = 21.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 3.0f;
    style.TabRounding = 4.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(0.85f, 0.89f, 1.00f, 1.00f);          // Soft moonlight white
    colors[ImGuiCol_TextDisabled] = ImVec4(0.52f, 0.56f, 0.65f, 1.00f);   // Muted blue-grey
    colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.11f, 0.18f, 1.00f);       // Deep moonlit blue
    colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.13f, 0.22f, 1.00f);        // Slightly lighter
    colors[ImGuiCol_PopupBg] = ImVec4(0.12f, 0.15f, 0.25f, 1.00f);        // Popup background
    colors[ImGuiCol_Border] = ImVec4(0.18f, 0.20f, 0.27f, 1.00f);         // Soft border
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.14f, 0.18f, 0.29f, 1.00f);        // Frame background
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.18f, 0.22f, 0.36f, 1.00f); // Hovered
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.22f, 0.26f, 0.42f, 1.00f);  // Active
    colors[ImGuiCol_TitleBg] = ImVec4(0.11f, 0.14f, 0.23f, 1.00f);        // Title background
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.20f, 0.32f, 1.00f);  // Active title
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.09f, 0.11f, 0.18f, 0.75f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.13f, 0.16f, 0.26f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.13f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.16f, 0.20f, 0.32f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.20f, 0.24f, 0.38f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);      // Bright blue
    colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.36f, 0.54f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.14f, 0.18f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.20f, 0.24f, 0.38f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.16f, 0.20f, 0.32f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.20f, 0.24f, 0.38f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.18f, 0.20f, 0.27f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.30f, 0.36f, 0.54f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.30f, 0.36f, 0.54f, 1.00f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.36f, 0.44f, 0.66f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.14f, 0.18f, 0.29f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.20f, 0.24f, 0.38f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.09f, 0.11f, 0.18f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.18f, 0.29f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.80f, 0.86f, 1.00f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.80f, 0.86f, 1.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.24f, 0.28f, 0.44f, 1.00f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.60f, 0.78f, 1.00f, 1.00f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.09f, 0.11f, 0.18f, 0.70f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.09f, 0.11f, 0.18f, 0.70f);
}

std::string banner = R"(
         /$$$$$$$$ /$$   /$$ /$$$$$$$$       /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$$
        | $$_____/| $$  / $$|__  $$__/      | $$__  $$ /$$__  $$ /$$__  $$| $$_____/
        | $$      |  $$/ $$/   | $$         | $$  \ $$| $$  \ $$| $$  \__/| $$      
        | $$$$$    \  $$$$/    | $$         | $$$$$$$ | $$$$$$$$|  $$$$$$ | $$$$$   
        | $$__/     >$$  $$    | $$         | $$__  $$| $$__  $$ \____  $$| $$__/   
        | $$       /$$/\  $$   | $$         | $$  \ $$| $$  | $$ /$$  \ $$| $$      
        | $$$$$$$$| $$  \ $$   | $$         | $$$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$$
        |________/|__/  |__/   |__/         |_______/ |__/  |__/ \______/ |________/
)";

int main() {
    std::cout << banner << std::endl;

    localplayer::init();
    entities::init();
    std::thread(aimbotThread).detach();
    overlay::SetupWindow();

    if (!(overlay::CreateDeviceD3D(overlay::Window)))
        return 1;

    setStyle();

    while (!overlay::ShouldQuit)
    {
        overlay::Render();

        cstrike::matrix = memory->read<view_matrix_t>(client + Offsets::dwViewMatrix);

        ImGui::SetNextWindowSize(ImVec2(350, 250));

        ImGui::Begin("Basic External");

        if (ImGui::BeginTabBar("CheatTabs")) {
            if (ImGui::BeginTabItem("Visuals")) {
                ImGui::Checkbox("box ESP", &cfg::espOn);
                ImGui::Checkbox("bone ESP", &cfg::bones);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Aimbot")) {
                ImGui::Checkbox("Aimbot", &cfg::aimbot);
                ImGui::Checkbox("Draw FOV", &cfg::drawFov);
                ImGui::SliderFloat("FOV Size", &cfg::fovSize, 1.f, 1000.f);
                ImGui::SliderFloat("Aim Smooth", &cfg::smoothing, 0.f, 100.f);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Settings")) {
                ImGui::ColorEdit4("Box Color", cfg::boxColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                ImGui::ColorEdit4("Bone Color", cfg::boneColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                ImGui::ColorEdit4("Fov Color", cfg::fovColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);
                ImGui::Checkbox("Team Check", &cfg::teamCheck);

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        ImGui::End();

        ImColor fovCol(cfg::fovColor[0], cfg::fovColor[1], cfg::fovColor[2], cfg::fovColor[3]);
        ImColor boxCol(cfg::boxColor[0], cfg::boxColor[1], cfg::boxColor[2], cfg::boxColor[3]);
        ImColor boneCol(cfg::boneColor[0], cfg::boneColor[1], cfg::boneColor[2], cfg::boneColor[3]);

        if (cfg::drawFov)
            ImGui::GetBackgroundDrawList()->AddCircle(SDK::screenCenter, cfg::fovSize, fovCol, 64, 1.f);

        for (entities::PLAYER& actor : entities::entities) {
            if (cfg::espOn)
                cstrike::drawBox(actor, boxCol);
            if (cfg::bones)
                cstrike::drawBones(actor, boneCol);
        }


        overlay::EndRender();
    }

    overlay::CloseOverlay();
}