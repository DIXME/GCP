#include "GameEngine/vectors.h"

struct rect2d_t
{
    float x;
    float y;
    float w;
    float h;

    // this structure is used to calcute the bounding box of a sprite
    // when a rect is drawn it is drawn from the center of the rect
    Vec2 getCenter() const
    {
        return Vec2({x + w / 2, y + h / 2});
    }

    Vec2 getSize() const
    {
        return Vec2({w, h});
    }

    Vec2 getTopLeft() const
    {
        return Vec2({x - w / 2, y - h / 2});
    }
    Vec2 getTopRight() const
    {
        return Vec2({x + w / 2, y - h / 2});
    }

    Vec2 getBottomLeft() const
    {
        return Vec2({x - w / 2, y + h / 2});
    }

    Vec2 getBottomRight() const
    {
        return Vec2({x + w / 2, y + h / 2});
    }

    Vec2 getTop() const
    {
        return Vec2({x, y - h / 2});
    }

    Vec2 getBottom() const
    {
        return Vec2({x, y + h / 2});
    }

    Vec2 getLeft() const
    {
        return Vec2({x - w / 2, y});
    }

    Vec2 getRight() const
    {
        return Vec2({x + w / 2, y});
    }

    Vec2 getSizeHalf() const
    {
        return Vec2({w / 2, h / 2});
    }

    Vec2 touching(const rect2d_t &other) const
    {
        return Vec2({x - other.x, y - other.y});
    }

    rect2d_t(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
    rect2d_t() : x(0), y(0), w(0), h(0) {}
};