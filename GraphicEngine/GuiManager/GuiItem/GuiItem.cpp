#include "GuiItem.h"
#include "../CallBackManager.h"
#include "GraphicEngine/EventHandler/EventHandler.h"

GuiItem::GuiItem(sf::RenderWindow& window, int x, int y, int sizex, int sizey) : _window(window)
{
    _x = x;
    _y = y;
    _sizex = sizex;
    _sizey = sizey;
    
    _canDraw = true;
}

GuiItem::~GuiItem()
{
    for (int i = 0; i < _callBackManagers.size(); i++)
    {
        delete _callBackManagers[i];
    }
}

void GuiItem::AddCallBack(CallBackManager* callBackManager)
{
    _callBackManagers.push_back(callBackManager);
}

void GuiItem::HandleEvent(sf::Event event)
{
    for (int i = 0; i < _callBackManagers.size(); i++)
    {
        if (_callBackManagers[i]->GetEventHandler()->IsTriggered(event))
            _callBackManagers[i]->Call();
    }
}

int GuiItem::GetX()
{
    return _x;
}

int GuiItem::GetY()
{
    return _y;
}

int GuiItem::GetSizeX()
{
    return _sizex;
}

int GuiItem::GetSizeY()
{
    return _sizey;
}