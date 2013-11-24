#include "rook.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Rook::Rook(string color):Piece(color) {
	if (color == "white")
		repr = 'R';
	else
		repr = 'r';
	moved = false;
    cout << "rook cons" << endl;
}

vector<ChessMove*> Rook::getPossibleMoves(GameState* state) const {
	vector<ChessMove*> list;
	int i;
	// up
	i = 1;
	while(state->isInsideBoard(this->xCord,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+i));
			break;
		}
		i++;
	}
	// down
	i = 1;
	while(state->isInsideBoard(this->xCord,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord-i));
			break;
		}
		i++;
	}
	// right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord));
			break;
		}
		i++;
	}
	// left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord-i,this->yCord))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord));
			break;
		}
		i++;
	}
	return list;
}

bool Rook::hasMoved() {
	return moved;
}
