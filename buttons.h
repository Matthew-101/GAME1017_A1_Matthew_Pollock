#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "SDL.h"

class Button
{
private:
    
    enum state {MOUSE_UP, MOUSE_OVER, MOUSE_DOWN};
    int m_iFrame;
    SDL_Rect m_Src;
    SDL_Rect m_Dst;
    SDL_Texture* m_pText;
    
    std::function<void()> m_callback;
    
public:
    Button(const char* s, SDL_Rect src, SDL_Rect dst, std::function<void()> cb);
    ~Button();
    bool MouseCollision();
    void Update();
    void Render();
};

#endif

