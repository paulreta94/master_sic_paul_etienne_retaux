#!/bin/bash
for i in $(seq 21 30)
do 
	/opt/openmpi/bin/mpirun --hostfile hostfile.txt ./bin/ep.S.x > results/result$i.txt 
done
