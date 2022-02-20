#include "Window.h"
#include "imgui.h"

namespace Velium::Graphics {

    Window::Window(const char *title, int height, int width, WINDOW_POSITION win_pos) :
        sf::RenderWindow(sf::VideoMode(width, height), title)
    {
        // Setup ImGUI
        if(!ImGui::SFML::Init(*this, false))
            std::cout << "Error while initializing ImGui!";

        ImGuiStyle* style = &ImGui::GetStyle();
        style->ScaleAllSizes(2);

        style->WindowPadding = ImVec2(15, 15);
        style->WindowRounding = 5.0f;
        style->FramePadding = ImVec2(5, 5);
        style->FrameRounding = 4.0f;
        style->ItemSpacing = ImVec2(12, 8);
        style->ItemInnerSpacing = ImVec2(8, 6);
        style->IndentSpacing = 25.0f;
        style->ScrollbarSize = 15.0f;
        style->ScrollbarRounding = 9.0f;
        style->GrabMinSize = 5.0f;
        style->GrabRounding = 3.0f;

        style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
        style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
        style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
        style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.09f, 0.12f, 0.5f);
        style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
        style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_Separator] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_SeparatorActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
        style->Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);


        ImGuiIO& io = ImGui::GetIO();

        io.Fonts->AddFontFromFileTTF("../src/res/fonts/ruda/Ruda-Regular.ttf", 20);
        io.Fonts->AddFontFromFileTTF("../src/res/fonts/ruda/Ruda-Medium.ttf", 20);
        io.Fonts->AddFontFromFileTTF("../src/res/fonts/ruda/Ruda-SemiBold.ttf", 20);
        io.Fonts->AddFontFromFileTTF("../src/res/fonts/ruda/Ruda-Bold.ttf", 20);

        io.Fonts->Build();
        if(!ImGui::SFML::UpdateFontTexture())
            std::cout << "Error while updating ImGui font!";

        // Set window position
        sf::Vector2<float> pos;
        sf::Vector2<float> screen_size = sf::Vector2<float>(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

        switch(win_pos)
        {
            case WINDOW_POSITION_CENTER: pos = screen_size / 2.f; break;
            case WINDOW_POSITION_TOP_LEFT: pos = screen_size / 5.f; break;
            case WINDOW_POSITION_TOP_RIGHT: pos = sf::Vector2<float>(screen_size.x / 1.2f, screen_size.y / 5.f); break;
            case WINDOW_POSITION_BOTTOM_LEFT: pos = sf::Vector2<float>(screen_size.x / 5.f, screen_size.y / 1.2f); break;
            case WINDOW_POSITION_BOTTOM_RIGHT: pos = sf::Vector2<float>(screen_size.x / 1.2f, screen_size.y / 1.5f); break;
        }

        setPosition((sf::Vector2<int>)pos - (sf::Vector2<int>)sf::RenderWindow::getSize() / 2);


    }

    Window::~Window()
    {

    }

    void Window::clear()
    {
        sf::RenderWindow::clear();
    }

    void Window::update()
    {
        clear();

        sf::Event event;
        // Check for events
        while (pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            handleClose(event);
            handleResize(event);
        }

        ImGui::SFML::Update(*this, m_delta_clock.restart());

        sf::Font font;
        if (!font.loadFromFile("../src/res/fonts/consolas/consolas.ttf"))
            std::cout << "Error loading font file";
        text = sf::Text("Hello SFML", font, 50);
        text.setPosition(100, 100);
        sf::RenderWindow::draw(text);


        sf::RectangleShape pixel;
        pixel.setSize({ 1.f, 1.f });
        pixel.setFillColor({ 255, 255, 255 });
        pixel.setPosition(sf::RenderWindow::mapPixelToCoords(sf::Mouse::getPosition(*this)));
        sf::RenderWindow::draw(pixel);

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        ImGui::SFML::Render(*this);
        sf::RenderWindow::display();
    }

    void Window::handleClose(sf::Event& event)
    {
        if (event.type == sf::Event::Closed)
            sf::RenderWindow::close();
    }

    void Window::handleResize(sf::Event event)
    {
        if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            this->setView(sf::View(visibleArea));
        }
    }
}
