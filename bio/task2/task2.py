import sys
from Bio import SeqIO
from Bio.Seq import Seq
from Bio import Entrez

def findGene(gene, animal):
    search_string = gene + "[Gene] AND " + animal + "[Organism]"
    print("Searching: " + search_string)
    print("")

    handle = Entrez.esearch(db="nucleotide", term=search_string)
    record = Entrez.read(handle)
    ids = record['IdList']

    seq_id = ids[0] #you must implement an if to deal with <0 or >1 cases
    handle = Entrez.efetch(db="nucleotide", id=seq_id, rettype="fasta", retmode="text")
    record = handle.read()

    return Seq(record)



Entrez.email = "a.ivakin@g.nsu.ru"

seq = findGene("Clock", "human")

print("Human DNA sequence:")
print(seq)
print("")
