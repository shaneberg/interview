#!/usr/bin/env python3

import argparse
import sys

def is_odd(number):
    return (number % 2) != 0

def main(args):
    num = args.number
    string = "even"
    if is_odd(num):
        string = "odd"

    print(f"{num} is {string}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Determine if an int is even or odd.")
    # Example of adding an optional argument
    parser.add_argument('-n', '--number', type=int, help='A number to evaluate.', default=0)
    # Parse the command line arguments
    args = parser.parse_args()

    # Call the main function with parsed arguments
    main(args)
