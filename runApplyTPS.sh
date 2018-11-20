#!/bin/bash
start_idx=$1
#applyTPS <Template s-rep, tpsFileName, sourceLandMark and outputPrefix>
for iter in $(seq $start_idx -1 2)
do
    j=$((iter-1))
    curr=$(printf %04d $iter)
    next=$(printf %04d $j)
    echo "Curr: $curr"
    echo "Next: $next"
    curr_vtk="$PWD/forward/$curr"".vtk"
    tps="$PWD/backward/$next"".txt"
    curr_m3d="$PWD/model/$curr"".m3d"
    path="$PWD/model/"
    out_prefix="$path$next"
    applyTPS $curr_m3d $tps $curr_vtk $out_prefix | tee "$path$curr"".log"
done
