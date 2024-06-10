#!/usr/bin/env python3

import argparse
import string
import sys

def main(args):
    print(f"Arguments received: {args}")
    file = open(args.input, 'r')
    content = file.read().lower()

    translator = str.maketrans('', '', string.punctuation)
    content = content.translate(translator)

    word_list = content.split()
    frequency_dictionary = dict()
    for word in word_list:
        if word in frequency_dictionary:
            frequency_dictionary[word] = frequency_dictionary[word] + 1
        else:
            frequency_dictionary[word] = 1

    sorted_frequency_dictionary = sorted(frequency_dictionary.items(), key=lambda item: item[1], reverse=True)

    print("========================")
    print("=== Word Frequencies ===")
    print("========================")
    for cur in range(args.count):
        if cur < len(sorted_frequency_dictionary):
            cur_word = sorted_frequency_dictionary[cur][0]
            cur_freq = sorted_frequency_dictionary[cur][1]
            output = f"{cur_word}\t\t{cur_freq}"
            print(output)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Displays the top N most frequent words in a given file.")
    parser.add_argument('-i', '--input', type=str, help='A file to perform frequency count on.', default='input.txt')
    parser.add_argument('-c', '--count', type=int, help='The number of frequencies to display.', default=10)
    args = parser.parse_args()
    main(args)
