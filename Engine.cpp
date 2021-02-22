#include <iostream>
#include <vector>
#include <image.h>
#include <mixer.h>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
using namespace std;

class bullet
{
    public:
    bool m_active = true;
    SDL_Rect m_dst;
    static const int speed = 6;
    public:
    Bullet(int x, int y)
    {
        m_dst = {x-2, y-2, 4, 4};
    }

    spawnTimer++;
if (spawnTimer == 120)
    {
        spawnEnemy();
        spawnTimer = 0;
    }
}
    class Enemy
    {
        bool m_playspawn = true;
        int bulletTimer = 0, m_timerMax, m_channel;
        
        enemy(SDL_Rect d = {0, 0, 0, 0}), vector<Bullet*>* bVec = nullptrnt int c = 0, int bt = 0, int t = 120)
        {
            m_dst = d;
            bulletVec = bVec;
            m_pSound = s;
            m_channel = c;
            m_timerMax = t;
            m_bulletTimer = bt;
        }
        if (g_pRenderer != nullptr)
            {
                if (IMG_Init(IMG_INIT_PNG))
                {
                    g_pTexture = IMG_LoadTexture(g_pRenderer,"Enemy.png");
                }
                return false;
    }

    void update()
    {
        m_dst.x+= speed;
        if (m_dst > WIDTH)
        m_active = false;
        
        if (bulletTimer == m_timerMax)
        {
            m_bulletTimer = 0;
            spawnBullet();
        }
    }
      g_pRenderer = SDL CreateRenderer(g_pWindow, -1, 0);
            if (g_pRenderer != nullptr)
            {
                if (IMG_Init(IMG_INIT_PNG))
                {
                    g_pTexture = IMG_LoadTexture(g_pRenderer,"bullet.png");
                }
}

void spawnBullet()
{
    bulletVec->push_back(new Bullet({m_dst.x, m_dst.y + 8, 8, 8}));
    if (m_playSpawn)
    {
        if Mix_Playing (m_channel);
        Mix_HaltChannel(m_channel);
        Mix_PlayChannel(m_channel, m_playSound, 0);
    }
}
    
int g_iSpeed = S;
const Uint8* g_iKeystates;
bool g_bRunnung = false;
Uint32 g_start, g_end, g_delta, g_fps;
SDL_Window* g_pWindow;
SDL_Renderer* g_pRednderer;
SDL_Rect g_rBox;
SDL_Rect g_player, g_enemybox;
bool g_isCol = false;
Mix_Music* g_pMusic;

Enemy eArray[4];
vector<Bullet*> EnemyBullets;

SDL_Rect g_src, g_dst;
SDL_Texture* g_pTexture;

vector<bullet*> bulletVec;

void updatePanning()
{
    Mix_SetPanning(0, 0, 255);
    Mix_SetPanning(1, 64, 128);
    Mix_SetPanning(2, 128, 64);
    Mix_SetPanning(3, 255, 0);
}

bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    cout << "Initializing game." << endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        g_pWindow = SDL_CreateWindow(title, int xpos, int ypos, int width, int height, int flags);
        if (g_pWindow != nullptr)
        {
            g_pRenderer = SDL CreateRenderer(g_pWindow, -1, 0);
            if (g_pRenderer != nullptr)
            {
                if (IMG_Init(IMG_INIT_PNG))
                {
                    g_pTexture = IMG_LoadTexture(g_pRenderer,"player.png");
                }
                return false;

                g_pRenderer = SDL CreateRenderer(g_pWindow, -1, 0);
            }
            if (Mix_Init(MIX_INIT_MP3)!=0)
            {
                Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 8192);
                Mix_AllocateChannels(10)
                g_pMusic = LoadMUS("Theme.wav")
                Mix_Volume(-1, MIX_MAX_VOLUME);
                Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
                updatePanning();
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
 else return false;
    g_fps = (Uint32)round((1/(double)FPS) * 1000);
    g_iKeystates = SDL_GetKeyState(nullptr);
    g_player = (512-32, 384-32, 64, 64);
    g_enemybox = (768, 384-32, 64, 64);
    g_src = {0, 0, 0, 255};
    g_dst = {width/2, - g_src w/4, height/2 - g_src.h/4, g_src.w, g_src.h/2};
    g_rBox = (WIDTH/2,HEIGHT/2,50,100)
    g_bRunning = true;
    g_iKeystates = SDL_GetKeyboardState(nullptr);
    playerBullets, &bullet, Mix_LoadWAV("PlayerBullet.mp3");
    eArray[0] = Enemy({ 896, 128, 16, 16 }, &enemyBullets, Mix_LoadWAV("Enemy1.mp3"), 0, 99, 100);
    eArray[1] = Enemy({ 896, 320, 16, 16 }, &enemyBullets, Mix_LoadWAV("Enemy2.mp3"), 1, 50, 100);
    eArray[2] = Enemy({ 896, 512, 16, 16 }, &enemyBullets, Mix_LoadWAV("Enemy3.mp3"), 2, 25, 50);
    eArray[3] = Enemy({ 896, 704, 16, 16 }, &enemyBullets, Mix_LoadWAV("Enemy4.mp3"), 3, 49, 50);
    Mix_PlayMusic(g_pMusic, -1);
    g_bRunning = true;
    cout << "Success!" << endl;
    return true;
}

void wake()
{
g_start = SDL_GetTicks();
}

void sleep()
{
    g_end = SDL_GetTicks();
    g_delta = g_end - g_start;
    if (g_delta < g_fps)
        SDL_Delay (g_fps - g_delta)
}

void handleEvents()
{
SDL_Event event;
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
        case SDL_QUIT:
        g_bRunning = false;
        break;
        case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        g_bRunning = false;
        else if (event.key.keysym.sym == SDLK_SPACE)
        bulletVec.push_back(new Bullet(g_dst.x+60+g_dst.y+g_dst.h/2,));
        g_bRunning = false;
        break;
    }
    case SDL_KEYUP:
        if (event.key.keysym.sym>= SDLK_1 && event.key.keysym.sym <= SDLK_4)
        {
            int index = event.key.keysym.sym - 49;
            eArray[index].m_playSpawn = eArray[index]m_playSpawn;
        }
        break;
}
}

bool keydown(SDL_Scancode c)
{
    if (g_iKeystates != nullptr)
    {
        if (g_iKetstates[c] == 1)
        return true;
        else
           return false;
    }
    return false;
}

void checkCollision(SDL_Rect& p, SDL_Rect& b)
{
if (!(p.y > b.y + b.h || p.y + p.h < b.y ||
    p.x > b.x + b.w || p.x + p.w < b.x))
    g_isCol = true;

    if (!(e.y > b.y + b.h || e.y + e.h < b.y ||
    e.x > b.x + b.w || e.x + e.w < b.x))
    g_isCol = true;
}

void update()
{
if (keyDown(SDL_SCANCODE_W))
g_rBox.y -= g_iSpeed;
if (keydown(SDL_SCANCODE_W) = 0)
stop();
if (keyDown(SDL_SCANCODE_S))
g_rBox.y += g_iSpeed;
if (keyDown(SDL_SCANCODE_S) = 1)
stop()
if (keyDown(SDL_SCANCODE_A))
g_rBox.x -= g_iSpeed;
if (keyDown(SDL_SCANCODE_A) = 0)
stop()
if (keyDown(SDL_SCANCODE_D))
g_rBox.x += g_iSpeed;
if (keyDown(SDL_SCANCODE_D) = 1)
stop()
checkCollision(g_player, g_enemybox);
for (int i = 0; i < (int)bulletVec.size; i++)
{
    bulletVec[i] ->update();
    if (bulletVec[i] ->m_active == false)
    {
        delete bulletVec[i];
        bulletVec[i] = nullptr;
    }
}
if (!bulletVec.empty())
bulletVec.erase(remove( bulletVec.begin(), bulletVec.end(), nullptr), bulletVec.end() );
updatePanning();
    for (int i = 0; i < 4; i++)
        eArray[i].update();
    for (int i = 0; i < (int)enemyBullets.size(); i++)
    {
        enemyBullets[i]->update();
        if(enemyBullets[i]->m_active == false)
        {
            delete enemyBullets[i];
            enemyBullets[i] = nullptr;
        }
    }
    if (!enemyBullets.empty())
    {
        enemyBullets.erase(remove(enemyBullets.begin(), enemyBullets.end(), nullptr),enemyBullets.end());
        enemyBullets.shrink_to_fit();
    }
}

