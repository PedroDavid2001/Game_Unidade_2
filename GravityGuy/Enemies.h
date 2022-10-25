/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_ENEMIES_H_
#define _GRAVITYGUY_ENEMIES_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
#include "GravityGuy.h"
#include <random>

using namespace std;

// ---------------------------------------------------------------------------------

enum ENEMIES { ENEMY, ENEMY_FLY };

enum EnemyState { IDLE_I, IDLE_INV_I };


// ---------------------------------------------------------------------------------

class Enemies : public Object
{
private:
    TileSet* tileSet = nullptr;             // sprite da plataforma
    Animation* anim = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma
    float xOrigin, yOrigin;                 // posi��es de origem das plataformas m�veis (s�o alteradas quando o player se move)
    float velocity;                         //velocidade alterada da plataforma para diferenciar o movimento
    random_device rd;
    mt19937 mt{ rd() };

    uniform_real_distribution<float> altVel{ 1.0f, 1.5f }; //alterador da velocidade da plataforma

public:
    float direcao = 1.0f;                   //dire��o do movimento (inverte quando a plataforma alcan�a um limite)
    uint enemyType;
    uint state;
    bool touched;
    bool touchedBullet;
    Timer time;
    uint hp;
    Enemies(float posX, float posY,
        uint plat,
        Color tint);                   // construtor    
    ~Enemies();                            // destrutor

    void Update();                          // atualiza��o do objeto

    
    void Draw();                            // desenho do objeto
    float Height();
    float Width();
    float Bottom();
    float Top();
    float Left();
    float Right();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Enemies::Draw()
{
    anim->Draw(x, y, z, GravityGuy::totalScale, 0.0f, color);
}

inline float Enemies::Height()
{
    return tileSet->TileHeight() * GravityGuy::totalScale;
}

inline float Enemies::Width()
{
    return tileSet->TileWidth() * GravityGuy::totalScale;
}

inline float Enemies::Bottom()
{
    return y + (this->Height() / 2.0f);
}

inline float Enemies::Top()
{
    return y - (this->Height() / 2.0f);
}

inline float Enemies::Right()
{
    return x + (this->Width() / 2.0f);
}

inline float Enemies::Left()
{
    return x - (this->Width() / 2.0f);

}
// ---------------------------------------------------------------------------------

#endif