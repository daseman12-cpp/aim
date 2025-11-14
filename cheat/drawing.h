#ifndef DRAWING_H
#define DRAWING_H
#include "overlay.h"
#include "math.h"

class Drawing {
public:

    // Draw a box (rectangle)
    void drawBox(const ImVec2& topLeft, const ImVec2& bottomRight, const ImColor& color, float thickness = 1.0f, float rounding = 0.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddRect(
            topLeft,                              // Top-left corner
            bottomRight,                          // Bottom-right corner
            color,                                // Color (ImColor automatically converts to ImU32)
            rounding,                             // Rounding radius
            0,                                    // Flags (e.g., ImDrawFlags_RoundCornersAll)
            thickness                             // Line thickness
        );
    }

    void drawFilledBox(const ImVec2& topLeft, const ImVec2& bottomRight, const ImColor& color, float thickness = 1.0f, float rounding = 0.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddRectFilled(
            topLeft,                              // Top-left corner
            bottomRight,                          // Bottom-right corner
            color,                                // Color (ImColor automatically converts to ImU32)
            rounding,                             // Rounding radius
            0
        );
    }

    // Draw a line
    void drawLine(const ImVec2& start, const ImVec2& end, const ImColor& color, float thickness = 1.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddLine(
            start,                                // Start point
            end,                                  // End point
            color,                                // Color (ImColor automatically converts to ImU32)
            thickness                             // Line thickness
        );
    }

    void drawLineFG(const ImVec2& start, const ImVec2& end, const ImColor& color, float thickness = 1.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddLine(
            start,                                // Start point
            end,                                  // End point
            color,                                // Color (ImColor automatically converts to ImU32)
            thickness                             // Line thickness
        );
    }

    // Draw a circle outline
    void drawCircle(const ImVec2& center, float radius, const ImColor& color, float thickness = 1.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddCircle(
            center,                               // Center of the circle
            radius,                               // Radius of the circle
            color,                                // Color (ImColor automatically converts to ImU32)
            0,                                    // Number of segments (0 lets ImGui auto-calculate)
            thickness                             // Line thickness
        );
    }

    // Draw a filled circle
    void drawFilledCircle(const ImVec2& center, float radius, const ImColor& color) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddCircleFilled(
            center,                               // Center of the circle
            radius,                               // Radius of the circle
            color                                 // Color (ImColor automatically converts to ImU32)
        );
    }

    // Draw a filled box (rectangle)
    void drawFilledBox(const ImVec2& topLeft, const ImVec2& bottomRight, const ImColor& color, float rounding = 0.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        drawList->AddRectFilled(
            topLeft,                              // Top-left corner
            bottomRight,                          // Bottom-right corner
            color,                                // Color (ImColor automatically converts to ImU32)
            rounding                              // Rounding radius
        );
    }

    void drawText(const ImVec2& position, const char* text, const ImColor& color, float size = 16.0f) {
        ImDrawList* drawList = ImGui::GetBackgroundDrawList();

        // Scale font size (ImGui uses PushFont for different font sizes; this is a simple workaround)
        ImGuiIO& io = ImGui::GetIO();
        float originalFontSize = io.FontGlobalScale;
        io.FontGlobalScale = size / 16.0f; // Adjust font scaling relative to default size

        // Add text to the drawing list
        drawList->AddText(
            position,
            color,
            text
        );

        // Restore original font size
        io.FontGlobalScale = originalFontSize;
    }
};

#endif
