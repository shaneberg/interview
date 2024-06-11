#!/usr/bin/env python3

import argparse
import sys

import string

from collections import Counter

FAIL_FORMATTING = "\033[1m\033[41m"
PASS_FORMATTING = "\033[32m"
RESET_FORMATTING = "\033[0m"

def main(args):
    if args.input:
        process_file(args.input)
    else:
        interactive()

def process_file(file):
    with open (file, 'r') as f:
        content = f.read()
        lines = content.splitlines()
        index = 0
        line_count = len(lines)
        while index + 2 < line_count:
            str1 = lines[index]
            str2 = lines[index + 1]
            expected = bool(lines[index + 2])
            anagram = are_anagram(str1, str2)
            failed = expected != anagram
            line_format = f"{FAIL_FORMATTING}" if failed else f"{PASS_FORMATTING}"

            test_result = "pass" if expected == anagram else f"FAIL"

            print(f"{line_format}EXPECTED: {expected}  \t\tACTUAL: {anagram}  \t\t{test_result}{RESET_FORMATTING}")
            index = index + 3

def interactive():
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")

    anagram = are_anagram(str1, str2)
    line_format = f"{FAIL_FORMATTING}" if not anagram else f"{PASS_FORMATTING}"
    print(f"{line_format}{anagram}{RESET_FORMATTING}")

def are_anagram(str1, str2):
    str1_clean = clean_string(str1)
    str2_clean = clean_string(str2)

    str1_counter = Counter(str1_clean)
    str2_counter = Counter(str2_clean)

    return str1_counter == str2_counter

def clean_string(str_input):
    str_cleaned = str_input.lower()
    translator = str.maketrans('', '', string.punctuation)
    translator = str.maketrans('', '', string.whitespace)
    str_cleaned = str_cleaned.translate(translator);
    return str_cleaned

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compares pairs of strings and reports if they are anagrams.")
    parser.add_argument('-i', '--input', type=str, help='A file to perform anagram processing.')
    args = parser.parse_args()
    main(args)
