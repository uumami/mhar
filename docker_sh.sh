#!/bin/bash
docker build -t  mhar_image --build-arg CACHEBUST=$(date +%s) . 
docker kill mhar_container
docker rm mhar_container
docker run --gpus all -ti -v /home/mario/Documents/github/mhar:/app --name=mhar_container mhar_image
#docker run --gpus all -ti --name=mhar_container mhar_image
