 #!/bin/bash

NPC=24
# NPC=mpiprocs=select*ncpus
# 1 <= select <= 2

SRC=main.cpp

#PBS -l select=2:ncpus=12:mpiprocs=12:mem=2000m,place=free

#PBS -l walltime=01:00:00

cd $PBS_O_WORKDIR
echo "I run on node: `uname -n`"
echo "My working directory is: $PBS_O_WORKDIR"

MPI_PATH=/opt/intel/impi/5.0.1.035/intel64/bin

#echo "Compiling $SRC..."

$MPI_PATH/mpicxx -Wunused-variable main.cpp -o lab3.out -std=c++11

echo "Executing $SRC..."

$MPI_PATH/mpirun -machinefile $PBS_NODEFILE -np $NPC ./lab3.out