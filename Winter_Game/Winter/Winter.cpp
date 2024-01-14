/*
	Incluse Ground.h
	Inherit a class from GroundApp. Override method OnUpdate in it.
	Feed the name of your class to START_GROUND_GAME_ENGINE macro.
*/

#include "Ground.h"

class WinterGame : public Ground::GroundApp {
public:
	WinterGame()
	{
		Ground::GroundWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Ground::KeyPressedEvent& event) {OnKeyPress(event); }
		);

		Ground::GroundWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Ground::KeyReleasedEvent& event) {OnKeyRelease(event); }
		);
	}
	void OnUpdate() override
	{
		//======GAME LOGIC=======
		Ground::Renderer::Clear();

		Ground::Renderer::Draw(m_Backgroud, -200, -100, 1);

		OnUpdateCharacter(m_Character);
		Ground::Renderer::Draw(m_Character);		
	}
private: //Data needed for the game
	Ground::Picture m_Backgroud{ "Assets/Textures/finalBackground.png" };
	Ground::Unit m_Character{ "Assets/Textures/character2.png", 1 };

	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		NOT_MOVING
	} m_State{ CharState::NOT_MOVING };

	void OnKeyPress(const Ground::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case GROUND_KEY_A:
			m_State = CharState::MOVE_LEFT;
			break;
		case GROUND_KEY_D:
			m_State = CharState::MOVE_RIGHT;
			break;
		}
	}

	void OnKeyRelease(const Ground::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case GROUND_KEY_A:
			if (m_State == CharState::MOVE_LEFT)
				m_State = CharState::NOT_MOVING;
			break;
		case GROUND_KEY_D:
			if (m_State == CharState::MOVE_RIGHT)
				m_State = CharState::NOT_MOVING;
			break;
		}
	}

	void OnUpdateCharacter(Ground::Unit& character) //change the characters position based on key pressed
	{
		if (m_State == CharState::MOVE_LEFT)
			character.ChangeX(-15);
		else if (m_State == CharState::MOVE_RIGHT)
			character.ChangeX(15);
		else if (m_State == CharState::NOT_MOVING)
			character.ChangeX(0);
	}
};

START_GROUND_GAME_ENGINE(WinterGame)