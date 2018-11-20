#!/bin/bash
start_idx=$1
for iter in $(seq $start_idx -1 2)
do
    j=$((iter-1))
    curr=$(printf %04d $iter)
    next=$(printf %04d $j)
    echo "Curr: $curr"
    echo "Next: $next"
    curr_vtk="$PWD/forward/$curr"".vtk"
    next_vtk="$PWD/forward/$next"".vtk"
    output_path=$PWD/"backward"/$next
#    echo "output: $output_path"
    computePairwiseTPS $curr_vtk $next_vtk $output_path
done
#for i in $(seq $j -1 2)
#do
#    j=$((i-1))
#    curr=$(printf %04d $i)
#    next=$(printf %04d $j)
#    echo $curr
#    echo $next
#    curr_vtk="$curr"".vtk"
#    next_vtk="$next"".vtk"
#    curr_m3d="$curr"".m3d"
#    tps_srep $curr_vtk $next_vtk $curr_m3d ./
#done
#
