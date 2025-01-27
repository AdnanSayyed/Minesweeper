
#include "../header/UI/Gameplay/GameplayUIController.h"
#include "../header/UI/UIElement/ImageView.h"
#include "../header/UI/UIElement/ButtonView.h"
#include "../header/UI/UIElement/TextView.h"
#include "../header/Global/Servicelocator.h"

#include <iomanip>
#include <sstream>
#include <string>

namespace UI
{
    namespace MainMenu
    {
        using namespace UIElement;
        using namespace Global;

        GameplayUIController::GameplayUIController()
        {
            createTexts();
        }

        GameplayUIController::~GameplayUIController()
        {
            destroy();
        }

        void GameplayUIController::createTexts()
        {
            time_text = new TextView();
        }

        void GameplayUIController::initialize()
        {
            initializeTexts();
        }

        void GameplayUIController::initializeTexts()
        {
            initializeTimeText();
        }

        void GameplayUIController::initializeTimeText()
        {
            time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
        }

        void GameplayUIController::show()
        {
            time_text->show();
        }

        void GameplayUIController::update()
        {
            updateTimeText();
        }

        void GameplayUIController::render()
        {
            time_text->render();
        }

        void GameplayUIController::updateTimeText()
        {
            int remaining_time = ServiceLocator::getInstance()->getGameplayService()->getRemainingTime();

            std::stringstream stream;
            stream << std::setw(3) << std::setfill('0') << remaining_time;
            std::string string_remaining_time = stream.str();

            time_text->setText(string_remaining_time);
            time_text->update();
        }

        void GameplayUIController::destroy()
        {
            delete (time_text);
        }
    }

}
