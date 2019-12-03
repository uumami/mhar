 #!/bin/bash
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
sleep 15  
for n in {5,15,25,50,100,200}     ### Outer for loop ###
do  
  for t in {1..23..1}    
  do
    thin=$(( n - 1 ))
    thin=$(($thin**2))
    iter=$(($thin*10))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((2**p))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "$1" "$n" "2" "$padd" "$iter" "0" "$thin"
        points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_times_thesis/$1_$(echo $n)_times_$(echo $pass).txt"
        echo "$points_aws"
        echo "$times_aws"
        aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done

