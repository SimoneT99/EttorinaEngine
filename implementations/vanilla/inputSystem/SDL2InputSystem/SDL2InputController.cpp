#include "..\headers\vanilla\inputSystem\SDL2InputSystem\SDL2InputController.hpp"

SDL2InputController::SDL2InputController(int updates_per_second){

    SDL2_PRINT_FOR_DEBUG("Creating SDL2 input controller...", false)

    this->target_frame_duration = std::chrono::duration<double>(1.0 / updates_per_second);
    this->running = new std::atomic<bool>(false); //memory leak?

    SDL2_PRINT_FOR_DEBUG("Input controller constructor done...", false)
}

SDL2InputController::~SDL2InputController(){

    SDL2_PRINT_FOR_DEBUG("Destroing SDL2 input controller...", false)

    this->running = false;
    this->input_loop_thread.join();

    SDL2_PRINT_FOR_DEBUG("No error in SDL2 init...", false)
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

void SDL2InputController::SDL2_event_loop(){

    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cerr << "Error in SDL Input SubSystem initialization: " << SDL_GetError() << std::endl;
    }

    this->hiddenWindow = SDL_CreateWindow(
        "SDLWindow", 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        200, 200,
        SDL_WINDOW_RESIZABLE
    );


    if (!this->hiddenWindow) {
        std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
    }

    SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);
    SDL_EventState(SDL_KEYUP, SDL_ENABLE);
    SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
    SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_ENABLE);
    SDL_EventState(SDL_MOUSEBUTTONUP, SDL_ENABLE);

    SDL2_PRINT_FOR_DEBUG("No error in SDL2 init...", false)


    SDL_Event event;
    long cycle = 0;

    while(this->running){
        SDL2_PRINT_FOR_DEBUG("update loop starting..." << cycle, true)
        cycle++;

        auto start_time = std::chrono::steady_clock::now();

        SDL_PumpEvents();
        while(SDL_PollEvent(&event)){
            SDL2_PRINT_FOR_DEBUG("SDL2 Event Polled...", false)
            this->event_handler->handle(event);
        }

        SDL_Delay(10);

        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_time = end_time - start_time;

        if (elapsed_time < target_frame_duration) {
            std::this_thread::sleep_for(target_frame_duration - elapsed_time);
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    free(this->hiddenWindow); //to avoid memory leaks

    SDL_Quit();
}


/**
* Setup methods
*/

void SDL2InputController::set_keyboard_manager(std::shared_ptr<AbstractKeyboardManager> keyboard_manager){
    SDL2_PRINT_FOR_DEBUG("Setting the keyboard manager of the controller...", false)
    this->keyboard_manager = keyboard_manager;
}

void SDL2InputController::set_mouse_manager(std::shared_ptr<AbstractMouseManager> mouse_manager){
    SDL2_PRINT_FOR_DEBUG("Setting the mouse manager of the controller...", false)
    this->mouse_manager = mouse_manager;
}

void SDL2InputController::set_controller_manager(std::shared_ptr<AbstractControllerManager> controller_manager){
    //TODO
}

void SDL2InputController::set_event_handler(std::shared_ptr<SDL2EventHandlerInterface> event_handler){
    SDL2_PRINT_FOR_DEBUG("Setting the event chain of the controller...", false)
    this->event_handler = event_handler;
}

void SDL2InputController::run(){
    SDL2_PRINT_FOR_DEBUG("Starting the event loop of the controller...", false)
    this->running = true;
    this->input_loop_thread = std::thread(&SDL2_event_loop, this);
}