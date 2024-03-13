#!/usr/bin/env python3

import argparse
import sys

def main(args):
    print(f"Arguments received: {args}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Short description of what your program does.")
    # Example of adding an optional argument
    parser.add_argument('-n', '--name', type=str, help='A name to print.', default='World')
    # Parse the command line arguments
    args = parser.parse_args()

    # Call the main function with parsed arguments
    main(args)
