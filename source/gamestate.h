#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <string>
#include "square.h"
#include "window.h"

class ChessMove;
class Piece;

class GameState 
{
    // All Actions are friends of GameState
    // since modifying the state should not be available
    // to the public
    friend class ChessMove;
    friend class Undo;
    friend class Castle;
    friend class EnPassant;
    friend class Promotion;
    friend class Resign;

    Xwindow *w;
    GameState *previousState;
    Square chessboard[8][8];

    bool whiteTurn;
    bool gameEnded;
    int gameResult;

    //sets the numberings and passes the window to each square
    void setSquareNumberings();

    //used within doSetupMode() to check if a state is proper
    bool isValidSetupState() const;

public:
    //possible results of the game
    static const int BLACK_WINS_BY_CHECKMATE = 1;
    static const int WHITE_WINS_BY_CHECKMATE = 2;
    static const int BLACK_RESIGNS = 3;
    static const int WHITE_RESIGNS = 4;
    static const int STALEMATE = 5;

    GameState(Xwindow *w, bool enterSetupMode = false);
    
    void doSetupMode();

    // initializes a default board
    void initializeDefault ();

    //swaps the turns
    void swapTurns();

    bool isGameEnded() const;

    bool isWhiteTurn() const;

    void setGameEnded(int result);

    int getGameResult() const;

    // returns list of possible moves without checking if the king is in check after making the move
    std::vector<ChessMove*> getPossibleMovesForPlayer (std::string color) const;
    
    // returns vector of legal moves
    std::vector<ChessMove*> getLegalMovesForPlayer (std::string color) const;

    bool hasLegalMoves(std::string color) const;

    bool playerUnderAttack(std::string color) const;

    // checks if a board's square is attacked by a given player 
    bool isAttackedBy (std::string color, int xCord, int yCord) const;

    // checks whether a player's king is in check
    bool isUnderCheck (std::string color) const;

    //whether a coordinate is within the bounds of the chess board
    bool isInsideBoard(int xCord, int yCord) const;
	
	bool hasPieceAt(int xCord, int yCord) const;

    std::string getPieceColor(int xCord, int yCord) const;

    bool hasPieceOfOppositeColor(std::string color,int xCord, int yCord) const;

    const Piece *getPieceAt(int xCord, int yCord) const;

    // returns the type of the piece (Piece::TYPE) given the coordinates	
	int getPieceType(int xCord, int yCord) const;
    
    void setPreviousState(GameState *state);

    GameState *getPreviousState() const;

    // re draws the game state
    void drawState() const;

    // prints the board to stdout
    void printBoard() const;

    // returns a "value" based on the configuration
    // used for the AI for making smart moves
    int getValueForPlayer(std::string color) const;
    
    ~GameState();
};

#endif
