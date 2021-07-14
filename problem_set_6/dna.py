import csv
import sys

from typing import Dict, List

def load_database(filename: str) -> List[Dict[str, str]]:
    db = open(filename)
    return list(csv.DictReader(db))

def load_dna_sequence(filename: str) -> str:
    dna = open(filename)
    return dna.read()

def max_longest_repeat(dna: str, seq: str) -> int:
    """Get maximum number of times STR sequence consecutively repeats in dna"""
    # Cache seq length to avoid calculating each time
    seq_length = len(seq)
    # Start seq search at beginnning of dna
    start = 0
    end = seq_length
    max_count = 0
    # loop through each character, _ indicates variable not to be used in loop
    for _ in enumerate(dna):
        if dna[start:end] == seq:
            count = 0
            while dna[start:end] == seq:
                count += 1
                start += seq_length
                end += seq_length
                if count > max_count:
                    max_count = count
        else:
            start += 1
            end += 1
    
    return max_count

def get_repeat_counts(dna: str, sequences: List[str]) -> Dict[str, int]:
    """Find the maximum number of repeats for each STR sequence"""
    repeat_counts = {}
    for seq in sequences:
        repeat_counts[seq] = max_longest_repeat(dna, seq)
    return repeat_counts

def show_match(people: List[Dict], sample: Dict[str, int]) -> str:
    for person in people:
        match = 0
        for key in sample:
            
            if int(person[key]) == sample[key]:
                match += 1
        if match == len(sample):
            return person["name"]
            break
    else:
        return "No match"

def main():
    if len(sys.argv) != 3:
        print("Usage: dna.py database.csv sequence.txt")
        sys.exit()
    # Load data
    dna_database = load_database(sys.argv[1])
    dna_sample = load_dna_sequence(sys.argv[2])
       
    # Get a list of repeat sequences from database
    repeat_sequences: List[str] = [seq for seq in dna_database[0].keys() if seq != "name"]
    
    repeat_counts = get_repeat_counts(dna_sample, repeat_sequences)
    print(show_match(dna_database, repeat_counts))
    

if __name__ == "__main__":
    main()
