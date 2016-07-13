/* 
 * File:   sceneContent.hpp
 * Author: marie
 *
 * Created on 8 juillet 2016, 23:04
 */

#ifndef SCENECONTENT_HPP
#define SCENECONTENT_HPP

namespace GenContent
{
    class ElementContent;
    
    class SceneContent
    {
    public:
        SceneContent()
        : exploHour(12), framebuffer(false), _elements()
        {}
        ~SceneContent()
        {
            _elements.clear();
        }

        inline std::vector<ElementContent *>&   elements() {
            return _elements;
        }
        
        //TODO put these in ClimateElement
        int exploHour;
        bool framebuffer;

    private:
        std::vector<ElementContent *>   _elements;
    };
}

#endif /* SCENECONTENT_HPP */

