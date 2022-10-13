/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _GRAVITYGUY_PLAYER_H_
#define _GRAVITYGUY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum PlayerState { IDLE, MOVE, JUMP, ATACK, HURT };         

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // anima��o do personagem
	uint		state;
	Timer		jumpTimer;				//timer usado para definir o tempo do pulo
    float       jumpForce;
    int         level;                  // n�vel finalizado
	bool        canJump;				//verifica se o player est� sobre uma plataforma para poder pular
    bool        falling;                //verifica se existe algo abaixo do player
    float       scale;
	
public:
    Player(float scale);                // construtor
    ~Player();                          // destrutor
    
    float currentPos;                   //posi��o atual baseada na quantidade de terreno que j� foi percorrido
    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo
    float Right();
    float Left();
    float Width();
    float Height();

    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Player::Level()
{ return level; }

inline float Player::Height()
{
    return tileset->TileHeight() * scale;
}

inline float Player::Width()
{
    return tileset->TileWidth() * scale;
}

inline float Player::Bottom()
{ 
    return y + ( tileset->TileHeight() / 2.0f );
}

inline float Player::Top()
{ 
    return y - ( tileset->TileHeight() / 2.0f );
}

inline float Player::Right()
{
    return x + ( tileset->TileWidth() / 2.0f );
}

inline float Player::Left()
{
    return x - ( tileset->TileWidth() / 2.0f );
}

inline void Player::Draw()
{ anim->Draw(x, y, z, scale); }

// ---------------------------------------------------------------------------------

#endif