#include <AppSettings.hpp>
#include <Toolbar.hpp>

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void Toolbar::Draw() const
{
    const int oldSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 32);

    int width, height;
    AppSettings::GetResolution(width, height);
    DrawRectangle(0, 0, width, 100, m_toolbarColor);

    const auto nonConstThis = const_cast<Toolbar *>(this);
    nonConstThis->m_planeButton = GuiButton((Rectangle){ 10, 10, 158, 80 }, "PLANE");

    GuiSetStyle(DEFAULT, TEXT_SIZE, oldSize);
}

void Toolbar::HandlePressedButtons()
{
    if (m_planeButton)
    {
        m_toolbarColor = RED;
    }
}
