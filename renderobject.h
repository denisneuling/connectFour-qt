#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

//! abstract class for each renderable object
class RenderObject
{
public:
    virtual void init()
    {

    }

    virtual void draw() = 0;

    virtual void resize(int width, int height) = 0;
};

#endif // RENDEROBJECT_H
