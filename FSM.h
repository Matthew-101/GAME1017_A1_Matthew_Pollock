#pragma once
#include <vector>
using namespace std;

class state
{
protected:
    State() {}
public:
   virtual void Enter() = 0;
   virtual void Update() = 0;
   virtual void Render();
    virtual void Exit() = 0;
    virtual void Resume();
};

class PauseState : public state
{
public:
    PauseState();
    void Enter();
       void Update();
       void Render();
       void Exit();
};


class GameState : public state
{
public:
    GameState();
    void Enter();
       void Update();
       void Render();
       void Exit();
       void Resume();
};

class TitleState : public state
{
public:
    TitleState();
    void Enter();
       void Update();
       void Render();
       void Exit();
};

class LoseState : public state
{
public:
    LoseState();
    void Enter();
       void Update();
       void Render();
       void Exit();
};

class FSM
{
private:
    vector<State*> m_vStates;
public:
    FSM();
    ~FSM();
    void Update();
    void Render();
    void ChangeState(State* pState);
    void PushState(State* pState)
    void PopState()
    void Clean();
    vector<State*>& GetStates();
};

