# MHAR (Matrix/Mentat Hit and Run)
# Status
The new version that allows for mixed numerical precision has been released (1.0.1) [here](https://github.com/sonder-art/mhar) and a working example/tutorial can be found [full dimensional](https://github.com/sonder-art/mhar/blob/released/nbs/tutorial_full_dimensional.ipynb) and [non-full dimensional](https://github.com/sonder-art/mhar/blob/released/nbs/tutorial_nonfull_dimensional.ipynb) 
This package constains one of the fastest polytope samplers known to date.
It only works with linear inequality restrictions, it does not accept V-representation.  

A paper with the asymptotic complexity and tests for MHAR is in:

arXiv: https://arxiv.org/abs/2104.07097

LACSC2021 conference: https://www.youtube.com/watch?v=o2CxnI6onts

Original code for the paper: https://github.com/uumami/mhar_pytorch

![image](https://user-images.githubusercontent.com/17039164/115347348-e8454a00-a176-11eb-9c98-a65214a17f87.png)

A Jupyter notebook with examples of how to use it is in (works in Colab):  
https://github.com/uumami/mhar/blob/beta/tutorial/turorial.ipynb  

PyPi: 
https://pypi.org/project/mhar/

You need to install Pytorch, then you can use the following command to install the MHAR package:  
``` pip install mhar ```

Contributors to the code: uumami (Mario Vazquez Corte)
