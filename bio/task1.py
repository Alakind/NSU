import sys
from Bio import SeqIO
from Bio.Seq import Seq


if (len(sys.argv) > 1):
    filename = sys.argv[1]
    with open(sys.argv[1], 'r') as f:
        data = f.read()
        # print(data);

for i in range(len(data)):
    if (data[i] == '\n'):
        seq = data[i + 1:]
        break

print("Original sequence:")
print(seq)

new_seq = ""

for symbol in seq:
    if (symbol == 'A'):
        new_seq += 'T'
    elif (symbol == 'T'):
        new_seq += 'A'
    elif (symbol == 'G'):
        new_seq += 'C'
    elif (symbol == 'C'):
        new_seq += 'G'

print("Complementary sequence:")
print(new_seq)
print("")

mRNA = ""

for symbol in seq:
    if (symbol == 'T'):
        mRNA += 'U'
    else:
        mRNA += symbol

print("mRNA sequence:")
print(new_seq)
print("")

for seq_record in SeqIO.parse(filename, "fasta"):
    seq = Seq(seq_record.seq)

print("DNA sequence:")
print(seq)
print("")

print("Translated:")
print(seq.translate())
print("")
