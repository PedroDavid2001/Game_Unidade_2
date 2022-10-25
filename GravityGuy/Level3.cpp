/**********************************************************************************
// Level1 (C�digo Fonte)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "NextLevel.h"
#include "Level3.h"
#include "Level4.h"
#include "BossLVL1.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include <string>
#include <fstream>
#include "Enemies.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* Level3::scene = nullptr;

// ------------------------------------------------------------------------------

void Level3::Init()
{
    //setta o level atual na classe principal
    GravityGuy::currentLvl = LEVEL_3;

    // cria gerenciador de cena
    scene = new Scene();

    //cria letreiro com o hp do player
    playerHp = new Font("Resources/Digital80.png");
    playerHp->Spacing("Resources/Digital80.dat");

    //cria letreiro com o score do player
    playerScore = new Font("Resources/Digital80.png");
    playerScore->Spacing("Resources/Digital80.dat");

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
    fin.open("Level3.txt");
    fin >> posX;

    while (!fin.eof())
    {
        if (fin.good())
        {
            // l� linha com informa��es da plataforma
            fin >> posY; fin >> platType;
            plat = new Platform(posX, posY, platType, white);
            scene->Add(plat, STATIC);
        }
        else
        {
            // ignora coment�rios
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();

    // ----------------------

    Enemies* enemy;

    uint  enemyType;
    fin.open("InimigosLevel3.txt");
    fin >> posX;

    while (!fin.eof())
    {
        if (fin.good())
        {
            // l� linha com informa��es da plataforma
            fin >> posY; fin >> enemyType;
            enemy = new Enemies(posX, posY, enemyType, white);
            scene->Add(enemy, MOVING);
        }
        else
        {
            // ignora coment�rios
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();

    // ----------------------


    endLvl = new EndLevel(11535.0f * GravityGuy::totalScale, 290.0f * GravityGuy::totalScale);
    scene->Add(endLvl, MOVING);

    // ----------------------

    // inicia com m�sica
    GravityGuy::audio->Frequency(MUSIC, 1.0f);
    GravityGuy::audio->Frequency(TRANSITION, 1.0f);
    GravityGuy::audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level3::Update()
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

    if (scene->Collision(GravityGuy::player, endLvl)) {
        GravityGuy::NextLevel<NextLevel>();
        GravityGuy::player->Reset();
    }
    else if (window->KeyPress(VK_ESCAPE))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->hp <= 0)
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
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
        GravityGuy::NextLevel<NextLevel>();
        GravityGuy::player->Reset();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level3::Draw()
{
    currentHp.str("");
    currentHp << "Life  " << (int)GravityGuy::player->hp;
    playerHp->Draw(100.0f * GravityGuy::totalScale, 650.0f * GravityGuy::totalScale, currentHp.str(), Color{ 1,1,1,1 }, Layer::FRONT, GravityGuy::totalScale, 0.0f);

    currentScore.str("");
    currentScore << "Score  " << (int)GravityGuy::player->score;
    playerScore->Draw(100.0f * GravityGuy::totalScale, 50.0f * GravityGuy::totalScale, currentScore.str(), Color{ 1,1,1,1 }, Layer::FRONT, GravityGuy::totalScale, 0.0f);

    backg->Draw();
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level3::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
    delete playerHp;
}

// ------------------------------------------------------------------------------
