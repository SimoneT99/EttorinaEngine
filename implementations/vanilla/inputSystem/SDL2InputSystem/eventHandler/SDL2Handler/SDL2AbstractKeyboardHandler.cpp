#include "..\headers\vanilla\inputSystem\SDL2InputSystem\eventHandler\SDL2Handler\SDL2AbstractKeyboardHandler.hpp"

/**
 * NOTE: probably slow, might be optimized
 */

Enums::KeyButton SDL2AbstractKeyboardHandler::convertSDLtoKeyButton(SDL_Keycode  sdlButton) const{
    switch (sdlButton) {
        // Lettere
        case SDLK_b: return Enums::KeyButton::B;
        case SDLK_c: return Enums::KeyButton::C;
        case SDLK_d: return Enums::KeyButton::D;
        case SDLK_e: return Enums::KeyButton::E;
        case SDLK_f: return Enums::KeyButton::F;
        case SDLK_g: return Enums::KeyButton::G;
        case SDLK_h: return Enums::KeyButton::H;
        case SDLK_i: return Enums::KeyButton::I;
        case SDLK_j: return Enums::KeyButton::J;
        case SDLK_k: return Enums::KeyButton::K;
        case SDLK_l: return Enums::KeyButton::L;
        case SDLK_m: return Enums::KeyButton::M;
        case SDLK_n: return Enums::KeyButton::N;
        case SDLK_o: return Enums::KeyButton::O;
        case SDLK_p: return Enums::KeyButton::P;
        case SDLK_q: return Enums::KeyButton::Q;
        case SDLK_r: return Enums::KeyButton::R;
        case SDLK_a: return Enums::KeyButton::A;
        case SDLK_s: return Enums::KeyButton::S;
        case SDLK_t: return Enums::KeyButton::T;
        case SDLK_u: return Enums::KeyButton::U;
        case SDLK_v: return Enums::KeyButton::V;
        case SDLK_w: return Enums::KeyButton::W;
        case SDLK_x: return Enums::KeyButton::X;
        case SDLK_y: return Enums::KeyButton::Y;
        case SDLK_z: return Enums::KeyButton::Z;

        // Numeri
        case SDLK_0: return Enums::KeyButton::NUM_0;
        case SDLK_1: return Enums::KeyButton::NUM_1;
        case SDLK_2: return Enums::KeyButton::NUM_2;
        case SDLK_3: return Enums::KeyButton::NUM_3;
        case SDLK_4: return Enums::KeyButton::NUM_4;
        case SDLK_5: return Enums::KeyButton::NUM_5;
        case SDLK_6: return Enums::KeyButton::NUM_6;
        case SDLK_7: return Enums::KeyButton::NUM_7;
        case SDLK_8: return Enums::KeyButton::NUM_8;
        case SDLK_9: return Enums::KeyButton::NUM_9;

        // Tasti funzione
        case SDLK_F1: return Enums::KeyButton::F1;
        case SDLK_F2: return Enums::KeyButton::F2;
        case SDLK_F3: return Enums::KeyButton::F3;
        case SDLK_F4: return Enums::KeyButton::F4;
        case SDLK_F5: return Enums::KeyButton::F5;
        case SDLK_F6: return Enums::KeyButton::F6;
        case SDLK_F7: return Enums::KeyButton::F7;
        case SDLK_F8: return Enums::KeyButton::F8;
        case SDLK_F9: return Enums::KeyButton::F9;
        case SDLK_F10: return Enums::KeyButton::F10;
        case SDLK_F11: return Enums::KeyButton::F11;
        case SDLK_F12: return Enums::KeyButton::F12;

        // Simboli principali
        case SDLK_BACKQUOTE: return Enums::KeyButton::GRAVE_ACCENT;
        case SDLK_MINUS: return Enums::KeyButton::MINUS;
        case SDLK_EQUALS: return Enums::KeyButton::EQUAL;
        case SDLK_LEFTBRACKET: return Enums::KeyButton::LEFT_BRACKET;
        case SDLK_RIGHTBRACKET: return Enums::KeyButton::RIGHT_BRACKET;
        case SDLK_BACKSLASH: return Enums::KeyButton::BACKSLASH;
        case SDLK_SEMICOLON: return Enums::KeyButton::SEMICOLON;
        case SDLK_COMMA: return Enums::KeyButton::COMMA;
        case SDLK_PERIOD: return Enums::KeyButton::PERIOD;
        case SDLK_SLASH: return Enums::KeyButton::SLASH;

        // Modificatori
        case SDLK_LSHIFT: return Enums::KeyButton::LEFT_SHIFT;
        case SDLK_RSHIFT: return Enums::KeyButton::RIGHT_SHIFT;
        case SDLK_LCTRL: return Enums::KeyButton::LEFT_CONTROL;
        case SDLK_RCTRL: return Enums::KeyButton::RIGHT_CONTROL;
        case SDLK_LALT: return Enums::KeyButton::LEFT_ALT;
        case SDLK_RALT: return Enums::KeyButton::RIGHT_ALT;
        case SDLK_LGUI: return Enums::KeyButton::LEFT_SUPER;
        case SDLK_RGUI: return Enums::KeyButton::RIGHT_SUPER;

        // Altri tasti
        case SDLK_SPACE: return Enums::KeyButton::SPACE;
        case SDLK_RETURN: return Enums::KeyButton::ENTER;
        case SDLK_BACKSPACE: return Enums::KeyButton::BACKSPACE;
        case SDLK_TAB: return Enums::KeyButton::TAB;
        case SDLK_CAPSLOCK: return Enums::KeyButton::CAPS_LOCK;
        case SDLK_ESCAPE: return Enums::KeyButton::ESCAPE;
        case SDLK_INSERT: return Enums::KeyButton::INSERT;
        case SDLK_DELETE: return Enums::KeyButton::DELETE;
        case SDLK_HOME: return Enums::KeyButton::HOME;
        case SDLK_END: return Enums::KeyButton::END;
        case SDLK_PAGEUP: return Enums::KeyButton::PAGE_UP;
        case SDLK_PAGEDOWN: return Enums::KeyButton::PAGE_DOWN;
        case SDLK_UP: return Enums::KeyButton::ARROW_UP;
        case SDLK_DOWN: return Enums::KeyButton::ARROW_DOWN;
        case SDLK_LEFT: return Enums::KeyButton::ARROW_LEFT;
        case SDLK_RIGHT: return Enums::KeyButton::ARROW_RIGHT;

        default: return Enums::KeyButton::END; // Se il tasto non è riconosciuto
    }
};
