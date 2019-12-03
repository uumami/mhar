 #!/bin/bash 
cp times_template.txt times.txt
export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 7)
for n in {5..25..5}     ### Outer for loop ###
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*10))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
        do
          padd=$((2**p))
          echo "$n , $p, $padd, $iter"
          ./call_mhar.sh "$1" "$n" "2" "$padd" "$iter" "0" "$thin"
          foo="s3://mhar/mhar_samples/$1_$(echo $n)_$(echo $pass).txt"
          echo "$foo"
          aws s3 cp output/points.txt "$foo"
        done
    echo "" #### print the new line ###
done
