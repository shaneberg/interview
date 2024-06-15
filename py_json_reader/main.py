#!/usr/bin/env python3

import argparse
import json
import sys

def main(args):
    with open(args.file, 'r') as file:
        creatures = json.load(file)

    print(f"==== Toy Creature Report ====")

    creature_count = len(creatures)
    print(f"Creature Count is {creature_count}")

    total_price = sum(creature['price'] for creature in creatures)
    print(f"Total of all prices is ${total_price}")

    average_price = total_price / creature_count
    print(f"Average price is ${average_price}")

    least_expensive = min(creatures, key=lambda creature: creature['price'])
    print(f"Least expensive price is ${least_expensive['price']} for a {least_expensive['name']}")

    most_expensive = max(creatures, key=lambda creature: creature['price'])
    print(f"Most expensive price is ${most_expensive['price']} for a {most_expensive['name']}")

    in_stock_names = [creature['name'] for creature in creatures if creature['in_stock']]
    print(f"=== IN STOCK ===")
    for stocked in in_stock_names: print(f"\t{stocked}")

    out_of_stock = [creature['name'] for creature in creatures if not creature['in_stock']]
    print(f"=== OUT OF STOCK ===")
    for missing in out_of_stock: print(f"\t{missing}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Short description of what your program does.")
    parser.add_argument('-f', '--file', type=str, help='A file to load.', default='creatures.json')
    args = parser.parse_args()
    main(args)
