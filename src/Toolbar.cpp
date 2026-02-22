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

    const auto nonConstThis = const_cast<Toolbar*>(this);
    nonConstThis->m_planeButton = GuiButton(Rectangle{ 10, 10, 158, 80 }, "PLANE");

    if (m_planeCreatorUI)
        nonConstThis->PlaneCreatorUI();

    GuiSetStyle(DEFAULT, TEXT_SIZE, oldSize);
}

void Toolbar::HandlePressedButtons()
{
    if (m_planeButton)
    {
        if (!m_planeCreatorUI)
            m_planeCreatorUI = true;
    }
}

void Toolbar::PlaneCreatorUI()
{
    DrawRectangle(20, 120, 300, 300, m_toolbarColor);
    GuiLabel(Rectangle{ 25, 130, 300, 35 }, "Plane creator");
    GuiLabel(Rectangle{ 25, 170, 50, 35 }, "X:");
    GuiLabel(Rectangle{ 25, 210, 50, 35 }, "Y:");
    GuiLabel(Rectangle{ 25, 250, 50, 35 }, "Z:");
    if (GuiTextBox(Rectangle{ 60, 170, 150, 35 }, m_planeCreatorXInput, 32, m_planeCreatorXBool))
        m_planeCreatorXBool = !m_planeCreatorXBool;
    if (GuiTextBox(Rectangle{ 60, 210, 150, 35 }, m_planeCreatorYInput, 32, m_planeCreatorYBool))
        m_planeCreatorYBool = !m_planeCreatorYBool;
    if (GuiTextBox(Rectangle{ 60, 250, 150, 35 }, m_planeCreatorZInput, 32, m_planeCreatorZBool))
        m_planeCreatorZBool = !m_planeCreatorZBool;
}