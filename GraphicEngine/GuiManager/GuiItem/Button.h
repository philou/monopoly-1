/* 
 * File:   Button.h
 * Author: manu
 *
 * Created on 21 février 2013, 10:17
 */

#ifndef BUTTON_H
#define	BUTTON_H

#define MARGIN 5

#include "GuiItem.h"

class Button : public GuiItem
{
	public:
		Button(sf::RenderWindow &window, int x, int y, int size, sf::Font font, std::string content);
		~Button();
		void Draw();
        sf::String &GetText();
        
	private:
        sf::Font _font;
        sf::String _text;
        sf::Shape _rect;
};

#endif	/* BUTTON_H */

