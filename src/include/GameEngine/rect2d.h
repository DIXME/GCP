#include "GameEngine/vectors.h"

struct rect2d_t
{
    Vec2 pos;
    Vec2 whv;

    // this structure is used to calcute the bounding bopos.x of a sprite
    // when a rect is drawn it is drawn from the center of the rect

    rect2d_t(Vec2 pos, Vec2 whv) : pos(pos), whv(whv) {
        //
    }
};

struct rectRectCollisonData {
    rect2d_t a;
    rect2d_t b;

    bool touchingXY;
    bool touchingX;
    bool touchingY;
    bool touchingNx; // negtive pos.x
    bool touchingNy; // negtive pos.y

    void update(){
        Vec2 Aleft  = Vec2(a.pos.x - a.whv.x / 2, a.pos.y);
        Vec2 Aright = Vec2(a.pos.x + a.whv.x / 2, a.pos.y);
        Vec2 Aup    = Vec2(a.pos.x, a.pos.y - a.whv.y / 2);
        Vec2 Adown  = Vec2(a.pos.x, a.pos.y + a.whv.y / 2);
        //----------------------a&b----------------------\\ 
        Vec2 Bleft  = Vec2(b.pos.x - b.whv.x / 2, b.pos.y);
        Vec2 Bright = Vec2(b.pos.x + b.whv.x / 2, b.pos.y);
        Vec2 Bup    = Vec2(b.pos.x, b.pos.y - b.whv.y / 2);
        Vec2 Bdown  = Vec2(b.pos.x, b.pos.y + b.whv.y / 2);     

        touchingX = Aleft.x < Bright.x && Bleft.x < Aright.x;
        touchingY = Bdown.y > Aup.y && Adown.y > Bup.y;
        touchingXY = touchingX && touchingY;
        // these two are used to find wich quadrent the object falls into
        touchingNx = b.pos.x > a.pos.x;
        touchingNy = a.pos.y > b.pos.y;
    }

    rectRectCollisonData(rect2d_t a, rect2d_t b) : 
        a(a), b(b), touchingX(false), touchingY(false),
        touchingXY(false), touchingNx(false), touchingNy(false) {
        //
    }
};