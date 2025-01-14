#include "..\headers\vanilla\inputSystem\SDL2InputSystem\SDL2InputController.hpp"

SDL2InputController::SDL2InputController(int updates_per_second){

    SDL2_PRINT_FOR_DEBUG("Starting input controller...", false)

    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cerr << "Error in SDL Input SubSystem initialization: " << SDL_GetError() << std::endl;
    }

    SDL2_PRINT_FOR_DEBUG("No error in SDL2 init...", false)

    this->target_frame_duration = std::chrono::duration<double>(1.0 / updates_per_second);
    this->running = new std::atomic<bool>(false); //memory leak?

    SDL2_PRINT_FOR_DEBUG("Input controller constructor done...", false)
}

SDL2InputController::~SDL2InputController(){
    this->running = false;
    this->input_loop_thread.join();
    SDL_Quit();
}

/**
 * Keyboard management
 */

bool SDL2InputController::key_pressed_down(Enums::KeyButton button) const{
    return this->keyboard_manager->key_pressed_down(button);
}

bool SDL2InputController::key_pressed(Enums::KeyButton button) const{
    return this->keyboard_manager->key_pressed(button);
}

bool SDL2InputController::key_released(Enums::KeyButton button) const{
    return this->keyboard_manager->key_released(button);
}

void SDL2InputController::bind_key_event(Enums::KeyButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action){    
    this->keyboard_manager->bind_key_event(button, event, std::move(action));
}

void SDL2InputController::unbind_key_event(Enums::KeyButton button, Enums::ButtonEvent event){
    this->keyboard_manager->unbind_key_event(button, event);
}

/**
 * Mouse management
 */

void SDL2InputController::get_mouse_position(float& x, float& y) const{
    this->mouse_manager->get_mouse_position(x, y);
}

void SDL2InputController::get_mouse_delta(float& dx, float& dy) const{
   this->mouse_manager->get_mouse_delta(dx, dy);
}

void SDL2InputController::get_mouse_wheel_delta(float& dx, float& dy) const{
    this->mouse_manager->get_mouse_wheel_delta(dx, dy);
}

bool SDL2InputController::mouse_button_pressed_down(Enums::MouseButton button) const{
    return this->mouse_manager->mouse_button_pressed_down(button);
}

bool SDL2InputController::mouse_button_pressed(Enums::MouseButton button) const{
    return this->mouse_manager->mouse_button_pressed(button);
}

bool SDL2InputController::mouse_button_released(Enums::MouseButton button) const{
    return this->mouse_manager->mouse_button_released(button);
}

void SDL2InputController::bind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action){
    this->mouse_manager->bind_mouse_event(button, event, std::move(action));
}

void SDL2InputController::unbind_mouse_event(Enums::MouseButton button, Enums::ButtonEvent event){
    this->mouse_manager->unbind_mouse_event(button, event);
}

/**
 * Controller Management
 */

bool SDL2InputController::controller_button_pressed_down(int controllerId, Enums::ControllerButton button) const{
    //TODO
    return false;
}

bool SDL2InputController::controller_button_pressed(int controllerId, Enums::ControllerButton button) const{
    return false;
}

bool SDL2InputController::controller_button_released(int controllerId, Enums::ControllerButton button) const{
    return false;
}
   
void SDL2InputController::get_controller_axis(int controllerId, Enums::ControllerAxis axis, float& value) const{
    //TODO
}

void SDL2InputController::bind_controller_event(int controllerId, Enums::ControllerButton button, Enums::ButtonEvent event, std::unique_ptr<AbstractInputCommand> action){
   //TODO
}

void SDL2InputController::unbind_controller_event(int controllerId, Enums::ControllerButton button, Enums::ButtonEvent event){
    //TODO
}

void SDL2InputController::tick(){
    this->mouse_manager->tick();
    this->keyboard_manager->tick();
    //TODO manage controller
}

void SDL2InputController::update_loop(){

    SDL_Event event;

    while(this->running){

        auto start_time = std::chrono::steady_clock::now();

        while(SDL_PollEvent(&event)){
            this->event_handler->handle(event);
        }

        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_time = end_time - start_time;

        if (elapsed_time < target_frame_duration) {
            std::this_thread::sleep_for(target_frame_duration - elapsed_time);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}


/**
* Setup methods
*/

void SDL2InputController::set_keyboard_manager(std::shared_ptr<AbstractKeyboardManager> keyboardManager){
    this->keyboard_manager = keyboard_manager;
}

void SDL2InputController::set_mouse_manager(std::shared_ptr<AbstractMouseManager> mouseManager){
    this->mouse_manager = mouse_manager;
}

void SDL2InputController::set_controller_manager(std::shared_ptr<AbstractControllerManager> controllerManager){
    //TODO
}

void SDL2InputController::set_event_handler(std::shared_ptr<SDL2EventHandlerInterface> event_handler){
    this->event_handler = event_handler;
}

void SDL2InputController::run(){
    this->running = true;
    this->input_loop_thread = std::thread(&update_loop, this);
}