void render()
{
    if (g_pWindow != nullptr)
        {
            g_pRenderer = SDL CreateRenderer(g_pWindow, -1, 0);
            if (g_pRenderer != nullptr)
            {
                if (IMG_Init(IMG_INIT_PNG))
                {
                    g_pTexture = IMG_LoadTexture(g_pRenderer,"Spacebackground.png");
                }
                return false;
                src.x = 0;
                src.w = IMG.w;
                src.h = IMG.h;
                dst.x = 100;
                dst.w = IMG.w;
                dst.h = IMG.h;

SDL_SetRenderDrawColour(g_pRenderer, 0, 0, 255, 255);
SDL_RenderClear (g_pRenderer);

for (int i = 0; i <=4; i++)
{
    SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
        if (eArray[i].m_playSpawn)
            SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255);
        SDL_RenderFillRect(g_pRenderer, &eArray[i].m_dst);
}
SDL_SetRenderDrawColour(g_pRenderer, 0, 255, 255, 255);
for (int i = 0; i < (int)enemyBullets. size(); i++)
SDL_RenderFillRect(g_pRenderer, &enemyBullets[i]->m_dst);

SDL_RenderPresent(g_pRenderer);


SDL_RenderCopyEx(g_pRenderer, g_pTexture, &g_src, &g_dst, 90.0, nullptr, SDL_FLIP_NONE);
SDL_SetRenderDrawcolour(g_pRenderer, 255, 0, 0, 255)
for (int 1 = 0; i < (int)bulletVec.size(); i++)
{
    SDL_RenderFillRect(g_pRenderer, &bulletVec[i]->m_dst);
}
SDL_RenderPresent(g_pRenderer);

SDL_SetRenderDrawColour(g_pRenderer, 0, 255, 0, 255);
SDL_RenderFillRect(g_Renderer, &g_rBox);

SDL_RenderPresent(g_pRenderer);

if (g_iscol)
SDL_SetRenderDrawColour(g_pRenderer, 220, 0, 50, 255);

else
SDL_SetRenderDrawColour(g_pRenderer, 0, 255, 0, 255);
SDL_RenderFillRect(g_pRenderer, &g_box);
SDL_SetRenderDrawColour(g_pRenderer,136 ,80 ,100, 255);
SDL_RenderFillRect(g_pRenderer, &g_player);

if (g_iscol)
SDL_SetRenderDrawColour(g_pRenderer, 130, 0, 230, 255);

else
SDL_SetRenderDrawColour(g_pRenderer, 140, 220, 60, 255);
SDL_RenderFillRect(g_pRenderer, &g_enemybox);
SDL_SetRenderDrawColour(g_pRenderer,120 ,90 ,180, 255);
SDL_RenderFillRect(g_pRenderer, &g_enemy);

}

void clean()
{
cout << "Cleaning game now!" << endl;
for (int i = 0; i < (int)enemyBullets.size(); i++)
    {
        delete enemyBullets[i];
        enemyBullets[i] = nullptr;
    }
    enemyBullets.clear();
    enemyBullets.shrink_to_fit();
    Mix_CloseAudio();
    Mix_FreeMusic(g_pMusic);
    for (int i = 0; i < 4; i++)
        Mix_FreeChunk(eArray[i].m_pSound);
SDL_DestroyRenderer(g_pRenderer);
SDL_DestroyWindow(g_pWindow);
SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (init("GAME SDL Setup", SDL WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0) == false)
    return 1;

    while (g_bRunning)
    {
        wake();
        handleEvents();
        update();
        render();
       
    if (g_bRunning)
        sleep();
    }

    clean();
    return 0;
}

