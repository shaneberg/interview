#!/usr/bin/env python3

import argparse
import os
import random
import sys

ANSI_RESET = '\033[0m'
ANSI_GREEN_BACKGROUND = '\033[42m'
ANSI_YELLOW_BACKGROUND = '\033[43m'
ANSI_BLACK_FOREGROUND = '\033[30m'

GUESS_COUNT = 6
WORD_LENGTH = 5

def get_printable_string_for_guess(guess, answer):
    printable = ""
    for cur in range(0, len(guess)):
        if guess[cur] == answer[cur]:
            printable += f"{ANSI_GREEN_BACKGROUND}"
        elif guess[cur] in answer:
            printable += f"{ANSI_YELLOW_BACKGROUND}{ANSI_BLACK_FOREGROUND}"

        printable += f"{guess[cur]}{ANSI_RESET}"

    return printable

def print_board(guesses, puzzle, message = ''):
    os.system('clear')

    for cur in range(0, GUESS_COUNT):
        if cur < len(guesses):
            print(get_printable_string_for_guess(guesses[cur], puzzle))
        else:
            print("")

    print(message)

def main(args):

    with open(args.wordlist, 'r') as wordfile:
        words = [word.strip().upper() for word in wordfile.readlines()]

    with open(args.puzzlelist, 'r') as puzzlefile:
        puzzles = [puzzle.strip().upper() for puzzle in puzzlefile.readlines()]

    puzzle = random.choice(puzzles)

    guesses = []
    message = ""
    while len(guesses) < GUESS_COUNT:

        print_board(guesses, puzzle, message)
        guess = input(f"Guess #{len(guesses) + 1}: ").upper()

        if len(guess) != WORD_LENGTH:
            message = f"INVALID GUESS: {guess}. Guess must be EXACTLY {WORD_LENGTH} letters."
            continue
        elif guess not in words:
            message = f"INVALID GUESS: {guess}. Guess must be in the dictionary."
            continue
        elif guess in guesses:
            message = f"INVALID GUESS: {guess}. Guess cannot be a previous guess."
            continue

        guesses.append(guess)
        if guess == puzzle:
            message = "CORRECT!"
            print_board(guesses, puzzle, message)
            break;

        message = ""

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Short description of what your program does.")
    parser.add_argument('-w', '--wordlist', type=str, help='Path of a wordlist file.', default='wordlist.txt')
    parser.add_argument('-p', '--puzzlelist', type=str, help='Path of a puzzlelist file.', default='puzzles.txt')
    args = parser.parse_args()

    main(args)
