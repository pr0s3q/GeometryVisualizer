#include <AppSettings.hpp>
#include <Toolbar.hpp>

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

void Toolbar::Draw() const
{
    int oldSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 32);

    int width, height;
    AppSettings::GetResolution(width, height);
    DrawRectangle(0, 0, width, 100, LIGHTGRAY);
    GuiButton((Rectangle){ 10, 10, 158, 80 }, "PLANE");

    GuiSetStyle(DEFAULT, TEXT_SIZE, oldSize);
}
