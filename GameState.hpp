#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

// Define the game states
enum class GameState {
    StartMenu,
    Gameplay,
    SkinSelection,
    Leaderboard,
    GameOver
};

// Functions for handling transitions
GameState transitionTo(GameState currentState, GameState nextState);

#endif // GAME_STATE_HPP
