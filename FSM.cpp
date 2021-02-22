#include "FSM.h"
#include "Engine.cpp"
#include "Buttons.h"
#include <iostream>
using namespace std;


void State::Render()
{
    SDL_RenderPresent(Engine::Instance().GetRenderer());
}

void State::Resume()
{
}

PauseState::PauseState()
{
}

void PauseState::Enter()
{
    cout << "Entering pause!" << endl;
    m_playBtn = new PlayButton({ 0,0,400,100 }, { 312.0f,100.0f,400.0f,100.0f },
}

void PauseState::Update()
{
    if (Engine::Instance().KeyDown(SDL_SCANCODE_R))
        Engine::Instance().GetFSM().PopState();
}

void PauseState::Render()
{
    cout << "Rendering pause!" << endl;
    Engine::Instance().GetFSM().GetStates().front()->Render();
    SDL_SetRenderBlendMode(Engine::Instance().GetRender(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(Engine::Instance().GerRender(), 0, 255, 0, 128);
    SDL_Rect rect = { 256, 128, 512, 512};
    SDL_RenderFillRect(Engine::Instance().GetRenderer(), &rect);
    State::Render();
}

void PauseState::Exit()
{
    cout << "Exiting pause!" << endl;
}

GameState::GameState()
{}

void GameState::Enter()
{
    cout << "Entering game!" << endl;
    
}

void GameState::Update()
{
    if (Engine::Instance().keyDown(SDL_SCANCODE_P))
    Engine::Instance().GetFSM().PushState(new PauseState());
    else if (Engine::Instance().keyDown(SDL_SCANCODE_X))
    Engine::Instance().GetFSM().ChangeState(new TitleState());
}

void GameState::Render()
{
    cout << "Rendering game!" << endl;
    SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 255, 255);
    SDL_RrnderClear(Engine::Instance().GetRenderer());
    if (dynamic_cast<GameState*>(Engine::Instance().GetFSM().GetStates().back()))
    State::Render();
}

void GameState::Exit()
{
    cout << "Exiting game!" << endl;
}

void GameState::Resume()
{
    cout << "Resuming game!" << endl;
}

TitleState::TitleState()
{
}

void TitleState::Enter()
{
    cout << "Entering titlescreen!" << endl;
    m_playBtn = new PlayButton({ 0,0,400,100 }, { 312.0f,100.0f,400.0f,100.0f },
}

void TitleState::Update()
{
    if (Engine::Instance().keyDown(SDL_SCANCODE_N))
        Engine::Instance().GetFSM().ChangeState(new GameState());
}

void TitleState::Render()
{
    cout << "Rendering titlescreen!" << endl;
    SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 255, 0, 0, 255);
    SDL_RrnderClear(Engine::Instance().GetRenderer());
    State::Render();
}

void TitleState::Exit()
{
    cout << "Exiting titlescreen!" << endl;
}

LoseState::LoseState()
{
}

void LoseState::Enter()
{
    cout << "Entering lose!" << endl;
    m_playBtn = new PlayButton({ 0,0,400,100 }, { 312.0f,100.0f,400.0f,100.0f },
}

void LoseState::Update()
{
    if (g_isCol = true)
    {
    Engine::Instance().GetFSM().PopState(new LoseState);
     Engine::Instance().GetFSM().ChangeState(new LoseState());
    }
}

void LoseState::Render()
{
    cout << "Rendering Lose!" << endl;
    SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 128, 0, 120, 255);
    SDL_RrnderClear(Engine::Instance().GetRenderer());
}

void LoseState::Exit()
{
    cout << "Exiting lose!" << endl;
}

FSM::FSM(){}
FSM::~FSM(){}

void FSM::Update()
{
    if(!m_vStates.empty())
    m_vStates.back()->Update();
}

void FSM::Render()
{
    if(!m_vStates.empty())
    m_vStates.back()->Render();
}

void FSM::ChangeState(State* pState)
{
    if(!m_vStates.empty)
    {
        m_vStates.back()->Exit();
        delete m_vStates.back();
        m_vStates.back() = nullptr;
        m_vStates.pop_back();
    }
   // PushState(pState);
    pState->Enter();
    m_vStates.push_back(pState);
}

void FSM::PushState(State* pState)
{
    pState->Enter();
    m_vStates.push_back(pState);
}

void FSM::PopState()
{
    if(!m_vStates.empty())
    {
        m_vStates.back()->Exit();
        delete m_vStates.back();
        m_vStates.back() = nullptr;
        m_vStates.pop_back();
    }
    m_vStates.back()->Resume();
}

void FSM::Clean()
{
    while (!m_vStates.empty())
    {
        m_vStates.back()->Exit();
        delete m_vStates.back();
        m_vStates.back() = nullptr;
        m_vStates.pop_back();
    }
}

void FSM::Update()
{
}

vector<State*>& FSM::GetStates()
{
    return m_vStates;
}

