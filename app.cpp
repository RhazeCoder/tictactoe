#include <iostream>
#include <windows.h>

using namespace std;

string board[] = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};
string player = "-";
int position;
bool valid_move = true;
bool is_draw = true;

void play() {
	void print_board(), player_move();
	system("cls");
	cout << "##### TIC TAC TOE GAME #####" << endl;
	print_board();
	player_move();
}

void print_board() {
	cout << "+-----------+" << endl;
	cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
	cout << "+-----------+" << endl;
	cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
	cout << "+-----------+" << endl;
	cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
	cout << "+-----------+" << endl << endl;
}

void reset() {
	for (int i = 0; i < 9; i++) {
		board[i] = "-";
	}
	player = "-";
	is_draw = true;
}

void change_player() {
	void play();
	player = player == "X" ? "0" : "X";
	
	play();
}

void player_move() {
	void check_winner();
	player = player == "-" ? "X" : player;
	
	cout << player << " >> ";
	cin >> position;
	
    while (valid_move) {
        if (board[position - 1] != "-") {
            cout << "Invalid move! Position already occupied" << endl;
            player_move();
        } else if (position < 1 || position > 9) {
        	cout << "Invalid move! Only numbers between 1-9" << endl;
            player_move();
		} else {
        	board[position - 1] = player;
        	check_winner();
            valid_move = false;
		}
    }
}

void check_winner() {
	void display_winner();
	valid_move = true;
	
	if (board[0] == board[1] && board[1] == board[2] && board[2] != "-") {
		display_winner();
	} else if (board[3] == board[4] && board[4] == board[5] && board[5] != "-") {
		display_winner();
	} else if (board[6] == board[7] && board[7] == board[8] && board[8] != "-") {
		display_winner();
	} else if (board[0] == board[3] && board[3] == board[6] && board[6] != "-") {
		display_winner();
	} else if (board[1] == board[4] && board[4] == board[7] && board[7] != "-") {
		display_winner();
	} else if (board[2] == board[5] && board[5] == board[8] && board[8] != "-") {
		display_winner();
	} else if (board[0] == board[4] && board[4] == board[8] && board[8] != "-") {
		display_winner();
	} else if (board[2] == board[4] && board[4] == board[6] && board[6] != "-") {
		display_winner();
	} else {
        for (int i = 0; i < 9; i++) {
        	cout << board[i] << endl;
            if (board[i] == "-") {
                is_draw = false;
                break;
            } else {
            	is_draw = true;
			}
        }

        if (is_draw) {
            display_winner();
        } else {
            change_player();
        }
	}
}

void display_winner() {
	char choice;
	system("cls");
	if (is_draw) {
		cout << "Draw, no one wins!" << endl << endl;
	} else {
		cout << "Player " <<  player << " Wins!" << endl << endl;
	}
	print_board();
	cout << "=============" << endl << endl;
	
	cout << "Play Again? [y, n]: ";
	cin >> choice;
	
	if (choice == 'Y' || choice == 'y') {
		reset();
		play();
	} else {
		system("exit");
	}
}

main() {
	play();
}
