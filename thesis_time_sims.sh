 #!/bin/bash

echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
sleep 15 

# SIMPLEX BELOW 25
for t in {1..5..1}    
do  
  for n in {5,15}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*1))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((10000))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "2" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/2_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done

 #!/bin/bash
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
sleep 15 


# SIMPLEX 25,50
for t in {1..5..1}    
do  
  for n in {25,50}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*2))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((4992))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "2" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/2_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done

echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
sleep 15 

# HYPERCUBE BELOW 25
for t in {1..5..1}    
do  
  for n in {5,15}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*1))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((10000))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "1" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/1_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done

 #!/bin/bash
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
echo "" #### print the new line ###
sleep 15 


# HYPERCUBE 25,50
for t in {1..5..1}    
do  
  for n in {25,50}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*2))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((4992))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "1" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/1_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done

# Simplex 100, 200
for t in {1..5..1}    
do  
  for n in {100,200}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*1))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((128))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "2" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/2_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done


# Hypercube 100, 200
for t in {1..5..1}    
do  
  for n in {100,200}  
  do
    thin=$(( n - 1 ))
    thin=$(($thin**3))
    iter=$(($thin*1))
    export n="$n"
      for p in {10..10..1} ### Inner for loop ###
      do
        counter="$(echo $n) $(echo $t)"
        echo "" #### print the new line ###
        echo "$counter"
        padd=$((128))
        echo "$n , $p, $padd, $iter"
        export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 12) 
        cp times_template.txt times.txt
        ./call_mhar.sh "1" "$n" "0" "$padd" "$iter" "0" "$thin"
        #points_aws="s3://mhar/mhar_samples_thesis/$1_$(echo $n)_points_$(echo $pass).txt"
        times_aws="s3://mhar/mhar_thesis_sim_times/1_$(echo $n)_new_times_$(echo $pass).txt"
        #echo "$points_aws"
        echo "$times_aws"
        #aws s3 cp output/points.txt "$points_aws"
        aws s3 cp times.txt "$times_aws"
      done
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
    echo "" #### print the new line ###
  done
done