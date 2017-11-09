#ifndef GAME_LOGIC_STATE_MANAGER_HPP
#define GAME_LOGIC_STATE_MANAGER_HPP

#include "game_state.hpp"
#include <graphics/abstract/drawable.hpp>
#include <graphics/gl/image_drawable_factory.hpp>
#include <graphics/gl/sprite_factory.hpp>
#include <logic/abstract/event_manager.hpp>
#include <logic/basic/process_manager.hpp>
#include <sound/abstract/sound.hpp>

namespace tung {
namespace state {

class Manager {
private:
    friend class GameState;
    friend class StartState;
    friend class PlayingState;
    friend class EndState;

    GameState *current_;

    GameStatePtr start_;
    GameStatePtr playing_;
    GameStatePtr end_;

private:
    IEventManager& event_manager_;
    ProcessManager& process_manager_;
    ImageDrawableFactory& image_drawable_factory_;
    SpriteFactory& sprite_factory_;
    ISoundManager& sound_manager_;
    IDrawableManagerPtr root_drawable_;
    IDrawableManagerPtr lower_group_;
    IDrawableManagerPtr middle_group_;
    IDrawableManagerPtr upper_group_;

public:
    Manager(IEventManager& manager, 
        ProcessManager& process_manager,
        ImageDrawableFactory& image_drawable_factory,
        SpriteFactory& sprite_factory,
        ISoundManager& sound_manager,
        IDrawableManagerPtr root_drawable
    ): event_manager_{manager},
        process_manager_{process_manager},
        image_drawable_factory_{image_drawable_factory},
        sprite_factory_{sprite_factory},
        sound_manager_{sound_manager},
        root_drawable_{std::move(root_drawable)}
    { init(); }

    void init();

    void make_transition_to(GameState& state);

    bool on_mouse_event(MouseButton button, 
        MouseEventType type, float x, float y);

    IEventManager& get_event_manager() const {
        return event_manager_;
    }

    IDrawableManager& root() const {
        return *middle_group_;
    }

    IDrawableManagerPtr get_root() const {
        return middle_group_;
    }

    IDrawableManagerPtr get_lower_group() const {
        return lower_group_;
    }

    IDrawableManagerPtr get_upper_group() const {
        return upper_group_;
    }

    ProcessManager& get_process_manager() const {
        return process_manager_;
    }

    ImageDrawableFactory& get_image_factory() const {
        return image_drawable_factory_;
    }

    SpriteFactory& get_sprite_factory() const {
        return sprite_factory_;
    }

    ISoundManager& get_sound_manager() const {
        return sound_manager_;
    }
};

}
} // namespace tung

#endif