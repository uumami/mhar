 #!/bin/bash
cp times_template.txt times.txt
export pass=$(cat /dev/urandom | tr -cd 'a-f0-9' | head -c 7) 
for n in {5..100..5}     ### Outer for loop ###
	do
		iter=$(( n - 1 )) 
		iter=$(($iter**3))  
    	for p in {0..13..1} ### Inner for loop ###
    		do 			 
  				padd=$((2**p))
    			echo "$n , $p, $padd, $iter"
    			./call_mhar.sh "2" "$n" "0" "$padd" "$iter" "0"
    			aws s3 cp times.txt "s3://mhar/mhar_sims_aws/$(echo $pass).txt"
    		done
  	echo "" #### print the new line ###
done
