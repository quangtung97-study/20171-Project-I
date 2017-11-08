#ifndef LOGIC_FACTORY_PLANE_HPP
#define LOGIC_FACTORY_PLANE_HPP

#include <logic/actor/actor.hpp>
#include <logic/actor/plane.hpp>
#include <logic/abstract/event_manager.hpp>
#include <logic/basic/process_manager.hpp>
#include <sound/abstract/sound.hpp>
#include <graphics/gl/sprite_factory.hpp>
#include <graphics/abstract/drawable.hpp>
#include <graphics/gl/image_drawable_factory.hpp>

namespace tung {
namespace factory {

class Plane {
private:
    IEventManager& event_manager_;
    ISoundManager& sound_manager_;
    ProcessManager& process_manager_;
    SpriteFactory& sprite_factory_;
    IDrawableManagerPtr root_;
    ImageDrawableFactory& image_drawable_factory_;

public:
    Plane(IEventManager& event_manager, 
        ISoundManager& sound_manager,
        ProcessManager& process_manager,
        SpriteFactory& sprite_factory,
        ImageDrawableFactory& image_drawable_factory,
        IDrawableManagerPtr root
    ): event_manager_{event_manager}, 
        sound_manager_{sound_manager},
        process_manager_{process_manager},
        sprite_factory_{sprite_factory},
        image_drawable_factory_{image_drawable_factory},
        root_{std::move(root)} 
    {}

    std::weak_ptr<actor::Plane> new_plane(bool is_fighter = true);
};

} // namespace factory
} // namespace tung

#endif