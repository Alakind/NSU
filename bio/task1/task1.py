import sys
from Bio import SeqIO
from Bio.Seq import Seq

if (len(sys.argv) > 1):
    filename = sys.argv[1]
    with open(sys.argv[1], 'r') as f:
        data = f.read()

for seq_record in SeqIO.parse(filename, "fasta"):
    seq = Seq(seq_record.seq)

print("DNA sequence:")
print(seq)
print("")

print("DNA complement:")
print(seq.complement())
print("")

print("DNA reverse complement:")
print(seq.reverse_complement())
print("")

print("mRNA:")
print(seq.transcribe())
print("")

print("Translated:")
print(seq.translate())
print("")
