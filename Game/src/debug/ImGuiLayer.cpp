#include <iostream>
#include "ImGuiLayer.h"
#include "imgui.h"

void ImGuiLayer::draw(Velium::Graphics::Window* window)
{
    // Hello World window
    int margin_right = 10;

    ImGui::Begin("Hello, world!");
    ImGui::SetWindowCollapsed(true, ImGuiCond_Once);
    ImGui::SetWindowPos(ImVec2(window->getSize().x - ImGui::GetWindowSize().x - margin_right, window->getSize().y - ImGui::GetWindowSize().y / 2), ImGuiCond_Once);
    static char test[128] = "";
    ImGui::InputText("asd", test, IM_ARRAYSIZE(test));
    if(ImGui::Button("Test")) {
        std::cout << "wow" <<std::endl;
    }
    ImGui::End();
}
