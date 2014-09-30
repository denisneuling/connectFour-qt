#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

/*!
 * \class RenderObject
 * \brief iface for objects which are able to be rendered
 * \details abstract class for each renderable object
 *
 * \author Roland Luckenhuber
 * \author Denis Neuling
 */
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
