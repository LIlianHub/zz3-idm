#!/bin/bash

num_replications=10

run_replication() {
    replication_number=$1
    simulation_program="$PWD/TP5_BALLEJOS"
    output_file="$PWD/output/pi_result_${replication_number}.txt"
    input_file="$PWD/status/mtStatusQ3-${replication_number}.txt"

    echo "Launching replication ${replication_number}"
    $simulation_program 5 $input_file >> "$PWD/calcul/yo.txt"
    echo "Replication ${replication_number} ended. Result in ${output_file}"
}

export -f run_replication

start_time=$SECONDS

# Boucle pour lancer les réplications en parallèle
for ((i = 0; i < num_replications; i++)); do
    # Exécution de la réplication en tâche de fond
    run_replication $i &
done

wait

end_time=$SECONDS
elapsed_time=$((end_time - start_time))

echo "All replications have been finished. Total time elapsed: ${elapsed_time} seconds."
