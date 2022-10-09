/**********************************************************************************
// GravityGuy (C�digo Fonte)
// 
// Cria��o:     05 Out 2011
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game*   GravityGuy::level = nullptr;
Audio*  GravityGuy::audio = nullptr;
bool    GravityGuy::viewBBox = false;
float   GravityGuy::playerPos = 0.0f;
float   GravityGuy::playerLftVel = 200.0f;
float   GravityGuy::playerRgtVel = 0.0f;
float   GravityGuy::totalScale = 1.0f;
Player* GravityGuy::player = nullptr;

// ------------------------------------------------------------------------------

void GravityGuy::Init() 
{
    // cria sistema de �udio
    audio = new Audio();
    audio->Add(MENU, "Resources/Menu.wav");
    audio->Add(MUSIC, "Resources/Music.wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");

    //escala de todas as coisas na tela
    totalScale = window->Width() / 700.0f;

    // bounding box n�o vis�vel
    viewBBox = false;

    // cria jogador
    player = new Player(this->totalScale);

    // inicializa n�vel de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void GravityGuy::Update()
{
    // habilita/desabilita visualiza��o da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza n�vel
    level->Update();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Draw()
{
    // desenha n�vel
    level->Draw();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    //engine->window->Mode(WINDOWED);
    //engine->window->Size(700, 500);
    engine->window->Color(30, 50, 80);
    engine->window->Title("Gravity Guy");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new GravityGuy());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

