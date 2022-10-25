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
#include "TileSet.h"

// ------------------------------------------------------------------------------

enum PlayerState { IDLE, IDLE_INV, MOVE, MOVE_INV, JUMP, JUMP_INV, ATACK, ATACK_INV, HURT, ATK_JMP, ATK_JMP_INV };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // anima��o do personagem
    Timer		jumpTimer;				//timer usado para definir o tempo do pulo
    float       jumpForce;
    float       gravity;
	bool        canJump;				//verifica se o player est� sobre uma plataforma para poder pular
    bool        direction;              //left = false; right = true
    float       scale;
    bool        shooted;
    
public:
    bool        showCtrls;              //exibeControles na tela
    uint        hp;
    float        score;
    uint		state;
    bool        left;                   //verifica se pode ir para esquerda
    bool        right;                  //verifica se pode ir para direita

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
    return y + ( this->Height() / 2.0f);
}

inline float Player::Top()
{ 
    return y - (this->Height() / 2.0f );
}

inline float Player::Right()
{
    return x + ( this->Width() / 2.0f );
}

inline float Player::Left()
{
    return x - (this->Width() / 2.0f );
}

inline void Player::Draw()
{ anim->Draw(x, y, 0.45f, scale); }

// ---------------------------------------------------------------------------------

#endif