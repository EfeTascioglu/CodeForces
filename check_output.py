
# H1: Compare the output file with the expected output

# H2: Dealing with Inputs
import argparse
parser = argparse.ArgumentParser(description='Compare the output file with the expected output')
parser.add_argument('expected_output_file', type=str, help='Path to the expected output file')
parser.add_argument('true_output_file', type=str, help='Path to the true output file')

args = parser.parse_args()

# H2: Read the output files
with open(args.expected_output_file, 'r') as f:
    expected_output = f.read().strip()
with open(args.true_output_file, 'r') as f:
    true_output = f.read().strip()

# H2: Compare the output files
for i, (true_out, expected_out) in enumerate(zip(true_output.split('\n'), expected_output.split('\n'))):
    
    print(f'Test Case {i+1}:')

    if true_out == expected_out:
        print(f'CORRECT: \t{true_out}')
    else:
        print(f'EXPECTED: \t{expected_out}')
        print(f'RECIEVED: \t{true_out}')
    print('=' * 20)