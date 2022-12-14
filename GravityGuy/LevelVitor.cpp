/**********************************************************************************
// Level1 (C?digo Fonte)
//
// Cria??o:     14 Fev 2013
// Atualiza??o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   N?vel 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "LevelVitor.h"
#include "BossLVL1.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est?ticos da classe

Scene* LevelVitor::scene = nullptr;

// ------------------------------------------------------------------------------

void LevelVitor::Init()
{
    //setta o level atual na classe principal
    GravityGuy::currentLvl = LEVEL_VITOR;

    // cria gerenciador de cena
    scene = new Scene();

    //cria letreiro com o hp do boss
    position = new Font("Resources/Digital80.png");
    position->Spacing("Resources/Digital80.dat");

    timer.Start();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 });
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);


    Platform* plat;
    Color white{ 1,1,1,1 };

    // ----------------------
    // plataformas
    // ----------------------

    float posX, posY;
    uint  platType;
    ifstream fin;
    fin.open("LevelVitor.txt");
    fin >> posX;

    while (!fin.eof())
    {
        if (fin.good())
        {
            // l? linha com informa??es da plataforma
            fin >> posY; fin >> platType;
            plat = new Platform(posX, posY, platType, white);
            scene->Add(plat, STATIC);
        }
        else
        {
            // ignora coment?rios
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();

    // ----------------------

    // inicia com m?sica
    GravityGuy::audio->Frequency(MUSIC, 1.0f);
    GravityGuy::audio->Frequency(TRANSITION, 1.0f);
    GravityGuy::audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void LevelVitor::Update()
{
    float start = window->CenterX();

    if (GravityGuy::playerPos < start) {
        GravityGuy::playerRgt = true;
        GravityGuy::playerLft = true;
    }
    else if (GravityGuy::playerPos >= start) {
        GravityGuy::playerRgt = false;
        GravityGuy::playerLft = false;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Top() > window->Height())
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
        GravityGuy::player->Reset();
    }
    else if (window->KeyPress('N'))
    {
        GravityGuy::NextLevel<BossLVL1>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void LevelVitor::Draw()
{
    currentPos.str("");
    currentPos << "DISTANCE " << (int)GravityGuy::playerPos;
    position->Draw(window->CenterX(), 50.0f * GravityGuy::totalScale, currentPos.str(), Color{ 1,1,1,1 }, Layer::FRONT, (GravityGuy::totalScale / 2.0f), 0.0f);

    backg->Draw();
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void LevelVitor::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
    delete position;
}

// ------------------------------------------------------------------------------
