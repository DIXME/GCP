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
        // we get have beacuse when we display the rects we going to center them
        Vec2 whA = a.getSizeHalf();
        Vec2 whB = b.getSizeHalf();
        Vec2 posA = a.pos;
        Vec2 posB = b.pos;

        touchingX = this.Aleft.x < this.Bright.x && this.Bleft.x < this.Aright.x
        touchingY = this.Bdown.y > this.Aup.y && this.Adown.y > this.Bup.y
        touchingXY = touchingX && touchingY
        // these two are used to find wich quadrent the object falls into
        touchingNx = this.b.pos.x > this.a.pos.x
        touchingNy = this.a.pos.y > this.b.pos.y
    }
}